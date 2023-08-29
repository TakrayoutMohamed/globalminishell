/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:19 by oredoine          #+#    #+#             */
/*   Updated: 2023/08/29 22:46:30 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libglobalminishell.h"

int main(int ac, char **av, char **env)
{
    t_llist     *env_list;
    t_llist     *pars_llst;
    t_list      *lst;
    t_list      *env_lst;
    char        *cmd_line;

    (void)ac;
    (void)av;
    while (1)
    {
        cmd_line = readline("\033[32m➜ minishell$ \033[0m");
        if (!cmd_line)
            exit(EXIT_FAILURE);
    	if (cmd_line && ft_strlen(cmd_line) > 0)
		{
			add_history(cmd_line);
			pars_llst = parse_data(cmd_line, env, &env_list);
            lst = convert_parsing_lst_to_execution(pars_llst);
            env_lst = convert_parsing_env_to_execution(env_list);
            execute_list(lst, env_lst);
		}
    }
    ft_lstclearp(&pars_llst);
}
