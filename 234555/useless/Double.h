#ifndef DOUBLE
#define DOUBLE

#include <string>
#include <iostream>
#include <sstream>
#include "Number.h"

using namespace std;

namespace W
{
	class Double : public Number
	{
        private:
            bool NaN;
            int recursiveNaN(string s);
        
        public:
            //Constructors
            Double();
            Double(double dd);
            Double(const Double &d);
            Double(const Integer &i);
            Double(const string &dd);

            //Operators
            Double operator + (const Double &d);
            Double operator - (const Double &d);
            Double operator * (const Double &d);
            Double operator / (const Double &d);

            Double operator + (double d);
            Double operator - (double d);
            Double operator * (double d);
            Double operator / (double d);

            Double &operator = (double d);
			Double &operator = (const Double &d);
            Double &operator = (const string &dd);

            bool operator == (double d);
			bool operator == (const Double &d);
			bool operator == (const string &dd);

            bool operator != (double d);
			bool operator != (const Double &d);
			bool operator != (const string &dd);

            //
            double toDouble() const;
			void isNaN(const string &dd) override;
    };
}

#endif
