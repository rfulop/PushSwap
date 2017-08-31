#include "pushswap.h"

/* BINARY MAGIC NUMBER :0xea83f3
Not already added on *.cor binary
*/

t_intlst    *create_node(int nb, int mode)
{
    t_intlst    *newNode;

    if (!(newNode = (t_intlst*)malloc(sizeof(t_intlst))))
    if (mode)
        exit (0);
      newNode->nb = nb;
    newNode->previous = NULL;
    newNode->next = NULL;
    return (newNode);
}

/* We admit we rotate on stackA
By down rotation we mean that the first element on stackA becomes the last one
And the lastone becomes the first one
  */
void        rotate_down(t_intlst *lst)
{
  /*
  int       tmp;
  t_intlst *firstEl;
  t_intlst *tmpLst;
  t_intlst *lastEl;

  tmp = lst->nb;
  lst = lst->next;
  tmpLst = lst;
  while (tmpLst)
    tmpLst = tmpLst->next;
  tmpLst = lastEl;
  tmpLst->next = create_node(tmp, 1);
*/}

/*We amite we rotate on stackA
The last element of stackA becomes the first one
the first element of stackA becomes the last one*/
void        rotate_up(t_intlst *lst)
{
    int       tmp;
    t_intlst *firstEl;
    t_intlst *tmpLst;
    t_intlst *lastEl;

    tmp = lst->nb;
    lst = lst->next;
    tmpLst = lst;
    while (tmpLst)
      tmpLst = tmpLst->next;
    lastEl = tmpLst;
    lastEl->next = create_node(tmp, 1);
}

//we admit stackA -> lsta and stackB -> lstb
/*We admit moving the first elem on stackA* on the top of stackB
A->firstStack
B->SecONe
We can alternate both*/
void        push(t_intlst *stackA, t_intlst *stackB, t_intlst *beginLstA, t_intlst *beginLstB)
{
  t_intlst *newLst;
  int movingNb;

  movingNb = stackA->nb;
  stackA = stackA->next;
  newLst = create_node(movingNb, 1);
  newLst->next = stackB;
  stackB = newLst;
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

void        print_lst(t_intlst *lst)
{
    int a;
    t_intlst *tmp;
//    t_intlst *last;

    a = 0;
    tmp = lst;
    printf("Lst :\n");
    while (tmp)
    {
        printf("%d - nb = %d\n", a, tmp->nb);
        tmp = tmp->next;
//        if (tmp)
//            last = tmp;
        ++a;
    }
    /*
    printf("\nReverse lst :\n");
    while (last)
    {
        printf("%d - nb = %d\n", a, last->nb);
        last = last->previous;
        --a;
    }*/
}

t_intlst  *create_intlst(int argc, char **argv)
{
    int nbArgs;
    t_intlst *beginLst;
    t_intlst *previous;
    t_intlst *newLst;

    nbArgs = 1;
    newLst = NULL;
    while (nbArgs != argc)
    {
        if (!newLst)
        {
            newLst = create_node(atoi(argv[nbArgs]), 1);
            beginLst = newLst;
            previous = newLst;
        }
        else
        {
            newLst->next = create_node(atoi(argv[nbArgs]), 1);
            newLst = newLst->next;
            newLst->previous = previous;
            previous = newLst;
        }
        ++nbArgs;
    }
    return (beginLst);
}

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

int main(int argc, char **argv)
{
    t_env env;

    //l_a = NULL;
    if (argc < 2)
        printf("Not enoth args\n");
    else
    {
      env.l_a = create_intlst(argc, argv);
      print_lst(env.l_a);
      env.l_b = create_emptylst(argc - 1);
      if (*argv[1] == '-')
        parse_args(&env, argc, argv);
    }
    print_lst(env.l_a);
    swap(env.l_a);
    print_lst(env.l_a);
    return 0;
}
