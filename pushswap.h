#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

typedef struct          s_intlst
{
    int                 nb;
    struct s_intlst    *next;
    struct s_intlst   *previous;
}                       t_intlst;

typedef struct          s_env
{
  int                   sizeSort;
    struct s_intlst     *l_a;
    struct s_intlst     *l_b;
	struct s_intlst		*beginLstA;
	struct s_intlst		*beginLstB;
}                       t_env;

/*Build functions*/
t_intlst *create_emptylst(int size);
t_intlst *create_intlst(t_env *env, int argc, char **argv);
t_intlst *create_node(int nb);
/*Parse functions*/
void parse_args(t_env *env, int argc, char **argv);
void checker_mode(t_env*env, int argc, char **argv);
void analyse_mode(t_env *env,int argc, char **argv);
void read_inst(t_env *env, char *inst);
int is_shorted(t_intlst *lst, int sizeSort);

/*Instructions functions*/
void swap(t_intlst *lst);
void push(t_intlst **stackA, t_intlst **stackB);
void rotate_up(t_intlst **lst);
void rotate_down(t_intlst **lst);
void double_swap(t_intlst *lstA, t_intlst *lstB);
void double_rotate_up(t_intlst **lstA, t_intlst **lstB);
void double_rotate_down(t_intlst **lstA, t_intlst **lstB);


/*Debug functions*/
void print_lst(t_intlst *lst);
void print_lsts(t_intlst *lstA, t_intlst *lstB);

#endif
