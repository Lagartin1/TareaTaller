CC=g++
CFLAGS=-Wall -std=c++17 -O3
BINS=main 
PROFILEFLAGS=-g -O0 -Wall -DVERBOSE
all: clean main


main:
	$(CC) $(CFLAGS) -o mainOut main.cpp

dbg_prog: clean
	$(CC) $(PROFILEFLAGS) SortAlg.cpp -o SortAlg.out

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
