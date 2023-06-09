/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:34:54 by davgarci          #+#    #+#             */
/*   Updated: 2023/03/14 18:22:07 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
# define CUBE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
#include "mlx.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

extern int worldmap[mapWidth][mapHeight];

typedef struct s_map {
	char	*dir;
	int		width;
	int		height;
	int		max_alt;
	int		**xyzc;
}	t_map;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		multiplicator;
	int		multi_z;
	int		win_w;
	int		win_h;
	int		size_x;
	int		size_y;
	double	posX;//= 22; 
	double	posY;//= 12;  //x and y start position
	double	dirX;//= -1;
	double	dirY;//= 0; //initial direction vector
	double	teta;
	double	planeX;// = 0;
	double	planeY;// = 0.66; //the 2d raycaster version of camera plane
	t_image	texN;
	t_image	texS;
	t_image	texE;
	t_image	texO;
	int			x;
	int			y;
	t_map map;
}	t_mlx;


void	fdf_init(t_mlx *mlx);
int	hook_exit(t_mlx *mlx);
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
int	ft_input(int keycode, t_mlx *mlx);
void raycasting(t_mlx *mlx);
void	vertical_texture(int x, int drawStart, int drawEnd, t_mlx	*mlx, int side, double rayDirX, double rayDirY, double pwd, int lineHeight);
void	draw_textures(int x, int drawStart, int drawEnd, t_mlx	*mlx, int side, double rayDirX, double rayDirY, int tex[], double pos[]);
#endif