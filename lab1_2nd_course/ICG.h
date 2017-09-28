#pragma once
const int m4 = 131071; //the modulus
const int a4 = 105; //the multiplier
const int c4 = 1282; // the increment
int Extended_Euclid(int a, int b, int &  x, int & y);
int Inverse_el(int el, int m, int &  x, int & y);
void init4(int x0);//initial seed
int ICG(); //returns next random number
