
#ifndef CUBE_H
# define CUBE_H

# include <math.h>
//# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PP_HEIGHT 1000
# define PP_WIDTH 1600
# define UNIT 64
# define VIEW_D 60
# define PURPLE 0x9facb7
# define PINK 0x00406c
# define YELLOW 0xfafefd
# define BLACK 0x000000

enum
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3,
	DO = 4,
	F = 5,
	C = 6,
	ARROW_LEFT = 65361,
	ARROW_UP = 65362,
	ARROW_RIGHT = 65363,
	ARROW_DOWN = 65364,
	LEFT = 97,
	FIRE = 102,
	UP = 119,
	SPACE = 32,
	RIGHT = 100,
	DOWN = 115,
	DESTROY = 65307,
	SPEED = 30,
	MINI_UNIT = 15,
	WALL = 222,
};

typedef struct s_data
{
	char				*addr;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_wall
{
	double				x;
	double				y;
	double				step_x;
	double				step_y;
}						t_wall;

typedef struct s_ray
{
	float				alpha;
	float				ang;
	float				cast;
	int					d_x;
	int					d_y;
	double				distance;
	int					up;
	int					down;
	int					right;
	int					left;
	int					content;
}						t_ray;


typedef struct s_map
{
	char				**map;
	int					m_x;
	int					m_y;
	int					n_v;
	int					n_h;
	int					vert;
	float				wall_h;
	t_wall				h;
	t_wall				v;
	struct s_directions	*directions;
	struct s_textures	*textures;
}						t_map;

typedef struct s_textures
{
	int					h;
	int					w;
	int					*add;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	struct s_map		*map;
}						t_textures;

typedef struct s_directions
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	long long			f;
	long long			c;
	struct s_map		*map;
}						t_directions;


#endif