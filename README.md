Successfully developed and implemented a DPLL algorithm based Boolean Satisfiability(SAT) solver using C++ programming language.This project involves implementing the key components of the DPLL algorithm, such as unit propagation and backtracking, and testing its effectiveness on a range of SAT problem instances. Additionally, optimizations and improvements to enhance the performance of the solver.

The idea behind the modification, is to set the highest occurring proposition true in order to reduce the length of the formula by removing the clause from the formula. If the assignment gives a conflict, it assigns the proposition as false and recursively calls the DPLL() function. If the formula returns true for any of the combinations of the propositions, then the formula is said to be sat and if it is unable to find the combinations of the proposition for which it is true, then the formula is declared as UNSAT.