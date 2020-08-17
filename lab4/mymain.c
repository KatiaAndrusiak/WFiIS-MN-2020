#include </usr/include/gsl/gsl_math.h>
#include </usr/include/gsl/gsl_linalg.h>
#include</usr/include/gsl/gsl_eigen.h>
#include <stdio.h>
#include <math.h>


double delta(int i, int j)
{
    double d;
    if(i==j) d=1;
    else d=0;
    return d;
}
int main()
{
    double L=10.0;
    double n=200.0;
    double N=1.0;
    double del_x=L/(n+1);
    int alfa;
    gsl_matrix *A = gsl_matrix_calloc(n, n);
    gsl_matrix *B = gsl_matrix_calloc(n, n);
    gsl_vector *x = gsl_vector_calloc(n);
    gsl_vector *ro = gsl_vector_calloc(n);
    gsl_eigen_gensymmv_workspace *w = gsl_eigen_gensymmv_alloc(n);
    gsl_vector *eval = gsl_vector_calloc(n);
    gsl_matrix *evec = gsl_matrix_calloc(n, n);
    FILE *file1;
    file1 = fopen("wyniki1.dat", "w");
    FILE *file2;
    file2 = fopen("wyniki2.dat", "w");
    FILE *file3;
    file3 = fopen("wyniki3.dat", "w");

    for(int i=0; i<n; i++)
    {
        gsl_vector_set(x, i,((-L/2)+del_x*(i+1)));
    }

    
    for(alfa=0; alfa<=100; alfa=alfa+2)
    {
        
        fprintf(file1, "%d ", alfa);

        for(int i=0; i<n; i++)
        {
            gsl_vector_set(ro, i, (1+4*alfa*pow(gsl_vector_get(x, i), 2)));
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++){
                gsl_matrix_set(A,i,j, (double)((-delta(i, j + 1) + 2 * delta(i, j) - delta(i, j - 1)) / pow(del_x, 2)));
                gsl_matrix_set(B,i,j, (gsl_vector_get(ro,i)*delta(i, j))/N);
             }

        } 
        gsl_eigen_gensymmv(A, B, eval, evec, w);
        gsl_eigen_gensymmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_ASC);

        for (int i = 0; i < 6; i++)
        {
            fprintf(file1, "%f ", sqrt(gsl_vector_get(eval, i)));
        }
        fprintf(file1, "\n");
        if (alfa == 0)
        {
            for (int i = 0; i < n; i++)
            {
                fprintf(file2, "%f ", gsl_vector_get(x,i));
                for (int j = 0; j < 6; j++)
                {
                    fprintf(file2, "%f ", gsl_matrix_get(evec, i, j));
                }
                fprintf(file2, "\n");
            }
        }
        if (alfa == 100)
        {
            for (int i = 0; i < n; i++)
            {
                fprintf(file3, "%f ", gsl_vector_get(x,i));
                 for (int j = 0; j < 6; j++)
                {
                    fprintf(file3, "%f ", gsl_matrix_get(evec, i, j));
                }
                fprintf(file3, "\n");
            }
        }
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);

return 0;
}
