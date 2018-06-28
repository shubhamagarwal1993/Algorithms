The shell keeps track of settings through an area it maintains called the environment
The environment is an area that the shell builds every time that it starts a session that contains variables that define system properties

How to interact with the environment
Read and Set environmental variables interactively and through configuration files
Read and Set shell variables interactively and through configuration files

## Variables:
 - These shell and environment variables are implemented as strings that represent key-value pairs
 - If multiple values are passed, they are typically separated by colon (:) characters. Each pair will generally will look something like this:
   `KEY=value1:value2:...`
 - If the value contains significant white-space, quotations are used:
   `KEY="value with spaces"`
 - These variable/keys are of 2 types:
   - Environment variables
     - Env variables are defined for the current shell and are inherited by any child shells or processes. Env variables are used to pass information into processes that are spawned from the shell
     - The value of an environmental variable can for example be the location of all executable files in the file system, or the default editor that should be used
   - Shell variables
     - Shell variables are contained exclusively within the shell in which they were set or defined
     - They are often used to keep track of ephemeral data, like the current working directory
     - Each shell session keeps track of its own shell and environmental variables
 - These types of variables are usually defined using all capital letters.

### Printing Environment and Shell variables:
 - The variables will differ based on user, so if you use `sudo su -`, the enviroment variables might be different
 - To list the current variables, use:
   - `printenv`
     - can request the values of individual variables like `printenv SHELL`
   - `env`
     - let's you modify the environment that programs run in by passing a set of variable definitions into a command like this `env VAR1="blahblah" command_to_run command_options`
     - The `env` utility can be used to run a command under a modified environment
     - `env EDITOR=vim xterm` will launch xterm with the environment variable EDITOR set to vim
       - This will not affect the global environment variable EDITOR

### Print Shell variables:
 - To list the current shell variables, use `set` without any additional parameters, we will get a list of all shell variables, environmental variables, local variables, and shell functions
 - To print a list of all environment and shell variables that are defined, use:
   `(set -o posix; set)`

### Creating Shell variables:
 - define a shell variable within our current session using `TEST_VAR='Hello World!'`
 - We now have a shell variable. This variable is available in our current session, but will not be passed down to child processes
 - We can see this by grepping for our new variable within the set output:
   - `set | grep TEST_VAR`
 - We can verify that this is not an environmental variable by trying the same thing with printenv using `printenv | grep TEST_VAR`
 - Accessing the value of any shell or environmental variable using `echo $TEST_VAR`

### Setting Environment variables:
