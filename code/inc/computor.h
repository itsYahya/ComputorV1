#ifndef COMPUTOR_H
# define COMPUTOR_H

typedef struct s_component
{
    int     power;
    double  coefficient;
}   t_component;

typedef struct s_equation
{
	t_component	*components;
	int			size;
	int			length;
}	t_equation;

int	addNewComponent(t_component component, t_equation *equation, int *status);
int	reAllocate(t_equation *equation, int *status);
int	printReducedForm(t_equation equation, double *res, int *degree);

#endif