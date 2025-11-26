#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
using namespace std;

class character {
protected:
	string name;
	int level;
	int hp;
	int maxhp;
	int attack;
	int defense;
	int exp;
	int maxexp;
public:
	character(string name, int level);
	virtual ~character();

	virtual void showstat() = 0;
	virtual int attacktarget() = 0;

	void takedamage(int damage);
	bool isLive() const;
	void heal(int amount);
	void gainexp(int amount);
	void levelup();

	string getname() const {
		return name;
	}
	int getlevel() const {
		return level;
	}
	int getmaxhp() const {
		return maxhp;
	}
	int getattack() const {
		return attack;
	}
	int getdefense() const {
		return defense;
	}
};
#endif // !CHARACTER_H

