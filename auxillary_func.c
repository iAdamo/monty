#include "monty.h"

int num_atoi(char *str)
{
	int i = 0;
	unsigned int num;

	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	num = atoi(str);
	return (num);	
}
