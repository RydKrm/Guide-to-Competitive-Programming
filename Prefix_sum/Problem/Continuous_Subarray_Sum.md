### Problem

[Continuous Sub-array Sum](https://leetcode.com/problems/continuous-subarray-sum)

Given an array `nums`. Return `true` if find a sub-array which total sum is multiple by some number `k`and sub-array length is larger than two otherwise `false`

### Logic

let think about this example :- <br>
`nums = [8,11,5,9,3,5,3,1,3,5,]` and `k = 13`

Most easy solution will be brute force. Iterate over all the sub array and sum up all the number and check if it's a multiple of `k` of not. But time complexity will be `O(n^2)`.

So we need t do `prefix_sum` for that which will make our work easy. After `prefix_sum` the example look like <br>
` nums =      [8,11, 5, 9, 3, 5, 3, 1, 3, 5,]` <br>
`prefix_sum = [8,19,24,33,36,41,44,45,48,53]`<br>

Now if look closely what question asked for? It say's `total_sub_array_sum % k == 0`. If mod all the element in the array with `k` and find the `reminder` what will that means? After mode :-
`after_mod = [8,6,11,7,10,2,5,6,9,1]` <br>

It says that `prefix_sum[i]` has `after_mod[i]` number extra in this place. If the `after_mod[i]` is found before that means all the number in that sub-array where `after_mod[i]` found before will be multiple by `k`.

### Complexity

- Time O(NLog(N))
- Space O(N)

### Code in Python

```python
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        checker = {0: -1}
        sum = 0

        for i, num in enumerate(nums):
            sum += num
            rem = sum % k
            if rem in checker:
                if i - checker[rem] > 1:
                    return True
            else:
                checker[rem] = i
        return False
```
