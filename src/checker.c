/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:15 by rfulop            #+#    #+#             */
/*   Updated: 2017/09/26 22:52:36 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
    t_env env;

    if (argc < 2)
        printf("Not enoth args\n");
    else
    {
      env.sizeSort = 0;
      env.nbArgs = 1;
      env.l_a = create_intlst(&env, argc, argv);
      print_lsts(env.l_a, env.l_b);
      checker_mode(&env);
    }
    return 0;
}
