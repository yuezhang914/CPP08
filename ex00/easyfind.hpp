/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:10:34 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/19 13:22:28 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), value);
    if(it == container.end())
    throw std::out_of_range("value not found");
    return it;  
}


template <typename T>
typename T::iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it;
    
    it = std::find(container.begin(), container.end(), value);
    if(it == container.end())
    throw std::out_of_range("value not found");
    return it;  
}



#endif