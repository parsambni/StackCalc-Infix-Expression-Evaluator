# Priority Queue Implementation

## Overview
This project implements five different variations of a priority queue using a fixed-size array in C++. Each implementation has unique insertion and deletion strategies to manage priority elements efficiently.

## Implemented Algorithms

### 1. PriorityQueue_1
- **Insertion**: Elements are inserted at the rear.
- **Deletion**: The maximum element is found and deleted, followed by shifting elements to maintain order.

### 2. PriorityQueue_2
- **Insertion**: Elements are inserted at the first empty slot.
- **Deletion**: The maximum element is found and marked as deleted (-1).

### 3. PriorityQueue_3
- **Insertion**: Elements are inserted at the rear.
- **Deletion**: The maximum element is found and marked as deleted (-1). Compression is performed when necessary.

### 4. PriorityQueue_4
- **Insertion**: Elements are inserted in sorted order.
- **Deletion**: The maximum element is always the last element and is deleted directly.

### 5. PriorityQueue_5
- **Insertion**: Elements are inserted at the rear.
- **Deletion**: The maximum element is found and replaced with the rear element before reducing the queue size.

## Usage
### Compilation
```sh
 g++ priority_queue.cpp -o priority_queue
```

### Running the Program
```sh
 ./priority_queue
```

## Example Output
```
Max deleted from PQ1: 10
Max deleted from PQ2: 20
Max deleted from PQ3: 30
Max deleted from PQ4: 40
Max deleted from PQ5: 50
```

## License
This project is licensed under the MIT License.

