#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	va_list args;
	char c;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format != '%')
			ft_putchar_fd(*format, 1);
		if (format == '%')
			to_write();
		format++;
	}
}

// int main()
// {
// 	ft_printf("wypisz i zobacz co sie wydarzy");
// }