#include <stdio.h>
#include <unistd.h>
int	ft_putstr(char *str);
int	ft_printf(const char *s, ...);

int	ft_putnbr(int nb, int code)
{
	char *base = "0123456789abcdef";

	if (nb == -2147483647 && code == 10)
		return (ft_putstr("-2147483647"));
	if (nb < 0 && code == 10)
		return(write(1, "-", 1) + ft_putnbr(-nb, 10));
	if (nb < 0 && code == 16)
	{
		return (write(1, "test\n", 5));
	}
		// return (ft_putnbr((unsigned int) nb, 16));
	if (nb / code == 0)
		return (write(1, &base[nb % code], 1));
	return (ft_putnbr(nb / code, code) + ft_putnbr(nb % code, code));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, 1) + ft_putstr(str + 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ctr = 0;
	int		i = 0;

	va_start(args, s);
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == 's')
			ctr+= ft_putstr(va_arg(args, char *));
		else if (s[i] == '%' && s[i + 1] == 'd')
			ctr+= ft_putnbr(va_arg(args, int), 10);
		else if (s[i] == '%' && s[i + 1] == 'x')
			ctr+= ft_putnbr(va_arg(args, int), 16);
		else
			ctr+= write(1, &s[i--], 1);
		i+= 2;
	}
	va_end(args);
	return (ctr);
}

int	main(void)
{
	printf("%i\n", printf(""));
	printf("%i\n", printf(NULL));
	printf("%i\n", printf("%s\n", (char *)NULL));
	printf("%i\n", printf("%x\n", -2147483647));
	printf("%i\n", printf("%d\n", -2147483647));

	ft_printf("ft_printf now:\n");
	ft_printf("%d\n", ft_printf(""));
	ft_printf("%d\n", ft_printf(NULL));
	ft_printf("%d\n", ft_printf("%s\n", (char *)NULL));
	ft_printf("%x\n", -2147483647);
	// ft_printf("%d\n", ft_printf("%x\n", -2147483647));
	// ft_printf("%d\n", ft_printf("%d\n", -2147483647));
	return (0);
}
