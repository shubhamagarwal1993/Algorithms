# Linux
 - Linux is a kernel, not an entire operating system. A kernel provides access to computer hardware and a controlled access to system resources such as:
   - Security and firewall
   - GNU libraries and utilities
   - Other management and installation scripts
   - Logged in users
   - Running and loading programs to memory
   - Networking systems
   - Files and data
   - Process management
   - Device management
   - I/O management

# Shell
 - A shell is an environment provided for the user to interact with the machine
 - A shell is a macro processor or a command language interpreter that translates the commands, written by the user in the terminal, into system actions that are executed
 - A shell is a way to interface with the operating system and run commands
 - The terminal window in our computer contains a shell that allows you to process information, store or retrieve data and much more by interacting with a computer via entering commands

## Shell and Linux kernel
 - A shell is not part of the Linux kernel, but uses the kermel to execute programs, create files, etc
 - Several command line shells are available for Linux including:
   - BASH (Bourne-Again SHell) - It’s the default open source shell on many Linux distributions today
   - CSH  (C SHell)            - The C shell’s syntax and usage are very similar to the C programming language
   - KSH (Korn SHell), TCSH, ZSH, and Fish (Friendly Interactive Shell)

### Sample commands
 #### Retrieving a list of files or directories
   `df -h`
 #### Sorting files
   `ls -S`
 #### Find out available and free memory
     - Find out what processes are eating up your system resources

### Shell Scripting
 - files with `.sh` extension are called shell scripts. They can execute commands on a Shell terminal, allowing users to automate thier tasks
 - These customized commands have the same status as system commands in directories like `/bin`. Thus, users can create their own customized environments to carry out tasks

## Types of Shell (2 types):
 - The Bourne Shell
   - default prompt is the # character
 - The C Shell
   - default prompt is the % character

## Shell Classification
 - Command line shell
   - Shells can be accesed by users using a program called terminal in Linux/macOS and command prompt in windows
 - Graphical shell
   - provide a GUI to interact with the system, like Ubuntu OS



