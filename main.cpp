//Roman Morasco
//CS111 Project 6
//Goal: Create a linked list of student's exam data in a stack

#include <iomanip>
#include <fstream>
#include "ExamClass.h"
#include "ExamStack.h"



//Pre-condition: Head is a null pointer
//Post-condition: A linked list is formed with the data read in from the file
void readData(ExamStack &h); //must pass by reference 

//Pre-condition: none
//Post-condition: Prints each examclass and the stack is emptied 
void printResults(ExamStack &h);


int main(void) {
	ExamStack stack;
	
	readData(stack);

	printResults(stack);
	

	return 0;
}

void readData(ExamStack &h) {
	//declaring variables that will be read in and passed into the class setters in the while loop below
	std::string name = "Undefined";
	float e1 = 0.0, e2 = 0.0, e3 = 0.0;

	std::ifstream inputFile; //declaring input file stream variable

	//opening file
	inputFile.open("data.txt");

	//check to see if file opened
	if (inputFile.fail()) {
		std::cout << "File did not open. \n"; //Display to user
		exit(1); //exits with error code 1
	}

	//checks to see if the file peek is also the same as the end of file, in which case there would be no content in the file
	if (inputFile.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "File is empty. \n"; //Display to user
		exit(1); //exits with error code 1
	}

	//while loop to input from the file until theres nothing left to input
	while (inputFile >> name >> e1 >> e2 >> e3) {
		ExamClassPtr student = new ExamClass(name, e1, e2, e3); //new pointer to ExamClass, aka allocating memory for the new object

		h.push(student); //add object to the stack
	}

	//closing file
	inputFile.close();
}


void printResults(ExamStack &h) {
	//output column titles
	std::cout << "Name: " << "\t   Student Average: " << std::endl;
	std::cout << "-------------------------------------\n"; //formatting
	while (!h.isEmpty()) {
		ExamClassPtr t = h.pop(); //set a temp pointer equal to the returned node from pop
		std::cout << std::fixed << std::setprecision(2);
		std::cout << std::left << t->getStudentName() << "\t"; //output node's name
		std::cout << std::right << t->getStudentAverage() << "\t \n"; //output node's average
		t->setNext(NULL); //make sure node's next is not pointing to an item
		delete t; //delete the node from list
	}

	std::cout << std::endl; //ouput whitespace
}

