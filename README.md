# 42 C++ Modules (CPP00-CPP09)

This repository contains my full 42 School C++ journey, from the first object-oriented basics to STL-heavy algorithmic exercises.

All projects are written in **C++98** and follow the 42 coding constraints.

## What This Repository Covers

The modules are progressive:

1. Build strong C++ fundamentals.
2. Master object-oriented design (encapsulation, inheritance, polymorphism).
3. Learn memory safety, copy semantics, and exception handling.
4. Use templates, containers, and algorithms from the Standard Library.
5. Solve practical parsing and performance problems.

## Repository Structure

Each module contains one or more exercises:

- `CPP00/ex00` to `CPP00/ex02`
- `CPP01/ex00` to `CPP01/ex06`
- `CPP02/ex00` to `CPP02/ex02`
- `CPP03/ex00` to `CPP03/ex02`
- `CPP04/ex00` to `CPP04/ex03`
- `CPP05/ex00` to `CPP05/ex03`
- `CPP06/ex00` to `CPP06/ex02`
- `CPP07/ex00` to `CPP07/ex02`
- `CPP08/ex00` to `CPP08/ex02`
- `CPP09/ex00` to `CPP09/ex02`

## Module-by-Module Learning Goals

### CPP00 - C++ Basics

**Exercises:** Megaphone, PhoneBook, Account  
**What you learn:**

- Basic syntax differences from C
- Classes and objects
- Member functions and visibility (public/private)
- Constructors and destructors
- Streams (`std::cin`, `std::cout`, formatting)

### CPP01 - Memory and References

**Exercises:** Zombie, Zombie Horde, references/pointers, Weapon, file replace, Harl  
**What you learn:**

- Stack vs heap allocation
- `new` / `delete` lifecycle
- References vs pointers and when to use each
- Basic file manipulation
- Better class design with clear ownership rules

### CPP02 - Canonical Form and Operator Overloading

**Exercises:** Fixed-point numbers and operators  
**What you learn:**

- Orthodox Canonical Form
- Copy constructor and copy assignment operator
- Operator overloading (`+`, `-`, comparison, increment, etc.)
- Static member functions
- Precise value representation with fixed-point arithmetic

### CPP03 - Inheritance

**Exercises:** ClapTrap, ScavTrap, FragTrap  
**What you learn:**

- Base/derived class relationships
- Constructor/destructor chaining
- Method overriding
- Protected members and class extension design

### CPP04 - Polymorphism and Abstract Interfaces

**Exercises:** Animal hierarchy, Brain deep copy, Materia system  
**What you learn:**

- Runtime polymorphism with `virtual`
- Importance of virtual destructors
- Abstract classes and interfaces
- Deep copy vs shallow copy in composed objects
- Interface-driven architecture

### CPP05 - Exceptions and Bureaucracy Model

**Exercises:** Bureaucrat, Form/AForm, concrete forms, Intern factory  
**What you learn:**

- Exception classes and error signaling
- Grade-bound invariants and defensive programming
- Nested class responsibilities
- Factory-style object creation (Intern)
- Executable workflows with validation steps

### CPP06 - C++ Casts and Type Handling

**Exercises:** ScalarConverter, Serializer, RTTI identification  
**What you learn:**

- Scalar conversion edge cases and literal parsing
- Serialization with `reinterpret_cast`
- Runtime type identification (`dynamic_cast`)
- Safe cast selection and conversion limits

### CPP07 - Templates

**Exercises:** `whatever`, `iter`, `Array` template  
**What you learn:**

- Function templates
- Class templates
- Generic programming patterns
- Template implementation organization (`.hpp` / `.tpp`)
- Type-independent utility design

### CPP08 - STL Containers and Algorithms

**Exercises:** easyfind, Span, MutantStack  
**What you learn:**

- Standard containers usage and trade-offs
- Iterators and algorithm interoperability
- Efficient range computations
- Extending/adapting STL containers

### CPP09 - Practical Data Processing and Performance

**Exercises:** BitcoinExchange, RPN, PmergeMe  
**What you learn:**

- Input parsing and validation
- Map-based historical lookup logic
- Reverse Polish Notation evaluation with stacks
- Ford-Johnson-inspired merge-insert strategy
- Comparing behavior and performance across containers

## Build and Run

From any exercise directory:

```bash
cd CPP0X/exYY
make
./<program_name>
```

Common useful targets:

```bash
make
make clean
make fclean
make re
```

## Compilation Standard

- Standard: **C++98**
- Typical flags: `-Wall -Wextra -Werror -std=c++98`

## Why These Modules Matter

This curriculum builds the mindset needed for robust C++ development:

- Design first, then implementation
- Strict memory and ownership discipline
- Correct copy behavior and resource management
- Reliable error handling
- Efficient use of generic and STL-based solutions
