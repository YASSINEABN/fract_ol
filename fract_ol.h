#ifndef FRACT_OLV2
#define FRACT_OLV2
#include "mlx/mlx.h"

typedef struct s_data {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     img_width;
    int     img_height;
    double  x_shift;
    double  y_shift;
    char *name;
    double c_reel;
    double imaginary;
    double zoom_factor;
    int max_iterations;
} t_data;

typedef struct s_complex {
    double x;
    double y;
    double temp;
} t_complex;

typedef struct s_coordinate {
    double x;
    double y;
} cr;

typedef struct fract
{
    double shift_x;
    double shift_y;
    char *name;
}fr;


int ft_strcmp(char *str , char *str2);
void my_mlx_pixel_put(t_data *data, int x, int y, int color);
double scale_number(double num, double old_max, double old_min, double new_max, double new_min);
void render(cr crr, t_complex *z, int x, int y, t_data *img);
void render_mandelbrot(t_data *param );
void renderjul( t_complex *z, double x, double y, t_data *img);
void render_julia(t_data *param);
int test(int keycode , t_data *param);
double ft_atoi(char *nmbr);
int mouse_hook(int keycode ,int x, int y,t_data *param);
void init_data(t_data *param);
void check_args(int argc , char **argv, t_data *img);



#endif
