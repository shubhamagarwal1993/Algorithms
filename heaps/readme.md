# maxHeap
  - This heap is typically used for heap sort or for a priority queue where higher values indicate higher priority
  - Each node in a binary heap must be at least as large as both of its children

# minHeap
  - This heap is typically used for retrieving items with integer keys in ascending order or strings in alphabetical order

# heapifyUp / siftUp
  - swaps a node that is too large with its parent (thereby moving it up) until it is no larger than the node above it
  - This operation is generally only used to perform inserts into an existing heap, so it would be used to implement a priority queue using a binary heap

# heapifyDown / siftDown
  - swaps a node that is too small with its largest child (thereby moving it down) until it is at least as large as both nodes below
  - used in buildHeap and heapSort

## Insert a single element into an existing heap
  - O(logn) since heapifyUp will start from bottom of tree, and go to top of tree at max - height of tree is O(logn)

## Remove top element from an existing heap
  - O(logn) since heapifyDown

## buildHeap is an O(n) time operation
  - The buildHeap function takes an array of unsorted items
  - There are two approaches one might take for buildHeap using the siftUp and siftDown operations:
    - Start at the top of the heap (beginning of the array) and call siftUp on each item. At each step, the previously sifted items (the items before the current item in the array) form a valid heap, and sifting the next item up places it into a valid position in the heap. After sifting up each node, all items satisfy the heap property
    - Start at the end of the array and move backwards towards the front. At each iteration, you sift an item down until it is in the correct location
  - The work required for the siftUp approach is given by the sum
    - (h * n/2) + ((h-1) * n/4) + ((h-2) * n/8) + ... + (0 * 1)
    - The first term alone is h n/2 = 1/2 n log n, so this approach has complexity at best O(n log n)
  - The work required for the siftDown approach is given by the sum
    - (0 * n/2) + (1 * n/4) + (2 * n/8) + ... + (h * 1)
    - turn the finite sum into an infinite series and then use Taylor series
    - Since the infinite sum is exactly n, we conclude that the finite sum is no larger, and is therefore, O(n)

## heap sort runs in O(n logn) time
  - 

#### Why we use heapifyDown in buildHeap
  - The number of operations required for siftDown and siftUp is proportional to the distance the node may have to move
  - For siftDown, it is the distance from the bottom of the tree, so siftDown is expensive for nodes at the top of the tree
  - For siftUp, the work is proportional to the distance from the top of the tree, so siftUp is expensive for nodes at the bottom of the tree
  - Although both operations are O(log n) in the worst case, in a heap, only one node is at the top whereas half the nodes lie in the bottom layer
  - If we have to apply an operation to every node, we would prefer siftDown over siftUp

## Binary Heap
  - A Binary Heap is a complete Binary Tree, where all levels are completely filled except possibly the last level and the last level has all keys as left as possible. This property of Binary Heap makes them suitable to be stored in an array
  - The root element will be at Arr[0]
  - Arr[(i - 1) / 2] returns the parent node
  - Arr[(2 * i) + 1] returns the left child node
  - Arr[(2 * i) + 2] returns the right child node
