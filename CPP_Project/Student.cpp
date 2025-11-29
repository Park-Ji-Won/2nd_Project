#include "Student.h"
#include <iomanip>

void Student::addScore(string subject, int score) {
	for (int i = 0; i < subjects.size(); i++) {
		if (subjects[i] == subject) {
			scores[i] = score;
			cout << ">> " << subject << "의 점수는 " << score << " 점으로 수정됨." << endl;
			return;
		}
	}
	subjects.push_back(subject);
	scores.push_back(score);
	cout << ">> " << subject << " " << score << "점 추가됨." << endl;
}

double Student::getAverage() {
	if (scores.empty()) {
		return 0.0;
	}
	int sum = 0;
	for (int score : scores) {
		sum += score;
	}
	return (double)sum / scores.size();
}

string Student::getGrade() {
	double avg = getAverage();

	if (avg >= 95)
		return "A+";
	else if (avg >= 90)
		return "A";
	else if (avg >= 85)
		return "A-";
	else if (avg >= 80)
		return "B+";
	else if (avg >= 75)
		return "B";
	else if (avg >= 70)
		return "B-";
	else if (avg >= 65)
		return "C+";
	else if (avg >= 60)
		return "C";
	else if (avg >= 55)
		return "C-";
	else if (avg >= 50)
		return "D+";
	else if (avg >= 45)
		return "D";
	else if (avg >= 40)
		return "D-";
	else
		return "F";

}

void Student::showScores() {
	if (subjects.empty()) {
		cout << " 성적이 등록되지 않음." << endl;
		return;
	}
	cout << "=====================" << endl;
	for (int i = 0; i < subjects.size(); i++) {
		cout << "" << subjects[i] << " : " << scores[i] << " 점" << endl;
	}
	cout << "=====================" << endl;
}

void Student::display() {
	cout << "======== 선택된 학생 정보 ========" << endl;
	cout << "이름: " << name << endl;
	cout << "학번: " << sex << endl;
	cout << "학번: " << id << endl;
	cout << "출석: " << attendance << "주차" << endl;

	showScores();

	if (!scores.empty()) {
		cout << "평균: " << getAverage() << "점" << endl;
		cout << "학점" << getGrade() << endl;
		cout << fixed << setprecision(2);
	}

	cout << "====================================" << endl;
}