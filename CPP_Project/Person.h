#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
	string name;
	string sex;
	int id;
public:
	Person(string n, string s, int i) :name(n), sex(s), id(i) {}
	virtual ~Person() {}

	virtual void display() = 0;
	virtual string getType() = 0;

	string getName() {
		return name;
	}
	string getSex() {
		return sex;
	}
	int getId() {
		return id;
	}
};
#endif // !PERSON_H

