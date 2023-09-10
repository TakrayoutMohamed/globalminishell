/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstructs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 15:40:49 by mohtakra          #+#    #+#             */
/*   Updated: 2023/09/10 15:41:01 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRUCTS_H
# define LIBSTRUCTS_H

typedef enum tokens
{
	INPUT,
	HERE_DOC,
	OUTPUT,
	APPEND,
	S_QUOTES,
	D_QUOTES,
	PIPE,
	WSPACEE,
	STRING,
	NO_EXPAND,
}	t_tokens;

typedef struct s_tokenize
{
	t_tokens	type;
	char		*value;
}	t_tokenize;

typedef struct s_llist
{
	void			*content;
	struct s_llist	*next;
}	t_llist;

typedef struct s_env{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_pass{
	char	**argument_cmd;
	int		infile;
	int		outfile;
}	t_pass;
typedef struct s_tools{
	t_env	*tmp;
	char	*add;
	char	*cutter;
	char	*key;
}	t_tools;

#endif
