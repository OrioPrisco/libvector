/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 19:00:08 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/07/26 17:27:42 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "vector.h"
#include "libft.h"

bool	vector_is_sorted(t_vector *vector, bool ascending,
			int (*cmp)(void *, void *))
{
	size_t	i;
	int		res;

	i = 0;
	while (i + 1 < vector->size)
	{
		res = cmp(vector->data + i * vector->elem_size,
				vector->data + (i + 1) * vector->elem_size);
		if (res && ((res < 0) ^ ascending))
			return (0);
		i++;
	}
	return (1);
}

bool	vector_null_term(t_vector *vector)
{
	if (vector_ensure_capacity(vector, 1))
		return (1);
	ft_bzero(vector->data + vector->size * vector->elem_size,
		vector->elem_size);
	return (0);
}

void	*vector_move_data(t_vector *vector)
{
	void	*data;

	data = vector->data;
	vector->data = NULL;
	vector->size = 0;
	vector->capacity = 0;
	return (data);
}

t_vector	*vector_free(t_vector *vector, void (*f)(void *))
{
	void	*data;
	size_t	i;

	data = vector->data;
	i = 0;
	while (i < vector->size)
	{
		f(data);
		i++;
		data += vector->elem_size;
	}
	return (vector_clear(vector));
}
