/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dongle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vskopova <vskopova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:40:10 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/19 16:57:37 by vskopova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static void	destroy_dongles(t_data *data, int count);
void		cleanup_dongles(t_data *data);

static int	init_dongle(t_dongle *dongle)
{
	dongle->available_at = 0;
	if (pthread_mutex_init(&dongle->mutex, NULL) != 0)
		return (1);
	return (0);
}

int	init_dongles(t_data *data)
{
	int	i;

	data->dongles = malloc(sizeof(t_dongle) * data->number_of_coders);
	if (!data->dongles)
		return (1);
	i = 0;
	while (i < data->number_of_coders)
	{
		if (init_dongle(&data->dongles[i]) != 0)
		{
			destroy_dongles(data, i);
			return (1);
		}
		i++;
	}
	return (0);
}

static void	destroy_dongles(t_data *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&data->dongles[i].mutex);
		i++;
	}
	free(data->dongles);
	data->dongles = NULL;
}

void	cleanup_dongles(t_data *data)
{
	if (data->dongles)
		destroy_dongles(data, data->number_of_coders);
}
