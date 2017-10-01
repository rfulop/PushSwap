/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:08 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/01 05:55:10 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include "libft.h"

#define A_SMALLER 1
#define A_BIGGER 0

typedef struct          s_intlst
{
    int                 nb;
    struct s_intlst    *next;
    struct s_intlst   *previous;
}                       t_intlst;

typedef struct          s_env
{
  int                   sizeSort;
  int                   verboseMode;
  int                   scoreMode;
  int                   nbArgs;
  int                   nbMoves;
    struct s_intlst     *l_a;
    struct s_intlst     *l_b;
	struct s_intlst		*beginLstA;
	struct s_intlst		*beginLstB;
}                       t_env;

/*Build functions*/
t_intlst *create_emptylst(int size);
t_intlst *create_intlst(t_env *env, int argc, char **argv);
t_intlst *create_node(t_intlst *begin, char *str);
t_intlst *create_node_with_int(int nb);
/*Parse functions*/
int parse_args(t_env *env, char **argv);
void checker_mode(t_env*env);
void analyse_mode();
void read_inst(t_env *env, char *inst);
int is_shorted(t_intlst *lst);
int split_size(char **str);

/*Instructions functions*/
void swap(t_intlst *lst);
void push(t_intlst **stackA, t_intlst **stackB);
void rotate_up(t_intlst **lst);
void rotate_down(t_intlst **lst);
void double_swap(t_intlst *lstA, t_intlst *lstB);
void double_rotate_up(t_intlst **lstA, t_intlst **lstB);
void double_rotate_down(t_intlst **lstA, t_intlst **lstB);


/*Debug functions*/
void error();
void print_lst(t_intlst *lst);
void print_lsts(t_intlst *lstA, t_intlst *lstB);

#endif