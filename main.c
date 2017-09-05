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
