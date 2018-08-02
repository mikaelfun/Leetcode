'''
ou are working at the cash counter at a fun-fair, and you have different types of coins available to you in infinite quantities.
The value of each coin is already given.
Can you determine the number of ways of making change for a particular number of units using the given types of coins?

For example, if you have 4 types of coins, and the value of each type is given as 8,3,1,2 respectively,
you can make change for 3 units in three ways: {1,1,1}, {1,2}, and {3}.
'''
import sys

def getWays(n, c):
    # Complete this function
    # dp[i]: ways for unit i

    if n == 0:
        return 1
    if min(c) > n:
        return 0
    if min(c) == n:
        return 1
    dp = []
    for i in range(n+1):
        temp = []
        for j in range(len(c)):
            temp.append(0)
        dp.append(temp)
    #dp = [[0] * len(c)] * (n+1)
    # dp[0] = 1
    c.sort() # nlogn
    dp[0][len(c) - 1] = 1
    for i in range(1,n+1):
        for j in range(len(c)):
            if c[j] > i:
                break
            if c[j] == 1:
                dp[i][j] = 1
            else:
                if i - c[j] == 0 :
                    dp[i][j] = sum(dp[i-c[j]])
                else:
                    dp[i][j] = sum(dp[i-c[j]][:j+1])

    #  print(dp)
    return sum(dp[n])

#n, m = input().strip().split(' ')
#n, m = [int(n), int(m)]
n, m = 1, 25
#c = list(map(int, input().strip().split(' ')))
c = [48, 6, 34, 50, 49, 36, 30, 35, 40, 41, 17, 43, 39, 13, 4, 20, 19, 2, 46, 7, 38, 33, 28, 18, 21]
# '1,1,1,1'
# '1,1,2'
# '1,3'
# '2,2'
# Print the number of ways of making change for 'n' units using coins having the values given by 'c'
ways = getWays(n, c)
print ((ways))
