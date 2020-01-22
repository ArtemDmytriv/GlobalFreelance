#include "Number.h"
#include "Integer.h"

namespace W
{
	//Constructors

	Integer::Integer() : Number("0")
	{

	}
    Integer::Integer(int ii) : Number(to_string(ii))
	{
		
	}
    Integer::Integer(const Integer &i) : Number(i.toString())
    {
        recursiveNaN(i.toString());
		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
    }
    Integer::Integer(const string &ii) : Number(ii)
    {
        recursiveNaN(ii);
		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
    }
    
    //Operators
    
    Integer Integer::operator + (const Integer &i)
    {
        int first = stoi(this->data);
        int second = stoi(i.toString());
        return Integer(first + second);
    }
    Integer Integer::operator - (const Integer &i)
    {
        int first = stoi(this->data);
        int second = stoi(i.toString());
        return Integer(first - second);
    }
    Integer Integer::operator * (const Integer &i)
    {
        int first = stoi(this->data);
        int second = stoi(i.toString());
        return Integer(first * second);
    }
    Integer Integer::operator / (const Integer &i)
    {
        int first = stoi(this->data);
        int second = stoi(i.toString());
        return Integer(first / second);
    } 

    Integer Integer::operator + (int i)
    {
        int first = stoi(this->data);
        int second = i;
        return Integer(first + second);
    }
    Integer Integer::operator - (int i)
    {
        int first = stoi(this->data);
        int second = i;
        return Integer(first - second);
    }
    Integer Integer::operator * (int i)
    {
        int first = stoi(this->data);
        int second = i;
        return Integer(first * second);
    }
    Integer Integer::operator / (int i)
    {
        int first = stoi(this->data);
        int second = i;
        return Integer(first / second);
    }

	Integer &Integer:: operator = (int i)
	{
		this->data = to_string(i);
		return *this;
	}
    Integer &Integer:: operator = (const Integer &i)
    {
        recursiveNaN(i.toString());

		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
		this->data = i.toString();
		return *this;
    }
    Integer &Integer::operator = (const string &ii)
    {
        recursiveNaN(ii);

		if (NaN)
		{
			string x = "Invalid";
			throw NumberException(x);
		}
        this->data = ii;
        return *this;
    }

    bool Integer::operator == (int i)
    {
        return stoi(this->data) == i;
    }
	bool Integer::operator == (const Integer &i)
    {
        return this->data == i.toString();
    }
	bool Integer::operator == (const string &ii)
	{
		isNaN(ii);

		if (NaN)
		{
			NaN = false;
			string x = "Invalid";
			throw NumberException(x);
		}
		return this->data == ii;
	}
    
	bool Integer::operator != (int i)
	{
		return stoi(this->data) != i;
	}
    bool Integer::operator != (const Integer &i)
    {
        return this->data != i.toString();
    }
	bool Integer::operator != (const string &ii)
	{
		isNaN(ii);

		if (NaN)
		{
			NaN = false;
			string x = "Invalid";
			throw NumberException(x);
		}
		return this->data != ii;
	}
    
    //
    
    void Integer::recursiveNaN(string s)
    {
        if (s.length() == 0)
        {
            this->NaN = false;
            return;
        }

        string s1;
        s1 = s.substr(0, s.length() - 1);
        recursiveNaN(s1);
        int curInd = s.length() - 1;

        if (!isdigit(s[curInd]))
        {
            this->NaN = true;
        }
    }
	void Integer::isNaN(const string &ii)
	{
		recursiveNaN(ii);
	}
	int Integer::toInt() const
	{
		return stoi(this->data);
	}
}
