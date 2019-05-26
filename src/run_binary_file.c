/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** run_binary_file
*/

#include "minishell1.h"
#include "my.h"
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <dirent.h>
#include <stddef.h>

bool contains_slash(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            return (true);
    return (false);
}

int check_for_binary(DIR *my_dir, char *filename)
{
    struct dirent *directory;

    if (my_dir == NULL)
        return (-1);
    directory = readdir(my_dir);
    while (directory != NULL) {
        if (my_strcmp(directory->d_name, filename) == 0)
            return (1);
        directory = readdir(my_dir);
    }
    return (0);
}

char *get_matching_path(t_shell *shell, char *filename)
{
    char *path = NULL;
    DIR *my_dir;

    if (shell->path == NULL)
        return (NULL);
    for (int i = 0; shell->path[i] != NULL; i++) {
        my_dir = opendir(shell->path[i]);
        if (my_dir != NULL && check_for_binary(my_dir, filename) == 1) {
            path = shell->path[i][my_strlen(shell->path[i])] == '/' ?
        shell->path[i] : my_strcat(shell->path[i], "/");
            path = my_strcat(path, filename);
            break;
        }
        closedir(my_dir);
    }
    return (path);
}

int start_child_process(t_shell *shell, char *binary_path, char **splitted_cmd)
{
    int pid;
    int status = 0;

    pid = fork();
    if (pid == 0) {
        if (execve(binary_path, splitted_cmd, shell->env) == -1) {
            my_printf("%s: Exec format error. ", binary_path);
            my_printf("Wrong Architecture.\n");
        }
    } else {
        waitpid(0, &status, WUNTRACED);
        check_signal(status);
    }
    return (0);
}

int run_binary_file(t_shell *shell, char **splitted_cmd)
{
    char *binary_path = NULL;

    if (contains_slash(splitted_cmd[0]))
        binary_path = access(splitted_cmd[0], F_OK)
        == -1 ? NULL : splitted_cmd[0];
    else
        binary_path = get_matching_path(shell, splitted_cmd[0]);
    if (binary_path == NULL) {
        my_printf("%s: Command not found.\n", splitted_cmd[0]);
        return (-1);
    }
    if (folder_exists(binary_path) == 0 || access(binary_path, X_OK) == -1) {
        my_printf("%s: Permission denied.\n", binary_path);
        return (0);
    }
    start_child_process(shell, binary_path, splitted_cmd);
    return (0);
}
