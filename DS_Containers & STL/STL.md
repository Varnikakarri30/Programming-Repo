# STL Notes - Striver

**Reference:**  
https://youtu.be/RRVYpIET_RU?si=mGjk9jHbVvY49agn

---

# Functions

## 1. Void Function

A void function does not return anything.

```cpp
void print() {
    cout << "raj";
}
```

---

## 2. Return Type Function

A return type function returns a value. The return type is specified using a data type.

```cpp
int add(int a, int b) {
    return a + b;
}
```

---

# Divisions of STL

- Algorithms
- Containers
- Functions
- Iterators

---

# Containers

## 1. Pair

A pair is used to store two values together.

### Basic Pair

```cpp
#include <iostream>
#include <utility>
using namespace std;

int main() {
    pair<int, int> pa = {1, 3};

    cout << pa.first << " " << pa.second << endl;
}
```

### Nested Pair

A pair can contain another pair.

```cpp
#include <iostream>
using namespace std;

int main() {

    pair<int, pair<int, char>> p = {1, {3, 'a'}};

    cout << p.first << endl;
    cout << p.second.first << endl;
    cout << p.second.second << endl;

    return 0;
}
```

### Array of Pairs

```cpp
#include <iostream>
using namespace std;

int main() {

    pair<int, int> arr[] = {
        {1, 2},
        {2, 3},
        {3, 4}
    };

    cout << arr[2].second << endl;

    return 0;
}
```

Output:

```text
4
```

---

## 2. Vector

A vector is a dynamic array. Unlike arrays, vectors can grow or shrink in size.

### Inserting Elements

- `push_back()` inserts an element at the end.
- `emplace_back()` constructs and inserts an element directly at the end.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    for (auto c : v) {
        cout << c << endl;
    }

    return 0;
}
```

Output:

```text
1
2
```

---

### Vector of Pairs

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<pair<int, char>> vec;

    vec.push_back({1, 'h'});
    vec.emplace_back(2, 'v');

    for (auto d : vec) {
        cout << d.first << " " << d.second << endl;
    }

    return 0;
}
```

Output:

```text
1 h
2 v
```

---

# Quick Revision

| Container | Purpose |
|------------|----------|
| Pair | Stores two values together |
| Nested Pair | Pair inside another pair |
| Array of Pairs | Array where each element is a pair |
| Vector | Dynamic array |
| Vector of Pairs | Dynamic array containing pairs |

---

## Common Functions

### Pair

```cpp
p.first
p.second
```

### Vector

```cpp
v.push_back(x);
v.emplace_back(x);
v.size();
v.empty();
```

### Range-Based Loop

```cpp
for(auto x : v) {
    cout << x;
}
```

### Range-Based Loop for Pairs

```cpp
for(auto p : vec) {
    cout << p.first << " " << p.second;
}
```