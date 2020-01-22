#ifndef INTEGER
#define INTEGER

#include <string>
#include <iostream>
#include <sstream>
#include "Number.h"

using namespace std;

namespace W
{
    class Integer : public Number
    {
        private:
            void recursiveNaN(string s);

        public:
            //Constructors
            Integer();
            Integer(int ii);
            Integer(const Integer &i);
            Integer(const string &ii);

            //Operators
            Integer operator + (const Integer &i);
            Integer operator - (const Integer &i);
            Integer operator * (const Integer &i);
            Integer operator / (const Integer &i);

            Integer operator + (int i);
            Integer operator - (int i);
            Integer operator * (int i);
            Integer operator / (int i);

            Integer &operator = (const Integer &i);
            Integer &operator = (const string &ii);
            Integer &operator = (int i);

            bool operator == (int i);
			bool operator == (const Integer &i);
			bool operator == (const string &ii);
            
            bool operator != (int i);
			bool operator != (const Integer &i);
			bool operator != (const string &ii);

            //
			void isNaN(const string &ii) override;
			int toInt() const;
    };
}

#endif
