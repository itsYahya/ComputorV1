double  powerOfTwo(double number)
{
    return (number * number);
}

double	abs_(double number)
{
	if (number < 0)
		return (-number);
	return (number);
}

double	squereRooT(double number)
{
    double	x1 = number;
	double	x2 = 0;
	double	presision = 1e-7;
	int		eterations = 1000;
	int		index = 0;

	while (index < eterations)
	{
		x2 = (x1 + number / x1) / 2;
		if (abs_(x2 - x1) < presision)
			break;
		x1 = x2;
		index++;
	}
	return x2;
}