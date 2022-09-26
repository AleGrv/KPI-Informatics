#include <stdio.h> // pidkliuchennia bibliotek
#include <stdlib.h> // pidkliuchennia bibliotek
#define Name "Olexandra"
#define LastName "Grov"
#define GroupName "RE-22"
#define Faculty "RTF"
#define University "Igor Sikorsky Kyiv Polytechnic Institute"
int main() { // holovna funktsiia

unsigned int semestr; // zminna dlia zberezhennia bezznakovoho tsiloho znachennia(nomer semestru)
float admissionScore; // zminna dlia zberezhennia chyslo z plavaiuchoiu krapkoiu (vstupnoho balu)
int grade1; // zminna dlia zberezhennia tsiloho znachennia (otsinka po predmetu #1)
int grade2; // zminna dlia zberezhennia tsiloho znachennia (otsinka po predmetu #2)
int grade3; // zminna dlia zberezhennia tsiloho znachennia (otsinka po predmetu #3)
double averageGrade; // zminna, zberezhennia serednoho znachennia otsinky
unsigned int age; // oholoshennia zminnoi
printf("%s %s Enter following data.\n", Name, LastName); // vyvedennia informatsii do potoku vyvodu
printf("Enter semestr:");
scanf("%u", &semestr); // vvodytsia bezznakove tsile znachennia
printf("Enter your admission score: ");
scanf("%f", &admissionScore); // vvodytsia chyslo z plavaiuchoiu krapkoiu
printf("Enter grade #1: ");
scanf("%d", &grade1); // vvodytsia tsile znachennia
printf("Enter grade #2:");
scanf("%d", &grade2); // vvodytsia tsile znachennia
printf("Enter grade #3:");
scanf("%d", &grade3); // vvodytsia tsile znachennia
printf("Enter your age: ");
scanf("%u", &age); // vvodytsia bezznakove tsile znachennia
averageGrade = (double)(grade1 + grade2 + grade3) / 3; // pidrakhunok serednoho balu
system("cls"); // ochyshchennia komandnoho vikna vid tekstu
printf("%s", University); // vvedennia/vyvedennia symvolnoho riadka (nazva Universytetu)
printf("\n%s", Faculty); // vvedennia/vyvedennia symvolnoho riadka (nazva Fakultetu)
printf("\n%s", GroupName); // vvedennia/vyvedennia symvolnoho riadka (nazva Hrupy)
printf("\n***************"); // viddilennia riznykh blokiv danykh
printf("\nstudent: %s %s", Name, LastName ); // vyvedennia symvolnoho riadku (Imia, Prizvyshche)
printf("\nage: %u", age); // vyvedennia symvolnoho riadku (vik)
printf("\nsemestr: %u", semestr); // vyvedennia symvolnoho riadku (semestr)
printf("\n==============="); // viddilennia riznykh blokiv danykh
printf("\nadmission score: %.1f", admissionScore); // vyvedennia znachennia serednoi otsinky iz odnym znakamy pislia komy
printf("\naverage grade = %.2lf", averageGrade); // vyvedennia znachennia serednoi otsinky iz dvoma znakamy pislia komy
printf("\n"); // perekhid na novyi riadok
return 0; // zavershennia roboty funktsii

}
