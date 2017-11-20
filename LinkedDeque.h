/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #1  : Linked List & Palindrome
*	CLASS      : CS1D
*	SECTION    : 6-10p T-Th
*	DUE DATE   : 1/22/2014
*******************************************************************************/

#ifndef LINKEDDEQUE_H_
#define LINKEDDEQUE_H_


/*******************************************************************************
 * CLASS linkedDeque
 * -----------------------------------------------------------------------------
 * 	Wrapper class that uses Linked List Template for this deque.
 ******************************************************************************/
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>
using namespace std;


template <class qType>
class LinkedDeque
{
	public:
		LinkedDeque();
		~LinkedDeque();

		// MUTATORS
		// pushBack - Adds data to end of deque
		void 	pushBack(qType someType);
		// pushFront - Adds data to front of deque
		void 	pushFront(qType someType);
		// popFront - deletes and returns data from front of deque
		qType 	popFront();
		// popBack - deletes and returns data from end of deque
		qType 	popBack();


		// Accessors
		// Obtains data from front of deque
		qType 	front();
		// Obtains data from back of deque
		qType   back();
		// Obtains size of deque
		int 	size();
		// Determines if deque is empty
		bool 	isEmpty();
		// Outputs deque to specified output location
		void 	print(ostream& os);
	private:
		LinkedList<qType> theDeque;
};


// Constructor
template <class qType>
LinkedDeque<qType>::LinkedDeque()
{
}

// Destructor
template <class qType>
LinkedDeque<qType>::~LinkedDeque()
{
}

// Mutators
template <class qType>
void LinkedDeque<qType>::pushBack(qType someType)
{
	theDeque.addEnd(someType);
}

// Mutators
template <class qType>
void LinkedDeque<qType>::pushFront(qType someType)
{
	theDeque.addFront(someType);
}

template <class qType>
qType LinkedDeque<qType>::popFront()
{
	qType removed;
	if(!isEmpty())
	{
		removed = front();
		theDeque.deleteFront();
	}

	return removed;
}

template <class qType>
qType LinkedDeque<qType>::popBack()
{
	qType removed;
	if(!isEmpty())
	{
		removed = back();
		theDeque.deleteEnd();
	}

	return removed;
}

// Accessors
template <class qType>
qType LinkedDeque<qType>::front()
{

	return theDeque.peek(0);
}

template <class qType>
qType LinkedDeque<qType>::back()
{
	return theDeque.peek(theDeque.getSize()-1);
}

template <class qType>
int LinkedDeque<qType>::size()
{
	return theDeque.getSize();
}

template <class qType>
bool LinkedDeque<qType>::isEmpty()
{
	return theDeque.isEmpty();
}

template <class qType>
void LinkedDeque<qType>::print(ostream& os)
{
	theDeque.print(os);
}

#endif /* LINKEDDEQUE_H_ */
