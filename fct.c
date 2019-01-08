/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fct.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/30 20:29:11 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 18:02:22 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		ft_n_tetri(char *file)
{
	int		fd;
	int		n;
	char	*line;
	int		ret;

	n = 0;
	if (!(fd = open(file, O_RDONLY)))
		return (-1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		free(line);
		n++;
	}
	return (((n + 1) % 5 != 0) ? -1 : (n + 1) / 5);
}

int		ft_sqrt_sup(int nb)
{
	int root;

	while (!(root = ft_sqrt(nb)))
		nb++;
	return (root);
}

char	**ft_rescale(char ***tofree, int scale)
{
	char	**ret;
	int		i;

	i = 0;
	if (*tofree)
	{
		while (tofree[0][i])
		{
			ft_strdel(&(tofree[0][i]));
			i++;
		}
		free(*tofree);
	}
	i = scale;
	if (!(ret = (char **)malloc(sizeof(char *) * (scale + 1))))
		return (NULL);
	ret[scale] = NULL;
	while (--i + 1)
	{
		ret[i] = ft_strnew(scale);
		ft_strfill(ret[i], '.', scale);
	}
	*tofree = ret;
	return (*tofree);
}

void	erase(int index, char **tab)
{
	int i;
	int j;

	j = 0;
	if (!tab)
		return ;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == index + 'A')
				tab[j][i] = '.';
			i++;
		}
		j++;
	}
}
