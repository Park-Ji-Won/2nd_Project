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
	Student(string n, int i, string s, string mj) : Person(n, i, s, mj) {}

	void display() override;

	string getType() override {
		return "학생";
	}

	void editInfo();
	void setName(string n) {
		name = n;
	}
	void setId(int i) {
		id = i;
	}
	void setSex(string s) {
		sex = s;
	}
	void setMajor(string mj) {
		major = mj;
	}

	void addScore(string subject, int score);
	double getAverage();
	string getGrade();
	void showScores();

	void addAttendance() {
		attendance++;
	}

	int getAttendance() {
		return attendance;
	}
};
#endif // !STUDENT_H
