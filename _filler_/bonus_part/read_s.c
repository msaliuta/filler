/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <msaliuta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:01:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/13 16:09:57 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	read_sizes(char *line, t_visual *v)
{
	char	**nums;

	nums = ft_strsplit(line, ' ');
	v->m_heigth = ft_atoi(nums[1]);
	v->m_width = ft_atoi(nums[2]);
	ft_arrclr(nums);
}
