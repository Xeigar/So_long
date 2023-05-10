#include <mlx.h>

typedef struct s_data
{
    void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

/*Esta função permite estabelecer os valores de transparencia, vermelho
verde e azul.*/
int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}


int main (void)
{
    void    *mlx;
    void    *mlx_window;
    t_data  img;
    char    *relative_path = "./untitled.xpm";
    int		img_width;
	int		img_height;

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1800, "Hello!");
    /*Inicia a imagem com determinado tamanho*/
    img.img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    mlx_put_image_to_window(mlx, mlx_window, img.img, 1, 1);
    mlx_loop(mlx);
    return (0);
}