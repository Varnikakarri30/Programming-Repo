# Operating Systems (OS) - Topic 4 & Topic 5 Notes

# Topic 4: File Systems

## What is a File?

A file is a collection of related data stored in secondary storage and identified by a name.

### Examples
- resume.pdf
- photo.jpg
- assignment.docx
- movie.mp4

### Interview Answer
> A file is a collection of related data stored in secondary storage and identified by a name.

---

## What is a Directory (Folder)?

A directory is a container used to store and organize files and other directories.

### Real-Life Example

Think of a folder in your cupboard.

```text
Documents
├── Resume.pdf
├── Notes.pdf
├── Assignment.docx
```

### Interview Answer
> A directory is a container used to organize and manage files.

---

# File Allocation

## Why Do We Need File Allocation?

File allocation helps the operating system decide where files should be stored on the disk.

### Benefits
- Efficient storage management
- Faster file access
- Reduced fragmentation
- Better utilization of disk space

---

# What is Fragmentation?

Fragmentation is the wastage of memory or storage space.

There are two types:

1. Internal Fragmentation
2. External Fragmentation

---

## Internal Fragmentation

Internal Fragmentation occurs when more memory is allocated than required.

### Example

Suppose:

```text
Allocated Space = 10 KG
Required Space = 7 KG
Unused Space = 3 KG
```

The remaining 3 KG is wasted inside the allocated block.

### Definition

> Internal Fragmentation is the wastage of memory inside an allocated memory block.

---

## External Fragmentation

External Fragmentation occurs when free space is available but scattered into smaller blocks.

### Example

```text
2 KG Free
3 KG Free
4 KG Free
```

Total Free Space:

```text
9 KG
```

Now suppose we need:

```text
5 KG Continuous Space
```

Even though 9 KG is available, it is not available as one continuous block.

### Definition

> External Fragmentation occurs when free memory exists but is scattered into non-contiguous blocks.

---

# Methods of File Allocation

There are three methods:

1. Contiguous Allocation
2. Linked Allocation
3. Indexed Allocation

---

## 1. Contiguous Allocation

In Contiguous Allocation, file blocks are stored next to each other.

### Example

```text
File A

5  6  7  8  9
```

All blocks are consecutive.

### Advantages

- Simple
- Fast access
- Easy implementation

### Disadvantages

- External fragmentation occurs
- Difficult to find continuous free space

### Interview Answer

> Contiguous Allocation stores file blocks in consecutive memory locations.

---

## 2. Linked Allocation

In Linked Allocation, each block points to the next block.

### Example

```text
5 → 18 → 3 → 25 → 40
```

Similar to a Linked List.

### Advantages

- No external fragmentation
- Easy file expansion

### Disadvantages

- Slow random access
- Pointer overhead

### Interview Answer

> Linked Allocation stores file blocks anywhere on the disk and links them together using pointers.

---

## 3. Indexed Allocation

In Indexed Allocation, a special index block stores the addresses of all file blocks.

### Example

```text
Index Block

5
18
3
25
40
```

The index contains all locations of the file.

### Advantages

- Fast direct access
- No external fragmentation
- Easy file management

### Disadvantages

- Additional memory required for index block

### Interview Answer

> Indexed Allocation uses an index block that contains pointers to all file blocks.

---

## Comparison of Allocation Methods

| Method | Storage Style | Fast Access | External Fragmentation |
|----------|-------------|------------|------------------------|
| Contiguous | Side by Side | Yes | Yes |
| Linked | Linked List | No | No |
| Indexed | Index Block | Yes | No |

---

# Topic 5: Disk Scheduling

## What is a Disk?

A disk is a secondary storage device used to permanently store data.

### Examples

- Hard Disk Drive (HDD)
- Solid State Drive (SSD)

---

## HDD vs SSD

### HDD (Hard Disk Drive)

HDD stores data using spinning magnetic disks and a moving read/write head.

### Features

- Cheaper
- Slower
- Has moving parts

### Real-Life Example

Think of a CD player.

---

### SSD (Solid State Drive)

SSD stores data using flash memory chips.

### Features

- Faster
- More expensive
- No moving parts

### Real-Life Example

Think of a large pen drive.

---

## HDD vs SSD Comparison

| HDD | SSD |
|------|------|
| Hard Disk Drive | Solid State Drive |
| Slower | Faster |
| Moving Parts | No Moving Parts |
| Cheaper | More Expensive |
| More Mechanical Wear | More Durable |

---

# Why is Disk Access Slow?

Consider a librarian.

Suppose someone asks for:

```text
Book 5
Book 9
Book 12
Book 16
```

The librarian keeps moving between shelves.

More movement means more time.

Similarly, in HDDs, the disk head moves between tracks.

This movement takes time.

---

## What is Seek Time?

Seek Time is the time taken by the disk head to move from one track to another.

### Interview Answer

> Seek Time is the time required for the disk head to reach the requested track.

---

# Why Do We Need Disk Scheduling?

Without scheduling:

```text
5 → 90 → 10 → 150
```

The disk head moves unnecessarily.

This increases seek time.

To reduce movement and improve performance, we use Disk Scheduling.

---

## What is Disk Scheduling?

Disk Scheduling is the process of deciding the order in which disk requests are served to reduce disk head movement and improve performance.

### Interview Answer

> Disk Scheduling is the process of selecting the order of disk requests to minimize seek time and improve efficiency.

---

# Disk Scheduling Algorithms

There are four common algorithms:

1. FCFS
2. SSTF
3. SCAN
4. C-SCAN

---

## 1. FCFS (First Come First Serve)

Requests are served in the order they arrive.

### Example

```text
20 → 30 → 40 → 50
```

### Real-Life Example

Queue at a ticket counter.

### Advantages

- Simple
- Fair

### Disadvantages

- Large seek time possible

---

## 2. SSTF (Shortest Seek Time First)

The nearest request is served first.

### Example

Current Head Position:

```text
50
```

Requests:

```text
45, 55, 100, 120
```

Nearest request:

```text
55
```

Serve 55 first.

### Real-Life Example

A Swiggy delivery partner delivers to the nearest customer first.

### Advantages

- Less seek time

### Disadvantages

- Some requests may wait too long (starvation)

---

## 3. SCAN

Also called the Elevator Algorithm.

The disk head moves in one direction, serving requests.

After reaching the end, it reverses direction.

### Example

```text
→ → → →
← ← ← ←
```

### Real-Life Example

A lift moves up serving requests and then comes down serving requests.

### Advantages

- Better performance than FCFS

---

## 4. C-SCAN (Circular SCAN)

The disk head moves in only one direction.

After reaching the end, it jumps back to the beginning without serving requests during the return.

### Example

```text
→ → → →
Jump Back
→ → → →
```

### Real-Life Example

A circular lift that serves requests only while moving upward.

### Advantages

- More uniform waiting time

---

# SCAN vs C-SCAN

| SCAN | C-SCAN |
|--------|--------|
| Services both directions | Services only one direction |
| Like a normal elevator | Like a circular elevator |
| Unequal waiting times | More uniform waiting times |

---

# Quick Interview Revision

### File Systems

- File → Collection of related data.
- Directory → Container used to organize files.
- Internal Fragmentation → Waste inside allocated space.
- External Fragmentation → Free space scattered outside.
- Contiguous Allocation → Side-by-side storage.
- Linked Allocation → Blocks linked together.
- Indexed Allocation → Uses an index block.

### Disk Scheduling

- HDD → Hard Disk Drive.
- SSD → Solid State Drive.
- Seek Time → Time taken by disk head movement.
- Disk Scheduling → Reduces disk head movement.
- FCFS → First Come First Serve.
- SSTF → Shortest Seek Time First.
- SCAN → Elevator algorithm.
- C-SCAN → Circular SCAN algorithm.

