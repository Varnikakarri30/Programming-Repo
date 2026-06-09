# DYNAMIC PROGRAMMING (DP)

## Why do we need Dynamic Programming?

- Store the answers and reuse them.
- Avoid solving the same subproblem multiple times.

## Where do we need Dynamic Programming?

1. Overlapping Subproblems
2. Maximum / Minimum score values
3. Finding the number of ways
4. Covering all possible cases
5. When Greedy algorithms fail
6. Checking possibilities (True / False)

---

# Implementation (Memoization)

```cpp
vector<int> dp(n, -1);

int fib(int n) {
    if (n <= 2) return 1;

    if (dp[n] != -1)
        return dp[n];

    int curr = fib(n - 1) + fib(n - 2);

    return dp[n] = curr;
}
```

---

# Useful Terminologies for Tabulation DP

## 1. State

A smaller subproblem that we want to solve.

The subproblem may be complex or simple, but the final aim is to solve the original problem.

### Example

For Fibonacci:

```cpp
f(n) = f(n-1) + f(n-2)
```

State:

```cpp
dp[i] = ith Fibonacci number
```

A **State** always tells you **what needs to be computed**.

---

## 2. Transition

Calculating the answer for a state (subproblem) using answers of smaller states.

A **Transition** tells you **how to achieve the state**.

### Example

```cpp
dp[i] = dp[i-1] + dp[i-2]
```

---

## 3. Base Case

The ending condition where the problem cannot be divided further.

### Example

```cpp
dp[1] = 1
dp[2] = 1
```

---

## 4. Final Answer

The state that represents the solution to the original problem.

### Example

For Fibonacci:

```cpp
dp[n]
```

is the final answer.

---

# References for DP Problems

- CSES Problem Set
- AtCoder DP Contest

---

# Sample Problem

## Question

Given a 2D Grid `(N × M)` with numbers in each cell, find the path from the top-left cell `(0,0)` to the bottom-right cell `(n-1,m-1)` having the minimum sum.

### Grid

```text
1    6    4
7    8   15
7   10   14
```

---

# Solution

## 1. State

```cpp
dp[i][j]
```

= Minimum sum required to reach cell `(i, j)` from `(0,0)`.

---

## 2. Transition

```cpp
dp[i][j] =
    min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
```

We can reach `(i,j)` either:

- From the top `(i-1,j)`
- From the left `(i,j-1)`

Choose the minimum path sum.

---

## 3. Base Case

Starting cell:

```cpp
dp[0][0] = grid[0][0];
```

or

```cpp
if (i == 0 && j == 0)
    dp[i][j] = grid[i][j];
```

---

## 4. Final Answer

```cpp
dp[n-1][m-1]
```

This contains the minimum path sum from `(0,0)` to `(n-1,m-1)`.

---

# DP Thinking Process

Whenever you solve a DP problem, identify:

1. **State** → What do I need to compute?
2. **Transition** → How can I compute it from smaller states?
3. **Base Case** → Where does recursion/tabulation start?
4. **Final Answer** → Which state gives the required result?

This framework works for most Dynamic Programming problems.