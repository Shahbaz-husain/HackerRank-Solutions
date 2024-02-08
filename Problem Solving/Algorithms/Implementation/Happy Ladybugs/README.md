Happy Ladybugs is a board game having the following properties:

The board is represented by a string, , of length . The  character of the string, , denotes the  cell of the board.
If  is an underscore (i.e., _), it means the  cell of the board is empty.
If  is an uppercase English alphabetic letter (ascii[A-Z]), it means the  cell contains a ladybug of color .
String  will not contain any other characters.
A ladybug is happy only when its left or right adjacent cell (i.e., ) is occupied by another ladybug having the same color.
In a single move, you can move a ladybug from its current position to any empty cell.
Given the values of  and  for  games of Happy Ladybugs, determine if it's possible to make all the ladybugs happy. For each game, return YES if all the ladybugs can be made happy through some number of moves. Otherwise, return NO.
Example

You can move the rightmost  and  to make  and all the ladybugs are happy. Return YES.

Function Description

Complete the happyLadybugs function in the editor below.

happyLadybugs has the following parameters:

string b: the initial positions and colors of the ladybugs
Returns

string: either YES or NO
Input Format

The first line contains an integer , the number of games.

The next  pairs of lines are in the following format:

The first line contains an integer , the number of cells on the board.
The second line contains a string  that describes the  cells of the board.
Constraints

Sample Input 0

4
7
RBY_YBR
6
X_Y__X
2
__
6
B_RRBR
Sample Output 0

YES
NO
YES
YES
Explanation 0

The four games of Happy Ladybugs are explained below:

Initial board:
lady.png
After the first move:
lady(1).png
After the second move:
lady(2).png
After the third move:
lady(3).png
Now all the ladybugs are happy, so we print YES on a new line.
There is no way to make the ladybug having color Y happy, so we print NO on a new line.
There are no unhappy ladybugs, so we print YES on a new line.
Move the rightmost  and  to form .
Sample Input 1

5
5
AABBC
7
AABBC_C
1
_
10
DD__FQ_QQF
6
AABCBC
Sample Output 1

NO
YES
YES
YES
NO
Language
C++11
More
252628293031323435363738394042434445462322212019474849505118242752335354415517161514
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'happyLadybugs' function below.
 *
…        s.end()
    );

    return s;
}

Line: 106 Col: 1

Test against custom input
Problem Solving
You have earned 30.00 points!
You are now 744 points away from the 6th star for your problem solving badge.
45%1456/2200
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
7
RBY_YBR
6
X_Y__X
2
__
6
B_RRBR
Expected Output
YES
NO
YES
YES
