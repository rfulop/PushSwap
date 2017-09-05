#include "pushswap.h"

int is_shorted(t_intlst *lst, int sizeSort)
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
  printf("shorted a = %d size = %d\n", a, sizeSort);
  return (a == sizeSort ? 1 : 0);
}

void read_inst(t_env *env, char *inst)
{
  if(!(ft_strcmp(inst, "sa")))
    swap(env->l_a);
  else if(!(ft_strcmp(inst, "sb")))
    swap(env->l_b);
  else if(!(ft_strcmp(inst, "ss")))
  {
    swap(env->l_a);
    swap(env->l_b);
  }
  else if(!(ft_strcmp(inst, "pa")))
    push(&env->l_a, &env->l_b);
  else if(!(ft_strcmp(inst, "pb")))
    push(&env->l_b, &env->l_a);
  else if(!(ft_strcmp(inst, "ra")))
    rotate_up(&env->l_a);
  else if(!(ft_strcmp(inst, "rb")))
    rotate_up(&env->l_b);
  else if(!(ft_strcmp(inst, "rr")))
  {
    rotate_up(&env->l_a);
    rotate_up(&env->l_b);
  }
  else if(!(ft_strcmp(inst, "rra")))
    rotate_down(env->l_a);
  else if(!(ft_strcmp(inst, "rrb")))
    rotate_down(env->l_b);
  else if(!(ft_strcmp(inst, "rrb")))
  {
    rotate_down(env->l_a);
    rotate_down(env->l_b);
  }
}

void analyse_mode(t_env *env, int argc, char **argv)
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

void checker_mode(t_env *env, int argc, char **argv)
{
  int fd;
  char *line;

  line = NULL;
  fd = 0;
  while (get_next_line(fd, &line))
  {
    read_inst(env, line);
    free(line);
    if (is_shorted(env->l_a, env->sizeSort))
      exit (1);
  print_lsts(env->l_a, env->l_b);
  }
}

void parse_args(t_env *env, int argc, char **argv)
{
  print_lsts(env->l_a, env->l_b);
//  print_lst(env->l_b);
  if (argv[1][1] == 'c')
    checker_mode(env, argc, argv);
  else if (argv[1][1] == 'a')
    analyse_mode(env, argc, argv);
}
