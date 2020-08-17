#include <stdio.h>
#include <stdlib.h>
#include <math.h>

# define PI 3.141592653589793238464

double U_1(const int a, const int c, long int m){
    static long int x = 10;
    x = (a*x + c) % m;
    return x/(m + 1.0);
}

double U_2(const int a, const int c, long int m){
    static long int x = 10;
    x = (a*x + c) % m;
    return x/(m + 1.0);
}

double U_3(long int m){
    static long int x0 = 10;
    static long int x1 = 10;
    static long int x2 = 10;

    long int x = (1176 * x2 + 1476 * x1 + 1776 * x0) % m;
    x0 = x1;
    x1 = x2;
    x2 = x;

    return x/(m + 1.0); 
}

void policz(double *tab, const int n,const int a, const int c, long int m, int liczba,FILE *file){
    for(int i = 0; i < n; i++)
    {
        if(liczba == 1)
            tab[i] = U_1(a,c,m);
        else if(liczba == 2)
            tab[i] = U_2(a,c,m);
        else
            tab[i] = U_3(m);
    }

    for(int i = 0; i < n - 3; i++)
    {
        fprintf(file, "%g %g %g %g \n", tab[i], tab[i+1], tab[i+2], tab[i+3]);
    }
    fprintf(file,"\n \n");
}



int main(void) {
    FILE *file1;
	file1 = fopen("uniform.dat", "w");
    FILE *file2;
	file2 = fopen("3D.dat", "w");
    FILE *file3;
	file3 = fopen("hist.dat", "w");
    const int n1 = 2000;
    int a1 = 17;
    int a2 = 85;
    int c12 = 0;
    long int m12 = pow(2,13) - 1;
    long int m3 = pow(2, 32) - 5;
    double tab1[n1];
  
    policz(tab1, n1, a1, c12, m12,1,file1);
    policz(tab1, n1, a2, c12, m12,2,file1);
    policz(tab1, n1, 0, 0, m3, 3, file1);

    //zadanie 1.2
    const int k = 10;
    const double delta = 1.0 / k;
    int N1[k],N2[k], N3[k]; 
    double G1[k], G2[k],G3[k]; 
   
    for(int i = 0; i < k; i++){
        N1[i] = N2[i] = N3[i] = 0;
    }
    const int maxsize = 10000000;

    double temp1[n1],temp2[n1],temp3[n1]; 
  
    for(int i = 0; i < maxsize; i++){
        double u1 = U_3(m3);
        double u2 = U_3(m3);
        double u3 = U_3(m3); 
        double u4 = U_3(m3);

        double x = sqrt(-2 * log(1 - u1)) * cos(2 * PI * u2);
        double y = sqrt(-2 * log(1 - u1)) * sin(2 * PI * u2);
        double z = sqrt(-2 * log(1 - u3)) * cos(2 * PI * u4);

        double length = sqrt(pow(x,2) + pow(y,2) + pow(z,2));

        x/=length;
        y/=length;
        z/=length;

        if(i < n1){ 
        fprintf(file2, "%g %g %g \n", x, y, z);
        }

        double ui = U_3(m3);
        double si = pow(ui, 1.0/3.0);
        x*=si;
        y*=si;
        z*=si;
        if(i < n1){ 
        temp1[i] = x;
        temp2[i] = y;
        temp3[i] = z;
        }

        double ri = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        int index = (int)(ri/delta);
        if(i < n1){           
            N1[index]++;
        }
        if(i < 10000){
            N2[index]++;            
        }
            N3[index]++;

    }
    fprintf(file2, "\n \n");
    for(int i = 0; i < n1; i++){
        fprintf(file2, "%g %g %g \n",temp1[i], temp2[i], temp3[i]);
    }

    double sum[k];
    for(int i = 0; i < k; i++){
        double rj = delta*(i+1);
        double rj1 = delta*i;
        double vj = (4.0 / 3.0) * PI * pow(rj, 3);
        double vj1 = (4.0 / 3.0) * PI * pow(rj1, 3);
        G1[i] = N1[i] / (vj - vj1);
        G2[i] = N2[i] / (vj - vj1);
        G3[i] = N3[i] / (vj - vj1);
        sum[i] = (rj+ rj1)/2; 
        fprintf(file3, "%g %d %g \n", sum[i], N1[i], G1[i]);
    }
    fprintf(file3,"\n \n");
    for(int i = 0; i < k; i++){
        fprintf(file3, "%g %d %g \n", sum[i], N2[i], G2[i]);
    }
    fprintf(file3,"\n \n");
        for(int i = 0; i < k; i++){
        fprintf(file3, "%g %d %g \n", sum[i], N3[i], G3[i]);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    return 0;



}
