# Greedy Method

## Definition

- If a problem has **N possible solutions**, the solutions that satisfy the constraints of the problem are called **feasible solutions**.
- In a **minimum cost** scenario, it becomes a **minimization problem**, and the solution with the minimum cost is called an **optimal solution**.

---

## Greedy Strategy

- The greedy method solves a problem in **stages**.
- At each stage:
  - We select a choice based on a greedy rule.
  - We check whether the choice is **feasible**.
  - If feasible, we include it in the solution.

---

## Approach

### Algorithm Greedy(a, n)

```cpp
n = 5;

Greedy(a, n) {
    for (int i = 1; i <= n; i++) {
        x = select(a);

        if (feasible(x)) {
            solution = solution + x;
        }
    }
}

```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int a = *max_element(nums.begin(), nums.end());
        int b = *min_element(nums.begin(), nums.end());

        return 1LL * k * (a - b); // 1LL = long long
    }
};
 

