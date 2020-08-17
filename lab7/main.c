#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.141592653589

const double xmin = -5.0;
const double xmax = 5.0;

double funkcja(double x) {
    return exp(-(x * x));
}

double lagraunge(double* x, double* y, int n, double _x){
    
   double wielomian = 0.0;
    for(int i = 0; i <= n; i++) {
        double licznik = 1.0;
        double mianownik = 1.0;
        for(int j = 0; j <= n; j++) {
            if(j != i){
                licznik *=(_x - x[j]);
                mianownik *= (x[i] - x[j]);
            } 
        }
        wielomian += y[i] * (licznik / mianownik);
    }
    return wielomian;
}



double czebyszew_x(int n, int m){
    return 0.5 * ( (xmax - xmin)* cos(PI*(2.0 * (double)m + 1.0)/(2.0 * (double)n + 2.0) )
            + (xmin + xmax));
}



void policz(int n, FILE* file1, FILE* file2){
    double x[n + 1];
    double y[n + 1];
    double cx[n + 1];
    double cy[n + 1];
 
    double h=(xmax - xmin) / (double)n;

    for(int i = 0; i <=n; i++){
        x[i] = y[i] = cx[i] = cy[i] = 0.0;

        x[i] = xmin + h * i;

        y[i] = funkcja(x[i]);

        cx[i] = czebyszew_x(n, i);

        cy[i] = funkcja(cx[i]);
    }

 
    double wielom=0.0;
        for(int i = 0; i<=1000; i++) {
                double xZnaczenia = xmin + 0.01 * i;
                wielom = lagraunge(x, y, n , xZnaczenia);
                fprintf(file1, "%g	", xZnaczenia);
                fprintf(file1, "%g\n", wielom);
        }


        for(int i = 0; i<=1000; i++) {
            double xZnaczenia = xmin + 0.01 * i;
            double wielom = lagraunge(cx, cy, n , xZnaczenia);
            fprintf(file2, "%g	", xZnaczenia);
            fprintf(file2, "%g\n", wielom);
        }
    

   
}

int main(void) {

   
    FILE *zad_1;
	zad_1 = fopen("zad_1.dat", "w");
    FILE *zad_2;
	zad_2 = fopen("zad_2.dat", "w");

    for(int n = 5; n <= 20; n += 5){
        policz(n,zad_1,zad_2);
        fprintf(zad_1, "\n \n");
        fprintf(zad_2, "\n \n");
    }

    fclose(zad_1);
	fclose(zad_2);

return 0;
}