//quadratic congruetional generetor  LCG
#include "QCG.h"

int seed2 = 0;

void init2(int x0) {
	seed2 = x0;
}
int QCG() {
	int next = (d2*seed2*seed2+a2*seed2 + c2) % m2;
	seed2 = next;
	return next;
}