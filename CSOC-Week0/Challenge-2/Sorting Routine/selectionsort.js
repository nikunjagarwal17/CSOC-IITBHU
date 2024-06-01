// readline module
const readline = require('readline');


const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Sortfunction
function selectionSort(arr) {
  const n = arr.length;
  for (let i = 0; i < n; i++) {
    let minIdx = i;
    // finding minimum element in the unsorted array
    for (let j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIdx]) {
        minIdx = j; 
      }
    }
    // Swap with first element
    if (minIdx != i) {
      [arr[minIdx], arr[i]] = [arr[i], arr[minIdx]];
    }
  }
}

// get array size
function askForArraySize() {
  return new Promise((resolve) => {
    rl.question("Enter size of array: ", (size) => {
      resolve(parseInt(size)); 
    });
  });
}

// get array elements
function askForArrayElements(size) {
  const arr = [];
  let index = 0;

  return new Promise((resolve) => {
    function askForElement() {
      if (index < size) {
        rl.question(`Enter element ${index + 1}: `, (element) => {
          arr.push(parseInt(element)); 
          index++;
          askForElement();
        });
      } else {
        resolve(arr);
      }
    }
    askForElement();
  });
}

async function main() {
  // size of array
  const size = await askForArraySize();
  // get array elements
  const arr = await askForArrayElements(size);

  // sorting
  selectionSort(arr);

  // Print the sorted array
  console.log("Sorted array:", arr.join(" "));

  rl.close();
}

// Run the main function
main();
