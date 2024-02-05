Your local library needs your help! Given the expected and actual return dates for a library book, create a program that calculates the fine (if any). The fee structure is as follows:

If the book is returned on or before the expected return date, no fine will be charged (i.e.: .
If the book is returned after the expected return day but still within the same calendar month and year as the expected return date, .
If the book is returned after the expected return month but still within the same calendar year as the expected return date, the .
If the book is returned after the calendar year in which it was expected, there is a fixed fine of .
Charges are based only on the least precise measure of lateness. For example, whether a book is due January 1, 2017 or December 31, 2017, if it is returned January 1, 2018, that is a year late and the fine would be .

Example


The first values are the return date and the second are the due date. The years are the same and the months are the same. The book is  days late. Return .

Function Description

Complete the libraryFine function in the editor below.

libraryFine has the following parameter(s):

d1, m1, y1: returned date day, month and year, each an integer
d2, m2, y2: due date day, month and year, each an integer
Returns

int: the amount of the fine or  if there is none
Input Format

The first line contains  space-separated integers, , denoting the respective , , and  on which the book was returned.
The second line contains  space-separated integers, , denoting the respective , , and  on which the book was due to be returned.

Constraints

Sample Input

9 6 2015
6 6 2015
Sample Output

45
Explanation

Given the following dates:
Returned: 
Due: 

Because , we know it is less than a year late.
Because , we know it's less than a month late.
Because , we know that it was returned late (but still within the same month and year).

Per the library's fee structure, we know that our fine will be . We then print the result of  as our output.

Language
C++20
More
202122242528293233343536373819181723262730313940
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'libraryFine' function below.
…
    return tokens;
}

Line: 112 Col: 1

Test against custom input
Problem Solving
You have earned 15.00 points!
You are now 1204 points away from the 6th star for your problem solving badge.
11%996/2200
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

Test case 12

Test case 13

Test case 14

Test case 15

Test case 16
Compiler Message
Success
Hidden Test Case
Unlock this testcase for 5 hackos.
Blog