#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;

class Student : public Person {
private:
	vector<string> subjects;
	vector<int> scores;
	int attendance = 0;
public:
	Student(string n, string s, int i) :Person(n, s, i) {}

	void display() override;

	string getType() override {
		return "학생";
	}

	void addScore(string subject, int score);
	double getAverage();
	string getGrade();

	void addAttendance() {
		attendance++;
	}

	int getAttendance() {
		return attendance;
	}

	void showScores();

};
#endif // !STUDENT_H
