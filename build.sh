cmake -DCMAKE_BUILD_TYPE=Release -S \. -B build 
cmake --build build --target all test -j 8
