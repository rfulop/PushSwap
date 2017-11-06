/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:37 by rfulop            #+#    #+#             */
/*   Updated: 2017/11/06 05:32:20 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pushswap.h"

int cmp_int(int a, int b)
{
	return (a < b ? A_SMALLER : A_BIGGER);
}

void qs_swap(t_env *env, int a, int b)
{
	int i;
	int tmp;

	if (a > b)
	{
		tmp = b;
		b = a;
		a = tmp;
	}
	if (a == b)
		return ;

	i = 0;
	while (i < a + 1)
	{
		push(&env->l_b, &env->l_a, PS_MODE, STACK_B);
		++i;
	}
	while (i < b + 1)
	{
		rotate_up(&env->l_a, PS_MODE, STACK_A);
		++i;
	}
	push(&env->l_a, &env->l_b, PS_MODE, STACK_A);
	rotate_down(&env->l_a, PS_MODE, STACK_A);
	push(&env->l_b, &env->l_a, PS_MODE, STACK_B);
	i = 0;
	while (i + 1< b - a)
	{
		rotate_down(&env->l_a, PS_MODE, STACK_A);
		++i;
	}
	while (env->l_b)
		push(&env->l_a, &env->l_b, PS_MODE, STACK_A);
}

int take_pivot(t_intlst *stack, int n)
{
	int i;
	t_intlst *lst;

	i = 0;
	lst = stack;
	while (lst)
	{
		if (i == n)
			return lst->nb;
		lst = lst->next;
		++i;
	}
	return (0)	;
}

t_intlst *start_intlist(t_intlst *stack, int n)
{
	int i;
	t_intlst *lst;

	i = 0;
	lst = stack;
	while (i < n)
	{
		lst = lst->next;
		++i;
	}
	return lst;
}

int qs_part(t_env *env, int start, int end)
{
	int pindex;
	int pivot;
	int i;
	t_intlst *lst;

	pindex = start;
	pivot = take_pivot(env->l_a, end);
	i = start;
	lst = start_intlist(env->l_a, start);
	while (lst && i < end)
	{
		if (lst->nb < pivot)
		{
			qs_swap(env, i, pindex);
			++pindex;
		}
		++i;
		lst = lst->next;
	}
	qs_swap(env, end, pindex);
	return (pindex);
}

void qs(t_env *env, int start, int end)
{
	int pindex;

	if (start >= end)
		return ;
	analyse2(env);
	pindex = qs_part(env, start, end);
	qs(env, start, pindex - 1);
	qs(env, pindex + 1, end);
}

int check_short(t_env *env)
{
	int minA;
	int maxB;

	minA = check_min(env->l_a);
	maxB = check_max(env->l_b);

	if (!env->l_a || !env->l_b)
		return 0;
	if (!is_shorted(env->l_a) || !is_rev_shorted(env->l_b))
		return 0;
	return (minA > maxB ? 1 : 0);
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

void idk(t_env *env, int cur)
{
	rotate_up(&env->l_a, PS_MODE, STACK_A);
	if (env->verboseMode)
		print_lsts(env->l_a, env->l_b);
	while (env->l_b && env->l_b->nb > cur)
	{
		++env->nbMoves;
		if (env->scoreMode)
			printf("Move %d : ", env->nbMoves);
		push(&env->l_a, &env->l_b, PS_MODE, STACK_A);
		if (env->verboseMode)
			print_lsts(env->l_a, env->l_b);
	}
	++env->nbMoves;
	if (env->scoreMode)
		printf("Move %d : ", env->nbMoves);
	rotate_down(&env->l_a, PS_MODE, STACK_A);
}

void short_stack(t_env *env)
{
	int cur;

	print_lsts(env->l_a, env->l_b);
	while (!(is_shorted(env->l_a) == env->sizeSort))
	{
		++env->nbMoves;
		if (env->scoreMode)
			printf("Move %d : ", env->nbMoves);
	 if (!analyse2(env))
		 {
			if (((!is_shorted(env->l_a) || !is_rev_shorted(env->l_b))) && !check_short(env) && env->l_a)
			{
				if (env->l_a && env->l_b && env->l_a->next && env->l_b->next && env->l_a->nb > env->l_a->next->nb && env->l_b->nb < env->l_b->next->nb)
					double_swap(env->l_a, env->l_b, PS_MODE);
				else if (env->l_b && env->l_b->next && env->l_b->nb < env->l_b->next->nb)
					swap(env->l_b, PS_MODE, STACK_B);
				else if (env->l_a && env->l_a->next && env->l_a->nb > env->l_a->next->nb)
					swap(env->l_a, PS_MODE, STACK_A);
				else
				{
					if (env->l_a)
						cur = env->l_a->nb;
						if (!env->l_b || cur > env->l_b->nb)
							push(&env->l_b, &env->l_a, PS_MODE, STACK_B);
						else
							idk(env, cur);
				}
			}
				else if (check_short(env))
					push(&env->l_a, &env->l_b, PS_MODE, STACK_A);
				else
				{
					if (env->l_a)
						cur = env->l_a->nb;
					if (!env->l_b || cur > env->l_b->nb)
						push(&env->l_b, &env->l_a, PS_MODE, STACK_B);
					else
						idk(env, cur);
				}
			}
			if (env->verboseMode)
				print_lsts(env->l_a, env->l_b);
		}
		if (env->scoreMode)
			printf("List is shorted on %d moves\n", env->nbMoves);
	}
//
// void short_stack(t_env *env)
// {
// 	int cmp;
// 	while (!(is_shorted(env->l_a) == env->sizeSort))
// 	{
// 		++env->nbMoves;
// 		if (env->scoreMode)
// 			printf("Move %d : ", env->nbMoves);
// 		if (!analyse(env))
// 		{
// 			if (env->l_a->next && is_shorted(env->l_a) != size_stack(env->l_a))
// 			{
// 				cmp = cmp_int(env->l_a->nb, env->l_a->next->nb);
// 				if (cmp == A_SMALLER)
// 					push(&env->l_b, &env->l_a, PS_MODE, STACK_B);
// 				else
// 					swap(env->l_a, PS_MODE, STACK_A);
// 			}
// 			else if (!env->l_b->next)
// 				push(&env->l_a, &env->l_b, PS_MODE, STACK_A);
// 			else
// 			{
// 				cmp = cmp_int(env->l_b->nb, env->l_b->next->nb);
// 				if (cmp == A_SMALLER)
// 					swap(env->l_b, PS_MODE, STACK_B);
// 				else
// 					push(&env->l_a, &env->l_b, PS_MODE, STACK_A);
// 			}
// 		}
// 		if (env->verboseMode)
// 			print_lsts(env->l_a, env->l_b);
// 	}
// 	if (env->scoreMode)
// 		printf("List is shorted on %d moves\n", env->nbMoves);
// }

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
//		short_stack(&env);
		qs(&env, 0, intlist_size(env.l_a) - 1);
		}
	return 0;
}
