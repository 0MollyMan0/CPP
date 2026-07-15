/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 19:46:25 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/16 01:00:33 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <stdlib.h>

template <typename T>
void	iter(T *tab, const size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		f(tab[i]);
}

template <typename T>
void	iter(const T *tab, const size_t len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++)
		f(tab[i]);
}

#endif