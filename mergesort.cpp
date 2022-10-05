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


void merge(vector<int> &l, vector<int> &r, vector<int> &v)
{

	int nl = l.size(), nr = r.size(), nv = v.size();

	int i = 0, j = 0, k = 0;

	while(i < nl && j < nr)
	{
		if(l[i] <= r[j])
		{
			v[k] = l[i];
			i++;
		}
		else
		{
			v[k] = r[j];
			j++;
		}
		k++;
	}
	while(i < nl)
	{
		v[k] = l[i];
		i++;
		k++;
	}
	while(j < nr)
	{
		v[k] = r[j];
		k++;
		j++;
	}

}


void mergesort(vector<int> &v)
{

	int n = v.size();

	if(n < 2) return;

	int mid = n/2;

	vector<int> v1, v2;

	for(int i = 0; i < mid; i++) v1.push_back(v[i]);

	for(int i = mid; i < v.size(); i++) v2.push_back(v[i]);

	// cout << "sad" << endl;

	mergesort(v1);
	mergesort(v2);

	merge(v1, v2, v);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, tmp;
	vector<int> v;
	cin>>t;
	while(t--)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	mergesort(v);

	for(int i = 0; i < v.size(); i++) cout << v[i] << " ";

	return 0;
}