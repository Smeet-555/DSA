#include <stdio.h>

char postfix[100];

int stringLength(const char* str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringConcat(char* dest, const char* src) {
    int destLen = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

int findChar(const char* str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            return i;
        }
        i++;
    }
    return -1;
}

void removeNewline(char* str) {
    int len = stringLength(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

int push(char stack[], int top, int size, char x)
{
    if (top >= size - 1) {
        printf("Stack Overflow!\n");
        return top;
    }
    stack[++top] = x;
    return top;
}

int pop(char stack[], int top)
{
    if (top < 0) {
        printf("Stack Underflow!\n");
        return top;
    }
    return top - 1;
}

int inputPrecedence(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/' || c == '%')
        return 3;
    if (c == '^')
        return 6;
    if (c == '(')
        return 9;
    if (c == ')')
        return 0;
    return -1;
}

int append(char c, int v)
{
    if (v < 99) {
        postfix[v++] = c;
    }
    return v;
}

void displayPostfix(int v)
{
    printf("Postfix expression: ");
    for (int i = 0; i < v; i++)
    {
        if (postfix[i] != '(')
        {
            printf("%c", postfix[i]);
        }
    }
    printf("\n");
}

int main()
{
    int size = 100, top = -1, v = 0;
    char stack[size];
    char inputString[100];

    printf("Enter infix expression: ");
    fgets(inputString, sizeof(inputString), stdin);
    
    removeNewline(inputString);
    
    printf("Infix expression: %s\n", inputString);

    stringConcat(inputString, ")");
    top = push(stack, top, size, '(');

    for (int i = 0; inputString[i] != '\0'; i++)
    {
        char token = inputString[i];
        
        if (token == ' ') {
            continue;
        }

        if (token == '+' || token == '-' || token == '*' || token == '/' || token == '%')
        {
            while (top >= 0 && inputPrecedence(stack[top]) >= inputPrecedence(token) && stack[top] != '(')
            {
                v = append(stack[top], v);
                top = pop(stack, top);
            }
            top = push(stack, top, size, token);
        }
        else if (token == '^')
        {
            while (top >= 0 && inputPrecedence(stack[top]) > inputPrecedence(token) && stack[top] != '(')
            {
                v = append(stack[top], v);
                top = pop(stack, top);
            }
            top = push(stack, top, size, token);
        }
        else if (token == '(')
        {
            top = push(stack, top, size, token);
        }
        else if (token == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                v = append(stack[top], v);
                top = pop(stack, top);
            }
            if (top >= 0 && stack[top] == '(') {
                top = pop(stack, top); 
            }
        }
        else if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z') || (token >= '0' && token <= '9'))
        {
            v = append(token, v);
        }
    }

    displayPostfix(v);

    return 0;
}