#include <stdio.h>
int main (void) {
    char gradeWant;
    double percentForGrade = 0;
    double currentPercent = 0;
    double finalWeight = 0;
    double finalGrade = 0;

printf ("Enter the grade you want in the class: ");
scanf ("%c", & gradeWant);

printf("Enter the percent you need to get that grade: ");
scanf ("%lf", & percentForGrade);

printf ("Enter your current percent in the class: ");
scanf ("%lf", & currentPercent);

printf("Enter the weight of the final: ");
scanf ("%lf", & finalWeight);

finalGrade = ((100 * percentForGrade - currentPercent * (100 - finalWeight))/finalWeight);

printf("You need to get at least %.2lf%% on the final to get a %c in the class.", finalGrade, gradeWant);

}