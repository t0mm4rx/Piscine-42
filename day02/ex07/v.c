
#include <unistd.h>


void ft_print_digit(int n)
{
	n += 48;
	write(1, &n, 1);
}

void ft_putnbr(int n)
{
	
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-n);
		return;
	}

	if (n < 10) {
		ft_print_digit(n);
	} else {
		ft_putnbr(n / 10);
		ft_print_digit(n % 10);
	}

}

int main()
{
	ft_putnbr(-123);
	return 0;
}
