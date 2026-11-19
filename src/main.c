/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vskopova <vskopova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:15:57 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/19 17:39:05 by vskopova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(data));
	if (parse_arguments(argc, argv, &data) != 0)
		return (1);
	if (init_coders(&data) != 0)
		return (1);
	if (init_dongles(&data) != 0)
	{
		free(data.coders);
		return (1);
	}
	printf("Initialization successful\n");
	cleanup_dongles(&data);
	free(data.coders);
	printf("Freed space\n");
	return (0);
}
