/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** cd
*/

#include "minishell1.h"
#include "my.h"
#include <unistd.h>
#include <dirent.h>

int folder_exists(char *folder_path)
{
    DIR *my_dir;
    int exists = 1;

    if (access(folder_path, F_OK) == -1)
        exists = 0;
    my_dir = opendir(folder_path);
    if (my_dir == NULL)
        return (exists == 1 ? 1 : -1);
    closedir(my_dir);
    return (0);
}

int home_folder(t_shell *shell, char *home_dir, char *current_dir)
{
    if (home_dir != NULL) {
        chdir(home_dir);
        change_env_value(shell, "PWD", home_dir);
        change_env_value(shell, "OLDPWD", current_dir);
    }
    return (0);
}

int prev_folder(t_shell *shell, char *old_dir, char *current_dir)
{
    if (old_dir == NULL) {
        my_printerr("Error: no OLDPWD variable in env.\n");
        return (-1);
    }
    chdir(old_dir);
    change_env_value(shell, "PWD", old_dir);
    change_env_value(shell, "OLDPWD", current_dir);
    return (0);
}

int ch_folder(t_shell *shell, char *current_dir, char *dir)
{
    char *correct_path = dir[0] == '/' ? dir :
    my_strcat(my_strcat(current_dir, "/"), dir);

    if (folder_exists(correct_path) == -1)
        my_printf("%s: No such file or directory.\n", dir);
    if (folder_exists(correct_path) == 1)
        my_printf("%s: Not a directory.\n", dir);
    else {
        chdir(correct_path);
        change_env_value(shell, "PWD", correct_path);
        change_env_value(shell, "OLDPWD", current_dir);
        return (0);
    }
    return (-1);
}

int execute_cd(t_shell *shell, char **args)
{
    char *current_dir = get_env_value(shell, "PWD");
    char *old_dir = get_env_value(shell, "OLDPWD");
    char *home_dir = get_env_value(shell, "HOME");

    if (current_dir == NULL) {
        my_printerr("Error: no PWD variable in env.\n");
        return (-1);
    }
    if (args[1] != NULL) {
        if (args[1][0] == '-')
            prev_folder(shell, old_dir, current_dir);
        else
            ch_folder(shell, current_dir, args[1]);
    }
    else
        home_folder(shell, home_dir, current_dir);
    return (0);
}
