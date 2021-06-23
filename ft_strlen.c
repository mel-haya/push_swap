int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count] != 0)
	{
		count++;
	}
	return (count);
}
