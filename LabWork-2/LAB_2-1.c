#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

// expressions functions declaration

// 1
double Y1(double);
// 2
double Y2(double);
// 3
double Y3(double);

// main funcion

int main() {

    /* variant 6
    y = ln((x^2) / 10) + 2, 10 <= x < 100
    y = lg(x) + (x^2 - 4) / (x^3 + 5), 100 <= x < 1001
    y = -3 * (sin(x))^2 + 3, 1800 <= x < 2000
    y = 1, for all ather x values.
    */

    double X, Y;
    char E;

    while (1) {

        printf("Enter X -> 10...99, 100...1000, 1800...1999: ");
        scanf("%lf", &X);

        if (X >= 10 && X < 100) {

            Y = Y1(X);
            E = '1';
        }

        else if (X >= 100 && X < 1001) {

            Y = Y2(X);
            E = '2';
        }

        else if (X >= 1800 && X < 2000) {
            Y = Y3(X);
            E = '3';
        }

        else {
            Y = 1.0;
            E = 'N';
        }

        system("cls");

        printf("\nX= %.2lf,\nY%c= %.4lf", X, E, Y);

        printf("\n  Press 'e' to Exit ... or Other key to continue... ");
        char e_char = getch();
        if (e_char == 'e') exit(1);

    }

    return 0;
}

// user's functions definition

// 1
double Y1(double X) {
    return log(powl(X, 2) / 10.0) + 2;
}

// 2
double Y2(double X) {
    return log10(X) + (powl(X, 2) - 4) / (powl(X, 3) + 5);
}

// 3
double Y3(double X) {
    return (-3) * powl(sin(X), 2) + 3;
}
