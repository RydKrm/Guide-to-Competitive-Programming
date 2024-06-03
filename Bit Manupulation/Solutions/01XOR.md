### XOR Problem

[Problem-01](https://leetcode.com/problems/single-number/description/)

### Statement

Given a non-empty array of integers number, every element appears twice except for one. Find that single one.
Example : number = [4,1,2,1,2] Output : 4

### Solution

From the X-OR property `a^a = 0` so `a^a^b^b^c^c = 0` and also `a^a^b^b^c^c^d = d`

if we X-OR all the number than find the single number

### Complexity

- Time O(n)
- Space O(n)

```python
   class Solution:
      def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for num in nums:
          ans ^= num
        return ans
```
