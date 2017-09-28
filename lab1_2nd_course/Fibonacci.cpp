//Fibonacci sequence
#include "Fibonacci.h"

int prev3 = 0, cur3 = 0;
void init3(int x0, int x1) {
	prev3 = x0;
	cur3 = x1;
}

int Fibonacci() {
	int next = (cur3 + prev3) % m3;
	prev3 = cur3;
	cur3 = next;
	return next;
}