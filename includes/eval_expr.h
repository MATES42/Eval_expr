/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchirk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 16:58:45 by jchirk            #+#    #+#             */
/*   Updated: 2018/08/19 17:11:23 by jchirk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

typdef struct	s_token
{
	void	*value;
	int		type;
}				t_token;

typedef struct	s_oper
{
	char		oper;
	int			precedence;
}				t_oper;

extern			g_opertab;

#endif
