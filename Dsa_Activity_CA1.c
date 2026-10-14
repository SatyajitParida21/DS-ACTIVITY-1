#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 100

double stack[MAX];
int top = -1;

// Push element
int push(double x) {
    if (top == MAX - 1)
        return 0;

    stack[++top] = x;
    return 1;
}

// Pop element
int pop(double *x) {
    if (top == -1)
        return 0;

    *x = stack[top--];
    return 1;
}

int main() {
    char exp[200];
    char *token;
    double a, b, result, num;
    char *end;

    printf("Enter postfix expression (spaces between tokens): ");
    fgets(exp, sizeof(exp), stdin);

    token = strtok(exp, " \t\n");

    while (token != NULL) {
        num = strtod(token, &end);

        // If token is a number
        if (*token != '\0' && *end == '\0') {
            if (!push(num)) {
                printf("Error: Stack overflow\n");
                return 1;
            }
        }

        // If token is an operator
        else if (strlen(token) == 1 &&
                 strchr("+-*/^", token[0]) != NULL) {

            if (top < 1) {
                printf("Error: Insufficient operands\n");
                return 1;
            }

            pop(&b);
            pop(&a);

            switch (token[0]) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0) {
                        printf("Error: Division by zero\n");
                        return 1;
                    }
                    result = a / b;
                    break;

                case '^':
                    result = pow(a, b);
                    break;
            }

            if (!push(result)) {
                printf("Error: Stack overflow\n");
                return 1;
            }
        }

        else {
            printf("Error: Invalid token '%s'\n", token);
            return 1;
        }

        token = strtok(NULL, " \t\n");
    }

    if (top != 0) {
        printf("Error: Invalid expression\n");
        return 1;
    }

    printf("Result = %.6f\n", stack[top]);

    return 0;
}