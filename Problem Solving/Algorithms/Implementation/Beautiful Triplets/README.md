Given a sequence of integers , a triplet  is beautiful if:

Given an increasing sequenc of integers and the value of , count the number of beautiful triplets in the sequence.

Example


There are three beautiful triplets, by index: . To test the first triplet,  and .

Function Description

Complete the beautifulTriplets function in the editor below.

beautifulTriplets has the following parameters:

int d: the value to match
int arr[n]: the sequence, sorted ascending
Returns

int: the number of beautiful triplets
Input Format

The first line contains  space-separated integers,  and , the length of the sequence and the beautiful difference.
The second line contains  space-separated integers .

Constraints

Sample Input

STDIN           Function
-----           --------
7 3             arr[] size n = 7, d = 3
1 2 4 5 7 8 10  arr = [1, 2, 4, 5, 7, 8, 10]
Sample Output

3
Explanation

There are many possible triplets , but our only beautiful triplets are  ,  and  by value, not index. Please see the equations below:




Recall that a beautiful triplet satisfies the following equivalence relation:  where .

Language
C++20
More
141516171819202122232425262728293031323334353637383940414243444546474849
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'beautifulTriplets' function below.
…
        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

Line: 109 Col: 1

Test against custom input
Problem Solving
You have earned 20.00 points!
You are now 1019 points away from the 6th star for your problem solving badge.
25%1181/2200
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
Compiler Message
Success
Input (stdin)
7 3
1 2 4 5 7 8 10
Expected Output
3
