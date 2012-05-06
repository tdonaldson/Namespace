// Tyler Donaldson Namespace
#ifndef LIST_H
#define LIST_H

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;
using std::showpoint;
#include <cstdio>
using std::cerr;
#include "nodes.h"
using Donaldson::SListNode;

namespace Donaldson
{	
	// Declaration of List class.
	template<class T>
	class List
	{
	private:
		bool found;

	public:
		// Public variables.
		SListNode<T> *head;

		// Public functions
		List();
		List(List *);
		~List();
		void push_front(T);
		void push_back(T);
		void insert(T, T);
		void remove(T);
		void remove(T, T);
		void pop_front();
		void pop_back();
		void reverse();
		bool find(T);
		bool find(T, SListNode<T> *);
		int	 search(T);
		void sort();
		void display();
		void clear();
		int  size();
		int search(T, T);
	};

	//***************************************************************
	// Linked List Functions!
	//***************************************************************
	// Base Constructor
	template<class T>
	List<T>::List()
	{
		found = false;
		head = NULL;
	}

	// Copy constructor
	template<class T>
	List<T>::List(List *original)
	{
		this->head = original->head;
	}

	// Destructor
	template<class T>
	List<T>::~List()
	{
		SListNode<T> *tempPtr = head;

		while (tempPtr != NULL)
		{
			SListNode<T> *garbage = tempPtr;
			tempPtr = tempPtr->next;
			delete garbage;
		}
	}

	// Function push_fronts a link to the linked list.
	template<class T>
	void List<T>::push_front(T val)
	{
		if (head == NULL)
			head = new SListNode<T>(val);

		else
		{
			SListNode<T> *following;
			following = new SListNode<T>(val);
			following->next = head;
			head = following;
		}
	}

	// Function push_back adds an element to the end of 
	// the linked list.
	template<class T>
	void List<T>::push_back(T val)
	{
		if (head == NULL)
			head = new SListNode<T>(val);

		else
		{
			SListNode<T> *temp = head;
			while (temp->next != NULL)
				temp = temp->next;

			temp->next = new SListNode<T>(val);
		}
	}

	// Function that push_fronts a link to the linked list 
	// at a specfic location.
	template<class T>
	void List<T>::insert(T val, T pos)
	{
		if (pos > size() || pos < 0)
		{
			cerr << "ERROR: Position out of range.\n";
			return;
		}

		else if (pos == size())
		{
			cerr << "ERROR: Cannot insert at end of list.\n";
			return;
		}

		else
		{
			SListNode<T> *prev, *newNode, *fake;
			int counter = 0;

			fake = head;
			while (counter != pos)
			{
				prev = fake;
				fake = fake->next;
				counter++;
			}

			newNode = new SListNode<T>(val, fake);
			prev->next = newNode;
		}
	}

	// Functions removes a link from the linked list.
	template<class T>
	void List<T>::remove(T val)
	{
		SListNode<T> *prev, *remove;

		// Checks to see if the list is empty.
		if (!head)
			return;

		// Checks to see if the first element is the one that needs to be destroyed.
		if (head->data == val)
		{
			remove = head;
			head = head->next;
			delete remove;
		}

		else
		{
			remove = head;

			// While the value is not the current link.
			while (remove != NULL && remove->data != val)
			{
				prev = remove;
				remove = remove->next;
			}

			// If the value is found.
			if (remove)
			{
				prev->next = remove->next;
				delete remove;
			}
		}
	}

	// Function that removes at link a certain position.
	template<class T>
	void List<T>::remove(T pos, T dne)
	{
		if (pos < 0 || pos >= size())
		{
			cerr << "ERROR: Unable to access that position\n";
			return;
		}
		int counter = 0;
		SListNode<T> *prev, *remove;

		// Makes there is a list.
		if (!head)
			return;

		// Checks to see if the position is the first one.
		if (pos == 0)
		{
			remove = head;
			head = head->next;
			delete remove;
		}

		else
		{
			remove = head;

			// While the value is not the current link.
			while (remove != NULL && counter != pos)
			{
				prev = remove;
				remove = remove->next;
				counter++;
			}

			// If the value is found.
			if (remove)
			{
				prev->next = remove->next;
				delete remove;
			}
		}
	}

	// Function removes the first element in the linked list.
	template<class T>
	void List<T>::pop_front()
	{
		SListNode<T> *remove;
		remove = head;
		head = head->next;
		delete remove;
	}

	// Function removes the last element in the linked list.
	template<class T>
	void List<T>::pop_back()
	{
		SListNode<T> *remove = head, *prev;
		while (remove->next != NULL)
		{
			prev = remove;
			remove = remove->next;
		}

		prev->next = remove->next;
		delete remove;
	}

	// Function that reverses the order of the links in the node.
	template<class T>
	void List<T>::reverse()
	{
		if(head == NULL) 
			return;

		SListNode<T> *prev = NULL, *current = NULL, *next = NULL;
		current = head;
		while(current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}

		// now let the head point at the last node (prev)
		head = prev;
	}

	// Function that checks to see if a value is a 
	// member of the linked list.
	template<class T>
	bool List<T>::find(T val)
	{
		SListNode<T> *tempPtr = head;
		found = false;

		while (tempPtr != NULL)
		{
			if (tempPtr->data == val)
				found = true;

			tempPtr = tempPtr->next;
		}

		return found;
	}

	// Recursively checks to see if a value is within
	// the list.
	template<class T>
	bool List<T>::find(T val, SListNode<T> *node)
	{
		if (node)
		{
			if (node->data == val)
				found = true;

			else
				find(val, node->next);
		}

		return found;
	}

	// Searches for a specific value and returns the
	// position of the value in the linked list. Returns
	// -1 is the value doesn't exist.
	template<class T>
	int List<T>::search(T val)
	{
		int pos = -1;
		return search(val, pos);
	}

	// Function that sorts a list in ascending order.
	template<class T>
	void List<T>::sort()
	{
		SListNode<T> *current, *next, *temp;
		current = head;

		// Check to see if the list is empty.
		while (current != NULL)
		{
			next = current->next;
			while (next != NULL) // Makes sure the new node is not NULL.
			{
				// Checks to see if the data in the next node is less
				// than the data in the current node.
				if (current->data > next->data)
				{
					temp = new SListNode<T>(current->data);
					current->data = next->data;
					next->data = temp->data;
					delete temp;
				}
				next = next->next;
			}
			current = current->next;
		}
	}

	// Function that displays the list.
	template<class T>
	void List<T>::display()
	{
		if (size() == -1)
			cout << "\nThere is nothing in the list.\n";

		else
		{
			SListNode<T> *tempPtr = head;

			//cout << fixed << showpoint << setprecision(2);
			while (tempPtr != NULL)
			{
				cout << tempPtr->data << ", ";
				tempPtr = tempPtr->next;
			}

			delete tempPtr;
		}

		cout << endl << endl;
	}

	// clears the entire list.
	template<class T>
	void List<T>::clear()
	{
		while (head)
		{
			SListNode<T> *tail = head;
			head = tail->next;
			delete tail;
		}
	}

	// Returns the size of the list, beginning at 1. 
	template<class T>
	int List<T>::size()
	{
		int counter = 1;

		// Checks to see if the pointer exists.
		if (!head)
			return -1;

		else
		{
			SListNode<T> *nodePtr = head;

			while (nodePtr->next != NULL)
			{
				nodePtr = nodePtr->next;
				counter++;
			}
		}

		return counter;
	}

	// Search function.
	template<class T>
	int List<T>::search(T val, T pos)
	{
		SListNode<T> *tempPtr = head;
		int counter = 0;

		while (tempPtr != NULL)
		{
			if (tempPtr->data == val)
				pos = counter;

			tempPtr = tempPtr->next;
			counter++;
		}

		return pos;
	}
}

#endif