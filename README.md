# **Simple Shell**

The simple shell takes in user input and translates that input into a command
That is executed and printed on to the user interface.

```
$ [User Input]
```

## *Shell.c*

This file calls all the functions in the program that are essential for the

execution of the shell. This main file gets input from the user and passes it

along to the tokenizing function.

## *token.c*

This file is called in the shell.c file accepts the user input as an argument.

This function then takes this user input and tokenizes it for easier use. It then

calls a function from the addnode.c to add a node to the linked list.

## *addnode.c*

This file contains multiple functions that work in conjunction with a linked list.

     addnode - Adds a node to the start of a list.

     add_node_end - This adds a node to the end of the list.

     free_list - This frees the linked list using a loop.

This function loops through the environmental variable and stores it into the linked list for use.

## *checkfunction.c*

This file contains multiple helper function that account for special uses.

    envfunction - This function loops through the environmental variabel and prints every char out.

    Checkfunction - This checks for certian builtin functions by using strcmp to compare user input.

    Cdex - This function allows for the change of directories.

    exitfunc - This exits the program when the user types in exit

    ctrl_c - This function blocks the control-c to exit the program

## *helper1.c*

This function contains helper functions that allow for simple tasks to be executed.
     _strcmp - This compares two strings and returns 0 if match is found.

     _strcpy - This copies a string into another place in memory.

     _strdup - This duplicates a string into another place in memory.

## *helper2.c*

This function contains helper functions that allow for simple tasks to be executed.
     _strlen - This functions loops through a string and gets a string length.

     _strcat - This concatenated a string to the end of another.

     _strncpy - This copes one string only up to n amount of bytes to a new place in memory.

     _strstr - This function finds the occurence of a substring within a larger string.

     _putchar - This prints a character to the STDOUT.

## *execute.c*

This file contins two functions that help execute the users input and get the corresponding response.

     execmd - This function takes in the linked list and extracts the the users input and tokenized path and executes it.

     append - This function appends the users input to one string for easier use in execmd.
## *dirsearch.c*

This file contians the files to check along the environmental variabel and path.

     dirsearch - This function searches along the enviromental variable and looks for PATH.

     tok_path - This function is passed the PATH and parses so that only the PATH remains.

     pathval - This function validates that a file exists and then finaly executes.
