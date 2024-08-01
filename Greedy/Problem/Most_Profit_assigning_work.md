[Problem Link](https://leetcode.com/problems/most-profit-assigning-work)

### Logic 

The total profit will be the sum of all worker profit. So  for every worker, need to find their job by their ability. In simple word for every worker `w` find the job `j` which is equal to or max less then their ability.  


### Code 

```python 
 class Solution:
    def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
        jobs = sorted(zip(difficulty, profit))
        res = i = best = 0
        for ability in sorted(worker):
            while i < len(jobs) and ability >= jobs[i][0]:
                best = max(jobs[i][1], best)
                i += 1
            res += best
        return res       
```