#include <iostream>


// определение функция которая будет передаваться как параметр
void printHello(){
    std::cout << "Hello, World!" << std::endl;
}

//функция которая принимает указаетль на функцию в качесвте параметра
void executeFunction(void (*func)()) {
    func();
}

int main(){
    //передаём указатель на функцию printHello
    executeFunction(printHello);
    return 0;
}


//прототип

// void executeFunction(void (*)())

