#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}int main() {
    char postfix[MAX];
    int i = 0;
    int op1, op2, result;

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');  
        }        else {
            op2 = pop();
            op1 = pop();

            switch (postfix[i]) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
                default:
                    printf("Invalid Operator\n");
                    return 0;
            }

            push(result);
        }

        i++;
    }

    printf("Result = %d\n", pop());

    return 0;
}
