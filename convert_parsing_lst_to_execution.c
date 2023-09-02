#include "./libglobalminishell.h"

t_list	*convert_parsing_lst_to_execution(t_llist *tmp_lst)
{
	t_list	*lst;
	t_pass	*pass;

	lst = NULL;
	while (tmp_lst)
	{
		ft_lstadd_back(&lst, ft_lstnew(NULL, NULL));
		if (tmp_lst->content != NULL)
		{
			pass = (t_pass *)tmp_lst->content;
			ft_lstlast(lst)->cmd = convert_matrix_to_list(pass->argument_cmd);
			ft_lstlast(lst)->infile = pass->infile;
			ft_lstlast(lst)->outfile = pass->outfile;
		}
		tmp_lst = tmp_lst->next;
	}
	return (lst);
}
