/******************************************
* AUTHOR : Shashwat M. Das*
* INSTITUTION : IIT Kharagpur *
******************************************/


/************
Approach: 

The vertices of the polygon have been arranged in an ascending order on the basis of it's x coordinate using merge sort algorithm which takes nlogn time(Implemented on my own, without using STL).
The set vertices are classified as two chains, top chain and bottom chain. This is done in n time complexity.
Further, I have used sweep-line approach, moving through the vertices in increasing order of it's x-axis(as already sorted), and drawing the diagonals starting from the 3rd vertex and to the applicable other vertices.
vertex. 
This process of drawing diagonals takes place in 2n time complexity, as I have maintained a stack(Implemented on my own, without using STL) which at a time has a maximum of 2 elements at a time, hence runs twice on every
(behaviour of drawing diagonals depend upon which chain the vertex lies on), if v i and top(stack) on same chain, diagonals are added onto all permissible vertices in the stack(which is at max 2 at a time) while popping 
each of them out making it an empty stack and only the current vertex is added onto the stack then. If they dont lie on the same chain, same beaviour is repeated with a slight change, this time the top element of the stack
before popping them out is added two the stack after which the current vertex is added on top of it. The total time compexity of the sweep line approach here is of the order of n, while that of sorting is nlogn.

Hence 2n time complexity. Overall the time complexity is nlogn + 2n ==> nlogn.

***************/

#include <iostream>
using namespace std;

#define MAX 10000 


void merge(double l[][4], int nl, double r[][4], int nr, double v[][4], int nv)                                        // merging the arrays in sorted order
{

	int i = 0, j = 0, k = 0;

	while(i < nl && j < nr)
	{
		if(l[i][0] <= r[j][0])																						  // sorting based on increasing order of x coordinate
		{
			v[k][0] = l[i][0];
			v[k][1] = l[i][1];
			v[k][2] = l[i][2];
			v[k][3] = l[i][3];
			i++;
		}
		else
		{
			v[k][0] = r[j][0];
			v[k][1] = r[j][1];
			v[k][2] = r[j][2];
			v[k][3] = r[j][3];
			j++;
		}
		k++;
	}
	while(i < nl)
	{
		v[k][0] = l[i][0];
		v[k][1] = l[i][1];
		v[k][2] = l[i][2];
		v[k][3] = l[i][3];
		i++;
		k++;
	}
	while(j < nr)
	{
		v[k][0] = r[j][0];
		v[k][1] = r[j][1];
		v[k][2] = r[j][2];
		v[k][3] = r[j][3];
		k++;
		j++;
	}

}


void mergesort(double v[][4], int n)																	//mergesort implementation
{

	if(n < 2) return;

	int mid = n/2;

	double v1[mid][4], v2[n-mid][4];																	// spltting array into shorter forms

	for(int i = 0; i < mid; i++)
	{
		v1[i][0] = v[i][0];
		v1[i][1] = v[i][1];
		v1[i][2] = v[i][2];
		v1[i][3] = v[i][3];
	}

	for(int i = mid; i < n; i++) 
	{
		v2[i-mid][0] =  v[i][0];
		v2[i-mid][1] =  v[i][1];
		v2[i-mid][2] =  v[i][2];
		v2[i-mid][3] =  v[i][3];
	}


	mergesort(v1, mid);
	mergesort(v2, n-mid);

	merge(v1, mid, v2, n-mid, v, n);

}


// Implementation of stack
class Stack { 
    int top; 
  
public: 
    double a[MAX][2];																					// 2d array class member for holding information of the vertices
  
    Stack() 
    { 
    	top = -1;																						// initializing the initial position of stack
    } 
    bool push(double x, double y); 
    void pop(); 
    double topInd();
    double topChain(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(double x, double y) 																	// function for pushing items onto the stack
{ 
    if (top >= (MAX - 1)) { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else { 
        a[top+1][0] = x; 
        a[top+1][1] = y;
        top++;
        return true; 
    } 
} 
  
void Stack::pop() 																						// function for popping elements out of the stack
{ 
    if (top < 0) { 
        cout << "Stack Underflow"; 
        return ; 
    } 
    else { 
        top--;
        return;
    } 
} 
double Stack::topInd() 																					// function for returning cyclic position of the vertex at the top 
{ 
    if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        double x = a[top][0]; 
        return x; 
    } 
} 

double Stack::topChain()																				// function for returning the chain on which the the top vertex lies
{
	if (top < 0) { 
        cout << "Stack is Empty"; 
        return 0; 
    } 
    else { 
        double x = a[top][1]; 
        return x; 
    } 

}
  
bool Stack::isEmpty() 																					// functio for checking if the stack is empty
{ 
    return (top < 0); 
} 


double abs(double a)																					// function for getting absolute value of a number
{
	if(a < 0) return -1*a;
	else return a;
}


void triangulate(double v[][4], int n, double final[][2], int fsize)									// function for traingulating the polygon
{
	Stack s;
	int c = 0;

	s.push(v[0][3], v[0][2]);
	s.push(v[1][3], v[1][2]);																			// pushing first two sorted vertices onto the stack

	for(int i = 2; i < n; i++)																			// looping through the vertices starting from 3rd, one by one and drawing diagonals onto the viable vertices by manipulating the stack 
	{
		if(v[i][2] == s.topChain())																		// checking if the current vertex and the top vertex on the stack lie on the same chain
		{
			while(!s.isEmpty())																			// looping through the stack(runs only twice at max)
			{
				double x = s.topInd();
				s.pop();																				// popping the topmost element of the stack
				if(abs(x-v[i][3]) >= 2 && !(x == 0 && v[i][3] == n-1) && !(x == n-1 && v[i][3] == 0))	// checking if the two viable vertices are next to each other, hence not a diagonal
				{
					final[c][0] = x;
					final[c][1] = v[i][3];
					c++;
				}
			}
			s.push(v[i][3], v[i][2]);																	// pushing the current vertex onto the stack
		}
		else 																							// if the current vertex and the top vertex don't on the stack lie on the same chain
		{
			double a = s.topInd(), y = s.topChain();													// storing the top element of the stack before popping it out, let it be Vtop
			while(!s.isEmpty())
			{
				double x = s.topInd();
				s.pop();
				if(abs(x-v[i][3]) >= 2 && !(x == 0 && v[i][3] == n-1) && !(x == n-1 && v[i][3] == 0))   // checking if the two viable vertices are next to each other, hence not a diagonal
				{
					final[c][0] = x;
					final[c][1] = v[i][3];
					c++;
				}
			}
			s.push(a, y);																				// pushing Vtop onto the empty stack
			s.push(v[i][3], v[i][2]);																	// pushing the current vertex onto the stack

		}
	}
}


int main() {

	double arr[6][2] = {{0,0},{0,1},{1,1}, {1.5, 1.5}, {1,0}, {0.5, -0.5}};								// set of vertices

	int mn = 1000000, mx = -1000000;

	int n = sizeof(arr)/sizeof(arr[0]), mxind = 0, mnind = 0;											// getting size of the vertex array

	for(int i = 0; i < n; i++)
	{
		if(mn > arr[i][0]) 																				//storing the index of minimum x-vertex
		{
			mn = arr[i][0];
			mnind = i;
		}
		if(mx < arr[i][0])																				//storing the index of max x-coordinate
		{
			mx = arr[i][0];
			mxind = i;
		}
	}

	double v[n][4] = { {0, 0, 0, 0} };

	for(int i = mnind; 1; )																				// splitting the vertices into first of two chains
	{
		v[i][0] = arr[i][0];
		v[i][1] = arr[i][1];
		v[i][2] = 0;
		v[i][3] = i;
		if(i == mxind)
		{
			break;
		}
		if(i == n-1)
		{
			i = 0;
		}
		else i++;
	}

	for(int i = mnind; 1; )																				// splitting the vertices into second of two chains
	{
		v[i][0] = arr[i][0];
		v[i][1] = arr[i][1];
		v[i][2] = 1;
		v[i][3] = i;
		if(i == mxind)
		{
			break;
		}
		if(i == 0)
		{
			i = n-1;
		}
		else i--;
	}

	mergesort(v, n);																				// sorting vertices of the polygon based on x-coordinate
	double final[n-3][2] = { {-1, -1} };


	triangulate(v, n, final, n-3);

	cout << "{";
	for(int i = 0; i < n-3; i++)
	{
		cout << "{" << final[i][0] << "," << final[i][1] << "}" << (i == n-4 ? "" : ",") ;
	}
	cout << "}";

	return 0;
}