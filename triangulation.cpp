/******************************************
* AUTHOR : Shashwat M. Das*
* INSTITUTION : IIT Kharagpur *
******************************************/



	


/***********

The method behind this approach is ear-clipping method. The polygon is divided into two polygon in each recursive call, each time one with 3 vertices and the other with n-1 vertices by drawing a diagonal between two non-adjecent vertices.
The triangle formed in each recursive call gives a diagonal for triangulation. In each recursive call, one vertex of the polygon is eliminated(the non-diagonal containing vertex of the triangle), and recursion is continued with
the second polygon. Hence the recurive function runs for n time, hence n time complexity. Now in every recursive call, we loop through the polygon (n, n-1. n-2, ...... 3(reducing polygon size in each recursive call)) hence it has 
a time complexity of n.
Total time complexity:

n+(n-1)+(n-2)+(n-3)+.......+3\
~ n*(n-3)/2
~n^2

Hence, the programme is of the order on n^2.

*************/





#include <iostream>
using namespace std;

void triangulate(double arr[][2], double diagonals[][2][2], int size, int *c, int a)								// function for triangulating the polygon
{
	int n = size;

	if(n <= 3 || *c >= a) return;																						// checking if the polygon has less than 3 vertices 


	double ear1[3][2];
	double ear2[n-1][2];

	for(int i = 0; i < 3; i++)																						//partitioning the poygon into a triangle
	{
		ear1[i][0] = arr[i][0];
		ear1[i][1] = arr[i][1]; 
	}

	for(int i = 2; i < n; i++)																						//partitioning the poygon into a a polygon on n-1 sides
	{
		ear2[i-2][0] = arr[i][0];
		ear2[i-2][1] = arr[i][1]; 
	}
	ear2[n-2][0] = arr[0][0];
	ear2[n-2][1] = arr[0][1];

	diagonals[*c][0][0] = ear1[0][0];																				//populating the diagonals array
	diagonals[*c][0][1] = ear1[0][1];
	diagonals[*c][1][0] = ear1[2][0];
	diagonals[*c][1][1] = ear1[2][1];

	*c = *c+1;

	triangulate(ear2, diagonals, n-1, c, a);																		//making a recursive call with second(smaller) polygon
}


int main() {

	double arr[5][2] = {{0,0},{0,1},{1,1},{1.5,0.5},{1,0}};

	int n = sizeof(arr)/sizeof(arr[0]);

	double diagonals[n-3][2][2];
	
	int c = 0;

	double ear1[3][2];
	double ear2[n-1][2];


	//doing first step of the triangulating process outside the recursive function

	for(int i = 0; i < 3; i++)
	{
		ear1[i][0] = arr[i][0];
		ear1[i][1] = arr[i][1]; 
	}

	for(int i = 2; i < n; i++)
	{
		ear2[i-2][0] = arr[i][0];
		ear2[i-2][1] = arr[i][1]; 
	}
	ear2[n-2][0] = arr[0][0];
	ear2[n-2][1] = arr[0][1];

	diagonals[c][0][0] = ear1[0][0];
	diagonals[c][0][1] = ear1[0][1];
	diagonals[c][1][0] = ear1[2][0];
	diagonals[c][1][1] = ear1[2][1];

	c++;

	// c = 0;


	//first step ends

	triangulate(ear2, diagonals, n-1, &c, n-3);
	int final[n-3][2];
	// cout << c;


	//converting the final output to the required output in n^2 complexity

	for(int i = 0; i < n-3; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(diagonals[i][0][0] == arr[j][0] && diagonals[i][0][1] == arr[j][1])
			{
				final[i][0] = j;
			}
			if(diagonals[i][1][0] == arr[j][0] && diagonals[i][1][1] == arr[j][1])
			{
				final[i][1] = j;
			}
		}

	}

	cout << "{";
	for(int i = 0; i < n-3; i++)
	{
		cout<< "{" << final[i][0] << "," << final[i][1] << "}" << (i == n-4 ? "" : ",");
	}
	cout << "}";
	
	return 0;
}