#include <iostream>
#include "Person.h"
#include "Student.h"	
using namespace std;

int main() {
	cout << "Person 클래스 생성 완료" << endl;

	Student s1("박지원", "Male", 202010732);

	s1.addAttendance();
	s1.addAttendance();

	s1.addScore("네트워크", 66);
	s1.addScore("Citizenship for English", 88);
	s1.addScore("시스템 프로그램밍", 74);

	s1.display();
}