#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <stdio.h>

using namespace std;

double func(double x, double y) {
    return x * x + 2 * y * y - x;
}

int main(int argc, char* argv[]) {

    double a = 0.0;
    double b = 1.0;
    double h = 0.1;
    int n = (b - a) / h;
    double* y = new double[n];
    for (int i = 0; i < n; i++) {
        y[i] = 0;
    }

    double startTime = omp_get_wtime();

    double k1 = 0, k2 = 0, k3 = 0, k4 = 0;

    omp_set_num_threads(2);

#pragma omp parallel shared(y)
    {
#pragma omp for
        for (int i = 0; i < n; i++) {
            k1 = func(a + i * h, y[i]);
            k2 = func(a + i * h + h / 2, y[i] + (h / 2) * k1);
            k3 = func(a + i * h + h / 2, y[i] + (h / 2) * k2);
            k4 = func(a + i * h + h, y[i] + h * k3);
            y[i + 1] = y[i] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "result: " << "x:" << a + i * h << " y:" << y[i] << endl;
    }

    double executeTime = omp_get_wtime() - startTime;
    cout << "Executing time: " << executeTime << endl;

    return 0;
}