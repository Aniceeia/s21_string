CC = gcc
DEBUGGER = gdb
CFLAGS = -Wall -Werror -Wextra 
GET_OBJECTS = -Wall -Werror -Wextra -std=c11 -c
ALL_SOURCE = functions/*.c
ALL_TESTS_SOURCE = tests/*.c
ALL_OBJECTS = *.o
LIBS = -lcheck $(shell pkg-config --cflags --libs check) -lm 

GOAL = s21_string.a

all: $(GOAL)

$(GOAL):
	$(CC) $(GET_OBJECTS) $(ALL_SOURCE)
	ar r $(GOAL) $(ALL_OBJECTS)
	rm -rf *.o

build_test: $(GOAL)
	$(CC) $(CFLAGS) $(ALL_TESTS_SOURCE) $(GOAL) $(LIBS) -o test

test: $(GOAL) build_test
	./test

valgrind: clean build_test
	valgrind --trace-children=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test

gcov_report: $(GOAL)
	gcc -lcheck --coverage $(ALL_SOURCE) $(ALL_TESTS_SOURCE) $(LIBS) -o test
	./test
	lcov -t "test" -o test.info -c -d .    
	genhtml -o report test.info
	open ./report/index.html
	rm -rf *.gcno *.gcda *.info test

debug: $(GOAL)
	$(CC) $(ALL_SOURCE) $(ALL_TESTS_SOURCE) $(LIBS) -g -o debug
	$(DEBUGGER) ./debug

style:
	clang-format -n --style=Google functions/* tests/* *.h

clean:
	rm -rf *.o 
	rm -rf *.gcda
	rm -rf  *.gcno
	rm -rf  *.a
	rm -rf  *.gch
	rm -rf  test
	rm -rf  *.css
	rm -rf  *.html
	rm -rf  debug
	rm -rf report

rebuild: clean all
