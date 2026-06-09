# C++ Basics & STL Notes

---

# Header Files

```cpp
#include <bits/stdc++.h>
```

`bits/stdc++.h` contains almost all standard C++ libraries and is commonly used in Competitive Programming.

Alternative:

```cpp
#include <iostream>
#include <string>
```

---

# Namespace

```cpp
using namespace std;
```

This avoids writing:

```cpp
std::cout << "Hello";
std::endl;
```

Instead, we can write:

```cpp
cout << "Hello";
endl;
```

---

# Struct

A `struct` is a user-defined data type used to group different types of data together.

## Example

```cpp
#include <iostream>
using namespace std;

struct Node {
    string str;
    double db;
    int number;
    char c;

    Node(string str_, double db_, int number_, char c_) {
        str = str_;
        db = db_;
        number = number_;
        c = c_;
    }
};

int main() {

    Node varni("Varnika", 93.5, 1, 'V');

    cout << varni.str << endl;

    return 0;
}
```

### Important

For objects:

```cpp
Node obj(...);
```

For dynamic allocation:

```cpp
Node* obj = new Node(...);
```

---

# Arrays

Arrays store elements of the same data type.

## Memory Limits

### Global Array

```cpp
int arr[10000000];
```

Maximum size is approximately:

```text
10^7
```

### Local Array (Inside main)

```cpp
int arr[1000000];
```

Maximum size is approximately:

```text
10^6
```

---

# STL Array Container

```cpp
#include <array>

array<int, 5> arr = {1, 2, 3, 4, 5};
```

---

## Initialization

```cpp
array<int, 5> arr = {1, 2, 3, 0, 0};
```

### All Zeros

```cpp
array<int, 5> arr = {0};
```

Equivalent to:

```cpp
{0, 0, 0, 0, 0}
```

### Partial Initialization

```cpp
array<int, 3> arr = {1};
```

Equivalent to:

```cpp
{1, 0, 0}
```

---

# fill()

Fills the entire array with a given value.

```cpp
array<int, 5> arr;

arr.fill(5);
```

Output:

```text
5 5 5 5 5
```

---

# Accessing Elements

```cpp
arr.at(index);
```

Example:

```cpp
for(int i = 0; i < 5; i++) {
    cout << arr.at(i) << " ";
}
```

---

# Iterators

Important iterator functions:

```cpp
begin()
end()
rbegin()
rend()
```

### Example

Array:

```cpp
{1, 2, 3, 4, 5}
```

```text
begin()  -> 1

end()    -> after 5

rbegin() -> 5

rend()   -> before 1
```

---

# Forward Iteration

```cpp
array<int, 5> arr = {1,2,3,4,5};

for(auto it = arr.begin(); it != arr.end(); it++) {
    cout << *it << " ";
}
```

Output:

```text
1 2 3 4 5
```

---

# Range-Based Loop

```cpp
for(auto it : arr) {
    cout << it << " ";
}
```

Output:

```text
1 2 3 4 5
```

---

# Reverse Iteration

```cpp
for(auto it = arr.rbegin(); it != arr.rend(); it++) {
    cout << *it << " ";
}
```

Output:

```text
5 4 3 2 1
```

---

# Reverse Iterator Notes

For reverse iterators:

```cpp
++  -> moves left
--  -> moves right
```

Because the iterator traverses in reverse order.

---

# String Traversal

```cpp
string str = "Varnika";

for(auto c : str) {
    cout << c << " ";
}
```

Output:

```text
V a r n i k a
```

---

# Useful STL Array Functions

## Size

```cpp
arr.size();
```

Returns:

```text
Number of elements
```

---

## Front Element

```cpp
arr.front();
```

Equivalent to:

```cpp
arr.at(0);
```

---

## Back Element

```cpp
arr.back();
```

Equivalent to:

```cpp
arr.at(arr.size() - 1);
```

---

# Quick Revision

| Function | Purpose |
|-----------|----------|
| `arr.at(i)` | Access element |
| `arr.size()` | Array size |
| `arr.front()` | First element |
| `arr.back()` | Last element |
| `arr.fill(x)` | Fill entire array |
| `begin()` | First element iterator |
| `end()` | After last element |
| `rbegin()` | Reverse begin |
| `rend()` | Reverse end |

---

# Interview Notes

### `auto`

Automatically detects the variable type.

```cpp
auto x = 10;
```

Compiler treats it as:

```cpp
int x = 10;
```

---

### Why `*it`?

```cpp
cout << *it;
```

Iterators behave like pointers.

`*it` means:

```text
Value stored at that iterator position
```

Without `*`, you'll get the iterator itself, not the value.