#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Define the maximum number of players
#define MAX_PLAYERS 8

// Structure to represent each player
typedef struct {
    char name[50];  // Player's name
    int isAlive;    // Player's status (alive or dead)
    int score;      // Player's score
} Player;

Player players[MAX_PLAYERS];  // Array to hold player data
int n = 2;  // Number of players, default is 2
int currentPlayer = 0;  // Index of the current player
int playersAlive = 0;  // Count of players still alive
int inp = 1;  // Input choice for game state

// statistics of all players
void print_stats() {
    for (int i = 0; i < n; i++) {
        printf("Player name: %s, Status: %s, Score: %d\n", players[i].name, players[i].isAlive ? "Alive" : "Dead", players[i].score);
    }
    printf("Players Alive: %d out of %d\n", playersAlive, n);
}

// move to next player
void update_currentPlayer() {
    do {
        currentPlayer = (currentPlayer + 1) % n;  // Move to the next player
    } while (!players[currentPlayer].isAlive);  // Skip dead players
}

// process for dead player
void shoot_dead() {
    printf("BOOM\n");
    players[currentPlayer].isAlive = 0;  // Set the player's status to dead
    printf("%s is dead now.\n", players[currentPlayer].name);
    playersAlive--;  // Decrease the count of alive players
    update_currentPlayer();  // Update the current player index
}

// process for alive player
void shoot_alive() {
    printf("CLICK\n");
    printf("%s survived.\n", players[currentPlayer].name);
    players[currentPlayer].score++;  // Increase the player's score
    update_currentPlayer();  // Update the current player index
}

//  random number between 1 and 6
int random_number() {
    return rand() % 6 + 1;
}

// play a round 
void play_game() {
    int random_no = random_number();
    printf("Shooting %s", players[currentPlayer].name);
    fflush(stdout);
    usleep(400000);  // delay to loook good
    printf(".");
    fflush(stdout);
    usleep(400000);
    printf(".");
    fflush(stdout);
    usleep(400000);
    printf(".");
    fflush(stdout);
    usleep(400000);
    //check deal or alive
    if (random_no == 6) {
        shoot_dead();  
    } else {
        shoot_alive(); 
    }
    usleep(400000);
}

// number of players
void get_n() {
    printf("Enter number of players must be between [2,8]: (default=2)");
    scanf("%d", &n);
    playersAlive = n;  // Set the count of alive players
    if (n < 2 || n > 8) {
        get_n();  // Recursively ask for a valid number of players
    }
}

// initilizing each player
void get_player_name(int i) {
    printf("Enter name of Player %d: ", i + 1);
    scanf("%s", players[i].name);
    players[i].isAlive = 1;  // Set the player's status to alive
    players[i].score = 0;  // Initialize the player's score
}

// get players
void defining_users() {
    get_n();  // Get the number of players
    for (int i = 0; i < n; i++) {
        get_player_name(i);  // initilize each player
    }
}

//  display the winner
void display_winner() {
    printf("******************************\n");
    printf("%s WIN\n", players[currentPlayer].name);
    printf("SCORE %d\n", players[currentPlayer].score);
    printf("******************************\n");
}

// initialize the game
void game_init() {
    printf("Enter 1 to get stats and 2 to play next round (default=2): ");
    if (scanf("%d", &inp) != 1) {
        printf("Value Error\n");
        inp = 2;  // Default to playing the next round
    }
    if (inp == 1) {
        print_stats();  // Print stats for option 1
    } else {
        play_game();  // Play the game
    }
}

// set up players and play rounds (handeling)
void pre_process() {
    defining_users();  // Set up players
    while (playersAlive > 1) {
        game_init();  // play until one win the game
    }
    print_stats();  // Print final stats
    display_winner();  // Display the winner
}

int main() {
    srand(time(NULL));  // Seeding the random number 
    printf("Welcome to Russian roulette game:\n");
    pre_process();  // Start 
    return 0;
}
