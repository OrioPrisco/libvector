/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:25:51 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/09/21 13:00:20 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

void	vector_pop(t_vector *vector, size_t index, void *dest)
{
	ft_memcpy(dest, vector->data + index * vector->elem_size,
		vector->elem_size);
	ft_memmove(vector->data + index * vector->elem_size,
		vector->data + (index + 1) * vector->elem_size,
		(vector->size - index - 1) * vector->elem_size);
	vector->size--;
}

//TODO : probably can avoid recopying the end of the data twice
bool	vector_insert(t_vector *vector, size_t index, const void *data)
{
	if (vector_ensure_capacity(vector, 1))
		return (1);
	ft_memmove(vector->data + (index + 1) * vector->elem_size,
		vector->data + index * vector->elem_size,
		(vector->size - index) * vector->elem_size);
	ft_memcpy(vector->data + index * vector->elem_size,
		data, vector->elem_size);
	vector->size++;
	return (0);
}

t_vector	*vector_sort(t_vector *vector, int (*cmp)(void *, void *),
				bool ascending)
{
	size_t			i;
	size_t			j;
	int				res;

	i = 0;
	while (i < vector->size)
	{
		j = i + 1;
		while (j < vector->size)
		{
			res = cmp(vector->data + i * vector->elem_size,
					vector->data + j * vector->elem_size);
			if (res && ((res < 0) ^ ascending))
				ft_memswp(
					vector->data + (i * vector->elem_size),
					vector->data + (j * vector->elem_size),
					vector->elem_size);
			j++;
		}
		i++;
	}
	return (vector);
}

bool	vector_copy(t_vector *dest, const t_vector *src)
{
	return (vector_copy_n(dest, src->data, src->size, src->elem_size));
}

bool	vector_copy_n(t_vector *dest, const void *src, size_t n,
			size_t elem_size)
{
	if (!n)
		return (vector_init(dest, elem_size), 0);
	dest->data = malloc(n * elem_size);
	if (!dest->data)
		return (1);
	ft_memcpy(dest->data, src, n * elem_size);
	dest->size = n;
	dest->capacity = n;
	dest->elem_size = elem_size;
	return (0);
}
