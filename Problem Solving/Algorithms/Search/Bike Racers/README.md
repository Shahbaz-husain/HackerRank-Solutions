There are  bikers present in a city (shaped as a grid) having  bikes. All the bikers want to participate in the HackerRace competition, but unfortunately only  bikers can be accommodated in the race. Jack is organizing the HackerRace and wants to start the race as soon as possible. He can instruct any biker to move towards any bike in the city. In order to minimize the time to start the race, Jack instructs the bikers in such a way that the first  bikes are acquired in the minimum time.

Every biker moves with a unit speed and one bike can be acquired by only one biker. A biker can proceed in any direction. Consider distance between bikes and bikers as Euclidean distance.

Jack would like to know the square of required time to start the race as soon as possible.

Input Format

The first line contains three integers, , , and , separated by a single space.
The following  lines will contain  pairs of integers denoting the co-ordinates of  bikers. Each pair of integers is separated by a single space. The next  lines will similarly denote the co-ordinates of the  bikes.

Constraints




,  

Output Format

A single line containing the square of required time.

Sample Input

3 3 2
0 1
0 2
0 3
100 1
200 2 
300 3
Sample Output

40000
Explanation

There's need for two bikers for the race. The first biker (0,1) will be able to reach the first bike (100,1) in 100 time units. The second biker (0,2) will be able to reach the second bike (200,2) in 200 time units. This is the most optimal solution and will take 200 time units. So output will be 2002 = 40000.