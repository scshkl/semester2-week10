# Task 5 Makefile

CFLAGS = -Wall -Wextra -Werror -O0 -pg
LDFLAGS = -pg

multiply: multiply.o matrix.o
	gcc $^ $(LDFLAGS) -o $@

%.o: %.c
	gcc $(CFLAGS) -c $<

clean:
	@rm -f *.o
	@rm -f multiply
	@rm -f gmon.out

.PHONY: clean
