/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 17:05:51 by rmalyavc          #+#    #+#             */
/*   Updated: 2018/02/24 15:05:36 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	arr_cpy(long long int *container, long long int *src, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		container[i] = src[i];
}

static void	merge_tabs(long long int *container, long long int *a,
			long long int *b, int n)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (++i < n)
		if ((j < n / 2 && k < n / 2) ||
				(n % 2 != 0 && j < n / 2 && k == n / 2))
		{
			if (a[j] < b[k])
				container[i] = a[j++];
			else
				container[i] = b[k++];
		}
		else if (j >= n / 2 && (k < n / 2 ||
					(n % 2 != 0 && k == n / 2)) && (k += 1))
			container[i] = b[k - 1];
		else if (k >= n / 2 && j < n / 2 && (j += 1))
			container[i] = a[j - 1];
}

void		ft_merge_sort(long long int *tab, int n)
{
	long long int		container[n];

	if (n < 2)
		return ;
	ft_merge_sort(tab, n / 2);
	if (n % 2 != 0)
		ft_merge_sort(tab + n / 2, n / 2 + 1);
	else
		ft_merge_sort(tab + n / 2, n / 2);
	merge_tabs(container, tab, tab + n / 2, n);
	arr_cpy(tab, container, n);
}
