#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//write a function that uses strep to parse a line of arguments

//should take a string w the command line invocation of a program ("ls -a -l")
//note the space between each argument
//return an array of pointers to each individual arg in the parameter string that could be used for execvp()
//ex: char ** args = parse_args(line); execvp(args[0], args); 
//to test: should use it on a string & then call execvp successfully
//assumptions: only one space between each arg, original string contains no more than 5 arguments, original string is correctly formatted
char ** parse_args(char * line) {
	char ** args = malloc(5 * sizeof(char *));
	
	int index = 0;
	while(line) {
		char * arg = strsep(&line, " ");
		args[index] = arg;
		index++;
	}
	return args;
}

int main() {
	printf("Enter Command: \n");
	
	char command[1000];
	fgets(command, 1000, stdin);
	*strchr(command, '\n') = 0;
	
	char ** args = parse_args(command);
	execvp(args[0], args);
}

