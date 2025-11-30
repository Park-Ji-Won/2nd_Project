#include "Person.h"
#include "Student.h"
#include "Educator.h"
#include <iostream>
using namespace std;

int main() {
    Educator Edu("장철기", 1001, "남", "컴퓨터공학과");
    Edu.display();

    // 학생 3명 생성 (동적 할당)
    Student* s1 = new Student("김철수", 20241001, "남");
    s1->addScore("수학", 95);
    s1->addScore("영어", 88);
    s1->addScore("C++", 92);

    Student* s2 = new Student("이영희", 20241002, "여");
    s2->addScore("수학", 78);
    s2->addScore("영어", 85);
    s2->addScore("C++", 90);

    Student* s3 = new Student("박민수", 20241003, "남");
    s3->addScore("수학", 92);
    s3->addScore("영어", 95);
    s3->addScore("C++", 88);

    // 교수에게 학생 추가
    Edu.addStudents(s1);
    Edu.addStudents(s2);
    Edu.addStudents(s3);

    Edu.viewAllStudents();
    Edu.showStatistics();
    Edu.showRanking();

    return 0;
}