/******************************************
* AUTHOR : Shashwat M. Das*
* INSTITUTION : IIT Kharagpur *
******************************************/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define pb push_back
#define mp make_pair

ll dp[1000000];

ll mindiff(vector<ll> &v, int n)
{
	if(n >= v.size()) return 0;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, K;
	cin>> K >> t;
	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		vector<ll> v;
		int N;
		cin >> N;
		for(int i = 1; i <= N; i++) v.pb(pow(i, K));

		cout << mindiff(v, 0) << endl;

	}
	return 0;
}