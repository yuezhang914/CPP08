/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:11:18 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/18 17:11:19 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <vector>

class Span
{
    public:
        Span(unsigned int n);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span(void);

        void addNumber(int value);

        template <typename InputIt>
        void addNumbers(InputIt first, InputIt last)
        {
            std::vector<int> values;

            while (first != last)
            {
                values.push_back(*first);
                ++first;
            }
            if (_numbers.size() + values.size() > _maxSize)
                throw std::out_of_range("span is full");
            _numbers.insert(_numbers.end(), values.begin(), values.end());
        }

        long shortestSpan(void) const;
        long longestSpan(void) const;

    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;
};

#endif
