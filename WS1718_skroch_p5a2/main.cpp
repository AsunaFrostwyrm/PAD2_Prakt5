/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Steve
 *
 * Created on December 11, 2017, 5:32 PM
 */
#include "quicksort.hpp"

int main(int argc, char** argv) try {
    srand(time(NULL));
    TestQuicksort();
    //CharTestQuicksort();
    return 0;
} catch (std::exception &e) {
    std::cerr << e.what();
    return -2;
} catch (...) {
    std::cerr << "Ein Fehler";
    return -1;
}


