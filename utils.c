#include <stdio.h>
#include "fract_ol.h"
#include <stdlib.h>
#include <math.h>

int ft_strcmp(char *str , char *str2)
{ 
    while (*str == *str2 && !*str && !*str2){
        str++;
        str2++;
    }
    return *str - *str2;
}
void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

double scale_number(double num, double old_max, double old_min, double new_max, double new_min)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

int test(int keycode , t_data *param)
{
    if (keycode == 65307) {
        free(param->mlx);
        mlx_clear_window(param->mlx, param->win);
        mlx_destroy_window(param->mlx, param->win);
        exit(1);
    }
    if (keycode == 65363)
        param->x_shift +=0.5;
    else if(keycode == 65361)
        param->x_shift -=0.5;
     else if(keycode == 65362)
        param->y_shift -=0.5;
     else if(keycode == 65364)
        param->y_shift +=0.5;
    else if(keycode == 65451)
        param->max_iterations+=15;
        else if(keycode == 65453)
        param->max_iterations-=15;
    

    if(!ft_strcmp(param->name,"mandelbrot"))
        render_mandelbrot(param);
    else
    render_julia(param);

     mlx_clear_window(param->mlx, param->win);
    mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);

 
    return 0;
}

double  ft_atoi(char *nmbr)
{
    int signe = 1;
    int result = 0;
    double  part_fract = 0.0;
    double flotant_part = 0.1;
    while (*nmbr == ' ' || *nmbr == '\t')
        nmbr++;
    if(*nmbr == '-')
    {
        signe*=-1;
        nmbr++;
    }
    while (*nmbr && *nmbr!= '.')
    {
        result =  (result * 10) + (*nmbr-48);
        nmbr++;
    }
    if(*nmbr == '.')
    {
        nmbr++;
    while(*nmbr)
    {
        part_fract += ((*nmbr-48) * flotant_part);
        flotant_part *=0.1;
        nmbr++;
    }
    }
    // printf("the value inside function is %d \n ",result);
    return signe * (result + part_fract) ;
    
}
void init_data(t_data *param)
{
    param->max_iterations = 42;
    param->mlx = mlx_init();
    param->win = mlx_new_window(param->mlx, 500, 500, "Hello world!");
    param->img_width = 500;
    param->img_height = 500;
    param->zoom_factor = 1.0;
    param->img = mlx_new_image(param->mlx, param->img_width, param->img_height);
    param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->line_length, &param->endian);
}

void check_args(int argc , char **argv, t_data *img)
{
    if (argc == 2 && !ft_strcmp(argv[0],"mandelbrot"))
    {
		img->name = "mandelbrot";
		render_mandelbrot(img);
    }
    else if (argc == 2 && !ft_strcmp(argv[0],"julia") )
    {
            img->name = "julia";
            img->c_reel = -0.745429;
            img->imaginary = 0.05;
            render_julia(img);
    }
     
        else if(argc == 4 && !ft_strcmp(argv[0],"julia"))
        {
            img->name = "julia";
            img->c_reel = ft_atoi(argv[1]);
            img->imaginary = ft_atoi(argv[2]);
            render_julia(img);
        }

    else
    {
        printf("please enter mandelbrot or julia \n");
        exit(1);
    }
}


int mouse_hook(int keycode ,int x, int y,t_data *param)
{
    if(keycode == 4)
    {
     printf("button pressed %d at the position %d %d \n",keycode , x , y);
        param->zoom_factor*=1.2;
    }
    if(!ft_strcmp(param->name,"mandelbrot"))
        render_mandelbrot(param);
    else
    render_julia(param);

     mlx_clear_window(param->mlx, param->win);
    mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);


    return 0;
}
