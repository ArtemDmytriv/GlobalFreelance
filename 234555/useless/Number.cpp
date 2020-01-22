#include "Number.h"

namespace W
{
	//Constructors

    Number::Number()
    {
        data = "0";
        NaN = false;
    }
    Number::Number(const string &str)
    {
        data = str; 
        NaN = false;
    }
    Number::Number(const char* s)
    {
        data = s;
        NaN = false;
    }

	//

	Number::~Number() 
	{

	}
	bool Number::isNaN() const 
	{
		return this->NaN;
	}
	string Number::toString() const
	{
		if (isNaN())
		{
			return "0";
		}
		return this->data; 
	}
}

