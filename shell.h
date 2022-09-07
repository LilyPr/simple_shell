#ifndef SHELL_H
#define SHELL_H

struct builtin {
    char *name;
    void (*func)(char **args);
};

struct builtin builtins[] = {
    {"help", shell_help},
    {"exit", shell_exit},
    {"cd", shell_cd},
};

int shell_builtins() {
    return sizeof(builtins) / sizeof(struct builtin);
}


#endif
