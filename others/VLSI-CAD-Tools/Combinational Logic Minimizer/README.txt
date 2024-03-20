This Python program uses ESPRESSO heuristic to perform 2-level logic minimization of a boolean function.
Truth table input specified in csv file is necessary. Future work will include ESPRESSO heuristic minimization from boolean function expression.

The tool asks for user input for desired propagation delay.
-> If the constraint can be met within certain number of iterations, it will stop and provide the result.
-> If the constraint can't be met even after maximum allowed number of iterations, it will provide the best result found.

The tool provides expression of final result and its corresponding propagation delay.

Dependencies: Numpy, Pandas, Random
