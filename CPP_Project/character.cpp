#include "character.h"

character::character(string name, int level) {
	this->name = name;
	this->level = level;
	this->maxhp = 150 + (level - 1) * 20;
	this->hp = maxhp;
	this->attack = 15 + (level - 1) * 5;
	this->defense = 10 + (level - 1) * 5;
	this->exp = 0;
	this->maxexp = level * 100;
}

character::~character() {
	cout << name << " 캐릭터 삭제" << endl;
}

void character::takedamage(int damage) {
	int realdamage = damage - defense;
	
	if (realdamage < 1) {
		realdamage = 1;
	}
	hp -= realdamage;

	if (hp < 0) {
		hp = 0;
	}

	cout << name << "이" << realdamage << " 타격을 입었습니다.";
	cout << "[남은 체력: " << hp << "|" << maxhp << "]" << endl;
}

void character::gainexp(int amount) {
	exp += amount;
	cout << name << "이 경험치 " << amount << "를 획득함." << endl;

	if (exp >= maxexp) {
		levelup();
	}
}

void character::levelup() {
	level++;
	exp = 0;

	int hpupgrade = 10;
	int attackupgrade = 5;
	int defensceupgrade = 5;

	maxhp += hpupgrade;
	hp = maxhp;
	attack += attackupgrade;
	defense += defensceupgrade;
	maxexp = level * 100;

	cout << "레벨이 올랐습니다." << endl;
	cout << name << "이 레벨" << level << "됬습니다" << endl;
	cout << "체력 " << hpupgrade << "증가" << "[최대 체력: " << maxhp << "]" << endl;
	cout << "공격력 " << attackupgrade << "증가" << "[현재 공격력: " << attack << "]" << endl;
	cout << "방어력 " << defensceupgrade << "증가" << "[현재 방어력: " << attack << "]" << endl;
	cout << "체력이 재생되었습니다." << endl;
}