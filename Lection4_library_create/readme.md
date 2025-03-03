<!-- 1.
gcc -c power_for.c -o power_for.o
ar rcs libpower_for.a power_for.o
2.
gcc -fPIC -c power_divide.c -o power_divide.o
gcc -shared -o libpower_divide.so power_divide.o
3.
gcc main_static.c -L. -lpower_for -o main_static
./main_static
4.
gcc main_dynamic.c -L. -lpower_divide -o main_dynamic
LD_LIBRARY_PATH=. 
./main_dynamic -->

<!-- У статической библиотеки размер больше чем у динамической. -->

