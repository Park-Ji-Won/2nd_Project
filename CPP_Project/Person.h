#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
	string name, sex, major;
	int id;
public:
	Person(string n, int i, string s, string mj) :name(n), id(i), sex(s), major(mj) {}
	virtual ~Person() {}

	virtual void display() = 0;
	virtual string getType() = 0;

	string getName() const {
		return name;
	}
	int getId() const {
		return id;
	}
	string getSex() const {
		return sex;
	}
	string getMajor() const {
		return major;
	}
};
#endif // !PERSON_H

