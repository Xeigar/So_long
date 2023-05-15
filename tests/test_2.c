#include <mlx.h>

typedef struct s_data
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
    int		h;
	int		w;
	int		endian;
}				t_data;


int main (void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    char    *relative_path = "./spider.xpm";
    int		img_width;
	int		img_height;

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1800, "Hello!");
    img.img = mlx_xpm_file_to_image(mlx, relative_path, &img.w, &img.h);
    printf("%i", img.bits_per_pixel);
    img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
    //img.w = 20;
    //img.h = 20;
    printf("Let's Find out what's inside our structure :D\n");
	printf("img_ptr		: [%p]\n", img.img);
	printf("bpp		: [%d]\n", img.bits_per_pixel);
	printf("line_len	: [%d]\n", img.line_length);
	printf("endian		: [%d]\n", img.endian);
	printf("addr		: [%p]\n", img.addr);
    mlx_put_image_to_window(mlx, mlx_window, img.img, 250, 250);
    mlx_loop(mlx);
    return (0);
}