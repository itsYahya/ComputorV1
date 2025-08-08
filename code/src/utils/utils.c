#include <stdio.h>
#include <stdlib.h>

void    checkStatus(int status)
{
    if (status == 42)
    {
        printf("computor: error.\n");
        printf("computor: use: ./computor \"5 + 4 * X + X^2= X^2\"\n");
    }
    else if (status == 1)
    {
        printf("computor: Incorrect form of equation detected.\n");
        printf("computor: use: ./computor \"5 + 4 * X + X^2= X^2\"\n");      
    }
    else if (status == 2)
    {
        printf("computor: This version lacks support for numbers larger than integers.\n");
        printf("computor: number: Ensure the value remains within integer bounds. :) %d \n");
    }
    exit(status); 
}

int lookUpForStar(char *str, int *start)
{
    int i = 0;

    while (str && str[i])
    {
        if (str[i] == '*')
        {
            *start = i + 1;
            str[i] = 0;
        }
        i++;
    }
}

int isNumber(char *str)
{
    int i = 0;

    while (str && str[i])
    {
        if (str[i] < 48 || str[i] > 57){
            return (0);
        }
        i++;
    }
    return (1);
}

int isFloat(char *str)
{
    int in_fraction = 0;
    int index = 0;

    while (str && str[index])
    {
        if ((str[index] < '0' || str[index] > '9') && str[index] != '.'){
            return (0);
        }
        else if (str[index] == '.' && !in_fraction)
            in_fraction = 0;
        else if (str[index] == '.' && in_fraction)
            return (0);
        index++;
    }

    if (index && str[index - 1] == '.')
        return (0);
    return(1);
}