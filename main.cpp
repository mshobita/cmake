#include <iostream>
#include "Wifi.hpp"
int main() {
    #ifdef DEBUGINFO
    std::cout<<DEBUGINFO<<std::endl;
    #endif
    WIFI_Init();
    // std::cout << "Hello" << std::endl;
    std::cout<<STD_CXX<<std::endl;
    return 0;
}