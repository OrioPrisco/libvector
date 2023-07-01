/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:37:12 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/07/01 22:28:40 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

bool	vector_append_n(t_vector *vector, const void *data, size_t n)
{
	if (vector_ensure_capacity(vector, n))
		return (1);
	while (n--)
		ft_memcpy(vector->data + (vector->size++) * vector->elem_size,
			data, vector->elem_size);
	return (0);
}

bool	vector_append_elems(t_vector *vector, const void *data, size_t n)
{
	if (vector_ensure_capacity(vector, n))
		return (1);
	ft_memcpy(vector->data + vector->size * vector->elem_size,
		data, n * vector->elem_size);
	vector->size += n;
	return (0);
}

t_vector	*vector_pop_n(t_vector *vector, size_t index, size_t n)
{
	ft_memmove(vector->data + index * vector->elem_size,
		vector->data + index + n,
		(vector->size - index - n) * vector->elem_size);
	vector->size -= n;
	return (vector);
}

t_vector	*vector_move(t_vector *dest, t_vector *src)
{
	vector_clear(dest);
	*dest = *src;
	ft_bzero(src, sizeof(*src));
	return (src);
}
/*
size_t	vector_count_elems(t_vector *vector, t_vector_data data, size_t index)
{
	size_t	total;

	total = 0;
	while (index < vector->size)
	{
		if (vector->data[index++] == data)
			total++;
	}
	return (total);
}
*/
