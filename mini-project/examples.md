# Document Processing

In a Linux OS "filters" are command line tools that reads standard input, performs an operation upon it and writes the results to standard output.

For this reason, it can be used to process information in powerful ways such as restructuring output to generate useful reports, modifying text in files and many other system administration tasks.

With that said, below are some of the useful file or text filters in Linux that can be implemented using FS concepts.

- **awk**
	- awk is a remarkable pattern scanning and processing language, it can be used to build useful filters in Linux.

- **sed**
	- sed is a powerful stream editor for filtering and transforming text.

- **grep**
	- This filter output lines matching a given pattern. It reads lines from a file or standard input, and prints all matching lines by default to standard output.

- **head**

	- head is used to display the first parts of a file, it outputs the first 10 lines by default. You can use the -n num flag to specify the number of lines to be displayed.

- **tail**

	- tail outputs the last parts (10 lines by default) of a file. Use the -n num switch to specify the number of lines to be displayed.

- **sort**
	- sort is used to sort lines of a text file or from standard input.

- **uniq**

	- uniq command is used to report or omit repeated lines, it filters lines from standard input and writes the outcome to standard output.

- **fmt**

	- fmt simple optimal text formatter, it reformats paragraphs in specified file and prints results to the standard output.

- **pr**

	- pr command converts text files or standard input for printing.

- **tr**

	- This tool translates or deletes characters from standard input and writes results to standard output.

- **more**

	- more command is a useful file perusal filter created basically for certificate viewing. It shows file content in a page like format, where users can press [Enter] to view more information.

- **less**

	- less is the opposite of more command above but it offers extra features and it’s a little faster with large files.

**transaction management, indexing and hashing, buffer management, configuration management** - *ToDo*