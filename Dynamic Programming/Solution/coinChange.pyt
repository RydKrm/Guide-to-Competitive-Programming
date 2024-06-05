coins = [3,2,5]
value = [0]*100


# * recursive solution 

def solve(x) :
    if x<0 : 
        return float('inf')
    if x==0:
        return 0
    if value[x] :
        return value[x]
    best = float('inf')
    for coin in coins :
        best = min(best, solve(x-coin) + 1)
    value[x] = best    
    return best    


# ans = solve(15)
# print("solution ",ans)  


# * Iteration Solution

dp = [float('inf')]*10000

def iterator(x):
    dp[0] = 0
    for i in range(1,x + 1):
        for coin in coins:
            if x-coin >=0 :
                dp[i] = min(dp[i], dp[i-coin]+1)
    return dp[x]

print(iterator(4))    
                

