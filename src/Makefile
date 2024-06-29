.PHONY: all s21_matrix.a test clean

CC = gcc
FLAGS = -Wall -Werror -Wextra -std=c11 -pedantic
FUNC_DIR = functions
COV_FLAGS = -fprofile-arcs -ftest-coverage

SYSTEM := $(shell uname -s)

ifeq ($(SYSTEM), Linux)
    SYSTEM_FLAGS =  -lcheck -lpthread -lrt -lsubunit -lm
else ifeq ($(SYSTEM), Darwin)
    SYSTEM_FLAGS = -lcheck
endif

SRCS = $(wildcard $(FUNC_DIR)/*.c)
OBJS = $(SRCS:.c=.o)

all: clean s21_matrix.a test

s21_matrix.a: $(OBJS)
	ar rcs $@ $^

test: 
	$(CC) $(FLAGS) tests/unit_tests.c -o test.exe s21_matrix.a $(SYSTEM_FLAGS)
	./test.exe

gcov_report:
	gcc $(FLAGS) $(COV_FLAGS) $(SRCS) tests/unit_tests.c -o test.exe $(SYSTEM_FLAGS)
	./test.exe
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage_report
	rm -rf *.gc* test coverage.info decimal_test

clean:
	rm -rf s21_matrix.a test.exe $(OBJS)  *.gc* gcov_report coverage.info coverage_report/*
	rm -rf report_html
	rm -rf coverage_report
