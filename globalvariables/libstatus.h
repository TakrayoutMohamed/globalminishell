#ifndef _LIBSTATUS_H_
#define _LIBSTATUS_H_
typedef struct s_stats
{
	int	status;
	int	flag_sigint;
} t_stats;

int		get_status(void);
int		get_flag_sigint(void);
void	set_status(int stvalue);
void	set_flag_sigint(int flag_sigintvalue);

#endif
