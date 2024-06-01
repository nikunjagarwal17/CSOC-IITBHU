// readline module 
const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Global variables 
let players = [];
let numPlayers = 2; // Default number of players
let currentPlayer = 0; //  current player
let playersAlive = 0; // Count of players still alive
let userInput = 2; // User input choice for game state

// Player class
class Player {
  constructor(name) {
    this.name = name;
    this.isAlive = true; 
    this.score = 0; // Initial score is 0
  }
}

// print statistics of all players
function printStats() {
  for (let i = 0; i < numPlayers; i++) {
    console.log(`Player name: ${players[i].name}, Status: ${players[i].isAlive ? "Alive" : "Dead"}, Score: ${players[i].score}`);
  }
  console.log(`Players Alive: ${playersAlive} out of ${numPlayers}`);
}

// move to next player
function updateCurrentPlayer() {
  currentPlayer = (currentPlayer + 1) % numPlayers;
  if (!players[currentPlayer].isAlive) {
    updateCurrentPlayer(); // Skip dead players
  }
}

// post process for dead player
function shootDead() {
  console.log("BOOM");
  players[currentPlayer].isAlive = false;
  console.log(`${players[currentPlayer].name} is dead now.`);
  playersAlive--; // Decrease the count of alive players
  updateCurrentPlayer(); // Update current player 
}

// post process for alive player
function shootAlive() {
  console.log("CLICK");
  console.log(`${players[currentPlayer].name} survived.`);
  players[currentPlayer].score++; // Increase the player's score
  updateCurrentPlayer(); // update current player
}

// play round
function playGame() {
  let randomNo = randomNumber();
  console.log(`Shooting ${players[currentPlayer].name} ...`);
  setTimeout(() => {
    // shot or dead
    if (randomNo === 6) {
      shootDead(); 
    } else {
      shootAlive(); 
    }
  }, 400);
}

// generate random number
function randomNumber() {
  return Math.floor(Math.random() * 6) + 1;
}

// get number of players
function getNPlayers() {
  rl.question("Enter number of players (must be between 2 and 8): ", (input) => {
    let n = parseInt(input);
    if (n >= 2 && n <= 8) {
      numPlayers = playersAlive = n;
      getPlayerNames(0); //get player credentials 
    } else {
      console.log("Invalid number of players. Please enter a number between 2 and 8.");
      getNPlayers();
    }
  });
}

// get credentials
function getPlayerNames(i) {
  if (i < numPlayers) {
    rl.question(`Enter name of Player ${i + 1}: `, (name) => {
      name = name.trim();
      if (name !== '') {
        players.push(new Player(name));
        getPlayerNames(i + 1);
      } else {
        console.log("Name cannot be empty. Please enter a valid name.");
        getPlayerNames(i);
      }
    });
  } else {
    preProcess();
  }
}

// display winner
function displayWinner() {
  const border = "*".repeat(40);
  const padding = " ".repeat(8);
  const winnerName = `Winner: ${players[currentPlayer].name}`.padEnd(38, " ");
  const winnerScore = `Score: ${players[currentPlayer].score}`.padEnd(38, " ");

  console.log(border);
  console.log(`*${padding}${" ".repeat(22)}*`);
  console.log(`*${padding}${winnerName}${padding}*`);
  console.log(`*${padding}${winnerScore}${padding}*`);
  console.log(`*${padding}${" ".repeat(22)}*`);
  console.log(border);
}

// initialize the game
function gameInit() {
  rl.question("Enter 1 to get stats and 2 to play next round (default=2): ", (input) => {
    userInput = parseInt(input) || 2;
    if (userInput === 1) {
      printStats();
      gameInit();
    } else {
      playGame();
      setTimeout(() => {
        if (playersAlive > 1) {
          gameInit();
        } else {
          printStats();
          displayWinner();
          rl.close();
        }
      }, 500);
    }
  });
}

// documentation
function documentation() {
  console.log("-".repeat(5) + " Welcome to the game " + "-".repeat(5));
  console.log("One number is chosen from 1-6. If the chosen number is 6, the player is shot.\nThe last player standing will win the game.\n");
  console.log("Score is the number of times the number is chosen for you and you survived...");
  rl.question("Enter 'quit' to quit and Enter 'back' to get back to home page\n", (input) => {
    if (input.toLowerCase() === 'back') {
      main();
    } else if (input.toLowerCase() === 'quit') {
      rl.close();
    } else {
      console.log("Invalid Choice");
      documentation();
    }
  });
}

// set up players and play rounds (handeling)
function preProcess() {
  gameInit();
}

// welcome screen
function main() {
  rl.question("Enter 'play' to play and 'help' to get help and 'quit' to exit the game....\n", (input) => {
    if (input.toLowerCase() === 'play') {
      getNPlayers();
    } else if (input.toLowerCase() === 'help') {
      documentation();
    } else if (input.toLowerCase() === 'quit') {
      rl.close();
    } else {
      console.log("Invalid choice. Please enter 'play', 'help', or 'quit'.");
      main();
    }
  });
}

// base msg
console.log("Welcome to Russian roulette game:");
main();
