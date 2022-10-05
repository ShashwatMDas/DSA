#include<iostream>
#include<string.h>
using namespace std;
#define max 15

bool gp[max][max] = {-1};
int n;
int clique[1000];
int c;

bool checkIfCover(int V, int k, int E) {
   int set = (1 << k) - 1;
   int limit = (1 << V);
   int node = k;

   bool vis[max][max];
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

int find_cover(int n, int m) {
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
int main() {
    int edges[][2] = {{1, 2}, {2, 3}, {3, 1}, {4, 3}, {4, 5}, {5, 3}} ;
    int size = sizeof(edges) / sizeof(edges[0]); 
    n = size; 
    c = 0;
    int V = size, E = size-1;

    for (int i = 0; i < size; i++) { 
        gp[edges[i][0]][edges[i][1]] = 1; 
        gp[edges[i][1]][edges[i][0]] = 1; 
    } 
   cout << "Size of Minimum Vertex Cover : " << find_cover(V, E) << endl << "Minimum Vortex Cover: " << endl;
   
   for(int i = 0; i < c; i++)
   {
      cout << clique[i] << endl;
   }

   return 0;
}