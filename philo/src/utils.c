/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:51:47 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/26 17:51:50 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

int	ft_get_next_char(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)

{
	int	num;
	int	i;
	int	symbol;

	num = 0;
	i = ft_get_next_char(str);
	symbol = 1;
	if (str[i] == '-')
	{
		symbol = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 && num == 0)
			num = str[i] - '0';
		else if (ft_isdigit(str[i]) == 1)
			num = num * 10 + (str[i] - '0');
		else
			return (0);
		i++;
	}
	return (num * symbol);
}
