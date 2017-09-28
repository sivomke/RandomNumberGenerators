#include "Histogram.h"
#include <iostream>
#include <iomanip>
void placement(double const u, int interval[], const int N, double a) {
	for (int i = 0; i < N; ++i) {
		if (((a + (double)i / 10) <= u) && (u <a+  ((double)(i + 1) / 10))) interval[i] += 1;
	}

}

void histogram_out(int interval[], const int N, const int n, double a, int k) {
	int sum = 0;
	for (int i = 0; i < N; i+=k) {
		for (int j=i; j < i+k; ++j) {
			sum += interval[j];
		}

		std::cout << "[" << std::fixed << std::setprecision(2)<< a + (double)i / 10 << ";" << a + (double)(i + k) / 10 << "):    ";
		std::cout<< std::fixed<< std::setprecision(5) << (double)sum / n << std::endl;
		sum = 0;
	}
}