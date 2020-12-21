/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vincentbaron <vincentbaron@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:46:54 by vincentbaro       #+#    #+#             */
/*   Updated: 2020/12/21 17:36:59 by vincentbaro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void affiliate_texture(t_general *mother, t_img *img, t_text *texture)
{
    if (texture->RGB[0] != -1)
        img->color = (texture->RGB[0] << 16) + (texture->RGB[1] << 8) + texture->RGB[2];
    else
    {
        img->color = 0;
        create_texture(mother, texture);
    }
}

void    define_wall_color(t_general *mother)
{
    if (check_charset(mother->args.matrix[mother->dda.map.y][mother->dda.map.x], "12") != -1)
    {
        if (mother->dda.side_pos == 1)
            (mother->gps.ray.y < 0) ? affiliate_texture(mother, &(mother->mlx.img_ray), &(mother->args.NO)) : affiliate_texture(mother, &(mother->mlx.img_ray), &(mother->args.SO)); 
        else if (mother->dda.side_pos == 0)
        {
            (mother->gps.ray.x < 0) ? affiliate_texture(mother, &(mother->mlx.img_ray), &(mother->args.WE)) : affiliate_texture(mother, &(mother->mlx.img_ray), &(mother->args.EA));
            mother->mlx.img_ray.color /= 2;
        }
    }
}