#include "./libglobalminishell.h"

t_list	*convert_parsing_env_to_execution(t_llist *tmp_lst)
{
	t_list	*lst;
	t_list	*new;
	t_env	*env;

	lst = NULL;
	while (tmp_lst)
	{
		env = (t_env *)tmp_lst->content;
		new = ft_lstnew(ft_strdup(env->key), ft_strdup(env->value));
		ft_lstadd_back(&lst, new);
		tmp_lst = tmp_lst->next;
	}
	return (lst);
}
