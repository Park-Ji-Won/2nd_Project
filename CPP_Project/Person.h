#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
	string name;
	int id;
public:
	Person(string n, int i) :name(n), id(i) {}
	virtual ~Person() {}

	virtual void display() = 0;
	virtual string getType() = 0;

	string getName() {
		return name;
	}
	int getId() {
		return id;
	}
};
#endif // !PERSON_H

