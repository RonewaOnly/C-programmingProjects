#include <stdio.h>
#include <stdlib.h>

// Main  function to run the program
int main()
{
    char ch;
    double a, b;
    while (1)
    {
        printf("Enter an operator (+,-,*,/), "
                "if want to exit press x: \n");
        scanf("%c", &ch);

        // To Exit
        if (ch == 'x')
            exit(0);
        printf("\nEnter two first and second operand: ");
        scanf("%lf %lf", &a, &b);

        // Using switch case we will differentiate
        // operations based on different operator
        switch (ch)
        {

        // For Addition
        case '+':
            printf("%.1lf + %.1lf = %.1lf\n", a, b, a + b);
            break;

        // For Subtraction
        case '-':
            printf("%.1lf - %.1lf = %.1lf\n", a, b, a - b);
            break;

        // For Multiplication
        case '*':
            printf("%.1lf * %.1lf = %.1lf\n", a, b, a * b);
            break;

        // For Division
        case '/':
            printf("%.1lf / %.1lf = %.1lf\n", a, b, a / b);
            break;

        // If operator doesn't match any case constant
        default:
            printf(
                "Error! please write a valid operator\n");
        }

        printf("\n");
    }
}