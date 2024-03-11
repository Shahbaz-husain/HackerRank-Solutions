Consider a string, , of  lowercase English letters where each character,  (, denotes the letter at index  in . We define an  palindromic tuple of  to be a sequence of indices in  satisfying the following criteria:

, meaning the characters located at indices  and  are the same.
, meaning the characters located at indices  and  are the same.
, meaning that , , , and  are ascending in value and are valid indices within string .
Given , find and print the number of  tuples satisfying the above conditions. As this value can be quite large, print it modulo .

Function Description
Complete the function shortPalindrome in the editor below.

shortPalindrome has the following paramter(s):
- string s: a string

Returns
- int: the number of tuples, modulo 

Input Format

A single string, .

Constraints

It is guaranteed that  only contains lowercase English letters.
Sample Input 0

kkkkkkz
Sample Output 0

15
Explanation 0

The letter z will not be part of a valid tuple because you need at least two of the same character to satisfy the conditions defined above. Because all tuples consisting of four k's are valid, we just need to find the number of ways that we can choose four of the six k's. This means our answer is .

Sample Input 1

ghhggh
Sample Output 1

4
Explanation 1

The valid tuples are:

Thus, our answer is .

Sample Input 0

kkkkkkz
Sample Output 0

15
Sample Input 1

abbaab
Sample Output 1

4
Sample Input 2

akakak
Sample Output 2

2
Explanation 2

Tuples possible are 