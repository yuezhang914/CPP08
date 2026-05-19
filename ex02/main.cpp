/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzhang2 <yzhang2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:11:33 by yzhang2           #+#    #+#             */
/*   Updated: 2026/05/19 15:35:58 by yzhang2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <stack>
#include <string>

template <typename InputIt>
static void printRange(InputIt first, InputIt last)
{
    while (first != last)
    {
        std::cout << *first << std::endl;
        ++first;
    }
}

static void subjectTest(void)
{
    MutantStack<int> mstack;
    MutantStack<int>::iterator it;
    MutantStack<int>::iterator ite;
    std::stack<int> s;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    it = mstack.begin();
    ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    s = std::stack<int>(mstack);
}

static void listComparisonTest(void)
{
    std::list<int> values;
    std::list<int>::iterator it;
    std::list<int>::iterator ite;

    values.push_back(5);
    values.push_back(17);
    std::cout << values.back() << std::endl;
    values.pop_back();
    std::cout << values.size() << std::endl;
    values.push_back(3);
    values.push_back(5);
    values.push_back(737);
    values.push_back(0);
    it = values.begin();
    ite = values.end();
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

static void constAndReverseTest(void)
{
    MutantStack<int> topStack;
    MutantStack<int> reverseStack;
    MutantStack<int> constStack;
    MutantStack<int>::reverse_iterator rit;
    MutantStack<int>::reverse_iterator rite;
    MutantStack<int>::const_iterator cit;
    MutantStack<int>::const_iterator cite;
    const MutantStack<int> *cmstack;

    topStack.push(5);
    topStack.push(17);
    std::cout << topStack.top() << std::endl;
    topStack.pop();
    std::cout << topStack.size() << std::endl;
    reverseStack.push(5);
    reverseStack.push(3);
    reverseStack.push(5);
    reverseStack.push(737);
    reverseStack.push(0);
    rit = reverseStack.rbegin();
    rite = reverseStack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    constStack.push(5);
    constStack.push(17);
    std::cout << constStack.top() << std::endl;
    constStack.pop();
    std::cout << constStack.size() << std::endl;
    constStack.push(3);
    constStack.push(5);
    constStack.push(737);
    constStack.push(0);
    cmstack = &constStack;
    cit = cmstack->begin();
    cite = cmstack->end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
}

static void typeTemplateTest(void)
{
    MutantStack<std::string> words;
    MutantStack<double> numbers;

    words.push("hello");
    words.push("mutant");
    words.push("stack");
    printRange(words.begin(), words.end());

    numbers.push(1.5);
    numbers.push(2.25);
    numbers.push(3.75);
    printRange(numbers.begin(), numbers.end());
}

int main(void)
{
    subjectTest();
    listComparisonTest();
    constAndReverseTest();
    typeTemplateTest();
    return 0;
}