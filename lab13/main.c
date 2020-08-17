#include"nrutil.c"
#include"nrutil.h"
#include"nr.h"
#include"gauher.c"
#include"gauleg.c"
#include"gaulag.c"
#include"gammln.c"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float fun(float x){
    return log(x);
}

float fun2a(float x){
    return powf((x-10.0),2.0)*sin(4.0*x);
}

float fun2b(float x){
    return powf((x-10.0),2.0)*sin(4.0*x)*exp(-x);
}

float fun3a(float x){
    return powf(x,7.0)*powf(2.0,(-powf(x,2.0)+x+4.0));
}

float fun3b(float x){
    return powf(x,7.0)*powf(2.0,(-powf(x,2.0)+x+4.0))*exp(-powf(x,2.0));
}

int main(){
    /////////////////////////////////   1  /////////////////////
    float x2=10.0;
    float x1=0.0;
    FILE *dane1;
    dane1 = fopen("dane1.dat", "w");
     double Cnum=x2*log(x2)-x2;

    for(int n=5; n<=70; n++){
        double C=0.0;
        float *x=vector(1,n);
        float *w=vector(1,n);
        gauleg(x1, x2, x, w, n);
        for(int i=1; i<=n; i++){
            C+=w[i]*fun(x[i]);
        }
        fprintf(dane1, " %d \t %f \t %e \n", n,  C,  fabsf(C - Cnum));
    }

    //////////////////////////////////   2   /////////////////////
    ////a)
    FILE *dane2a;
    dane2a = fopen("dane2a.dat", "w");
    Cnum= 22.95461022;
    float alf=0.0;
    for(int n=5; n<=70; n++){
        double C=0.0;
        float *x=vector(1,n);
        float *w=vector(1,n);
        gaulag( x, w, n,alf);
        for(int i=1; i<=n; i++){
            C+=w[i]*fun2a(x[i]);
        }
        fprintf(dane2a, " %d \t %f \t %e \n", n,  C,  fabsf(C - Cnum));
    }
    ///b)
    FILE *dane2b;
    dane2b = fopen("dane2b.dat", "w");
    Cnum= 22.95461022;
    for(int n=5; n<=70; n++){
        double C=0.0;
        float *x=vector(1,n);
        float *w=vector(1,n);
        gauleg(x1, x2, x, w, n);
        for(int i=1; i<=n; i++){
            C+=w[i]*fun2b(x[i]);
        }
        fprintf(dane2b, " %d \t %f \t %e \n", n,  C,  fabsf(C - Cnum));
    }

    //////////////////////// 3 ////////////////////////////
    /// a)
    FILE *dane3a;
    dane3a = fopen("dane3a.dat", "w");
    Cnum =  14.83995751;
    for(int n=5; n<=70; n++){
        double C=0.0;
        float *x=vector(1,n);
        float *w=vector(1,n);
        gauher(x, w, n);
        for(int i=1; i<=n; i++){
            C+=w[i]*fun3a(x[i]);
        }
        fprintf(dane3a, " %d \t %f \t %e \n", n,  C,  fabsf(C - Cnum));
    }

    /// b)
     FILE *dane3b;
    dane3b = fopen("dane3b.dat", "w");
    Cnum =  14.83995751;
    x1=-10.0;
    x2=15.0;
    for(int n=5; n<=70; n++){
        double C=0.0;
        float *x=vector(1,n);
        float *w=vector(1,n);
        gauleg(x1, x2, x, w, n);
        for(int i=1; i<=n; i++){
            C+=w[i]*fun3b(x[i]);
        }
        fprintf(dane3b, " %d \t %f \t %e \n", n,  C,  fabsf(C - Cnum));
    }
    ///////////////////
    FILE * other1, * other2, * other3;
    other1 = fopen("fun1.dat","w");
    other2 = fopen("fun2.dat","w");
    other3 = fopen("fun3.dat","w");

    for (double i = 0.1; i <=10; i+=0.1) 
        fprintf(other1,"%f\t%f\n",i, fun(i));

    for (double i = 0; i <=10; i+=0.1) 
        fprintf(other2,"%f\t%f\n",i, fun2b(i));
        

    for (double i = -10; i <=15; i+=0.1) 
        fprintf(other3,"%f\t%f\n",i, fun3b(i));
    fclose(dane1);
    fclose(dane2a);
    fclose(dane2b);
    fclose(dane3a);
    fclose(dane3b);
    fclose(other1);
    fclose(other2);
    fclose(other3);
    return 0;
}
