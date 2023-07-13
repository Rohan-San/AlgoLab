# AlgoLab
Topics (Click to jump):
1. [Algorithms](#algorithms)
   - [Linear Search](#linear-search)
   - [Binary Search](#binary-search)
   - [Bubble Sort](#bubble-sort)
   - [Insertion Sort](#insertion-sort)
   - [Merge Sort](#merge-sort)
   - [Quick Sort](#quick-sort)
   - [DFS](#depth-first-search)
   - [BFS](#breadth-first-search)
2. [Analysis](#analysis)
   - [Linear & Binary Search](#linear-and-binary-search)
   - [Bubble & Insertion Sort](#bubble-and-insertion-sort)
   - [Merge & Quick Sort](#merge-and-quick-sort)
   - [DFS & BFS](#dfs-and-bfs)
   
## Algorithms

1. ### Linear Search:
   - Start from the beginning of the array.
   - Compare each element with the target value.
   - If a match is found, return the index of the element.
   - If the end of the array is reached without finding a match, return -1.

2. ### Binary Search:
   - Set the low index to the beginning of the array and the high index to the end of the array.
   - While the low index is less than or equal to the high index:
     - Calculate the middle index as the average of the low and high indices.
     - If the middle element is equal to the target, return the middle index.
     - If the middle element is less than the target, update the low index to mid + 1.
     - If the middle element is greater than the target, update the high index to mid - 1.
   - If the target is not found, return -1.

3. ### Bubble Sort:
   - Start from the first element and compare it with the next element.
   - If the current element is greater than the next element, swap them.
   - Repeat this process for all elements in the array.
   - Continue this process for each pass until the array is sorted.

4. ### Insertion Sort:
   - Start with the second element in the array.
   - Compare the current element with the elements before it, moving them one position ahead if they are greater.
   - Repeat this process for all elements until the array is sorted.

5. ### Merge Sort:
   - Divide the array into two halves.
   - Recursively apply merge sort to each half.
   - Merge the sorted halves by comparing elements and placing them in the correct order.

6. ### Quick Sort:
   - Choose a pivot element from the array (usually the last element).
   - Partition the array into two parts: elements less than the pivot and elements greater than the pivot.
   - Recursively apply quick sort to the two partitions.

7. ### Depth-First Search:
   - Start from a given vertex.
   - Mark the vertex as visited and print its value.
   - Explore its adjacent vertices recursively, following an arbitrary order.
   - Repeat this process for each unvisited vertex until all vertices are visited.

8. ### Breadth-First Search:
   - Start from a given vertex.
   - Mark the vertex as visited and enqueue it.
   - While the queue is not empty:
     - Dequeue a vertex from the queue and print its value.
     - Enqueue all unvisited neighbors of the dequeued vertex.
     - Mark the neighbors as visited.

## Analysis

1. ### Linear and Binary Search
> **LINEAR SEARCH:** <br>
- The *best-case* scenario for linear search occurs when the key is found at the beginning of the array, resulting in a complexity of O(1).<br>
- The *worst-case* scenario happens when the key is either not present in the array or it is at the very end. In this case, the algorithm will need to iterate through all elements, resulting in a complexity of O(n), where n is the size of the array.<br>
- The *average case* complexity for linear search is also O(n), as it may need to search through approximately half of the array on average.<br>
> **BINARY SEARCH:** <br>
- The *best-case* scenario for binary search occurs when the key is found at the middle element of the array, resulting in a complexity of O(1).<br>
- The *worst-case* scenario happens when the key is either not present in the array or it is at one of the ends. In this case, the algorithm will divide the search space in half at each step, resulting in a complexity of O(log n), where n is the size of the array.<br>
- The *average case* complexity for binary search is also O(log n), as it halves the search space at each step, reducing the remaining elements to search exponentially.<br>

2. ### Bubble and Insertion Sort
> **BUBBLE SORT:** <br>
- The *best-case* scenario for bubble sort occurs when the array is already sorted. In this case, the algorithm will make a single pass through the array without any swaps, resulting in a complexity of O(n).<br>
- The *worst-case* scenario happens when the array is sorted in reverse order. In this case, the algorithm will need to make comparisons and swaps for every pair of adjacent elements, resulting in a complexity of O(n^2), where n is the size of the array.<br>
- The *average case* complexity for bubble sort is also O(n^2), as it generally requires multiple passes through the array and comparisons for each pair of adjacent elements.<br>
> **INSERTION SORT:** <br>
- The *best-case* scenario for insertion sort occurs when the array is already sorted. In this case, the algorithm will make a single pass through the array without any element shifting, resulting in a complexity of O(n).<br>
- The *worst-case* scenario happens when the array is sorted in reverse order. In this case, each element needs to be compared and shifted to its correct position, resulting in a complexity of O(n^2), where n is the size of the array.<br>
- The *average case* complexity for insertion sort is also O(n^2), as it requires comparisons and potential shifting for each element, with the number of operations increasing quadratically with the input size.<br>

3. ### Merge and Quick Sort
> **MERGE SORT:** <br>
- The best-case, worst-case, and average case complexity for merge sort is O(n log n), where n is the size of the array. It consistently divides the array into halves and performs merging operations, resulting in a time complexity that scales logarithmically with the input size. The additional space complexity for merge sort is O(n) due to the need for temporary arrays during the merging process.<br>
> **QUICK SORT:** <br>
- The *best-case* scenario for Quick Sort occurs when the pivot divides the array into two equal-sized subarrays. In this case, the algorithm performs balanced partitions, resulting in a complexity of O(n log n).<br>
- The *worst-case* scenario happens when the pivot always selects the smallest or largest element, resulting in unbalanced partitions. This can lead to one subarray with only one element and the other with n-1 elements. In the worst case, the complexity of Quick Sort becomes O(n^2).<br>
- The *average case* complexity for Quick Sort is O(n log n), making it an efficient sorting algorithm for most cases. The average case occurs when the pivot divides the array into subarrays of roughly equal sizes.<br>

4. ### DFS and BFS
> **BFS:** <br>
- The *best-case* for BFS occurs when the goal node is close to the starting node. In this case, BFS will find the goal node quickly as it explores all the nodes at the current level before moving to the next level. The time complexity of BFS in the best case is O(1) or constant time.<br>
- The *worst-case* for BFS occurs when the goal node is located at the deepest level of the graph or tree. In this case, BFS will have to explore all the nodes before reaching the goal node. The time complexity of BFS in the worst case is O(V + E), where V is the number of vertices and E is the number of edges in the graph.<br>
- The *average case* for BFS depends on the structure and size of the graph. In a balanced tree or graph with a uniform branching factor, BFS will have a time complexity of O(V + E), similar to the worst case. However, if the graph is sparse or has a low average branching factor, the time complexity of BFS can be closer to O(V).<br>
> **DFS:** <br>
- The *best-case* for DFS occurs when the goal node is found early in the search, preferably in the first few levels of the search tree. This happens if the goal node is a direct child of the starting node or located in a branch that is explored early. The time complexity of DFS in the best case is O(1) or constant time.<br>
- The *worst-case* for DFS occurs when the goal node is located at the deepest level of the search tree or in a branch that is explored last. In this case, DFS will traverse all possible paths before finding the goal node. The time complexity of DFS in the worst case is O(V + E), where V is the number of vertices and E is the number of edges in the graph.<br>
- The *average case* for DFS depends on the structure and size of the graph. In a balanced tree or graph with a uniform branching factor, DFS will have a time complexity of O(V + E), similar to the worst case. However, if the graph is sparse or has a low average branching factor, the time complexity of DFS can be closer to O(V).<br>
