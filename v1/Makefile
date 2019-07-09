CC=g++
SRCS=main.cpp\
		big_integer.cpp\
		test.cpp
OBJS=$(SRCS:.cpp=.o)
INPUT=input.in
EXEC=exec
start:$(OBJS)
	$(CC) -Wall -std=c++11 -o $(EXEC) $(OBJS)
.cpp.o:
	$(CC) -o $@ -c $<
run: $(EXEC)
	./$(EXEC)
clean:
	rm -rf $(OBJS)