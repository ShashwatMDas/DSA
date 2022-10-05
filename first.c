#include<stdio.h>
#include <string.h>

int main()
{

	char s[1000];

	scanf("%s", s);

	int n = strlen(s);

	char arr[n][n];

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			arr[i][j] = '\0';

	int k = 0, l = 0;
	for(int i = 0; i < n; i++)
	{

		for(int j = 0; j < n; j++)
		{
			if(!(k%2))
			{
				if(j+k >= n)
					arr[i][j] = '\0';
				else
					arr[i][j] = s[j+l];
				// l++;
			}
			else
			{
				if(n-(j+k) < 1)
					arr[i][j] = '\0';
				else
					arr[i][j] = s[n-(j+l)];
			}
		}
		if(!(k%2)) l++;
		k++;
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(arr[i][j] == '\0')
				arr[i][j] = arr[n-j-1][n-i-1];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%c ", arr[i][j]);
		printf("\n");
	}



	// printf("%d\n", strlen(s));

}