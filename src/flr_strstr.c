#include "../include/filler.h"

int		flr_strstr(char *big, char *little)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (big[i])
	{
		len = 0;
		j = 0;
		if (big[i] == little[j])
		{
			while (big[i] == little[j] && little[j])
			{
				i++;
				j++;
				len++;
			}
			if (len == ft_strlen(little))
				return (1);
		}
		else
			i++;
	}
	return (0);
}
