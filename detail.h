#pragma once
#include <iostream>
using namespace std;

//equation structure with its coefficients
typedef struct Equation {
	float a;
	float b;
	float c;
}Equation;

//Structure to get answers as result
typedef struct Answer {
	float x1;
	float x2;
	float Error;
}Answer;

//function to read polynom's coefficient and return struct poly
Equation GetEquation() {
	struct Equation poly;
	std::cin >> poly.a >> poly.b >> poly.c;
	cout << poly.a << "ax^2" << " + " << poly.b << "bx" << " + " << poly.c << "c" << endl;
	return poly;
}

//Discriminant compute as delta
float Delta(Equation poly)
{
	return ((poly.b * poly.b) - (4 * poly.a * poly.c));
}

//Main function that compute root with struct Equation as type for the input poly in order to out put the answer as result
Answer rootComputation(Equation poly)
{
	Answer result;
	result.Error = 0;

	if (poly.a == 0) //case where a=0
	{
		if (poly.b == 0)//case where a=0 and b=0
		{
			if (poly.c == 0)// case where a=0 b=0 and c=0
			{
				result.Error = 1;
				return result;
			}
			else//case where a=0 b=0 and c non null
			{
				result.Error = 2;
				return result;
			}
		}
		else // case where a=0 b is non null 
		{
			if (poly.c != 0)//case where a=0 b is non null and c non null
			{
				result.x1 = -poly.c / poly.b;
				result.x2 = result.x1;
			}
			else //case where a=0 b is non null and c =0
			{
				result.x1 = 0;
				result.x2 = result.x1;
			}
		}
	}
	else if ((poly.b == 0) && (poly.c == 0))//case where a is non null but b =0 and c=0
	{
		result.x1 = 0;
		result.x2 = result.x1;

	}

	else //case where a is non null 
	{

		if (Delta(poly) < 0) //case when Discriminent is negative
		{
			result.Error = 3;
		}
		else if (Delta(poly) == 0)//case where Discriminent is null
		{
			result.x1 = (-poly.b) / (2 * poly.a);
			result.x2 = result.x1;
		}
		else //case where discriminent is positive
		{
			result.x1 = (-poly.b + sqrt(Delta(poly))) / (2 * poly.a);
			result.x2 = (-poly.b - sqrt(Delta(poly))) / (2 * poly.a);
		}
	}
	return result;
}

//Let us print our  answers either x1 and x2 or just x1 in case x1=x2
void DisplayResult(Answer result)
{

	if (result.Error == 0)
	{
		if (result.x1 != result.x2)
		{
			cout << "X1 = " << result.x1 << endl;
			cout << "X2 = " << result.x2 << endl;
		}
		else
		{
			cout << "X= " << result.x1 << endl;
		}
	}
	else
	{

		cout << "No solution in the set of real number"; //<< result.x1 << endl
	}
}
