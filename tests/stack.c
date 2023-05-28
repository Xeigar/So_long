void	b_map(w_vars *win)
{
	int	i;
	int j;
	char	*p = "./sprites/walls/wall_right.xpm";
	int		w;
	int		h;
	void	*wall;

	i = 0;

	while(i <= win->map->row)
	{
		j = 0;
		while (j <= win->map->col)
		{
			if (win->map->map_mx[i][j] == '1')
			{
				wall = mlx_xpm_file_to_image(win->mlx, p, &w, &h);
				printf("%d\n", w);
				mlx_put_image_to_window(win->mlx, win->win, wall, j * w, i * h);
			}
			j++;
		}
		i++;
		
	}
}

______________________________________


void	map_project(int argc, char **argv, w_vars *win, t_struct *checker)
{
	get_map(argc, argv, win, checker);
	map_checker(win, checker);
	wall_checker(win);
	path_check(win, checker);
}