#include <iostream>
#include "character.h"
using namespace std;

class test1character : public character {
public:
	test1character(string name, int level) :character(name, level) {}

	void showstat() override {
		cout << "--------능력치---------" << endl;
		cout << "이름: " << name << endl;
		cout << "레벨: " << level << endl;

	}
};