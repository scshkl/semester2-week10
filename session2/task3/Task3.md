
# Task 3 

## a. Pointers to functions

### Defining and using a pointer

The code `p_func.c` shows how a pointer-to-a-function is defined, assigned and used.

Read, compile and test the code to ensure you understand the idea.

Implement 2 further integer operations as functions:
- `int subtract( int i, int j );`
- `int multiply( int i, int j );`

Test them using the function and a pointer to the function.

### Arrays of function pointers

Create an array of 3 function pointers that are assigned to your functions.

The syntax for an array is: `int (*operations[3])(int,int);`

You can assign functions directly using normal array syntax: `int (*operations[3])(int,int) = { add, subtract, multiply };`

### A simple calculator

- Read a string from the command line, such as `2 + 3`
- Use `argv[]` to parse the string into the two operands and operator and use your code to compute the answer.

Hint:
- You can make this simpler with an enumeration of the operations that matches the array index 
- ie. '+' = add = 0, '-' = subtract = 1, ...


## b. Simulating a class 

### Structures containing function pointers

- We cannot define functions within structures 
- However, we can create function pointers inside a struct and assign that to a function.
- It allows us to return more complex data from a function, including references to other functions.

The code `struct_func.c` illustrates this.

### A "class" in C?

You cannot define a class in C but you can use a combination of structs and pointers to functions that give class-like behaviour

The code template `class.c` defines a simple struct for a calculator.

It contain's both:
- state
    - data defining the internal state of the calculator
- behaviour
    - operations that change the state

**Note** 
- functions inside the class use a pointer to the structure
- this is analagous to the use of `self` in a Python class
- We use a separate `init()` function to dynamically create the struct

Complete the tasks indicated in the `main()` function
- note how we can use the structure for all the operations
- functions are only called via the structure pointers

**Extension**
- use command line data such that the calculator can be used in the form `./class 3 + 4`
- you should do appropriate input validation and type-conversion on `argv` and `argc` 

**Discussion**

In principle you can see how coding structures like this can lead to "class-like" behaviour.

What is missing from this description compared to, for example, a `class` in Python?
