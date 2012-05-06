// Class declaration and definition of the Stack template.
// Tyler Donaldson
// tylerdonaldson@hotmail.com
// 4/10/2012
// Stack Template
//
// This files defines a template for the Stack class.
//*****************************************************
// Functionality:
//		1. Add Values at the top.
//		2. Remove Values from the top.
//		3. Displays the current stack.
//		4. Ability to check if the stack is empty.
//		5. Able to destroy entire stack.
//		6. Able to reverse the contents of the stack.
//		7. Create an object with no initial value.
//		8. Create an object with one initial value.
//		9. Also have access to the value on the top.
//*****************************************************
#ifndef STACK_H
#define STACK_H

#include "nodes.h"
using Donaldson::SListNode;

namespace Donaldson
{
	template<class T>
	class Stack
	{
	private:
		int count;
	public:
		SListNode<T> *head;

		Stack();			// Base Constructor.
		Stack(T &val);		// Constructor with value param.
		~Stack();			// Destructor.
		void push(T &val);	// Adding a number at beginning.
		void pop();			// Removing number from beginning.
		bool isEmpty();		// Check to see if empty.
		void display();		// Display the stack.
		void destroy();		// Destroy the stack.
		int size();			// Gets the size of the stack.
		void reverse();		// Reverse the order of the stack.
		T currentVal();		// Returns first value.
	};

	// Constrcutor for constructor with no paramters.
	template<class T>
	Stack<T>::Stack()
	{
		head = NULL;
		count = 0;
	}

	// Constructor for Stack template.
	template<class T>
	Stack<T>::Stack(T &val)
	{
		head = new SListNode<T>(val);
	}

	// Destructor for Stack template.
	template<class T>
	Stack<T>::~Stack()
	{
		destroy();
	}

	// Adds a value to the top of the stack.
	template<class T>
	void Stack<T>::push(T &val)
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

	// Removes the value at the top of the stack.
	template<class T>
	void Stack<T>::pop()
	{
		if (head != NULL)
		{
			SListNode<T> *remove = head;
			head = head->next;
			delete remove;
		}
	}

	// Checks to see if the stack exists.
	template<class T>
	bool Stack<T>::isEmpty()
	{
		if (head != NULL)
			return false;

		else
			return true;
	}

	// Displays the stack from the top down.
	template<class T>
	void Stack<T>::display()
	{
		SListNode<T> *temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
	}

	// Destroys the Stack.
	template<class T>
	void Stack<T>::destroy()
	{
		while (head != NULL)
		{
			SListNode<T> *remove = head;
			head = remove->next;
			delete remove;
		}
	}

	// Returns the value that is currently accessible.
	template<class T>
	T Stack<T>::currentVal()
	{
		return head->data;
	}

	// Returns the size of the stack.
	template<class T>
	int Stack<T>::size()
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

	// Reverses the stack.
	template<class T>
	void Stack<T>::reverse()
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

}

#endif