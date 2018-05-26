### Hypervisor:
 - A program that enables you to host serveral different virtual machines on a single hardware
 - Each of these virtual machines or operating systems will be able to run its own programs
 - It will appear that the system has the host hardware's processor, memory, and resources
 - It is actually the hypervisor that is allocating those resources to the virtual machines
 - The hypervisor is like the OS for virtualized systems. It can access the memory, disk, and all aspects and parts of a virtual meachine
 - A virtual machine can create requests to the hypervisor through a variety of methods, including API calls

### 2 types of hypervisors:
 - Bare Metal, type I,  or native hypervisors:
   - hypervisors are run on the host's hardware to control it as well as manage the virtual machines on it
   - E.g. microsoft hyper-V hypervisor, VMware ESX/ESXi, Oracle VM server for x86
   - Pros:
     - Faster and more efficient as they do not need to go though the OS and other layers
     - more secure
   - Cons:
     - Difficult to set up
     - limited to certain hardware


 - Embedded, type II,  or hosted hypervisors:
   - These hypervisors are run as a software using an operating system such as windows, linux, or FreeBDS
   - E.g. Virtage hypervisor, VirtualBox, and VMWare workstation
   - Pros:
     - easy to set up
     - compatible with a broad range of hardware
   - Cons:
     - Slower and less efficient as they need to go through the OS and other layers that usually make hosted hypervisors slower
     - less secure

### Use and application of hypervisors:
 - data services for easy cloning, and replication
   - cost effective and less complex than current replication methods
   - hypervisor-based replication is hardware neutral, meaning you could store any data duplicates to any storage device

