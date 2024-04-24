We call an quadruple of positive integers, , beautiful if the following condition is true:

Note:  is the bitwise XOR operator.

Given , , , and , count the number of beautiful quadruples of the form  where the following constraints hold:

When you count the number of beautiful quadruples, you should consider two quadruples as same if the following are true:

They contain same integers.
Number of times each integers occur in the quadruple is same.
For example  and  should be considered as same.

Input Format

A single line with four space-separated integers describing the respective values of , , , and .

Constraints

For  of the maximum score, 
Output Format

Print the number of beautiful quadruples.

Sample Input

1 2 3 4
Sample Output

11
Explanation

There are  beautiful quadruples for this input:

Thus, we print  as our output.

Note that  is same as .