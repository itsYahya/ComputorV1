#include "computor.h"
#include <stdlib.h>
#include <stdio.h>

int	reAllocate(t_equation *equation, int *status)
{
	int			newSize;
	int			index;
	t_component	*tmp;

	newSize = equation->size ? equation->size * 2 : 2;
	tmp = malloc(sizeof(t_component) * newSize);
	if (!tmp)
	{
		*status = 4;
		return (1);
	}
	index = 0;
	while (index < equation->length)
	{
		tmp[index] = equation->components[index];
		index++;
	}
	free(equation->components);
	equation->components = tmp;
	equation->size = newSize;
	return (0);
}

int appendCompoent(t_equation *equation, t_component component)
{
	int 		index = 0;
	t_component	tmp;
	
	while (index < equation->length)
	{
		if (equation->components[index].power == component.power)
		{
			equation->components[index].coefficient += component.coefficient;
			return (0);
		}
		index++;
	}
	return (1);
}

int	sortedAdd(t_equation *equation, t_component component, int *status)
{
	int			index;
	int			j;
	int			len;
	t_component	*tmp;

	len = 0;
	if (!equation->length)
	{
		len = equation->length;
		equation->components[len] = component;
		equation->length += 1;
		return (0);
	}

	tmp = malloc(sizeof(t_component) * equation->size);
	if (!tmp)
	{
		*status = 1;
		return (4);
	}

	index = 0;
	j = 0;
	len = equation->length;
	while (index < equation->length)
	{
		if (component.power < equation->components[index].power && index == j) {
			len = index;
			j++;
		}
		else {
			tmp[j] = equation->components[index];
			index++;
			j++;
		}
	}
	tmp[len] = component;
	free(equation->components);
	equation->components = tmp;
	equation->length += 1;
	return (0);
}

int	addNewComponent(t_component component, t_equation *equation, int *status)
{
	int	len;

	if (appendCompoent(equation, component))
	{
		if (equation->length == equation->size)
			reAllocate(equation, status);

		if (*status)
			return (1);
		sortedAdd(equation, component, status);
	}
	return (0);
}

int	printReducedForm(t_equation equation, double *res, int *degree)
{
	int	index = 0;

	while (index < equation.length)
	{
		if (!index)
			printf("Reduced form: ");
		t_component component = equation.components[index];
		printf("%s%.6g * X^%d ", component.coefficient > 0 ? "+" : "", component.coefficient, component.power);
		if (component.power < 3)
			res[component.power] = component.coefficient;
		index++;
		if (component.coefficient)
			*degree = component.power;
	}
	if (index)
		printf("= 0\n");
}
