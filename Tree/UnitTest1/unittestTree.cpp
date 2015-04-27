#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Project1/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestTree)
	{
	public:

		TEST_METHOD(Tree_Add)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);

			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(Tree_Clear)
		{
			Tree<int> tree(0);

			tree.Add(100, 0);
			tree.Add(200, 0);
			tree.Add(300, 0);
			tree.Add(101, 100);
			tree.Add(102, 100);
			tree.Add(103, 100);
			tree.Add(210, 200);
			tree.Add(220, 200);
			tree.Add(221, 220);

			tree.Clear();

			Assert::IsTrue(tree.root == NULL);
		}

		TEST_METHOD(Tree_Preorder_Recursive)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PreorderRecursive(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(Tree_Inorder_Recursive)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.InorderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(Tree_Postorder_Recursive)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PostorderRecursive(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(Tree_Preorder_Iterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('X', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PreorderIterative(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(Tree_Inorder_Iterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.InorderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		TEST_METHOD(Tree_Postorder_Iterative)
		{
			Tree<char> tree('F');

			tree.Add('B', 'F');
			tree.Add('G', 'F');
			tree.Add('A', 'B');
			tree.Add('D', 'B');
			tree.Add('C', 'D');
			tree.Add('E', 'D');
			tree.Add('I', 'G');
			tree.Add('H', 'I');

			p2List<TreeNode<char>*> list;
			tree.PostorderIterative(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

	};

}