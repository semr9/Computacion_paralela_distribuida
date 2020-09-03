#include <bits/stdc++.h>
using namespace std;

#define MAX 1000


int main()
{
	double A[MAX][MAX], x[MAX], y[MAX];
	
	for (int i = 0; i < MAX; ++i)
	{
		x[i] = i;
		y[i] = i;
		for (int j = 0; j < MAX; ++j)
		{
			A[i][j] = i ;
		}
	}

	clock_t start, end;  
	double time_taken;

	start = clock(); 	
	for (int i = 0; i < MAX; ++i)
		for (int j = 0; j < MAX; ++j)
			y[i] = A[i][j]*x[j];
	end = clock();

	time_taken = double(end - start)/ double(CLOCKS_PER_SEC);
	cout << "Time taken by program 1 is : " << fixed << time_taken << setprecision(5); cout << " sec " << endl; 

	start = clock();
	for (int j = 0; j < MAX ; j++)
		for ( int i = 0; i < MAX ; i++)
			y[i] += A[i][j]* x [j];	
	end = clock();

	time_taken = double(end - start)/ double(CLOCKS_PER_SEC); 
    cout << "Time taken by program 2 is : " << fixed << time_taken << setprecision(5); cout << " sec " << endl; 
	return 0;
}