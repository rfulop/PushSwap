#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>

typedef struct          s_intlst
{
    int                 nb;
    struct s_intlst    *next;
    struct s_intlst   *previous;
}                       t_intlst;

typedef struct          s_env
{
    struct s_intlst     *l_a;
    struct s_intlst     *l_b;
}                       t_env;

#endif
