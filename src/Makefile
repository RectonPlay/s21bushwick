CC = gcc -Wall -Wextra -Werror -std=c11 -g
CHECK = -lcheck -lm
ifeq ($(shell uname -s), Linux)
	CHECK += -lsubunit -lrt -lpthread
endif
BINARY = test
SRC = $(wildcard *.c)
LIB = s21_matrix.a
GCOV_FLAGS = --coverage
TEST_SRC = ./tests/tests.c

all: s21_matrix.a

s21_matrix.a: 
	$(CC) -c $(SRC) 
	ar rcs s21_matrix.a *.o
	rm -rf *.o

test: s21_matrix.a
	$(CC) $(TEST_SRC) -o $(BINARY) $(CHECK) -L. $(LIB)
	./$(BINARY)

gcov_report:
	$(CC) -o $(BINARY) $(SRC) $(TEST_SRC) $(CHECK) $(GCOV_FLAGS)
	./test
	lcov -t $(BINARY) -o 21_test.info -c -d .
	genhtml -o report 21_test.info
	open ./report/index.html
	rm -rf *.gcda *.gcno 21_test.info
	
valgrind: s21_matrix.a
	gcc -g -Wall -Werror -Wextra -std=c11 ./tests/tests.c $< -o test -lcheck -lsubunit -lrt -lpthread -lm
	CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT_VALGRIND.txt ./test

clean:
	rm -rf *.o *.gcno *gcda *.info *.a $(BINARY) report *.dSYM

rebuild: clean all


style:
	clang-format -style=Google -i *.c *.h tests/*
	clang-format -style=Google -n *.c *.h tests/*

.PHONY: test, clean, rebuild, style
