#include "./libglobalminishell.h"

void	prompt(t_list **env_lst, t_llist *env_list)
{
	char	*cmd_line;
	t_llist	*pars_llst;
	t_list	*lst;
	int		currentstatus;

	cmd_line = readline("\033[32m➜ minishell$ \033[0m");
	if (!cmd_line)
	{
		ft_lstclear(env_lst, del);
		ft_lstclearp(&env_list);
		ft_putstr_fd("exit\n", 1);
		exit (t_stats.status);
	}
	if (cmd_line && ft_strlen(cmd_line) > 0)
	{
		add_history(cmd_line);
		currentstatus = t_stats.status;
		pars_llst = parse_data(cmd_line, env_list);
		free(cmd_line);
		lst = convert_parsing_lst_to_execution(pars_llst);
		ft_lstclearp(&pars_llst);
		if (currentstatus == t_stats.status)
			execute_list(lst, env_lst);
		ft_lstclear(&lst, del);
	}
}
