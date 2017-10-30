/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:30 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/30 12:12:16 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void        double_swap(t_intlst *lstA, t_intlst *lstB, int mode)
{
  swap(lstA, mode, STACK_A);
  swap(lstB, mode, STACK_B);
  if (mode == PS_MODE)
    printf("ss\n");
}

void       double_rotate_up(t_intlst **lstA, t_intlst **lstB, int mode)
{
  rotate_up(lstA, mode, STACK_A);
  rotate_up(lstB, mode, STACK_B);
  if (mode == PS_MODE)
    printf("rr\n");
}

void      double_rotate_down(t_intlst **lstA, t_intlst **lstB, int mode)
{
  rotate_down(lstA, mode, STACK_A);
  rotate_down(lstB, mode, STACK_B);
  if (mode == PS_MODE)
    printf("rrr\n");
}

void        rotate_down(t_intlst **lst, int mode, int stack)
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
  if (mode == PS_MODE && stack == STACK_A)
    printf("rra\n");
  if (mode == PS_MODE && stack == STACK_B)
    printf("rrb\n");
}

void        rotate_up(t_intlst **lst, int mode, int stack)
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
  if (mode == PS_MODE && stack == STACK_A)
    printf("ra\n");
  if (mode == PS_MODE && stack == STACK_B)
    printf("rb\n");
}

void        push(t_intlst **pushTo, t_intlst **pushFrom, int mode, int stack)
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
  if (mode == PS_MODE && stack == STACK_A)
      printf("pa\n");
  if (mode == PS_MODE && stack == STACK_B)
      printf("pb\n");
}

void        swap(t_intlst *lst, int mode, int stack)
{
    int tmp;

    if (lst && lst->next)
    {
        tmp = lst->nb;
        lst->nb = lst->next->nb;
        lst->next->nb = tmp;
    }
    if (mode == PS_MODE && stack == STACK_A)
      printf("sa\n");
    if (mode == PS_MODE && stack == STACK_B)
      printf("sb\n");
}
