A palindrome is a string that reads the same from left to right as it does from right to left.

Given a string, , of  lowercase English letters, we define a -length rotation as cutting the first  characters from the beginning of  and appending them to the end of . For each , there are  possible -length rotations (where ). See the Explanation section for examples.

Given  and , find all  -length rotations of ; for each rotated string, , print the maximum possible length of any palindromic substring of  on a new line.

Input Format

The first line contains an integer,  (the length of ).
The second line contains a single string, .

Constraints

Output Format

There should be  lines of output, where each line  contains an integer denoting the maximum length of any palindromic substring of rotation .

Sample Input 0

13
aaaaabbbbaaaa
Sample Output 0

12
12
10
8
8
9
11
13
11
9
8
8
10
Sample Input 1

7
cacbbba
Sample Output 1

3
3
3
3
3
3
3
Sample Input 2

12
eededdeedede
Sample Output 2

5
7
7
7
7
9
9
9
9
7
5
4
Explanation

Consider Sample Case 1, where .

The possible rotations, , for string  are:
.






The longest palindromic substrings for each  are:
 and , so we print their length () on a new line.
, so we print its length () on a new line.
 and , so we print their length () on a new line.
 and , so we print their length () on a new line.
 and , so we print their length () on a new line.
 and , so we print their length () on a new line.
 and , so we print their length () on a new line.