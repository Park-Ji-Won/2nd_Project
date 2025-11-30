#ifndef EDUCATOR_H
#define EDUCATOR_H

#include "Person.h"
#include "Student.h"
#include <vector>
using namespace std;

class Educator : public Person {
private:
	string major;
	vector<Student*> students;
public:
	Educator(string n, int i, string s, string mj) : Person(n, i, s), major(mj) {}
	~Educator();

	void display() override;
	string getType() override {
		return "교수";
	}

	void addStudents(Student* s);
	void removeStudent(int id);
	Student* findStudent(int id);

	void viewAllStudents();
	void viewStudentDetail(int id);
	
	void showStatistics();
	void showRanking();

	int getStudentCount() {
		return students.size();
	}
};
#endif // !EDUCATOR_H
