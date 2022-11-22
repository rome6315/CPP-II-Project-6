#include <iostream>
#include "ExamClass.h"


//default constructor
ExamClass::ExamClass() {
	studentName = "Undefined";
	exam1Score = 0.0;
	exam2Score = 0.0;
	exam3Score = 0.0;
	next = NULL;
	setStudentAverage();
}

ExamClass::ExamClass(std::string name, float e1, float e2, float e3) {
	studentName = name;
	exam1Score = e1;
	exam2Score = e2;
	exam3Score = e3;
	next = NULL;
	setStudentAverage();
}

//destructor
ExamClass::~ExamClass() {
	std::cout << "Removed: " << studentName << std::endl;
}

//set student names
void ExamClass::setStudentName(std::string name) {
	studentName = name;
}

//set next pointer
void ExamClass::setNext(ExamClass* ptr) {
	next = ptr;
}

//set exam 1 score
void ExamClass::setExam1Score(float e1) {
	exam1Score = e1;
	setStudentAverage();
}

//set exam 2 score
void ExamClass::setExam2Score(float e2) {
	exam1Score = e2;
	setStudentAverage();
}

//set exam 3 score
void ExamClass::setExam3Score(float e3) {
	exam1Score = e3;
	setStudentAverage();
}

//set student average
void ExamClass::setStudentAverage() {
	studentAverage = (exam1Score + exam2Score + exam3Score) / (float)3.0;
}

//get student names
std::string ExamClass::getStudentName() {
	return studentName;
}

//get student exam scores
//convenience for class average function
float ExamClass::getExamScoresTotal() {
	return exam1Score + exam2Score + exam3Score;
}

//get student average
float ExamClass::getStudentAverage() {
	return studentAverage;
}

//get next item in list
ExamClass* ExamClass::getNext() {
	return next;
}