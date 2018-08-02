'''
You have a rectangular board consisting of N rows, numbered from 1 to N, and M columns, numbered from 1 to M.
The top left is 1,1 and the bottom right is N,M. Initially - at time  - there is a coin on the top-left cell of your board.
Each cell of your board contains one of these letters: URDL*
When the coin reaches a cell that has letter '*', it will stay there permanently.
When you punch on your board, your timer starts and the coin moves between cells.
Before starting the game, you can make operations to change the board, such that you are sure that at or before time
the coin will reach the cell having letter '*'.
In each operation you can select a cell with some letter other than '*' and change the letter to 'U', 'L', 'R' or 'D'.
You need to carry out as few operations as possible in order to achieve your goal.
Your task is to find the minimum number of operations.
'''
#!/bin/python3

import os
import sys
import random
import numpy as np

#
# Complete the coinOnTheTable function below.
#
def coinOnTheTable(m, k, board):
    #
    # Write your code here.
    #
    # base case: k >= steps to reach * without changing board, return 0
    steps = 0
    n = len(board)
    i, j = 0, 0
    canNotReach = False
    path = []
    while board[i][j] != '*':
        path.append((i,j))
        if board[i][j] == 'U':
            i-=1
        elif board[i][j] == 'D':
            i+=1
        elif board[i][j] == 'R':
            j+=1
        elif board[i][j] == 'L':
            j-=1
        else:
            pass
        steps+=1
        if i<0 or i>=n or j<0 or j>=m:
            canNotReach = True
            break
    print (steps)
    if steps <= k:
        return 0






if __name__ == '__main__':
    n, m, k = 4,5,3

    board = []

    for i in range(n):
        temp = []
        for j in range(m):
            if len(board) == 0 and len(temp) == 0:
                temp.append(random.choice(['D','R']))
            elif len(board) == 0:
                if temp[-1] == 'R':
                    temp.append(random.choice(['U','D','R']))
                else:
                    temp.append(random.choice(['L','D','R']))
            elif len(temp) == 0:
                if board[-1][j] == 'D':
                    temp.append(random.choice(['D','L','R']))
                else:
                    temp.append(random.choice(['U','D','R']))
            else:
                temp.append(random.choice(['U','D','L','R']))

        board.append(temp)
    board[random.randint(0, n-1)][random.randint(0, m - 1)] = '*'
    print (np.array(board))
    result = coinOnTheTable(m, k, board)
    print(result)
