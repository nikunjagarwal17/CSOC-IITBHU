import random
import time

player = [] #players obbject
n = 2 # number of players, default 2
currentplayer = 0 #player that is playing currently
playeralive = 0 # number of player alive
inp = 1 # defalult input for game

#player class 
class Players:
    def __init__(self, name):
        self.name = name
        self.isAlive = True
        self.score = 0

#print statictics of the game
def print_stats():
    for i in range(n):
        print("Player name: {}, Status: {}, Score: {}".format(player[i].name, "Alive" if player[i].isAlive else "Dead",
                                                              player[i].score))
    print("Players Alive: {} out of {}".format(playeralive, n))


#moving on the next player
def update_currentplayer():
    global currentplayer
    currentplayer = (currentplayer + 1) % n
    if not player[currentplayer].isAlive:
        update_currentplayer()

#post process for dead player
def shoot_dead():
    print("BOOM")
    player[currentplayer].isAlive = False
    print("{} is dead now.".format(player[currentplayer].name))
    global playeralive
    playeralive -= 1
    update_currentplayer()

#post process for alive player
def shoot_alive():
    print("CLICK")
    print("{} survived.".format(player[currentplayer].name))
    player[currentplayer].score += 1
    update_currentplayer()

#playing the game deciding dead or alive
def play_game():
    random_no = random_number()
    print("Shooting {}".format(player[currentplayer].name), end='')
    time.sleep(.4)
    print(".", end="")
    time.sleep(.4)
    print(".", end="")
    time.sleep(.4)
    print(".", end=" ")
    time.sleep(.4)
    if random_no == 6:
        shoot_dead()
    else:
        shoot_alive()
    time.sleep(.4)

#generateing random choise
def random_number():
    return random.randint(1, 6)

#get number of players
def get_n():
    global n
    global playeralive
    playeralive = n = int(input("Enter number of players must be between [2,8]: "))
    if n < 2 or n > 8:
        get_n()

#get name of all players 
def get_player_name(i):
    name = input("Enter name of Player {}: ".format(i + 1))
    if name.strip() != '':
        player.append(Players(name))
        return
    get_player_name(i)

# defining users
def defining_users():
    try:
        get_n()
    except ValueError:
        defining_users()
        return
    for i in range(n):
        get_player_name(i)

# display results 
def display_winner():
    print("*" * 30)
    print("*{:^28}*".format(""))
    print("*{:^28}*".format("{} WIN".format(player[currentplayer].name)))
    print("*{:^28}*".format("SCORE: {}".format(player[currentplayer].score)))
    print("*{:^28}*".format(""))
    print("*" * 30)

#initiliaze the game
def game_init():
    global inp
    try:
        inp = int(input("Enter 1 to get stats and 2 to play next round (default=2): "))
    except ValueError:
        print("Value Error")
        game_init()
    if inp == 1:
        print_stats()
    else:
        play_game()

#get help
def documentation():
    print("-" * 5 + "Welcome to the game" + "-" * 5)
    print(
        "One number is choosen from 1-6 if the choosen number is 6 the player is GUN shot. \nThe last Player standing will win the game.\n")
    print("Score is the number of times the number is choosen for you and you survived...")
    while True:
        inpp = input("Enter 'quit' to quit and Enter 'back' to get back to home page\n")
        if inpp.lower() == 'back':
            welcomepage()
            return
        elif inpp.lower() == 'quit':
            return
        else:
            print("Invalid Choise")

#get players play game and display result
def pre_process():
    defining_users()
    global playeralive
    while playeralive > 1:
        game_init()
    print_stats()
    display_winner()

#home page of the game
def welcomepage():
    inppp = input("Enter 'play' to play and 'help' to get help and 'quit' to exit the game....\n")
    if inppp.lower() == 'play':
        pre_process()
    elif inppp.lower() == 'help':
        documentation()
    elif inppp.lower() == 'quit':
        return
    else:
        print("invalid choise")
        welcomepage()
        return

#start of the program
if __name__ == '__main__':
    print("Welcome to Russian roulette game:")
    welcomepage()
