A pair of nodes, , is a similar pair if the following conditions are true:

node  is the ancestor of node 
Given a tree where each node is labeled from  to , find the number of similar pairs in the tree.

For example, given the following tree:

image

We have the following pairs of ancestors and dependents:

Pair	abs(a-b)	Pair	abs(a-b)
1,2	1		3,4	1
1,3	2		3,5	2
1,4	3		3,6	3
1,5	4
1,6	5
If  for example, we have  pairs that are similar, where .

Function Description

Complete the similarPair function in the editor below. It should return an integer that represents the number of pairs meeting the criteria.

similarPair has the following parameter(s):

n: an integer that represents the number of nodes
k: an integer
edges: a two dimensional array where each element consists of two integers that represent connected node numbers
Input Format

The first line contains two space-separated integers  and , the number of nodes and the similarity threshold.
Each of the next  lines contains two space-separated integers defining an edge connecting nodes  and , where node  is the parent to node .

Constraints

Output Format

Print a single integer denoting the number of similar pairs in the tree.

Sample Input

5 2
3 2
3 1
1 4
1 5
Sample Output

4
Explanation

image
The similar pairs are , , , and , so we print  as our answer.
Observe that  and  are not similar pairs because they do not satisfy  for .