/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2d_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 11:04:53 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/17 11:52:53 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./debug.h"

void print_2d_array(int **arr, int r, int c)
{
    
    if (!arr)
    {
        printf("NULL\n");
        return;
    }

    for (int i = 0; i < r; i++)
    {
        printf("{ ");
        for (int j = 0; j < c; j++) // sentinel inside each row
        {
            printf("%d", arr[i][j]);    
            if (j + 1 < c)
                printf(", ");
        }
        printf(" }\n");
    }
}
