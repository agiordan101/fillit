/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 16:18:53 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 17:34:28 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int		putable(char **tab, int square, t_dot **coord)
{
	int i;

	i = 0;
	while (coord[i])
	{
		if (coord[i]->x >= square || coord[i]->y >= square)
			return (-1);
		if (coord[i]->x < 0 || coord[i]->y < 0 ||
		tab[coord[i]->y][coord[i]->x] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	upleft_tetri(t_tetri *tetri, int square)
{
	int x;
	int y;
	int i;

	while (tetri)
	{
		x = 0;
		y = 0;
		while (!(x == tetri->coord[0]->x && y == tetri->coord[0]->y))
		{
			if (++x > square)
			{
				x = 0;
				y++;
			}
		}
		i = 0;
		while (i < 4)
		{
			tetri->coord[i]->x = tetri->coord[i]->x - x;
			tetri->coord[i]->y = tetri->coord[i]->y - y;
			i++;
		}
		tetri = tetri->next;
	}
}

void	decal(t_tetri *tetri, int square_scale)
{
	int i;
	int j;

	i = -1;
	while (++i < 4)
		tetri->coord[i]->x++;
	i = -1;
	while (++i < 4)
		if (tetri->coord[i]->x == square_scale)
		{
			j = 4;
			while (--j >= 0)
			{
				tetri->coord[j]->x = tetri->coord[j]->x - tetri->coord[0]->x;
				tetri->coord[j]->y++;
			}
		}
}

int		solve(t_tetri *tetri, int square_scale, char **solut, int replace)
{
	int test;
	int i;

	i = -1;
	if (!replace)
		upleft_tetri(tetri, square_scale);
	else
	{
		erase(tetri->index, solut);
		decal(tetri, square_scale);
	}
	while (!(test = putable(solut, square_scale, tetri->coord)) && test != -1)
		decal(tetri, square_scale);
	if (test == -1)
		return (0);
	while (++i < 4)
		solut[tetri->coord[i]->y][tetri->coord[i]->x] = tetri->index + 'A';
	if (!tetri->next)
		return (1);
	if (solve(tetri->next, square_scale, solut, 0))
		return (1);
	return (solve(tetri, square_scale, solut, 1));
}

char	**fillit(t_tetri *tetri)
{
	int		square;
	char	**solut;
	int		i;

	square = ft_sqrt_sup(4 * ft_nbr_tetri(tetri));
	solut = NULL;
	while (!(solve(tetri, square, ft_rescale(&solut, square), 0)))
		square++;
	i = -1;
	while (solut[++i])
		ft_putendl(solut[i]);
	ft_delete_list(&tetri, &solut);
	return (solut);
}
