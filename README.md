This is my implementation of handling of big numbers.  It is meant to handle 
numbers larger than can be handled with the built in data types.  

# Implementation
The numbers
are stored as a vector of shorts.  Though this is not necessarily the most 
efficient for space, it is more simple to code.  The motivation behind this
code is the ACM programming competition, so the easier the code is to type,
the better.

Operations are done as long addition with a carry, long subtraction, long
multiplication, long division.  

# files

driver.cpp : reads the numbers out of numstomult.txt and carrys out operation

numstomult.cpp : 2 numbers seperated by spaces with trailing space.  typical 
of competition files.

bignums.h : implementation of operations. 
