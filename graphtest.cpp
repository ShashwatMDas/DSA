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

vector<vector<int>> g;
vector<bool> v;



void edge(int a, int b)
{
	g[a].push_back(b);
}

void bfs(int u)
{

	queue<int> q;

	q.push(u);

	v[u] = true;
	while(!q.empty())
	{

		cout << q.front() << " ";
		q.pop();

		for(int i = 0; i < g[u].size(); i++)
		{
			if(!v[g[u][i]])
			{
				q.push(g[u][i]);
				v[g[u][i]] = true;
			}
		}
	}

}

void dfs(int u)
{
	v[u] = true;

	cout << u << " ";

	for(int i = 0; i < g[u].size(); i++)
	{
		if(!v[g[u][i]])
			dfs(g[u][i]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	v.assign(n, false);
	g.assign(n, vector<int> ());


	int t;
	cin >> t;

	while(t--)
	{
		int a, b;
		cin >> a >> b;

		edge(a, b);
	}

	// for(int i = 0; i < v.size(); i++)
	// {
	// 	if(!v[i])
	// 		bfs(i);
	// }

	for(int i = 0; i < v.size(); i++)
	{
		if(!v[i])
			dfs(i);
	}
	
	return 0;
}