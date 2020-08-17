#include <stdlib.h>
#include <stdio.h>
#include <math.h>


double funkcja(double x) {
    return sin(x)-((x*x)/8);
}

double pochodnaFunkcji(double x) {
    return cos(x)-(x/4);
}


void metodaSiecznych(double x0, double x1, int K, FILE *file){
    double x2 = 0;
    for(int k = 1; k <= K; k++) {
       x2 = x1 - ((x1 - x0)/(funkcja(x1) - funkcja(x0))) * funkcja(x1);
       fprintf(file, "%3d  %14f  %14f %14f \n", k, x2, funkcja(x1), funkcja(x0));
       //if(fabs(x2 - x1) < pow(10, -6)){
       //     break;
        //}
       x0 = x1;
       x1 = x2;
    }
    fprintf(file,"\n");

}

void metodaNewtona(double x, int K,  FILE *file)
{
    for(int k=1; k<=K; k++){
        x=x-funkcja(x)/pochodnaFunkcji(x);
        fprintf(file, "%3d  %14f  %14f %14f \n", k, x, funkcja(x), pochodnaFunkcji(x));
    }
    fprintf(file,"\n");
}

int main()
{
    FILE *file1;
    file1 = fopen("MetNewtona.dat", "w");
    FILE *file2;
    file2 = fopen("MetSiecznych.dat", "w");

    metodaNewtona(-8, 10, file1);
    metodaNewtona(8, 10, file1);

    metodaSiecznych(-8, -8.1, 15, file2);
    metodaSiecznych(8, 8.1, 15, file2);

    fclose(file1);
    fclose(file2);
    return 0;
}