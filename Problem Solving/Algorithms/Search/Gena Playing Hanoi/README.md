The Tower of Hanoi is a famous game consisting of  rods and a number of discs of incrementally different diameters. The puzzle starts with the discs neatly stacked on one rod, ordered by ascending size with the smallest disc at the top. The game's objective is to move the entire stack to another rod, obeying the following rules:

Only one disk can be moved at a time.
In one move, remove the topmost disk from one rod and move it to another rod.
No disk may be placed on top of a smaller disk.
Gena has a modified version of the Tower of Hanoi. This game of Hanoi has  rods and  disks ordered by ascending size. Gena has already made a few moves following the rules above. Given the state of Gena's Hanoi, determine the minimum number of moves needed to restore the tower to its original state with all disks on rod .

Note: Gena's rods are numbered from  to . The radius of a disk is its index in the input array, so disk  is the smallest disk with a radius of , and disk  is the largest with a radius of .

Example

In this case, the disks are arranged from large to small across the four rods. The largest disk, disk , is already on rod , so move disks  and  to rod , in that order. It takes  moves to reset the game.


The largest disk, disk  with radius , is already on rod . Disk  is on rod  and must be below disk . Move disk  to rod , disk  to rod  and disk  to rod . Now move disk  to rod . It takes  moves to reset the game.

Function Description

Complete the hanoi function below.

hanoi has the following parameters:

int posts[n]:  is the location of the disk with radius 
Returns

int: the minimum moves to reset the game to its initial state
Input Format

The first line contains a single integer, , the number of disks.
The second line contains  space-separated integers, where the  integer is the index of the rod where the disk with diameter  is located.

Constraints

Sample Input

STDIN   Function
-----   --------
3       size of posts[] n = 3
1 4 1   posts = [1, 4, 1]
Sample Output

3
Explanation

 moves are enough to build the tower. Here is one possible solution:
gena1.png
gena2.png