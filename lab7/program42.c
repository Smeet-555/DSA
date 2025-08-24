#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Stack {
    int data[100];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

void push(struct Stack* stack, int value) {
    if (stack->top < 99) {
        stack->data[++stack->top] = value;
    }
}

int pop(struct Stack* stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    }
    return -1;
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '%');
}

int performOperation(int a, int b, char operator) {
    switch (operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0) {
                return a / b;
            } else {
                printf("Error: Division by zero!\n");
                return 0;
            }
        case '%':
            if (b != 0) {
                return a % b;
            } else {
                printf("Error: Modulo by zero!\n");
                return 0;
            }
        case '^':
            return (int)pow(a, b);
        default:
            printf("Error: Unknown operator %c\n", operator);
            return 0;
    }
}

int evaluatePostfix(char* expression) {
    struct Stack stack;
    initStack(&stack);
    
    int len = strlen(expression);
    
    for (int i = 0; i < len; i++) {
        char token = expression[i];
        
        if (token == ' ') {
            continue;
        }
        
        if (isdigit(token)) {
            push(&stack, token - '0');
        }
        else if (isOperator(token)) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            
            if (operand1 == -1 || operand2 == -1) {
                printf("Error: Invalid expression (insufficient operands)\n");
                return 0;
            }
            
            int result = performOperation(operand1, operand2, token);
            push(&stack, result);
        }
        else {
            printf("Error: Invalid character '%c' in expression\n", token);
            return 0;
        }
    }
    
    int result = pop(&stack);
    
    if (stack.top != -1) {
        printf("Error: Invalid expression (too many operands)\n");
        return 0;
    }
    
    return result;
}

void displayEvaluation(char* expression) {
    printf("Evaluation Process:\n");
    printf("Expression: %s\n\n", expression);
    
    struct Stack stack;
    initStack(&stack);
    
    int len = strlen(expression);
    int step = 1;
    
    for (int i = 0; i < len; i++) {
        char token = expression[i];
        
        if (token == ' ') {
            continue;
        }
        
        if (isdigit(token)) {
            push(&stack, token - '0');
            printf("Step %d: Push %c\n", step++, token);
        }
        else if (isOperator(token)) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            
            if (operand1 == -1 || operand2 == -1) {
                printf("Error: Invalid expression\n");
                return;
            }
            
            int result = performOperation(operand1, operand2, token);
            push(&stack, result);
            
            printf("Step %d: Pop %d, Pop %d, %d %c %d = %d, Push %d\n", 
                   step++, operand2, operand1, operand1, token, operand2, result, result);
        }
        
        // Display current stack
        printf("Stack: ");
        for (int j = 0; j <= stack.top; j++) {
            printf("%d ", stack.data[j]);
        }
        printf("\n\n");
    }
    
    int finalResult = pop(&stack);
    printf("Final Result: %d\n", finalResult);
}

int main() {
    char expression[100];
    
    printf("=== Expression Evaluation using Stack ===\n\n");
    printf("Enter postfix expression (use single digits 0-9): ");
    
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = 0;
    
    printf("\n");
    
    displayEvaluation(expression);
    
    int result = evaluatePostfix(expression);
    printf("\nResult: %d\n", result);
    
    return 0;
}