#include <stdio.h>
#include <unistd.h>
#include "mlx/mlx.h"
#include "fract_ol.h"
#include <stdlib.h>

int main(int argc , char **argv)
{
    t_data  img;
    
    init_data(&img);
	check_args(argc ,argv+1 ,&img);

 	mlx_key_hook(img.win, test, &img);
    mlx_mouse_hook(img.win, mouse_hook, &img);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
    mlx_loop(img.mlx);
	        free(img.mlx);

}

