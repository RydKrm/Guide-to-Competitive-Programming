### Solution

### Statement

Given an array find the largest product of the sub-array?

Input :- `[2,3,-2,4]` Output :- `6`

start with `index = 0`. if i move forward with product by multiple with current number than some time it makes negative value
let `product = 1` and start a for loop from `i=0` to `len(arr)` and do `product *= arr[i]`. for negative value it's make negative product. But if their are two negative value it's make the product positive again.

So we have to keep the whole iteration value with the current value. and check with ans product which sum is max

```python

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        # O(n)/O(1) : Time/Memory
        res = nums[0]
        curMin, curMax = 1, 1

        for n in nums:
            tmp = curMax * n
            curMax = max(n * curMax, n * curMin, n)
            curMin = min(tmp, n * curMin, n)
            res = max(res, curMax)
        return res
```
