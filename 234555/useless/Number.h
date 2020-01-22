#ifndef NUMBER
#define NUMBER

#include <iostream>
#include <string>

using namespace std;

namespace W
{
    class Number
    {
        protected:
            string data;
			bool NaN;

        public:
			class NumberException
			{
			private:
				int code;
				string message;

			public:
				int getCode() const
				{
					return code;
				}
				string getMessage() const
				{
					return message;
				}
				NumberException()
				{
					message = "Unknown! /n";
					code = -1;
				}
				NumberException(const string &s)
				{
					message = s;
					code = -1;
				}
				NumberException(const string &s, int c)
				{
					message = s;
					code = c;
				}
			};

            //Constructors
            Number();
            Number(const string &str);
            Number(const char* s);

			//
			virtual ~Number();
			virtual string toString() const;
			virtual bool isNaN() const;

			virtual void isNaN(const string &s) {}
    };
}

#endif
