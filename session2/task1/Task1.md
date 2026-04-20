
# Task 1 - Tokenisation

## a. String tokenisation with `strtok()`

Test the `<string>` library function `strtok()`

Read the documentation https://en.cppreference.com/w/c/string/byte/strtok.html
and complete the program `token.c`

Note that we call `strtok()` repeatedly until the string is "consumed"

## b. Implementation of string tokenisation

Implement string tokenisation on whitespace without the `<string>` library.

Complete the program `tokenise.c`
- We can iterate through the string with a for-loop
- assign argv[] array entries when each token is found

Compare to `strtok()` output from `token.c`

You could alternatively implement with a while-loop

## c. Implementation of command-line arguments in C?

Our `tokenise.c` code has a set limit of 10 for argc

If we first count the tokens we can dynamically allocate `argv[]`

We use 2 passes:
- in the first pass we count tokens to find `argc`
- we allocate `argv[]`
- in the second pass we assign values to `argv[]`

Complete implementation of `cmd_args.c` to implement this.