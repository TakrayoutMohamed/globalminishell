/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:19 by oredoine          #+#    #+#             */
/*   Updated: 2023/09/01 15:45:11 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libglobalminishell.h"

void	print_env(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (lst != NULL)
	{
		printf("**%s=%s**\n",lst->key, lst->value);
		lst = lst->next;
	}
	lst = tmp;
	printf("jj\n");
}

void	print_lst(t_list *lst)
{
	t_list	*tmp;
	t_list	*cmd_lst;

	tmp = lst;
	while (tmp != NULL)
	{
		cmd_lst = tmp->cmd;
		while (cmd_lst != NULL)
		{
			printf("**%s**\n",cmd_lst->value);
			cmd_lst = cmd_lst->next;
		}
		printf("infile = |%d| outfile = |%d|\n",tmp->infile, tmp->outfile);
		tmp = tmp->next;
	}
	printf("\n");
}

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

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		if (t_stats.flag_sigint == 1)
		{
			ft_putstr_fd("", 1);
		}
		else
		{
			printf("\n");
			rl_on_new_line();
			rl_replace_line("", 1);
			rl_redisplay();
		}
	}
}

int	main(int ac, char **av, char **env)
{
	t_llist	*env_list;
	t_llist	*pars_llst;
	t_list	*lst;
	t_list	*env_lst;
	char	*cmd_line;

	t_stats.flag_sigint = 0;
	(void)ac;
	(void)av;
	signal(SIGINT, &handler);
	signal(SIGQUIT, SIG_IGN);
	t_stats.status = 5;
	env_list = preparing_env(env);
	env_lst = convert_parsing_env_to_execution(env_list);
	update_shlvl(env_lst);
	while (1)
	{
		cmd_line = readline("\033[32m➜ minishell$ \033[0m");
		if (!cmd_line)
		{
			ft_putstr_fd("exit\n",1);
			exit(t_stats.status);
		}
		if (cmd_line && ft_strlen(cmd_line) > 0)
		{
			add_history(cmd_line);
			pars_llst = parse_data(cmd_line, env_list);
			lst = convert_parsing_lst_to_execution(pars_llst);
			execute_list(lst, env_lst);
		}
	}
	ft_lstclearp(&pars_llst);
}
