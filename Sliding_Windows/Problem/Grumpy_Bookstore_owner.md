[Problem Link](https://leetcode.com/problems/grumpy-bookstore-owner)

### Logic 

Main goal of this problem is to find a window with size of `minutes` where window sum is maximum. 

But what if the `minutes` is greater then the size of `grumpy` array.
then find the total sum.

If find a window with max sum  but all the `grumpy` element is `0` in simple words the window sum is max but shop owner is not grumpy at that momont.  
then that window is not taken care.

So make window sum in `customers` with from `1 to minutes`. Now start a iteration with every one step 
check if all the time shop owner is not grumpy or not. If grumpy then compair with with max and beside that also calculate the total sum which is outside the window and shop owner is not grumpy. 



