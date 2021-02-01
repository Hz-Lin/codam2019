#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		contain_c(const char *str, char c, int len)
{
	int		i;

	i = 0;
	while (str[i] && i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	inter(const char *s1, const char *s2)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s2[len])
		len++;
	while (s1[i])
	{
		if (contain_c(s1, s1[i], i) == 0 && contain_c(s2, s1[i], len))
			ft_putchar(s1[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	ft_putchar('\n');
	return (0);
}
