#include "MutantStack.hpp"
#include <iostream>
#include <list>

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
    MutantStack<int> mstack;
    MutantStack<int>::reverse_iterator rit;
    MutantStack<int>::reverse_iterator rite;
    MutantStack<int>::const_iterator cit;
    MutantStack<int>::const_iterator cite;
    const MutantStack<int>* cmstack;

    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    rit = mstack.rbegin();
    rite = mstack.rend();
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    cmstack = &mstack;
    cit = cmstack->begin();
    cite = cmstack->end();
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
}

int main(void)
{
    subjectTest();
    listComparisonTest();
    constAndReverseTest();
    return 0;
}
