# Linked List in C++

## What is a Linked List?

A **Linked List** is a dynamic data structure whose size can grow or shrink during runtime.

### Characteristics

- Dynamic sizing (can add/remove nodes).
- Elements are stored in **non-contiguous memory locations**.
- Each node stores:
  - Data
  - Address of the next node
- Can store any data type.

---

## Why Does a Linked List Store the Address of the Next Element?

### Arrays

- Stored in contiguous memory locations.
- Elements can be accessed directly using indices.

```text
Index:  0   1   2   3
Array: [1] [2] [3] [4]
```

### Linked Lists

- Stored in non-contiguous memory locations.
- No indexing is available.
- To traverse the list, each node stores the address of the next node.

```text
[10|*] → [20|*] → [30|*] → NULL
```

The last node stores a **null pointer (`nullptr`)**.

---

## Use Cases

- Browser Back and Forward Buttons
- Stack Implementation
- Queue Implementation
- Undo/Redo Operations
- Music Playlists

---

## Traversing a Linked List

Traversal is performed using the `next` pointer.

```text
Head → Node1 → Node2 → Node3 → NULL
```

---

# Node Structure

```cpp
struct Node {
    int data;
    Node* next;

public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};
```

---

# Initialization

### Object Creation

```cpp
Node x = Node(2, nullptr);
```

### Dynamic Memory Allocation

```cpp
Node* y = new Node(2, nullptr);
```

---

# Basic Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }
};

int main() {
    vector<int> arr = {2,3,4,5};

    Node* y = new Node(arr[1], nullptr);

    cout << y->data;
}
```

> **Note:** In industry projects, `class` is generally preferred over `struct`.

---

# Memory Space Required by a Node

Each node stores:

1. Data
2. Pointer

### 32-bit System

```text
int      = 4 bytes
pointer  = 4 bytes

Total = 8 bytes
```

### 64-bit System

```text
int      = 4 bytes
pointer  = 8 bytes

Total = 12 bytes
```

---

# Converting an Array to a Linked List

## Algorithm

1. Create the head node from the first element.
2. Create a pointer `mover` to track the last node.
3. Keep creating nodes and connecting them.
4. Return the head.

## Implementation

```cpp
Node* Convertarr2LL(vector<int> arr) {

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++) {

        Node* temp = new Node(arr[i]);

        mover->next = temp;
        mover = temp;
    }

    return head;
}
```

---

# Traversal of a Linked List

### Time Complexity

```text
O(N)
```

### Important

⚠️ Never modify the `head` pointer while traversing.

Use a temporary pointer.

```cpp
Node* temp = head;

while(temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
}
```

---

# Length of a Linked List

### Time Complexity

```text
O(N)
```

### Implementation

```cpp
int LengthofLL(Node* head) {

    int cnt = 0;

    Node* temp = head;

    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}
```

---

# Searching for a Value in a Linked List

### Complexity Analysis

| Case | Complexity |
|--------|-----------|
| Best Case | O(1) |
| Average Case | O(N/2) |
| Worst Case | O(N) |

### Implementation

```cpp
bool Findvalue(Node* head, int val) {

    Node* temp = head;

    while(temp != NULL) {

        if(temp->data == val)
            return true;

        temp = temp->next;
    }

    return false;
}
```

---

# Deletion Operations

## 1. Delete Head Node

### Time Complexity

```text
O(1)
```

### Implementation

```cpp
Node* removehead(Node* head) {

    if(head == NULL)
        return NULL;

    Node* temp = head;

    head = head->next;

    delete temp;

    return head;
}
```

---

## 2. Delete Tail Node

### Time Complexity

```text
O(N)
```

### Implementation

```cpp
Node* removetail(Node* head) {

    if(head == NULL || head->next == NULL)
        return NULL;

    Node* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}
```

---

## 3. Delete Node at Position K

### Time Complexity

```text
O(N)
```

### Implementation

```cpp
Node* removeposition(Node* head, int k) {

    if(head == NULL)
        return head;

    if(k == 1) {

        Node* temp = head;

        head = head->next;

        delete temp;

        return head;
    }

    int cnt = 0;

    Node* prev = NULL;
    Node* temp = head;

    while(temp != NULL) {

        cnt++;

        if(cnt == k) {

            prev->next = temp->next;

            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
```

---

## 4. Delete Node by Value

### Time Complexity

```text
O(N)
```

### Implementation

```cpp
Node* removeelement(Node* head, int ele) {

    if(head == NULL)
        return head;

    if(head->data == ele) {

        Node* temp = head;

        head = head->next;

        delete temp;

        return head;
    }

    Node* prev = NULL;
    Node* temp = head;

    while(temp != NULL) {

        if(temp->data == ele) {

            prev->next = temp->next;

            delete temp;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
```

---

# Insertion Operations

## 1. Insert at Head

### Time Complexity

```text
O(1)
```

### Implementation

```cpp
Node* Inserthead(Node* head, int val) {

    Node* temp = new Node(val, head);

    return temp;
}
```

---

## 2. Insert at Tail

### Time Complexity

```text
O(N)
```

### Implementation

```cpp
Node* Inserttail(Node* head, int val) {

    if(head == NULL)
        return new Node(val);

    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    Node* insert = new Node(val);

    temp->next = insert;

    return head;
}
```

---

## 3. Insert at Position K

### Method 1: Using Previous Pointer

```cpp
Node* Insertk(Node* head, int val, int k) {

    if(head == NULL)
        return new Node(val);

    if(k == 1)
        return new Node(val, head);

    int cnt = 0;

    Node* prev = NULL;
    Node* temp = head;

    while(temp != NULL) {

        cnt++;

        if(cnt == k) {

            Node* newNode = new Node(val, temp);

            prev->next = newNode;
            break;
        }

        prev = temp;
        temp = temp->next;
    }

    return head;
}
```

### Method 2: Without Previous Pointer

```cpp
Node* Insertk(Node* head, int val, int k) {

    if(head == NULL)
        return new Node(val);

    if(k == 1)
        return new Node(val, head);

    int cnt = 0;

    Node* temp = head;

    while(temp != NULL) {

        cnt++;

        if(cnt == k - 1) {

            Node* newNode = new Node(val, temp->next);

            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}
```

---

## 4. Insert Before a Given Value

### Example

```text
11 → 2 → 3 → 7 → 9 → 4

↓

11 → 2 → 3 → 7 → 9 → 29 → 4
```

### Implementation

```cpp
Node* InsertValue(Node* head, int val, int ele) {

    if(head == NULL)
        return NULL;

    if(head->data == ele)
        return new Node(val, head);

    Node* temp = head;

    while(temp->next != NULL) {

        if(temp->next->data == ele) {

            Node* newNode =
                new Node(val, temp->next);

            temp->next = newNode;
            break;
        }

        temp = temp->next;
    }

    return head;
}
```

---

# Complexity Summary

## Searching

| Case | Complexity |
|--------|-----------|
| Best Case | O(1) |
| Average Case | O(N/2) |
| Worst Case | O(N) |

## Insertion

| Operation | Complexity |
|------------|------------|
| Head | O(1) |
| Tail | O(N) |
| Position K | O(N) |
| Before Value | O(N) |

## Deletion

| Operation | Complexity |
|------------|------------|
| Head | O(1) |
| Tail | O(N) |
| Position K | O(N) |
| By Value | O(N) |

---

# Key Takeaways

✅ Dynamic size.

✅ Non-contiguous memory allocation.

✅ Each node stores data and next pointer.

✅ Traversal uses the `next` pointer.

✅ Head insertion/deletion takes **O(1)** time.

✅ Most operations require traversal and take **O(N)** time.

✅ Never modify the original `head` pointer while traversing.

