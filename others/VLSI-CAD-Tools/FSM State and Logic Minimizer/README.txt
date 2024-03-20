This Python program performs FSM state minimization and output logic, next state logic minimization.
It requires state transition table specified in certain format in csv file as input.

Equivalence checking is performed to reduce number of essential states in the FSM.
ESPRESSO heuristic is used to minimize the next state logic and output logic functions of the FSM.

The tool provides the following outputs:
-> Output logic in terms of inputs and present state
-> Next state logic in terms of inputs and present state
-> Critical path delay (i.e worst case delay among all the logic functions found)

Dependencies : Numpy, Pandas, Random
