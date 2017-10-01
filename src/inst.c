/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:30 by rfulop            #+#    #+#             */
/*   Updated: 2017/09/30 18:40:15 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void        double_swap(t_intlst *lstA, t_intlst *lstB)
{
  swap(lstA);
  swap(lstB);
}

void       double_rotate_up(t_intlst **lstA, t_intlst **lstB)
{
  rotate_up(lstA);
  rotate_up(lstB);
}

void      double_rotate_down(t_intlst **lstA, t_intlst **lstB)
{
  rotate_down(lstA);
  rotate_down(lstB);
}

void        rotate_down(t_intlst **lst)
{
  t_intlst *tmp;
  t_intlst *newLst;
  int movingNb;

  if (lst[0] && lst[0]->next)
  {
    tmp = *lst;
    while (tmp && tmp->next)
      tmp = tmp->next;
    tmp->previous->next = NULL;
    movingNb = tmp->nb;
    newLst = create_node_with_int(movingNb);
    newLst->next = lst[0];
    lst[0]->previous = newLst;
    *lst = newLst;
    free(tmp);
  }
}

void        rotate_up(t_intlst **lst)
{
  t_intlst *tmp;
  t_intlst *newLst;
  int movingNb;

  if (lst[0] && lst[0]->next)
  {
    movingNb = lst[0]->nb;
    tmp = lst[0];
    *lst = lst[0]->next;
    lst[0]->previous = NULL;
    free(tmp);
    newLst = create_node_with_int(movingNb);
    tmp = *lst;
    while(tmp && tmp->next)
      tmp = tmp->next;
    newLst->previous = tmp;
    newLst->next = NULL;
    tmp->next = newLst;
  }
}

void        push(t_intlst **pushTo, t_intlst **pushFrom)
{
  t_intlst *tmp;
  t_intlst *newLst;
  int movingNb;

  if (pushFrom[0])
  {
    movingNb = pushFrom[0]->nb;
    tmp = pushFrom[0];
    if (tmp->next)
      tmp->next->previous = NULL;
    *pushFrom = pushFrom[0]->next;
    free(tmp);
    newLst = create_node_with_int(movingNb);
    newLst->next = *pushTo;
    if (newLst->next)
      newLst->next->previous = newLst;
    newLst->previous = NULL;
    *pushTo = newLst;
  }
}

void        swap(t_intlst *lst)
{
    int tmp;

    if (lst && lst->next)
    {
        tmp = lst->nb;
        lst->nb = lst->next->nb;
        lst->next->nb = tmp;
    }
}
