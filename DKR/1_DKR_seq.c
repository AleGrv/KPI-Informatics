#include <stdio.h>
#include <stdlib.h>

/* MAIN */
int main() {

double S=0, a, pa;
int n, i=1, po1, po;

printf("Enter a= ");
scanf("%lf", &a);

printf("Enter n= ");
do{
scanf("%d", &n);
if(n<1) printf("Enter n>=1");
} while(n<1);

pa=a;

while(i<=n){

if(i-1==0 && i%2!=0) po1=1; else po1=-1;
if(i%2!=0) po=-1; else  po=1;

if(a+po*i!=0){
S=S+po1*pa/(a+po*i);
}

i++;
pa*=pa;
}

S=S+1;
printf("S= %lf", S);

	return 0;
}
/* MAIN, END */



