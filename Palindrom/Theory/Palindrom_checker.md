### Check Palindrom

### Statement 1

Given a string, check is it a palindrom or not.

#### Two pointer approach

1. Take two pointer `start=0` and `end = len(string)-1`
2. Start a while loop which is go on until `start<=end`
3. if `str[start]==str[end]` then `start++` and `end--`
4. else it is not a palindrom

### Statement 2

Given a string, find the largest substring which is palindrom

### Iteration approach

#### Brute force approach

1. Loop through over the string with `i=1` to `i<len(str)`
2. Start another loop which is start from `j=1` to `j<len(str)`
3. check if string from `i` to `j` is a palindrom or not
4. if palindrom check compare with height

##### Complexity

- Time `O(n^3)`
- Space `O(1)`

#### Single Iteration

1. `ans = 1` and `highestLen = 1` because single character also a substring
2. Start loop from `i=0` to `i<len(str)`
3. consider `ith` position is the middle of palindrom
4. move two way `backward = i-1` and `forward = i+1`
5. if `backward == forward` then this is also a palindrom and it's size will be `highestLen+=2`
6. else make compare with ans and take the best `ans = max(highestLen, ans)`
7. **Another problem is abba also palindrom**
8. for that `backward=i` and `forward=i+1` then start from `highestLen=0`
9. again move two way `backward = i-1` and `forward = i+1`
10. if `backward == forward` then this is also a palindrom and it's size will be `highestLen+=2`
11. else make compare with ans and take the best `ans = max(highestLen, ans)`

### Complexity

- Time `O(n^2)
- Space `O(n)

#### Python

```python
def longest_palindrome(s):
    if len(s) < 2:
        return s

    start = 0
    max_length = 1

    for i in range(len(s)):
        left = i
        right = i
        while left >= 0 and right < len(s) and s[left] == s[right]:
            if right - left + 1 > max_length:
                start = left
                max_length = right - left + 1
            left -= 1
            right += 1

        left = i
        right = i + 1
        while left >= 0 and right < len(s) and s[left] == s[right]:
            if right - left + 1 > max_length:
                start = left
                max_length = right - left + 1
            left -= 1
            right += 1

    return s[start:start + max_length]
```
