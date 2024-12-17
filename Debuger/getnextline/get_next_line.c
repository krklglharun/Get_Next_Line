#include "get_next_line.h"
#include <stdio.h>

char	*readline(int fd, char	*readone)
{
	char	*buff;
	int		reader;

	printf("*************readline fonksiyonu basladı**************\n");//werror
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	printf("whille ocesi buff=%s\n", buff);//werror
	printf("whille ocesi readone=%s\n", readone);//werror
	if (!buff)
		return (0);
	reader = 1;
	while (!ft_strchr(readone, '\n') && reader != 0)
	{
		printf("once reader=%d\n", reader);//werror
		printf("read oncesi buff=%s\n", buff);//werror
		reader = read(fd, buff, BUFFER_SIZE);
		printf("sonra reader=%d\n", reader);//werror
		if (reader == -1)
		{
			free(buff);
			free(readone);
			return (NULL);
		}
		printf("once buff=%s\n", buff);//werror
		buff[reader] = '\0';
		printf("sonra buff=%s\n", buff);//werror
		printf("once readone=%s\n", readone);//werror
		readone = ft_strjoin(readone, buff);
		printf("sonra readone=%s\n", readone);//werror
	}
	free(buff);
	printf("son readline readone=%s\n", readone);//werror
	printf("**************readline fonksiyonu bitti*************\n");//werror
	return (readone);
}

char	*putline(char *readone)
{
	char	*str;
	int		i;

	i = 0;
	if (!readone[i])
		return (NULL);
	while (readone[i] != '\n' && readone[i] != '\0')
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (readone[i] != '\n' && readone[i] != '\0')
	{
		str[i] = readone[i];
		i++;
	}
	if (readone[i] == '\n')
	{
		str[i] = readone[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*nxtline(char *readone)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	printf("**************nextline fonksiyonu basladı*************\n");//werror
	while (readone[i] != '\n' && readone[i] != '\0')
		i++;
	printf("ilk whiledan dönenen değer(readone uzunluğu)=%d\n" , i);//werror
	if (!readone[i])
	{
		printf("***************bunu gördüğüne göre fonksiyon bitmiştir************\n");//werror
		free(readone);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(readone) - i));
	printf("ft_strlen(readone)=%ld\n", ft_strlen(readone));//werror
	printf("str de yer acıldı mı =%s\n", str);//werror
	if (!str)
		return (NULL);
	i++;
	printf("j=%d\n", j);//werror
	printf("i=%d\n", i);//werror
	while (readone[i + j] != '\0')
	{
		printf("2.While girdim\n");//werror
		str[j] = readone[j + i];
		j++;
	}
	printf("j=%d\n", j);//werror
	str[j] = '\0';
	free(readone);
	printf("Return(str)=%s\n", str);//werror
	printf("************nextline fonksiyonu bitti*************\n");//werror
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*readone;
	char		*arr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readone = readline(fd, readone);
	if (!readone)
		return (NULL);
	arr = putline(readone);
	printf("Putline sonrası Arr=%s\n", arr);//werror
	printf("Putline sonrası(nexline oncesi) readone=%s\n", readone);//werror
	readone = nxtline(readone);
	printf("nexline sonrası readone=%s\n", readone);//werror
	return (arr);
}
