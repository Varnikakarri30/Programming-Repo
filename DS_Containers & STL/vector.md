# STL Notes - Vectors

## What is a Vector?

A vector is a dynamic array that can grow or shrink in size during program execution.

```cpp
vector<int> arr;
```

---

# Inserting Elements

## push_back()

Adds an element at the end of the vector.

```cpp
vector<int> arr;

arr.push_back(0);
arr.push_back(5);
```

---

## emplace_back()

Constructs and inserts the element directly into the vector.

```cpp
arr.emplace_back(3);
```

### Note

`emplace_back()` is slightly faster than `push_back()` and is commonly preferred in Competitive Programming.

---

# Removing Elements

## pop_back()

Removes the last element.

```cpp
arr.pop_back();
```

Example:

```cpp
{1, 2, 3}
```

After:

```cpp
arr.pop_back();
```

Becomes:

```cpp
{1, 2}
```

---

## clear()

Removes all elements from the vector.

```cpp
arr.clear();
```

After:

```cpp
{}
```

---

# Initializing Vectors

## Initialize with Zeros

```cpp
vector<int> vec(4, 0);
```

Output:

```cpp
{0, 0, 0, 0}
```

---

## Initialize with Same Value

```cpp
vector<int> vec2(4, 10);
```

Output:

```cpp
{10, 10, 10, 10}
```

---

# Copying Vectors

## Copy Entire Vector

```cpp
vector<int> vec3(vec2);
```

or

```cpp
vector<int> vec3(vec2.begin(), vec2.end());
```

---

## Copy Partial Vector

### First 2 Elements

```cpp
vector<int> vec3(vec2.begin(), vec2.begin() + 2);
```

Example:

```cpp
vec2 = {10, 20, 30, 40}
```

Result:

```cpp
vec3 = {10, 20}
```

---

## Last 2 Elements

```cpp
vector<int> vec3(vec2.end() - 2, vec2.end());
```

Example:

```cpp
vec2 = {10, 20, 30, 40}
```

Result:

```cpp
vec3 = {30, 40}
```

---

# Iterators

Vectors support:

```cpp
begin()
end()
rbegin()
rend()
```

| Function | Meaning |
|-----------|----------|
| begin() | First element |
| end() | After last element |
| rbegin() | Last element |
| rend() | Before first element |

---

# Swapping Vectors

```cpp
vector<int> v1 = {1, 2};
vector<int> v2 = {10, 20};

swap(v1, v2);
```

Result:

```cpp
v1 = {10, 20}
v2 = {1, 2}
```

---

# Traversing a Vector

```cpp
vector<int> arr = {1, 2, 3};

for(auto x : arr)
{
    cout << x << " ";
}
```

Output:

```text
1 2 3
```

---

# 2D Vectors

A vector can store other vectors.

```cpp
vector<vector<int>> vec;
```

---

## Example

```cpp
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> vec;

    vector<int> vec1(4, 12);
    vector<int> vec2(3, 10);

    vec.emplace_back(vec1);
    vec.emplace_back(vec2);

    for(auto row : vec)
    {
        for(auto x : row)
        {
            cout << x << " ";
        }

        cout << endl;
    }
}
```

Output:

```text
12 12 12 12
10 10 10
```

---

# Common Vector Functions

| Function | Purpose |
|-----------|----------|
| push_back(x) | Insert at end |
| emplace_back(x) | Faster insertion at end |
| pop_back() | Remove last element |
| clear() | Remove all elements |
| size() | Number of elements |
| empty() | Check if vector is empty |
| begin() | Iterator to first element |
| end() | Iterator after last element |
| front() | First element |
| back() | Last element |

---

# Quick Revision

```cpp
vector<int> v;

v.push_back(10);
v.emplace_back(20);

v.pop_back();

v.size();

v.front();

v.back();

v.clear();

swap(v1, v2);
```

---

# Interview Notes

### Vector vs Array

| Array | Vector |
|---------|---------|
| Fixed Size | Dynamic Size |
| Faster | Slightly Slower |
| No Built-in Functions | Rich STL Functions |
| Size decided at creation | Can grow/shrink |

### Time Complexities

| Operation | Complexity |
|------------|------------|
| push_back() | O(1) |
| emplace_back() | O(1) |
| pop_back() | O(1) |
| Access by index | O(1) |
| Insert in middle | O(n) |
| Delete in middle | O(n) |