#### Process vs threads
 - process is made up of threads. the one thread that runs in beginning is called the main/primary thread
 - Process consists of:
   - virtual address space
   - executable code
   - open handles to system objects
   - a security context
   - a unique process identifier
   - environment variables
   - a priority class
   - minimum and maximum working set sizes
   - at least one thread of execution
   - processes run in separate memory spaces

 - Threads of the same process:
   - share memory
   - share virtual address space
   - share system resources
   - each threads has its own stack but share heap
   - each thread has its own registers
   - If a thread allocates some object on its stack, and sends the address to another thread, they'll both have equal access to that object

#### Lock
   - allows only 1 thread to enter the part that's locked and the lock is not shared with any other processes

#### Mutex vs Semaphore: (Mutex and Semaphore are kernel resources that provide synchronization services)
 - Mutex:
   - A locking mechanism
   - A mutex is the same as a lock but it can be system wide (shared by multiple processes)
   - used to synchronize access to a resource
   - only one task can acquire the mutex
   - pthread mutexes are used for mutual exclusion between threads of the same process
   - System V IPC (man svipc) semaphores can be used across processes
   - Filesystem-level locks (on files or parts of files) can also used to coordinate between multiple processes
 - Semaphore:
   - A signaling mechanism
   - A semaphore does the same as a mutex but allows x number of threads to enter, this can be used for example to limit the number of cpu, io or ram intensive tasks running at the same time

#### Read / Write lock
 - allows either unlimited number of readers or 1 writer at any given time

## Deadlocks and Livelocks

#### Essential conditions for deadlock
 - mutual exclusion
   - The resources involved must be unshareable
 - hold and wait
   - The processes must hold the resources they have already been allocated while waiting for other resources
 - no pre-emption
   - No preference should be given to different requests. The processes must not have resources taken away while that resource is being used
 - Circular wait or resource waiting
   - A circular chain of processes, with each process holding resources which are currently being requested by the next process in the chain

#### Deadlock Prevention
 - We can prevent Deadlock by eliminating any of the above four condition
   - eliminate mutual exclusion
     - not possible because some resources (e.g. printer) are inherently non-sharable
   - eliminate hold and wait
     - Allocate all required resources to the process before start of its execution, this way hold and wait condition is eliminated but it will lead to low device utilization
       - E.g. If a process requires printer at a later time and we have allocated printer before the start of its execution; printer will remained blocked till it has completed its execution
     - Process will make new request for resources after releasing the current set of resources. This solution may lead to starvation
   - eliminate no pre-emption
     - Preempt resources from process when resources required by other high priority process
   - eliminate circular wait
     - Each resource will be assigned with a numerical number. A process can request for the resources only in increasing order of numbering

#### Deadlock avoidance
 - Banker’s Algorithm is a resource allocation and deadlock avoidance algorithm which test all the request made by processes for resources, it check for safe state, if after granting request system remains in the safe state it allows the request and if their is no safe state it don’t allow the request made by the process.

 - Inputs to Banker’s Algorithm
   1. Max need of resources by each process
   2. Currently allocated resources by each process
   3. Max free available resources in the system

 - Request will only be granted under below condition
   1. If request made by process is less than equal to max need to that process.
   2. If request made by process is less than equal to freely availbale resource in the system


