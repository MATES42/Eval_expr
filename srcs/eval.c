/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:05:32 by bdevessi          #+#    #+#             */
/*   Updated: 2018/08/19 20:46:35 by jchirk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/eval_expr.h"
#include "../includes/utils.h"

int			ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
			|| c == ' ')
		return (1);
	return (0);
}

char		*remove_spaces(char *str)
{
	int		i;
	int		j;
	int		not_space;
	char	*ret;

	i = 0;
	j = 0;
	not_space = 0;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]) == 0)
			not_space++;
		i++;
	}
	if (!(ret = (char*)malloc(sizeof(char) * (not_space + 1))))
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_space(str[i]) == 0)
			ret[j++] = str[i];
		i++;
	}
	ret[j] = '\0';
	return (ret);
}

int         count_tokens(char *str)                                               {
	int     i;
	int     len;
	int     in_nb;

	i = 0;
	in_nb = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			in_nb = 1;
		if (str[i] == '*' || str[i] == '/'  || str[i] == '%' || str[i] == '('
				|| str[i] == ')')
		{
			len++;                                                                            if (in_nb == 1)
			{
				in_nb = 0;
				len++;                                                                        }
		}
		if (str[i] == '-' || str[i] == '+')
		{
			if (i == 0)                                                                           in_nb = 1;
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9') && i > 0)
				in_nb = 1;
			if ((str[i - 1] >= '0' && str[i - 1] <= '9') && i > 0)
			{
				len++;
				if (in_nb == 1)                                                                   {                                                                                     in_nb = 0;
					len++;                                                                        }                                                                             }
		}                                                                                 i++;                                                                          }
	if (in_nb == 1)
		len++;
	return (len);
}

t_token			*fill_result(char *str, t_token *input)
{
	int     i;
	int		j;
	int		in_nb;
	int     nb;
	int		signe;

	i = 0;
	j = 0;
	in_nb = 0;
	nb = 0;
	signe = 1;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			in_nb = 1;
			nb = (nb * 10) + (str[i] - '0');
		}
		if (str[i] == '*' || str[i] == '/'  || str[i] == '%' || str[i] == '('
				|| str[i] == ')')
		{
			if (in_nb == 1)
			{
				in_nb = 0;
				input[j].value = (nb * signe);
				signe = 1;
				nb = 0;
				input[j++].type = 0;
			}
			input[j].value = str[i];
			input[j++].type = 1;
		}
		if (str[i] == '-' || str[i] == '+')
		{
			if (i == 0)
			{
				in_nb = 1;
				if (str[i] == '-')
				{
					signe = signe * (-1);
				}
			}
			if (!(str[i - 1] >= '0' && str[i - 1] <= '9') && i > 0)
			{
				in_nb = 1;
				if (str[i] == '-')
					signe *= (-1);
			}
			if ((str[i - 1] >= '0' && str[i - 1] <= '9') && i > 0)
			{
				if (in_nb == 1)
				{
					in_nb = 0;
					input[j].value = (nb * signe);
					signe = 1;
					nb = 0;
					input[j++].type = 0;
				}
				input[j].value = str[i];
				input[j++].type = 1;
			}
		}
	//	printf("signe = %d\n", signe);
		i++;
	}
	if (in_nb == 1)
	{
		in_nb = 0;
		input[j].value = (nb * signe);
		signe = 1;
		nb = 0;
		input[j++].type = 0;
	}
	input[j].value = 0;
	input[j].type = -1;
	return (input);
}

t_result		parse_input(char *str)
{
	int			len;
	char		*str_no_space;
	t_result	result;

	str_no_space = remove_spaces(str);
	if (str[0] == '\0')
		return (result);
	len = count_tokens(str_no_space);
	result.size = len;
	if (!(result.input = (t_token*)malloc(sizeof(t_token) * len + 1)))
		return (result);
	result.input = fill_result(str_no_space, result.input);
	return (result);
}

int main(int ac, char **av)
{
	t_result result;

	result = parse_input(av[1]);
	printf("size = %d\n", result.size);
	printf("input0 value = %d\n", result.input[0].value);
	printf("input0 type = %d\n", result.input[0].type);
	printf("input1 value = %d\n", result.input[1].value);
	printf("input1 type = %d\n", result.input[1].type);
	printf("input2 value = %d\n", result.input[2].value);
	printf("input2 type = %d\n", result.input[2].type);
	printf("input3 value = %d\n", result.input[3].value);
	printf("input3 type = %d\n", result.input[3].type);
	printf("input4 value = %d\n", result.input[4].value);
	printf("input4 type = %d\n", result.input[4].type);
	printf("input5 value = %d\n", result.input[5].value);
	printf("input5 type = %d\n", result.input[5].type);
	printf("input6 value = %d\n", result.input[6].value);
	printf("input6 type = %d\n", result.input[6].type);

}

