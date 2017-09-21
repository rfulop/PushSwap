#include "pushswap.h"

int cmp_int(int a, int b)
{
	return (a < b ? A_SMALLER : A_BIGGER);
}

int size_stack(t_intlst *lst)
{
	int a;

	a = 0;
	while (lst)
	{
		lst = lst->next;
		++a;
	}
	return a;
}

void parse_stack(t_env *env, int argc, char **argv)
{
	int cmp;
	while (!(is_shorted(env->l_a) == env->sizeSort))
	{
		print_lsts(env->l_a, env->l_b);
		if (env->l_a->next && is_shorted(env->l_a) != size_stack(env->l_a))
		{
			cmp = cmp_int(env->l_a->nb, env->l_a->next->nb);
			if (cmp == A_SMALLER)
			{
				push(&env->l_b, &env->l_a);
				printf("pb\n");
			}
			else
			{
				swap(env->l_a);
				printf("sa\n");
			}
		}
		else if (!env->l_b->next)
		{
			push(&env->l_a, &env->l_b);
			printf("pa\n");
		}
		else
		{
			cmp = cmp_int(env->l_b->nb, env->l_b->next->nb);
			if (cmp == A_SMALLER)
			{
				swap(env->l_b);
				printf("sb\n");
			}
			else
			{
				push(&env->l_a, &env->l_b);
				printf("pa\n");
			}
		}
	}
	printf("List is shorted\n");
	print_lst(env->l_a);
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
		parse_stack(&env, argc, argv);
	}
	return 0;
}
