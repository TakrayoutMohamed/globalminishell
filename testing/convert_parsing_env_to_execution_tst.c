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
    // system("leaks a.out");
}

int main(int argc, char **argv, char **env)
{
    atexit(foo);
    char str[] = "ls -l -a";
    char **matrix = ft_split(str, ' ');
    t_llist *env_list;

    t_llist *llst = parse_data(str, env, &env_list);

    print_llst(env_list);

    t_list *envv = convert_parsing_env_to_execution(env_list);

    print_lst(envv);

    ft_lstclearp(&llst);
    ft_lstclearp(&env_list);
    ft_freematrix(matrix);


}