/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/10 17:12:00 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 18:58:20 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	t_inputs	*inputs;
	t_tetri		*begin;
	int			ret;

	if (ac == 2)
	{
		inputs = (t_inputs *)malloc(sizeof(t_inputs));
		inputs->file = av[1];
		inputs->line = NULL;
		begin = NULL;
		ret = parse(&begin, &inputs);
		if (inputs->line)
			ft_strdel(&inputs->line);
		if (!ret)
			fillit(begin);
		else
		{
			ft_putstr("error\n");
			ft_delete_list(&begin, NULL);
		}
		free(inputs);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
