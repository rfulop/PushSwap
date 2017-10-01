/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:27 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/01 06:02:19 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void        error()
{
  printf("Error\n");
  exit (0);
}

int split_size(char **str)
{
  int size;
  char *tmp;

  size = 0;
  tmp = *str;
  while (str[size])
    ++size;
  return (size);
}

int         already_exit(t_intlst *begin, int nb)
{
  t_intlst *lst;

  lst = begin;
  while (lst)
  {
    if (nb == lst->nb)
      return (1);
    lst = lst->next;
  }
  return (0);
}

int         is_int(long long int nb)
{
  return (nb < INT_MIN || nb > INT_MAX ? 0 : 1);
}

int         checknb(t_intlst *begin, char *str)
{
  int i;
  int sign;

  i = 0;
  sign = 0;
  while (str[i])
  {
    if (str[i] >= '0' && str[i] <= '9')
      ++i;
    else if (!sign && str[i] == '-' && (str[i+1] >= '0' && str[i+1] <= '9'))
    {
      ++sign;
      ++i;
      if (sign > 1)
        error();
    }
    else
      error();
  }
  if (!is_int(ft_atoi_ll(str)) || already_exit(begin, ft_atoi(str)))
    error();
  return (ft_atoi(str));
}

t_intlst    *create_node(t_intlst *begin, char *str)
{
    t_intlst    *newNode;

    if (!(newNode = (t_intlst*)malloc(sizeof(t_intlst))))
      exit(0);
    newNode->nb = checknb(begin, str);
    newNode->previous = NULL;
    newNode->next = NULL;
    return (newNode);
}

t_intlst    *create_node_with_int(int nb)
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
            newLst = create_node(NULL, argv[nbArgs]);
            beginLst = newLst;
            previous = newLst;
        }
        else
        {
            newLst->next = create_node(beginLst, argv[nbArgs]);
            newLst = newLst->next;
            newLst->previous = previous;
            previous = newLst;
        }
        ++nbArgs;
        ++env->sizeSort;
    }
    return (beginLst);
}
