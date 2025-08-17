/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 14:06:32 by znajdaou          #+#    #+#             */
/*   Updated: 2025/07/07 14:06:36 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/events.h"

int	ft_destroy_event(t_data *data)
{
	ft_handle_window_exit(data, ERR_SUCCESS);
	return (0);
}
