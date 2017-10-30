/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:34 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/30 12:11:06 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int is_shorted(t_intlst *lst)
{
  int a;
  int tmp;

  a = 0;
  tmp = INT_MIN;
  while (lst)
  {
    if (lst->nb < tmp)
      return (0);
    tmp = lst->nb;
    lst = lst->next;
    ++a;
  }
  return (a);
}

int is_rev_shorted(t_intlst *lst)
{
  int a;
  int tmp;

  a = 0;
  tmp = INT_MAX;
  while (lst)
  {
    if (lst->nb > tmp)
      return (0);
    tmp = lst->nb;
    lst = lst->next;
    ++a;
  }
  return (a);
}

void read_inst(t_env *env, char *inst)
{
  if(!(ft_strcmp(inst, "sa")))
    swap(env->l_a, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "sb")))
    swap(env->l_b, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "ss")))
    double_swap(env->l_a, env->l_b, CHR_MODE);
  else if(!(ft_strcmp(inst, "pa")))
    push(&env->l_a, &env->l_b, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "pb")))
    push(&env->l_b, &env->l_a, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "ra")))
    rotate_up(&env->l_a, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "rb")))
    rotate_up(&env->l_b, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "rr")))
    double_rotate_up(&env->l_a, &env->l_b, CHR_MODE);
  else if(!(ft_strcmp(inst, "rra")))
    rotate_down(&env->l_a, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "rrb")))
    rotate_down(&env->l_b, CHR_MODE, NO_STACK);
  else if(!(ft_strcmp(inst, "rrr")))
    double_rotate_down(&env->l_a, &env->l_b, CHR_MODE);
  else
    error();
}

void analyse_mode()
{
  int fd;
  char *line;

  line = NULL;
  fd = open(line, O_RDONLY);
  while (get_next_line(fd, &line))
  {
    //solve();
    free(line);
  }
}

void checker_mode(t_env *env)
{
  int fd;
  char *line;

  line = NULL;
  fd = 0;
  while (get_next_line(fd, &line))
  {
    read_inst(env, line);
    free(line);
  }
  if (is_shorted(env->l_a) == env->sizeSort)
  {
    printf("OK\n");
    exit (1);
  }
  else
  {
    printf("KO\n");
    exit (0);
  }
  print_lsts(env->l_a, env->l_b);
}
