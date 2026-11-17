/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vskopova <vskopova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:16:07 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/17 17:43:34 by vskopova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef enum e_scheduler
{
	FIFO,
	EDF
}	t_scheduler;

typedef struct s_coder
{
    int             id;
    int             compiles_done;
    long            last_compile_start;
    pthread_t       thread;
}   t_coder;

typedef struct s_dongle
{
    pthread_mutex_t mutex;
    long            available_at;
}   t_dongle;

typedef struct s_data
{
	int			number_of_coders;
	int			time_to_burnout;
	int			time_to_compile;
	int			time_to_debug;
	int			time_to_refactor;
	int			number_of_compiles_required;
	int			dongle_cooldown;
	t_scheduler	scheduler;
	t_coder		*coders;
	t_dongle	*dongles;
}	t_data;

int	parse_arguments(int argc, char **argv, t_data *data);
int init_coders(t_data *data);
int init_dongles(t_data *data);

#endif
