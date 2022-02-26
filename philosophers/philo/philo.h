/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/23 15:04:17 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/22 21:53:09 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>

# define MSG_FORK "\033[1;34mhas taken a fork\033[0;39m"
# define MSG_EAT "\033[1;36mis eating\033[0;39m"
# define MSG_SLEEP "\033[1;35mis sleeping\033[0;39m"
# define MSG_THINK "\033[1;33mis thinking\033[0;39m"
# define MSG_DIE "\033[1;31mdied\033[0;39m"

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef enum e_error
{
	END = 1,
	MALLOC_FAILED = -1,
	TOO_MANY_PHILO = -2,
	INV_PHILO_COUNT = -3,
	INV_DIE_TIME = -4,
	INV_EAT_TIME = -5,
	INV_SLEEP_TIME = -6,
	INV_REPEAT_COUNT = -7,
	THREAD_FAILED = -9,
	MUTEX_FAILED = -10,
	PLIST_FAILED = -11
}			t_error;

typedef struct s_data
{
	int				philo_count;
	long long		die_time;
	long long		eat_time;
	long long		sleep_time;
	long			repeat_count;
	useconds_t		init_time;
	long			eat_count;
	pthread_mutex_t	eat_count_lock;
	int				died;
	pthread_mutex_t	died_lock;
}					t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			thread_id;
	pthread_mutex_t		fork_lock;
	useconds_t			last_meal;
	pthread_mutex_t		last_meal_lock;
	long				eat_count;
	struct s_data		*data;
}						t_philo;

int			ft_putstr_fd(char *s, int fd);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newnode);

int			print_error(t_error error_code);
void		philo_exit(t_list *philos);
void		terminate_thread(int philo_count, t_list *philos);

t_data		parse_args(char **argv);
int			args_validation(t_data *d);
t_list		*create_philo_list(t_data *d);

useconds_t	get_time(void);
int			ft_usleep(useconds_t usec);
void		print_timestamp(t_list *philos, char *actions, useconds_t t);

int			philo_start(int philo_count, t_list *philos);

#endif
