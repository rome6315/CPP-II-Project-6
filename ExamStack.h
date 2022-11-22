#pragma once
#include "ExamClass.h"



class ExamStack {
private:
	ExamClassPtr head;
	void deleteStack();
public:
	ExamStack(); //default constructor
	~ExamStack(); //destructor
	void push(ExamClassPtr &examClass); //push item onto linked list (aka head insert)
	ExamClassPtr pop(); //remove item from linked list
	bool isEmpty(); //check if linked list is empty
};