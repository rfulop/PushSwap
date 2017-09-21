#include "pushswap.h"

int main(int argc, char **argv)
{
    t_env env;

    if (argc < 2)
        printf("Not enoth args\n");
    else
    {
      env.sizeSort = 0;
      env.l_a = create_intlst(&env, argc, argv);
      parse_args(&env, argc, argv);
    }
    return 0;
}
