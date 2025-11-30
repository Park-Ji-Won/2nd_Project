#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
	string name;
	int id;
	string sex;
public:
	Person(string n, int i, string s) :name(n), id(i), sex(s) {}
	virtual ~Person() {}

	virtual void display() = 0;
	virtual string getType() = 0;

	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
	string getSex() {
		return sex;
	}
};
#endif // !PERSON_H

