#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void ft_putnbr_base(int nbr, char *base)
{
    int b;

    b = ft_strlen(base);
    if (nbr <= -2147483648)
    {
        write(1, "-", 1);
        ft_putnbr_base((-(long int)nbr) / b, base);
        ft_putnbr_base((-(long int)nbr) % b, base);
    }
    else if (nbr < 0)
    {
        write(1, "-", 1);
        ft_putnbr_base(-nbr, base);
    }
    else if (nbr < b)
    {
        write(1, &base[nbr], 1);
    }
    else
    {
        ft_putnbr_base(nbr / b, base);
        ft_putnbr_base(nbr % b, base);
    }
}

int main(void)
{
    ft_putnbr_base(-2147483648, "01");
    return (0);
}
