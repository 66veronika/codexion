/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vskopova <vskopova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:15:57 by vskopova          #+#    #+#             */
/*   Updated: 2026/11/17 17:06:34 by vskopova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "codexion.h"

int main(int argc, char **argv)
{
    t_data data;

    memset(&data, 0, sizeof(data));
    if (parse_arguments(argc, argv, &data) != 0)
        return (1);
    if (init_coders(&data) != 0)
        return (1);
    printf("Coder 1 ID: %d\n", data.coders[0].id);
    free(data.coders);
    return (0);
}
