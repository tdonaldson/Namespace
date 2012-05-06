// Class declaration and definition of Queue class.
// Tyler Donaldson
// tylerdonaldson@hotmail.com
// 4/10/2012
// Queue Template
//
// This file contains the definition of the Queue functions.
//*****************************************************
// Functionality:
//		1. Add value at the end of the queue.
//		2. Remove values at the beginning of the queue.
//		3. Check to see if the queue is empty.
//		4. Able to destroy the entire queue.
//		5. Can display the entire queue.
//		6. Create an object with no initial value.
//		7. Create an object with one initial value.
//*****************************************************
#ifndef QUEUE_H
#define QUEUE_H

#include "nodes.h"
using Donaldson::SListNode;
#include <iostream>

namespace Donaldson
{
	template<class T>
	class Queue
	{
	private:
		int count;
	public:
		SListNode<T> *head;
		Queue();				// Base Constructor.
		Queue(T &val);			// Constructor with val param.
		~Queue();				// Destructor.
		void enqueue(T &val);	// Add at end.
		void dequeue();			// Remove at beginning.
		bool isEmpty();			// Checks to see if empty.
		void display();			// Displays the queue.
		void destroy();			// Destroys the queue.
		int size();				// Returns the size.
		void reverse();			// Reverses the queue.
		T currentVal();			// Returns first value.
	};

	// Constrcutor with no parameters.
	template<class T>
	Queue<T>::Queue()
	{
		head = NULL;
	}

	// Constructor with 1 parameter queue template.
	template<class T>
	Queue<T>::Queue(T &val)
	{
		head = new SListNode<T>(val);
	}

	// Destructor for queue template.
	template<class T>
	Queue<T>::~Queue()
	{
		destroy();
	}

	// Add values to the queue.
	template<class T>
	void Queue<T>::enqueue(T &val)
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

	// Delete values from the queue.
	template<class T>
	void Queue<T>::dequeue()
	{
		SListNode<T> *temp = head;
		if (temp != NULL)
		{
			head = temp->next;
			delete temp;
		}
	}

	// Check to see if the queue is empty.
	template<class T>
	bool Queue<T>::isEmpty()
	{
		if (head == NULL)
			return true;
		else
			return false;
	}

	// Displays the queue.
	template<class T>
	void Queue<T>::display()
	{
		SListNode<T> *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
	}

	// Destroys the queue.
	template<class T>
	void Queue<T>::destroy()
	{
		while (head)
		{
			SListNode<T> *garbage = head;
			head = garbage->next;
			delete garbage;
		}
	}
	
	// Returns the size of the queue.
	template<class T>
	int Queue<T>::size()
	{
		count = 0;
		SListNode<T> *temp = head;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}

		return count;
	}

	// Reverses the queue.
	template<class T>
	void Queue<T>::reverse()
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
	// Returns the value that is currently accessible.
	template<class T>
	T Queue<T>::currentVal()
	{
		return head->data;
	}
}

#endif