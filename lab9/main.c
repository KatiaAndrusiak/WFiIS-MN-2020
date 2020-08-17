#include "gsl/gsl_linalg.h"
#include "gsl/gsl_math.h"
#include "math.h"
#include "stdio.h"
double funkcja( double x){
    return sin(x);
}
const double xmin=-2*3.14;
const double xmax=2*3.14;

long int factorial(int n) { 
    int c; long int r = 1;
for (c = 1; c <= n; c++) r = r * c;
return r; }

void aproksymacja( int n, int m,  FILE* file1){
 gsl_matrix *A = gsl_matrix_calloc(n ,m);
 gsl_vector *y = gsl_vector_calloc(n);
 gsl_permutation *p = gsl_permutation_alloc(n); 
 int signum; 
 gsl_vector * x = gsl_vector_calloc(n); 
    double c[n+m+1];
    double b[m+1];
    double a[n+1];
    

    // c
    for(int k=0; k<=(n+m)/2; k++){
        c[2*k]=0;
        c[2*k+1]=pow(-1,k)/(double)factorial(2*k+1);
    }
    
    // A
   for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
         gsl_matrix_set(A,i,j,c[n-m+i+j+1]);
        }
    }

    // y 
  for(int i=0; i<m;i++){
        gsl_vector_set(y, i, -c[n+1+i]);
    }
     
    gsl_linalg_LU_decomp(A, p, &signum);
    gsl_linalg_LU_solve(A,p,y,x);

    // b
    b[0]=1;
    for(int i=0; i<m; i++){
        b[m-i]=gsl_vector_get(x,i);
    }
    
    
    // a
    for(int i=0; i<=n; i++){
            a[i]=0;
    }
    for(int i=0; i<=n; i++){
        for(int j=0; j<=i; j++){
            a[i]+=c[i-j]*b[j];
        }
    }

   


    double Rx=0;
    double Pn;
    double Qm;
     for(double _x=xmin; _x<=xmax; _x+=0.02) {
         Pn=0; Qm=0;
        for(int i=0; i<=n; i++){  
            Pn+=a[i]*pow(_x,i);
        }
        for(int i=0; i<=m;i++) { 
            Qm+=b[i]*pow(_x,i);
        }
      Rx=Pn/Qm;
      fprintf(file1," %g %g  \n",_x, Rx);
     } 
    fprintf(file1,"\n\n");

}


int main(){
    FILE *file1;
	file1 = fopen("wyn.dat", "w");
    aproksymacja(3,3,file1);
    aproksymacja(5,5,file1);
    aproksymacja(7,7,file1);
    return 0;
}
