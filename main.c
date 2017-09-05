#include "pushswap.h"

t_intlst    *create_node(int nb)
{
    t_intlst    *newNode;

    if (!(newNode = (t_intlst*)malloc(sizeof(t_intlst))))
    printf("nb = %d\n", nb);
    newNode->nb = nb;
    newNode->previous = NULL;
    newNode->next = NULL;
    return (newNode);
}

/* We admit we rotate on stackA
By down rotation we mean that the first element on stackA becomes the last one
And the lastone becomes the first one
  */
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
    newLst = create_node(movingNb);
    newLst->next = lst[0];
    lst[0]->previous = newLst;
    *lst = newLst;
    free(tmp);
  }
}

/*We amite we rotate on stackA
The last element of stackA becomes the first one
the first element of stackA becomes the last one*/
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
    newLst = create_node(movingNb);
    tmp = *lst;
    while(tmp && tmp->next)
      tmp = tmp->next;
    newLst->previous = tmp;
    newLst->next = NULL;
    tmp->next = newLst;
  }
}

//we admit stackA -> lsta and stackB -> lstb
/*We admit moving the first elem on stackA* on the top of stackB
A->firstStack
B->SecONe
We can alternate both*/
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
    newLst = create_node(movingNb);
    newLst->next = *pushTo;
    if (newLst->next)
      newLst->next->previous = newLst;
    newLst->previous = NULL;
    *pushTo = newLst;
  }
}

/*Replace stackA->nb by stackB->nb, both sides*/
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

t_intlst  *create_intlst(t_env *env, int argc, char **argv)
{
    int nbArgs;
    t_intlst *beginLst;
    t_intlst *previous;
    t_intlst *newLst;

    nbArgs = 2;
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
/*
t_intlst*   create_emptylst(int size)
{
  t_intlst *beginLst;
  t_intlst *previousLst;
  t_intlst *newLst;

  newLst = NULL;
  while (size)
  {
    if (!newLst)
    {
      newLst = create_node(0, 0);
      beginLst = newLst;
      previousLst = newLst;
    }
    else
    {
      newLst->next = create_node(0, 0);
      newLst = newLst->next;
      newLst->previous = previousLst;
      previousLst = newLst;
    }
    --size;
  }
  return (beginLst);
}
*/
int main(int argc, char **argv)
{
    t_env env;

    if (argc < 2)
        printf("Not enoth args\n");
    else
    {
      env.sizeSort = 0;
      env.l_a = create_intlst(&env, argc, argv);
      if (*argv[1] == '-')
        parse_args(&env, argc, argv);
    }
    return 0;
}
