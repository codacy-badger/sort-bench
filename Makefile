all: 
	g++ main.cpp -O3 -flto -o sort_bench

bench:
	./sort_bench

clean:
	rm sort_bench
