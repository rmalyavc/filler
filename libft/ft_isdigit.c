/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalyavc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:58:34 by rmalyavc          #+#    #+#             */
/*   Updated: 2017/11/15 10:59:57 by rmalyavc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if ((unsigned char)c >= '0' && (unsigned char)c <= '9' && c < 128 && c > 0)
		return (1);
	return (0);
}
