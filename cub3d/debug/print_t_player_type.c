/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_t_player_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 10:22:09 by znajdaou          #+#    #+#             */
/*   Updated: 2025/08/30 11:24:47 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./debug.h"

void    print_t_player(t_player p)
{
	  printf("----------------------player info-------------------\n");
    printf("t_player {\n");
    printf("  size   : %d\n", p.size);
    printf("  dx     : %d\n", p.dx);
    printf("  dy     : %d\n", p.dy);
    printf("  dv     : %d\n", p.dv);
    printf("  dh     : %d\n", p.dh);
    printf("  angle  : %f\n", p.angle);
    printf("  speed  : %f\n", p.speed);
    printf("  sp_inc : %f\n", p.sp_inc);
    printf("  sp_max : %f\n", p.sp_max);
    printf("  sp_min : %f\n", p.sp_min);
    printf("  rs     : %f\n", p.rs);
    printf("  pitch  : %f\n", p.pitch);
    printf("  pos    : { x: %f, y: %f }\n", p.pos.x, p.pos.y);
    printf("}\n");
}
