# CPP Module 08 - Templated Containers, Iterators and Algorithms

This repository contains my solutions for **42 School C++ Module 08**.

The main goal of this module is to practice using the **STL** in C++98: containers, iterators, algorithms, and container adapters. Instead of manually rewriting common data structures or search/sort logic, this project focuses on using the right standard tools correctly.

## General Requirements

- Compile with `c++`
- Use `-Wall -Wextra -Werror`
- Compatible with `-std=c++98`
- No external libraries
- No `using namespace std`
- Use STL containers and algorithms where appropriate
- Follow Orthodox Canonical Form when a class requires it

## Project Structure

```text
ex00/
  Makefile
  main.cpp
  easyfind.hpp

ex01/
  Makefile
  main.cpp
  Span.hpp
  Span.cpp

ex02/
  Makefile
  main.cpp
  MutantStack.hpp
  MutantStack.tpp
```

---

## ex00 - Easy Find

### Main Purpose

The main purpose of this exercise is to learn how to write a **function template** that works with different STL containers.

It also introduces the standard STL way of searching through a range using iterators.

### What I Did

I implemented a template function called `easyfind`.

The function takes:

- a container of integers
- an integer value to search for

It searches for the first occurrence of the value inside the container.

The implementation uses:

```cpp
std::find(container.begin(), container.end(), value)
```

If the value is found, the function returns an iterator pointing to it. If the value is not found, the function reports the failure using the chosen error-handling behavior.

### Key Concepts Practiced

- Function templates
- Generic programming
- STL containers
- Iterators
- `begin()` and `end()`
- `std::find`
- Returning an iterator as a search result
- Handling a "not found" case

### What I Learned

This exercise helped me understand that STL algorithms are designed to work with iterator ranges, not with only one specific container type.

Instead of writing a separate search function for `std::vector<int>`, `std::list<int>`, or `std::deque<int>`, a template function can work with any compatible integer container.

---

## ex01 - Span

### Main Purpose

The main purpose of this exercise is to learn how to combine an STL container with STL algorithms inside a class.

The class must store a limited number of integers and calculate the shortest and longest distance between any two stored numbers.

### What I Did

I implemented a `Span` class.

The class stores integers internally and has a maximum capacity defined at construction.

It provides:

```cpp
addNumber()
addNumbers()
shortestSpan()
longestSpan()
```

`addNumber()` adds one integer.

`addNumbers()` adds a range of integers using iterators.

`shortestSpan()` calculates the smallest distance between two stored numbers.

`longestSpan()` calculates the largest distance between two stored numbers.

The class throws exceptions when:

- trying to add more numbers than the allowed capacity
- trying to calculate a span with fewer than two numbers

### Key Concepts Practiced

- `std::vector<int>` as internal storage
- Capacity control
- `std::vector::size()`
- `std::vector::push_back()`
- `std::vector::insert()`
- Iterator ranges: `[first, last)`
- Template member function for range insertion
- `std::sort`
- `std::min_element`
- `std::max_element`
- `static_cast<long>`
- Exception handling with `std::out_of_range` and `std::logic_error`
- `const` member functions
- Orthodox Canonical Form

### Implementation Logic

For `addNumber()`, I first check whether the `Span` is already full. If there is still space, the number is added to the internal vector.

For `addNumbers()`, I first collect the values from the iterator range and check whether the whole range can fit. Only then are the values inserted. This avoids a partial insertion where only some numbers are added before an error occurs.

For `shortestSpan()`, I copy the stored numbers into a temporary vector and sort it. After sorting, the shortest distance must be between two neighboring numbers, so I compare adjacent elements.

For `longestSpan()`, I find the minimum and maximum values. The longest span is the difference between the maximum and minimum value.

### What I Learned

This exercise showed me how STL algorithms can make a class simpler and more reliable.

I learned that sorting can turn a complex comparison problem into a simple adjacent-element comparison.

I also learned why iterator-range functions are useful: they allow the class to accept numbers from different containers without changing the internal storage type.

---

## ex02 - MutantStack

### Main Purpose

The main purpose of this exercise is to understand how `std::stack` works as a **container adapter** and how to expose iterators from its underlying container.

A normal `std::stack` is not iterable. This exercise adds iterator support while keeping normal stack behavior.

### What I Did

I implemented a template class called `MutantStack`.

It inherits from `std::stack` and keeps all normal stack operations:

```cpp
push()
pop()
top()
size()
empty()
```

It also adds iterator support:

```cpp
begin()
end()
rbegin()
rend()
```

The implementation supports:

```cpp
iterator
const_iterator
reverse_iterator
const_reverse_iterator
```

In the more complete version, the class is declared with two template parameters:

```cpp
template <typename T, typename Container = std::deque<T> >
```

This means:

- `T` is the type of element stored in the stack
- `Container` is the underlying container used by the stack
- `std::deque<T>` is the default underlying container, matching the usual behavior of `std::stack`

### Key Concepts Practiced

- Class templates
- `std::stack`
- Container adapters
- Underlying container
- Protected member `c`
- `container_type`
- Type aliases with `typedef`
- `iterator`
- `const_iterator`
- `reverse_iterator`
- `const_reverse_iterator`
- `this->c`
- Template implementation in `.hpp` / `.tpp`
- Compatibility with `std::stack`

### Implementation Logic

`std::stack` stores its data inside an underlying container. This container is accessible from a derived class through the protected member `c`.

`MutantStack` exposes the iterators of that underlying container:

```cpp
this->c.begin()
this->c.end()
this->c.rbegin()
this->c.rend()
```

This makes it possible to traverse the stack like a normal STL container.

Because `MutantStack` still inherits from `std::stack`, it can still be used with standard stack operations such as `push`, `pop`, `top`, and `size`.

### What I Learned

This exercise helped me understand that `std::stack` is not a full standalone container. It is a container adapter built on top of another container, usually `std::deque`.

I also learned how to expose inherited protected data safely through public iterator functions, and why type aliases are useful for making a custom class feel like a standard STL container.

---

## Overall Learning Summary

CPP Module 08 strengthened my understanding of STL-based programming in C++98.

Across the three exercises, I practiced:

- writing generic template functions
- using STL containers to store data
- using iterators to describe ranges
- using STL algorithms instead of rewriting common logic manually
- designing classes around standard containers
- handling invalid states with exceptions
- understanding the difference between containers and container adapters
- making a non-iterable adapter iterable by exposing its underlying container's iterators

The biggest takeaway from this module is that good C++ code often starts by choosing the right STL container and algorithm.

Instead of manually managing arrays, loops, searching, and sorting in every situation, I learned to express solutions using the tools already provided by the C++ standard library.
