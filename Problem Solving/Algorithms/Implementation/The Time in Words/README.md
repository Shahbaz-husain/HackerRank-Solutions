Given the time in numerals we may convert it into words, as shown below:

At , use o' clock. For , use past, and for  use to. Note the space between the apostrophe and clock in o' clock. Write a program which prints the time in words for the input given in the format described.

Function Description

Complete the timeInWords function in the editor below.

timeInWords has the following parameter(s):

int h: the hour of the day
int m: the minutes after the hour
Returns

string: a time string as described
Input Format

The first line contains , the hours portion The second line contains , the minutes portion

Constraints

Sample Input 0

5
47
Sample Output 0

thirteen minutes to six
Sample Input 1

3
00
Sample Output 1

three o' clock
Sample Input 2

7
15
Sample Output 2

quarter past seven
Language
C++20
More
404142434439383736353433323130292827262524232221201918454647481716
        case 14: min = "fourteen";break;
        case 16: min = "sixteen";break;
        case 17: min = "seventeen"; break;
        case 18: min = "eighteen";break;
        case 19: min = "nineteen";break;
        case 20: min = "twenty";break;
        case 21: min = "twenty one";break;
        case 22: min = "twenty two";break;
        case 23: min = "twenty three";break;
        case 24: min = "twenty four";break;

hour
14 of 16
min
Line: 52 Col: 28

Test against custom input
Problem Solving
You have earned 25.00 points!
You are now 954 points away from the 6th star for your problem solving badge.
29%1246/2200
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
5
47
Expected Output
thirteen minutes to six
