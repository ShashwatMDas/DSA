/******************************************
* AUTHOR : Shashwat M. Das*
* INSTITUTION : IIT Kharagpur *
******************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {

	int T, N, Aj;
	cin >> T;
	while(T--) {
		cin >> N;
		unordered_map<int, int> mp;
		while(N--) {
			cin >> Aj;
			auto it = mp.find(Aj);
			if(it != mp.end()) it->second++;
			else mp.insert(make_pair(Aj, 1));
		}
		int res = 0;
		for(auto i = mp.begin(); i != mp.end(); i++) {
			if(i->second > 1) res += (i->second*(i->second-1)); 
		}
		cout << res << endl;
	}
	return 0;
}