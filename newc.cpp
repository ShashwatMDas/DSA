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


int partition(vector<int> &v, int l, int r)
{

	int pivot = v[r];

	int pi = l;

	for(int i = l; i < r; i++)
	{
		if(v[i] <= pivot)
		{
			swap(v[i], v[pi]);
			pi++;
		}
	}

	swap(v[pi], v[r]);

	return pi;

}


void quicksort(vector<int> &v, int l, int r)
{

	if(l >= r) return;

	int pi = partition(v, l, r);

	quicksort(v, l, pi-1);
	quicksort(v, pi+1, r);

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
		v.push_back(tmp);
	}
	quicksort(v, 0, v.size()-1);

	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
	return 0;
}