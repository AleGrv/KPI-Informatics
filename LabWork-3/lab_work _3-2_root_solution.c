#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

/* FUNCTIONS DECLARATION */

//--- Expression
double expr();

//--- Derivative sign check;
int sgn_ch();

//--- Secant method;
int scnt_mtd();

//--- Bisection method;
int bsect_mtd();

//--- Result output;
void r_out();

/* MAIN */
int main(){
time_t t_start=time(NULL);

/* VARIABLES DECLARATION */
double A, X, Y, Yabs, B, eps, X0, Xn, Xl, Xr, dX;
int N, i, sln_mtd, sg_ch, sgn_xl, eps10, sgn_x, dbg_mod;
char e_chr;
unsigned int t_res;
//---
while(1){

/* METHOD SELECTION */
do{
system("cls");
printf("\n\tSelect the a root-finding method:\n\n");
printf("\t1. Secant method: \n"); //--- Secant method
printf("\t2. Bisection method:\n\n"); //--- Bisection method
printf("\tEnter selected root-finding method number: ");
scanf("%d", &sln_mtd);

if(sln_mtd!=1 && sln_mtd!=2){
printf("\t\nThis method number is not available!\n");
printf("\n\tPress 'e' to Exit or ... Other key to Continue... ");
e_chr=getch();
if(e_chr=='e') exit(1);
}
}while(sln_mtd!=1 && sln_mtd!=2);

//--- Debug mode
printf("\n\tEnable Debug mode: (1 - on / 0 - off)?: ");
scanf("%d", &dbg_mod);
if(dbg_mod!=1) dbg_mod=0;

/* PARAMETERS INPUT */
do{
printf("\n\tLeft boundary: a= ");
scanf("%lf", &A);
printf("\n\tRight boundary: b= ");
scanf("%lf", &B);
printf("\n\tError eps=1/10^(eps10) (0<eps10). If eps10=0, exit...: eps10= ");
scanf("%d", &eps10);
if(eps10<=0) exit(1);
printf("\n\tIteration number (n>0). If n=0, exit...: n= ");
scanf("%d", &N);
if(N<=0) exit(1);
eps=1/powl(10, eps10);

//--- Derivative
sg_ch=sgn_ch(A, B);
if(sg_ch==-1){
e_chr=getch();
if(e_chr=='e') exit(1);
system("cls");
}

}while(sg_ch==-1);

/* WORKSPACE */
system("cls");

switch (sln_mtd) {

//--- Secant method
case 1: {

scnt_mtd(N, A, B, X0, Xn, Yabs, eps, X, Y, i, dbg_mod);

} // case 1 end
break;

//--- Bisection method
case 2: {

bsect_mtd(A, X, Y, B, eps, Xn, Xl, Xr, dX, N, i, sgn_xl, sgn_x, dbg_mod);

} // case 2 end
} // switch end

time_t t_stop=time(NULL);
t_res=t_stop-t_start;
printf("\n\tProgram execution time: %u sec", t_res);
printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
e_chr = getch();
if (e_chr == 'e') exit(1);
/* WORKSPACE, END */
} // while(1)
return 0;
}
/* MAIN, END */

/* FUNCTIONS DEFINITION */

//--- Expression
double expr(double X){
//. y=x^2/1000-0.5*x-1000; 6 variant expression
//. Y=0 {X1=-780.77640640, X2=1280.77640640
return powl(X, 2)/1000-0.5*X-1000;
}

//--- Derivative sign check
int sgn_ch(double A, double B){
double Ya, Yb, sgn_ya, sgn_yb;
Ya=(0.002*A-0.5);
Yb=(0.002*B-0.5);
sgn_ya=copysign(1, Ya);
sgn_yb=copysign(1, Yb);

if(sgn_ya!=sgn_yb) {

printf("\t\nSegment [a,b] has several solutions. Select other segment boundaries.\n\n");
printf("A= %.1lf, B= %.1lf, Y(A)= %.5lf, Y(B)= %.5lf", A, B, Ya, Yb);
printf("\n\tPress 'e' to Exit or ... Other key to Continue... ");

return -1;
}
return 0;
}

//=================
//--- Secant method
//=================

int scnt_mtd(int N, double A, double B, double X0, double Xn, double Yabs, double eps, double X, double Y, int i, int dbg_mod ){

if(expr(A)>0){
X0=B; Xn=A;
} else {X0=A; Xn=B;}

//--- X0=B
if(X0==B){
i=1;
Xn=A;
Yabs=fabsf(expr(X));

while(Yabs>=eps){

X=X0-expr(X0)*(X0-Xn)/(expr(X0)-expr(Xn));
Y=expr(X);
Yabs=fabsf(Y);

//---
if(fabs(X0)>=fabs(Xn)){
if(Yabs>eps){
printf("\t\nSegment [a,b] has no solutions. Select other segment boundaries.\n\n");
exit(1);
}
}

if(dbg_mod==0){
if(i==N){

printf("\nError equals N\n");
r_out(N, A, B, eps, i, X, Y);
printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
char e_chr = getch();
if (e_chr == 'e') exit(1);
}// i = N, x0=B
}// dm = 0, x0=B

if(dbg_mod==1){
r_out(N, A, B, eps, i, X, Y);
printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
char e_chr = getch();
if (e_chr == 'e') exit(1);
system("cls");
} // dm = 1, x0=B

X0=X;
i++;
} // while eps
} // x0=B

//--- X0=A
if(X0==A){
i=1;
Xn=B;
Yabs=fabsf(expr(X));

while(Yabs>=eps){

X=X0-expr(X0)*(Xn-X0)/(expr(Xn)-expr(X0));
Y=expr(X);
Yabs=fabsf(Y);

//---
if(fabs(X0)>=fabs(Xn)){
if(Yabs>eps){
printf("\t\nSegment [a,b] has no solutions. Select other segment boundaries.\n\n");
exit(1);
}
}

if(dbg_mod==0){
if(i==N){
printf("\n Iterations number equals N\n");
r_out(N, A, B, eps, i, X, Y);
printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
char e_chr = getch();
if (e_chr == 'e') exit(1);
}// i = N, x0=A
}// dm = 0, x0=A

if(dbg_mod==1){
r_out(N, A, B, eps, i, X, Y);
printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
char e_chr = getch();
if (e_chr == 'e') exit(1);
system("cls");
} // dm = 1

X0=X;
i++;
} // while eps*/
} // x0=A
r_out(N, A, B, eps, i, X, Y);

return 0;
}

//====================
//--- Bisection method
//====================

int bsect_mtd(double A, double X, double Y, double B, double eps, double Xn, double Xl, double Xr, double dX, int N, int i, int sgn_xl, int sgn_x, int dbg_mod){

Xl=A; Xr=B;
dX=B-A;
i=1;

while (fabsf(expr(Xl))>eps||fabsf(expr(Xr))>eps){

dX=dX/2;
X=Xl+dX;
sgn_xl=copysign(1, expr(Xl));
sgn_x=copysign(1, expr(X));
if(sgn_xl!=sgn_x) Xr=X;
else Xl=X;
Y=expr(X);

if(dbg_mod==0){
if(i==N){
printf("\n Iterations number equels N\n");
r_out(N, A, B, eps, i, X, Y);
printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
char e_chr = getch();
if (e_chr == 'e') exit(1);
}// i = N, x0=A
}// dm = 0, x0=A

if(dbg_mod==1){
r_out(N, A, B, eps, i, X, Y);
printf("\n\n\tPress 'e' to Exit or ... Other key to Continue... ");
char e_chr = getch();
if (e_chr == 'e') exit(1);
system("cls");
} // dm = 1

i++;
} // while eps
r_out(N, A, B, eps, i, X, Y);

return 0;
}

//--- Result output
void r_out(int N, double A, double B, double eps, int i, double X, double Y){
printf("\n");
printf("-------------------------------------------------------------------------\n");
printf("|            N            |    A    |    B    |          Error          |\n");
printf("+-------------------------+---------+---------+--------------------------\n");
printf("|%24d |%8.1lf |%8.1lf |%24.14lf |\n", N, A, B, eps);
printf("-------------------------------------------------------------------------\n\n");
//---
printf("-------------------------------------------------------------------------\n");
printf("|   Iterations    |          root: X          |           F(X)          |\n");
printf("+-----------------+---------------------------+-------------------------+\n");
printf("|%16d |%26.20lf |%24.18lf |\n", i, X, Y);
printf("-------------------------------------------------------------------------\n\n");
}

/*
sln_mtd - solution method;
A - left boundary;
B - right boundary;
X - root variable;
X0 - start X;
Xl - left X;
Xr - right X;
Xn - final X;
Y - expression result;
eps - error;
eps10 - 10-power
dbg_mod - "debug mode" marker;
t_res - time result;
*/
