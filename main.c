/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:45:19 by oredoine          #+#    #+#             */
/*   Updated: 2023/08/29 19:30:42 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libglobalminishell.h"

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    // (void)env;
    // t_tokenize  *token;
    t_llist     *env_list;
    t_llist     *iterator;
    char *cmd_line;

    while (1)
    {
        cmd_line = readline("\033[32m➜ minishell$ \033[0m");
        if (!cmd_line)
            exit(0);
    	if (cmd_line && ft_strlen(cmd_line) > 0)
		{
			add_history(cmd_line);
			// added this to get the parsed data in type of t_llist
			iterator = parse_data(cmd_line, env, &env_list);
		}
        // t_llist *tmpe = iterator;
        // while (tmpe)
        // {
        //     token = (t_tokenize *)iterator->content;
        //     token = tmpe->content;
        //     printf("token->value : %s\n", token->value);
        //     tmpe = tmpe->next;
        // }
        // **********************print list**************************
        if(iterator)
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
                printf("=========\n");
                iterate = iterate->next;
            }
        }
        // **********************print list**************************
        // void execution(t_llst *lst); hnaaaaaaaaaaaaaa fin atbda khdmtk; l head dyal list hwa iterator
        ft_lstclearp(&iterator);
        // free(cmd_line);
    }
}
/*env */
// t_llist *parse_data(char *str, env)