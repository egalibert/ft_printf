#include "../includes/ft_printf.h"


int	check_width_percent(t_flags *flags)
{
	int char_count;
	
	char_count = flags->width;
	if (flags->minus == 1)
	{
		ft_putchar('%');
		if (flags->width > 1)
			while (flags->width-- > 1)
				ft_putchar(' ');
		else
			char_count = 1;
	}
	else
	{
		while (flags->width-- > 1)
		{
			if (flags->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar('%');	
	}
	return (char_count);
}

int		ft_treat_percent(t_flags *flags)
{
	int char_count;
	
	char_count = 0;
	if (flags->minus == 1 || flags->width > 1)
		char_count = check_width_percent(flags);
	else
	{
		ft_putchar('%');
		char_count++;
	}	
	return (char_count);
}












/*int		ft_treat_percent(t_flags flags)
{
	int char_count;

	char_count = 0;
	if (flags.minus == 1)
		char_count += ft_putstrprec("%", 1);
	char_count += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		char_count += ft_putstrprec("%", 1);
	return (char_count);
}
*/