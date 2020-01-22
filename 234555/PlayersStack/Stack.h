#ifndef STACK
#define STACK

#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename W>
class Stack
{
	private:
		vector <W> data;

	public:
		void pop();
		void push(W const& elem);
		W peek() const;
		bool empty();
};

#endif
