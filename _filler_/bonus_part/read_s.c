/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaliuta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:01:05 by msaliuta          #+#    #+#             */
/*   Updated: 2019/07/15 19:21:28 by msaliuta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	read_sizes(char *line, t_visual *vis)
{
	char	**nums;

	nums = ft_strsplit(line, ' ');
	vis->h = ft_atoi(nums[1]);
	vis->w = ft_atoi(nums[2]);
	ft_arrclr(nums);
}
