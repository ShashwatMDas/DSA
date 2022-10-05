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

int dp[1000][1000];

int nsteps(string &s, int l, int r, int cnt) {

	if(dp[l][r] != -1) return dp[l][r];

	if(l >= s.size() || r >= s.size() || l >= r) {
		if(cnt != s.size()/2) {
		
			// cout << cnt << endl;
			return 0;

		}
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == 'B') return 0;
		}
		cout << s << endl;
		return 1;
	}

	string s1 = s, s2 = s;

	for(int i = l; i <= r; i++) {
		if(s1[i] == 'B') s1[i] = 'A';
		else s1[i] == 'B';
	}

	dp[l][r] = nsteps(s1, l, r+1, cnt+1)+nsteps(s1, l+1, r+1, cnt+1)+nsteps(s2, l, r+1, cnt)+nsteps(s1, l+1, r+1, cnt);

	return dp[l][r];

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	string s, s2;
	cin >> s;

	memset(dp, -1, sizeof(dp));

	cout << nsteps(s, 0, 1, 0) << endl;

	return 0;
}