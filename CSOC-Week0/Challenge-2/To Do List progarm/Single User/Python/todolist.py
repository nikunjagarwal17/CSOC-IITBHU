import ast
import os

# check if file exists
def check_file():
    if not os.path.exists('tasklist.txt'):
        print("No task list exists...")
        inp = input("Enter 'quit' to exit the program or any other letter to create a empty list: ")
        if inp == 'quit':
            exit()
        else:
            create_empty_task_list() #create emply file if not exits
    return 1

#list all the task
def list_task():
    with open("tasklist.txt", "r") as task_file:
        data = task_file.read().splitlines()
        num = 1
        for i in data:
            print("{}. {}".format(num, ast.literal_eval(i)["task"]))
            num = num + 1
    initialize()

#adding task
def update_task_list():
    with open("tasklist.txt", "r") as task_file:
        data = task_file.read().splitlines()
    with open("tasklist.txt", "a") as task_file:
        try:
            last_UID = int(ast.literal_eval(data[-1])["UID"])
        except IndexError:
            last_UID = 0
        data_block = {"UID": str(last_UID + 1), "task": input("Enter your task:")}
        task_file.write(str(data_block))
        task_file.write("\n")
    initialize()

# takeing user input in menu
def take_input():
    try:
        task = int(input("Enter Choice (enter '0' for options)>>>"))
    except ValueError:
        take_input()
        return
    while task not in range(0, 6):
        task = int(input("Enter Choice (enter '0' for options)"))
    return task

# take input to delete the task
def take_del_input(num):
    try:
        task = int(input(">>>"))
    except ValueError:
        take_del_input(num)
        return
    while task not in range(1, num):
        task = int(input(">>>"))
    return task

# deleting task
def delete_task():
    with open("tasklist.txt", "r+") as task_file:
        data = task_file.read().splitlines()
        num = 1
        for i in data:
            print("{}. {}".format(num, ast.literal_eval(i)["task"]))
            num = num + 1
        print("Enter which task you want to delete?")
        task = take_del_input(num)
        data.pop(task - 1)
    with open("tasklist.txt", "w") as task_file:
        for i in data:
            task_file.write(i)
            task_file.write("\n")
    print("Deleted...")
    initialize()

# confirmation to clr task list
def confirmation():
    try:
        inp = input("Do you really want to clr task list (YES/NO)").lower()
        if inp == 'yes':
            return 1
        elif inp == 'no':
            return 0
        else:
            confirmation()
    except Exception:
        confirmation()

# create empty task file
def create_empty_task_list():
    with open("tasklist.txt", "w") as task_file:
        pass
    initialize()

# clear task file
def clear_task_list():
    confirm = confirmation()
    if confirm == 1:
        create_empty_task_list()
    else:
        initialize()

# help option
def task_list_help():
    print("1: List Your Tasks\n2: Update Task List\n3: Delete Task\n4: Clear task List\n5:Exit\n")
    initialize()

# intitializing the list
def initialize():
    task = take_input()
    if task == 0:
        task_list_help()
    elif task == 1:
        list_task()
    elif task == 2:
        update_task_list()
    elif task == 3:
        delete_task()
    elif task == 4:
        clear_task_list()
    else:
        exit(0)

# program start
if __name__ == '__main__':
    print("Welcome to To-Do List:")
    if check_file():
        task_list_help()
        initialize()