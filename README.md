# Exam-Rank-03

J'ai repris le code du github de @Pasqualerossi

# ft_printf
int  ft_printf(const char *s, ...);
   penser au cas NULL: return (-1);
 int  ft_putnbr(long nbr, int base);
   penser a mettre LONG
   penser au cas negatif hexa : return(ft_putnbr((unsigned int) nbr, base));
   penser au cas negatif base 10: return(write(1, "-', 1) + ft_putnbr(-nbr, base));
 int  ft_putstr(char *str);
   penser au cas NULL: return (write(1, "(null)", 6));
   penser au cas vide: return (0);

# get_next_line
 5 variables dont 3 static
 conditions de sortie: fd < 0 || BUFFER_SIZE <= 0
 conditions de sortie: buff_read <= 0 ou line[i - 1] == '\n'
 penser a mettre line[i] == '\0';
 penser au cas if(i == 0) return (NULL);
