/*******************************************************************************
*	AUTHOR	   : Jeffrey Lo
*	STU ID#	   : 374780
*	ASSIGN #1  : Linked List & Palindrome
*	CLASS      : CS1D
*	SECTION    : 6-10p T-Th
*	DUE DATE   : 1/22/2014
*******************************************************************************/

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/*******************************************************************************
 * CLASS LinkedList
 * ----------------------------------------------------------------------------
 * This class is a template for a Double-Ended Linked List.
 ******************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

/*******************************************************************************
 * STRUCT nodeType
 * ----------------------------------------------------------------------------
 * This struct is the node for the linked list. Contains a datatype for the
 * list, a pointer to the next, and a pointer to the previous.
 ******************************************************************************/
template <class listType>
struct nodeType{
	listType data;
	nodeType* next;
	nodeType* prev;
};

template <class listType>
class LinkedList{
	public:
		LinkedList();
		~LinkedList();

		// MUTATORS
		// Adds to back of list
		void addEnd(listType nodeData);
		// Adds to front of list
		void addFront(listType nodeData);
		// Adds to specified index in list
		void insert(listType nodeData, int index);
		// Deletes from the front of list
		bool deleteFront();
		// Deletes from the back of list
		bool deleteEnd();
		// Delete specific item in list
		bool deleteNode(int index);
		//Delete Whole List:
		void deleteAll();

		// ACCESSORS
		// Obtains the current size of the linked list
		int  getSize() const;
		// Determines if linked list is empty
		bool isEmpty() const;
		// Prints the linked list to specified output
		void print(ostream& os) const;
		// Allows user to view node data of specified index
		listType peek(int index) const;

	private:
		int size;
		nodeType<listType>* head;
		nodeType<listType>* tail;
};

// Constructor
template <class listType>
LinkedList<listType>::LinkedList(){
	head = NULL;
	tail = NULL;
	size = 0;
}

// Destructor
template <class listType>
LinkedList<listType>::~LinkedList(){
	while(!isEmpty()){
		this->deleteAll();
	}
	delete head;
	delete tail;
}

// M U T A T O R S

//addEnd - Adds to END of list
template <class listType>
void LinkedList<listType>::addEnd (listType nodeData){
	nodeType<listType>* temp = new nodeType<listType>;
	temp->data = nodeData;

	if(isEmpty()){
		head = temp;
		temp->next = NULL;
		temp->prev = NULL;
		tail = temp;
		++size;
	}
	else{
		tail->next = temp;
		temp->prev = tail;
		temp->next = NULL;
		tail = temp;
		++size;
	}
}

//addFront - Adds to FRONT of list
template <class listType>
void LinkedList<listType>::addFront(listType nodeData){
	nodeType<listType>* temp = new nodeType<listType>;
	temp->data = nodeData;

	if(isEmpty()){
		temp->next = NULL;
		temp->prev = NULL;
		head = temp;
		tail = temp;
		++size;
	}
	else{
		temp->prev = NULL;
		temp->next = head;
		head->prev = temp;
		head = temp;
		++size;
	}
}

//insert - Inserts node to specified index
template <class listType>
void LinkedList<listType>::insert(listType nodeData, int index){
	nodeType<listType>* temp = new nodeType<listType>;
	temp->data = nodeData;

	int count = 0;
	bool added = false;

	if(isEmpty()){
		head = temp;
		temp->next = NULL;
		temp->prev = NULL;
		tail = temp;
		++size;
		added = true;
	}
	else if(index == 0){
		this->addFront(temp->data);
	}
	else if(index == size-1){
		this->addEnd(temp->data);
	}
	else{
		nodeType<listType>* incrementor = head;
		while(!added && count < size){
			if(count != index){
				incrementor = incrementor->next;
				++count;
			}
			else{
				incrementor->prev->next = temp;
				temp->prev = incrementor->prev;
				temp->next = incrementor;
				incrementor->prev = temp;
				++size;
				added = true;
			}
		}
	}
}

//deleteFront - Deletes front element on list
template <class listType>
bool LinkedList<listType>::deleteFront(){
	bool hasDeleted = false;
	if(!isEmpty()){
		nodeType<listType>* temp = head;
		if(head == tail){
			head = NULL;
			tail = NULL;
			--size;
		}
		else{
			head->next->prev = NULL;
			head = head->next;
			--size;
		}
		delete temp;

		hasDeleted = true;
	}
	else{
		cout << "List is empty -- Nothing to delete" << endl;
	}
	return hasDeleted;
}

//deleteEnd - Deletes end element on list
template <class listType>
bool LinkedList<listType>::deleteEnd(){
	bool hasDeleted = false;
	if(!isEmpty()){
		nodeType<listType>* temp = tail;
		if(head == tail){
			head = NULL;
			tail = NULL;
			--size;
		}
		else{
			tail->prev->next = NULL;
			tail = tail->prev;
			--size;
		}
		delete temp;
		hasDeleted = true;
	}
	else{
		cout << "List is empty -- Nothing to delete" << endl;
	}
	return hasDeleted;
}


template <class listType>
bool LinkedList<listType>::deleteNode(int index){
	bool hasDeleted = false;
	int count = 0;

	if(!isEmpty()){
		if(index == 0){
			hasDeleted = this->deleteFront();
		}
		else if(index == size-1){
			hasDeleted = this->deleteEnd();
		}
		else{
			nodeType<listType>* incrementor = head;
			while(!hasDeleted && count < size){
				if(count != index){
					incrementor = incrementor->next;
					++count;
				}
				else{
					incrementor->prev->next = incrementor->next;
					incrementor->next->prev = incrementor->prev;
					incrementor->next = NULL;
					incrementor->prev = NULL;
					delete incrementor;
					--size;
					hasDeleted = true;
				}
			}// End While
		}
	}//End If
	if(hasDeleted == false){
		cout << "Invalid index - out of bounds" << endl;
	}
	return hasDeleted;
}

//deleteAll - deletes entire list
template <class listType>
void LinkedList<listType>::deleteAll(){
	while(!isEmpty()){
		this->deleteFront();
	}
}

// A C C E S S O R S
//isEmpty - checks if list is empty
template <class listType>
bool LinkedList<listType>::isEmpty() const{
	return head==NULL;
}

//getSize - gets the size of the list
template <class listType>
int LinkedList<listType>::getSize() const{
	return size;
}

//print - prints the list
template <class listType>
void LinkedList<listType>::print(ostream& os) const{
	nodeType<listType>* temp = head;
	if(isEmpty()){
		os << "List is Empty" << endl;
	}
	else{
		for(int index = 0; index < size; index++){
			os << " " << temp->data;
			temp = temp->next;
		}
		cout << endl;
	}
}

//peek - gets data from specified index
template <class listType>
listType LinkedList<listType>::peek(int index) const{
	nodeType<listType>* temp;

	if(index < size){
		temp = head;
		int i = 0;
		while(i<index){
			temp = temp->next;
			i++;
		}

	}
	else{
		cout << "ERROR - index out of bounds";
		temp = NULL;
	}
	return temp->data;
}


#endif /* LINKEDLIST_H_ */
