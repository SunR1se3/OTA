#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <locale.h>

using namespace std;

void input_data();

double Fn, Gn;
double arctg_Fn, arctg_Gn;
double pi, nBeg, nEnd, step, phi, k, delta, theta, o_large, ii;
double M_PI = 3.1415;

int main()
{
	setlocale(LC_ALL, "rus");
	FILE* f;
	f = fopen("lb1.txt", "w+");
	input_data();
	
	phi = M_PI / k;
	ii = nBeg;

	while (ii <= nEnd)
	{
		Fn = 2.5 * pow(ii, 2) + 6 * ii;
		Gn = 7.5 * ii * sqrt(ii) + 22 * ii;
		arctg_Fn = atan(Fn);
		arctg_Gn = atan(Gn);
		pi = arctg_Fn - arctg_Gn;
		delta = phi - pi;
		theta = fabs(pi) - phi;
		o_large = pi + phi;
		fprintf(f, "%f %f %f %f %f %f %f %f %f\n", ii, Fn, Gn, arctg_Fn, arctg_Gn, pi, delta, theta, o_large);
		ii += step;
	}
	fclose(f);
}

void input_data()
{
	cout << "Начальная точка ";
	cin >> nBeg;
	cout << endl;
	cout << "Конечная точка ";
	cin >> nEnd;
	cout << endl;
	cout << "Введите шаг ";
	cin >> step;
	cout << endl;
	cout << "Введите коэффициент ";
	cin >> k;
	cout << endl;
}
