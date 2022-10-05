/******************************************
* AUTHOR : Shashwat M. Das*
* INSTITUTION : IIT Kharagpur *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define dd double
#define pb push_back
#define mp make_pair


class Books {


	int l, b;

	public:
		Books(int a, int c)
		{
			l = a;
			b = c;
		}
		Books()
		{
			cout << "I am shashwat" << endl;
			// l = 0;
			// b = 0;
		}
		Books(double a, int c)
		{
			l = (int)a;
			b = c;
		}

		int per()
		{
			return 2*(l+b);
		}

		int area()
		{
			return l*b;
		}

		virtual void printHello()
		{
			cout << "Hello I am a book" << endl;
		}

		void printHello(int a)
		{
			cout << a << endl;
		}

		void virtualfunc()
		{
			cout << "Hi i am parent class" << endl;
		}

		virtual void cyx() = 0;

};

class Science: public Books
{

	public:
		Science()
		{
			cout << "sad" << endl;
		}
		void printHello()
		{
			cout << "Hi I am a science book " << endl;
		}
		void cyx()
		{
			cout << "sad" << endl;
		}

		void virtualfunc()
		{
			cout << "Hi i am child class" << endl;
		}

};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	Books *a;
	Science b;

	a = &b;
	a->printHello();

	// Books b, sc(3, 4), sa(2.2, 4);
	// Science s;
	// s.printHello();
	// b.printHello(2);

	// Books *a;
	// a = &s;
	// a->virtualfunc();

	// cout << s.area() << sc.area() << " " << sa.area() << endl;

	return 0;
}