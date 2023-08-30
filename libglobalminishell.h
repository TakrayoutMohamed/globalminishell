#ifndef _LIBGLOBALMINISHELL_H_
#define _LIBGLOBALMINISHELL_H_
#ifndef LIBMINISHELL_H_
# include "./execution/libminishell.h"
#endif
#ifndef MINISHELL_H
# include "./parsing/includes/minishell.h"
#endif
// int status;

t_list	*convert_parsing_lst_to_execution(t_llist *tmp_lst);
t_list	*convert_parsing_env_to_execution(t_llist *tmp_lst);

#endif
