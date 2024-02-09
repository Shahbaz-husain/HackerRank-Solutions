Louise joined a social networking site to stay in touch with her friends. The signup page required her to input a name and a password. However, the password must be strong. The website considers a password to be strong if it satisfies the following criteria:

Its length is at least .
It contains at least one digit.
It contains at least one lowercase English character.
It contains at least one uppercase English character.
It contains at least one special character. The special characters are: !@#$%^&*()-+
She typed a random string of length  in the password field but wasn't sure if it was strong. Given the string she typed, can you find the minimum number of characters she must add to make her password strong?

Note: Here's the set of types of characters in a form you can paste in your solution:

numbers = "0123456789"
lower_case = "abcdefghijklmnopqrstuvwxyz"
upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
special_characters = "!@#$%^&*()-+"
Example


This password is 5 characters long and is missing an uppercase and a special character. The minimum number of characters to add is .


This password is 5 characters long and has at least one of each character type. The minimum number of characters to add is .

Function Description

Complete the minimumNumber function in the editor below.

minimumNumber has the following parameters:

int n: the length of the password
string password: the password to test
Returns

int: the minimum number of characters to add
Input Format

The first line contains an integer , the length of the password.

The second line contains the password string. Each character is either a lowercase/uppercase English alphabet, a digit, or a special character.

Constraints

All characters in  are in [a-z], [A-Z], [0-9], or [!@#$%^&*()-+ ].
Sample Input 0

3
Ab1
Sample Output 0

3
Explanation 0

She can make the password strong by adding  characters, for example, $hk, turning the password into Ab1$hk which is strong.

 characters aren't enough since the length must be at least .

Sample Input 1

11
#HackerRank
Sample Output 1

1
Explanation 1

The password isn't strong, but she can make it strong by adding a single digit.

Language
C++11
More
1920212425262728293031323334353637383941421823404317441622454647
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
…

Line: 90 Col: 1

Test against custom input
Problem Solving
You have earned 15.00 points!
You are now 654 points away from the 6th star for your problem solving badge.
52%1546/2200
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

Test case 17

Test case 18

Test case 19

Test case 20

Test case 21

Test case 22

Test case 23

Test case 24

Test case 25

Test case 26

Test case 27

Test case 28

Test case 29

Test case 30

Test case 31

Test case 32

Test case 33

Test case 34

Test case 35

Test case 36

Test case 37

Test case 38

Test case 39

Test case 40

Test case 41

Test case 42

Test case 43

Test case 44

Test case 45

Test case 46

Test case 47

Test case 48

Test case 49

Test case 50

Test case 51

Test case 52

Test case 53

Test case 54

Test case 55

Test case 56

Test case 57

Test case 58

Test case 59

Test case 60

Test case 61

Test case 62

Test case 63

Test case 64

Test case 65

Test case 66

Test case 67

Test case 68

Test case 69

Test case 70

Test case 71

Test case 72

Test case 73

Test case 74

Test case 75

Test case 76

Test case 77

Test case 78

Test case 79

Test case 80

Test case 81

Test case 82

Test case 83

Test case 84

Test case 85

Test case 86

Test case 87

Test case 88

Test case 89
Compiler Message
Success
Input (stdin)
3
Ab1
Expected Output
3
