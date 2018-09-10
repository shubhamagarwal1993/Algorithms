Sorting algorithms
==================

## Overview

|     | Algo                  | Worst time    | Space   | Use                                                                                |
|-----|-----------------------|---------------|---------|------------------------------------------------------------------------------------|
| Yes | selection sort        | O(n^2)        | O(1)    | Simple 2 loop in place sorting. Better than mergesort if array mostly sorted       |
|     |                       |               |         |                                                                                    |
| Yes | insertion sort        | O(n * n)      | O(1)    | Sort like playing cards, take an element in array, find new position in place      |
| Yes | binary insertion sort | O(n^2)        | O(1)    | Useful when most array is sorted and only a few elements are out of place          |
|     |                       |               |         |                                                                                    |
| Yes | counting sort         | O(n+k)        | O(n+k)  | Sorting technique based on keys between a specific range, efficient if small range |
| Yes | radix sort            | O(d * (n+b))  | O(n+k)  | Sort in a lare range with few numbers, uses counting sort                          |
|     |                       |               |         |                                                                                    |
| Yes | merge sort            | O(n logn)     | O(n)    | best sorting algo for general purposes, takes extra array space to merge elements  |
| Yes | in-place merge sort   | O(n logn)     | O(1)    |                                                                                    |
|     |                       |               |         |                                                                                    |




| Yes | quick sort            | O(n^2)        | log(n)    | partition with pivot and swap                                                 |
|     |                       |               |           |                                                                               |
|     | Bucket sort           | O(n^2)        | O(nk)     | E.g. sort numbers between 0 and 1, n is num of buckets, k is significant bits |
|     |                       |               |           |                                                                               |
|     | heap sort             | O(n logn)     | O(1)      | create a max heap, remove max element from heap, repeat                       |
|     |                       |               |           |                                                                               |
|     | cubesort              | nlogn         | O(n)      | partitions data into groups and sorts like bucket sort                        |
|     |                       |               |           |                                                                               |





| No  | bubble sort           | n^2           | O(1)    | switch adjacent elements till all done                                        |
|-----|-----------------------|---------------|---------|-------------------------------------------------------------------------------|
