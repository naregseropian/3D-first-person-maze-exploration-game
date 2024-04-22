#ifndef cub3D_H
# define cub3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"

#define WIN_WIDTH       720
#define WIN_HEIGHT      480
#define MAX_RGB         255
#define MIN_RGB         0
#define FAT             " \n"

# define NORTH 1
# define SOUTH 2
# define EAST 3
# define WEST 4

#define MALLOC_ERROR    1

typedef struct s_ray_data
{
    double      p_pos_x;
    double      p_pos_y;
    double      p_dir_x;
    double      p_dir_y;
    double      plane_x;
    double      plane_y;
    double      mov_s;
    double      rot_s;
	
    int		    curr_x;
    int		    map_x;
	int		    map_y;
	double	    cam_x;
	double	    rayx;
	double	    rayy;
	double	    sidex;
	double	    sidey;
	double	    deltax;
	double	    deltay;
	double	    perpwd;
	int		    step_x;
	int		    step_y;
	int		    hit;
	int		    side;
	int		    line_h;
	int		    dstart;
	int		    dend;
}              t_ray;

typedef struct	s_image_data 
{
	void	    *img_ptr;
	char	    *img;
	int		    bpp;
	int		    llen;
	int		    endian;
    int         h;
    int         w;
}			    t_img;

typedef struct	s_texture_data 
{
    int			texdir;
    double		wallx;
    int			texx;
    int			texy;
    double		step;
    double		texpos;
}			    t_t;

typedef struct s_mlx_data
{
    void        *mlx_connection;
    void        *mlx_window;
    int         window_height;
    int         window_width;
}              t_mlx;

typedef struct s_map_data
{
    char        **map;
    char        **cub;
    char        *temp;
    int         frgb[3];
    int         crgb[3];
    char        *no_path;
    char        *so_path;
    char        *ea_path;
    char        *we_path;
    int         map_height;
    int         isinmap;
    int         no_of_players;
    int         right;
    int         left;
    int         forwards;
    int         backwards;
    int         rot_right;
    int         rot_left;
    int         fd;
    int         count;
    char        *buff;
    t_img       t[4];
}              t_map;


typedef struct s_data
{
    t_mlx  mlx;
    t_map  map;
    t_ray  ray;
    t_img  img;
    t_t    t;
    int    eflag;
}              t_data;

//*** string_utils.c ***
int	    ft_isspace(int c);
int	    ft_count_commas(char *str);
int     ft_count_num(char *str);
int	    ft_isdigit(int c);
int     ft_isdigit_str(char *str);
int     ft_isspace_str(char *str);
int		ft_is_empty_line(char *str);

//*** libft_utils.c ***
int	    ft_strncmp(char *s1, char *s2, int n);
int	    ft_n_words(char *s, char c);
char	*ft_substr(char *s, int start, int len);
char	**ft_split(char *s, char c);
int 	ft_atoi(const char *nptr);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strdup(char *s);

//*** parser.c ***
void    ft_parse_cub(char *infile, t_data *data);
void    ft_parse_map(char *infile, t_data *data);

//*** get_colors.c ***
void    ft_get_colors(char *str, t_data *data);
void    ft_save_rgb(char *line, int *arr, t_data *data);

//*** get_textures.c ***
void    ft_get_textures(char *str, t_data *data);
void    ft_check_texture_file(char *infile, t_data *data);
char    *ft_get_path_texture(char *str, char *texture, t_data *data);

//*** get_map.c ***
void    ft_get_map(char *str, t_data *data);
int     ft_is_map(char *str, t_data *data);

//*** raycasting.c ***
int     ft_mlx(t_data *data);

//*** key_hooks.c***
int     handle_input(int keysym, t_data *data);
int     button_press(int button, int x, int y);
void    ft_right_left(t_data *data);

//*** checkers ***
int	    ft_check_argv(int ac, char **av);

//*** free.c ***
void	ft_free(char **arr);

//*** error.c ***
void	ft_error(t_data *data, char *error_msg);

//*** init.c ***
void    ft_init_s_data(t_data *data);

//*** main.c ***
void    ft_exit(t_data *data);

#endif
