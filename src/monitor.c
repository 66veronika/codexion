/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vskopova <vskopova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:10:56 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/21 20:47:51 by vskopova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	coder_burned_out(t_data *data, t_coder *coder);

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (!simulation_stopped(data))
	{
		i = 0;
		while (i < data->number_of_coders)
		{
			if (coder_burned_out(data, &data->coders[i]))
			{
				stop_simulation(data);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}

static int	coder_burned_out(t_data *data, t_coder *coder)
{
	long	now;
	long	last_compile;

	pthread_mutex_lock(&data->state_mutex);
	last_compile = coder->last_compile_start;
	pthread_mutex_unlock(&data->state_mutex);
	now = get_time_ms();
	if (now - last_compile >= data->time_to_burnout)
		return (1);
	return (0);
}

long	get_time_ms(void)
{
	struct timespec	ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0)
		return (-1);
	return (ts.tv_sec * 1000L + ts.tv_nsec / 1000000L);
}