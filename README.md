# PUSH_SWAP

## Table of Contents
- [About](#about)
- [Installation](#installation)
- [Usage](#usage)
- [Key Concepts Learned](#key-concepts-learned)
- [Skills Developed](#skills-developed)
- [Project Overview](#project-overview)
- [Algorithm Implementation](#algorithm-implementation)
- [Operations Available](#operations-available)
- [Technical Highlights](#technical-highlights)
- [42 School Standards](#42-school-standards)
- [Related Articles](#-related-articles)
- [Contact](#contact)

## About

This repository contains my implementation of the **push_swap** project at 42 School.
Push_swap is a highly challenging **algorithmic project** that focuses on **sorting optimization** and **computational efficiency**.
The goal is to sort a stack of integers using only a limited set of stack operations, while minimizing the total number of moves required.

This project demonstrates mastery of **sorting algorithms**, **algorithmic optimization**, and **complexity analysis** - core computer science concepts that are fundamental to writing efficient software.
The challenge lies in achieving optimal sorting performance under strict constraints, requiring deep understanding of data structures and algorithm design.


## Installation

### Prerequisites
- **GCC compiler** with C99 standard support
- **Make** utility
- **Unix/Linux environment** for optimal performance

### Compilation
```bash
# Clone the repository
git clone https://github.com/TuroTheReal/push_swap.git
cd push_swap

# Compile the project
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```


## Usage

### Basic Sorting
```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Sort with negative numbers
./push_swap -1 5 -3 42 0

# Using quotes for shell protection
./push_swap "4 67 3 87 23"
```

### Performance Testing
```bash
# Generate random numbers for testing
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Test with larger datasets
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

```

### Benchmark Testing
```bash
# Test different stack sizes
./push_swap $(seq 1 100 | shuf | tr '\n' ' ') | wc -l    # 100 numbers
./push_swap $(seq 1 500 | shuf | tr '\n' ' ') | wc -l    # 500 numbers
```


## Key Concepts Learned

### Advanced Algorithm Design
- **Sorting Algorithm Optimization**: Developing custom algorithms for constrained environments
- **Complexity Analysis**: Understanding time and space complexity trade-offs
- **Algorithmic Strategy**: Choosing optimal approaches for different input sizes
- **Performance Profiling**: Measuring and optimizing algorithm efficiency

### Data Structure Mastery
- **Stack Operations**: Deep understanding of LIFO (Last In, First Out) principles
- **Dual Stack Management**: Coordinating operations between two interconnected stacks
- **Memory Layout Optimization**: Efficient data organization for minimal overhead
- **State Space Analysis**: Understanding all possible configurations and transitions

### Mathematical Problem Solving
- **Combinatorial Optimization**: Finding optimal solutions in large solution spaces
- **Heuristic Development**: Creating intelligent decision-making algorithms
- **Pattern Recognition**: Identifying optimal move sequences and recurring patterns
- **Complexity Bounds**: Understanding theoretical limits and practical constraints

### Software Engineering Principles
- **Algorithm Implementation**: Translating theoretical concepts into efficient code
- **Performance Engineering**: Writing code optimized for specific performance metrics
- **Error Handling**: Robust input validation and edge case management
- **Modular Design**: Creating reusable, maintainable algorithmic components


## Skills Developed

- **Algorithmic Thinking**: Advanced problem-solving and optimization skills
- **Performance Engineering**: Writing highly efficient, optimized code
- **Mathematical Analysis**: Applying mathematical concepts to programming challenges
- **System Optimization**: Understanding hardware-software performance interactions
- **Complex Problem Decomposition**: Breaking down intricate problems into manageable parts
- **Competitive Programming**: Skills applicable to technical interviews and coding contests
- **Research and Analysis**: Evaluating different algorithmic approaches scientifically


## Project Overview

Push_swap challenges students to develop an efficient sorting algorithm using only a restricted set of operations on two stacks (A and B).
The project requires both algorithmic creativity and implementation excellence to achieve optimal performance across different input sizes.

### Core Challenge
Sort a stack of integers using a limited set of operations (push, swap and rotate) and minimize the number of moves.
The algorithm must handle various input sizes efficiently while maintaining correctness.

### Key Components

**Algorithm Engine**: Custom-designed sorting algorithm optimized for the specific constraints of dual-stack operations.
**Operation Optimizer**: Intelligent move selection system that chooses optimal operations based on current stack state.
**Input Validator**: Comprehensive validation system ensuring proper input format and duplicate detection.
**Performance Monitor**: Built-in operation counting and efficiency tracking for algorithm analysis.
**Stack Manager**: Efficient dual-stack implementation with optimized memory usage and operation handling.


## Algorithm Implementation

### Strategic Approaches

**Small Stack Optimization (<= 5 elements)**:
- Hand-crafted optimal solutions
- Hardcoded decision trees for maximum efficiency
- Zero algorithmic overhead

**Other Stack Strategy (> 5 elements)**:
- Intelligent chunk-based sorting
- Strategic element positioning
- Optimized rotation patterns
- Optimized for minimal operation count


## Operations Available

### Stack Operations
```c
// Swap operations
sa    // Swap first 2 elements of stack A
sb    // Swap first 2 elements of stack B
ss    // Swap both stacks simultaneously

// Push operations
pa    // Push top element from B to A
pb    // Push top element from A to B

// Rotate operations
ra    // Rotate stack A upward (first becomes last)
rb    // Rotate stack B upward
rr    // Rotate both stacks upward

// Reverse rotate operations
rra   // Rotate stack A downward (last becomes first)
rrb   // Rotate stack B downward
rrr   // Rotate both stacks downward
```

### Strategic Operation Usage
- **Double Operations** (ss, rr, rrr): Maximum efficiency when both stacks need the same operation
- **Position Optimization**: Calculating optimal rotation directions (ra/rra) based on element position
- **Push Strategy**: Strategic use of pb/pa for temporary storage and sorting phases


## Technical Highlights

### Optimization Techniques
- **Preprocessing**: Input analysis for algorithm selection and optimization
- **Move Prediction**: Lookahead algorithms for optimal operation sequencing
- **Pattern Recognition**: Identifying and exploiting common sorting patterns

### Advanced Features
- **Adaptive Algorithm Selection**: Choosing optimal strategy based on input characteristics
- **Operation Compression**: Combining operations for maximum efficiency
- **Error Recovery**: Robust handling of edge cases and invalid inputs

### Code Quality
- **Modular Design**: Clean separation of algorithm logic, stack operations, and I/O
- **Performance Profiling**: Built-in operation counting and efficiency analysis
- **Comprehensive Testing**: Validation across various input sizes and patterns


## 42 School Standards

### Norm Requirements
- ✅ Maximum 25 lines per function
- ✅ Maximum 5 functions per file
- ✅ Proper indentation and formatting
- ✅ No forbidden functions usage
- ✅ Compilation without warnings (-Wall -Wextra -Werror)

### Project Standards
- ✅ Comprehensive error handling for invalid inputs
- ✅ No memory leaks (validated with valgrind)
- ✅ Efficient algorithm implementation
- ✅ Proper input validation (duplicates, non-integers, overflow)
- ✅ Orthodox Canonical Form for data structures

### Performance Requirements
- ✅ 3 numbers: ≤ 3 operations
- ✅ 5 numbers: ≤ 12 operations
- ✅ 100 numbers: ≤ 1500 operations (grade 4/5)
- ✅ 500 numbers: ≤ 11500 operations (grade 5/5)
- ✅ Correct output format for all valid inputs

### Bonus Features
- ✅ **Checker Program**: Validates if a sequence of operations correctly sorts the input
- ✅ **Advanced Error Handling**: Comprehensive validation of edge cases
- ✅ **Visualization Tools**: Optional tools for algorithm analysis and debugging
- ✅ **Performance Analytics**: Detailed operation counting and efficiency metrics


## 📝 Related Articles

Blog posts documenting the learning process and context behind this project:

- 📝 [42 Piscine and Common Core: What I Learned](https://arthurbernard.dev/en/blog/42-piscine-and-core-curriculum) — Reflections on 42 School's selection process and 2-year curriculum

---
## Contact

- **GitHub**: [@TuroTheReal](https://github.com/TuroTheReal)
- **Email**: arthurbernard.dev@gmail.com
- **LinkedIn**: [Arthur Bernard](https://www.linkedin.com/in/arthurbernard92/)

---

<p align="center">
  <img src="https://img.shields.io/badge/Made%20with-C-blue.svg"/>
  <img src="https://img.shields.io/badge/Algorithm-Sorting%20Optimization-green.svg"/>
  <img src="https://img.shields.io/badge/Complexity-O(n)-red.svg"/>
</p>
