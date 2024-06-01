#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "tasklistc.txt"
#define MAX_TASK_LENGTH 256

// task structure
typedef struct {
    int UID;
    char task[MAX_TASK_LENGTH];
} Task;

// Global variables for task list and task count
Task *task_list = NULL;
int task_count = 0;

// Function 
void create_empty_task_list();
void initialize();
void load_tasks();
void save_tasks();

//  check if the task file exists
void check_file() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        // If file does not exist, prompt the user to create a new task list or exit
        printf("No task list exists...\n");
        char inp[MAX_TASK_LENGTH];
        printf("Enter 'quit' to exit the program or any other letter to create an empty list: ");
        fgets(inp, sizeof(inp), stdin);
        inp[strcspn(inp, "\n")] = 0;   
        if (strcmp(inp, "quit") == 0) {
            exit(0);
        } else {
            create_empty_task_list();
        }
    } else {
        fclose(file);
        load_tasks(); // Load existing tasks if file exists
    }
}

// load task
void load_tasks() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Failed to open task list");
        return;
    }
    task_count = 0;
    char line[MAX_TASK_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        task_list = realloc(task_list, (task_count + 1) * sizeof(Task));
        sscanf(line, "{UID: %d, task: %[^\n]}", &task_list[task_count].UID, task_list[task_count].task);
        task_count++;
    }
    fclose(file);
}

// save task
void save_tasks() {
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Failed to save task list");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "{UID: %d, task: %s}\n", task_list[i].UID, task_list[i].task);
    }
    fclose(file);
}

//  list all 
void list_task() {
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s\n", i + 1, task_list[i].task);
    }
    initialize();
}

//  enter new task
void update_task_list() {
    task_list = realloc(task_list, (task_count + 1) * sizeof(Task));
    task_list[task_count].UID = (task_count > 0) ? task_list[task_count - 1].UID + 1 : 1;
    printf("Enter your task: ");
    fgets(task_list[task_count].task, sizeof(task_list[task_count].task), stdin);
    task_list[task_count].task[strcspn(task_list[task_count].task, "\n")] = 0; 
    task_count++;
    save_tasks();
    initialize();
}

// taking user input 
int take_input() {
    int task;
    printf("Enter Choice (enter '0' for options)>>> ");
    while (scanf("%d", &task) != 1) {
        while (getchar() != '\n');  
        printf("Enter Choice (enter '0' for options)>>> ");
    }
    while (getchar() != '\n'); 
    return task;
}

// take input to delete task
int take_del_input(int num) {
    int task;
    printf(">>> ");
    while (scanf("%d", &task) != 1 || task < 1 || task >= num) {
        while (getchar() != '\n');  
        printf(">>> ");
    }
    while (getchar() != '\n');
    return task;
}

//  delete task
void delete_task() {
    for (int i = 0; i < task_count; i++) {
        printf("%d. %s\n", i + 1, task_list[i].task);
    }
    printf("Enter which task you want to delete? ");
    int task_to_delete = take_del_input(task_count + 1);
    for (int i = task_to_delete - 1; i < task_count - 1; i++) {
        task_list[i] = task_list[i + 1];
    }
    task_list = realloc(task_list, (task_count - 1) * sizeof(Task));
    task_count--;
    save_tasks();
    printf("Deleted...\n");
    initialize();
}

// confirm clear task
int confirmation() {
    char inp[MAX_TASK_LENGTH];
    printf("Do you really want to clear task list (YES/NO) ");
    fgets(inp, sizeof(inp), stdin);
    inp[strcspn(inp, "\n")] = 0;   
    if (strcmp(inp, "yes") == 0) {
        return 1;
    } else if (strcmp(inp, "no") == 0) {
        return 0;
    } else {
        return confirmation();
    }
}

// create empty task list
void create_empty_task_list() {
    free(task_list);
    task_list = NULL;
    task_count = 0;
    save_tasks();
    initialize();
}

// clear task list
void clear_task_list() {
    if (confirmation() == 1) {
        create_empty_task_list();
    } else {
        initialize();
    }
}

// help
void task_list_help() {
    printf("1: List Your Tasks\n2: Update Task List\n3: Delete Task\n4: Clear task List\n5: Exit\n");
    initialize();
}

// initialize 
void initialize() {
    int task = take_input();
    if (task == 0) {
        task_list_help();
    } else if (task == 1) {
        list_task();
    } else if (task == 2) {
        update_task_list();
    } else if (task == 3) {
        delete_task();
    } else if (task == 4) {
        clear_task_list();
    } else {
        exit(0);
    }
}

// Main function
int main() {
    printf("Welcome to To-Do List:\n");
    check_file();
    task_list_help();
    initialize();
    return 0;
}
