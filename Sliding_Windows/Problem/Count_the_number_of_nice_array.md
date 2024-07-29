[Problem Link](https://leetcode.com/problems/count-number-of-nice-subarrays/)

### Problem 
Count the  number of sub array where the number of odd element is equal to k.

### Logic 

Count the total number of odd in every element with prefix sum. so that by subtracting the two position found the number of odd element in that window

nums = [1,1,2,1,1]
        ^
odds = [1 2 2 3 4] 
        ^     ^
     =>  end - start + 1
     =>  3 == k 
     =>  ans += 
even = [0 0 1 1 1]

 k = 3 

nums = [2, 2, 2, 1, 2, 2, 1, 2, 2, 2]   k = 2

odds = [0  0  0  1  1  1  2  2  2  2]
              ^           ^
even = [1  2  3  0  1  2  0  1  2  3]        

