/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfulop <rfulop@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 22:48:15 by rfulop            #+#    #+#             */
/*   Updated: 2017/10/01 06:02:29 by rfulop           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
    int size;
    t_env env;
    char **split;

    if (argc < 2)
        printf("Not enoth args\n");
    else
    {
      env.sizeSort = 0;
      env.nbArgs = 1;
      if (argc == 2 && ft_strlen(argv[1]) > 1)
      {
        split = ft_strsplit(argv[1], ' ');
        size = split_size(split);
        env.nbArgs = 0;
        env.l_a = create_intlst(&env, size, split);
      }
      else
        env.l_a = create_intlst(&env, argc, argv);
  //    print_lsts(env.l_a, env.l_b);
      checker_mode(&env);
    }
    return 0;
}
