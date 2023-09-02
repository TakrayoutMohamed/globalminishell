/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libglobalminishell.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 04:43:04 by takra             #+#    #+#             */
/*   Updated: 2023/09/02 04:44:00 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGLOBALMINISHELL_H
# define LIBGLOBALMINISHELL_H
# include <signal.h>
# ifndef LIBMINISHELL_H
#  include "./execution/libminishell.h"
# endif
# ifndef MINISHELL_H
#  include "./parsing/includes/minishell.h"
# endif

t_list	*convert_parsing_lst_to_execution(t_llist *tmp_lst);
t_list	*convert_parsing_env_to_execution(t_llist *tmp_lst);

#endif
