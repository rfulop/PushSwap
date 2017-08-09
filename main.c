#include "pushswap.h"

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

t_intlst    *create_node(int nb)
{
    t_intlst    *newNode;

    if (!(newNode = (t_intlst*)malloc(sizeof(t_intlst))))
        exit (0);
    newNode->nb = nb;
    newNode->previous = NULL;
    newNode->next = NULL;
    return (newNode);
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
        env.l_a = create_intlst(argc, argv);
    print_lst(env.l_a);
    swap(env.l_a);
    print_lst(env.l_a);
    return 0;
}
