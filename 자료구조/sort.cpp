#include <iostream>
#include <algorithm>

using namespace std;

class Student {
public:
	string name; 
	int score; 
	Student(string name, int score) {
		this->name = name; 
		this->score = score; 
	}
	//정렬 기준은 '점수가 작은 순서' 
	bool operator < (Student& student) {
		return this->score < student.score;
	}
};

//bool compare(int a, int b) {
//	return a > b; 
//}

int main(void) {
	Student students[] = {
		Student("kim",90),
		Student("choi",93),
		Student("pack",97),
		Student("heo",87),
		Student("lee",92),
	};

	sort(students, students + 5);
	for (int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}

