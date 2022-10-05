
#include <bits/stdc++.h>
using namespace std;
 

bool compSort(vector<int> &x, vector<int> y) {
    return x[1] < y[1];
}
 
 
int minStepsMarker(vector<vector<int>> &arr, int n) {
     
    int numsteps = 1;
     
    sort(arr.begin(), arr.end(), compSort);
     
    int p = arr[0][1];

    for(int i = 0; i < n; i++) {
        if((arr[i][0] > p && arr[i][0] >= 0) || (arr[i][0] < p && arr[i][0] < 0)) {
            numsteps++; 
            p = arr[i][1];
        }
    }
     
    return numsteps;
     
}

int markerPlaces(vector<int> startX, vector<int> endX)  {

	vector<vector<int>> arr;
	arr.assign(startX.size(), vector<int> ());

	for(int i = 0; i < startX.size(); i++) {
		arr[i].push_back(startX[i]);
        arr[i].push_back(endX[i]);
	}

    return minStepsMarker(arr, arr.size()); 

}
 
int main() {
     
    vector<int> startX = { 0, 2, 4, -8 };
    vector<int> endX = { 4, 5, 6, -9 };

    int N = startX.size();
     
    cout<< markerPlaces(startX, endX);
    return 0;
}