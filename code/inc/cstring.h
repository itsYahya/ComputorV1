#ifndef CSTRING_H
# define CSTRING_H

int     isSeparator(char ch);
char    *trim(char *str);
int     flipSign(int *sign, int *status);
long    atoi_(char *str, int *status, int sign);
double  atof_(char *str, int *status, int sign);

#endif