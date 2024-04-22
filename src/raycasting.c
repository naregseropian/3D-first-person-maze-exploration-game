/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szalazar <szalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:36:17 by cb                #+#    #+#             */
/*   Updated: 2024/03/10 11:58:57 by szalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	handle_key_press(int key, t_data *data)
{
    if (key == 65307)
    {
        mlx_destroy_window(data->mlx.mlx_connection, data->mlx.mlx_window);
        ft_error(data, "You've pressed Esc\n");
        mlx_destroy_display(data->mlx.mlx_connection);
        free(data->mlx.mlx_connection);
    }
    if (key == 100)
		data->map.right = 1;
    if (key == 97)
        data->map.left = 1;
    if (key == 119)
        data->map.forwards = 1;
    if (key == 115)
        data->map.backwards = 1;
    if (key == 65363)
        data->map.rot_right = 1;
    if (key == 65361)
        data->map.rot_left = 1;
    return (0);
}

int	handle_key_release(int key, t_data *data)
{
    if (key == 100)
        data->map.right = 0;
    if (key == 97)
        data->map.left = 0;
    if (key == 119)
        data->map.forwards = 0;
    if (key == 115)
        data->map.backwards = 0;
    if (key == 65363)
        data->map.rot_right = 0;
    if (key == 65361)
        data->map.rot_left = 0;
    return (0);
}

int encode_rgb(int *rgb)
{
    return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.img + (y * data->img.llen + x * (data->img.bpp / 8));
	*(unsigned int*)dst = color;
}

void    ft_right(t_data *data)
{
    if (data->map.map[(int) data->ray.p_pos_y]
                            [(int)(data->ray.p_pos_x + data->ray.plane_x * ceil(data->ray.mov_s))] != '1')
        data->ray.p_pos_x += data->ray.plane_x * data->ray.mov_s;
    if (data->map.map[(int)(data->ray.p_pos_y + data->ray.plane_y * ceil(data->ray.mov_s))]
                            [(int)(data->ray.p_pos_x)] != '1')
        data->ray.p_pos_y += data->ray.plane_y *data->ray.mov_s;
}

void    ft_left(t_data *data)
{
    if (data->map.map[(int) data->ray.p_pos_y]
                            [(int)(data->ray.p_pos_x - data->ray.plane_x * ceil(data->ray.mov_s))] != '1')
        data->ray.p_pos_x -= data->ray.plane_x * data->ray.mov_s;
    if (data->map.map[(int)(data->ray.p_pos_y - data->ray.plane_y * ceil(data->ray.mov_s))]
                            [(int)(data->ray.p_pos_x)] != '1')
        data->ray.p_pos_y -= data->ray.plane_y *data->ray.mov_s;
}

void    ft_forwards(t_data *data)
{
    if (data->map.map[(int) data->ray.p_pos_y]
                            [(int)(data->ray.p_pos_x + data->ray.p_dir_x * ceil(data->ray.mov_s))] != '1')
        data->ray.p_pos_x += data->ray.p_dir_x * data->ray.mov_s;
    if (data->map.map[(int)(data->ray.p_pos_y + data->ray.p_dir_y * ceil(data->ray.mov_s))]
                            [(int)(data->ray.p_pos_x)] != '1')
        data->ray.p_pos_y += data->ray.p_dir_y * data->ray.mov_s;
}

void    ft_backwards(t_data *data)
{
    if (data->map.map[(int) data->ray.p_pos_y]
                            [(int)(data->ray.p_pos_x - data->ray.p_dir_x * ceil(data->ray.mov_s))] != '1')
        data->ray.p_pos_x -= data->ray.p_dir_x * data->ray.mov_s;
    if (data->map.map[(int)(data->ray.p_pos_y - data->ray.p_dir_y * ceil(data->ray.mov_s))]
                            [(int)(data->ray.p_pos_x)] != '1')
        data->ray.p_pos_y -= data->ray.p_dir_y *data->ray.mov_s;
}

void    ft_rot_right(t_data *data)
{
    double  og_dirx;
    double  og_planex;
    double  sens;

    og_dirx = data->ray.p_dir_x;
    og_planex = data->ray.plane_x;
    sens = data->ray.rot_s;
    data->ray.p_dir_x = data->ray.p_dir_x * cos(sens) - data->ray.p_dir_y * sin(sens);
    data->ray.p_dir_y = og_dirx * sin(sens) + data->ray.p_dir_y * cos(sens);
    data->ray.plane_x = data->ray.plane_x * cos(sens) - data->ray.plane_y * sin(sens);
    data->ray.plane_y = og_planex * sin(sens) + data->ray.plane_y * cos(sens);
}

void    ft_rot_left(t_data *data)
{
    double  og_dirx;
    double  og_planex;

    og_dirx = data->ray.p_dir_x;
    og_planex = data->ray.plane_x;
    data->ray.p_dir_x = data->ray.p_dir_x * cos(-data->ray.rot_s) - data->ray.p_dir_y * sin(-data->ray.rot_s);
    data->ray.p_dir_y = og_dirx * sin(-data->ray.rot_s) + data->ray.p_dir_y * cos(-data->ray.rot_s);
    data->ray.plane_x = data->ray.plane_x * cos(-data->ray.rot_s) - data->ray.plane_y * sin(-data->ray.rot_s);
    data->ray.plane_y = og_planex * sin(-data->ray.rot_s) + data->ray.plane_y * cos(-data->ray.rot_s);
}

void    ft_event(t_data *data)
{
    if (data->map.right == 1)
    {
        ft_right(data);
    }
    if (data->map.left == 1)
    {
        ft_left(data);
    }
    if (data->map.forwards == 1)
    {
        ft_forwards(data);
    }
    if (data->map.backwards == 1)
    {
        ft_backwards(data);
    }
    if (data->map.rot_right == 1)
    {
        ft_rot_right(data);
    }
    if (data->map.rot_left == 1)
    {
        ft_rot_left(data);
    }
}

void    ft_init_texture(t_data *data)
{
    if (data->ray.side == 0 && data->ray.rayx < 0)
        data->t.texdir = 2;  // WEST
    if (data->ray.side == 0 && data->ray.rayx >= 0)
        data->t.texdir = 3;  // EAST
    if (data->ray.side == 1 && data->ray.rayy < 0)
        data->t.texdir = 0;  //SOUTH
    if (data->ray.side == 1 && data->ray.rayy >= 0)
        data->t.texdir = 1;  //NORTH
    if (data->ray.side == 0)
        data->t.wallx = data->ray.p_pos_y + data->ray.perpwd * data->ray.rayy;
    else
        data->t.wallx = data->ray.p_pos_x + data->ray.perpwd * data->ray.rayx;
    data->t.wallx -= floor((data->t.wallx));
}

void    ft_draw_texture(t_data *data, int x, int y)
{
    int scale;

    y = data->ray.dstart - 1;
    ft_init_texture(data);
    data->t.texx = (int)(data->t.wallx * (double)data->map.t[data->t.texdir].w);
    if (data->ray.side == 0 && data->ray.rayx > 0)
        data->t.texx = data->map.t[data->t.texdir].w - data->t.texx - 1;
    else if (data->ray.side == 1 && data->ray.rayy < 0)
        data->t.texx = data->map.t[data->t.texdir].w - data->t.texx - 1;
    while (++y <= data->ray.dend)
    {
        scale = y * data->map.t[data->t.texdir].llen - WIN_HEIGHT * 
                    data->map.t[data->t.texdir].llen / 2 + data->ray.line_h * data->map.t[data->t.texdir].llen / 2;
        data->t.texy = ((scale * data->map.t[data->t.texdir].h) / data->ray.line_h) / data->map.t[data->t.texdir].llen;
        data->img.img[y * data->img.llen + x * data->img.bpp / 8] = 
                                    data->map.t[data->t.texdir].img[data->t.texy * data->map.t[data->t.texdir].llen
                                        + data->t.texx * (data->map.t[data->t.texdir].bpp / 8)];
        data->img.img[y * data->img.llen + x * (data->img.bpp / 8) + 1] = 
                                    data->map.t[data->t.texdir].img[data->t.texy * data->map.t[data->t.texdir].llen
                                        + data->t.texx * (data->map.t[data->t.texdir].bpp / 8) + 1];
        data->img.img[y * data->img.llen + x * (data->img.bpp / 8) + 2] = 
                                    data->map.t[data->t.texdir].img[data->t.texy * data->map.t[data->t.texdir].llen
                                        + data->t.texx * (data->map.t[data->t.texdir].bpp / 8) + 2];
    }
}       

void    ft_preparation(t_data *data)
{
    data->ray.cam_x = 2 * data->ray.curr_x / (double) WIN_WIDTH - 1;
    data->ray.rayx = data->ray.p_dir_x + data->ray.plane_x * data->ray.cam_x;
    data->ray.rayy = data->ray.p_dir_y + data->ray.plane_y * data->ray.cam_x;
    data->ray.map_x = (int) data->ray.p_pos_x;
    data->ray.map_y = (int) data->ray.p_pos_y;
    if (data->ray.rayx == 0)
        data->ray.deltax = 1e30;
    else
        data->ray.deltax = fabs(1 / data->ray.rayx);
    if (data->ray.rayy == 0)
        data->ray.deltay = 1e30;
    else
        data->ray.deltay = fabs(1 / data->ray.rayy);
    data->ray.hit = 0;
}

void    ft_determine_step(t_data *data)
{
    if (data->ray.rayx < 0)
    {
        data->ray.step_x = -1;
        data->ray.sidex = (data->ray.p_pos_x - data->ray.map_x) * data->ray.deltax;
    }
    else
    {
        data->ray.step_x = 1;
        data->ray.sidex = (data->ray.map_x + 1.0 - data->ray.p_pos_x) * data->ray.deltax;
    }
    if (data->ray.rayy < 0)
    {
        data->ray.step_y = -1;
        data->ray.sidey = (data->ray.p_pos_y - data->ray.map_y) * data->ray.deltay;
    }
    else
    {
        data->ray.step_y = 1;
        data->ray.sidey = (data->ray.map_y + 1.0 - data->ray.p_pos_y) * data->ray.deltay;
    }
}

void    ft_dda(t_data *data)
{
    while (data->ray.hit == 0)
    {
        if (data->ray.sidex < data->ray.sidey)
        {
            data->ray.sidex += data->ray.deltax;
            data->ray.map_x += data->ray.step_x;
            data->ray.side = 0;
        }
        else
        {
            data->ray.sidey += data->ray.deltay;
            data->ray.map_y += data->ray.step_y;
            data->ray.side = 1;
        }
        if (data->map.map[data->ray.map_y][data->ray.map_x] == '1')
            data->ray.hit = 1;
    }
}

void    ft_calculate_dist(t_data *data)
{
    if (data->ray.side == 0)
    data->ray.perpwd = ((double) data->ray.map_x - data->ray.p_pos_x
                            + (1 - data->ray.step_x) / 2) / data->ray.rayx;
    else
        data->ray.perpwd = ((double) data->ray.map_y - data->ray.p_pos_y
                                + (1 - data->ray.step_y) / 2) / data->ray.rayy;
    data->ray.line_h = WIN_HEIGHT / data->ray.perpwd;
    data->ray.dstart = -data->ray.line_h / 2 + WIN_HEIGHT / 2;
    if (data->ray.dstart <= 0)
        data->ray.dstart = 0;
    data->ray.dend = (data->ray.line_h / 2) + (WIN_HEIGHT / 2);
    if (data->ray.dend >= WIN_HEIGHT)
        data->ray.dend = WIN_HEIGHT - 1;
}

void    ft_draw_pixel(t_data *data)
{
    int j;
    int i;

    j = -1;
    data->ray.dend = WIN_HEIGHT - data->ray.dstart;
    i = data->ray.dend;
    while (++j < data->ray.dstart)
        my_mlx_pixel_put(data,
                        data->ray.curr_x,
                        j,
                        encode_rgb(data->map.crgb));
    if (j <= data->ray.dend)
        ft_draw_texture(data, data->ray.curr_x, j);
    j = i;
    while (++j < WIN_HEIGHT)
        my_mlx_pixel_put(data,
                        data->ray.curr_x,
                        j,
                        encode_rgb(data->map.frgb));
}

int ft_render(t_data *data)
{
    data->ray.curr_x = 0;
    while (data->ray.curr_x < WIN_WIDTH)
    {
        // *** init ***
        ft_preparation(data);
        // *** determine step ***
        ft_determine_step(data);
        // *** perform dda ***
        ft_dda(data);
        // *** calculate shortest dst ***
        ft_calculate_dist(data);
        // *** draw pixel ***
        ft_draw_pixel(data);
        data->ray.curr_x++;
    }
    mlx_put_image_to_window(data->mlx.mlx_connection, data->mlx.mlx_window, data->img.img_ptr, 0, 0);
    ft_event(data);
    return (0);
}

void    ft_get_texture_add(t_data *data)
{
    data->map.t[0].img = mlx_get_data_addr(data->map.t[0].img_ptr,
                            &data->map.t[0].bpp,
                            &data->map.t[0].llen,
                            &data->map.t[0].endian);
    
    data->map.t[1].img = mlx_get_data_addr(data->map.t[1].img_ptr,
                                                                        &data->map.t[1].bpp,
                                                                        &data->map.t[1].llen,
                                                                        &data->map.t[1].endian);
    
    data->map.t[2].img = mlx_get_data_addr(data->map.t[2].img_ptr,
                                                                        &data->map.t[2].bpp,
                                                                        &data->map.t[2].llen,
                                                                        &data->map.t[2].endian);
    
    data->map.t[3].img = mlx_get_data_addr(data->map.t[3].img_ptr,
                                                                        &data->map.t[3].bpp,
                                                                        &data->map.t[3].llen,
                                                                        &data->map.t[3].endian);
}

void    ft_get_texture(t_data *data)
{
    if (!(data->map.t[0].img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_connection,
                                                                    data->map.no_path,
                                                                    &(data->map.t[0].w),
                                                                    &(data->map.t[0].h))))
        ft_error(data, "Error\nNO Texture\n");
    if (!(data->map.t[1].img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_connection,
                                                                data->map.so_path,
                                                                &(data->map.t[1].w),
                                                                &(data->map.t[1].h))))
        ft_error(data, "Error\nSO Texture\n");
    if (!(data->map.t[2].img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_connection,
                                                                data->map.we_path,
                                                                &(data->map.t[2].w),
                                                                &(data->map.t[2].h))))
        ft_error(data, "Error\nWE Texture\n");
    if (!(data->map.t[3].img_ptr = mlx_xpm_file_to_image(data->mlx.mlx_connection,
                                                                data->map.ea_path,
                                                                &(data->map.t[3].w),
                                                                &(data->map.t[3].h))))
        ft_error(data, "Error\nEA Texture\n");
    ft_get_texture_add(data);
}

int ft_mlx(t_data *data)
{
    data->mlx.mlx_connection = mlx_init();
    if (NULL == data->mlx.mlx_connection)
        return (MALLOC_ERROR);
    data->map.t[0].img_ptr = NULL;
	data->map.t[1].img_ptr = NULL;
	data->map.t[2].img_ptr = NULL;
	data->map.t[3].img_ptr = NULL;
    ft_get_texture(data);
    data->mlx.mlx_window = mlx_new_window(data->mlx.mlx_connection,
                    WIN_WIDTH,
                    WIN_HEIGHT,
                    "cub3D");
    if (NULL == data->mlx.mlx_window)
    {
        mlx_destroy_display(data->mlx.mlx_connection);
        free(data->mlx.mlx_connection);
        return (MALLOC_ERROR);
    }
    data->img.img_ptr = mlx_new_image(data->mlx.mlx_connection, WIN_WIDTH, WIN_HEIGHT);
    data->img.img = mlx_get_data_addr(data->img.img_ptr,
                &data->img.bpp,
                &data->img.llen,
                &data->img.endian);

    mlx_hook(data->mlx.mlx_window, 2, 1L << 0, handle_key_press, data);
	mlx_hook(data->mlx.mlx_window, 3, 1L << 1, handle_key_release, data);
    mlx_loop_hook(data->mlx.mlx_connection, ft_render, data);

    mlx_hook(data->mlx.mlx_window, 17, 0, (void *)exit, 0);

    mlx_loop(data->mlx.mlx_connection);
    mlx_destroy_window(data->mlx.mlx_connection, data->mlx.mlx_window);
    mlx_destroy_display(data->mlx.mlx_connection);
    free(data->mlx.mlx_connection);
    return (0);
}
