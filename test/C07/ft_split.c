#include <stdlib.h>
int	is_sep(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

int	get_size(char *str)
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (str[idx])
	{
		if (!is_sep(str[idx])
			&& (is_sep(str[idx + 1]) || !str[idx + 1]))
			count ++;
		idx ++;
	}
	return (count);
}

char	*ft_strdup(char *str, int size)
{
	int	idx = 0;
	char	*dest;

	dest = malloc(sizeof(char) * (size + 1));
	while (idx < size)
	{
		dest[idx] = str[idx];
		idx ++;
	}
	dest[idx] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	char	**res;
	char	*from;
	int		size;
	int		idx = 0;

	size = get_size(str);
	res = malloc(sizeof(char*) * (size + 1));
	while (idx < size)
	{
		while (is_sep(*str))
			str ++;
		from = str;
		while (!is_sep(*str) && *str)
			str ++;
		res[idx] = ft_strdup(from, str - from);
		idx ++;
	}
	res[idx] = 0;
	return (res);
}

#include <stdio.h>
int	main()
{
	printf("-------ex05-------\n\n");
    char **ex05_split1;
    char **ex05_split2;
	char *ex05_str1 = "hello my name is hunpark!";
	char *ex05_str2 = "good day cat dog vim1";
	ex05_split1 = ft_split(ex05_str1);
    ex05_split2 = ft_split(ex05_str2);
    printf("---test1---\n");
	for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ex05_split1[j]);
		printf("\n");
	}	
    printf("\n\n");
    printf("---test2---\n");
    for (int j = 0; j < 5; j++)
	{
		printf("%s\n", ex05_split2[j]);
	}
   	free(ex05_split1);
    free(ex05_split2);
}
