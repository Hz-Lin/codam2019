#include "../includes/ft_printf.h"

char	*ft_malloc_str(int len)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
