//linear congruetional generetor  LCG
#include "LCG.h"

int seed1 = 0;

void init1(int x0) {
	seed1 = x0;
}
int LCG () {
	int next = (a1*seed1 + c1) % m1;
	seed1 = next;
	return next;
	}