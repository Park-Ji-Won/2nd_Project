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
			cout << ">> " << students[i]->getName() << " 학생 삭제 진행됨." << endl;
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
	cout << "==================================" << endl;

	for (Student* s : students) {
		cout << "학번: " << s->getId() << endl;
		cout << "이름: " << s->getName() << endl;
		cout << "성별: " << s->getSex() << endl;
		cout << fixed << setprecision(1);
		cout << "평균: " << s->getAverage() << endl;
		cout << "학점: " << s->getGrade() << endl;
	}
	cout << "==================================\n" << endl;
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
		cout << "통계를 낼 해당 학생이 없음." << endl;
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
	cout << "\n======== = 학생 전체 통계 ========" << endl;
	cout << "학생 수: " << students.size() << "명" << endl;
	cout << fixed << setprecision(2);
	cout << "반 평균: " << totalAvg / students.size() << "점" << endl;
	cout << "최고점: " << maxAvg << "점 (" << topStudent << ")" << endl;
	cout << "최저점: " << minAvg << "점" << endl;
	cout << "==================================\n" << endl;
}

void Educator::showRanking() {
	if (students.empty()) {
		cout << "순위를 표시할 학생이 없음." << endl;
		return;
	}
	vector<Student*> sorted = students;

	sort(sorted.begin(), sorted.end(), [](Student* a, Student* b) {
		return a->getAverage() > b->getAverage();
		});
	
	cout << "\n========= 성적 순위 =========" << endl;
	for (int i = 0; i < sorted.size(); i++) {
		cout << (i + 1) << "등: "
			<< sorted[i]->getName()
			<< " (" << sorted[i]->getId() << ") - "
			<< fixed << setprecision(2)
			<< sorted[i]->getAverage() << "점" << endl;
	}
	cout << "==================================\n" << endl;
}

void Educator::display() {
	cout << "\n========= 교수 정보 =========" << endl;
	cout << "이름: " << name << endl;
	cout << "성별: " << sex << endl;
	cout << "교수코드: " << id << endl;
	cout << "학과: " << major << endl;
	cout << "담당 학생수: " << students.size() << "명" << endl;
	cout << "==================================\n" << endl;
}