/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_list.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 16:11:57 by agiordan     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/13 18:52:06 by agiordan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete_tabs(t_tetri **tetri)
{
	t_tetri *tmp;
	int		i;

	i = -1;
	if ((*tetri)->tetri)
	{
		while ((*tetri)->tetri[++i])
			ft_strdel((*tetri)->tetri + i);
		free((*tetri)->tetri);
	}
	i = -1;
	if ((*tetri)->coord)
	{
		while ((*tetri)->coord[++i])
			free((*tetri)->coord[i]);
		free((*tetri)->coord);
	}
	tmp = (*tetri)->next;
	free(*tetri);
	*tetri = tmp;
}

void	ft_delete_list(t_tetri **tetri, char ***solut)
{
	int i;

	i = 0;
	if (solut)
	{
		while (solut[0][i])
		{
			ft_strdel(&(solut[0][i]));
			i++;
		}
		free(*solut);
	}
	while (*tetri)
		ft_delete_tabs(tetri);
}

t_tetri	*ft_new_tetri(int index)
{
	t_tetri *new;
	int		i;

	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	if (!(new->tetri = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	i = 0;
	while (i < 5)
		new->tetri[i++] = NULL;
	new->coord = NULL;
	new->index = index;
	new->next = NULL;
	return (new);
}

size_t	ft_nbr_tetri(t_tetri *first_tetri)
{
	size_t count;

	if (!first_tetri)
		return (0);
	count = 1;
	while (first_tetri->next)
	{
		first_tetri = first_tetri->next;
		count++;
	}
	return (count);
}

void	ft_add_tetri(t_tetri **alst, t_tetri *new)
{
	while ((*alst)->next)
		*alst = (*alst)->next;
	(*alst)->next = new;
	new->next = NULL;
}
