/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 16:17:24 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 17:54:19 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

t_dot	**ft_save_coord(char **tetri)
{
	t_dot	**tab;
	int		i;
	int		j;
	int		n;

	if (!(tab = (t_dot **)malloc(sizeof(t_dot *) * 5)))
		return (NULL);
	tab[4] = NULL;
	n = 0;
	i = 0;
	while (i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetri[i][j] == '#')
			{
				if (!(tab[n] = (t_dot *)malloc(sizeof(t_dot))) || n > 3)
					return (NULL);
				tab[n]->x = j;
				tab[n]->y = i;
				n++;
			}
		i++;
	}
	return ((n == 4) ? tab : NULL);
}

void	check_voisins(t_dot **tab, int i, int j, int **n)
{
	if (i != j)
	{
		if ((tab[i]->y == tab[j]->y) && ((tab[i]->x == tab[j]->x - 1) ||
		(tab[i]->x == tab[j]->x + 1)))
			n[0][i]++;
		if ((tab[i]->x == tab[j]->x) && ((tab[i]->y == tab[j]->y - 1) ||
		(tab[i]->y == tab[j]->y + 1)))
			n[0][i]++;
	}
}

int		check_error(t_inputs *inputs)
{
	int		i;
	int		j;
	int		*n;
	int		coeur;

	if (!(inputs->tmp->coord = ft_save_coord(inputs->tmp->tetri)))
		return (1);
	if (!(n = (int *)malloc(sizeof(int) * 4)))
		return (1);
	coeur = 0;
	i = 0;
	while (i < 4)
	{
		n[i] = 0;
		j = -1;
		while (++j < 4)
			check_voisins(inputs->tmp->coord, i, j, &n);
		if (!n[i])
			return (1);
		if (n[i] > 1)
			coeur = 1;
		i++;
	}
	free(n);
	return (!coeur ? 1 : 0);
}

int		read_tetri(t_inputs *inputs)
{
	int		nline;
	int		i;

	nline = 0;
	while ((inputs->ret = get_next_line(inputs->fd, &(inputs->line))) > 0
	&& nline < 4)
	{
		if (ft_strlen(inputs->line) != 4 || inputs->ret == -1)
			return (-1);
		i = -1;
		while (inputs->line[++i])
			if (inputs->line[i] != '.' && inputs->line[i] != '#')
				return (-1);
		inputs->tmp->tetri[nline] = ft_strdup(inputs->line);
		ft_strdel(&inputs->line);
		nline++;
	}
	ft_strdel(&inputs->line);
	if (check_error(inputs))
		return (-1);
	return (1);
}

int		parse(t_tetri **begin, t_inputs **inputs)
{
	int	i;

	if (((*inputs)->fd = open((*inputs)->file, O_RDONLY)) == -1 ||
	ft_n_tetri((*inputs)->file) > 26 ||
	((*inputs)->n_tetri = ft_n_tetri((*inputs)->file)) == -1)
		return (1);
	*begin = ft_new_tetri(0);
	(*inputs)->tmp = *begin;
	if (read_tetri(*inputs) == -1)
		return (1);
	i = 1;
	while (i < (*inputs)->n_tetri)
	{
		(*inputs)->tmp->next = ft_new_tetri(i);
		(*inputs)->tmp = (*inputs)->tmp->next;
		if (read_tetri(*inputs) == -1)
			return (1);
		i++;
	}
	(*inputs)->tmp->next = NULL;
	return (0);
}
