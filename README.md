This program is designed to simulate a hard disk drive read head moving across the cylinders of a disk using various scheduling algorithms. These algorithms handle 1000 random read requests in different ways. Descriptions of each algorithm can be found in the disk_algorithms.h header file.

To run this program:

First, compile: enter "g++ disk_sched.cpp"

This generates the executable (default: a.out).

Then enter ./a.out <starting position>

Starting position is the starting position of the read head

Example:

./a.out 15

The read head will start at cylinder 15 and go from there
