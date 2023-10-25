#include <mpi.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    //double** A = new double* [SIZE];
    //for (int i = 0; i < SIZE; i++) {
    //    A[i] = new double[SIZE];
    //}

    //double** B = new double* [SIZE];
    //for (int i = 0; i < SIZE; i++) {
    //    B[i] = new double[SIZE];
    //}

    const int SIZE = 4;
    const int R_MIN = 0;
    const int R_MAX = 100;

    double A[SIZE][SIZE];
    double B[SIZE][SIZE];
    double C[SIZE][SIZE];


    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            //A[i][j] = rand() % (R_MAX - R_MIN + 1) + R_MIN;
            //B[i][j] = rand() % (R_MAX - R_MIN + 1) + R_MIN;
            A[i][j] = 3;
            B[i][j] = 2;
        }
    }

    int world_size, world_rank;
    MPI_Status status;
    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int dim = SIZE;
    int i, j, k, p, ind;
    double temp;
    MPI_Status Status;
    int ProcPartsize = dim / world_size;
    int ProcPartElem = ProcPartsize * dim;
    double* bufA = new double[ProcPartElem];
    double* bufB = new double[ProcPartElem];
    double* bufC = new double[ProcPartElem];


    MPI_Scatter(A, ProcPartElem, MPI_DOUBLE, bufA, ProcPartElem, MPI_DOUBLE, 0, MPI_COMM_WORLD);
    MPI_Scatter(B, ProcPartElem, MPI_DOUBLE, bufB, ProcPartElem, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    temp = 0.0;

    for (i = 0; i < ProcPartsize; i++)
    {
        for (j = 0; j < ProcPartsize; j++)
        {
            for (k = 0; k < dim; k++)
                temp += bufA[i * dim + k] * bufB[j * dim + k];

            bufC[i * dim + j + ProcPartsize * world_rank] = temp;
            temp = 0.0;
        }

    }

    int NextProc;
    int PrevProc;

    for (p = 1; p < world_size; p++)
    {
        NextProc = world_rank + 1;
        if (world_rank == world_size - 1)
            NextProc = 0;

        PrevProc = world_rank - 1;
        if (world_rank == 0)
            PrevProc = world_size - 1;

        MPI_Sendrecv_replace(bufB, ProcPartElem, MPI_DOUBLE, NextProc, 0, PrevProc, 0, MPI_COMM_WORLD, &Status);

        temp = 0.0;
        for (i = 0; i < ProcPartsize; i++)
            for (j = 0; j < ProcPartsize; j++)
            {
                for (k = 0; k < dim; k++)
                    temp += bufA[i * dim + k] * bufB[j * dim + k];

                if (world_rank - p >= 0)
                    ind = world_rank - p;
                else
                    ind = world_size - p + world_rank;
                bufC[i * dim + j + ind * ProcPartsize] = temp;
                temp = 0.0;
            }
    }

    MPI_Gather(bufC, ProcPartElem, MPI_DOUBLE, C, ProcPartElem, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            cout << C[i][j] << '\t';
        }
        cout << endl << endl;
    }

    delete[]bufA;
    delete[]bufB;
    delete[]bufC;
}