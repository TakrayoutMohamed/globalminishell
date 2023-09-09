/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstatus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takra <takra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 04:45:08 by takra             #+#    #+#             */
/*   Updated: 2023/09/09 02:59:48 by takra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTATUS_H
# define LIBSTATUS_H

struct s_stats
{
	int	status;
	int	flag_sigint;
	int	delimiter_expand;
} t_stats;
#endif
