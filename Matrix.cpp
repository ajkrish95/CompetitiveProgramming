#include <stdio.h>
#include <string.h>


class Matrix
{
	
public:
	
	int size;
	int mat[100][100];

    Matrix(int N)
    {
    	size = N;
		memset(array, 0, sizeof(array[0][0]) * m * n);
    }

    Matrix(int N, int arr[N][N])
    {
    	size = N;
    	mat = new int*[N];
    	int i,j;
    	
		for (i = 0; i<N; i++)
    	{
        	for (j=0; j<N; j++)
			{
        		mat[i][j] = arr[i][j];
    		}
		}
    }

    Matrix multiply( Matrix m )
    {
		Matrix* ans = new Matrix(size);
		int i,j,k;
		for (i=0; i<size; i++)
		{
			for (j=0; j<size; j++)
			{
				for (k=0; k<size; k++)
				{	
					ans.mat[i][j] = ans.mat[i][j] + m.mat[i][k]*mat[k][j];
				}
			}
		}
		
		return ans;
    }

    Matrix const_multiply(int constant)
    {
		Matrix ans;
		
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
					ans.mat[i][j] = constant * mat[i][j];
			}
		}
		
		return ans;
    }

    Matrix add(Matrix m)
    {

		Matrix ans;
		
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				ans.mat[i][j] = m.mat[i][j] + mat[i][j];
			}
		}
		return ans;	
    }
};
