/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veronikaskopova <veronikaskopova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:15:49 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/14 19:53:58 by veronikasko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

static int	is_valid_scheduler(char *str);
static int	validate_arguments(char **argv);
static void	assign_arguments(char **argv, t_data *data);
static int	is_valid_number(char *str);

int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc != 9)
	{
		fprintf(stderr, "Error: expected 8 arguments\n");
		return (1);
	}
	if (!validate_arguments(argv))
		return (1);
	assign_arguments(argv, data);
	if (data->number_of_coders == 0)
		return (fprintf(stderr, "Error: expected at least one coder\n"), 1);
	return (0);
}

static int	is_valid_scheduler(char *str)
{
	if (strcmp(str, "fifo") == 0)
		return (1);
	if (strcmp(str, "edf") == 0)
		return (1);
	fprintf(stderr, "Error: invalid scheduler\n");
	return (0);
}

static int	validate_arguments(char **argv)
{
	if (!is_valid_scheduler(argv[8]))
		return (0);
	if (!is_valid_number(argv[1]) || !is_valid_number(argv[2]))
		return (0);
	if (!is_valid_number(argv[3]) || !is_valid_number(argv[4]))
		return (0);
	if (!is_valid_number(argv[5]) || !is_valid_number(argv[6]))
		return (0);
	if (!is_valid_number(argv[7]))
		return (0);
	return (1);
}

static int	is_valid_number(char *str)
{
	int	i;
	int	num;

	if (!str || str[0] == '\0')
		return (fprintf(stderr, "Error: argument is empty\n"), 0);
	i = 0;
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (fprintf(stderr, "Error: argument is not an integer\n"), 0);
		if (num > (INT_MAX - (str[i] - '0')) / 10)
			return (fprintf(stderr, "Number is too large\n"), 0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (1);
}

static void	assign_arguments(char **argv, t_data *data)
{
	data->number_of_coders = atoi(argv[1]);
	data->time_to_burnout = atoi(argv[2]);
	data->time_to_compile = atoi(argv[3]);
	data->time_to_debug = atoi(argv[4]);
	data->time_to_refactor = atoi(argv[5]);
	data->number_of_compiles_required = atoi(argv[6]);
	data->dongle_cooldown = atoi(argv[7]);
	if (strcmp(argv[8], "fifo") == 0)
		data->scheduler = FIFO;
	else
		data->scheduler = EDF;
}
