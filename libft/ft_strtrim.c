#include "libft.h"

unsigned int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	i;
	size_t	k;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	k = 0;
	while (s1[i] && in_set(s1[i], set))
		i++;
	while (len_s1 > i && in_set(s1[len_s1 - 1], set))
		len_s1--;
	str = (char *)malloc(sizeof(char const) * (len_s1 - i + 1));
	if (!str)
		return (NULL);
	while (i < len_s1)
	{
		str[k++] = s1[i++];
	}
	str[k] = '\0';
	return (str);
}
