#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

using namespace std;


int main(int argc, char* argv[])
{
    const int SIZE = 4;
    const int R_MIN = 0;
    const int R_MAX = 100;

    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    int C[SIZE][SIZE];

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            A[i][j] = 3;
            B[i][j] = 2;
        }
    }


	int ThreadNum = 2;
	int GridSize = int(sqrt((double)ThreadNum));
	int BlockSize = SIZE / GridSize;
	omp_set_num_threads(ThreadNum);

	#pragma omp parallel

	{
		int ThreadID = omp_get_thread_num();
		int RowIndex = ThreadID / GridSize;
		int ColIndex = ThreadID % GridSize;

        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < SIZE; k++)
                    C[i][j] += A[i][k] * B[k][j];
            }
	}

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << C[i][j] << '\t';
        }
        cout << endl << endl;
    }
}