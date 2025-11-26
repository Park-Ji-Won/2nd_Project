#include <iostream>
#include "character.h"
using namespace std;

class test1character : public character {
public:
	test1character(string name, int level) :character(name, level) {}

	void showstat() override {
		cout << "--------능력치----------------" << endl;
		cout << "이름: " << name << endl;
		cout << "레벨: " << level << endl;
		cout << "체력: " << hp << "|" << maxhp << endl;
		cout << "공격력: " << attack << endl;
		cout << "방어력: " << defense << endl;
		cout << "경험치: " << exp << "|" << maxexp << endl;
		cout << "------------------------------" << endl;
	}

	int attacktarget() override {
		cout << name << "의 공격" << endl;
		return attack;
	}
};

int main() {
	cout << "---클래스 테스트---" << endl;

	test1character hero("생존자", 1);
	test1character enomy("구울", 1);

	hero.showstat();
	enomy.showstat();

	cout << "싸움" << endl;

	int damage = hero.attacktarget();
	enomy.takedamage(damage);


}