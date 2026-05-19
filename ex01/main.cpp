/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:11:00 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/19 13:22:03 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

static void subjectTest(void)
{
    Span sp(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void largeRangeTest(void)
{
    std::vector<int> values;
    Span sp(10000);
    int i;

    i = 0;
    while (i < 10000)
    {
        values.push_back(i * 2);
        i++;
    }
    sp.addNumbers(values.begin(), values.end());
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

static void exceptionTests(void)
{
    Span empty(2);
    Span full(1);

    try
    {
        std::cout << empty.shortestSpan() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        full.addNumber(1);
        full.addNumber(2);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

int main(void)
{
    subjectTest();
    largeRangeTest();
    exceptionTests();
    return 0;
}
