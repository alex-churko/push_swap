🔁  push_swap — Sorting with two stacks

push_swap is a constrained sorting project in C, built as part of the 42 curriculum.
The goal is to sort a stack of integers using only a limited set of stack operations
on two stacks, `a` and `b`, while minimizing the total number of operations.

This project is a practical introduction to:

	• algorithmic thinking
	• time complexity and optimization
	• stack data structures
	• input validation and error handling
	• writing clean and maintainable C code


DESCRIPTION

The program `push_swap` receives a list of integers as arguments. These integers
are stored in stack `a`, while stack `b` starts empty.

The objective:

	• Sort stack `a` in ascending order (smallest value at the top),
	  using only the allowed operations on stacks `a` and `b`.
	• Print the sequence of operations, one per line, to standard output.
	• Achieve the sorting with the lowest possible number of moves.

The program must:

	• Handle invalid input (non-integer values, overflows, duplicates).
	• Print "Error" followed by a newline to standard error in case of any error.
	• Do nothing and print nothing if no arguments are given.


ALLOWED OPERATIONS

You are only allowed to use the following stack operations:

	sa   → swap the first two elements of stack a
	sb   → swap the first two elements of stack b
	ss   → sa and sb at the same time

	pa   → take the first element at the top of b and put it on top of a
	pb   → take the first element at the top of a and put it on top of b

	ra   → rotate a upwards (first element becomes last)
	rb   → rotate b upwards
	rr   → ra and rb at the same time

	rra  → reverse rotate a (last element becomes first)
	rrb  → reverse rotate b
	rrr  → rra and rrb at the same time


INSTRUCTIONS

Compilation:

	The project comes with a Makefile including the following rules:

		make        → compile the push_swap binary
		make clean  → remove object files
		make fclean → remove objects and binary
		make re     → rebuild from scratch

Usage:

	./push_swap <list of integers>

Examples:

	./push_swap 2 1 3 6 5 8
	(sa / pb / pa ... operations printed here)

	./push_swap 0 one 2 3
	Error

Checker usage (with the official checker_OS binary):

	ARG="4 67 3 87 23"
	./push_swap $ARG | wc -l              (count operations)
	./push_swap $ARG | ./checker_OS $ARG  (verify: OK / KO)


BENCHMARKS & COMPLEXITY

During evaluation, the efficiency of your algorithm is tested on random data sets.

For full validation (100%) and bonus eligibility:

	• Sort 100 random numbers in under 700 operations.
	• Sort 500 random numbers in no more than 5500 operations.

The project is centered around:

	• designing a sorting strategy adapted to constraints
	• balancing operations between the two stacks
	• minimizing the total instruction count in practice


POSSIBLE ALGORITHMIC APPROACHES (HIGH LEVEL)

Some typical ideas (implementation-specific):

	• Indexing or normalizing values before sorting
	• Using chunk-based strategies for medium/large input sizes
	• Radix-like approaches for big input sets
	• Carefully combining rotations (rr / rrr) to reduce moves
	• Separating small-input logic (e.g. 3 / 5 elements) from large-input logic


RESOURCES

Classic references:

	• Sorting algorithms & complexity (Big-O notation)
	• Stack data structures and operations
	• 42 push_swap subject PDF and checker_OS documentation

AI usage in this project:

	• Drafting and structuring this README text
	• Refining wording and English phrasing for clarity
	• Discussing high-level algorithm design ideas and trade-offs

All core logic, validation, and implementation decisions of the push_swap algorithm
are written and understood by the author and can be explained during peer evaluation.


AUTHOR

	Name:   Oleksandr Churko
	School: 42 Wolfsburg 🇩🇪
