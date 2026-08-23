#include <stdio.h>
#include <ctype.h>

#define MAX 200

int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

int applyOperator(long long value[], int *top, char op)
{
    long long a, b;

    if (*top < 1)
    {
        printf("Error: Invalid expression.\n");
        return 0;
    }

    b = value[(*top)--];
    a = value[(*top)--];

    if (op == '+')
        value[++(*top)] = a + b;
    else if (op == '-')
        value[++(*top)] = a - b;
    else if (op == '*')
        value[++(*top)] = a * b;
    else if (op == '/')
    {
        if (b == 0)
        {
            printf("Error: Division by zero is not allowed.\n");
            return 0;
        }

        value[++(*top)] = a / b;
    }

    return 1;
}

int main(void)
{
    char expression[MAX];
    char operators[MAX];
    long long values[MAX];
    int i = 0;
    int topValue = -1;
    int topOperator = -1;
    int expectingNumber = 1;

    printf("Enter expression: ");

    if (fgets(expression, MAX, stdin) == NULL)
    {
        printf("Error: Cannot read input.\n");
        return 1;
    }

    while (expression[i] != '\0' && expression[i] != '\n')
    {
        char ch = expression[i];

        if (isspace((unsigned char)ch))
        {
            i++;
            continue;
        }

        if (isdigit((unsigned char)ch))
        {
            long long number = 0;

            if (!expectingNumber)
            {
                printf("Error: Missing operator.\n");
                return 1;
            }

            while (isdigit((unsigned char)expression[i]))
            {
                number = number * 10 + (expression[i] - '0');
                i++;
            }

            values[++topValue] = number;
            expectingNumber = 0;
            continue;
        }

        if (ch == '(')
        {
            operators[++topOperator] = ch;
        }
        else if (ch == ')')
        {
            while (topOperator != -1 && operators[topOperator] != '(')
            {
                if (!applyOperator(values, &topValue,
                                   operators[topOperator--]))
                    return 1;
            }

            if (topOperator == -1)
            {
                printf("Error: Parentheses are not balanced.\n");
                return 1;
            }

            topOperator--;
            expectingNumber = 0;
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (expectingNumber)
            {
                printf("Error: Invalid operator position.\n");
                return 1;
            }

            while (topOperator != -1 &&
                   operators[topOperator] != '(' &&
                   precedence(operators[topOperator]) >= precedence(ch))
            {
                if (!applyOperator(values, &topValue,
                                   operators[topOperator--]))
                    return 1;
            }

            operators[++topOperator] = ch;
            expectingNumber = 1;
        }
        else
        {
            printf("Error: Invalid character.\n");
            return 1;
        }

        i++;
    }

    if (expectingNumber)
    {
        printf("Error: Expression is incomplete.\n");
        return 1;
    }

    while (topOperator != -1)
    {
        if (operators[topOperator] == '(')
        {
            printf("Error: Parentheses are not balanced.\n");
            return 1;
        }

        if (!applyOperator(values, &topValue, operators[topOperator--]))
            return 1;
    }

    printf("Value = %lld\n", values[0]);

    return 0;
}