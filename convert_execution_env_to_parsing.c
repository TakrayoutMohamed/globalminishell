/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_execution_env_to_parsing.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:53:02 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/09 18:53:08 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libglobalminishell.h"

t_llist	*convert_execution_env_to_parsing(t_list *lst)
{
	t_llist	*llst;
	t_llist	*llst_tmp;
	void	*new;
	char	*value;

	llst = NULL;
	while (lst)
	{
		value = NULL;
		new = (t_env *) malloc(sizeof(t_env));
		if (new == NULL)
			return (NULL);
		((t_env *)new)->key = ft_strdup(lst->key);
		if (lst->value != NULL)
			value = ft_strdup(lst->value);
		((t_env *)new)->value = value;
		llst_tmp = ft_lstnewp(new);
		ft_lstadd_backp(&llst, llst_tmp);
		lst = lst->next;
	}
	return (llst);
}