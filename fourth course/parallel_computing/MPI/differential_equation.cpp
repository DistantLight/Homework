#include <iostream>
#include <stdio.h>
#include <mpi.h>

using namespace std;

double func(double x, double y) {
    return x * x + 2 * y * y - x;
}

int main(int argc, char* argv[]) {
    MPI_Status status;
    MPI_Init(&argc, &argv);
    int rank, communicatorSize;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &communicatorSize);

    double a = 0.0;
    double b = 1.0;
    double h = 0.1;
    int n = (b - a) / h;
    double* y = new double[n];
    for (int i = 0; i < n; i++) {
        y[i] = 0;
    }

    double startTime = MPI_Wtime();

    double k1 = 0, k2 = 0, k3 = 0, k4 = 0;

    if (rank == 0) {
        for (int i = 0; i < n / 2; i++) {
            k1 = func(a + i * h, y[i]);
            k2 = func(a + i * h + h / 2, y[i] + (h / 2) * k1);
            k3 = func(a + i * h + h / 2, y[i] + (h / 2) * k2);
            k4 = func(a + i * h + h, y[i] + h * k3);
            y[i + 1] = y[i] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        }
        MPI_Send(y, n, MPI_DOUBLE, 1, 101, MPI_COMM_WORLD);
    }
    else {
        MPI_Recv(y, n, MPI_DOUBLE, 0, 101, MPI_COMM_WORLD, &status);
        for (int i = n / 2; i < n; i++) {
            k1 = func(a + i * h, y[i]);
            k2 = func(a + i * h + h / 2, y[i] + (h / 2) * k1);
            k3 = func(a + i * h + h / 2, y[i] + (h / 2) * k2);
            k4 = func(a + i * h + h, y[i] + h * k3);
            y[i + 1] = y[i] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        }
    }

    if (rank == 1) {
        for (int i = 0; i < n; i++) {
            cout << "result: " << "x:" << a + i * h << " y:" << y[i] << endl;
        }

        double endTime = MPI_Wtime();
        cout << "time: " << endTime - startTime << endl;
    }

    MPI_Finalize();
    return 0;
}