#include <iostream>

using namespace std;

short int findLength(unsigned long long);
unsigned long long karatsuba(unsigned long long, unsigned long long);

int main()
{
	unsigned long long a = 2016;
	unsigned long long b = 1963;
	unsigned long long c = 201653;
	unsigned long long d = 1963;
	unsigned long long e = 20165545;
	unsigned long long f = 1963;
	unsigned long long g = 2016;
	unsigned long long h = 1963412415;

	cout << karatsuba(a, b) << endl;
	cout << a * b << endl;
	
	cout << karatsuba(c, d) << endl;
	cout << c * d << endl;
	
	cout << karatsuba(e, f) << endl;
	cout << e * f << endl;

	cout << karatsuba(g, h) << endl;
	cout << g * h << endl;
	
	system("pause");
	return 0;
}

short int findLength(unsigned long long var){
	short int counter = 0;
	while (var > 0){
		counter++;
		var = var / 10;
	}
	return counter;
}

unsigned long long karatsuba(unsigned long long x, unsigned long long y){
	short int xLength = findLength(x);
	short int yLength = findLength(y);

	int Longer;
	if (xLength > yLength)
		Longer = xLength;
	else
		Longer = yLength;

	if ((xLength + yLength) < 5 ) // en iyi deðer ?
		return x*y;

	Longer = (Longer / 2) + (Longer%2);

	long long b_ustu_m = pow(10, Longer);

	//19 x 10^2 + 63 ----- 20 x 10^2 + 16
	//x0          x1       y0          y1
	long long x0 = x / b_ustu_m;
	long long x1 = x - (x0 * b_ustu_m);
	long long y0 = y / b_ustu_m;
	long long y1 = y - (y0 * b_ustu_m);

	long long z0 = karatsuba(x1, y1);
	long long z2 = karatsuba(x0, y0);
	long long z1 = karatsuba(x1 + x0, y1 + y0) - (z0 + z2);

	long long P = z0 + (z1 * b_ustu_m) + (z2 * (long long)(pow(10, 2 * Longer)));


	return P;
}
