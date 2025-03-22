/*5. Мини-интерпретатор команд
Описание:
Создайте программу, которая работает в режиме командной строки и выполняет команды:

alloc <size> — выделяет память
free — освобождает память
write <text> — записывает текст в выделенную область памяти
print — выводит текущие данные из памяти
exit — завершает программу
Используйте структуру с указателями на функцию для обработки команд.

🔹 Дополнительно: Реализовать защиту от некорректного использования (free без alloc, выход за границы памяти и т. д.).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024  

typedef struct {
    char *memory;     
    size_t size;      
} MemoryManager;

MemoryManager mem = {NULL, 0}; 

void alloc_memory(size_t size) {
    if (mem.memory != NULL) {
        printf("Ошибка: память уже выделена. Освободите её перед новым alloc.\n");
        return;
    }
    if (size == 0 || size > MAX_SIZE) {
        printf("Ошибка: недопустимый размер памяти.\n");
        return;
    }

    mem.memory = (char *)malloc(size);
    if (!mem.memory) {
        printf("Ошибка: не удалось выделить память.\n");
        return;
    }
    mem.size = size;
    memset(mem.memory, 0, size); 
    printf("Выделено %zu байт памяти.\n", size);
}

void free_memory() {
    if (!mem.memory) {
        printf("Ошибка: память не выделена.\n");
        return;
    }
    free(mem.memory);
    mem.memory = NULL;
    mem.size = 0;
    printf("Память освобождена.\n");
}

void write_memory(const char *text) {
    if (!mem.memory) {
        printf("Ошибка: память не выделена.\n");
        return;
    }
    size_t text_length = strlen(text);
    if (text_length >= mem.size) {
        printf("Ошибка: недостаточно памяти для записи текста.\n");
        return;
    }
    strncpy(mem.memory, text, mem.size - 1);
    mem.memory[mem.size - 1] = '\0'; 
    printf("Текст записан в память.\n");
}

void print_memory() {
    if (!mem.memory) {
        printf("Ошибка: память не выделена.\n");
        return;
    }
    printf("Содержимое памяти: \"%s\"\n", mem.memory);
}

typedef struct {
    char *command;
    void (*func)(char *arg);
} Command;

void alloc_handler(char *arg) {
    if (!arg) {
        printf("Ошибка: команда alloc требует аргумент (размер).\n");
        return;
    }
    size_t size = strtoul(arg, NULL, 10);
    alloc_memory(size);
}

void free_handler(char *arg) {
    (void)arg; 
    free_memory();
}

void write_handler(char *arg) {
    if (!arg) {
        printf("Ошибка: команда write требует аргумент (текст).\n");
        return;
    }
    write_memory(arg);
}

void print_handler(char *arg) {
    (void)arg; 
    print_memory();
}

void process_command(char *input) {
    Command commands[] = {
        {"alloc", alloc_handler},
        {"free", free_handler},
        {"write", write_handler},
        {"print", print_handler},
        {"exit", NULL}
    };
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    char *cmd = strtok(input, " ");
    char *arg = strtok(NULL, ""); 

    if (!cmd) return;

    for (int i = 0; i < num_commands; i++) {
        if (strcmp(cmd, commands[i].command) == 0) {
            if (commands[i].func) {
                commands[i].func(arg);
            } else {
                exit(0); 
            }
            return;
        }
    }
    printf("Ошибка: неизвестная команда \"%s\".\n", cmd);
}

int main() {
    char input[256];
    
    printf("Мини-интерпретатор команд\n");
    printf("Доступные команды: alloc <size>, free, write <text>, print, exit\n");

    while (1) {
        printf("> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break;
        }
        
        input[strcspn(input, "\n")] = '\0';

        process_command(input);
    }

    return 0;
}