/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_syntax_header.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaffier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 00:59:21 by dbaffier          #+#    #+#             */
/*   Updated: 2019/10/22 20:59:14 by dbaffier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static int				asm_syntax_comment(t_token *ptr2,
		t_env *e, t_aolist *head)
{
	if (ft_strcmp(ptr2->lab, COMMENT_CMD_STRING))
		return (syntax_error(e, ERR_COMMENT_H, NULL, head->next->line));
	if (ptr2->next)
	{
		if (!ptr2->next->lab)
			return (syntax_error(e, ERR_COMNOTF, NULL, head->next->line));
		if (ptr2->next->lab && ft_strlen(ptr2->next->lab) > 2048)
			return (syntax_error(e, ERR_COMMENT_LEN, NULL, head->next->line));
	}
	else
		return (syntax_error(e, ERR_COMMENT_H, NULL, head->next->line));
	return (0);
}

static int				asm_syntax_name(t_token *ptr, t_env *e, t_aolist *head)
{
	if (ft_strcmp(ptr->lab, NAME_CMD_STRING))
		return (syntax_error(e, ERR_NAME_H, NULL, head->line));
	if (ptr)
	{
		if (!ptr->next->lab)
			return (syntax_error(e, ERR_NAMENOTF, NULL, head->next->line));
		if (ptr->next->lab && ft_strlen(ptr->next->lab) > 128)
			return (syntax_error(e, ERR_NAME_LEN, NULL, head->next->line));
	}
	else
		return (syntax_error(e, ERR_NAME_H, NULL, head->line));
	return (0);
}

int						asm_syntax_header(t_env *e, t_aolist *head)
{
	t_token		*ptr;

	if (!head)
		return (syntax_error(e, ERR_NAME_H, NULL, 1));
	ptr = head->tok;
	if (!ft_strcmp(ptr->lab, NAME_CMD_STRING))
	{
		asm_syntax_name(ptr, e, head);
		asm_syntax_comment(head->next->tok, e, head);
	}
	else if (!ft_strcmp(ptr->lab, COMMENT_CMD_STRING))
	{
		asm_syntax_comment(ptr, e, head);
		asm_syntax_name(head->next->tok, e, head);
	}
	else
		return (syntax_error(e, ERR_NAME_H, NULL, head->line));
	return (0);
}
