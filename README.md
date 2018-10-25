# Logic Assignment 2

Submission for Assignment 2 of CS F214 - Logic in CS, 2018-19.

## Running
Start by running the `Logic` file (precompiled) in a Linux terminal. 

## Features
+ Modularized code, separated into various files.
+ Namespaces for constants so as to not pollute the global namespace.
+ Well documented, including time complexities of every function.
+ Performance and stress tested, to see the limits of the program. 

### Part 1

+ Convert an infix expression to postfix form
+ Convert a postfix expression to a Binary Parse Tree
+ Convert a Binary Parse Tree to infix expression

### Part 2

+ Check validity of a given proof in propositional logic with a limited set of rules
  + Premise
  + And introduction
  + And elimination
  + Or introduction
  + Implication eliminiation
  + Modus Tollens

+ We convert the formula of each line to its parse tree, and then compare the inorder strings of previous proof lines as required by the rule.

## Assumptions and Performance Testing

### Part 1
+ We assume that the given formula of only contains propositional atoms made up of the 26 lowercase English alphabets, and that it is well formed propositional formula.
+ We have implemented a operator priority based approach to resolve ambiguity in case the formula is not well parenthesized.

#### Memory
![1](performance/Part1-Memory-1.png)
![2](performance/Part1-Memory-2.png)
Crashed (2819 atoms):
![3](performance/Part1-Memory-3-Crashed.png)

#### Time
![1](performance/Part1-Time.png)

### Part 2

#### Memory
![1](performance/Part2-Valid-Invalid.png)

#### Time
![1](performance/Part2-Time.png)

## Tools used
+ Editors and IDEs: Sublime Text, Vim, CLion
+ Compilers: gcc and cmake
+ Performance test: valgrind
+ Documentation: doxygen
+ Version Control: git, with a repo hosted at local gitlab [server](https://td.bits-hyderabad.ac.in/lab/mach64/logic-assgn-2/).

## Contributors

+ [Krut Patel](f20170184@hyderabad.bits-pilani.ac.in)
+ [Niral Khambhati](f20170130@hyderabad.bits-pilani.ac.in)

