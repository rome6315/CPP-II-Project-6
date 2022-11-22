#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>


class ExamClass {
private:
	std::string studentName;
	float exam1Score;
	float exam2Score;
	float exam3Score;
	float studentAverage;
	ExamClass* next;
	void setStudentAverage(); //set students average
public:
	//default constructor
	ExamClass();
	//specific constructor
	ExamClass(std::string name, float e1, float e2, float e3);
	//destructor
	~ExamClass();

	//set student names
	void setStudentName(std::string name);
	//set exam 1 score
	void setExam1Score(float e1);
	//set exam 2 score
	void setExam2Score(float e2);
	//set exam 3 score
	void setExam3Score(float e3);
	//set next pointer
	void setNext(ExamClass* ptr);

	//get student names
	std::string getStudentName();
	//get student exam scores
	float getExamScoresTotal();
	//get student average
	float getStudentAverage();
	//get next item in list
	ExamClass* getNext();
};

typedef ExamClass* ExamClassPtr; //define a "variable type" that points to ExamClass class