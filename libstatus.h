/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstatus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 04:45:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/10 15:41:22 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTATUS_H
# define LIBSTATUS_H
# include "./libstructs.h"

struct s_stats
{
	int		status;
	int		here_doc_stat;
	int		flag_sigint;
	int		delimiter_expand;
	t_llist	*garbage;
} t_stats;

#endif
