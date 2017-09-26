/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:27 by rfulop            #+#    #+#             */
/*   Updated: 2017/09/26 22:48:28 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_intlst    *create_node(int nb)
{
    t_intlst    *newNode;

    if (!(newNode = (t_intlst*)malloc(sizeof(t_intlst))))
      exit(0);
    newNode->nb = nb;
    newNode->previous = NULL;
    newNode->next = NULL;
    return (newNode);
}

t_intlst  *create_intlst(t_env *env, int argc, char **argv)
{
    int nbArgs;
    t_intlst *beginLst;
    t_intlst *previous;
    t_intlst *newLst;

    nbArgs = env->nbArgs;
    newLst = NULL;
    while (nbArgs != argc)
    {
        if (!newLst)
        {
            newLst = create_node(atoi(argv[nbArgs]));
            beginLst = newLst;
            previous = newLst;
        }
        else
        {
            newLst->next = create_node(atoi(argv[nbArgs]));
            newLst = newLst->next;
            newLst->previous = previous;
            previous = newLst;
        }
        ++nbArgs;
        ++env->sizeSort;
    }
    return (beginLst);
}
