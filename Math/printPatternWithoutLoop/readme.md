Print a pattern without using any loop
Difficulty Level : Easy
Last Updated : 11 Sep, 2021
Given a number n, print following a pattern without using any loop.

Examples :

Input: n = 16
Output: 16, 11, 6, 1, -4, 1, 6, 11, 16

Input: n = 10
Output: 10, 5, 0, 5, 10
We basically first reduce 5 one by one until we reach a negative or 0. After we reach 0 or negative, we one add 5 until we reach n.
Source: Microsoft Interview Question.

We strongly recommend that you click here and practice it, before moving on to the solution.
The idea is to use recursion. It is an interesting question to try on your own.
Below is the Code. The code uses a flag variable to indicate whether we are moving toward 0 or we are moving toward the back to n.

> #### points
>
> -   Python program to print pattern
> -   that first reduces 5 one by one,
> -   then adds 5. Without any loop.
> -   Recursive function to print
> -   the pattern.n indicates
> -   input value m indicates
> -   current value to be printed
> -   flag indicates whether we
> -   need to add 5 or subtract 5.
> -   Initially flag is True.
>
>     _Everything_ is going according to **plan**.

    def printPattern(n, m, flag):

    # Print m.
    print(m)

    # If we are moving back
    # toward the n and we
    # have reached there,
    # then we are done
    if flag == False and n == m:
        return
    # If we are moving
    # toward 0 or negative.
    if flag:
    # If m is greater, then 5,
    # recur with true flag
        if m - 5 > 0:
            printPattern(n, m - 5, True)
        else: # recur with false flag
            printPattern(n, m - 5, False)
    else: # If flag is false.
        printPattern(n, m + 5, False)

# Driver Code

n = 16
printPattern(n, n, True)

# This code is contributed

# by HrushikeshChoudhary

Output :

16, 11, 6, 1, -4, 1, 6, 11, 16
How to print above pattern without any extra variable and loop?
The above program works fine and prints the desired out but uses extra variables. We can use two print statements. First one before the recursive call that prints all decreasing sequence. The second one after the recursive call to print increasing sequence.

Below is the implementation of the idea.

# Python3 program to print pattern that

# first reduces 5 one by one, then adds 5.

# Without any loop an extra variable.

# Recursive function to print the pattern

# without any extra variable

    def printPattern(n):

    # Base case (When n becomes 0 or negative)
    if (n == 0 or n < 0):
        print(n, end = ", ")
        return

    # First print decreasing order
    print(n, end = ", ")
    printPattern(n - 5)

    # Then print increasing order
    print(n, end = ", ")

# Driver Code

n = 16
printPattern(n)

# This code is contributed by

# Mohit kumar 29

Output:

16, 11, 6, 1, -4, 1, 6, 11, 16
Thanks to AKSHAY RATHORE for suggesting the above solution.
This article is contributed by Gautham. Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above
