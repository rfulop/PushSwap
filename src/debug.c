#include "pushswap.h"

void        print_lsts(t_intlst *lstA, t_intlst *lstB)
{
  printf("stackA :\n");
  print_lst(lstA);
  printf("stackB :\n");
  print_lst(lstB);
  printf("\n");
}

void        print_lst(t_intlst *lst)
{
    int a;
    t_intlst *tmp;
//    t_intlst *last;

    a = 0;
    tmp = lst;
  //  printf("Lst :\n");
    while (tmp)
    {
        printf("%d - nb = %d\n", a, tmp->nb);
//        if (tmp)
//            last = tmp;
        tmp = tmp->next;
        ++a;
    }

/*    printf("\nReverse lst :\n");
    while (last)
    {
        printf("%d - nb = %d\n", a, last->nb);
        last = last->previous;
        --a;
    }*/
}
