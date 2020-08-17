#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000
#define m 10

void iloczynMW(float a[N][N], float x[N], float tmp[N])
{
	for (int i = 0; i < N; i++)
	{
		tmp[i] = 0;
		for (int j = fmax(0, i - m); j <= fmin(i + m, N - 1); j++)
		{
			tmp[i] += (a[i][j] * x[j]);
		}
	}
}

float iloczynSkalarny(float w1[N], float w2[N])
{
	float wynik = 0.0;
	for (int i = 0; i < N; i++)
		wynik += w1[i] * w2[i];

	return wynik;
}

void sumW(float w1[N], float w2[N])
{
	for (int i = 0; i < N; i++)
		w2[i] = w1[i] + w2[i];
}

int main(void)
{

	float licznik = 0.0;
	float mianownik = 0.0;
	float alfa = 0.0;
	float A[N][N];
	float b[N],x[N], r[N];
	float Ax[N];
	FILE *fpa = fopen("zad_a.dat", "w");
	FILE *fpb = fopen("zad_b.dat", "w");

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (abs(i - j) > m)
			{
				A[i][j] = 0.0;
			}
			else
			{
				A[i][j] = 1.0 / (1.0 + abs(i - j));
			}
		}
	}

	for (int i = 0; i < N; i++)		b[i] = i;

	for (int i = 0; i < N; i++)		x[i] = 0.0;

	int k = 0;
	do
	{
		iloczynMW(A, x, Ax);

		for (int i = 0; i < N; i++)
			r[i]= b[i] - Ax[i];

		iloczynMW(A, r, Ax);
		licznik = iloczynSkalarny(r, r);
		mianownik = iloczynSkalarny(r, Ax);
		alfa = licznik / mianownik;

		for (int i = 0; i < N; i++)
			Ax[i] = r[i] * alfa;
		sumW(Ax, x);

		k++;

		fprintf(fpa, "%d \t %f \t %f \t %f\n", k, sqrt(iloczynSkalarny(r, r)), alfa, sqrt(iloczynSkalarny(x, x)));

	} while (sqrt(iloczynSkalarny(r, r)) > pow(10, -6) && k < 500);

	for (int i = 0; i < N; i++)
		x[i] = 1.0;

	k = 0;

	do
	{
		iloczynMW(A, x, Ax);

		for (int i = 0; i < N; i++)
			r[i] = b[i] - Ax[i];

		iloczynMW(A, r, Ax);
		licznik = iloczynSkalarny(r, r);
		mianownik = iloczynSkalarny(r, Ax);
		alfa = licznik / mianownik;

		for (int i = 0; i < N; i++)
			Ax[i] = r[i] * alfa;
		sumW(Ax, x);

		k++;
		fprintf(fpb, "%d \t %f \t %f \t %f\n", k, sqrt(iloczynSkalarny(r, r)), alfa, sqrt(iloczynSkalarny(x, x)));

	} while (sqrt(iloczynSkalarny(r, r)) > pow(10, -6) && k < 500);

	fclose(fpa);
	fclose(fpb);

	return 0;
}
