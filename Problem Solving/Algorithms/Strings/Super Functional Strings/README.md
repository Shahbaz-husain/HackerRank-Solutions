We define a function, , on a string, , as follows:

where:

 denotes the number of characters in string .
 denotes the number of distinct characters in string .
Consuela loves creating string challenges and she needs your help testing her newest one! Given a string, , consisting of  lowercase letters, compute the summation of function  (provided above) over all possible distinct substrings of . As the result is quite large, print it modulo .

Input Format

The first line contains a single integer, , denoting the number of test cases.
Each of the  subsequent lines contains a string, .

Constraints

The sum of  over all test cases does not exceed .
Scoring

 for  of test data.
 for  of test data.
 for  of test data.
Output Format

For each test case, print the answer modulo .

Sample Input

3
aa
aba
abc
Sample Output

3
19
38
Explanation

Test 0:

 and  are the only distinct substrings.


Test 1:

, , , , and  are the only distinct substrings.


