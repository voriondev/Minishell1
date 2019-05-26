/*
** EPITECH PROJECT, 2019
** minishell1
** File description:
** minishell1
*/

#ifndef MINISHELL1_H_
#define MINISHELL1_H_

#define EOF_SIGNAL 42
#define EXIT_SIGNAL 21

typedef struct shell t_shell;

typedef struct builtins {
    char *builtins_cmd[6];
    int (*builtins_ptr[6])(t_shell *shell, char **args);
} t_builtins;

struct shell {
    char **path;
    char **env;
    t_builtins *builtins;
    int exit_status;
};

int my_shell(t_shell *shell, char **env);
int define_custom_env(t_shell *shell);
int parse_path_variable(t_shell *shell);
int copy_env(t_shell *shell, char **env);
int prompt_loop(t_shell *shell);
int get_input(t_shell *shell);
int intepret_command(t_shell *shell, char **splitted_cmd);
int run_binary_file(t_shell *shell, char **splitted_cmd);
char *get_env_value(t_shell *shell, char *var);
char *get_previous_path(char *path);
int folder_exists(char *folder_path);
int execute_cd(t_shell *shell, char **args);
int execute_env(t_shell *shell, char **args);
int execute_exit(t_shell *shell, char **args);
int execute_setenv(t_shell *shell, char **args);
int execute_unsetenv(t_shell *shell, char **args);
int change_env_value(t_shell *shell, char *var, char *value);
void check_signal(int status);

#endif
