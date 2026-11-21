#include "codexion.h"

int	init_simulation(t_data *data)
{
	data->stopped = 0;
	data->start_time = 0;
	if (pthread_mutex_init(&data->state_mutex, NULL) != 0)
		return (1);
	return (0);
}

void	cleanup_simulation(t_data *data)
{
	pthread_mutex_destroy(&data->state_mutex);
}

int	simulation_stopped(t_data *data)
{
	int	stopped;

	pthread_mutex_lock(&data->state_mutex);
	stopped = data->stopped;
	pthread_mutex_unlock(&data->state_mutex);
	return (stopped);
}

void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->state_mutex);
	data->stopped = 1;
	pthread_mutex_unlock(&data->state_mutex);
}

void	set_start_time(t_data *data)
{
	int		i;
	long	start;

	start = get_time_ms();
	pthread_mutex_lock(&data->state_mutex);
	data->start_time = start;
	i = 0;
	while (i < data->number_of_coders)
	{
		data->coders[i].last_compile_start = start;
		i++;
	}
	pthread_mutex_unlock(&data->state_mutex);
}
void	update_compile_time(t_data *data, t_coder *coder)
{
	pthread_mutex_lock(&data->state_mutex);
	coder->last_compile_start = get_time_ms();
	pthread_mutex_unlock(&data->state_mutex);
}
