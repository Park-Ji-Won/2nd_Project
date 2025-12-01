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

void Student::editInfo() {
	cout << "======== 선택된 학생 정보 수정 ========" << endl;
	
	cout << "\n[현재 정보]" << endl;
	cout << "이름: " << name << endl;
	cout << "학번: " << id << endl;
	cout << "성별: " << sex << endl;
	cout << "전공: " << major << endl;

	cout << "\n 수정할 정보 선택" << endl;
	cout << "1.이름" << endl;
	cout << "2.학번" << endl;
	cout << "3.성별" << endl;
	cout << "4.전공" << endl;
	cout << "0.취소" << endl;
	cout << " 선택 >> ";

	int ch;
	cin >> ch;

	string newName, newSex, newMajor;
	int newId;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << " >> 잘못된 입력, 다시 입력" << endl;
		return;
	}

	switch (ch) {
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
			cin.ignore(50000, '\n');
			cout << ">> 학번은 숫자로 입력하시오." << endl;
			break;
		}
		cin.ignore(1000, '\n');

		id = newId;
		cout << " >> 학번이 변경됨." << endl;
		break;
	case 3:
		cout << "정정할 성별: ";
		cin.ignore();
		getline(cin, newSex);
		sex = newSex;
		cout << " >> 성별이 변경됨." << endl;
		break;
	case 4:
		cout << "정정할 전공: ";
		cin.ignore();
		getline(cin, newMajor);
		major = newMajor;
		cout << " >> 전공이 변경됨." << endl;
		break;
	case 0:
		cout << " >> 정정 취소." << endl;
		break;
	default:
		cout << " >> 잘못된 입력." << endl;
	}
	
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
	cout << "\n====================================" << endl;
	for (int i = 0; i < subjects.size(); i++) {
		cout << "" << subjects[i] << " : " << scores[i] << " 점" << endl;
	}
	cout << "====================================\n" << endl;
}

void Student::display() {
	cout << "\n======== 선택된 학생 정보 ========" << endl;
	cout << "이름: " << name << endl;
	cout << "학번: " << id << endl;
	cout << "성별: " << sex << endl;
	cout << "전공: " << major << endl;
	cout << "출석: " << attendance << "주차" << endl;

	showScores();

	if (!scores.empty()) {
		cout << fixed << setprecision(2);
		cout << "평균: " << getAverage() << "점" << endl;
		cout << "학점: " << getGrade() << endl;
	}

	cout << "====================================\n" << endl;
}