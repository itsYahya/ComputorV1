
#include <string.h>
#include <float.h>

int isSeparator(char ch)
{
    if (ch == '+')
        return (1);
    if (ch == '-')
        return (-1);
    if (ch == '=')
        return (42);
    if (ch == '\0')
        return (2);
    return (0);
}

char    *trim(char *str)
{
    int	index = 0;

    if (!str)
        return (str);
    while (str[index] == ' ')
        index++;

    str = str + index;
    index = strlen(str) - 1;
    while (str[index] == ' ')
        index --;

    str[index + 1] = 0;
    return (str);
}

int flipSign(int *sign, int *status)
{
    *status = (*sign == -1);
    *sign = -1;
    return (*status);
}

long atoi_(char *str, int *status, int sign)
{
    int	res = 0;
	int	i = 0;

    if (strcmp("2147483648", str) == 0 && sign == -1){
        return ((long)2147483648);
    }
    
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + (str[i] - '0');
        if (res < 0)
            break;
        i++;
    }

    if (str[i])
        *status = 2;
    return ((long)res);
}

double atof_(char *str, int *status, int sign)
{
    int		in_fraction = 0;
    int		index = 0;
    int		result = 0;
    double	fraction = 0.0f;
    double	divisor = 10.0f;

    while (str[index]) {
        if (str[index] >= '0' && str[index] <= '9') {
            if (!in_fraction && index > 8 && result > 9999999)
            {
                *status = 2;
                break;
            }
            if (!in_fraction) {
                result = result * 10 + (str[index] - '0');
            } else if (in_fraction < 7){
                fraction += (str[index] - '0') / divisor;
                divisor *= 10.0f;
                in_fraction++;
            }
            else
                break;
        } else if (str[index] == '.' && !in_fraction) {
            in_fraction = 1;
        } else {
            break;
        }
        index++;
    }
    fraction = (double)result + fraction;
    return (fraction);
}
