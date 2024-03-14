#include "fract_ol.h"

void render(cr crr, t_complex *z, int x, int y, t_data *img)
{
    z->x = 0.0;
    z->y = 0.0;
    int j = -1;
    while (++j < img->max_iterations)
    {
        z->temp = z->x;
        z->x = (z->x * z->x) - (z->y * z->y) + crr.x; 
        z->y = 2 * z->temp * z->y + crr.y;
        if ((z->x * z->x + z->y * z->y) > 4)
        {
            my_mlx_pixel_put(img, x, y, scale_number(j, img->max_iterations, 0, 0x000000, 0xFFFFFF));
            return;
        }
    }
    my_mlx_pixel_put(img, x, y, 0xFFFFFF);
}

void render_mandelbrot(t_data *param )
{
    param->img = mlx_new_image(param->mlx, 500 * param->zoom_factor, 500* param->zoom_factor);
    param->addr = mlx_get_data_addr(param->img, &param->bits_per_pixel, &param->line_length, &param->endian);

    for (int y = 0; y < 500 * param->zoom_factor; y++) {
        for (int x = 0; x < 500 * param->zoom_factor; x++) {
            cr t_cr;
            t_complex t_complex;
            t_cr.x = scale_number(x, 500* param->zoom_factor  , 0, 2, -2) + param->x_shift;
            t_cr.y = scale_number(y, 0, 500* param->zoom_factor  , -2, 2) + param->y_shift;
            //render_mandelbrot(t_cr, &t_complex, x, y, param);
            render(t_cr, &t_complex, x, y, param);
        }
    }



}