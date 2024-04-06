Alice was given the  integers from  to . She wrote all possible permutations in increasing lexicographical order, and wrote each permutation in a new line. For example, for , there are  possible permutations:

She then chose one permutation among them as her favorite permutation.

After some time, she forgot some elements of her favorite permutation. Nevertheless, she still tried to write down its elements. She wrote a  in every position where she forgot the true value.

She wants to know the sum of the line numbers of the permutations which could possibly be her favorite permutation, i.e., permutations which can be obtained by replacing the s. Can you help her out?

Since the sum can be large, find it modulo .

Input Format

The first line contains a single integer .

The next line contains  space-separated integers  denoting Alice's favorite permutation with some positions replaced by .

Constraints

The positive values appearing in  are distinct.
Subtask

For ~33% of the total points, 
Output Format

Print a single line containing a single integer denoting the sum of the line numbers of the permutations which could possibly be Alice's favorite permutation.

Sample Input 0

4
0 2 3 0
Sample Output 0

23
Explanation 0

The possible permutations are  and . The permutation  occurs on line  and the permutation  occurs on line . Therefore the sum is .

Sample Input 1

4
4 3 2 1
Sample Output 1

24
Explanation 1

There is no missing number in the permutation. Therefore, the only possible permutation is , and it occurs on line . Therefore the sum is .