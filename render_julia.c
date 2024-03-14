#include "fract_ol.h"

void renderjul( t_complex *z, double x, double y, t_data *img)
{
    double c_real = (img->c_reel )+ img->x_shift; 
    double c_imaginary = (img->imaginary ) + img->y_shift; 

    z->x = scale_number(x, img->img_width * img->zoom_factor, 0, 2, -2);
    z->y = scale_number(y, 0, img->img_height * img->zoom_factor, -2, 2);

    int j = -1;
    while (++j < img->max_iterations)
    {
        z->temp = z->x;
        z->x = (z->x * z->x) - (z->y * z->y) + c_real;
        z->y = 2 * z->temp * z->y + c_imaginary;
        if ((z->x * z->x + z->y * z->y) > 4)
        {
            my_mlx_pixel_put(img, x, y, scale_number(j, img->max_iterations, 0, 0x000000, 0xFFFFFF));
            return;
        }
    }
}


void render_julia(t_data *param)
{
    param->img = mlx_new_image(param->mlx,500 * param->zoom_factor, 500* param->zoom_factor);
    param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->line_length, &param->endian);

    for (int y = 0; y < 500*param->zoom_factor  ; y++) {
        for (int x = 0; x < 500*param->zoom_factor ; x++) {
            t_complex t_complex;
            //render_mandelbrot(t_cr, &t_complex, x, y, param);
            renderjul(&t_complex, x , y, param);
        }
    }



}