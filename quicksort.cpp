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



// practice


// int Partition(vector<int> &v, int s, int e)
// {

// 	int pivot = v[e];

// 	int pi = start;

// 	for(int i = 0; i < e; i++)
// 	{
// 		if(v[i] <= pivot)
// 		{
// 			swap(v[pi], v[i]);
// 			pi++;
// 		}
// 	}

// 	swap(v[pi], v[e]);
// 	return pi;

// }

// void quickSort(vector<int> &v, int s, int e)
// {

// 	if(s >= e) return;

// 	int pi = Partition(v, s, e);

// 	quickSort(v, s, pi-1);
// 	quickSort(v, pi+1, end);

// }

// practice end



int partition(vector<int> &v, int start, int end)
{

	int pivot = v[end];

	int pi = start;

	for(int i = start; i < end; i++)
	{
		if(v[i] <= pivot)
		{
			swap(v[i], v[pi]);
			pi++;
		}
		
	}
	swap(v[pi], v[end]);

	return pi;

}


void quickSort(vector<int> &v, int start, int end)
{

	if(start >= end) return;

	int pi = partition(v, start, end);
	// for(int j = start; j <= end; j++) cout << v[j] << " ";
	// 		cout << endl;

	// cout << pi << " " << v[pi]  << endl;

	quickSort(v, start, pi-1);
	quickSort(v, pi+1, end);

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin>>t;
	vector<int> v;
	while(t--)
	{
		int tmp;
		cin >> tmp;
		v.pb(tmp);
	}

	quickSort(v, 0, v.size()-1);

	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}