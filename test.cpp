
#include <bits/stdc++.h>
using namespace std;

class Course {
public:
	string name;
	string term;
};

class LabCourse : public Course {
public:
	string labtime;
	LabCourse(string a, string b, string c)
	{
		name = a;
		term = b;
		labtime = c;
	}
};


int main() {
	
	LabCourse a("Mechanics", "6th Semester", "2pm");

	cout << "Lab Name: " << a.name << "\nLab Term: " << a.term << "\nLab Time: " << a.labtime << endl;
	
	return 0;
}