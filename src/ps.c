/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/03 12:23:51 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void short_stack(t_env *env)
{
	int cmp;
	while (!(is_shorted(env->l_a) == env->sizeSort))
	{
		++env->nbMoves;
		if (env->scoreMode)
			printf("Move %d : ", env->nbMoves);
		if (!analyse(env))
		{
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
		if (env->verboseMode)
			print_lsts(env->l_a, env->l_b);
	}
	if (env->scoreMode)
		printf("List is shorted on %d moves\n", env->nbMoves);
}

void print_help()
{
	printf("Usage : ./push_swap [-[+]hsv] {x1 x2 ... xn}\n");
	printf("Options : \n");
	printf("h : Print help\n");
	printf("s : Score Mode - Print step number and gives final short score\n");
	printf("v : Verbose Mode - Display stacks'contents at each step\n");
}

int parse_args(t_env *env, char **argv)
{
	int a;
	int b;

	a = 1;
	while (argv[a] && *argv[a] == '-')
	{
		b = 1;
		while(argv[a][b])
		{
			if (argv[a][b] == 'h')
				print_help();
			else if (argv[a][b] == 'v')
				env->verboseMode = 1;
			else if (argv[a][b] == 's')
				env->scoreMode = 1;
			else if (argv[a][b] >= '0' && argv[a][b] <= '9')
				return a;
			else
			{
				printf("Invalid argument\n");
				print_help();
				exit (0);
			}
			++b;
		}
		++a;
	}
	return a;
}

int main(int argc, char **argv)
{
	int size;
	t_env env;
	char **split;

	if (argc < 2)
		printf("Missing arguments (\"./push_swap -h\" for help)\n");
	else
	{
		env.sizeSort = 0;
		env.scoreMode = 0;
		env.verboseMode = 0;
		env.nbMoves = 0;
		env.nbArgs = parse_args(&env, argv);
		if (argc == 2 && ft_strlen(argv[1]) > 1)
		{
			split = ft_strsplit(argv[1], ' ');
			size = split_size(split);
			--env.nbArgs;
			env.l_a = create_intlst(&env, size, split);
		}
		else
			env.l_a = create_intlst(&env, argc, argv);
		if (env.verboseMode)
		{
			printf("Stack in the beginning : ");
			//	print_lst(env.l_a);
			printf("\n");
		}
		short_stack(&env);
	}
	return 0;
}
