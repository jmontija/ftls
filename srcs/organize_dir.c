/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 05:20:26 by jmontija          #+#    #+#             */
/*   Updated: 2016/02/10 05:20:28 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

// penser a implementer !

void	delete_dir(t_dir *trash)
{
	t_dir *tmp = NULL;

	while (trash != NULL)
	{
		//printf("deleting -> %s\n", trash->name);
		REMOVE(&trash->name);
		REMOVE(&trash->rights);
		REMOVE(&trash->last_stat);
		REMOVE(&trash->last_access);
		REMOVE(&trash->last_modif);
		REMOVE(&trash->uid);
		REMOVE(&trash->gid);
		trash->slink = 0;
		trash->size = 0;
		trash->blocks = 0;
		trash->size_min = -1;
		tmp = trash;
		trash = trash->next;
		ft_memdel((void *)tmp);
	}
	//grp->dir_organize = NULL;
	//grp->curr_dir = NULL;
}

t_dir	*init_dir(char *name)
{
	t_dir *new;
	//printf("initing -> %s\n", name);
	new = (t_dir *)malloc(sizeof(t_dir));
	if (!(new))
		exit(0);
	new->name = SDUP(name);
	new->isopt = false;
	new->rights = NULL;
	new->last_stat = NULL;
	new->last_access = NULL;
	new->last_modif = NULL;
	new->uid = NULL;
	new->gid = NULL;
	new->blocks = 0;
	new->slink = 0;
	new->size = 0;
	new->size_min = -1;
	new->next = NULL;
	return (new);
}

void	organize_dir(int isopt, t_group *grp, char *name)
{
	t_dir	*last_other;
	t_dir	*other;
	t_dir	*new;

	new = init_dir(name);
	new->isopt = isopt;
	opt_1(new, &grp->dir_organize, &grp->curr_dir);
}