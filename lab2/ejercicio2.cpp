#include <bits/stdc++.h>
using namespace std;


void prueba(int MAX, int p)
{
	double matriz1[MAX][MAX];
	double matriz2[MAX][MAX];

	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			matriz1[i][j] = i ;
			matriz2[i][j] = i ;
		}
	}


	clock_t start, end;  
	double time_taken;
	
	start = clock(); 	
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			for (int k = 0; k < MAX; ++k)
			{
				matriz1[i][j] += matriz1[i][k] * matriz2[k][j] ;
			}
		}
	}
	end = clock();

	time_taken = double(end - start)/ double(CLOCKS_PER_SEC);
	cout << "Time taken by prove "<< p <<" is : " << fixed << time_taken << setprecision(5); cout << " sec " << endl; 

}

int main()
{
	prueba(20, 1);
	prueba(100, 2);
	prueba(400, 3);
	prueba(700, 4);
}