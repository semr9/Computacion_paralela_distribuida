#include <bits/stdc++.h>
using namespace std;


int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}

void normalMatrixMultiplication(int MAX, int p)
{
	double matriz1[MAX][MAX];
	double matriz2[MAX][MAX];
	double matriz3[MAX][MAX];

	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			matriz1[i][j] = i ;
			matriz2[i][j] = i ;
			matriz3[i][j] = i ;
		}
	}

	int i,j,k;
	clock_t start, end;  
	double time_taken;
	
	start = clock(); 	
	for (i = 0; i < MAX; ++i)
	{
		for ( j = 0; j < MAX; ++j)
		{
			for ( k = 0; k < MAX; ++k)
			{
				matriz3[i][j] += matriz1[i][k] * matriz2[k][j] ;
			}
		}
	}
	end = clock();

	time_taken = double(end - start)/ double(CLOCKS_PER_SEC);
	cout << "Time taken by prove of clasic matrix"<< p <<" is : " << fixed << time_taken << setprecision(5); cout << " sec " << endl; 

}

void blockMatrixMultiplication(int MAX, int p, int t)
{
	double matriz1[MAX][MAX];
	double matriz2[MAX][MAX];
	double matriz3[MAX][MAX];

	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			matriz1[i][j] = i ;
			matriz2[i][j] = i ;
			matriz3[i][j] = i ;
		}
	}


	int i0,j0,k0,i,j,k;
	clock_t start, end;  
	double time_taken;
	
	start = clock();
	 	
	for (i0 = 0; i0 < MAX; i0+=t)
	{
		for (j0 = 0; j0 < MAX; j0+=t)
		{
			for ( k0 = 0; k0 < MAX; k0+=t)
			{
				for ( i = i0; i < i0+t; ++i) //min(i0+t,MAX)
					{
						for ( j = j0; j < j0+t; ++j)
						{
							for ( k = k0; k < k0+t; ++k)
							{
								matriz3[i][j] += matriz1[i][k] * matriz2[k][j] ;	
							}
						}
					}	
			}
		}
	}
	end = clock();

	time_taken = double(end - start)/ double(CLOCKS_PER_SEC);
	cout << "Time taken by prove of block matrix "<< p <<" is : " << fixed << time_taken << setprecision(5); cout << " sec " << endl; 

}
int main()
{
	normalMatrixMultiplication(300,1);
	blockMatrixMultiplication(300,1,100);
	cout<<"****************************************************************************************************+\n";
	normalMatrixMultiplication(400,2);
	blockMatrixMultiplication(400,2,100);
	cout<<"****************************************************************************************************+\n";
	normalMatrixMultiplication(500,3);
	blockMatrixMultiplication(500,3,100);
	//cout<<"****************************************************************************************************+\n";
	//normalMatrixMultiplication(900,4);
	//blockMatrixMultiplication(900,4,50);
}