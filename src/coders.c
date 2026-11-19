/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veronikaskopova <veronikaskopova@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:04:45 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/18 12:50:52 by veronikasko      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int init_coders(t_data *data)
{
    int i;

    data->coders = malloc(sizeof(t_coder) * data->number_of_coders);
    if (!data->coders)
        return (1);
    i = 0;
    while (i < data->number_of_coders)
    {
        data->coders[i].id = i + 1;
        data->coders[i].compiles_done = 0;
        data->coders[i].last_compile_start = 0;
        i++;
    }
    return (0);
}
