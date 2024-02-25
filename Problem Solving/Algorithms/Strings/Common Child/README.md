A string is said to be a child of a another string if it can be formed by deleting 0 or more characters from the other string. Letters cannot be rearranged. Given two strings of equal length, what's the longest string that can be constructed such that it is a child of both?

Example



These strings have two children with maximum length 3, ABC and ABD. They can be formed by eliminating either the D or C from both strings. Return .

Function Description

Complete the commonChild function in the editor below.

commonChild has the following parameter(s):

string s1: a string
string s2: another string
Returns

int: the length of the longest string which is a common child of the input strings
Input Format

There are two lines, each with a string,  and .

Constraints

 where  means "the length of "
All characters are upper case in the range ascii[A-Z].
Sample Input

HARRY
SALLY
Sample Output

 2
Explanation

The longest string that can be formed by deleting zero or more characters from  and  is , whose length is 2.

Sample Input 1

AA
BB
Sample Output 1

0
Explanation 1

 and  have no characters in common and hence the output is 0.

Sample Input 2

SHINCHAN
NOHARAAA
Sample Output 2

3
Explanation 2

The longest string that can be formed between  and  while maintaining the order is .

Sample Input 3

ABCDEF
FBDAMN
Sample Output 3

2
Explanation 3
 is the longest child of the given strings.