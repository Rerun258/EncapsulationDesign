// Week8Lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double calLienearInterpolationDistance(double r1, double r0, double d1, double d0, double r)
{
    return ((r1 - r0) / ((d1 - d0) * (r - r0))) + d0;
}

double calLienearInterpolationHeight(double r1, double r0, double d1, double d0, double d)
{
	return (r0 + (((r1 - r0) * (d - d0)) / (d1 - d0))); 
}


int main()
{
    std::cout << "Hello World!\n";
}