/******************************************
* AUTHOR : Shashwat M. Das*
* INSTITUTION : IIT Kharagpur *
******************************************/
#include <bits/stdc++.h>
using namespace std;

int minRefills(vector<int> &dis, vector<int> &gas, int d, int g) {

	vector<vector<int>> refills;
	refills.assign(dis.size(), vector<int> ());

	for(int i = 0; i < (int)dis.size(); i++) {
		refills[i].push_back(dis[i]);
		refills[i].push_back(gas[i]);
	}

	int curr = 0;
	  sort(refills.begin(), refills.end());
	  priority_queue<int> pq;
	  int i = 0;
	  int cnt = 0;
	  curr += g;
	  while (curr < d) {
	     cnt++;
	     while (i < (int)refills.size() && refills[i][0] <= curr) {
	        pq.push(refills[i][1]);
	        i++;
	     }
	     if (pq.empty())
	        break;
	     curr += pq.top();
	     pq.pop();
	  }
	  return curr >= d ? cnt : -1;

}

int main() {
	
	vector<int> dis = {5, 7, 10};
	vector<int> gas = {2, 3, 5};
 	cout << minRefills(dis, gas, 15, 5) << endl;
	return 0;
}