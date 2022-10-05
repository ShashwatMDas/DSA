
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
bool sieve[1000000];
 
void buildSieve()
{
    for (auto& i : sieve)
        i = true;
 
    sieve[0] = false;
    sieve[1] = false;
 
    for (int p = 2; p * p <= 1000000; p++) {
        if (sieve[p] == true) {
            for (int i = p * p; i <= 1000000;
                 i += p)
                sieve[i] = false;
        }
    }
}
 
bool isPrime(string number)
{
    int num = stoi(number);
    return sieve[num];
}
 
int rec(string& number, int i,
        vector<int>& dp)
{
    if (dp[i] != -1)
        return dp[i];
 
    int cnt = 0;
 
    for (int j = 1; j <= 6; j++) {
 
        if (i - j >= 0
            && number[i - j] != '0'
            && isPrime(
                   number.substr(i - j, j))) {
 
            cnt += rec(number, i - j, dp);
            cnt %= MOD;
        }
    }
    return dp[i] = cnt;
}
 
int countPrimeStrings(string& number)
{
    int n = number.length();
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    return rec(number, n, dp);
}
 
int fun(char *str) {
	string s;
	int i = 0;
	while(str[i] != '\0') {
		s.push_back(str[i]);
		i++;
	}
	buildSieve();
	return countPrimeStrings(s);
}

int main()
{
    
 
    char arr[5];
    cin >> arr;
 
    cout << fun(arr) << "\n";
 
    return 0;
}