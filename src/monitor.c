/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vskopova <vskopova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:10:56 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/19 16:44:42 by vskopova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

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
