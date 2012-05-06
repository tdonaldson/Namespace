//*******************************************************************
// Tyler Donaldson													*
// tylerdonaldson@hotmail.com										*
// Started on: 4/16/2012											*
// Finished on: 4/16/2012											*
// File Name: Tree.h												*
//*******************************************************************
// This file declares the variables and definitions					*
// that are to be used to create a binary search tree.				*
//*******************************************************************
// ERROR LIST:														*
//	1. Searching/Inserting - Entering a value that is stored		*
//				in the 2nd variable inside the node.				*
//				The limitation is that the number must				*
//				meet the same criteria as the first variable.		*
//				If the first number is less than the head,			*
//				the second number must also be less than the head	*
//				but must be greater than the first.	Note: you can	*
//				insert any value into the second node, but the error*
//				then occurs in searching for it. It may look the in *
//				the wrong direcetion.								*
//*******************************************************************
#ifndef TREE_H
#define TREE_H

#include "nodes.h"
using Donaldson::TreeNode;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <fstream>
using std::fstream;
using std::ios;
#include <stdio.h>
using std::remove;
using std::cerr;

namespace Donaldson
{
	template<class T> class Tree
	{
	private:
		TreeNode<T> *root;
		int leaves;
		fstream file;
		string fileName;

		void insert(T, TreeNode<T> *&);
		void insert(T, T, TreeNode<T> *&);
		void displayInOrder(TreeNode<T> *);
		void displayPreOrder(TreeNode<T> *);
		void displayPostOrder(TreeNode<T> *);
		void removeVal(TreeNode<T> *&, T);
		void makeDeletion(TreeNode<T> *&);
		void destroySubtree(TreeNode<T> *);
		int countLeaves(TreeNode<T> *);
		bool search(T, TreeNode<T> *);
		void traverse(TreeNode<T> *, vector<T> &);
		int size(TreeNode<T> *);
		int height(TreeNode<T> *);
		int width(TreeNode<T> *, int);
		int max(int, int);
		void copy(TreeNode<T> *&, TreeNode<T> *&);
		void fileHandling(TreeNode<T> *, fstream &);

	public:


		Tree();
		Tree(Tree &);
		Tree(T);
		~Tree();
		TreeNode<T> *getRoot();
		void insert(T);
		void insert(T, T);
		bool search(T);
		void InOrder(vector<T> &);
		void removeVal(T);
		void destroy();
		void InOrder();
		void PreOrder();
		void PostOrder();
		int leafCount();
		int size();
		int height();
		int width();
		void writeToFile();
		Tree<T> &operator=(Tree<T> &);
	};

	// Constructor that sets the tree to NULL.
	// The base constructor.
	template<class T>
	Tree<T>::Tree()
	{
		root = NULL;
		leaves = 0;
		fileName = "leaf.dat";
	}

	// Copy constructor.
	template<class T>
	Tree<T>::Tree(Tree &tree)
	{
		*this = tree;
		fileName = "leaf.dat";
	}

	// Constructor that only sets the value
	// of the root node.
	template<class T>
	Tree<T>::Tree(T val)
	{
		root = new TreeNode(val);
		fileName = "leaf.dat";
	}

	// Destructor
	template<class T>
	Tree<T>::~Tree()
	{
		destroy();
	}

	// Returns the root.
	template<class T>
	TreeNode<T>* Tree<T>::getRoot()
	{
		return root;
	}

	// Calling the private function insert to insert 
	// a the value into the tree. Recursively
	template<class T>
	void Tree<T>::insert(T val)
	{
		insert(val, root);
	}

	// Insert a value into the tree.
	template<class T>
	void Tree<T>::insert(T val, TreeNode<T> *&tree)
	{
		// Check to see if the tree is empty.
		if (!tree)
		{
			tree = new TreeNode<T>(val);
			return;
		}

		// Check to see if the number is already
		// in the tree.
		if (tree->value == val)
			return;

		// If the tree is not empty, nor is the value
		// contained in the tree.
		if (val < tree->value)
			insert(val, tree->left);
		else
			insert(val, tree->right);
	}

	// Insert two values of the same data type into 
	// the binary tree.
	template<class T>
	void Tree<T>::insert(T val1, T val2)
	{
		insert(val1, val2, root);
	}

	// Inserts 2 values into the same tree node.
	template<class T>
	void Tree<T>::insert(T val, T val2, TreeNode<T> *&tree)
	{
		// Check to see if the tree is empty.
		if (!tree)
		{
			tree = new TreeNode<T>(val, val2);
			return;
		}

		// Check to see if the number is already
		// in the tree.
		if (tree->value == val)
			return;

		// If the tree is not empty, nor is the value
		// contained in the tree.
		if (val < tree->value)
			insert(val, val2, tree->left);
		else
			insert(val, val2, tree->right);
	}

	// Traverse the list from left, to root, to right.
	template<class T>
	void Tree<T>::InOrder()
	{
		displayInOrder(root);
	}

	// Traverse the list from left, to right, to root.
	template<class T>
	void Tree<T>::PostOrder()
	{
		displayPostOrder(root);
	}

	// Traverse the list from root, to left, to right.
	template<class T>
	void Tree<T>::PreOrder()
	{
		displayPreOrder(root);
	}

	// Display the tree Inorder.
	template<class T>
	void Tree<T>::displayInOrder(TreeNode<T> *tree)
	{
		if (tree)
		{
			displayInOrder(tree->left);
			cout << "Number 1: " << tree->value << "\n";
			cout << "Number 2: " << tree->data << "\n\n";
			displayInOrder(tree->right);
		}
	}

	// Display the tree postOrder.
	template<class T>
	void Tree<T>::displayPostOrder(TreeNode<T> *tree)
	{
		if (tree)
		{
			cout << tree->value << " ";
			displayPostOrder(tree->left);
			displayPostOrder(tree->right);
		}
	}

	// Display the tree in preOrder.
	template<class T>
	void Tree<T>::displayPreOrder(TreeNode<T> *tree)
	{
		if (tree)
		{
			displayPostOrder(tree->left);
			displayPostOrder(tree->right);
			cout << tree->value << " " ;
		}
	}

	// Searches the binary tree for a value that 
	// is stored within the tree.
	template<class T>
	bool Tree<T>::search(T num)
	{
		return search(num, root);
	}

	// Search the tree recursively.
	template<class T>
	bool Tree<T>::search(T num, TreeNode<T> *tree)
	{
		if (!tree)
		{
			cout << "Not\n";
			return false;
		}
		if (tree->value == num || tree->data == num)
			return true;
		else if (num < tree->value)
			search(num, tree->left);
		else if (num > tree->value)
			search(num, tree->right);
		else
			return false;
	}

	// Calls the function to find the value.
	template<class T>
	void Tree<T>::removeVal(T num)
	{
		removeVal(root, num);
	}

	// Remove the value from the tree.
	template<class T>
	void Tree<T>::removeVal(TreeNode<T> *&tree, T num)
	{
		if (tree == NULL)
			return;
		if (num < tree->value)
			removeVal(tree->left, num);
		else if (num > tree->value)
			removeVal(tree->left, num);
		else
			makeDeletion(tree);
	}

	// Make the deletion at the node.
	template<class T>
	void Tree<T>::makeDeletion(TreeNode<T> *&tree)
	{
		TreeNode<T> *garbage = tree;
		TreeNode<T> *attach;

		// Replace tree with it's left subtree.
		if (tree->right == NULL)
			tree = tree->left;

		// Replace tree with it's right subtree.
		else if (tree->left == NULL)
			tree = tree->right;

		// The case where the tree has two children.
		else
		{
			// Move to right subtree.
			attach = tree->right;

			// Locate the smallest node in the right subtree
			// by moving as far to the left as possible.
			while (attach->left != NULL)
				attach = attach->left;

			// Attach the left subtree of the original tree 
			// as the left subtree of the smallest node 
			// in the right subtree.
			attach->left = tree->left;

			// Replace the original tree with its right subtree.
			tree = tree->right;
		}

		// Delete root of original tree.
		delete garbage;
	}

	// Calls the function to destroy the contents
	// of the tree.
	template<class T>
	void Tree<T>::destroy()
	{
		destroySubtree(root);
	}

	// Destroys the contents of the tree.
	template<class T>
	void Tree<T>::destroySubtree(TreeNode<T> *tree)
	{
		if (!tree)
			return;
		destroySubtree(tree->left);
		destroySubtree(tree->right);
		delete tree;
	}

	// Returns the number of leaves to the driver.
	template<class T>
	int Tree<T>::leafCount()
	{
		return countLeaves(root);
	}

	// Figures out how many leaves are in the tree.
	template<class T>
	int Tree<T>::countLeaves(TreeNode<T> *tree)
	{
		if (!tree)
			return 0;
		if (!tree->left && !tree->right)
			return 1;
		else
			return countLeaves(tree->left) + 
			countLeaves(tree->right);
	}

	// Traverses through the tree and returns all 
	// of the values in the tree into a vector.
	template<class T>
	void Tree<T>::traverse(TreeNode<T> *tree, vector<T> &contents)
	{
		if (!tree)
			return;
		else
		{
			traverse(tree->left, contents);
			contents.push_back(tree->value);
			traverse(tree->right, contents);
		}
	}

	// This function places all of the contents of the 
	// tree into the vector using the inorder traversal.
	template<class T>
	void Tree<T>::InOrder(vector<T> &contents)
	{
		if (!contents.empty())
			contents.clear();

		traverse(root, contents);

		// Display the vector.
		for (int a = 0; a < contents.size(); a++)
			cout << contents[a] << " ";

		cout << endl;
	}

	// Returns the size of the tree after calling
	// the recursive finder.
	template<class T>
	int Tree<T>::size()
	{
		return size(root);
	}

	// Returns the size of the tree, or how many
	// nodes are in it.
	template<class T>
	int Tree<T>::size(TreeNode<T> *tree)
	{
		if (!tree)
			return 0;
		else
			return 1 + size(tree->left) + size(tree->right);
	}

	// Returns max of two integers.
	template<class T>
	int Tree<T>::max(int x, int y)
	{
		if (x >= y)
			return x;
		else
			return y;
	}

	// Returns the width.
	template<class T>
	int Tree<T>::width()
	{
		int level = height();
		return width(root, level);
	}

	// Recursively finds the width.
	template<class T>
	int Tree<T>::width(TreeNode<T> *tree, int level)
	{
		if (!tree)
			return 0;
		if (level == 1)
			return 1;
		else if (level > 1)
		{
			return (width(tree->left, level - 1)
				+ width(tree->right, level - 1));
		}
	}

	// Returns the height.
	template<class T>
	int Tree<T>::height()
	{
		return height(root);
	}

	// Recursively finds the height.
	template<class T>
	int Tree<T>::height(TreeNode<T> *tree)
	{
		if (!tree)
			return 0;
		else
			return 1 + max(height(tree->left), height(tree->right));
	}

	// Copy the contents of one tree to the other.
	template<class T>
	void Tree<T>::copy(TreeNode<T> *&tree, TreeNode<T> *&original)
	{
		if (!original)
			tree = NULL;
		else
		{
			tree = new TreeNode<T>(original->value, original->data);
			copy(tree->left, original->left);
			copy(tree->right, original->right);
		}
	}

	// Overloaded assignment operator.
	template<class T>
	Tree<T> &Tree<T>::operator=(Tree<T> &right)
	{
		copy(this->root, right.root);
		return *this;
	}

	// writes the data to a file then opens the file in
	// textpad. Waits for user to close the file until 
	// program resumes.
	template<class T>
	void Tree<T>::writeToFile()
	{
		file.open(fileName, ios::out);
		fileHandling(root, file);
		file.close();
		system("Notepad.exe leaf.dat");
		if (remove(fileName.data()) != 0)
			cerr << "ERROR: Failed to delete file.\n";

	}

	// Writes the data to from the tree to file.
	template<class T>
	void Tree<T>::fileHandling(TreeNode<T> *tree, fstream &btfile)
	{
		if (!tree)
			return; 

		fileHandling(tree->left, btfile);

		btfile << "First: " << tree->value;
		btfile << endl;

		btfile << "Second: " << tree->data;
		btfile << endl << endl;

		fileHandling(tree->right, btfile);
	}
}

#endif