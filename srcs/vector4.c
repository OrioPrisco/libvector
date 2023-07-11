/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:00:08 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/07/11 14:49:26 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"
#include "libft.h"

/*
bool	vector_is_sorted(t_vector *vector, bool ascending)
{
	size_t	i;

	i = 0;
	while (i + 1 < vector->size)
	{
		if ((vector->data[i] < vector->data[i + 1]) ^ ascending)
			return (0);
		i++;
	}
	return (1);
}
*/

bool	vector_null_term(t_vector *vector)
{
	if (vector_ensure_capacity(vector, 1))
		return (1);
	ft_bzero(vector->data + vector->size * vector->elem_size,
		vector->elem_size);
	return (0);
}
