.PHONY : build run

# Runners
build: clean
	/usr/local/Cellar/gcc/9.2.0_1/bin/g++-9 src/* -o bin/run

debug: clean
	/usr/local/Cellar/gcc/9.2.0_1/bin/g++-9 -g src/* -o bin/debug

run:
	./a.out

clean: 
	rm src/*.gch || echo "Already Clean"

tests:
	/usr/local/Cellar/gcc/9.2.0_1/bin/g++-9 test/*
