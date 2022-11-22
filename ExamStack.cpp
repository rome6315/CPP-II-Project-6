#include "ExamStack.h"

ExamStack::ExamStack() {
	head = NULL;
}

ExamStack::~ExamStack() {
	std::cout << "Stack destructor ran. \n";
	deleteStack();
}

void ExamStack::deleteStack() {
	while (head != NULL) {
		ExamClassPtr temp = head; //set a temp pointer to point to where head does
		head = head->getNext(); //iterate head to the next item in the list
		temp->setNext(NULL); //make sure temp's next doesn't point to anything
		delete temp; //delete temp, this calls the destructor 
	}
}

void ExamStack::push(ExamClassPtr& examClass) {
	examClass->setNext(head); //new item's(examClass's) next will point to head
	head = examClass; //head is moved to point to new item(examClass) now
	examClass = NULL; //prevent dangling pointer
}

ExamClassPtr ExamStack::pop() {
	if (isEmpty()) {
		std::cout << "Stack is empty. \n";
		return NULL; //if list is empty
	}
	ExamClassPtr temp = head; //set item that we want to remove to point to head
	head = head->getNext(); //iterate head to next item on list
	temp->setNext(NULL); //make sure this temp item's next points to NULL
	return temp; //return the popped item

}

bool ExamStack::isEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}