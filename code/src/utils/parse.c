#include <stdio.h>
#include <string.h>
#include "computor.h"
#include "cstring.h"
#include "utils.h"

int isAVariable(char *str)
{
    if (!str)
        return (0);

    if (str[0] != 'X')
        return (0);
    else if (str[1] && str[1] != '^')
        return (0);
    else if (str[1] && str[2] && !isNumber(str + 2))
        return (0);
    return (1);
}

int lookUpForX(char *str, int *status, int *power)
{
    if (isNumber(str))
        return (0);
    
    if (str[0] == 'X')
    {
        if (str[1] == 0)
            *power = 1;
        else if (str[1] != '^')
        {
            *status = 1;
            return (0);
        }
        else if (isNumber(str + 2))
            *power = atof_(str + 2, status, 1);
    }
    return (1);
}

t_component calculateComponent(char *str1, char *str2, int sign, int *status)
{
    t_component tmp;
    double       numb;

    tmp.coefficient = 1;
    tmp.power = 0;
    if ((!isFloat(str1) && !isAVariable(str1)) || (str2 && !isFloat(str2) && !isAVariable(str2)))
    {
        *status = 1;
        return (tmp);
    }
    if (isFloat(str1))
    {
        numb = atof_(str1, status, sign);
        if (*status)
            return (tmp);
        tmp.coefficient = numb;
    }
    if (str2 && isFloat(str2))
    {
        numb = atof_(str2, status, sign);
        if (*status)
            return (tmp);
        tmp.coefficient = tmp.coefficient * numb;
    }
    lookUpForX(str1, status, &tmp.power);
    if (str2)
        lookUpForX(str2, status, &tmp.power);
    tmp.coefficient = tmp.coefficient * sign;
    return (tmp);
}


int	partialParse(char *str, int *status, int side, int sign, t_equation *equation)
{
	int			start = 0, i = 0;
	char		*str1, *str2;
	long		numb = 0;
	t_component cmpnt;
		
	if (str[0] == '\0')
		return (0);
	sign = side * sign;
	lookUpForStar(str, &start);
	str1 = trim(str);
	str2 = start ? trim(str + start) : NULL;
	cmpnt = calculateComponent(trim(str1), trim(str2), sign, status);
	addNewComponent(cmpnt, equation, status);
}

int parsString(char *str, int *status, t_equation *equation)
{
    int     i, start = 0, sign = 10, nextSign, side = 1, len = 0;

    i = 0;
    len = strlen(str);
    while (i <= len && *status == 0)
    {
        nextSign = isSeparator(str[i]);
        if (nextSign)
        {
            str[i] = 0;
            char *tmp = trim(str + start);
            if ((nextSign == 42 && strlen(tmp) == 0) || (nextSign != 42 && sign != 42 && sign != 10 && strlen(tmp) == 0))
                *status = 1;
            else if (sign == 42)
                flipSign(&side, status);
            sign = sign / ((sign == 42 || sign == 10) ? sign : 1);
            partialParse(tmp, status, side, sign, equation);
            start = i + 1;
            sign = nextSign;
        }
        i++;
    }
    if (side == 1 && *status == 0)
        *status = 1;
}