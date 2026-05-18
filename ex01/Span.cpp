/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:11:13 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/18 17:11:14 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : _maxSize(n), _numbers()
{
    _numbers.reserve(n);
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span(void)
{
}

void Span::addNumber(int value)
{
    if (_numbers.size() >= _maxSize)
        throw std::out_of_range("span is full");
    _numbers.push_back(value);
}

long Span::shortestSpan(void) const
{
    std::vector<int> sorted;
    std::vector<int>::size_type index;
    long shortest;
    long current;

    if (_numbers.size() < 2)
        throw std::logic_error("not enough numbers");
    sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());
    index = 1;
    shortest = static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]);
    while (index + 1 < sorted.size())
    {
        current = static_cast<long>(sorted[index + 1]) - static_cast<long>(sorted[index]);
        if (current < shortest)
            shortest = current;
        index++;
    }
    return shortest;
}

long Span::longestSpan(void) const
{
    int minValue;
    int maxValue;

    if (_numbers.size() < 2)
        throw std::logic_error("not enough numbers");
    minValue = *std::min_element(_numbers.begin(), _numbers.end());
    maxValue = *std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<long>(maxValue) - static_cast<long>(minValue);
}
