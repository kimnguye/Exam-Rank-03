#include <stdio.h>
#include <unistd.h>
int	ft_putstr(char *str);
int	ft_printf(const char *s, ...);

int	ft_putnbr(long nb, int base)
{
	char *b = "0123456789abcdef";

	if (nb < 0 && base == 10)
		return(write(1, "-", 1) + ft_putnbr(-nb, base));
	if (nb < 0 && base == 16)
		return (ft_putnbr((unsigned int) nb, base));
	if (nb / base == 0)
		return (write(1, &b[nb], 1), 1);
	return (ft_putnbr(nb / base, base) + ft_putnbr(nb % base, base));
}

int	ft_putstr(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
		if (!*str)
		return (0);
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
	printf(" || %d\n", printf("%x", -2147483647));
	printf(" || %d\n", printf("%d", -2147483647));
	printf(" || %d\n", printf("%x %x %x %x", 10, 9, 16, 17));
	printf(" || %d\n", printf("%d %d %d %d", 10, 9, 16, 17));
	printf("%d\n", printf("%x\n", 21));
	printf("%d\n", printf("%d\n", 21));
	printf("%d\n", printf("%x\n", 2147483647));
	printf("%d\n", printf("%d\n", 2147483647));
	printf("%d\n", printf("coucou comment tu %s\n", "vas"));
	printf("%d\n", printf("%d\n", -20));
	printf("%d\n", printf("%x\n", -2));

	ft_printf("\n**********************\n\n");

	ft_printf("%d\n", ft_printf(""));
	ft_printf("%d\n", ft_printf(NULL));
	ft_printf("%d\n", ft_printf("%s\n", (char *)NULL));
	ft_printf(" || %d\n", ft_printf("%x", -2147483647));
	ft_printf(" || %d\n", ft_printf("%d", -2147483647));
	ft_printf(" || %d\n", ft_printf("%x %x %x %x", 10, 9, 16, 17));
	ft_printf(" || %d\n", ft_printf("%d %d %d %d", 10, 9, 16, 17));
	ft_printf("%d\n", ft_printf("%x\n", 21));
	ft_printf("%d\n", ft_printf("%d\n", 21));
	ft_printf("%d\n", ft_printf("%x\n", 2147483647));
	ft_printf("%d\n", ft_printf("%d\n", 2147483647));
	ft_printf("%d\n", ft_printf("coucou comment tu %s\n", "vas"));
	ft_printf("%d\n", ft_printf("%d\n", -20));
	ft_printf("%d\n", ft_printf("%x\n", -2));
	return (0);
}
