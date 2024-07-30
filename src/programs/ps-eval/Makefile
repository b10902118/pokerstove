all:
	c++ -O3 -Wall -shared -std=c++14 -fPIC -Wl,-rpath=. `python3 -m pybind11 --includes` -I../../lib  main.cc -o example`python3-config --extension-suffix` -static-libgcc -static-libstdc++  -L./lib -lpeval -lpenum -Wl,--exclude-libs,ALL 
bin: bin.cc
	c++ -O3 -Wall -static -std=c++14 -fPIC -Wl,-rpath=. -I../../lib  bin.cc -o bin -L./lib -lpeval -lpenum -Wl,--exclude-libs,ALL 
