/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealislam <ealislam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:18:35 by ealislam          #+#    #+#             */
/*   Updated: 2024/09/05 08:03:02 by ealislam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h> 
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;

typedef enum state
{
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING
}	t_state;

typedef struct s_info
{
	long long	num_of_philo;
	long long	t_to_die;
	long long	t_to_eat;
	long long	t_to_sleep;
	long long	t_start;
	long long	num_of_meals;
}	t_info;

typedef struct s_philo	t_philo;

typedef struct s_all
{
	t_info			info;
	t_philo			**philos;
	t_mutex			**forks;
	t_mutex			typing_mutex;
	t_mutex			checker_mutex;
	pthread_t		checker;
	struct timeval	tv;
	int				all_alive;
}	t_all;

typedef struct s_philo
{
	int				num;
	int				meals_left;
	long long		t_last_meal;			
	t_all			*all;
	t_state			state;
	pthread_t		*thread;	
	t_mutex			*right_fork;
	t_mutex			*left_fork;
}	t_philo;

typedef struct s_malloc
{
	void			*ptr;
	struct s_malloc	*next;
}	t_malloc;

//functions---------------------------------------------------
int			ft_atoi(const char *str, long long *n);
int			print_and_exit(char *msg);
int			check_and_get_args(int argc, char **argv, t_all *all);
int			create_philosophers(t_all *all);
int			join_threads(t_all *all);
int			create_forks(t_all *all);
void		assign_forks(t_all *all, t_philo *philo, int i);
void		*ft_malloc(unsigned int size, int free);
long long	get_time(t_all *all);
int			destroy_mutex(t_all *all);
char		*num_to_str(long long num);
int			create_checker(t_all *all);
char		**ft_split(char const *s, char c);

//routine---------------------------------------------------
void		*routine(void *arg);
void		print_state(t_philo *philo, char *str);
void		take_forks(t_philo *philo);
void		put_forks(t_philo *philo);
void		eat_state(t_philo *philo);
void		sleep_state(t_philo *philo);
void		think_state(t_philo *philo);
void		think_forever(t_philo *philo);
void		*checker_of_death(void *arg);

#endif