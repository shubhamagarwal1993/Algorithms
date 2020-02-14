"""
Reservoir sampling is a family of randomized algorithms for randomly choosing k samples from a list of n items.
n is a very large or unknown number, large enough that the list doesn’t fit into main memory.
"""

# -*- encoding: utf-8 *-*

import random


def merge(input, left, mid, right):
    return


def select_k_items(input_stream, reservoir_length):
    """
    A function to randomly select k items from stream[0..n-1]

    Time compexity: O(n)

    Finding probability:
    Prove that the probability that any item stream[i] where 0 <= i < n will be in final reservoir[] is k/n.

    Divide the proof in 2 cases:
     - For last n-k stream items (k <= i < n)
     - ..
    """
    # index to maintain position in list
    stream_index = 0

    # reservoir is the output array ,initialized with the first k elements from input_stream
    reservoir = []
    for val in input_stream:
        reservoir.append(val)

        stream_index += 1
        if stream_index >= reservoir_length:
            break

    # Iterate from the (k+1)th element to nth element
    while(stream_index < len(input_stream)):
        # Pick a random index from 0 to reservoir_index
        random_index = random.randrange(stream_index + 1)

        # If the randomly picked index is smaller than k, then replace the element
        # present at the index with new element from stream
        if(random_index < reservoir_length):
            reservoir[random_index] = input_stream[stream_index]

        stream_index += 1

    print("Following are k randomly selected items")
    print(reservoir)

    return


def main():
    # input stream
    stream = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    k = 5
    select_k_items(stream, k)


if __name__ == '__main__':
    main()

