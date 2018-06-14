### awk (
 - pattern scanning language

### sed (UNIX stream editor)
 - powerful regular expressions

### Perl
 - started as a glue language to stick together by converting the different formats from different tools
 - high-level language, easy to learn and write, very portable across computers, good support for regular expressions
 - currently using version 5 (5.6 and above); perl is completely free. Download it under the Artistic License, found at opensource.org/licenses
 - Perl programs use the expression `.pm`. Some older programs might use `.pl`, `.plx`, or nothing at all
 - check the version of perl installed on your computer with `perl -v`

#### Main uses of Perl
 - CGI programming: dynamically generated web pages
 - extracting data from one source and translating it to another format
   - processing and summarizing system logs, report info on disk usage, produce reports on resource use, and watch for security problems
   - manipulating databases
   - reformatting text files
   - simple search and replace operations
   - alien: a program to port Linux software packages between different distributors' packaging formats
   - manages the data from the Human Genome Project, a task requiring massive amounts of data manipulation
   - sending automatically generated emails
   - automating administrative tasks
   - filter mail, mirror web sites, automate downloading and uploading

#### Simple inline perl
 - running `perl -e "print qq(hi\n)"` will print hi followed by a new line in the terminal. qq stands for `quick quotes` and can be used inplace of double quotes; thus, its more like an operator
 - check helloWorld.pl to see a basic perl script. Run it using `perl helloWorld.pl`


