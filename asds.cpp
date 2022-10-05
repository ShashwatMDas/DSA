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

void merge(vector<int> &l, vector<int> &r, vector<int> &v) {

  int n = v.size(), nl = l.size(), nr = r.size();
  int i = 0, j = 0, k = 0;

  while(i < nl && j < nr) {
    if(l[i] >= r[j]) {
      v[k] = r[j];
      k++;
      j++;
    } else {
      v[k] = l[i];
      k++;
      i++;
    }
  }
  while(i < nl) {
    v[k] = l[i];
    i++;
    k++;
  }
  while(j < nr) {
    v[k] = r[j];
    j++;
    k++;
  }

}

void mergesort(vector<int> &v) {
  int n = v.size();
  if(n < 2) return;

  int mid = n/2;

  vector<int> v1, v2;

  for(int i = 0; i < mid; i++) v1.push_back(v[i]);
  for(int i = mid; i < n; i++) v2.push_back(v[i]);
  
  mergesort(v1);
  mergesort(v2);

  merge(v1, v2, v);

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin>>t;
  vector<int> v(t, 0);
  for(int i = 0; i < t; i++)
  {
    cin >> v[i]; 
  }
  mergesort(v);
  for(auto i : v) {
    cout << i << " ";
  }
  return 0;
}