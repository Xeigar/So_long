#include "so_long.h"

void	checker_initialize(t_struct *checker)
{
	checker->prev_size = 0;
	checker->p = 0 ;
	checker->c = 0;
	checker->e = 0;
	checker->p_ck = 0;
	checker->c_ck = 0;
	checker->e_ck = 0;
}

void	error_call(char *message)
{
	perror(message);
	exit(1);
}

int	get_rows(char *file)
{
	int		fd;
	int		row;
	char	*line;

	row = 0;
	fd = open(file, O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		row++;
	}
	close (fd);
	return (row);
}

char	**matrix_generator(int fd, w_vars *win, char *line)
{
	int	r;
	char **temp;

	temp =(char**)malloc(sizeof(char*) * (win->map->row + 2));
	if (!temp)
		return (NULL);
	temp[win->map->row + 1] = NULL;
	temp[0] = line;
	r = 0;
	while (++r <= win->map->row)
	{
		temp[r] =(char*)malloc(sizeof(char) * win->map->col + 1);
		if (!temp[r])
			return (NULL);
		if (ft_strlen(line) != win->checker->prev_size)
		error_call("Error\nLines are not same size");
		win->checker->prev_size = ft_strlen(line);
		temp[r] = get_next_line(fd);
	}
	return(temp);
}

/*A funcao vai contar o tamanho das linhas e passar o conteudo
do mapa para win->map, NOT WORKING FOR BLANK DOCUMENT*/
void	get_map(int argc, char **argv, w_vars *win, t_struct *checker)
{
	int			fd;
	char		*line;

	if (argc != 2)
		error_call("Error Wrong number of maps");
	if(!ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		error_call("Error Wrong file type");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_call("Error opening file");
	checker_initialize(checker);
	line = get_next_line(fd);
	if (!line || !*line)
		error_call("Error Blank file");
	checker->prev_size = ft_strlen(line);
	win->map->row = get_rows(argv[1]) - 1;//4 ou 5?
	win->map->col = checker->prev_size - 1; //12
	win->map->map_mx = matrix_generator(fd, win, line);
	close (fd);
	map_checker(win, checker);
}

void	wall_checker(w_vars *win)
{	int	pos;
	int	r;

	r = -1;
	if (win->map->map_mx[0][++r] != '1' || win->map->map_mx[win->map->col][r++] != '1')
		error_call("Error\nMissing Wall");
	r = -1;
	if (win->map->map_mx[r++][0] != '1' || win->map->map_mx[r++][win->map->col] != '1')
		error_call("Error\nMissing Wall");
}

void	flood_fill(char** map, t_point origin, t_struct *checker)
{
	if (map[origin.x][origin.y] == '1' || map[origin.x][origin.y] == 'F')
		return ;
	if (map[origin.x][origin.y] == 'P')
		checker->p_ck += 1;
	if (map[origin.x][origin.y] == 'E')
		checker->e_ck += 1;
	if (map[origin.x][origin.y] == 'C')
		checker->c_ck += 1;
	if (map[origin.x][origin.y] != 'C' && map[origin.x][origin.y] != 'P'
	&& map[origin.x][origin.y] != 'E' && map[origin.x][origin.y] != '1'
	&& map[origin.x][origin.y] != 'F' && map[origin.x][origin.y] != '0')
		error_call("Error\nUnknown character");
	map[origin.x][origin.y] = 'F';
	flood_fill(map, (t_point){origin.x - 1, origin.y}, checker);
	flood_fill(map, (t_point){origin.x + 1, origin.y}, checker);
	flood_fill(map, (t_point){origin.x, origin.y - 1}, checker);
	flood_fill(map, (t_point){origin.x, origin.y + 1}, checker);
}
char **matrix_duplicator(w_vars *win)
{
	int	c;
	int	r;
	char **temp;

	temp =(char**)malloc(sizeof(char*) * (win->map->row + 2));
	if (!temp)
		return (NULL);
	temp[win->map->row + 1] = NULL;
	r = -1;
	while (++r <= win->map->row)
	{
		temp[r] =(char*)malloc(sizeof(char) * win->map->col + 1);
		if (!temp[r])
			return (NULL);
		while (++c <= win->map->col)
		{
			temp[r][c] = win->map->map_mx[r][c];
		}
	}
	return(temp);
}

void path_check(w_vars *win, t_struct *checker)
{
	char **temp;
	int			a;

	temp = matrix_duplicator(win);
	flood_fill(temp, win->player,checker);
	if (checker->c != checker->c_ck || checker->p != checker->p_ck
	|| checker->e != checker->e_ck)
		error_call("Error\nNo valid path");
	checker->c_ck = 0;
	a = 0;
	while(temp[a])
	{
		free(temp[a]);
		a++;
	}
	free(temp);
}

void	map_checker(w_vars *win, t_struct *checker)
{
	int	i;
	int	j;

	i = -1;
	while(win->map->map_mx[++i])
	{
		j = -1;
		while(win->map->map_mx[i][++j])
		{
			if (win->map->map_txt[i] == 'P')
				checker->p += 1;
			if (win->map->map_txt[i] == 'E')
				checker->e += 1;
			if (win->map->map_txt[i] == 'C')
				checker->c += 1;
		}
	}
	if (checker->p != 1)
		error_call("Error\nOn starting position");
	if (checker->c <= 0)
		error_call("Error\nNo colectibles");
	if (checker->e != 1)
		error_call("Error\nOn exit");
	printf("%s", win->map->map_txt);/*used just to visualize the map*/
	wall_checker(win);
	path_check(win, checker);
}