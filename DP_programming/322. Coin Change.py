'''
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
'''
class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        '''
        [1,4,5] 12, greedy wont work: 5,5,1,1,   4,4,4
        dp: fewest number of coins to make up i
        dp[i] = min(dp[i - coins[j]] + 1) for j in coins
        '''
        if amount <= 0:
            return 0
        dp = [-1 for _ in range(amount + 1)]
        dp[0] = 0
        coins.sort()
        print (coins)
        for i in range(1, amount + 1):
            for j in coins:
                # print (j , i)
                if j>i:
                    break
                if dp[i] == -1:
                    if dp[i-j] != -1:
                        dp[i] = dp[i - j] + 1
                else:
                    if dp[i-j] != -1:
                        dp[i] = min(dp[i], dp[i-j] + 1)
        print (dp)
        return dp[i]

if __name__ == '__main__':
    a = Solution
    coin = [370,417,408,156,143,434,168,83,177,280,117]
    amount = 9953
    print (a.coinChange(a,coin, amount))
