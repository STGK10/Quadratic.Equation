#pragma once
#include <iostream>
#include"detail.h"
using namespace std;

int main()
{
	cout << "Enter a, b, c of ax^2 + bx + c = 0 using space between coefficients" << endl;
	DisplayResult(rootComputation(GetEquation()));

	return 0;
}