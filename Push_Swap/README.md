*This project has been created as part of the 42 curriculum by akheiral*
# push_swap
## 🧠 Description
This project involves writing a sorting algorithm for stacks. We are given two stacks and a set of operations we can perform. The goal is to generate the best set of steps to sort the numbers in one stack. 

The program receives a sequence of numbers either seperated by a space or place in double quotes. If the input is invalid it returns an Error\n.

Two stacks are used:
* **Stack A** -> contains the initial list of unsorted numbers
* **Stack B** -> an empty stack used as filler when sorting 

**Stack Operations:**

Push:
* pb (pushes a number from the top of stack a to stack b)
* pa (pushes a number from the top of stack b to stack a)

Swap:
* sb (swaps the first two numbers in stack b)
* sa (swaps the first two numbers in stack a)
* ss (swaps the first two numbbers in both stack a and stack b)

Rotate:
* rb (shifts all the numbers in stack b up by one)
* ra (shifts all the numbers in stack a up by one)
* rr (shifts all the numbers in both stack a and stack b up by one)

Reverse Rotate:
* rrb (shifts all the numbers in stack b down by one)
* rra (shifts all the numbers in stack a down by one)
* rrr (shifts all the numbers in both stack a and stack b down by one)

### Technical Implementation
I chose to create a custom linked list, each node contains a value, index, and pointer to the next node. In my program both stack a and stack b are linked lists and the operations are built to handle and preform changes on the lists.

Before sorting, I check if the input is valid and store all the values in an array of integers. I initialize both stack a and stack b by allocating memory. I then use this array of integers to fill stack a by storing all the numbers in nodes.

When filling stack a, I preform something called **Index Normalization**. Instead of relying on the values of the nodes to compare numbers I use the index instead this simplifies the process of sorting as I don't have to worry about comparing large postive or negative numbers. I just know that at maximum capacity the index ranges from 0 to 499.

After setting up the index I start sorting I have 3 different sorting algorithms.
1. Simple Sort (This is used for sorting 3 numbers in <= 2 steps)
2. Radix Sort (This sorting alogorithm compares index values by looking at the binary values it preforms well with smaller inputs so I have this algorithm sort when we have less than 20 numbers)
3. Chunk Sort (This is my main sorting algorithm it divides the stack into smaller chunks and sorts each chunk by pushing it to stack b and then back to stack a in order)

After sorting all the numbers in stack a, I free all the used up memory to prevent memory leaks. 

**Average Benchmark:**

592 steps for 100 numbers

5110 steps for 500 numbers

## 📝 Instructions
In order to compile the C files into the push_swap program you just have to type `make` or `make all`.

You can then use the program like this usage example:

```./push_swap 2 6 1 5 3 4 0```

```./push_swap -15 129 32 897 23792 0 -1231 3920 23232 10000 2 4 -900```

```./push_swap 2 1```

In order to test whether or not the sorting instructions are correct you can use the provided tester for mac or linux:

```ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_mac $ARG```

```ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG```

Or you can use the testers I made by typing (You have to use either the ubuntu one or mac one)

```make test```

## ℹ Resources
Push Swap Blog [here](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)

Radix Sorting [here](https://www.geeksforgeeks.org/dsa/radix-sort/)

Cool Video [here](https://www.youtube.com/watch?v=OaG81sDEpVk)

I used AI LLM's such as Claude to brainstorm an implmentation of push swap. I had it generate visual guides for radix, chunk, and turk to understand how they work and what fits for my specific version. It also helped me generate proper testing files covering a lot of examples such as worse case scenarios and random combinations of numbers. 