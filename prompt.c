/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:51:12 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/14 06:18:13 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libglobalminishell.h"

// void print_llst(t_llist *iterator)
// {
// 	t_llist *iterate = iterator;
// 	while (iterate)
// 	{
// 		// printf("here\n");
// 		t_pass *cmde = (t_pass *)iterate->content;
// 		int i = 0;
// 		if (cmde->argument_cmd)
// 		{
// 			while (cmde->argument_cmd[i])
// 			{
// 				printf("arg : %s\n",cmde->argument_cmd[i]);
// 				i++;
// 			}
// 		}
// 		printf("infile =|%d|, outfile = |%d|\n", cmde->infile, cmde->outfile);
// 		printf("=========\n");
// 		iterate = iterate->next;
// 	}
// }

static void	clean_data_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		ft_lstclear(&(tmp->cmd), del);
		tmp = tmp->next;
	}
	ft_lstclear(&lst, del);
}

void	prompt(t_list **env_lst, t_llist *env_list)
{
	char	*cmd_line;
	t_llist	*pars_llst;
	t_list	*lst;

	cmd_line = readline("\033[32m➜ minishell$ \033[0m");
	if (!cmd_line)
	{
		ft_lstclear(env_lst, del);
		ft_lstclearp(&env_list);
		ft_putstr_fd("exit\n", 1);
		exit (t_stats.status);
	}
	if (ft_strlen(cmd_line) > 0)
	{

		add_history(cmd_line);
		t_stats.here_doc_stat = 1;
		pars_llst = parse_data(cmd_line, env_list);
		free(cmd_line);
		lst = convert_parsing_lst_to_execution(pars_llst);
		ft_lstclearp(&pars_llst);
		if (t_stats.here_doc_stat == 1 && lst != NULL && lst->cmd != NULL)
			execute_list(lst, env_lst);
		clean_data_lst(lst);
	}
}
