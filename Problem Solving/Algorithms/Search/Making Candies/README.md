Karl loves playing games on social networking sites. His current favorite is CandyMaker, where the goal is to make candies.

Karl just started a level in which he must accumulate  candies starting with  machines and  workers. In a single pass, he can make  candies. After each pass, he can decide whether to spend some of his candies to buy more machines or hire more workers. Buying a machine or hiring a worker costs  units, and there is no limit to the number of machines he can own or workers he can employ.

Karl wants to minimize the number of passes to obtain the required number of candies at the end of a day. Determine that number of passes.

For example, Karl starts with  machine and  workers. The cost to purchase or hire,  and he needs to accumulate  candies. He executes the following strategy:

Make  candies. Purchase two machines.
Make  candies. Purchase  machines and hire  workers.
Make  candies. Retain all  candies.
Make  candies. With yesterday's production, Karl has  candies.
It took  passes to make enough candies.

Function Description

Complete the minimumPasses function in the editor below. The function must return a long integer representing the minimum number of passes required.

minimumPasses has the following parameter(s):

m: long integer, the starting number of machines
w: long integer, the starting number of workers
p: long integer, the cost of a new hire or a new machine
n: long integer, the number of candies to produce
Input Format

A single line consisting of four space-separated integers describing the values of , , , and , the starting number of machines and workers, the cost of a new machine or a new hire, and the the number of candies Karl must accumulate to complete the level.

Constraints

Output Format

Return a long integer denoting the minimum number of passes required to accumulate at least  candies.

Sample Input

3 1 2 12
Sample Output

3
Explanation

Karl makes three passes:

In the first pass, he makes  candies. He then spends  of them hiring another worker, so  and he has one candy left over.
In the second pass, he makes  candies. He spends  of them on another machine and another worker, so  and  and he has  candies left over.
In the third pass, Karl makes  candies. Because this satisfies his goal of making at least  candies, we print the number of passes (i.e., ) as our answer.