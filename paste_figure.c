static int		need_offset_x(char **piece, size_t size)
{
	while (--size >= 0)
		if (piece[size] == '*')
			return (0);
	return (1);
}

static char		**cut_spare(char **piece, int size, int *off_x, int *off_y)
{
	int			i;

	i = -1;
	while (++i < size && !ft_strchr(piece->map, '*')) {
		piece++;
		*off_y++;
	}
	while (need_offset_x(piece, ft_count_strings(piece)) && (i = -1))
	{
		while (++i < ft_count_strings(piece))
			piece[i]++;
		*off_x++;
	}
	return (piece);
}

// static int		try_paste(char **map, char **piece)
// {

// }