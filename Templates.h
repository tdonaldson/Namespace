// Tyler R. Donaldson
// tylerdonaldson@hotmail.com
// 4/9/2012
// Definition of necessary templates for odd functions.
//*****************************************************
// Functionality:
//		1. Input Validation - Added on 4/9/2012
//*****************************************************
#ifndef TEMPLATES_H
#define TEMPLATE_H

#include <limits>
using std::numeric_limits;
using std::max;
using std::streamsize;

namespace Donaldson
{
	// Template input validation function.
	// Accepts the value as a reference parameter.
	// Accepts the lowest and highest values the can be 
	// input without telling the user to enter a different value.
	template<class T>
	T validation(T &value, T low, T high)
	{	
		bool failed;

		do
		{
			cin.clear();
			if(cin >> value && (value >= low && value <= high))
				failed = false;

			else
			{
				failed = true;		
				cout << "New choice please: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

		}while(failed == true);
		return value;
	}
}
#endif