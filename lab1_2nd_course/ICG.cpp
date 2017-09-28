#include "ICG.h"
int Extended_Euclid(int a, int b, int &  x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1=0,  y1=0;
	int d = Extended_Euclid(b%a, a, x1, y1);
	x = y1 - (b / a)*x1;
	y = x1;
	return d;
}

int Inverse_el (int el, int m, int &  x, int & y){ //x*el=1( mod m)
	int d = Extended_Euclid(el, m, x, y);
	if (d != 1) return 0;
	else return (x % m + m) % m;
}

int prev = 0;

void init4(int x0) {
	prev = x0;
}
int ICG() {
	int x = 0, y = 0;
	int next = (a4*Inverse_el(prev, m4, x, y) + c4) % m4;
	prev = next;
	return next;
}