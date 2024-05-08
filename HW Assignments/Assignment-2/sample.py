def chickens(A, i, r, d, n, memo):
    if i >= n:
        return 0
    if memo[i][r][d] != -1:
        return memo[i][r][d]

    if d == 3:
        memo[i][r][d] = chickens(A, i + 1, 1, 0, n, memo) + A[i]
    elif r == 3:
        memo[i][r][d] = chickens(A, i + 1, 0, 1, n, memo) - A[i]
    else:
        cnt1 += 2
        memo[i][r][d] = max(
            chickens(A, i + 1, r + 1, 0, n, memo) + A[i],
            chickens(A, i + 1, 0, d + 1, n, memo) - A[i]
        )

    return memo[i][r][d]

A = [-100, 2, 1, -3, -2, -3, -1, -4, -2, 1, 6, 3, 4, -5]
n = len(A)
memo = [[[-1] * 4 for _ in range(4)] for _ in range(n)]
print(chickens(A, 0, 0, 0, n, memo))
