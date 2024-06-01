#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// contsants
#define MAX_TASK_LENGTH 256
#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50
#define TASKS_FILE "tasks_multiusersc.txt"
#define USERS_FILE "usersc.txt"

// Global variable to hold the current logged-in user ID
int UID = 0;

// Structure for Task, including user ID (UID), task ID (TASKID), and task description
typedef struct {
    int UID;
    int TASKID;
    char task[MAX_TASK_LENGTH];
} Task;

// Structure for User, including user ID (UID), username, and password
typedef struct {
    int UID;
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;



// functions
void create_empty_file(const char *filename);
void load_tasks(Task **tasks, int *task_count);
void save_tasks(Task *tasks, int task_count);
void load_users(User **users, int *user_count);
void save_users(User *users, int user_count);
void loggedin_home_help(int userid);
void list_task(int userid);
void update_task_list(int userid);
void delete_task(int userid);
void clear_task_list(int userid, void (*redirect)(int));
void delete_account(int userid, int step);
void update_users_list(int userid);
void home_prompt(int userid);
void pre_tasks();
void welcome_prompt();
int take_input(int n1, int n2);
int check(const char *username, const char *password);
void login_prompt();
void login();
int check_username(const char *username);
void create_new_user();

// first step of deletion
void delete_account_step1(int userid) {
    delete_account(userid, 1);
}

// create empty file if not exits
void create_empty_file(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file) {
        fclose(file);
    }
}

// check if file exits and make new if not
void pre_tasks() {
    FILE *file;
    if ((file = fopen(USERS_FILE, "r")) == NULL) {
        create_empty_file(USERS_FILE);
    } else {
        fclose(file);
    }
    if ((file = fopen(TASKS_FILE, "r")) == NULL) {
        create_empty_file(TASKS_FILE);
    } else {
        fclose(file);
    }
}

// get tasks
void load_tasks(Task **tasks, int *task_count) {
    FILE *file = fopen(TASKS_FILE, "r");
    if (!file) {
        perror("Failed to open tasks file");
        return;
    }
    *task_count = 0;
    char line[MAX_TASK_LENGTH + 50];
    while (fgets(line, sizeof(line), file)) {
        Task temp;
        sscanf(line, "{UID: %d, TASKID: %d, task: %[^\n]}", &temp.UID, &temp.TASKID, temp.task);
        char *end_brace = strchr(temp.task, '}');
        if (end_brace) {
            *end_brace = '\0';
        }
        *tasks = realloc(*tasks, (*task_count + 1) * sizeof(Task));
        (*tasks)[*task_count] = temp;
        (*task_count)++;
    }
    fclose(file);
}

// add new task
void save_tasks(Task *tasks, int task_count) {
    FILE *file = fopen(TASKS_FILE, "w");
    if (!file) {
        perror("Failed to save tasks file");
        return;
    }
    for (int i = 0; i < task_count; i++) {
        fprintf(file, "{UID: %d, TASKID: %d, task: %s}\n", tasks[i].UID, tasks[i].TASKID, tasks[i].task);
    }
    fclose(file);
}

// get users
void load_users(User **users, int *user_count) {
    FILE *file = fopen(USERS_FILE, "r");
    if (!file) {
        perror("Failed to open users file");
        return;
    }
    *user_count = 0;
    char line[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 50];
    while (fgets(line, sizeof(line), file)) {
        User temp;
        sscanf(line, "{UID: %d, username: %[^,], password: %[^\n]}", &temp.UID, temp.username, temp.password);
        char *end_brace = strchr(temp.password, '}');
        if (end_brace) {
            *end_brace = '\0';
        }
        *users = realloc(*users, (*user_count + 1) * sizeof(User));
        (*users)[*user_count] = temp;
        (*user_count)++;
    }
    fclose(file);
}

// save user
void save_users(User *users, int user_count) {
    FILE *file = fopen(USERS_FILE, "w");
    if (!file) {
        perror("Failed to save users file");
        return;
    }
    for (int i = 0; i < user_count; i++) {
        fprintf(file, "{UID: %d, username: %s, password: %s}\n", users[i].UID, users[i].username, users[i].password);
    }
    fclose(file);
}

// logged in home menu
void loggedin_home_help(int userid) {
    if (userid == UID) {
        printf("\n1: List Your Tasks.\n2: Update Task List.\n3: Delete Task.\n4: Clear task List.\n5: Delete My Account.\n6: Logout.\n");
        home_prompt(userid);
    } else {
        welcome_prompt();
    }
}

// display tasklist 
void list_task(int userid) {
    if (userid == UID) {
        Task *tasks = NULL;
        int task_count = 0;
        load_tasks(&tasks, &task_count);
        int num = 1;
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].UID == userid) {
                printf("%d. %s\n", num, tasks[i].task);
                num++;
            }
        }
        free(tasks);
        home_prompt(userid);
    } else {
        welcome_prompt();
    }
}

// update task list
void update_task_list(int userid) {
    if (userid == UID) {
        Task *tasks = NULL;
        int task_count = 0;
        load_tasks(&tasks, &task_count);
        int last_TASKID = (task_count > 0) ? tasks[task_count - 1].TASKID : 0;
        tasks = realloc(tasks, (task_count + 1) * sizeof(Task));
        tasks[task_count].UID = userid;
        tasks[task_count].TASKID = last_TASKID + 1;
        printf("Enter your task: ");
        fgets(tasks[task_count].task, sizeof(tasks[task_count].task), stdin);
        tasks[task_count].task[strcspn(tasks[task_count].task, "\n")] = '\0'; 
        task_count++;
        save_tasks(tasks, task_count);
        free(tasks);
        home_prompt(userid);
    } else {
        welcome_prompt();
    }
}

// delete a task
void delete_task(int userid) {
    if (userid == UID) {
        Task *tasks = NULL;
        int task_count = 0;
        load_tasks(&tasks, &task_count);
        int num = 1;
        int task_ids[task_count];
        for (int i = 0; i < task_count; i++) {
            if (tasks[i].UID == userid) {
                printf("%d. %s\n", num, tasks[i].task);
                task_ids[num - 1] = i;
                num++;
            }
        }
        printf("Enter which task you want to delete? ");
        int task_to_delete = take_input(1, num - 1) - 1;
        for (int i = task_ids[task_to_delete]; i < task_count - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        task_count--;
        tasks = realloc(tasks, task_count * sizeof(Task));
        save_tasks(tasks, task_count);
        free(tasks);
        printf("Deleted...\n");
        home_prompt(userid);
    } else {
        welcome_prompt();
    }
}

// clear all task for a user
void clear_task_list(int userid, void (*redirect)(int)) {
    if (userid == UID) {
        printf("1: Are you sure you want to delete.\n2: Go back.\n");
        int inp = take_input(1, 2);
        if (inp == 2) {
            home_prompt(userid);
        } else {
            Task *tasks = NULL;
            int task_count = 0;
            load_tasks(&tasks, &task_count);
            FILE *file = fopen(TASKS_FILE, "w");
            if (!file) {
                perror("Failed to clear tasks file");
                return;
            }
            for (int i = 0; i < task_count; i++) {
                if (tasks[i].UID != userid) {
                    fprintf(file, "{UID: %d, TASKID: %d, task: %s}\n", tasks[i].UID, tasks[i].TASKID, tasks[i].task);
                }
            }
            fclose(file);
            free(tasks);
            redirect(userid);
        }
    } else {
        welcome_prompt();
    }
}

// delete user account
void delete_account(int userid, int step) {
    if (userid == UID) {
        if (step == 0) {
            clear_task_list(userid, delete_account_step1);
        } else if (step == 1) {
            update_users_list(userid);
        } else if (step == 2) {
            printf("Account Deleted...\n");
            welcome_prompt();
        }
    } else {
        welcome_prompt();
    }
}

// update users after deletion
void update_users_list(int userid) {
    if (userid == UID) {
        User *users = NULL;
        int user_count = 0;
        load_users(&users, &user_count);
        FILE *file = fopen(USERS_FILE, "w");
        if (!file) {
            perror("Failed to update users file");
            return;
        }
        for (int i = 0; i < user_count; i++) {
            if (users[i].UID != userid) {
                fprintf(file, "{UID: %d, username: %s, password: %s}\n", users[i].UID, users[i].username, users[i].password);
            }
        }
        fclose(file);
        free(users);
        delete_account(userid, 2);
    } else {
        welcome_prompt();
    }
}

// home for logged in user
void home_prompt(int userid) {
    if (userid == UID) {
        printf("Enter 0 for help.\n");
        int inp = take_input(0, 6);
        if (inp == 0) {
            loggedin_home_help(userid);
        } else if (inp == 1) {
            list_task(userid);
        } else if (inp == 2) {
            update_task_list(userid);
        } else if (inp == 3) {
            delete_task(userid);
        } else if (inp == 4) {
            clear_task_list(userid, home_prompt);
        } else if (inp == 5) {
            delete_account(userid, 0);
        } else {
            UID = 0;
            welcome_prompt();
        }
    } else {
        welcome_prompt();
    }
}

// wlecome screen for new user
void welcome_prompt() {
    printf("1. Log-in into existing user:\n2. Create new user:\n3. Quit\n");
    int inp = take_input(1, 3);
    if (inp == 1) {
        login();
    } else if (inp == 2) {
        create_new_user();
    } else if (inp == 3) {
        exit(0);
    }
}

// take input for different functions
int take_input(int n1, int n2) {
    int inp;
    printf(">>>");
    while (scanf("%d", &inp) != 1 || inp < n1 || inp > n2) {
        while (getchar() != '\n');  
        printf("Invalid Value Entered:\n>>>");
    }
    while (getchar() != '\n'); 
    return inp;
}

// logging in mechanism
int check(const char *username, const char *password) {
    User *users = NULL;
    int user_count = 0;
    load_users(&users, &user_count);
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            int uid = users[i].UID;
            free(users);
            return uid;
        }
    }
    free(users);
    return 0;
}

// login prompt
void login_prompt() {
    printf("1. Go to login page:\n2. Go back:\n");
    int inp = take_input(1, 2);
    if (inp == 1) {
        login();
    } else if (inp == 2) {
        welcome_prompt();
    }
}

// logiin function
void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;  
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0; 

    if ((UID = check(username, password))) {
        printf("Login Successful\n");
        loggedin_home_help(UID);
    } else {
        printf("Your 'Username' or 'password' is incorrect.\n");
        welcome_prompt();
    }
}

// check if username exits
int check_username(const char *username) {
    User *users = NULL;
    int user_count = 0;
    load_users(&users, &user_count);
    for (int i = 0; i < user_count; i++) {
        if (strcmp(users[i].username, username) == 0) {
            free(users);
            return 1;
        }
    }
    free(users);
    return 0;
}

// create new user
void create_new_user() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;
    while (check_username(username)) {
        printf("Username Already Exists\nEnter your username: ");
        fgets(username, sizeof(username), stdin);
        username[strcspn(username, "\n")] = 0;
    }
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    User *users = NULL;
    int user_count = 0;
    load_users(&users, &user_count);
    users = realloc(users, (user_count + 1) * sizeof(User));
    users[user_count].UID = (user_count > 0) ? users[user_count - 1].UID + 1 : 1;
    strcpy(users[user_count].username, username);
    strcpy(users[user_count].password, password);
    user_count++;
    save_users(users, user_count);
    free(users);
    welcome_prompt();
}

// initialization
int main() {
    pre_tasks();
    printf("Welcome to Task List\n");
    welcome_prompt();
    return 0;
}
