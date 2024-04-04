Greg wants to build a string,  of length . Starting with an empty string, he can perform  operations:

Add a character to the end of  for  dollars.
Copy any substring of , and then add it to the end of  for  dollars.
Calculate minimum amount of money Greg needs to build .

Input Format

The first line contains number of testcases .

The  subsequent lines each describe a test case over  lines:
The first contains  space-separated integers, ,  , and , respectively.
The second contains  (the string Greg wishes to build).

Constraints

 is composed of lowercase letters only.
Output Format

On a single line for each test case, print the minimum cost (as an integer) to build .

Sample Input

2
9 4 5
aabaacaba
9 8 9
bacbacacb
Sample Output

26
42
Explanation

Test Case 0:
 "";  ""
Append "";  ""; cost is 
Append "";  ""; cost is 
Append "";  ""; cost is 
Copy and append "";  ""; cost is 
Append "";  ""; cost is 
Copy and append "";  ""; cost is 

Summing each cost, we get , so our output for Test Case 1 is .

Test Case 1:
 "";  ""
Append "";  ""; cost is 
Append "";  ""; cost is 
Append "";  ""; cost is 
Copy and append "";  ""; cost is 
Copy and append "";  ""; cost is 

Summing each cost, we get , so our output for Test Case 2 is .