#include <iostream>
#include <string>
#include "Educator.h"
using namespace std;

void showMainMenu();
void addStudentMenu(Educator& Edu);
void addScoreMenu(Educator& Edu);
void viewStudentMenu(Educator& Edu);
void deleteStudentMenu(Educator& Edu);
void editStudentMenu(Educator& Edu);
Educator* createEducator();
void clearScreen();
void pause();

void showMainMenu() {
	clearScreen();
	cout << "==========================================" << endl;
	cout << "|         학생 성적 관리 시스템          |" << endl;
	cout << "==========================================" << endl;
	cout << "|         [  학    생  ]                 |" << endl;
	cout << "|         1. 학생 추가                   |" << endl;
	cout << "|         2. 성적 입력                   |" << endl;
	cout << "|         3. 학생 상세 정보 조회         |" << endl;
	cout << "|         4. 전체 학생 목록              |" << endl;
	cout << "|         5. 반 통계 보기                |" << endl;
	cout << "|         6. 성적 순위 보기              |" << endl;
	cout << "|         7. 등록된 학생 삭제            |" << endl;
	cout << "|         8. 등록된 학생 정정            |" << endl;
	cout << "|         [  교    수  ]                 |" << endl;
	cout << "|         9. 교수 정보                   |" << endl;
	cout << "|        10. 교수 정보 정정              |" << endl;
	cout << "|         0. 종료                        |" << endl;
	cout << "==========================================" << endl;
}

void addStudentMenu(Educator& Edu) {
	clearScreen();
	cout << "========= 학생 추가 =========" << endl;

	string name, sex, major;
	int id;

	cout << "이름: ";
	cin.ignore();
	getline(cin, name);

	cout << "학번: ";
	if (cin.fail()) {
		cin.clear();
		cin.ignore(9000, '\n');
		cout << " >> 해당 대상에 맞게 입력하시오" << endl;
		pause();
		return;
	}
	cin >> id;

	cout << "성별: ";
	cin.ignore();
	getline(cin, sex);

	cout << "전공: ";
	cin.ignore();
	getline(cin, major);

	Student* newStudent = new Student(name, id, sex, major);
	Edu.addStudents(newStudent);

	pause();
}

void addScoreMenu(Educator& Edu) {
	clearScreen();
	cout << "========= 성적 입력 =========" << endl;

	if (Edu.getStudentCount() == 0) {
		cout << ">> 등록된 학생 없음."
			<< "학생을 추가 필요." << endl;
		pause();
		return;
	}

	int id;
	cout << "학번: ";
	cin >> id;

	Student* s = Edu.findStudent(id);
	if (s == nullptr) {
		cout << " >> 해당 학번의 학생 없습니다." << endl;
		pause();
		return;
	}

	cout << "\n" << s->getName() << " 학생의 성적을 입력하시오." << endl;

	while (true) {
		string subject;
		int score;

		cout << "\n과목명 (0 입력시 종료) : ";
		cin >> subject;
		if (subject == "0")
			break;

		cout << "점수: ";
		cin >> score;

		if (cin.fail() || score < 0 || score>100) {
			cin.clear();
			cin.ignore(1000,'\n');
			cout << " >> 0~100 사이의 점수를 입력하시오." << endl;
			continue;
		}
		s->addScore(subject, score);
	}
	cout << "\n 성적 입력이 완료됨." << endl;
	pause();
}

void viewStudentMenu(Educator& Edu) {
	clearScreen();
	cout << "========= 학생 상세 정보 =========" << endl;

	if (Edu.getStudentCount() == 0) {
		cout << ">> 등록된 학생이 없음." << endl;
		pause();
		return;
	}

	int id;
	cout << "학번: ";
	cin >> id;

	Edu.viewStudentDetail(id);
	pause();
}

void deleteStudentMenu(Educator& Edu) {
	clearScreen();
	cout << "========= 등록된 학생 삭제 =========" << endl;

	if (Edu.getStudentCount() == 0) {
		cout << ">> 등록된 학생이 없음" << endl;
		pause();
		return;
	}

	int id;
	cout << "삭제할 학생 학번 : ";
	cin >> id;

	cout << "삭제 확인(y/n) : ";
	char confirm;
	cin >> confirm;

	if (confirm == 'y' || confirm == 'Y') {
		Edu.removeStudent(id);
	}
	else {
		cout << " >> 삭제 취소" << endl;
	}
	pause();
}

void editStudentMenu(Educator& Edu) {
	clearScreen();

	if (Edu.getStudentCount() == 0) {
		cout << " >> 등록된 학생 없음." << endl;
		pause();
		return;
	}

	int id;
	cout << "정정할 학생 학번: ";
	cin >> id;

	Student* s = Edu.findStudent(id);
	if (s == nullptr) {
		cout << " >> 해당 학번의 학생을 찾을수 없음." << endl;
		pause();
		return;
	}
	s->editInfo();
	pause();
}

Educator* createEducator() {
	clearScreen();

	Educator* Edu = new Educator("", 0, "", "");
	Edu->inputInfo();

	pause();
	return Edu;
}

void clearScreen() {
	system("cls");
}

void pause() {
	cout << "\n 계속하려면 Enter...";
	cin.ignore();
	cin.get();
}

int main() {
	int ch;

	while (true) {
		showMainMenu();
		cout << "기능 선택 >>";
		cin >> ch;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\n>> 기능에 해당하는 숫자 입력" << endl;
			pause();
			continue;
		}

		switch (ch) {
		case 1:
			addStudentMenu(*Edu);
			break;
		case 2:
			addScoreMenu(*Edu);
			break;
		case 3:
			viewStudentMenu(*Edu);
			break;
		case 4:
			clearScreen();
			Edu.viewAllStudents();
			pause();
			break;
		case 5:
			clearScreen();
			Edu.showStatistics();
			pause();
			break;
		case 6:
			clearScreen();
			Edu.showRanking();
			pause();
			break;
		case 7:
			deleteStudentMenu(*Edu);
			break;
		case 8:
			editStudentMenu(*Edu);
			break;
		case 9:
			clearScreen();
			Edu.display();
			break;
		case 10:
			createEducator();
			Edu.editInfo();
			pause();
			break;
		case 0:
			cout << "\n 프로그램 종료." << endl;
			delete Edu;
			return 0;
		default:
			cout << "\n >> 잘못된 선택임."
				<< "\n다시 선택하시오 >>" << endl;
			pause();
		}
	}
	delete Edu;
	return 0;
}