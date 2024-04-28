Consider an array  of  integers. We perform  queries of the following type on :

Sort all the elements in the subsegment .
Given , can you find and print the value at index  (where ) after performing  queries?

Input Format

The first line contains three positive space-separated integers describing the respective values of  (the number of integers in ),  (the number of queries), and  (an index in ).
The next line contains  space-separated integers describing the respective values of .
Each line  of the  subsequent lines contain two space-separated integers describing the respective  and  values for query .

Constraints

Output Format

Print a single integer denoting the value of  after processing all  queries.

Sample Input 0

3 1 1
3 2 1
0 1
Sample Output 0

3
Explanation 0


There is only one query to perform. When we sort the subarray ranging from index  to index , we get . We then print the element at index , which is .

Sample Input 1

4 2 0
4 3 2 1
0 2
1 3
Sample Output 1

2 
Explanation 1


There are  queries:

When we sort the subarray ranging from index  to index , we get .
When we sort the subarray of  from index  to index , we get .
Having performed all of the queries, we print the element at index , which is .