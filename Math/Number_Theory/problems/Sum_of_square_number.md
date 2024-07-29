[Problem Link](https://leetcode.com/problems/sum-of-square-numbers/description)

### Statements 

Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c

#### Constrains 
`0 <= c <= 2^31 - 1`

### Example 
Input : c = 5 output : true 
Explanation : 2^2 + 1^2 = 5 
Input: c = 3  Output: false

### Logic 

let another example 

3^2 + 3^2 = 18 

2^2 + 7^2 = 53

2^2 + 9^2 = 85

### Brutforce Method

`a` and `b` can be the same number or the different number. As the constrains tells `1 <=c <=2^32-1`. 
so `a` and `b` can not be the greater then `sqrt(2^32-1)`. so that need two nested loop for all the possible values. 

```python 
class Solution:
    def judgeSquareSum(self, c: int) -> bool:
      for i in range(1,ceil(math.sqrt(c))):
        for j in range(1,ceil(math.sqrt(c))):
          if (i**2 + j**2) == c :
            return True 
      return False           
```


#### that create a TLE Error
let's say give number c = 82 

#### Let's try two pointer 
`start = 1` and `end = sqrt(c)` 
 from the example `start = 1` and `end = floor(sqrt(82)) => 9` 
 `sum = start^2 + end^2`
 if `sum == c` return `True` 
 else if `sum > c` then ` end -= 1`
 else `sum < c` then `start += 1`


 ```python 
 class Solution:
    def judgeSquareSum(self, c: int) -> bool:
      left,right = 0, ceil(math,sqrt(c))
      while left <= right:
        sum = left**2 + right**2
        if sum == c :
            return True
        else if sum<c :
            left += 1
        else : right -= 1

      return False  

 ```