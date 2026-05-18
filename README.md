# CPP Module 08 - Templated Containers, Iterators, Algorithms

This repository contains my solutions for **42 School C++ Module 08**.

The main goal of this module is to practice using the **STL**: standard containers, iterators, and algorithms.  
Instead of manually rewriting common data structures or algorithms, this module focuses on choosing the right STL tool and using it correctly in a C++98 project.

## General Requirements

- Compile with `c++`
- Use the flags `-Wall -Wextra -Werror`
- Compatible with `-std=c++98`
- No external libraries
- No `using namespace std`
- Use STL containers and algorithms where appropriate
- Follow Orthodox Canonical Form for classes when needed

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

# ex00 - Easy Find

## Main Learning Goal

The purpose of this exercise is to learn how to write a **function template** that works with different STL containers.

It also introduces the idea that STL algorithms usually work through **iterators**, not directly through one specific container type.

## What I Implemented

I implemented a template function:

```cpp
easyfind(container, value)
```

The function takes:

- a container of integers
- an integer value to search for

It uses `std::find` to search for the first occurrence of the value in the container.

If the value is found, the function returns an iterator pointing to it.  
If the value is not found, the function throws an exception.

## Key Concepts Practiced

- Function templates
- Generic programming
- `typename T::iterator`
- `std::find`
- `begin()` and `end()`
- STL-style error handling through exceptions

## What I Learned

This exercise helped me understand how one function can work with several different container types, such as `std::vector<int>`, `std::list<int>`, or `std::deque<int>`.

I also learned why STL algorithms are designed around iterator ranges.  
Instead of writing a separate search function for each container, I can write one generic function that works with any compatible integer container.

---

# ex01 - Span

## Main Learning Goal

The purpose of this exercise is to learn how to store and process a group of numbers using STL containers and algorithms.

The exercise also introduces a practical use of iterator ranges to insert many values at once.

## What I Implemented

I implemented a `Span` class that stores a limited number of integers.

The class supports:

```cpp
addNumber()
shortestSpan()
longestSpan()
addNumbers()
```

`addNumber()` adds one integer to the container.

`shortestSpan()` returns the smallest distance between any two stored numbers.

`longestSpan()` returns the largest distance between any two stored numbers.

`addNumbers()` inserts a whole range of numbers using iterators, which avoids calling `addNumber()` thousands of times manually.

The class throws exceptions when:

- adding a number beyond the maximum capacity
- trying to calculate a span with fewer than two numbers
- trying to insert a range that does not fit in the remaining capacity

## Key Concepts Practiced

- `std::vector<int>` as internal storage
- Capacity control
- `std::sort`
- `std::min_element`
- `std::max_element`
- `std::distance`
- Range insertion with iterators
- Exception-safe insertion logic
- Orthodox Canonical Form

## Implementation Logic

For the shortest span, I copy the stored numbers into a temporary vector, sort it, then compare each pair of neighboring values.  
After sorting, the shortest distance must be between two adjacent elements.

For the longest span, I find the minimum and maximum values using STL algorithms.  
The longest distance is the difference between the maximum and minimum values.

For range insertion, I first calculate how many elements are going to be inserted.  
Only if there is enough remaining capacity do I insert the range.  
This avoids partially inserting values before detecting an error.

## What I Learned

This exercise showed me how STL algorithms can simplify numeric processing.

I learned that sorting can transform a difficult comparison problem into a simple neighboring-element comparison.  
I also learned how to design safer insertion logic by checking capacity before modifying the object.

The range insertion function helped me understand how STL containers commonly accept iterator pairs to represent a sequence of values.

---

# ex02 - MutantStack

## Main Learning Goal

The purpose of this exercise is to understand how `std::stack` works as a **container adapter** and how to expose iterators from its underlying container.

A normal `std::stack` is not iterable.  
This exercise adds iteration support while keeping all normal stack behavior.

## What I Implemented

I implemented a template class:

```cpp
MutantStack<T>
```

It inherits from `std::stack<T>`.

It keeps all standard stack operations, such as:

```cpp
push()
pop()
top()
size()
empty()
```

and adds iterator support:

```cpp
begin()
end()
rbegin()
rend()
```

The implementation also provides:

```cpp
iterator
const_iterator
reverse_iterator
const_reverse_iterator
```

This makes `MutantStack` usable in a way similar to standard iterable containers.

## Key Concepts Practiced

- `std::stack`
- Container adapters
- Underlying container
- Protected member `c`
- `container_type`
- Iterator type aliases
- `this->c`
- Template class implementation in `.hpp` / `.tpp`
- Reverse iterators
- Const iterators

## Implementation Logic

`std::stack` stores its elements inside an underlying container.

That underlying container is accessible in a derived class through the protected member `c`.

`MutantStack` exposes the underlying container's iterators by returning:

```cpp
this->c.begin()
this->c.end()
this->c.rbegin()
this->c.rend()
```

Because `MutantStack` inherits from `std::stack`, it can still be used as a normal stack.  
At the same time, it can be traversed with iterators.

## What I Learned

This exercise helped me understand that `std::stack` is not a full container by itself, but a container adapter built on top of another container.

I learned how inheritance can be used to extend an STL adapter in a controlled way, and how the underlying container makes iteration possible.

I also learned why template class implementations usually need to be visible from the header file or included through a `.tpp` file.

---

# Overall Summary

CPP Module 08 strengthened my understanding of STL-based programming in C++98.

Across the three exercises, I practiced:

- writing generic template functions
- using STL containers to manage data
- using iterators to describe ranges
- using STL algorithms instead of rewriting common logic manually
- designing classes that combine STL tools with proper exception handling
- understanding the difference between containers and container adapters

The main takeaway from this module is that good C++ code often starts by choosing the right standard container and algorithm.

Instead of manually managing arrays, loops, sorting, and searching in every situation, I learned to express the solution using the tools provided by the STL.
