#include <iostream>

using namespace std;

// Selection Sort
//      keep track of unsorted section
//      find minimum of unsorted section

<template typename T> void findMinIndex(T[] list, int start, int count)
{
    int minIndex = start;
    for (int i = start; i < count; i++)
    {
        if (list[i] < list[minIndex])
            minIndex = i;
    }
    return minIndex;
}

<template typename T> void selectionSort(T[] list, int count)
{
    if (count <= 1)
        return;

    for (int start = 0; start < count; start++)
        // find minimum between start and count-1
        int minIndex = findMinIndex(list, start, count);

    // swap minimum and next unsorted
    if (minIndex != start)
    {
        T minItem = list[minIndex];
        list[minIndex] = list[start];
        list[start] = minItem;
    }
}


// Insertion Sort
//      keep track of unsorted section
//      move 1st unsorted to the left until it is in correct location

<template typename T> void insertionSort(T[] list, int count)
{
    if (count <= 1)
        return;

    for (int i = 1; i < count; i++)
        // unsorted is set to i for next item to sort
        int unsorted = i;

        while (list[unsorted] < list[unsorted-1]){
            // swap
            swap(list[unsorted], list[unsorted-1]);
            unsorted--;

            // break while loop if unsorted is at start of list
            if (unsorted <= 0) break;
        }

        int minIndex = findMinIndex(list, start, count);

    // swap minimum and next unsorted
    if (minIndex != start)
    {
        T minItem = list[minIndex];
        list[minIndex] = list[start];
        list[start] = minItem;
    }
}




int main()
{

    return 0;
}