#ifndef EDUCATOR_H
#define EDUCATOR_H

#include <vector>
#include <algorithm>
#include "Person.h"
#include "Student.h"
using namespace std;

class Educator : public Person {
private:
	vector<Student*> students;
public:
	Educator(string n, int i, string s, string mj) : Person(n, i, s, mj) {}
	~Educator();

	void display() override;
	string getType() override {
		return "교수";
	}

	int getStudentCount() const {
		return students.size();
	}
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

	void inputInfo();
	void editInfo();

	void addStudents(Student* s);
	void removeStudent(int id);
	Student* findStudent(int id);
	void viewAllStudents();
	void viewStudentDetail(int id);
	void showStatistics();
	void showRanking();

	vector<Student*>& getStudents() {
		return students;
	}
};
#endif // !EDUCATOR_H
