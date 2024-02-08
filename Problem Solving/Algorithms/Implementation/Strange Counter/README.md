There is a strange counter. At the first second, it displays the number . Each second, the number displayed by decrements by  until it reaches . In next second, the timer resets to  and continues counting down. The diagram below shows the counter values for each time  in the first three cycles:

strange(1).png

Find and print the value displayed by the counter at time .

Function Description

Complete the strangeCounter function in the editor below.

strangeCounter has the following parameter(s):

int t: an integer
Returns

int: the value displayed at time 
Input Format

A single integer, the value of .

Constraints

Subtask

 for  of the maximum score.
Sample Input

4
Sample Output

6
Explanation

Time  marks the beginning of the second cycle. It is double the number displayed at the beginning of the first cycle:. This is shown in the diagram in the problem statement.

Language
C++11
More
15161718192021222324252627282930313233343536373839401413
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'strangeCounter' function below.
 *
…
Line: 81 Col: 1

Test against custom input
Problem Solving
You have earned 30.00 points!
You are now 714 points away from the 6th star for your problem solving badge.
47%1486/2200
Congratulations
You solved this challenge. Would you like to challenge your friends?Share on FacebookShare on TwitterShare on LinkedIn

Test case 0

Test case 1

Test case 2

Test case 3

Test case 4

Test case 5

Test case 6

Test case 7

Test case 8

Test case 9

Test case 10

Test case 11
Compiler Message
Success
Input (stdin)
4
Expected Output
6
BlogScoringEnvironment