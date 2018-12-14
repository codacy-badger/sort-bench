all: 
	g++ main.cpp --std=c++1z -O3 -flto -o sort_bench

bench:
	./sort_bench

clean:
	rm sort_bench
