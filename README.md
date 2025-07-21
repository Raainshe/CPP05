# C++ Module 05 - Repetition and Exceptions

## 📋 Project Overview

**CPP05** simulates an "artificial nightmare of offices, corridors, forms, and waiting queues" - a bureaucratic system implementation in C++. This project focuses on **exception handling**, **inheritance**, **polymorphism**, and **proper class design** following the Orthodox Canonical Form.

## 🎯 Learning Objectives

- **Exception Handling**: Creating and throwing custom exceptions
- **Inheritance & Polymorphism**: Abstract classes and virtual functions
- **RAII**: Resource Acquisition Is Initialization pattern
- **Factory Pattern**: Creating objects through factory methods
- **Memory Management**: Proper use of `new`/`delete` and exception safety

## 🏗️ Project Structure

```
CPP05/
├── ex00/           # Bureaucrat class with exception handling
├── ex01/           # Form class with signing mechanism
├── ex02/           # Abstract AForm with concrete implementations
├── ex03/           # Intern factory class
└── README.md       # This file
```

## 📚 Exercises

### Exercise 00: "Mommy, when I grow up, I want to be a bureaucrat!"
**Objective**: Create a Bureaucrat class with grade validation and custom exceptions.

**Features**:
- **Bureaucrat class** with constant name and grade (1-150)
- **Custom exceptions**: `GradeTooHighException`, `GradeTooLowException`
- **Grade manipulation**: increment/decrement with boundary checking
- **Stream output**: Formatted bureaucrat information

**Key Concepts**: Exception throwing/catching, const correctness, operator overloading

### Exercise 01: "Form up, maggots!"
**Objective**: Create a Form class that can be signed by bureaucrats.

**Features**:
- **Form class** with signing requirements and status
- **Bureaucrat-Form interaction**: `beSigned()` and `signForm()` methods
- **Authorization checking**: Grade-based access control
- **Error handling**: Appropriate exception messages

**Key Concepts**: Class interaction, authorization patterns, method chaining

### Exercise 02: "No, you need form 28B, not 28C..."
**Objective**: Create an abstract form system with concrete implementations.

**Features**:
- **Abstract AForm class** with pure virtual `execute()` method
- **Three concrete forms**:
  - `ShrubberyCreationForm` (145/137): Creates ASCII art files
  - `RobotomyRequestForm` (72/45): 50% success rate with drilling sounds
  - `PresidentialPardonForm` (25/5): Presidential pardon by Zaphod Beeblebrox
- **Polymorphic execution**: `executeForm()` method in Bureaucrat class
- **File operations**: Safe file handling with error checking

**Key Concepts**: Abstract classes, polymorphism, file I/O, random generation

### Exercise 03: "At least this beats coffee-making"
**Objective**: Implement an Intern factory class to create forms by name.

**Features**:
- **Intern class**: Factory pattern for form creation
- **String-to-enum conversion**: Switch statement with helper function
- **Form factory method**: `makeForm()` with name-based creation
- **Custom exception**: `FormNotFoundException`
- **Memory management**: Proper allocation and cleanup

**Key Concepts**: Factory pattern, string processing, switch statements, memory management

## 🛠️ Compilation & Usage

### Prerequisites
- C++ compiler with C++98 support
- Make utility

### Compilation
```bash
# For each exercise directory
cd ex0X/
make

# Clean build files
make clean

# Clean everything including executables
make fclean

# Rebuild everything
make re
```

### Running Tests
```bash
# Each exercise produces an executable named 'bureaucrat'
./bureaucrat

# Check generated files (ex02/ex03)
ls -la *.txt
```

## 🔧 Implementation Details

### Exception Safety
- **RAII pattern** for automatic resource management
- **Exception specifications** using `throw()` notation
- **Proper cleanup** in destructors and exception handling

### Memory Management
- **Dynamic allocation** for form creation in Intern class
- **Proper cleanup** with `delete` in tests
- **Exception safety** during object construction

### Polymorphism
- **Virtual destructors** for proper polymorphic destruction
- **Pure virtual functions** in abstract AForm class
- **Base class pointers** for polymorphic behavior

## 📁 Generated Files

The project creates several output files during execution:

- **ex02**: `*_shrubbery.txt` files with ASCII art trees
- **ex03**: Additional shrubbery files from intern-created forms

## 🧪 Test Coverage

Each exercise includes comprehensive tests:

- **Constructor/Destructor testing**
- **Exception handling verification**
- **Boundary condition testing**
- **Integration testing between classes**
- **Memory management validation**

## ⚡ Key Features Demonstrated

### Exception Handling
```cpp
try {
    Bureaucrat bob("Bob", 0);  // Too high!
} catch (const Bureaucrat::GradeTooHighException& e) {
    std::cout << e.what() << std::endl;
}
```

### Polymorphism
```cpp
AForm* form = intern.makeForm("shrubbery creation", "garden");
form->execute(bureaucrat);  // Polymorphic call
delete form;
```

### Factory Pattern
```cpp
Intern intern;
AForm* forms[3];
forms[0] = intern.makeForm("robotomy request", "target");
forms[1] = intern.makeForm("presidential pardon", "criminal");
```

## 🎨 ASCII Art Feature

The ShrubberyCreationForm creates beautiful ASCII tree art in files:

```
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠖⠒⠢⣄⣀⡀⣀⣀⠀⡠⠔⠒⠒⢤⡀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⡇⠀⠀⠀⠁⠠⡋⠀⠀⠙⠦⠀⠀⠀⠀⣧⠤⣀⠀⠀⠀⠀
[... beautiful tree continues ...]
```

## 🏆 Project Highlights

- **Complete exception hierarchy** with meaningful error messages
- **Robust error handling** throughout all operations
- **Clean polymorphic design** with proper virtual destructors
- **Safe file operations** with comprehensive error checking
- **Comprehensive test suite** covering all functionality
- **Memory leak prevention** with proper RAII patterns

## 📖 Subject Compliance

This implementation fully complies with the 42 School CPP05 subject requirements:
- ✅ Orthodox Canonical Form for all classes
- ✅ C++98 standard compliance
- ✅ Proper exception handling
- ✅ No forbidden functions or libraries
- ✅ Comprehensive testing coverage
- ✅ All mandatory features implemented

---

*"In the end, we will remember not the words of our enemies, but the silence of our forms."* - A bureaucrat, probably