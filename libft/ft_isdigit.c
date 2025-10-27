
int	ft_isdigit(int c)
{
	unsigned char	ch;

	ch = c;
	if (ch >= '0' && ch <= '9')
	{
		return (1);
	}
	return (0);
}
