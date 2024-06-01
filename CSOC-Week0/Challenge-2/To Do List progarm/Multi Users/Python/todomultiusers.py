import os
import ast
#user id
UID = 0

#elp for logged in userh
def loggedin_home_help(userid):
    global UID
    if userid == UID:
        print(
            "\n1: List Your Tasks.\n2: Update Task List.\n3: Delete Task.\n4: Clear task List.\n5: Delete My Account.\n6: Logout.\n")
        home_prompt(userid)
    else:
        welcome_prompt()

#list all the tasks
def list_task(userid):
    global UID
    if userid == UID:
        with open("tasksmultiusers.txt", "r") as task_file:
            data = task_file.read().splitlines()
            num = 1
            for i in data:
                if ast.literal_eval(i)["UID"] == userid:
                    print("{}. {}".format(num, ast.literal_eval(i)["task"]))
                    num = num + 1
        home_prompt(userid)
    else:
        welcome_prompt()

#adding task to list
def update_task_list(userid):
    global UID
    if userid == UID:
        with open("tasksmultiusers.txt", "r") as task_file:
            data = task_file.read().splitlines()
        with open("tasksmultiusers.txt", "a") as task_file:
            try:
                last_TASKID = int(ast.literal_eval(data[-1])["TASKID"])
            except IndexError:
                last_TASKID = 0
            data_block = {"UID": str(userid), "TASKID": str(last_TASKID + 1), "task": input("Enter your task:")}
            task_file.write(str(data_block))
            task_file.write("\n")
            task_file.flush()  # Ensure data is written to the file immediately
            os.fsync(task_file.fileno())  # Ensure the file descriptor is synced with the storage
        home_prompt(userid)
    else:
        welcome_prompt()


#deleting a task
def delete_task(userid):
    global UID
    if userid == UID:
        with open("tasksmultiusers.txt", "r") as task_file:
            data = task_file.read().splitlines()
            num = 1
            data_ids = []
            for i in data:
                if ast.literal_eval(i)["UID"] == userid:
                    print("{}. {}".format(num, ast.literal_eval(i)["task"]))
                    data_ids.append(ast.literal_eval(i)["TASKID"])
                    num = num + 1
            print("Enter which task you want to delete?")#take which task to delete
            task = take_input(1, num - 1)
        with open("tasksmultiusers.txt", "w") as task_file:
            for i in data:
                if ast.literal_eval(i)["TASKID"] != data_ids[task - 1]:
                    task_file.write(i)
                    task_file.write("\n")
        print("Deleted...")
        home_prompt(userid)
    else:
        welcome_prompt()

# clear task list
def clear_task_list(userid, redirect):
    global UID
    if userid == UID:
        #confirmation
        print("1: Are you sure you want to delete.\n2: Go back.")
        inp = take_input(1, 2)
        if inp == 2:
            home_prompt(userid)
        else:
            with open("tasksmultiusers.txt", "r") as task_file:
                data = task_file.read().splitlines()
            with open("tasksmultiusers.txt", "w") as task_file:
                for i in data:
                    if ast.literal_eval(i)["UID"] != userid:
                        task_file.write(i)
                        task_file.write("\n")
            redirect()
    else:
        welcome_prompt()

#deleting my account
def delete_account(userid, step=0):
    global UID
    if userid == UID:
        delete_account_lambda = lambda: delete_account(userid, 1)#lambda function tomove on to next step
        if step == 0:
            clear_task_list(userid, delete_account_lambda) #delete all users task 
        elif step == 1:
            update_users_list(userid) #delete user info form users list
        elif step == 2:
            print("Account Deleted...")
            UID=0
            welcome_prompt()
    else:
        welcome_prompt() #get to welcome screen (logged out)

#deleting user credintials
def update_users_list(userid):
    global UID
    if userid == UID:
        with open("users.txt", "r") as users:
            data = users.read().splitlines()
        with open("users.txt", "w") as users:
            for i in data:
                if ast.literal_eval(i)["UID"] != userid:
                    users.write(i)
                    users.write("\n")
        delete_account(userid, 2)
    else:
        welcome_prompt()

#home prompt for logged in user
def home_prompt(userid):
    global UID
    if userid == UID:
        print("Enter 0 for help.")
        inp = take_input(0, 6)
        if inp == 0:
            loggedin_home_help(userid)
        elif inp == 1:
            list_task(userid)
        elif inp == 2:
            update_task_list(userid)
        elif inp == 3:
            delete_task(userid)
        elif inp == 4:
            clear_task_list(userid, home_prompt)
        elif inp == 5:
            delete_account(userid)
            print("Cleared...")
        else:
            UID = 0
            welcome_prompt()
    else:
        welcome_prompt()

#check if file exists or not
def pre_tasks():
    if not os.path.exists('users.txt'):
        with open("users.txt", "w") as users:
            pass
    if not os.path.exists('tasksmultiusers.txt'):   
        with open("tasksmultiusers.txt", "w") as tasklist:
            pass

#welcome for not logged in user
def welcome_prompt():
    print("1. Log-in into existing user:")
    print("2. Create new user:")
    print("3. Quit")
    inp = take_input(1, 3)
    if inp == 1:
        login()
    elif inp == 2:
        create_new_user()
    elif inp == 3:
        exit()

#taking input from the user for different functions
def take_input(n1, n2):
    try:
        inp = int(input(">>>"))
        if inp in range(n1, n2 + 1):
            return inp
        else:
            print("Invalid Value Entered:")
            inp = take_input(n1, n2)
            return inp
    except ValueError:
        print("Invalid Value Entered:")
        inp = take_input(n1, n2)
        return inp

#logging -n mechanism
def check(username, password):
    with open("users.txt", "r") as users:
        data = users.read().splitlines()
        for i in data:
            if ast.literal_eval(i)["username"] == username and ast.literal_eval(i)["password"] == password:
                return ast.literal_eval(i)["UID"]
        return False

#login prompt
def login_prompt():
    print("1. Go to login page:")
    print("2. Go back:")
    inp = take_input(1, 2)
    if inp == 1:
        login()
    elif inp == 2:
        welcome_prompt()

#login function
def login():
    global UID
    username = input("Enter your username: ")
    password = input("Enter your password: ")
    if UID := check(username, password):
        print("Login Successful")
        loggedin_home_help(UID)
    else:
        print("Your 'Username' or 'password' is incorrect.")
        welcome_prompt()

#check if username exits
def check_username(username):
    with open("users.txt", "r") as users:
        data = users.read().splitlines()
        for i in data:
            if ast.literal_eval(i)["username"] == username:
                return True
        return False

#creating new user
def create_new_user():
    username = input("Enter your username:")
    while check_username(username):
        print("Username Already Exists")
        username = input("Enter your username:")
    password = input("Enter your password:")
    with open("users.txt", "r") as users:
        data = users.read().splitlines()
    with open("users.txt", "a") as users:
        try:
            last_UID = int(ast.literal_eval(data[-1])["UID"])
        except IndexError:
            last_UID = 0
        data_block = {"UID": str(last_UID + 1), "username": username, "password": password}
        users.write(str(data_block))
        users.write("\n")
        users.flush()  # Ensure data is written to the file immediately
        os.fsync(users.fileno())  # Ensure the file descriptor is synced with the storage
    welcome_prompt()


#start program
if __name__ == '__main__':
    pre_tasks()
    print("Welcome to Task List")
    welcome_prompt()
