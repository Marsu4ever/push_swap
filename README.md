# push_swap
(Radix) Algorithm that sorts between two stacks (A &amp; B)

This program is all about sorting unsorted numbers, so that by the end they are sorted in **Stack A**.
-------------------------------------------------------------------------------------------------------
**How to use**: 
Pass your program your favourite numbers.. (which will initially go to Stack A):
./push_swap "2" "1" "3"

OR 

./push_swap "2 1 3"

**What happpens then in the program**:  
By the end, The program will sort numbers into order in a linked list in **Stack A** as **"1, 2, 3**".

The program will do something more though. It'll tell you what **moves** it uses to move these numbers.
-------------------------------------------------------------------------------------------------------
The **Moves**:  
**Push**: Either it pushes the top number of a stack to the top of another stack (**pa** (push to stack A) or **pb**).  
**Rotate**: It rotates the top number to the bottom of a stack f.ex. **ra**, **rb**. (Or rotates both of them at the same time **rr**).  
**Reverse Rotate**: Or does the reverse (so rotates the bottom to the top). F.ex. **rra**, **rrb** and **rrr**.  
-------------------------------------------------------------------------------------------------------
**The Algorithm**:  
The algorithm used is Radix, which checks the bits of the numbers used.

**The Bits** please:
 0 - 0000 0000
 1 - 0000 0001
 2 - 0000 0010
 3 - 0000 0011
 ...
 etc

The numbers are are given **index numbers** starting from Zero (for the smallest number).  
Then, the algorithm sorts the numbers using the index numbers as a reference.

-> And that's the gist of it. Enjoy sorting and resorting and resorting and resorting.  
