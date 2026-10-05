#include "Emulator.hpp"
#include <iostream>
using namespace std;

int main(){
    try{
        Emulator app;
        app.run();
    } catch(const exception& e){
        cerr<<"Error: "<<e.what()<<endl;
        return -1;
    }
    return 0;
}