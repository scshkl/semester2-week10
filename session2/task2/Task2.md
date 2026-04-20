# Task 2 - Structures, unions and enumerations

## a. Storing unions and enumerations in a structure

We can define a struct for a Variable containing:
- an enumerated type: Integer, Real, String
- a union for storing the value of the appropriate type

Use of the enumeration label and union storage simulates the behaviour of a dynamic data-type, such as we see in Python  

To implement in the file `pyVar.c`:
- define an enumeration `_type`
    - with 3 values: `INTEGER`, `REAL`, `STRING`
    - `typedef` to `Type`
- define a union `_value`
    - with 3 items: `int ival`, `float fval`, `char sval[10]`
    - `typedef` to `Value`
- define a structure `_variable`, including
    - a `Type` enumeration
    - a `Value` union
    - `typedef` to `Variable`

In `main()` 
- create `Variable` structures with data of different types and appropriate enumeration label
- print the data stored in each variable (using appropriate formnatting) to demonstrate that different types can be stored in the `union`
- what happens if you try and print with the wrong format? Why?

## b. Functions using `Variable`s

We can define function that operate on a `Variable` such that our code in `main()` can transparently handle the different data types
- to assign and reassign data
- to print data
- to operate on data values, eg. add values

Functions will use a common pattern of `switch`ing behaviour on the enumerated `type`

```
switch( var.type ) {
    case INTEGER:
        ...
        break;
    case REAL:
        ...
        break;
    case STRING:
        ...
        break;
    default:
        ...
        break;  
}
```

Complete the following functions:
- `void print( Variable var );` 
    - print using an appropriate format 
- `Variable assign( Type t, Value v );`
    - assign a value and type
    - this can include changing the type of the `Variable` that is assigned, 
        - ie. `var = assign( t, v );` assigns or reassigns the `Variable var`
    - return a new `Variable`
- `Variable add( Variable var1, Variable var2 );`
    - check that types match or report an error
    - add (or concatenate for strings) the data

Test your new functions.

**Discussion**

The `Variable` struct shows how dynamic typing can be simulated in C and provides a hint at how Python can support this behaviour, although the Python implementation is more complex and flexible.

## c. Arrays of `Variable`s

Create an array of `Variable` type.

You can store data in each array item of different primitive type.

Test your array using the functions you have written.

**Discussion**

The array of `Variable` structs shows how a language like Python can implement a `List` that stores data of different type.

Combined with dynamic allocation and list operations (see Week 9 Lectures) we could implement a comparable data structure.