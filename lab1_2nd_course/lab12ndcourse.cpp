// lab12ndcourse.cpp : Defines the entry point for the console application.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include "LCG.h"
#include "QCG.h"
#include "Fibonacci.h"
#include "ICG.h"
#include <cmath>
#include "Histogram.h"



void menu() {
	std::cout << "Please, enter number from 1 to 10 to choose generetor:" << std::endl;
	std::cout << "1  linear congruetional generetor (LCG)" << std::endl;
	std::cout << "2  quadratic congruetional generetor (QCG)" << std::endl;
	std::cout << "3  Fibonacci generator" << std::endl;
	std::cout << "4  inversive congruential generator" << std::endl;
	std::cout << "5  combination of Fibonacci and QCG" << std::endl;
	std::cout << "6  3-sigma generator" << std::endl;
	std::cout << "7  polar method for normal distribution" << std::endl;
	std::cout << "8  ratio method " << std::endl;
	std::cout << "9  the exponential distribution" << std::endl;
	std::cout << "10 gamma distribution of order a>1" << std::endl;
}


int main()
{
	const int n = 100000; //number of elements generated

	double a_unif = 0.; // left end-point for uniform distribution
	double a_normal = -3;// left end-point for normal distribution

	const int U= 10; //number of intervals we devide interval [0;1] for uniform distribution
	const int N = 60; //... [-3;3] for normal distribution
	const int O = 1000;//...[0;100] for others
	int k_unif = 1; //0.1 - step of histogram for uniform distribution
	int k_norm = 3; //0.3 ..for normal
	int k_other = 50;//5 for  others
	int interval_u[U]; //number of elements in interval [a+i/10; a+(i+1)/10] for uniform distribution
	int interval_n[N]; //...for normal
	int interval_o[O];	//for other types
	for (int i = 0; i < U; ++i) {
		interval_u[i] = 0;
	}
	for (int i = 0; i < N; ++i) {
		interval_n[i] = 0;
	}
	for (int i = 0; i < O; ++i) {
		interval_o[i] = 0;
	}
	int choice = -1;
	menu();
	while (choice != 0) {
		std::cin >> choice;
		switch (choice) {
		case 1: {
			int seed = 2;
			init1(seed);
			double u = 0.;
			for (int i = 0; i < n; ++i) {
				u = double(LCG()) / m1;
				placement(u, interval_u, U, a_unif);
			}
			histogram_out(interval_u, U, n, a_unif, k_unif);
			break;
		}
		
		case 2: {
			int seed = 2;
			init2(seed);
			double u = 0.;
			for (int i = 0; i < n; ++i) {
				u = double(QCG()) / m2;
				placement(u, interval_u, U, a_unif);
			}
			histogram_out(interval_u, U, n, a_unif, k_unif);
			break;
		}


		case 3: {
			int prev = 2, cur = 1755;
			init3(prev, cur);
			double u = 0.;
			for (int i = 1; i < n; ++i) {
				u = double(Fibonacci()) / m3;
				placement(u, interval_u, U, a_unif);
			}
			histogram_out(interval_u, U, n, a_unif, k_unif);
			break;
		}
		case 4: {
			int seed = 2;
			init4(seed);
			double u = 0.;
			for (int i = 0; i < n; ++i) {
				u = double(ICG()) / m4;
				placement(u, interval_u, U, a_unif);
			}
			histogram_out(interval_u, U, n, a_unif, k_unif);
			break;
		}

		case 5: {
			int seed = 2;
			init4(seed);
			init2(seed);
			double u = 0.;
			for (int i = 0; i < n; ++i) {
				u = double((ICG() - QCG()) % m4) / m4;
				placement(u, interval_u, U, a_unif);
			}
			histogram_out(interval_u, U, n, a_unif, k_unif);
			break;
		}


			case 6: {
				double a = -3.;
				double sum = 0;
				int seed = 2;
				double u = 0.;
				init1(seed);
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < 12; ++j) {
						sum +=double(LCG())/m1;
					}
					u = sum - 6;
					placement( u, interval_n, N, a_normal);
					u = 0;
					sum = 0;
				}
				
				histogram_out(interval_n, N, n,a_normal, k_norm);
				break;
		}
			case 7: {
				int seed_1 = 2;
				int seed_2 = 2;
				init1(seed_1);
				init4(seed_2);
				double s = 1, u_1 = 0., u_2 = 0., v_1 = 0., v_2 = 0., x_1 = 0., x_2 = 0;
				for (int i = 0; i < n/2; ++i) {
					do {
						u_1 = double(LCG()) / m1;
						u_2 = double(ICG()) / m4;
						v_1 = 2 * u_1 - 1;
						v_2 = 2 * u_2 - 1;
						s = v_1*v_1 + v_2*v_2;
					} while (s >= 1);
					x_1 = v_1*sqrt((-2 * log(s)) / s);
					x_2 = v_2*sqrt((-2 * log(s)) / s);
					placement(x_1, interval_n, N, a_normal);
					placement(x_2, interval_n, N, a_normal);
				}
				histogram_out(interval_n, N, n, a_normal, k_norm);
				break;
			}
			case 8: {
				int seed_1 = 2;
				init1(seed_1);
				init4(seed_1);
				double u = 0., v = 0., x = 0.;
				for (int i = 0; i < n; ++i) {
					do {
						u = double(LCG()) / m1;
						v = double(ICG()) / m4;
						x = (sqrt(8. / M_E)*(v - 0.5)) / u;
					} while ((x*x <= 5 - 4 * exp(1. / 4)) && (x*x >= 4 * exp(-1.35) / u + 1.4) && (x*x <= -4 * log(u)));
					placement(x, interval_n, N, a_normal);
				}
				histogram_out(interval_n, N, n, a_normal, k_norm);
				break;
			}
			case 9: {
				int seed = 2;
				init1(seed);
				const double mu = 15;
				double u = 0., x = 0.;
				for (int i = 0; i < n; ++i) {
					u = double(LCG())/m1;
					if (u == 0) x = 0.;
					else x = -mu*log(u);
					placement(x, interval_o, O, a_unif);
				}
				histogram_out(interval_o, O, n, a_unif, k_other);
				break;
			}
			case 10: {
				int seed = 2;
				init2(seed);
				init4(seed);
				const int a = 33;
				double u = 0., y = 0., x = 0., v = 0.;
				for (int i = 0; i < n; ++i) {
					do {
						do {
							u = double(ICG()) / m4;
							y = tan(M_PI*u);
							x = sqrt(2 * a - 1)*y + a - 1;
						} while (x <= 0);

						v = double(QCG()) / m2;
					} while (v > (1 + y*y)*exp((a - 1)*log(x / (a - 1)) - sqrt(2 * a - 1)*y));
					placement(x, interval_o, O, a_unif);
				}
				histogram_out(interval_o, O, n, a_unif, k_other);
				break;
			}
		   default:
				std::cout << "You've decided to exit the program." << std::endl;
				system("pause");
			return 0;
			 
		  }
       for (int i = 0; i < U; ++i) {
			interval_u[i] = 0;
		}
	   for (int i = 0; i < N; ++i) {
		   interval_n[i] = 0;
	   }
	   for (int i = 0; i < O; ++i) {
		   interval_o[i] = 0;
	   }
	}
	return 0;

}