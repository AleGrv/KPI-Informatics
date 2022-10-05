#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main() {
    unsigned int variant, N; // unsigned integer variables declaration
    int v=5, i=0; // counters: variants checker, iterator, variables checker
    double delta, S, X1, X2,  X, Y; // double variables declaration

    //--- variants checker
    do {
        printf("Enter variant (1 or 2): ");
        scanf("%u", &variant);
        v--;

        if (v==0) {
            printf("Variant is not correct! Exit");
            exit(1);
        }
    } while (variant !=1 && variant !=2);

    //---
    printf("Enter start argument (X1): ");
    scanf("%lf", &X1);

    printf("Enter end argument (X2): ");
    scanf("%lf", &X2);

    //--- values amount
    S=fabsf(X2-X1);

    //--- variant 1  (input: N - points amount)
    if (variant==1) {
        printf("Enter points amount (N>1): ");
        scanf("%u", &N); // (N>1)

        delta=S/(N-1); // (delta>0)
    }

    //--- variant 2 (input: delta - argument's step change)
    else {
        printf("Enter Argument's step change (delta>0): ");
        scanf("%lf", &delta);

        N=1+S/delta; // N: points amount calculation (50)
    }

    //--- X
    if (X1<X2)
    X=X1;
    else X=X2;

    //--- X1, X2, N or delta output
    printf(".\n");
    printf("X1=%.8lf,", X1);
    printf(" X2=%.8lf,", X2);
    printf(" N=%.0u,", N);
    printf(" delta=%.8lf\n", delta);

    //--- table header output
    printf("************************************************************\n");
    printf("*  N   *            X            *           F(X)          *\n");
    printf("************************************************************\n");

    //--- table calculation
    for (i; i<N; i++) {

        Y=powl(X, 2)/1000-0.5*X-1000; // 6 variant expression

        printf("+------+-------------------------+-------------------------+\n");
        printf("|%5.0d |%24.8lf |%24.8lf |\n", i+1, X, Y);

        X+=delta; // increase X by delta

        //--- output delay conditions
        if (i>0 && (i+1)==10) {
            printf("+------+-------------------------+-------------------------+\n");
            printf("Press Any Key to Continue...\n");
            getch(); // delay before continue

        }

        else if ((i+1)>10 && (i+1)%10==0) {
            printf("+------+-------------------------+-------------------------+\n");
            getch();

        }

    }
    return 0;
}
