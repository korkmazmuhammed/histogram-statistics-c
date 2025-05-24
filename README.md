# Histogram and Statistics Tool in C

This is a C program to analyze an array of integers, display a histogram, and calculate basic statistics such as average, median, and mode within a user-specified interval.

## Features

- Reads a static array of integers, optionally allows user to add up to 5 more numbers
- Prompts the user for an interval `[A, B]` where 50 ≤ A ≤ B ≤ 200
- Displays a histogram of numbers in the chosen interval
- Calculates and prints:
    - Average
    - Median
    - Mode(s)
- User-friendly menu for adding extra numbers or analyzing the default dataset

## How to Use

1. Compile the code:
    ```bash
    gcc 220104004043.c -o histogram_stats
    ```
2. Run the program:
    ```bash
    ./histogram_stats
    ```
3. Enter a valid interval (A and B between 50 and 200).
4. Optionally, add up to 5 extra numbers.
5. The program prints the histogram and statistical summaries.

## Example Output

