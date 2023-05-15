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
#include <stdio.h>
#include <unistd.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	doing(int keycode, t_vars *vars)
{
	if ( keycode == 65307)
	{
		//printf("%d\n", keycode);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_loop_end(vars->mlx);
	}
	else
		ft_putchar('X');
	return (keycode);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, doing, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
