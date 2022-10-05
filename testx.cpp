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

// bool sumPair(vector<int> &v, int sm)
// {

// 	int i = 0, j = v.size()-1;

// 	for(; i <= j; )
// 	{
// 		if(v[i]+v[j] == sm) return true;

// 		else if(v[i]+v[j] > sm) j--;

// 		else i++;
// 	}

// 	return false;

// }

// vector<int> topfive(vector<int> &v)
// {
// 	vector<int> a;
// 	for(int i = 0; i < 5; i++)
// 	{
// 		for(int j = 0; j < v.size()-1, j++)l
// 		{
// 			if(v[j] > v[j+1])
// 				swap(&v[j], &v[j+1]);
// 		}
// 	}
// 	for(int i = v.size()-1; i >= v.size()-5; i--)
// 	{
// 		a.push_back(v[i]);
// 	}
// 	return a;
// }

int totalC(int money, int candies, int wrappers)
{

	// if(money > 0)
	// 	candies += totalC(0, money, money);

	// if(wrappers >= 3)
	// 	candies += totalC(wrappers/3, candies, wrappers%3);

	while(money != 0 || wrappers > 2)
	{
		if(money > 0)
		{
			candies += money;
			wrappers += money;
			money = 0;
		}
		else if(wrappers != 0)
		{
			money = wrappers/3;
			wrappers = wrappers%3;
		}
		else break;
	}

	return candies;

}

int main() {
	
	cout << totalC(45, 0, 0);

	return 0;
}