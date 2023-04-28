#include "main.h"

struct builtin builtins[] = 
{
    {"help", shell_help},
    {"exit", shell_exit},
    {"cd", shell_cd},
};
