#include  "main.h"

define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
char *prompt = "lynne$ ";
char *lineptr = NULL;
char *user_input;
size_t n = 0;
char *word;
char *delim = " \n";
int i = 0;
char *cmd_args[];

pid_t pid;

(void)argc, (void) argv;
while (1) {
printf("%s", prompt);

if (getline(&lineptr, &n, stdin) == -1) {
perror("getline");
return (-1);
}

user_input = strdup(lineptr);
word = strtok(user_input, delim);
i = 0;
while (word != NULL) {
cmd_args[i++] = word;
word = strtok(NULL, delim);
}
cmd_args[i] = NULL;

/*char **cmd_args = malloc((i + 1) * sizeof(char *));*/
/*if (cmd_args == NULL) {
perror("malloc failed");
return (-1);
}

word = strtok(lineptr, delim);
i = 0;
while (word != NULL) {
cmd_args[i] = word;
word = strtok(NULL, delim);
i++;
}
cmd_args[i] = NULL;

if (strcmp(cmd_args[0], "cd") == 0) {
if (i > 1) {
if (chdir(cmd_args[1]) != 0) {
perror("cd failed");
}
} else {
chdir(getenv("HOME"));
}*/
} else {
pid = fork();
if (pid < 0) {
perror("fork failed");
return (1);
}
if (pid == 0) {
if (execvp(cmd_args[0], cmd_args) == -1) {
perror("Error");
return (-1);
}
} else {
wait(NULL);
}
}

free(cmd_args);
}
free(lineptr);

return 0;
}
