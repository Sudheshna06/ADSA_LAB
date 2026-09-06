#include <stdio.h>
#include <ctype.h>

int precedence(char op)
{
    if (op == '/' || op == '*')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    char stack[100];
    int top = -1;
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        // Operand
        if (isdigit(ch))
        {
            postfix[j++] = ch;
        }

        // Opening parenthesis
        else if (ch == '(')
        {
            stack[++top] = ch;
        }

        // Closing parenthesis
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            top--;   // remove '('
        }

        // Operator
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }

            stack[++top] = ch;
        }

        i++;
    }

    // Pop remaining operators
    while (top != -1)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s", postfix);

    return 0;
}