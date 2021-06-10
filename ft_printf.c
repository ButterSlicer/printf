#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "printf.h"
#include <stdlib.h>
int	ft_atoi(const char *str)
{
	int				i;
	int				min;
	unsigned int	res;
	char			*p;

	p = (char *) str;
	i = 0;
	min = 1;
	res = 0;
	while ((p[i] >= 0x09 && p[i] <= 0x0D) || (p[i] == ' '))
		i++;
	if (p[i] == '-')
		min *= -1;
	if (p[i] == '-' || p[i] == '+')
		i++;
	while (p[i] >= '0' && p[i] <= '9')
	{
		res = (res * 10) + (p[i] - '0');
		i++;
	}
	if (res > 2147483648 && min == -1)
		return (0);
	if (res > INT_MAX && min == 1)
		return (-1);
	return (min * res);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, 1);
}
t_flag init_struct(t_flag flag)
{
	flag.width = 0;
	flag.dot = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.digit = 0;
	return (flag);
}
void ft_parce_c(va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_putchar_fd(c,1);
	//write(1,"\0",1);
}
// void ft_parce_s(va_list ap, t_flag *flag)
// {
// 	char *str;
// 	char *p;
	
// 	str = va_arg(ap, char *);
// 	p = mal
// 	if ((ft_strlen(str) < flag->width) && (flag->dot == 0))
// 	{
// 		while (*str != '\0')
// 		{
// 		write(1, &str, 1);
// 		}
// 	}

// }
void	ft_parcing(const char *s, va_list ap, int *count)
{
	t_flag flag;
	flag = init_struct(flag);

	while (*s)
	{
		write(1, &*s, 1);
		s++;
		if (*s == '%')
		{
			s++;
			(*count)++;
			if (*s == '-')
				flag.minus += 1;
			if (*s == '0' && flag.zero != 1)
			{
				flag.zero += 1;
				s++;
				(*count)++;
			}
			if (*s >= '0' && *s <= '9')
			{
				flag.width = ft_atoi(s);
				while (*s >= '0' && *s <= '9')
				{
					s++;
					(*count)++;
				}
			}
			if (*s == '*')
			{
				flag.width = va_arg(ap, int);
				s++;
				(*count)++;
			}
			if (*s == 'c')
			{
				ft_parce_c(ap);
				s++;
			}
			// if (*s == 's')
			// 	ft_parce_s(ap);
			if (*s == '.')
			{
				s++;
				(*count)++;
				if (*s >= '0' && *s <= '9')
				{
					flag.dot = ft_atoi(s);
					while (*s >= '0' && *s <= '9')
					{
						s++;
						(*count)++;
					}
				}
				if (*s == '*')
				{
					flag.dot = va_arg(ap, int);
					s++;
					(*count)++;
				}
			}
		}
		//write(1, &*s, 1);
		//s++;
		(*count)++;
	}
	printf("\nwidth--> %d\n",flag.width);
	printf("dot---->%d\n", flag.dot);
	printf("zero--->%d\n",flag.zero);
}
int ft_printf(const char *s, ...)
{
	va_list ap;
	int count;
	int *i;

	i = 0;
	count = 0;
	va_start(ap, s);
	ft_parcing(s, ap, &count);
	return (1);
}

int main()
{
    int item;

    item = 1234;
    ft_printf("origin printf=%*.233d",01234,item);
    printf("origin printf=%*.233d",01234,item);
    // printf("origin printf = %s",item);
}

