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

    mlx = mlx_init();
    mlx_window = mlx_new_window(mlx, 1920, 1800, "Hello!");
    /*Inicia a imagem com determinado tamanho*/
    img.img = mlx_new_image(mlx, 1920, 1800);
    /*Obtem info da imagem apartir dos parametros passados*/
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    /*Penso que esta função sirva para ajustar o posição da imagem a janela
    tendo em conta o tamanho da imagem*/
    my_mlx_pixel_put(&img, 20, 20, 0x00FFFF00);
    /*Coloca a imagem na janela e indica a posição do eixo dos x e y em
    que esta se encontra*/
	mlx_put_image_to_window(mlx, mlx_window, img.img, 960, 540);
    mlx_loop(mlx);
    return (0);
}