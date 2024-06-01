def selectionsort(arr):
    n = len(arr)
    # Traverse through all array elements
    for i in range(n):
        # Find the minimum element in the unsorted portion of the array
        min_idx = i
        for j in range(i + 1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j  # Update min_idx if a smaller element is found
        # Swap the found minimum element with the first element of the unsorted portion
        if min_idx != i:
            arr[min_idx], arr[i] = arr[i], arr[min_idx]

def main():
    # Ask the user for the size of the array
    n = int(input("Enter size of array: "))
    arr = []
    
    # Input the array elements from the user
    for i in range(n):
        element = int(input(f"Enter element {i + 1}: "))
        arr.append(element)
    
    # Call the selection sort function to sort the array
    selectionsort(arr)
    
    # Print the sorted array
    for i in range(n):
        print(arr[i], end=" ")
    print()

if __name__ == "__main__":
    main()
