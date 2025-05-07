#ifndef STRUCTS_H
#define STRUCTS_H

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define MOVE_SPEED 0.06
#define ROT_SPEED 0.1
#define MAP_WIDTH 64
#define MAP_HEIGHT 24

// typedef struct s_img
// {
// 	void		*img_ptr;
// 	int			*map;
//     char        *addr;         
//     int         bits_per_pixel;
//     int         line_length;   
//     int         endian;        
// }				t_img;


typedef struct s_resolution
{
	long long	width;
	long long	height;
}				t_resolution;

typedef struct s_texture
{
	char		*path;
	t_img		img;
	int			width;
	int			height;
}				t_texture;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	int			x;
	int			y;
	char		direction;
}				t_map;

typedef struct s_field
{
	t_resolution		res;
	t_texture	no_tex;
	t_texture	so_tex;
	t_texture	we_tex;
	t_texture	ea_tex;
	t_color		floor;
	t_color		ceilling;
	t_map		*map;
}				t_field;

typedef struct s_game
{
	t_field		*field;
}	t_game;

void free_all(t_field *field, t_map *map);

#endif