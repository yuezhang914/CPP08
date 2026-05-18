/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:10:42 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/18 17:10:43 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

static void testVector(void)
{
    std::vector<int> values;
    std::vector<int>::iterator it;
    int i;

    i = 0;
    while (i < 10)
    {
        values.push_back(i * 2);
        i++;
    }
    it = easyfind(values, 8);
    std::cout << "vector found: " << *it << std::endl;
    try
    {
        it = easyfind(values, 7);
        std::cout << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "vector error: " << e.what() << std::endl;
    }
}

static void testList(void)
{
    std::list<int> values;
    std::list<int>::iterator it;
    int i;

    i = 0;
    while (i < 10)
    {
        values.push_back(i - 3);
        i++;
    }
    it = easyfind(values, 4);
    std::cout << "list found: " << *it << std::endl;
    try
    {
        it = easyfind(values, 42);
        std::cout << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "list error: " << e.what() << std::endl;
    }
}

int main(void)
{
    testVector();
    testList();
    return 0;
}
