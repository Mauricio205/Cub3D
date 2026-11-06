/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maumonte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:30:18 by maumonte          #+#    #+#             */
/*   Updated: 2025/06/26 01:58:01 by maumonte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i = 1;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_check_signal(int nb)
{
	int	signal;

	signal = 0;
	if (nb < 0)
		signal = 1;
	return (signal);
}

char	*ft_itoa(int n)
{
	int		count0;
	int		signal;
	char	*dest;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	signal = ft_check_signal(n);
	if (n < 0)
		n *= -1;
	count0 = ft_count(n) + signal;
	dest = (char *)malloc((count0 + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[count0] = 0;
	if (n == 0)
		dest[0] = 48;
	if (signal)
		dest[0] = '-';
	while (n > 0)
	{
		dest[--count0] = (n % 10) + '0';
		n /= 10;
	}
	return (dest);
}
