/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfouger <anfouger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 05:30:33 by anfouger          #+#    #+#             */
/*   Updated: 2026/07/14 05:54:20 by anfouger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
# define TEMPLATE_HPP

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;
	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T		min(T &a, T &b)
{
	if (a == b || b < a)
		return b;
	else
		return a;
}

template <typename T>
T		max(T &a, T &b)
{
	if (a == b || b > a)
		return b;
	else
		return a;
}
#endif