#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

void welcome(void);

void ask(double *a, double *b);

void welcome()
{
    printf("--------------\n");
    printf("| Calculator |\n");
    printf("--------------\n");
}

void ask(double *a, double *b)
{
    char buffer[128];
    
    printf("Provide a real number A: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", a);

    printf("Provide a real number B: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", b);
}

int main()
{
    
    welcome();
    
    double a, b, result;
    char operator[10] = "";
    char status[5] = "";
    
    printf("Do you want to use the calculator? (Yes or No) ");
    fgets(status, sizeof(status), stdin);
    status[strlen(status) - 1] = '\0';
    
    while (strcmp(status, "Yes") == 0 || strcmp(status, "yes") == 0)
    {    
        printf("\nSelect a valid operation (plus, minus, mul, div, true div, modulo): ");
        fgets(operator, sizeof(operator), stdin);
        operator[strlen(operator) - 1] = '\0';

        if (strcmp(operator, "plus") == 0)
        {
            ask(&a, &b);
            result = a + b;
            
            printf("A (%.3lf) + B (%.3lf) = %.3lf.\n\n", a, b, result);
        }

        else if (strcmp(operator, "minus") == 0)
        {
            ask(&a, &b);
            result = a - b;
            
            printf("A (%.3lf) - B (%.3lf) = %.3lf.\n\n", a, b, result);
        }

        else if (strcmp(operator, "mul") == 0)
        {
            ask(&a, &b);
            result = a * b;
            
            printf("A (%.3lf) * B (%.3lf) = %.3lf.\n\n", a, b, result);
        }

        else if (strcmp(operator, "div") == 0)
        {
            ask(&a, &b);

            if (b == 0)
            {
                printf("Error: Division by zero is not allowed.\n\n");
                return -1;
            }
            else
            {
                result = (int)a / (int)b;
                printf("A (%.3lf) // B (%.3lf) = %.3lf.\n\n", a, b, result);
            }
        }

        else if (strcmp(operator, "true div") == 0)
        {
            ask(&a, &b);

            if (b == 0)
            {
                printf("Error: Division by zero is not allowed.\n");
                return -1;
            }
            else
            {
                result = a / b;
                printf("A (%.3lf) / B (%.3lf) = %.3lf.\n\n", a, b, result);
            }
        }

        else if (strcmp(operator, "modulo") == 0)
        {
            ask(&a, &b);

            if (b == 0)
            {
                printf("Error: Modulo by zero is not allowed.\n\n");
                return -1;
            }
            else
            {
                result = fmod(a, b);
                printf("A (%.3lf) %% B (%.3lf) = %.3lf.\n\n", a, b, result);
            }
        }

        else
        {
            printf("You provided the wrong operator!\n\n");
            return -1;
        }
        
        printf("Do you want to use the calculator? (Yes or No) ");
        fgets(status, sizeof(status), stdin);
        status[strlen(status) - 1] = '\0';
    }
    
    return 0;
}