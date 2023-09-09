#include "../libglobalminishell.h"

void print_llst(t_llist *iterator)
{
    t_llist *iterate = iterator;
    while (iterate)
    {
        t_env *env = (t_env *)iterate->content;
        printf("%s=%s\n",env->key, env->value);
        iterate = iterate->next;
    }
    printf("=========\n");
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
    	printf("**%s=%s**\n",lst->key, lst->value);
        lst = lst->next;
	}
	lst = tmp;
	printf("\n");
}

void foo(void)
{
    system("leaks convert_lst_env_to_llstenv");
}

int main(int argc, char **argv, char **env)
{

    atexit(foo);
    t_llist *env_list = preparing_env(env);

    print_llst(env_list);
    printf("\n++++++++++++++++++++++++++++++++++++++++\n");
    t_list *envv = convert_parsing_env_to_execution(env_list);

    print_lst(envv);
    printf("\n++++++++++++++++++++++++++++++++++++++++\n");
    
    t_llist *llenvv = convert_execution_env_to_parsing(envv);

    print_llst(llenvv);

    ft_lstclearp(&env_list);
    ft_lstclearp(&llenvv);
    ft_lstclear(&envv, del);


}