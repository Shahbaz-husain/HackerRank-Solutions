Madam Hannah Otto, the CEO of Reviver Corp., is fond of palindromes, or words that read the same forwards or backwards. She thinks palindromic brand names are appealing to millennials.

As part of the marketing campaign for the company's new juicer called the Rotator™, Hannah decided to push the marketing team's palindrome-searching skills to a new level with a new challenge.

In this challenge, Hannah provides a string  consisting of lowercase English letters. Every day, for  days, she would select two integers  and , take the substring  (the substring of  from index  to index ), and ask the following question:

Consider all the palindromes that can be constructed from some of the letters from . You can reorder the letters as you need. Some of these palindromes have the maximum length among all these palindromes. How many maximum-length palindromes are there?

For example, if ,  and , then we have,

image

Your job as the head of the marketing team is to answer all the queries. Since the answers can be very large, you are only required to find the answer modulo .

Complete the functions initialize and answerQuery and return the number of maximum-length palindromes modulo .

Input Format

The first line contains the string .

The second line contains a single integer .

The  of the next  lines contains two space-separated integers ,  denoting the  and  values Anna selected on the  day.

Constraints

Here,  denotes the length of .

Subtasks

For 30% of the total score:

For 60% of the total score:

Output Format

For each query, print a single line containing a single integer denoting the answer.

Sample Input 0

week
2
1 4
2 3
Sample Output 0

2
1
Explanation 0

On the first day,  and . The maximum-length palindromes are "ewe" and "eke".

On the second day,  and . The maximum-length palindrome is "ee".

image

Sample Input 1

abab
1
1 4
Sample Output 1

2
Explanation 1

Here, the maximum-length palindromes are "abba" and "baab".