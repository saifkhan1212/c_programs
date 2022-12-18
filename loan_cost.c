#include <stdio.h>
#include <math.h>
int main (void) {
    double totalAmount = 0;
    double interestRate = 0;
    double monthlyRate = 0;
    double periodicPayment = 0;
    int numPayments = 0;
    double num1 = 0;
    double totalPaymentWitInterest = 0;
    double differenceWithInterest = 0;
   


    printf ("Please enter the amount of money you borrowed: $");
    scanf ("%lf", & totalAmount);

    printf ("Please enter the annual interest rate: "); 
    scanf ("%lf", & interestRate);
    monthlyRate = interestRate / 12;

//    printf("%.2f", interestRate);

    printf ("Please enter the number of payments to be made: ");
    scanf("%d" , & numPayments);
 
    num1 = 1 + monthlyRate;
    periodicPayment = (totalAmount * monthlyRate)/ (1 - (pow(num1 , -numPayments)));
    
    totalPaymentWitInterest = periodicPayment * numPayments;
    differenceWithInterest =  (totalPaymentWitInterest - totalAmount);
 

    printf ("A loan of $%.2f", totalAmount);
    printf (" with an annual interest of %.2f" , interestRate);
    printf (" paid off over %d", numPayments);
    printf (" months will have monthly payments of $%.2f.\n" , periodicPayment);
    printf ("In total, you will pay $%.2f, making the cost of your loan $%.2f.", totalPaymentWitInterest, differenceWithInterest);
    
    

}