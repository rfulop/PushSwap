/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 11:53:12 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/03 16:13:47 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int check_min(t_intlst *begin)
{
	int min;

	min = INT_MAX;
	t_intlst *tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

int check_max(t_intlst *begin)
{
	int max;

	max = INT_MIN;
	t_intlst *tmp;

	tmp = begin;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}

int intlist_size(t_intlst *begin)
{
	int size;
	t_intlst *lst;

	lst = begin;
	size = 0;
	while (lst)
	{
		++size;
		lst = lst->next;
	}
	return (size);
}

t_intlst *last_elem(t_intlst *begin)
{
	t_intlst *elem;

	elem = begin;
	while (elem && elem->next)
		elem = elem->next;
	return elem;
}

int analyse(t_env *env)
{
	int minA;
	int maxA;
	int maxB;
	int minB;
	int sizeA;
	int sizeB;
	t_intlst *lastA;
	t_intlst *lastB;

	minA = check_min(env->l_a);
	maxA = check_max(env->l_a);
	minB = check_min(env->l_b);
	maxB = check_max(env->l_b);
//	printf("minA = %d maxA = %d minB = %d maxB = %d\n", minA, maxA, minB, maxB);
//	printf("listsizeB = %d\n", sizeB);
	lastA = last_elem(env->l_a);
	lastB = last_elem(env->l_b);
	sizeA = intlist_size(env->l_a);
	sizeB = intlist_size(env->l_b);
	if (sizeA > 2 && sizeB > 2 && env->l_a && env->l_b  && env->l_a->nb == maxA && env->l_b->nb == maxB)
	{
		double_rotate_up(&env->l_a, &env->l_b);
		printf("rr\n");
	}
	else if (sizeA > 2 && env->l_a && env->l_a->nb == maxA)
	{
		rotate_up(&env->l_a);
		printf("ra\n");
	}
	else if (sizeB > 2 && env->l_b && env->l_b->nb == maxB)
	{
		rotate_up(&env->l_b);
		printf("rb\n");
	}
	else if (sizeA > 2 && sizeB > 2 && lastA && lastB && (lastA->nb == minA && lastB->nb == minB))
	{
		double_rotate_down(&env->l_a, &env->l_b);
		printf("rrr\n");
	}
	else if (sizeA > 2 && lastA && lastA->nb == minA)
	{
		rotate_down(&env->l_a);
		printf("rra\n");
	}
	else if (sizeB > 2 && lastB && lastB->nb == minB)
	{
		rotate_down(&env->l_b);
		printf("rrb\n");
	}
	else if (sizeA > 2 && env->l_a->nb > lastA->nb)
	{
		rotate_up(&env->l_a);
		printf("ra\n");
	}
//	else if (sizeA > 2 && env->l_a->nb < lastA->nb)
//	{
//		rotate_down(&env->l_a);
//		printf("rra\n");
//	}
	else
		return (0);
	return (1);
}
