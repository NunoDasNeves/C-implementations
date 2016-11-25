#include <stdlib.h>
#include <stdio.h>
#include "List.h"

#define LINE_BUFF_SIZE 1024
#define checkPtr(p) if(p==NULL){fprintf (stderr,"nsh allocation error\n");exit(1);}

void nsh_loop();
char * nsh_read_line();
char ** nsh_split_line(char *);
int nsh_execute(char **);
// globals here

int main(int argc, char **argv)
{
    // config file
    nsh_loop();
    // cleanup
    return EXIT_SUCCESS;
}

void nsh_loop()
{
    // the whole line
    char *line;
    // array of args
    char **args;
    // status 
    int status;
    char * p;
    do {
        printf("> ");
        line = nsh_read_line();
        args = nsh_split_line(line);
        status = nsh_execute(args);
        free(line);
        for (p=args;p!=NULL;p++) free(p);
        free(args);
    } while (status);
}

char * nsh_read_line()
{
    long bufsize = LINE_BUFF_SIZE;
    char * line = malloc(sizeof(char)*LINE_BUFF_SIZE);
    char curr;
    int p = 0;
    while (1) {
        checkPtr(line);
        curr = getchar();
        if (curr == EOF || curr == '\n') {
            line[p] = '\0';
            break;
        } else line[p++] = curr;
        if (p >= bufsize-1) {
            bufsize += LINE_BUFF_SIZE;
            realloc (line, bufsize);
        }
    }
    return line;
}

char ** nsh_split_line(char * line)
{
    stack = ListNew();

    ListDestroy(stack);
    char ** args;
    return args;
}
int nsh_execute(char ** args)
{
    
    return status;
}
