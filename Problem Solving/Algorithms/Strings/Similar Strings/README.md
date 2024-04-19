Jimmy loves playing with strings. He thinks string  is similar to string  if the following conditions are satisfied:

Both strings have the same length (i.e.,  and ).
For each valid pair of indices, , in the strings,  and  or  and .
For example, string  and  are similar as for ,  and  and for all other  pairs  as well as .

He has a string, , of size  and gives you  queries to answer where each query is in the form of a pair of integers . For each substring , find the number of substrings  where substring  is similar to substring  and print this number on a new line.

Note: Substring  is the contiguous sequence of characters from index  to index . For example, if  abcdefgh, then  cdef.

Input Format

The first line contains two space-separated integers describing the respective values of  and .
The second line contains string .
Each line  of the  subsequent lines contains two space-separated integers describing the respective values of  and  for query .

Constraints

Output Format

For each query, print the number of similar substrings on a new line.

Sample Input

8 4
giggabaj
1 1
1 2
1 3
2 4
Sample Output

8
6
2
1
Explanation

We perform the following sequence of queries:

Strings with length  are all similar, so our answer is .
gi, ig, ga, ab, ba, and aj are similar, so our answer is .
gig and aba are similar, so our answer is .
igg has no similar string, so our answer is .