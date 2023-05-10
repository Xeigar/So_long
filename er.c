/*int	get_b(int trgb)
{
	return (trgb & 0xFF);
}

int main (void)
{
    printf("%d", get_b(0xFF00000AF));
    return 0;
}*/

#include <mlx.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	key_hook(vars.win, 3, 1L<<1, close, &vars);
	mlx_loop(vars.mlx);
}
