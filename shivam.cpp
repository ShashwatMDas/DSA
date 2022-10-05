#include <iostream> 
#include<string.h>

using namespace std; 

int store[100000], n; 
  
int gp[1000][1000]; 

int clique[1000];
int c;

bool checkIfCover(int V, int k, int E) {
   int set = (1 << k) - 1;
   int limit = (1 << V);
   int node = k;

   bool vis[1000][1000];
   while (set < limit) {
      memset(vis, 0, sizeof vis);
      int count = 0;

      for (int j = 1, v = 1 ; j < limit ; j = j << 1, v++) {
         if (set & j) {
            for (int k = 1 ; k <= V ; k++) {
               if (gp[v][k] && !vis[v][k]) {
                  vis[v][k] = 1;
                  vis[k][v] = 1;
                  count++;
               }
            }
         }
      }

      if (count == E)
      {
         clique[c] = node;
         c++;
         return true;
      }
      int c = set & -set;
      int r = set + c;
      set = (((r^set) >> 2) / c) | r;
   }
   return false;
}

int vertex_cover(int n, int m) {
   int left = 1, right = n;
   while (right > left){
      int mid = (left + right) >> 1;
      if (!checkIfCover(n, mid, m))
         left = mid + 1;
      else
         right = mid;
   }
   return left;
}


int max(int a, int b)
{
	if(a >= b)
		return a;
	else return b;
}
  
  
bool isClique(int a) 
{ 
  
    for(int i = 1; i < a; i++) 
    { 
        for(int j = i + 1; j < a; j++)
        {
          if (gp[store[i]][store[j]] == 0) 
            return false; 
        } 
    } 
    return true; 
} 
  
int maxCliqueSize(int i, int l, int arr[][1000], int c, int k) 
{ 
    int mx = -10000; 
  
    for (int j = i + 1; j <= n; j++) { 
   
        store[l] = j; 
        if (isClique(l + 1)) {

        	if(mx <= l)
        	{
        		arr[c][k] = l;
        		k++;
        		mx = l;
        	}
            mx = max(mx, maxCliqueSize(j, l + 1, arr, c, k++)); 
        }
        c++; 
    } 
    return mx; 
} 

  
int main() 
{ 
    int edges[][2] = {{1, 2}, {2, 3}, {3, 1}, {4, 3}, {4, 1}, {4, 2}} ;
    int size = sizeof(edges) / sizeof(edges[0]); 
    n = size; 
    int V = size, E = size-1;

    for (int i = 0; i < size; i++) { 
        gp[edges[i][0]][edges[i][1]] = 1; 
        gp[edges[i][1]][edges[i][0]] = 1; 
    } 

    int cl[1000][1000] = {0};
    int sz = maxCliqueSize(0, 1, cl, 0, 0);

    cout << "Size of Max clique: " << sz << endl;

    for(int i = 0; i < 100; i++)
    {
    	int j = 0;
    	while(cl[i][j] != 0)
    	{
    		j++;
    	}
    	if(j == sz)
    	{
    		j = 0;
    		cout << "MAX Clique: " << endl;
    		while(cl[i][j] != 0)
	    	{
	    		cout << cl[i][j] << endl;
	    		j++;
	    	}
    	}
    }
    cout << "Size of Minimum Vertex Cover : " << vertex_cover(V, E) << endl << "Minimum Vortex Cover: " << endl;
   
    for(int i = 0; i < c; i++)
    {
       cout << clique[i] << endl;
    }


    return 0; 
} 