#include "../includes/push_swap.h"
/* DEBUG */
#include <stdio.h>
/*********/

/**********DEBUG********************/
void	display_stack(t_stack *stack)
{
	int i = 0;
	printf("pile a :\n");
	while (i < stack->size_a)
	{
		printf("i : %d -> %d\n", i, stack->a[i]);
		i++;
	}
	printf("pile b :\n");
	i = 0;
	while (i < stack->size_b)
	{
		printf("i : %d -> %d\n", i, stack->b[i]);
		i++;
	}
}
/**********DEBUG********************/