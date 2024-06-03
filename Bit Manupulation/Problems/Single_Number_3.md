### Problem Link

[Problem](https://leetcode.com/problems/single-number-iii/)

### Statement

Given an integer array number, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order

### Example

Input: numbers = [1,2,1,3,2,5]
Output: [3,5]

### Logic

#### Bit Manipulation Solution

Simple theory first from the X-OR property `a^a = 0` so `a^a^b^b^c^c = 0` and also `a^a^b^b^c^c^d = d` <br>
Then this problem logic <br>
Let's say `num1` and `num2` are those number. If I X-OR all those number it will end up with `num1 ^ num2`. But here is an tricky part to notice that, those two number `num1` and `num2` must have one or more bit difference. So if I made two group with that difference bit and I will find those two number.

### Algorithm

1. Find the x-or of all number
2. Find the different bit
3. Take two group `num1` and `num2`
4. Add all the number into `num1` where `different_bit = 1` and other number into `num2`
5. return `num1` and `num2`

### Explanation with Example

numbers = [1,2,1,3,2,5]

after x-or = [6] which is `110` in binary <br>
Now divide two group
`num1 = [1,1,5]` and `num2 = [2,2,3]` <br>
Now x-or all element of two group and find the single number <br>
`num1 = 1^1^5 = 5` and `num2 = 2^2^3 = 3` <br>
return `num1` and `num2`

### Complexity

- Time : O(n)
- Space :(1)

```python
class Solution:
    def singleNumber(self, nums: List[int]) -> List[int]:
        twoNum = 0
        for num in nums:
            twoNum ^= num

        diff_bit = 1

        while not( twoNum & diff_bit):
          diff_bit = diff_bit << 1

        num1,num2 = 0,0
        for num in nums:
          if diff_bit & num:
            num1 ^= num
          else:
             num2 ^= num

        return [num1, num2]

```

```cpp
class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        int twoNum = 0;
        for (int num : nums) {
            twoNum ^= num;
        }

        int diff_bit = 1;

        while ((twoNum & diff_bit) == 0) {
            diff_bit <<= 1;
        }

        int num1 = 0, num2 = 0;
        for (int num : nums) {
            if (num & diff_bit) {
                num1 ^= num;
            } else {
                num2 ^= num;
            }
        }

        return {num1, num2};
    }
};
```

```javascript
var singleNumber = function (nums) {
  let twoNum = 0;
  for (let num of nums) {
    twoNum ^= num;
  }

  let diff_bit = 1;

  while ((twoNum & diff_bit) === 0) {
    diff_bit <<= 1;
  }

  let num1 = 0,
    num2 = 0;
  for (let num of nums) {
    if (num & diff_bit) {
      num1 ^= num;
    } else {
      num2 ^= num;
    }
  }

  return [num1, num2];
};
```
