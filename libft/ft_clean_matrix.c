/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 18:44:49 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/12/06 14:51:47 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_clean_matrix(char ***matrix, char ****ptr)
{
	size_t	i;

	i = 0;
	if (matrix == NULL)
		return ;
	while (matrix[i] != 0)
	{
		ft_clean_buff(matrix[i], &matrix[i]);
		i++;
	}
	*ptr = NULL;
}
