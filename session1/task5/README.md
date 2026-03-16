# Task 5: Profiling

The `task5` directory contains a slightly different version of the matrix
multiplication example from Task 1.

1. Compile the application by entering `make`. Look at the compiler commands
   echoed in the terminal. Notice how `-pg` is used when compiling the
   source files to object code _and_ when linking them into an executable.

2. Run the program:

       ./multiply

   After a short delay, the program should terminate. There should now be
   a file named `gmon.out` in this directory.

3. Run Gprof like so:

       gprof multiply gmon.out > report.txt

   Profiling information will be available in human-readable form in
   `report.txt`.

4. Study the 'flat profile' printed at the start of `report.txt`. This shows
   headline performance statistics for the program's functions, in a table.

   The table is sorted by total time spent executing each function, and then
   by function name in cases where time estimates are indistinguishable
   from each other. Read the column descriptions beneath the table for further
   information on what it shows.

   You can see here that

   - The program spends almost all of its time in `multiply_row_by_column()`,
     which is invoked 1,000,000 times.

   - `get_pseudorandom_number()` is invoked 2,000,000 times, but consumes
     almost no time in comparison to `multiply_row_by_column()`.

   - The other functions are called only a few times each and make no
     measureable contribution to execution time themselves.

5. Study the call graph, which appears after the flat profile. This appears
   in tabular form and is a little harder to interpret.

   Read the information below the table carefully, as it gives a detailed
   explanation of what the different elements of the table mean.

   Notice how this provides additional information, not seen in the flat
   profile. For example, the flat profile tells you that `matrix_create()`
   is called a total of three times, but the call graph tells you that one of
   those calls is made from `matrix_multiply()` and the other two are made
   from `main()`.
