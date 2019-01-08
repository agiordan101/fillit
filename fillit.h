/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mwaterso <mwaterso@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 16:16:37 by mwaterso     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 17:20:17 by mwaterso    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct		s_dot
{
	int				x;
	int				y;
}					t_dot;

typedef	struct		s_tetri
{
	char			**tetri;
	t_dot			**coord;
	int				index;
	struct s_tetri	*next;

}					t_tetri;

typedef struct		s_inputs
{
	char			*file;
	char			*line;
	t_tetri			*tmp;
	int				fd;
	int				ret;
	int				n_tetri;
}					t_inputs;

int					parse(t_tetri **begin, t_inputs **inputs);
t_tetri				*ft_new_tetri(int index);
size_t				ft_nbr_tetri(t_tetri *first_tetri);
void				ft_add_tetri(t_tetri **alst, t_tetri *newtetri);
void				upleft_tetri(t_tetri *tetri, int square);
int					ft_n_tetri(char *file);
char				**fillit(t_tetri *tetris);
int					ft_sqrt_sup(int nb);
void				ft_delete_list(t_tetri **tetri, char ***solut);
void				erase(int index, char **tab);
char				**ft_rescale(char ***tofree, int scale);

#endif
