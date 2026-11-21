/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coder.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vskopova <vskopova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 21:01:33 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/21 21:01:38 by vskopova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

void	*coder_routine(void *arg)
{
	t_coder	*coder;

	coder = (t_coder *)arg;
	while (/* simulation is running */)
	{
		/* Request permission from FIFO/EDF scheduler */
		/* Wait until both dongles are available */
		/* Start compiling */
		/* Debug */
		/* Refactor */
	}
	return (NULL);
}