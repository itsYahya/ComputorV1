#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"
#include "utils.h"
#include "computor.h"
#include "math.h"

int main(int argc, char **argv){
    int			status;
	int			degree = 0;
	double		res[3] = {0, 0, 0};
	t_equation	equation;
	
	status = 42;
	equation.size = 0;
	equation.length = 0;
	equation.components = NULL;
    if (argc == 2)
    {
        status = 0;
        parsString(argv[1], &status, &equation);
		if (status)
		{
			free(equation.components);
			checkStatus(status);	
		}	
	}
	printReducedForm(equation, res, &degree);
	solvePolynomial(res, degree);
	free(equation.components);
    return (0);
}