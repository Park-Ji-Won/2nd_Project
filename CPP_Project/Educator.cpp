#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Educator.h"
using namespace std;

Educator::~Educator() {
	for (Student* s : students) {
		delete s;
	}
	students.clear();
}

void Educator::addStudents(Student* s) {
	for (Student* student : students) {
		if (student->getId() == s->getId()) {
			cout << ">> 이미 같은 학번(" << s->getId() << ")이 존재함!" << endl;
			return;
		}
	}
	students.push_back(s);
	cout << ">> " << s->getName() << " 학생이 추가됨." << endl;
}

void Educator::removeStudent(int id) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->getId() == id) {
			cout << ">> " << students[i]->getName() << " 학생 삭제 완료." << endl;
			delete students[i];
			students.erase(students.begin() + i);
			return;
		}
	}
	cout << ">> 학번 " << id << " 학생을 찾을수 없음." << endl;
}

Student* Educator::findStudent(int id) {
	for (Student* s : students) {
		if (s->getId() == id) {
			return s;
		}
	}
	return nullptr;
}

void Educator::viewAllStudents() {
	if (students.empty()) {
		cout << "\n등록된 학생이 없습니다." << endl;
		return;
	}

	cout << "\n========= 전체 학생 목록 =========" << endl;
	cout << "총 " << students.size() << "명" << endl;
	cout << "====================================" << endl;

	for (Student* s : students) {
		cout << "학번: " << s->getId() << endl;
		cout << "이름: " << s->getName() << endl;
		cout << "성별: " << s->getSex() << endl;
		cout << fixed << setprecision(1);
		cout << "평균: " << s->getAverage() << endl;
		cout << "학점: " << s->getGrade() << endl;
	}
	cout << "====================================\n" << endl;
}

void Educator::viewStudentDetail(int id) {
	Student* s = findStudent(id);
	if (s == nullptr) {
		cout << ">>학번 " << id << "인 해당 학생을 찾을 수 없음." << endl;
		return;
	}
	s->display();
}

void Educator::showStatistics() {
	if (students.empty()) {
		cout << "통계를 낼 학생이 없음." << endl;
		return;
	}

	double totalAvg = 0;
	double maxAvg = 0;
	double minAvg = 100;
	string topStudent = "";

	for (Student* s : students) {
		double avg = s->getAverage();
		totalAvg += avg;

		if (avg > maxAvg) {
			maxAvg = avg;
			topStudent = s->getName();
		}
		if (avg < minAvg) {
			minAvg = avg;
		}
	}
	cout << "\n========= 학생 전체 통계 ==========" << endl;
	cout << "학생 수: " << students.size() << "명" << endl;
	cout << fixed << setprecision(2);
	cout << "반 평균: " << totalAvg / students.size() << "점" << endl;
	cout << "최고점: " << maxAvg << "점 (" << topStudent << ")" << endl;
	cout << "최저점: " << minAvg << "점" << endl;
	cout << "====================================\n" << endl;
}

void Educator::showRanking() {
	if (students.empty()) {
		cout << "\n순위를 표시할 학생이 없음." << endl;
		return;
	}
	vector<Student*> sorted = students;

	sort(sorted.begin(), sorted.end(), [](Student* a, Student* b) {
		return a->getAverage() > b->getAverage();
		});
	
	cout << "\n=========== 성적 순위 =============" << endl;
	for (int i = 0; i < sorted.size(); i++) {
		cout << (i + 1) << "등: "
			<< sorted[i]->getName()
			<< " (" << sorted[i]->getId() << ") - "
			<< fixed << setprecision(2)
			<< sorted[i]->getAverage() << "점" << endl;
	}
	cout << "====================================\n" << endl;
}

void Educator::inputInfo() {
	cout << "\n=========== 교수 정보 입력 =============" << endl;
	cout << "첫 사용 확인." << "해당 정보를 입력하시오" << endl;

	string n, s, mj;
	int i;

	name = n;
	id = i;
	sex = s;
	major = mj;

	cout << "이름: ";
	cin.ignore();
	getline(cin, n);

	cout << "번호: ";
	cin >> i;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(900000000, '\n');
		cout << " >> 교수 번호는 숫자로만 입력가능." << endl;
		i = 198000001;
	}
	
	cout << "성별 :";
	cin.ignore();
	getline(cin, s);

	cout << "전공: ";
	cin.ignore();
	getline(cin, mj);

	cout << "\n 입력 완료." << endl;
}

void Educator::editInfo() {
	cout << "========= 교수 정보 입력 ==========" << endl;
	cout << "\n[현재 정보]" << endl;
	cout << "이름: " << name << endl;
	cout << "교번: " << id << endl;
	cout << "성별: " << sex << endl;
	cout << "전공: " << major << endl;

	cout << "\n 수정할 정보 선택" << endl;
	cout << "1.이름" << endl;
	cout << "2.학번" << endl;
	cout << "3.성별" << endl;
	cout << "4.전공" << endl;
	cout << "0.취소" << endl;
	cout << " 선택 >> ";

	int choice;
	cin >> choice;

	string newName, newSex, newMajor;
	int newId;

	switch (choice) {
	case 1:
		cout << "정정할 이름: ";
		cin.ignore();
		getline(cin, newName);
		name = newName;
		cout << " >> 이름이 변경됨." << endl;
		break;
	case 2:
		cout << "정정할 학번: ";
		cin >> newId;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(900000000, '\n');
			cout << ">> 학번은 숫자로 입력하시오." << endl;
			break;
		}
		id = newId;
		cout << " >> 학번이 변경됨." << endl;
		break;
	case 3:
		cout << "정정할 성별: ";
		cin.ignore();
		getline(cin, newSex);
		cout << " >> 성별이 변경됨." << endl;
		break;
	case 4:
		cout << "정정할 전공: ";
		cin.ignore();
		getline(cin, newMajor);
		cout << " >> 전공이 변경됨." << endl;
	case 0:
		cout << " >> 수정 취소." << endl;
		break;
	default:
		cout << " >> 잘못된 입력." << endl;
	}
}

void Educator::display() {
	cout << "\n============ 교수 목록 ============" << endl;
	cout << "이름: " << name << endl;
	cout << "교번: " << id << endl;
	cout << "성별: " << sex << endl;
	cout << "전공: " << major << endl;
	cout << "전담 학생: " << students.size() << "명" << endl;
	cout << "====================================\n" << endl;
}