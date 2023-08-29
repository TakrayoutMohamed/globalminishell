#include "../libglobalminishell.h"

void print_llst(t_llist *iterator)
{
    t_llist *iterate = iterator;
    while (iterate)
    {
        t_pass *cmde = (t_pass *)iterate->content;
        int i = 0;
        while (cmde->argument_cmd[i])
        {
            printf("arg : %s\n",cmde->argument_cmd[i]);
            i++;
        }
        printf("infile =|%d|, outfile = |%d|\n", cmde->infile, cmde->outfile);
        printf("=========\n");
        iterate = iterate->next;
    }
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
        while (lst->cmd != NULL)
        {
    		printf("**%s**\n",lst->cmd->value);
            lst->cmd = lst->cmd->next;
        }
        printf("infile = |%d| outfile = |%d|\n",lst->infile, lst->outfile);
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

    print_llst(llst);

    t_list *lst = convert_parsing_lst_to_execution(llst);

    print_lst(lst);

    ft_lstclearp(&llst);
    ft_lstclearp(&env_list);
    ft_freematrix(matrix);


}