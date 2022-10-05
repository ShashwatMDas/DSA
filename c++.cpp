#include <iostream>
#include<bits/stdc++.h>

using namespace std;


long getMinimumCost(vector<int> parcels,int k){
    int i=1;
    sort(parcels.begin(),parcels.end());
    long resultCost = 0;
    int j=0;
    k -= (int)parcels.size();
    while(k > 0){
        if(j < (int)parcels.size() && parcels[j]==i ){
            j++;

        }
        else{
            resultCost += i;
            k--;
        }
        i++;
    }
    
    return resultCost ;
    
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<int>parcels(n);
    for(int i=0;i<n;i++){
        cin >> parcels[i] ;
    }
    cout << getMinimumCost(parcels,k) << endl;
    return 0;
}