

int	ft_isalnum(int c)
{
	unsigned char	ch;
	
	ch = c;
	if ((ch >= '0' && ch <= '9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
	{
		return (1);	
	}
	return (0);
}
