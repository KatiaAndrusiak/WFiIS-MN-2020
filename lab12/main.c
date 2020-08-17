#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double funkcja(double k, double m, double x)
{
    return pow(x, m) * sin(k * x);
}


double silnia(int n)
{
    if (n == 0 || n == 1)  return 1.0;
    else  return (silnia(n - 1) * (1.0/n));
}

double suma(double i, double m, double k, double x)
{
    double licznik = pow(-1, i) * pow(k * x, 2 * i + m + 2)* silnia(2 * i + 1);
    double mianownik = pow(k, m + 1)  * (2 * i + m + 2);
    return licznik / mianownik;
}


void simspson(double n, double m, double k,  double I, FILE *fp)
{

    double h = (M_PI - 0) / n;
    double f0 = funkcja(k, m, 0);
    double fn = funkcja(k, m, M_PI);

    int i = 0;
    double sum = 0.0;
    double calka = 0.0;

    for (double j = h; j < M_PI; j += h)
    {
        if (i % 2)
            sum += 2 * funkcja(k, m, j);
        else
            sum += 4 * funkcja(k, m, j);
            
        i++;
    }

    sum = sum + f0 + fn;
    calka = (h / 3) * sum;

    fprintf(fp, "%f \t %f \t %f \n", n, calka, fabs(calka - I));
}

void policz(double m, double k, double I,  FILE *file){
        double a = 0.0;
        double b = M_PI;
        double result = 0.0;
        double wynik;
        double mod;
        int max=30;

        for (int i = 0; i < max; i++)
    {
        result += suma(i, m, k, b) - suma(i, m, k, a);
        wynik = result;
        mod = fabs(wynik - I);
        fprintf(file, "%d \t %f \t %f \n", i + 1, wynik, mod);
    }
}

void policzS(double m, double k, double I,  FILE *file){
    double N[5] = {10, 20, 50, 100, 200};
    for (int j = 0; j < 5; j++)
        {
            simspson(N[j], m, k, I, file);
        }
}


int main()
{

    FILE *dane1;
    dane1 = fopen("dane1.dat", "w");

    policz(0.0,1.0,2.0,dane1);



    FILE *dane2;
    dane2 = fopen("dane2.dat", "w");

    policz(1.0,1.0,M_PI, dane2);

   
    double I = 56.363569;
    FILE *dane3;
    dane3 = fopen("dane3.dat", "w");

    policz(5.0,5.0,I, dane3);

   

    

    FILE *daneS1;
    daneS1 = fopen("daneSimpson1.dat", "w");
    FILE *daneS2;
    daneS2 = fopen("daneSimpson2.dat", "w");
    FILE *daneS3;
    daneS3 = fopen("daneSimpson3.dat", "w");
    
    policzS(0.0,1.0,2.0,daneS1);
    policzS(1.0,1.0,M_PI, daneS2);
    policzS(5.0,5.0,I, daneS3);

    fclose(dane1);
    fclose(dane2);
    fclose(dane3);
    fclose(daneS1);
    fclose(daneS2);
    fclose(daneS3);

    return 0;
}