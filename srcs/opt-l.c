/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt-l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julio <julio@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 01:00:29 by julio             #+#    #+#             */
/*   Updated: 2016/02/12 05:46:07 by julio            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_nblen(int nb)
{
	int i;

	i = 1;
	if (nb > 0)
	{
		while (nb /= 10)
			i++;
	}
	return (i);
}

void	opt_l(t_group *grp, t_dir *file)
{
	t_space	*s_grp = NULL;
	int len_file_uid     = LEN(file->uid);
	int len_file_grpid   = LEN(file->gid);
	int len_file_link    = ft_nblen(file->slink);
	int len_file_size    = ft_nblen(file->size);
	int len_file_size_min = ft_nblen(file->size_min);

	s_grp = define_space(grp);
	ft_putstr(file->rights);
	while (len_file_link++ < s_grp->link_space + 1)
		ft_putchar(' ');
	ft_putnbr(file->slink);
	ft_putchar(' ');
	ft_putstr(file->uid);
	while (len_file_uid++ < s_grp->uid_space + 2)
		ft_putchar(' ');
	ft_putstr(file->gid);
	while (len_file_grpid++ < s_grp->grpid_space)
		ft_putchar(' ');
	while (len_file_size++ < s_grp->size_space)
		ft_putchar(' ');
	len_file_size = ft_nblen(file->size);
	(grp->ismaj_min == false) ? ft_putstr("  ") : ft_putchar(' ');
	if (file->size_min < 0 && grp->ismaj_min)
		while (len_file_size++ < s_grp->size_space + 2)
			ft_putchar(' ');
	ft_putnbr(file->size);
	if (file->size_min >= 0)
	{
		ft_putchar(',');
		while (len_file_size_min++ < s_grp->size_min_space + 1)
			ft_putchar(' ');
		ft_putnbr(file->size_min);
	}
	ft_putstr(file->last_modif);
	ft_putchar(' ');
	ft_memdel((void*)&s_grp);
}