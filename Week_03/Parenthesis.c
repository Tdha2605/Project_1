#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

int is_correct(char *expression)
{
    char stack[MAX_SIZE];
    int top = -1;

    
    for (int i = 0; i < strlen(expression); i++)
    {
        
        if (   expression[i] == '(' 
            || expression[i] == '[' 
            || expression[i] == '{')
        {
            stack[++top] = expression[i];
        }
        
        else if (  expression[i] == ')' 
                || expression[i] == ']' 
                || expression[i] == '}')
        {
            
            if (top == -1)
                return 0;
            if (  (stack[top] == '(' && expression[i] != ')') 
               || (stack[top] == '[' && expression[i] != ']') 
               || (stack[top] == '{' && expression[i] != '}'))
            {
                return 0;
            }
            top--;
        }
    }

    return top == -1;
}

int main()
{
    char expression[MAX_SIZE];
    scanf("%s", expression);

    if (is_correct(expression))
    {
        printf("1");
    }
    else
    {
        printf("0");
    }

    return 0;
}
