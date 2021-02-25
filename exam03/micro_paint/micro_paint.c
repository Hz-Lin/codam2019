#include <unistd.h>
#include <string.h>
#include <stdio.h>

int		put_error(char *s)
{
	for (int i = 0; s[i]; i++)
		write(1, &s[i], 1);
	write(1, "\n", 1);
	return (1);
}

int		is_valid_size(int width, int height)
{
	if (width > 0 && width <= 300 && height > 0 && height <= 300)
		return (1);
	return (0);
}

int		is_valid_type(char c)
{
	if (c == 'r' || c == 'R')
		return (1);
	return (0);
}

void	draw_canvas(int width, int height, char canvas[height][width],
		char type, float x, float y, float rbx, float rby, char filler)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			int distance = x <= j && j <= rbx && y <= i && i <= rby;
			int	border = j - x < 1 || rbx - j < 1 || i - y < 1 || rby - i < 1;
			if (type == 'R' && distance)
				canvas[i][j] = filler;
			else if (type == 'r' && distance && border)
				canvas[i][j] = filler;
		}
	}
}

void	print_canvas(int width, int height, char canvas[height][width])
{
	for (int i = 0; i < height; i++)
	{
		write(1, canvas[i], width);
		write(1, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	FILE	*file;
	int		width, height, flag;
	char	background, filler, type;
	float	x, y, rec_width, rec_height;

	if (argc != 2)
		return (put_error("Error: argument"));
	file = fopen(argv[1], "r");
	if (!file)
		return (put_error("Error: Operation file corrupted"));
	flag = fscanf(file, "%d %d %c\n", &width, &height, &background);
	if (flag != 3)
		return (put_error("Error: Operation file corrupted"));
	if (!is_valid_size(width, height))
		return (put_error("Error: Operation file corrupted"));
	char	canvas[height][width];
	for (int i = 0; i < height; i++)
		memset(canvas[i], background, width);
	while (flag)
	{
		flag = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &rec_width, &rec_height, &filler);
		if (flag == -1)
			break ;
		if (flag != 6 || !is_valid_type(type) || rec_width <= 0 || rec_height <= 0)
			return (put_error("Error: Operation file corrupted"));
		draw_canvas(width, height, canvas, type, x, y, rec_width + x, rec_height + y, filler);
	}
	fclose(file);
	print_canvas(width, height, canvas);
	return (0);
}