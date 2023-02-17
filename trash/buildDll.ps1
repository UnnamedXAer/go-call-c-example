g++ -c myapi.cpp -lole32 -loleaut32
gcc -shared -o mydll.dll myapi.o -lole32 -loleaut32 