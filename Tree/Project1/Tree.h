#ifndef __TREE_H__
#define __TREE_H__
#include <stdio.h>
#include <assert.h>
#include "p2List.h"
#include "p2Stack.h"

template <class TYPE>
class TreeNode{
public:
	TYPE data;
	TreeNode* father;
	p2List<TYPE>* sons;

protected:
	TreeNode<TYPE>* _Find(const TYPE& father)
	{
		if (father == data)
		{
			return this;
		}
		
		TreeNode<TYPE>* found_father = NULL;

		//search all sons of each father
		for (p2List_item<TYPE*>* progenitors = sons.start; progenitors != NULL; progenitors = progenitors->next)
		{
			found_father = progenitors->_Find(father);

			if (found_father != NULL)
			{
				return found_father;
			}
		}
		//no sons; return null
		return NULL;
	}


public:
	//Constructors
	TreeNode(const TYPE& data) :  father(NULL) 
	{
		assert(data); 

			this->data = data;
	} 

	TreeNode(const TYPE& data, const TreeNode& father)
	{
		assert(data);
		assert(father);

		this->data = data;
		this->father = father;
	} 

	//Destructor
	~TreeNode()
	{
		Clear();
	}

	//Data Management Functions
	void AppendSon(TreeNode* node)
	{
		assert(node);

		node->father = this; //father node
		sons.add(node);
	}

	void Clear()
	{
		
		delete sons;
		delete data;
	}

	//Recursive methods
	void _PreorderRecursive(p2List<TYPE> list)
	{
		if (father != NULL)
		{
			list.add(father->data);
			for (p2List_item<TYPE*>* progenitors = sons.start; progenitors != NULL; progenitors = progenitors->next)
			{
				progenitors->data._PreorderRecursive(list);
			}
		}
	}

	void _InorderRecursive(p2List<TYPE> list)
	{
		if (father != NULL)
		{
			unsigned int max = sons.count();

			if (max > 0)
			{
				p2List_item<TYPE*>* progenitors = sons.start;

				max /= 2;

				for (unsigned int i = 0; i < max; i++, progenitors = progenitors->next)
				{
					progenitors->data._PreorderRecursive(list);
				}

				list.add(data);

				for (; progenitors != NULL; progenitors = progenitors->next)
				{
					progenitors->data._InorderRecursive(list);
				}
			}
		}
	}

	void _PostorderRecursive(p2List<TYPE> list)
	{
		if (father != NULL)
		{
			
			for (p2List_item<TYPE*>* progenitors = sons.start; progenitors != NULL; progenitors = progenitors->next)
			{
				progenitors->data._PostorderRecursive(list);
			}
			list.add(father->data);
		}
	}


	//Utility Functions

	TreeNode<TYPE>* Find(const TYPE& father)
	{
		assert(father);
		
		return _find(father);
		
	}
};


template <class TYPE>
class Tree{
private:
	TreeNode<TYPE>* root;

public:
	//Constructors
	Tree(const TYPE& data)
	{
		assert(data);

		root.data = data;
	}

	//Destructor
	virtual ~Tree()
	{
		Clear();
	}

	//Data Management Functions
	void Add(const TYPE& data)
	{
		assert(data);
		root.AppendSon(new TreeNode<TYPE>(data)); // add child if father is undefined
	}

	bool Add(const TYPE& data, const TYPE& father = NULL)
	{
		assert(data);

		//if father = root, don't search
		if (father == NULL || root.data == father)
		{
			root.AppendSons(new TreeNode<TYPE>(data, root));
			return true;
		}
		else
		{
			//where we add the new node
			TreeNode<TYPE>* f = root.Find(father);

			if (f != NULL)
			{
				//append son to tree
				f->AppendSon(new TreeNode<TYPE>(data, father))
					return true;
			}
		}
		return false; // father inexistent
	}

	void Clear(TYPE& node = NULL)
	{
		if (node == NULL) // Clear all tree
		{
			root.Clear();
		}

		else // Clear one node 
		{
			node.Clear();
			node.father->sons.del(node);
		}
	}

	void PreorderRecursive(p2List<TYPE> list)
	{
		assert(list);
		
		root._PreorderRecursive(list);
	}

	void InorderRecursive(p2List<TYPE> list)
	{
		assert(list);

		root._InorderRecursive(list);
	}

	void PostorderRecursive(p2List<TYPE> list)
	{
		assert(list);

		root._PostorderRecursive(list);
	}

	void PreorderIterative(p2List<TYPE> list)
	{
		assert(list);

		p2Stack<TreeNode<TYPE>*> stack;
		TreeNode<TYPE>* node = &root;

		unsigned int max;

		p2List_item<TreeNode<TYPE>*>* tmp;

		while (node != NULL || stack.Pop(node))
		{
			list->add(node);

			max = node->sons.count();

			if (max > 0)
			{
				tmp = node->sons.end;

				for (unsigned int i = 0; i < max; i++, tmp = tmp->next)
				{
					stack.Push(tmp->data);
				}

			}

				node = (tmp != NULL) ? tmp->data : NULL;
			}

	}

};
#endif