/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Quicksort.hpp
 * Author: Steve
 *
 * Created on December 12, 2017, 10:34 AM
 */

#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <stdexcept>
using namespace std;

template <typename T> size_t MedianOfThree(T &a, T &b, T &c, size_t ai, size_t bi, size_t ci) {
    if (a >= b && a <= c)
        return ai;
    if (b >= a && b <= c)
        return bi;
    return ci;
}

template <typename T> size_t QuicksortPartition(vector<T> &A, size_t lo, size_t hi) {
    size_t ci = (int) (0.5 * (lo + hi) + 0.5);
    size_t pivotIndex = MedianOfThree(A[lo], A[ci], A[hi], lo, ci, hi);
    T pivot = A[pivotIndex];

    size_t i = lo;
    size_t j = hi;
    while (true) {
        while (A[i] <= pivot && i < pivotIndex) i++;
        while (A[j] >= pivot && j > pivotIndex) j--;
        if (i == pivotIndex && j == pivotIndex)
            return pivotIndex;

        T tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;

        if (i == pivotIndex)
            pivotIndex = j;
        else if (j == pivotIndex)
            pivotIndex = i;
    }
}

template <typename T> void Quicksort(vector<T> &A, size_t lo, size_t hi) {
    if (lo < hi) {
        size_t p = QuicksortPartition<T>(A, lo, hi);
        if (p > 0) //p is unsigned, so prevent negative
            Quicksort<T>(A, lo, p - 1);
        Quicksort<T>(A, p + 1, hi);
    }
}

template <typename T> void Quicksort(vector<T> &A) {
    if (A.size() <= 1)
        return; //Nothing to do
    Quicksort(A, 0, A.size() - 1);
}

template <typename T> bool SortResultIsValid(const vector<T> &A) {
    for (size_t i = 1; i < A.size(); i++)
        if (A[i] < A[i - 1])
            return false;
    return true;
}

void TestQuicksort() {
    //for (size_t tn = 0; tn < 10000; tn++) {
        vector<unsigned> test;
        int numVals = 50;
        for (int i = 0; i < numVals; i++)
            test.push_back((rand() % 100) - 50);

        Quicksort(test);
        for(int i = 0; i < test.size();i++){
            cout << test[i] << endl;
        }

        bool valid = SortResultIsValid(test);
        if (!valid)
            throw runtime_error("Quicksort produced invalid result");
    //}
}

/*void CharTestQuicksort() {
    for (size_t tn = 0; tn < 10000; tn++) {
        vector<char> test;
        int numVals = rand() % 100;
        for (int i = 0; i < numVals; i++)
            test.push_back((rand() % 127) );

        Quicksort(test);

        bool valid = SortResultIsValid(test);
        cout << test.at(tn) << ", valid=" << valid << endl;
        if (!valid)
            throw runtime_error("Quicksort produced invalid result");
    }
}*/


#endif /* QUICKSORT_HPP */

