# DSA Practice Problems

This repository is a collection of data-structure and algorithm practice
solutions in C++. Each solution is kept in a topic folder and is written in
the style commonly used by coding platforms such as LeetCode and GeeksforGeeks.

The README is also a study guide: every problem below includes a short
description, a small example, the main idea, complexity, and a direct link to
the implementation.

## Topics

- [Arrays](#arrays)
- [Binary Search](#binary-search)
- [Dynamic Programming](#dynamic-programming)
- [Graphs](#graphs)
- [Greedy](#greedy)
- [Linked Lists](#linked-lists)
- [Strings](#strings)

## How to Use the Solutions

Most files contain a `class Solution` intended to be submitted to an online
judge. The judge supplies the required headers and calls the method. A few
files contain a complete `main` function and can be compiled directly:

```bash
g++ -std=c++17 -Wall -Wextra path/to/file.cpp -o solution
./solution
```

The links below point to the source files in this repository. Open a link to
read the complete implementation.

---

## Arrays

### 1. Find a Peak Element

**Problem:** Given an array where adjacent values are different, return an
index whose value is greater than its neighbors. An edge element only needs to
be greater than its one neighbor.

**Example:** `[1, 2, 3, 1]` → index `2`, because `3` is a peak.

**Approach:** Store `(value, index)` pairs, sort them in descending order, and
return the index of the largest value.

**Complexity:** `O(n log n)` time and `O(n)` extra space.

**Source:** [`Arrays/LeetCode_find_peak_element.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Arrays/LeetCode_find_peak_element.cpp)

### 2. Contains Duplicate

**Problem:** Determine whether an array contains any value more than once.

**Example:** `[1, 2, 3, 1]` → `true`; `[1, 2, 3, 4]` → `false`.

**Approach:** Insert every number into a set. If the set size is smaller than
the original array size, at least one duplicate exists.

**Complexity:** `O(n log n)` time and `O(n)` extra space.

**Source:** [`Arrays/contains_duplicate.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Arrays/contains_duplicate.cpp)

### 3. Maximum and Minimum Element

**Problem:** Find the smallest and largest values in an array.

**Example:** `[3, 5, 1, 2, 4]` → minimum `1`, maximum `5`.

**Approach:** Scan the array to update the minimum and maximum values.

**Complexity:** `O(n)` time and `O(1)` extra space.

**Source:** [`Arrays/maximum_minimum_element_in_array.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Arrays/maximum_minimum_element_in_array.cpp)

### 4. Reverse an Array

**Problem:** Reverse the order of all elements in an array.

**Example:** `[1, 2, 3, 4]` → `[4, 3, 2, 1]`.

**Approach:** Copy values from the original array in reverse order into a
temporary vector, then write them back.

**Complexity:** `O(n)` time and `O(n)` extra space.

**Source:** [`Arrays/reverse_the_array.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Arrays/reverse_the_array.cpp)

---

## Binary Search

All binary-search solutions require a sorted input unless the problem
explicitly provides a rotated sorted array.

### 5. Find First and Last Position

**Problem:** In a sorted array, return the first and last index of a target.
Return `[-1, -1]` if it is absent.

**Example:** `nums = [5, 7, 7, 8, 8, 10]`, target `8` → `[3, 4]`.

**Approach:** Use one lower-bound search for the first value greater than or
equal to the target and one upper-bound search for the first value greater
than the target.

**Complexity:** `O(log n)` time and `O(1)` extra space.

**Source:** [`Binary_Search/LeetCode_Find_first_and_last_position.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Binary_Search/LeetCode_Find_first_and_last_position.cpp)

### 6. Integer Square Root

**Problem:** Return `floor(sqrt(x))` without using a square-root library
function.

**Example:** `x = 8` → `2`, because `2² ≤ 8 < 3²`.

**Approach:** Binary search the answer range and use `long long` for the
square to avoid integer overflow.

**Complexity:** `O(log x)` time and `O(1)` extra space.

**Source:** [`Binary_Search/LeetCode_Sqrt(x).cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Binary_Search/LeetCode_Sqrt%28x%29.cpp)

### 7. Search in a Rotated Sorted Array

**Problem:** Search for a target in a sorted array that was rotated at an
unknown pivot.

**Example:** `[4, 5, 6, 7, 0, 1, 2]`, target `0` → index `4`.

**Approach:** At each step, one half is still sorted. Check whether the target
belongs to that half, then discard the other half.

**Complexity:** `O(log n)` time and `O(1)` extra space.

**Source:** [`Binary_Search/LeetCode_search_in_rotated_sorted_arrey.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Binary_Search/LeetCode_search_in_rotated_sorted_arrey.cpp)

### 8. Search Insert Position

**Problem:** Return the index where a target exists or should be inserted to
keep a sorted array in order.

**Example:** `[1, 3, 5, 6]`, target `2` → index `1`.

**Approach:** Find the first index whose value is greater than or equal to the
target.

**Complexity:** `O(log n)` time and `O(1)` extra space.

**Source:** [`Binary_Search/LeetCode_search_insert_position.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Binary_Search/LeetCode_search_insert_position.cpp)

---

## Dynamic Programming

Dynamic programming stores answers to smaller subproblems so that each state
is solved once instead of repeatedly.

### 9. Climbing Stairs

**Problem:** You can climb one or two steps at a time. Count the number of
different ways to reach step `n`.

**Example:** `n = 4` → `5` ways: `1111`, `112`, `121`, `211`, `22`.

**Approach:** The last move comes from step `n - 1` or `n - 2`, so
`dp[n] = dp[n - 1] + dp[n - 2]`.

**Complexity:** `O(n)` time and `O(n)` space.

**Source:** [`DP/LeetCode_Climbing_Stairs.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/DP/LeetCode_Climbing_Stairs.cpp)

### 10. Coin Change II

**Problem:** Count the number of combinations that form `amount` using
unlimited copies of the given coin values. Coin order does not create a new
combination.

**Example:** `amount = 5`, coins `[1, 2, 5]` → `4` combinations:
`5`, `2+2+1`, `2+1+1+1`, and `1+1+1+1+1`.

**Approach:** Process coins outside and amounts inside, so each combination is
counted once regardless of order.

**Complexity:** `O(amount × number_of_coins)` time and `O(amount)` space.

**Source:** [`DP/LeetCode_Coin_Change_2.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/DP/LeetCode_Coin_Change_2.cpp)

### 11. Coin Change

**Problem:** Find the minimum number of coins needed to make an amount. Return
`-1` when it is impossible.

**Example:** coins `[1, 2, 5]`, amount `11` → `3` (`5 + 5 + 1`).

**Approach:** `dp[i]` stores the fewest coins needed for amount `i`; try every
coin as the final coin.

**Complexity:** `O(amount × number_of_coins)` time and `O(amount)` space.

**Source:** [`DP/LeetCode_Coin_change.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/DP/LeetCode_Coin_change.cpp)

### 12. Fibonacci Number

**Problem:** Return the `n`th Fibonacci number, where `F(0) = 0` and
`F(1) = 1`.

**Example:** `n = 6` → `8`.

**Approach:** Build the sequence from the two base cases using
`dp[i] = dp[i - 1] + dp[i - 2]`.

**Complexity:** `O(n)` time and `O(n)` space.

**Source:** [`DP/LeetCode_Fibonacci_Number.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/DP/LeetCode_Fibonacci_Number.cpp)

### 13. House Robber

**Problem:** Maximize the money robbed from houses in a line without robbing
two adjacent houses.

**Example:** `[2, 7, 9, 3, 1]` → `12` (`2 + 9 + 1`).

**Approach:** At each house, choose between skipping it (`dp[i - 1]`) and
robbing it plus the best result two houses earlier (`dp[i - 2] + nums[i]`).

**Complexity:** `O(n)` time and `O(n)` space.

**Source:** [`DP/LeetCode_House_Robber.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/DP/LeetCode_House_Robber.cpp)

### 14. Minimum Cost Climbing Stairs

**Problem:** Each stair has a cost. Starting from step `0` or `1`, find the
minimum cost to reach the top.

**Example:** `[10, 15, 20]` → `15`; pay `15` and jump over the final stair.

**Approach:** To reach position `i`, come from `i - 1` or `i - 2`, choosing the
cheaper previous route.

**Complexity:** `O(n)` time and `O(n)` space.

**Source:** [`DP/LeetCode_Min_Cost_Climbing_Stairs.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/DP/LeetCode_Min_Cost_Climbing_Stairs.cpp)

### 15. Subset Sum

**Problem:** Decide whether some subset of the array adds exactly to a target
sum. Each element can be used at most once.

**Example:** `[3, 34, 4, 12, 5, 2]`, target `9` → `true` (`4 + 3 + 2`).

**Approach:** For every element, choose between excluding it and including it
when it does not exceed the remaining sum. Memoization stores repeated states.

**Complexity:** `O(n × sum)` time and `O(n × sum)` space.

**Source:** [`DP/Subset_Sum_problem.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/DP/Subset_Sum_problem.cpp)

---

## Graphs

### 16. Breadth-First Search (BFS)

**Problem:** Visit the vertices of a graph level by level from vertex `0`.

**Example:** For edges `0-1`, `0-2`, `1-3`, a BFS traversal can be
`[0, 1, 2, 3]`.

**Approach:** Use a queue and mark vertices when they are enqueued, preventing
the same vertex from being added more than once.

**Complexity:** `O(V + E)` time and `O(V)` space.

**Source:** [`Graphs/BFS.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/BFS.cpp)

### 17. Bellman-Ford

**Problem:** Find shortest paths from one source, including graphs with
negative edge weights, and detect a reachable negative cycle.

**Example:** Edges `0 → 1 (4)`, `0 → 2 (5)`, `1 → 2 (-2)` give distance to
`2` equal to `2`.

**Approach:** Relax every edge `V - 1` times. A further improvement indicates a
negative cycle.

**Complexity:** `O(VE)` time and `O(V)` space.

**Source:** [`Graphs/Bellman_ford.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/Bellman_ford.cpp)

### 18. Depth-First Search (DFS)

**Problem:** Traverse a graph by exploring as far as possible along one branch
before backtracking.

**Example:** On edges `0-1`, `0-2`, `1-3`, one valid traversal is
`[0, 1, 3, 2]`.

**Approach:** Use an explicit stack and a visited array. Neighbors are pushed
in reverse order to preserve a predictable traversal order.

**Complexity:** `O(V + E)` time and `O(V)` space.

**Source:** [`Graphs/DFS.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/DFS.cpp)

### 19. DFS Discovery and Finishing Times

**Problem:** Record the time at which DFS enters and leaves every vertex.

**Example:** If DFS enters vertex `0`, visits `1`, and returns, the discovery
time of `0` is earlier than the finishing time of `0`.

**Approach:** Use three colors: white for unvisited, gray for active, and
black for finished. Increment a timer on both entry and exit.

**Complexity:** `O(V²)` with the adjacency-matrix representation used here,
and `O(V)` auxiliary space.

**Source:** [`Graphs/DFS_time.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/DFS_time.cpp)

### 20. Dijkstra's Shortest Path

**Problem:** Find shortest distances from a source in a weighted graph with
non-negative edge weights.

**Example:** Edges `0-1 (4)`, `0-2 (1)`, `2-1 (2)` give distance `0 → 1 = 3`.

**Approach:** Always expand the unprocessed vertex with the smallest known
distance using a min-priority queue, then relax its edges.

**Complexity:** `O((V + E) log V)` time and `O(V + E)` space.

**Source:** [`Graphs/Dijkstra's_sortest_path.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/Dijkstra%27s_sortest_path.cpp)

### 21. Dijkstra with Predecessors

**Problem:** Compute shortest distances and the predecessor of each vertex so
that shortest paths can be reconstructed.

**Example:** If the shortest route to `3` is `0 → 1 → 3`, the predecessor of
`3` is `1`.

**Approach:** Store both `dist[v]` and `pred[v]`; update the predecessor when a
shorter route is found.

**Complexity:** `O((V + E) log V)` time and `O(V + E)` space.

**Source:** [`Graphs/Dijstra_slide.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/Dijstra_slide.cpp)

### 22. Cheapest Flights Within K Stops

**Problem:** Find the cheapest route from `src` to `dst` using at most `k`
stops.

**Example:** Flights `0 → 1 (100)`, `1 → 2 (100)`, `0 → 2 (500)`, `k = 1`
give cost `200`.

**Approach:** Track both the current city and the number of stops. A distance
is stored separately for each allowed stop count.

**Complexity:** Depends on the explored states; up to `O((V + E)k log(Vk))`
time and `O(Vk)` space.

**Source:** [`Graphs/LeetCode_Cheapest_Flights_Within_K_Stops.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/LeetCode_Cheapest_Flights_Within_K_Stops.cpp)

### 23. Course Schedule

**Problem:** Determine whether all courses can be completed when prerequisite
relationships form a directed graph.

**Example:** `0 → 1`, `1 → 2` is possible; `0 → 1`, `1 → 0` is impossible
because it contains a cycle.

**Approach:** Run DFS with white/gray/black states. An edge to a gray vertex
is a back edge and proves that a cycle exists.

**Complexity:** `O(V + E)` time and `O(V + E)` space.

**Source:** [`Graphs/LeetCode_Class_Schedule.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/LeetCode_Class_Schedule.cpp)

### 24. Course Schedule II

**Problem:** Return an order in which all courses can be completed, or an
empty array if prerequisites contain a cycle.

**Example:** prerequisites `[[1, 0], [2, 1]]` → `[0, 1, 2]`.

**Approach:** Perform DFS topological sorting and order vertices by decreasing
finishing time. Reject the result when DFS detects a cycle.

**Complexity:** `O(V + E)` time and `O(V + E)` space.

**Source:** [`Graphs/LeetCode_Class_Schedule_2.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/LeetCode_Class_Schedule_2.cpp)

### 25. Network Delay Time

**Problem:** A signal starts at node `k`. Find how long it takes to reach every
node, or return `-1` if some node is unreachable.

**Example:** If the shortest arrival times are `[0, 2, 5]`, the answer is
`5`, the slowest arrival.

**Approach:** Run Dijkstra from `k`, then return the maximum finite distance.

**Complexity:** `O((V + E) log V)` time and `O(V + E)` space.

**Source:** [`Graphs/LeetCode_Network_delay_time.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/LeetCode_Network_delay_time.cpp)

### 26. Minimum Steps Through a Maze

**Problem:** Find the shortest path from `S` to `T` in a grid. Cells marked
`0` are blocked, and movement is allowed up, down, left, or right.

**Example:** In a maze with an open route of six moves from `S` to `T`, the
answer is `6`.

**Approach:** BFS explores all cells at distance `d` before cells at distance
`d + 1`, guaranteeing the first target visit is shortest.

**Complexity:** `O(RC)` time and `O(RC)` space for an `R × C` maze.

**Source:** [`Graphs/Maze_BFS.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/Maze_BFS.cpp)

### 27. Prim's Minimum Spanning Tree

**Problem:** Find the total weight of a minimum spanning tree (MST) of a
connected weighted undirected graph.

**Example:** Edges with weights `1`, `2`, and `3` may form an MST of weight
`6` when they connect all vertices without a cycle.

**Approach:** Start from vertex `0` and repeatedly select the cheapest edge
that reaches an unvisited vertex.

**Complexity:** `O((V + E) log V)` time and `O(V + E)` space.

**Source:** [`Graphs/Prims_algorithm.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/Prims_algorithm.cpp)

### 28. Kruskal's Minimum Spanning Tree

**Problem:** Find the minimum total weight needed to connect every vertex
without cycles.

**Example:** Sort edges by weight and choose `1`, `2`, and `3` when they
connect new components; the MST weight is `6`.

**Approach:** Sort edges by weight and use disjoint-set union (DSU) to accept
an edge only when it joins two different components.

**Complexity:** `O(E log E)` time and `O(V)` auxiliary space.

**Source:** [`Graphs/kruskal_algorithm.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/kruskal_algorithm.cpp)

### 29. Topological Sort

**Problem:** Order the vertices of a directed acyclic graph so every edge
`u → v` places `u` before `v`.

**Example:** Edges `0 → 1` and `1 → 2` produce the order `[0, 1, 2]`.

**Approach:** Run DFS and sort vertices by decreasing finishing time.

**Complexity:** `O(V + E)` time and `O(V + E)` space.

**Source:** [`Graphs/topological_sort.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Graphs/topological_sort.cpp)

---

## Greedy

### 30. Fractional Knapsack

**Problem:** Maximize the value placed in a bag of fixed capacity when items
can be divided into fractions.

**Example:** Capacity `50`, items `(value, weight) = (60, 10), (100, 20),
(120, 30)` → maximum value `240`.

**Approach:** Sort items by value-to-weight ratio, take the highest-ratio
items first, and take a fraction of the final item if necessary.

**Complexity:** `O(n log n)` time and `O(n)` space.

**Source:** [`Greedy/Fractional_Kanpsack.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Greedy/Fractional_Kanpsack.cpp)

---

## Linked Lists

### 31. Merge Two Sorted Lists

**Problem:** Combine two sorted singly linked lists into one sorted list.

**Example:** `1 → 3 → 5` and `2 → 4 → 6` → `1 → 2 → 3 → 4 → 5 → 6`.

**Approach:** Compare the current nodes of both lists, attach the smaller one,
and continue until one list is exhausted.

**Complexity:** `O(m + n)` time and `O(1)` auxiliary space.

**Source:** [`LinkedList/Merge_Two_Sorted_List_leetcode.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/LinkedList/Merge_Two_Sorted_List_leetcode.cpp)

### 32. Reverse a Linked List

**Problem:** Reverse the direction of every `next` pointer in a singly linked
list.

**Example:** `1 → 2 → 3 → null` → `3 → 2 → 1 → null`.

**Approach:** Keep `prev`, `curr`, and the saved next node. Redirect
`curr->next` to `prev` and advance all pointers.

**Complexity:** `O(n)` time and `O(1)` auxiliary space.

**Source:** [`LinkedList/Reverse_Linked_List_leetcode.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/LinkedList/Reverse_Linked_List_leetcode.cpp)

---

## Strings

### 33. Valid Palindrome

**Problem:** Check whether a string reads the same forward and backward after
ignoring spaces, punctuation, and letter case.

**Example:** `"A man, a plan, a canal: Panama"` → `true`;
`"race a car"` → `false`.

**Approach:** Build a normalized string containing only lowercase letters and
digits, reverse it, and compare the two strings.

**Complexity:** `O(n)` time and `O(n)` extra space.

**Source:** [`Strings/valid_palindrome.cpp`](https://github.com/hasan2733/DSA_Practice_Problems/blob/main/Strings/valid_palindrome.cpp)

---

## Suggested Practice Order

1. Arrays
2. Binary search
3. Linked lists
4. BFS and DFS
5. Dynamic programming
6. Greedy algorithms
7. Minimum spanning trees and shortest paths

For each problem, first write the example by hand, identify the state that
changes at every step, and only then compare your solution with the linked
implementation.
