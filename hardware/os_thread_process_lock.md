# Process and threads
The one thread that runs on a process at the start of a program is called the main/primary thread.

A Process is made up of many threads. It consists of:
- Virtual address space
- Executable code
- Open handles to system objects
- A security context
- A unique process identifier
- Environment variables
- A priority class
- Minimum and maximum working set sizes
- At least one thread of execution
- Processes run in separate memory spaces

Threads of the same process:
- Share memory
- Share virtual address space
- Share system resources
- Each threads has its own stack but share heap
- Each thread has its own registers
- If a thread allocates some object on its stack, and sends the address to another thread, they'll both have equal access to that object

# Lock:
Lock:
- Allows only 1 thread to enter the part that's locked and the lock is not shared with any other processes
## Read / Write lock:
- allows either unlimited number of readers or 1 writer at any given time

# Mutex: (A kernel resource that provide synchronization services):
- A locking mechanism
- A mutex is the same as a lock but it can be system wide (shared by multiple processes)
- Used to synchronize access to a resource
- Only one task can acquire the mutex
- Pthread mutexes are used for mutual exclusion between threads of the same process
- System V IPC (man svipc) semaphores can be used across processes
- Filesystem-level locks (on files or parts of files) can also used to coordinate between multiple processes
- A mutex provides mutual exclusion, either producer or consumer can have the key (mutex) and proceed with their work. As long as the buffer is filled by producer, the consumer needs to wait, and vice versa.

# Semaphore: (A kernel resource that provide synchronization services):
- A signaling mechanism
- A semaphore does the same as a mutex but allows x number of threads to enter, this can be used for example to limit the number of cpu, io or ram intensive tasks running at the same time
- In lieu of single buffer, we can split the 4 KB buffer into four 1 KB buffers (identical resources). A semaphore can be associated with these four buffers. The consumer and producer can work on different buffers at the same time.

# Deadlocks and Livelocks
## Essential conditions for deadlock:
- Mutual exclusion: The resources involved must be unshareable
- Hold and wait: The processes must hold the resources they have already been allocated while waiting for other resources
- No pre-emption: No preference should be given to different requests. The processes must not have resources taken away while that resource is being used
- Circular wait or resource waiting: A circular chain of processes, with each process holding resources which are currently being requested by the next process in the chain

## Deadlock Prevention:
A deadlock can by eliminated by avoiding any one of the above four condition:
- Eliminate mutual exclusion
  - not possible because some resources (e.g. printer) are inherently non-sharable
- Eliminate hold and wait
  - Allocate all required resources to the process before start of its execution, this way hold and wait condition is eliminated but it will lead to low device utilization
    - E.g. If a process requires printer at a later time and we have allocated printer before the start of its execution; printer will remained blocked till it has completed its execution
  - Process will make new request for resources after releasing the current set of resources. This solution may lead to starvation
- Eliminate no pre-emption
  - Preempt resources from process when resources required by other high priority process
- Eliminate circular wait
  - Each resource will be assigned with a numerical number. A process can request for the resources only in increasing order of numbering

- Deadlock free Class: Class provides a lock only if there are no possible deadlocks.
  - create resources as nodes
  - take resources needed list from processes
  - create edges in the graph
  - DFS to check for a cycle
  - backtrack and remove edges

## Deadlock Avoidance:
### Banker’s Algorithm:
A resource allocation and deadlock avoidance algorithm that tests for safety by simulating the allocation for predetermined maximum possible amounts of all resources. 
If after granting request system remains in the safe state it allows the request and if their is no safe state it don’t allow the request made by the process.

- Inputs to Banker’s Algorithm
 1. Max need of resources by each process
 2. Currently allocated resources by each process
 3. Max free available resources in the system

- Request will only be granted under below condition
 1. If request made by process is less than equal to max need to that process.
 2. If request made by process is less than equal to freely availbale resource in the system

# Context Switch:
- The time spent switching between 2 processes
