/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdevessi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:05:32 by bdevessi          #+#    #+#             */
/*   Updated: 2018/08/19 17:31:10 by bdevessi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"
#include "utils.h"
#define IS_NUMBER(X) ((X) >= '0' && (X) <= '9')
#define IS_OPERATOR(X) ((X) == '+' || (X) == '-' || (X) == '*' || (X) == '/' || (X) == )

int			count_tokens(char *str)
{
	int		len;

	len = 0;
	while (*str)
	{
		if (*str)
	}
}

t_token		*parse_input(char *str)
{
	
}
