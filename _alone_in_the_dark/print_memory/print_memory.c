#include <unistd.h>

void	print_hex(unsigned char c, char *buf)
{
	char	a;
	char	b;

	a = c / 16 > 9 ? c / 16 + 87 : c / 16 + 48;
	b = c % 16 > 9 ? c % 16 + 87 : c % 16 + 48;
	write(1, &a, 1);
	write(1, &b, 1);
	*buf = (char)(c >= 32 && c <= 126 ? c : '.');
}

void	print_memory(const void *addr, size_t size)
{
	size_t 			i;
	int 			j;
	char 			buf[16];

	i = 0;
	j = 0;
	while (addr && i < size)
	{
		print_hex(((unsigned char *)addr)[i++], &(buf[j++]));
		if (!(i % 2))
			write(1, " ", 1);
		if (!(i % 16) || i == size)
		{
			if (i == size && (i %= 16))
			{
				i = 40 - (i * 2 + i / 2);
				while (i--)
					write(1, " ", 1);
				i = size;
			}
			write(1, buf, j);
			write(1, "\n", 1);
			j = 0;
		}
	}
}
