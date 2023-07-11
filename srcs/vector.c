/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:09:19 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/07/11 18:28:18 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

t_vector	*vector_init(t_vector *vector, size_t elem_size)
{
	ft_bzero(vector, sizeof(*vector));
	vector->elem_size = elem_size;
	return (vector);
}

bool	vector_allocate(t_vector *vector, size_t size)
{
	if (size == 0)
		return (0);
	vector->size = 0;
	vector->data = malloc(size * vector->elem_size);
	if (!vector->data)
		return (1);
	vector->capacity = size;
	return (0);
}

bool	vector_append(t_vector *vector, const void *data)
{
	if (vector_ensure_capacity(vector, 1))
		return (1);
	ft_memcpy(vector->data + vector->size * vector->elem_size,
		data, vector->elem_size);
	vector->size++;
	return (0);
}

t_vector	*vector_clear(t_vector *vector)
{
	if (!vector)
		return (NULL);
	free(vector->data);
	ft_bzero(vector, sizeof(*vector));
	return (vector);
}

bool	vector_ensure_capacity(t_vector *vector, size_t size)
{
	void			*new_data;
	size_t			new_capacity;

	if (vector->capacity == 0 && size < DEFAULT_VECTOR_SIZE)
		return (vector_allocate(vector, DEFAULT_VECTOR_SIZE));
	if (vector->capacity == 0)
		return (vector_allocate(vector, size));
	if (vector->size + size < vector->capacity)
		return (0);
	new_capacity = vector->capacity * 2;
	while (vector->size + size > new_capacity)
		new_capacity *= 2;
	new_data = malloc(new_capacity * vector->elem_size);
	if (!new_data)
		return (1);
	ft_memcpy(new_data, vector->data, vector->size * vector->elem_size);
	free(vector->data);
	vector->data = new_data;
	vector->capacity = new_capacity;
	return (0);
}
