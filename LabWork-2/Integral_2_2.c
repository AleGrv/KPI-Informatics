#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/*
expression: S(-3, 0) dX/(25+3*X)^(1/2): 1/sqrt(3*x+25);
a=-3 - left boundry "a";
b=0 - right boundry "b";
n - segments amount;
N - segments amount for measurement error (0.00001<= Delta<= 0.001);
N_min - minimum N value for Delta;
N_max - maximum N value for Delta;
h - segment length (integration step);
Delta = |I1-I2|;
Delta_min - minimum Delta value;
Delta_max - maximum Delta value;
s -  integral value;
I1 -  integral value from N;
I2 - integral value from N+2;
i - counter;
f_p - function pointer;
x - expression variable;
*/

//--- Numerical integration rules functions declaration:

// left rectangle
double lt_rtn_r();

// right rectangle
double rt_rtn_r();

// trapezoid
double trp_r();

// Composite Simpson's quadrature rule (parabolas)
double c_smps_r();

//--- computing expression function
double expr();

//--- "N, Delta" function and result output
int N_D();

//--- MAIN FUNCTION ---
int main() {

//--- variables declaration
    double a=-3, b=0;
    int n, rule;
    double s=0;
    double (*f_p)();

//--- while (always true)
    while (1) {

        system("cls");

//---
        do {

//--- The Numerical integration rule selection
            printf("\n\t\tThe Numerical integration. Variant 6.\n\n");
            printf("\n\tSelect the integration rule:\n\n");
            printf("\t1. By Left Rectangles :\n");
            printf("\t2. By Right Rectangles:\n");
            printf("\t3. By Trapezoid:\n");
            printf("\t4. By Simpson's (parabola), even 'n' values:\n\n");
            printf("\tEnter selected Rule number: ");
            scanf("%d", &rule);

            if (rule!=1 && rule!=2 && rule!=3 && rule!=4) {
                printf("\n\tThis rule number is not available!\n");

                printf("\n\tPress 'e' to Exit or ... Other key to Continue... ");

                char e_char=getch();

                if (e_char=='e') exit(1);
                system("cls");
            }
        } while (rule!=1 && rule!=2 &&rule!=3 && rule!=4);

//---
        do {

            printf("\n\tEnter the number of segments n (n>0). ...n=0 to Exit!... :\n\n\tn= ");
            scanf("%d", &n);

            if (n==0) exit(1);

        } while (n<0);

//---
        system("cls");

//--- switch (Integrals computation)
        switch (rule) {

//--- 1, left rectangle
        case 1:

        {
            printf("\n\n  = Numerical integration Left Rectangles rule =\n");
            printf("\n\tLeft boundry:  a= %.2lf\n\tRight boundry: b=  %.2lf\n\n\tSegments amount: n= %d\n", a, b, n);

            s=lt_rtn_r(a, b, n);

//---
            f_p=lt_rtn_r;

            N_D(a, b, n, s, f_p);
        }
        break;

//---  2, right rectangle
        case 2:

        {
            printf("\n\n  = Numerical integration Right Rectangles rule =\n");
            printf("\n\tLeft boundry:  a= %.2lf\n\tRight boundry: b=  %.2lf\n\n\tSegments amount: n= %d\n", a, b, n);

            s=rt_rtn_r(a, b, n);

//---
            f_p=rt_rtn_r;

            N_D(a, b, n, s, f_p);
        }
        break;

//--- 3, trapezoid
        case 3:

        {
            printf("\n\n  = Numerical integration Trapezoid rule =\n");
            printf("\n\tLeft boundry:  a= %.2lf\n\tRight boundry: b=  %.2lf\n\n\tSegments amount: n= %d\n", a, b, n);

            s=trp_r(a, b, n);

//---
            f_p=trp_r;

            N_D(a, b, n, s, f_p);
        }
        break;

//--- 4, Composite Simpson's
        case 4:

        {
            printf("\n\n  = Numerical integration Simpson's rule =\n");
            printf("\n\tLeft boundry:  a= %.2lf\n\tRight boundry: b=  %.2lf\n\n\tSegments amount: n= %d\n", a, b, n);

            s=c_smps_r(a, b, n);

//---
            f_p=c_smps_r;

            N_D(a, b, n, s, f_p);
        }
        }
//--- switch (Integrals computation), END
    }
//--- while ( alwais true), END

    return 0;
}
//--- MAIN FUNCTION, END ---

//--- FUNCTIONS DEFINITION ---

//--- left rectangle
double lt_rtn_r(double a, double b, int n) {

//--- S = h*(E k(1, n-1) f(xk))

    double x=0, s=0;
    double h=(b-a)/n;

//---
    for (int i=0; i<n; i++) {
        s+=expr(x);
        x=a+h*i;
    }

    return h*s;
}
//--- left rectangle, END

//--- right rectangle
double rt_rtn_r(double a, double b, int n) {

//--- S = h*(E k(1, n) f(xk))

    double x=0, s=0;
    double h=(b-a)/n;

//---
    for (int i=0; i<n; i++) {
        x=a+h*i;
        s+=expr(x);

    }

    return h*s;
}
//--- right rectangle, END

//--- trapezoid
double trp_r(double a, double b, int n) {

//--- S = h*(f(a)/2 + E k(1, n-1) f(xk) + f(b)/2)

    double x=0, s=0;
    double h=(b-a)/n;

//---
    for (int i=1; i<n; i++) {
        x=a+h*i;
        s+=expr(x);
    }
    s+=(expr(a)+expr(b))/2;

    return h*s;
}
//--- trapezoid, END

//--- Composite Simpson's
double c_smps_r(double a, double b, int n) {

//--- S = (h/3)*( f(a) + 4*E k(1.3.5., n-1) f(xk) + 2*E k(2.4.6., n-2) (xk) + f(b))

    double x=0;
    double s1=0, s2=0;
    double h=(b-a)/n;
    double s=expr(a)+expr(b);


    for (int i=1; i<=n-1; i+=2) {
        x=a+h*i;
        s1+=expr(x);
    }

    x=0;
    for (int i=2; i<=n-2; i+=2) {
        x=a+h*i;
        s2+=expr(x);
    }

    s+=4*s1+2*s2;

    return s*h/3;
}
//--- Simpson's, END

//--- expression function, variant 6
double expr(double x) {
    return 1/sqrt(3*x+25);
}
//--- expression function, variant 6, END

//--- "N, Delta" function and result output
int N_D(double a, double b, int n, double s, double (*f_p)()) {

    double I1, I2, Delta, Delta_min, Delta_max, I1_N_min, I2_N_min, I1_N_max, I2_N_max;
    int N, N_min, N_max;

//---
    I1=f_p(a, b, n);
    I2=f_p(a, b, n+=2);

    Delta=fabs(I1-I2);

//--- N min,  Delta max
    Delta_max=1;
    for (int i=1; Delta_max>0.001; i++) {
        n=i;
        I1_N_min=f_p(a, b, n);
        I2_N_min=f_p(a, b, n+=2);
        Delta_max=fabs(I1_N_min-I2_N_min);
        N_min=n-2;
    }
    if (Delta_max>0.001) N_min+=1;
    if (f_p==c_smps_r && N_min%2 !=0) N_min+=1;

//--- N max, Delta min
    Delta_min=1;
    for (int i=1; Delta_min>0.00001; i++) {
        n=i;
        I1_N_max=f_p(a, b, n);
        I2_N_max=f_p(a, b, n+=2);
        Delta_min=fabs(I1_N_max-I2_N_max);
        N_max=n-2;
    }
    if (Delta_min<0.00001) N_max-=1;
    if (f_p==c_smps_r && N_max%2 !=0) N_max-=1;

//--- result output
    printf("\n\tIntegral= %.8lf\n", s);

    printf("\n\tI1= %.8lf\n\tI2= %.8lf\n", I1, I2);

    if (Delta>0.001) printf("\n\tDelta for current 'n': %.8lf >0.001, NO! :(\n", Delta);
    else if (Delta<0.00001) printf("\n\tDelta for current 'n': %.8lf <0.00001, NO! :(\n", Delta);
    else printf("\n\tDelta for current 'n': 0.00001<= %.8lf <=0.001, YES! :)\n", Delta);

    printf("\n  = N for (0.00001<= Delta <=0.001) =\n");

    printf("\n\tN values range: [%d, %d]\n", N_min, N_max);

    printf("\n  Press 'e' to Exit ... or Other key to continue... ");
    char e_char = getch();
    if (e_char == 'e') exit(1);

    return 0;
}
//--- "N, Delta" function and result output, END

//--- FUNCTIONS DEFINITION, END ---
