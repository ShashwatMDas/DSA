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

void bubblesort(vector<int> &v)
{
	int n = v.size();
	for(int i = 0; i < n-1;i++)
	{
		for(int j = 0; j < n-i-1; j++)
			if(v[j] > v[j+1])
				swap(v[j], v[j+1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	vector<int> v;
	cin>>t;
	while(t--)
	{
		int tmp;
		cin >> tmp;
		v.pb(tmp);
	}

	bubblesort(v);

	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

	return 0;
}