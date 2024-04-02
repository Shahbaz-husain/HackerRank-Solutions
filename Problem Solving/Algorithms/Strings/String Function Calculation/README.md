Jane loves strings more than anything. She has a string  with her, and value of string  over function  can be calculated as given below:

Jane wants to know the maximum value of  among all the substrings  of string . Can you help her?

Input Format
A single line containing string  .

Output Format
Print the maximum value of  among all the substrings  of string .

Constraints

The string consists of lowercase English alphabets.

Sample Input 0

aaaaaa
Sample Output 0

12
Explanation 0

f('a') = 6
f('aa') = 10
f('aaa') = 12
f('aaaa') = 12
f('aaaaa') = 10
f('aaaaaa') = 6
Sample Input 1

abcabcddd
Sample Output 1

9
Explanation 1

f values of few of the substrings are shown below:

f("a") = 2
f("b") = 2
f("c") = 2
f("ab") = 4
f("bc") = 4
f("ddd") = 3
f("abc") = 6
f("abcabcddd") = 9
Among the function values 9 is the maximum one.