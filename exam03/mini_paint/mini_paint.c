#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

int		put_error(char *s)
{
	for (int i = 0; s[i]; i++)
		write(1, &s[i], 1);
	write(1, "\n", 1);
	return (1);
}

int		is_valid_size(int width, int height)
{
	if (height > 0 && height <= 300 && width > 0 && width <= 0)
		return (1);
	return (0);
}

int		is_valid_type(char c)
{
	if (c == 'c' || c == 'C')
		return (1);
	return (0);
}

float	calc_distance(float x1, float x2, float y1, float y2)
{
	return (sqrtf(powf((x2 - x1), 2) + powf((y2 - y1), 2)));
}

void	draw_canvas(int width, int height, char canvas[height][width],
		char type, float x, float y, float radius, char filler)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			float distance = calc_distance(x, j, y, i);
			if (type == 'C' && distance <= radius)
				canvas[i][j] = filler;
			else if (type == 'c')
			{
				distance = distance - radius;
				if (distance <= 0 && distance > -1)
					canvas[i][j] = filler;
			}
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
	int		height, width, flag;
	char	background, filler, type;
	float	x, y, radius;

	if (argc != 2)
		return (put_error("Error: argument"));
	file = fopen(argv[1], "r");
	if (!file)
		return (put_error("Error: Operation file corrupted"));
	flag = fscanf(file, "%d %d %c\n", &width, &height, &background);
	if (flag != 3)
		return (put_error("Error: Operation file corrupted"));
	char canvas[height][width];
	for (int i = 0; i < height; i++)
		memset(canvas[i], background, width);
	while (flag)
	{
		flag = fscanf(file, "%c %f %f %f %c\n", &type, &x, &y, &radius, &filler);
		if (flag == -1)
			break ;
		if (flag != 5 || !is_valid_type(type) || radius <= 0)
			return (put_error("Error: Operation file corrupted"));
		draw_canvas(width, height, canvas, type, x, y, radius, filler);
	}
	fclose(file);
	print_canvas(width, height, canvas);
	return (0);
}