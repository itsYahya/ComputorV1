#include <stdio.h>
#include "utils.h"

void	solvePolynomialDegreeOf0(double component)
{
	if (component == 0)
		printf("Any real number is a solution.\n");
	else
		printf("No solution.\n\n");
}

void	solvePolynomialDegreeOf1(double *res)
{
	double reslut = 0;

	reslut = -res[0] / res[1];
	printf("The solution is:\n%.6g\n\n", reslut);
}

void	solvePolynomialDegreeOf2(double *res)
{
	double	delta = 0;
	double	deltaSquared = 0;
	double	result = 0;
	double	x0 = 0;
	double	x1 = 0;
	double	x2 = 0;

	x0 = 2 * res[2];
	delta = powerOfTwo(res[1]) - 4 * res[2] * res[0];
	if (delta == 0)
	{
		result = -res[1] / x0;
		printf("Discriminant is null, the only real solutions is\n");
		printf("%.6g\n\n", result);
	}
	else
	{
		deltaSquared = squereRooT(abs_(delta));
		x1 = -res[1] / x0;
		x2 = deltaSquared / x0;

		if (delta > 0)
		{
			printf("Discriminant is strictly positive, the two real solutions are\n");
			printf("%.6g\n", x1 + x2);
			printf("%.6g\n\n", x1 - x2);
			return ;
		}
		printf("Discriminant is strictly negative, the two complex solutions are\n");
		printf("%.6g/%.6g + %.6gi/%.6g\n", -res[1], x0, deltaSquared, x0);
		printf("%.6g/%.6g - %.6gi/%.6g\n\n", -res[1], x0, deltaSquared, x0);
	}
}

int solvePolynomial(double *res, int degree)
{
	if (degree)
		printf("Polynomial degree: %d\n", degree);

	switch (degree)
	{
		case 0:
			solvePolynomialDegreeOf0(res[0]);
			break;
		case 1:
			solvePolynomialDegreeOf1(res);
			break;
		case 2:
			solvePolynomialDegreeOf2(res);
			break;
		default:
			printf("The polynomial degree is strictly greater than 2, I can't solve!\n");
	}
}