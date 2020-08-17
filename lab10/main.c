#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f_x(double x) {
	return log(pow(x,5)+ 3*(x*x) + x + 9);
}

double g_x(double x) {
	return pow(x,6);
}

int main(){

    FILE *file1;
    file1=fopen("f_zl.dat", "w");
    FILE *file2;
    file2=fopen("f_3.dat", "w");
    FILE *file3;
	file3 = fopen("g_zl.dat", "w");
	FILE *file4;
	file4 = fopen("g_3.dat", "w");
    double x_a = -0.5;
	double x_b = 1.0;
	double x_1 = x_a;
	double x_2 = x_b;
	double x_dokl = -0.1673198;
	
	double x_min;
	
	double r = (sqrt(5) - 1) / 2;
	double epsilon = 10e-6;
	
	int i = 0;
	

	
	do {
		i++;
		x_1 = x_a + r*r * (x_b - x_a);
		x_2 = x_a + r * (x_b - x_a);
		if (f_x(x_2) > f_x(x_1))
			x_b = x_2;
		else
			x_a = x_1;
		fprintf(file1, "%d	%f	%f	%f	%f\n", i, x_a, x_b, x_min = (x_a + x_b) / 2, fabs(x_min - x_dokl));
	}
	while (fabs(x_a - x_b) > epsilon);
	

	
	r = 1.0 / 3.0;
	i = 0;
	x_a = -0.5;
	x_b = 1.0;
	x_1 = x_a;
	x_2 = x_b;
	
	do {
		i++;
		x_1 = x_a + r * (x_b - x_a);
		x_2 = x_a + 2 * r * (x_b - x_a);
		if (f_x(x_2) > f_x(x_1))
			x_b = x_2;
		else
			x_a = x_1;
		fprintf(file2, "%d	%f	%f	%f	%f\n", i, x_a, x_b, x_min = (x_a + x_b) / 2, fabs(x_min - x_dokl));
	}
	while (fabs(x_a - x_b) > epsilon);
	

	
	r = (sqrt(5) - 1) / 2;
	i = 0;
	x_a = -4.0;
	x_b = 1.0;
	x_1 = x_a;
	x_2 = x_b;
	x_dokl = 0.0;
	
	do {
		i++;
		x_1 = x_a + r*r * (x_b - x_a);
		x_2 = x_a + r * (x_b - x_a);
		if (g_x(x_2) > g_x(x_1))
			x_b = x_2;
		else
			x_a = x_1;
		fprintf(file3, "%d	%f	%f	%f	%f\n", i, x_a, x_b, x_min = (x_a + x_b) / 2, fabs(x_min - x_dokl));
	}
	while (fabs(x_a - x_b) > epsilon);
	

	
	r = 1.0 / 3.0;
	i = 0;
	x_a = -4.0;
	x_b = 1.0;
	x_1 = x_a;
	x_2 = x_b;
	
	do {
		i++;
		x_1 = x_a + r * (x_b - x_a);
		x_2 = x_a + 2 * r * (x_b - x_a);
		if (g_x(x_2) > g_x(x_1))
			x_b = x_2;
		else
			x_a = x_1;
		fprintf(file4, "%d	%f	%f	%f	%f\n", i, x_a, x_b, x_min = (x_a + x_b) / 2, fabs(x_min - x_dokl));
	}
	while (fabs(x_a - x_b) > epsilon);



    return 0;
}
