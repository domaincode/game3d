#ifndef GAME_H
#define GAME_H

#include "../parsing/includes/structs.h"
#include "../parsing/includes/parse_map.h"
#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"


#define HEIGHT 1200
#define WIDTH  1200
#define MAP_SIZE 8
#define TILE_SIZE 32
#define pi 3.14159265
#define RES 1
#define RAYS WIDTH / RES

typedef struct s_text
{
    char* north;
    char* south;
    char* west;
    char* east;
} t_text;

typedef struct s_my_map
{
    char** data;
    int rows;
    int cols;
    int y_max;
    int x_max;
    
}t_my_map;

typedef struct s_player
{
    int px;
    int py;
    double fov;
    double rot;
    double ray_angle_start;
    double ray_angle;
}t_player;

typedef struct s_my_game
{
    t_game* old_game;
    t_xvar* co;
    t_win_list* win;
    t_player player;
    t_my_map map;
    t_text textures;

    int floor_color;
    int ceiling_color;

    t_img* img;
    t_img* test;

    t_img* north;
    t_img* south;
    t_img* west;
    t_img* east;

} t_my_game;

int make_grid(t_img* img, int color);
void draw_line(t_my_game* game, int x_end, int y_end, int color);
void clor_ceiling_floor(t_my_game* game, int y_start, int y_end, int x_start, int color);
void draw_square(t_img* image, int color, int posx, int posy, int surface);
void draw_map(t_my_game* game);
void ft_cast(t_my_game* game, int color);
void draw_fov(t_my_game* game, int color);


char *get_next_line(int fd);

void map_configuration(t_my_game* game, char** data);
double normalize_angle(double angle);


int free_game(t_my_game* game, t_game* old_game);
int color(int r, int g, int b);
int get_pixel(t_img *image, int x, int y);
void my_pixel_put(t_img* image, int x, int y, int color);
void set_player_position(t_my_game* game);
int check_wall(t_my_game* game, int x, int y);
void map_configuration(t_my_game* game, char** data);


int cub_init(t_my_game* game);
void check_intersections(t_my_game* game);
void facing_up(t_my_game* game, double* ay, double* YA, double ray_angle);
void facing_left(t_my_game* game, double* ax, double* XA, double ray_angle);
void ft_textures(t_my_game* game, int projected_x_start, int texture_x, double projected_height);
void ft_execution(t_my_game* game);


#endif