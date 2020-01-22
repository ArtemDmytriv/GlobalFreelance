#include "Number.h"
#include "Integer.h"
#include "Double.h"

namespace W
{
	//Constructors

	Double::Double() : Number("0") {}
	Double::Double(double d) : Number(to_string(d)) {}
    Double::Double(const Integer &i) : Number(i.toString())
    {
        isNaN(i.toString());
		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
    }
    Double::Double(const Double &d) : Number(d.toString())
    {
        isNaN(d.toString());
		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
    }
    Double::Double(const string &dd) : Number(dd)
    {
        isNaN(dd);
		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
    }

    //Operators
    
    Double Double::operator + (const Double &d)
    {
        double first = stod(this->data);
        double second = stod(d.toString());
        return Double(first + second);
    }
    Double Double::operator - (const Double &d)
    {
        double first = stod(this->data);
        double second = stod(d.toString());
        return Double(first - second);
    }
    Double Double::operator * (const Double &d)
    {
        double first = stod(this->data);
        double second = stod(d.toString());
        return Double(first * second);
    }
    Double Double::operator / (const Double &d)
    {
        double first = stod(this->data);
        double second = stod(d.toString());
        return Double(first / second);
    }

    Double Double::operator + (double d)
    {
        double first = stod(this->data);
        double second = d;
        return Double(first + second);
    }
    Double Double::operator - (double d)
    {
        double first = stod(this->data);
        double second = d;
        return Double(first - second);
    }
    Double Double::operator * (double d)
    {
        double first = stod(this->data);
        double second = d;
        return Double(first * second);
    }
    Double Double::operator / (double d)
    {
        double first = stod(this->data);
        double second = d;
        return Double(first / second);
    }

    Double &Double::operator = (double d)
    {
        this->data = to_string(d);
        return *this;
    }
	Double &Double::operator = (const Double &d)
	{
		isNaN(d.toString());

		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
		this->data = d.toString();
		return *this;
	}
	Double &Double::operator = (const string &dd)
	{
		isNaN(dd);

		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
		this->data = dd;
		return *this;
	}

    bool Double::operator == (double d)
    {
        return stod(this->data) == d;
    }    
	bool Double::operator == (const Double &d)
    {
        return this->data == d.toString();
    }
	bool Double::operator == (const string &dd)
	{
		isNaN(dd);

		if (NaN)
		{
			NaN = false;
			string x = "Invalid";
			throw NumberException(x);
		}
		return this->data == dd;
	}

    bool Double::operator != (double d)
    {
        return stod(this->data) != d;
    }    
	bool Double::operator != (const Double &d)
    {
        return this->data != d.toString();
    }
	bool Double::operator != (const string &dd)
	{
		isNaN(dd);

		if (NaN)
		{
			NaN = false;
			string x = "Invalid";
			throw NumberException(x);
		}
		return this->data != dd;
	}
    
    //
    
    int Double::recursiveNaN(string s)
    {
        if (s.length() == 0)
        {
            this->NaN = false;
            return 0;
        }

        string s1;
        s1 = s.substr(0, s.length() - 1);
        int pnum = recursiveNaN(s1);
        int curInd = s.length() - 1;

        if (s[curInd] == '.')
        {
            pnum++;
        }

        if ((!isdigit(s[curInd]) && s[curInd] != '.') || (pnum > 1))
        {
            this->NaN = true;
        }
        return pnum;
    }
	void Double::isNaN(const string &dd)
	{
		recursiveNaN(dd);
	}
	double Double::toDouble() const
	{
		return stod(this->data);
	}
}
