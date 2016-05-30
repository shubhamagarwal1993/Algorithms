We have a sorted array of unknown length.
we’re searching for the value k.

Check array indexes 0, 1, 2, 4, 8, 16, …, 2^N in a loop

	If the value is less than k we continue
	If we luckily find the actual value k then we return the index.

	if keep going in the loop until
		either we get an exception
		or we see an element larger than k.


If at index 2^m we see an element larger than k or an exception
	it means the value k (if it exists) must be between indexes 2^(m-1)+1 and 2^m-1 (inclusive)

Since the array is sorted, we know that the number at index 2^(m-1) is less than k

We break out of the loop and start another modified binary search
	between indexes 2^(m-1)+1 and 2^m-1.

If we previously got exception at index 2^m
	we may get more exceptions during this binary search.

	So we should handle this case by assigning the new high index to that location.

The complexity of this approach is O(logN)
	because we use binary search all the time, we never perform a linear scan.

Python code is given below:

def getIndex(arr, num):
	#check array indexes 0, 2^0, 2^1, 2^2, ...
	index, exp = 0, 0
	while True:
		try:
			if arr[index]==num:
				return index
			elif arr[index]<num:
				index=2**exp
				exp+=1
			else:
				break
		except IndexError:
			break

	#Binary Search
	left=(index/2)+1
	right=index-1
	while left<=right:
		try:
			mid=left+(right-left)/2
			if arr[mid]==num:
				return mid
			elif arr[mid]<num:
				left=mid+1
			else:
				right=mid-1
		except IndexError:
			right=mid-1
	return -1
