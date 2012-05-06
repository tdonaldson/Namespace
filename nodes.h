// Template definition of Singly and Doubly linked lists.
// Tyler Donaldson
// tylerdonaldson@hotmail.com
// 4/8/2012
//*****************************************************
// This file contains the definition of template structures
// for a singly and doubly linked list, and a definition
// for a structure for a double Binary Tree.
//*****************************************************
#ifndef NODES_H
#define NODES_H

#include <iostream> // Had to include for NULL.
#include <string>
using std::string;

namespace Donaldson
{
	// Definition of SListNode structure used with
	// the List class. (Single Linked List)
	template<class T>
	struct SListNode
	{
		SListNode *next;
		T data;

		SListNode(T num, SListNode *p=NULL)
		{
			data = num;
			next = p;
		}
	};

	// Definition of DListNode structure.
	template<class T>
	struct DListNode
	{
		DListNode *prev;
		DListNode *next;
		T data;
		
		DListNode(T num, DListNode *prevPtr=NULL, DListNode *nextPtr=NULL)
		{
			data = num;
			prev = prevPtr;
			next = nextPtr;
		}
	};

	// Definition of a binary tree structure.
	template<class T> struct TreeNode
	{
		TreeNode<T> *left;
		TreeNode<T> *right;
		T value;
		T data;

		// Constructor allows the user to enter one number.
		TreeNode(T val1, TreeNode<T> *leftPtr=NULL, 
						TreeNode<T> *rightPtr=NULL)
		{
			value = val1;
			data = 0;
			left = leftPtr;
			right = rightPtr;
		}

		// Constructor allows the user to enter more than one number.
		TreeNode(T val1, T val2, TreeNode<T> *leftPtr=NULL, 
						TreeNode<T> *rightPtr=NULL)
		{
			value = val1;
			data = val2;
			left = leftPtr;
			right = rightPtr;
		}
	};
}

#endif 