#include "Stack.h"
	
	template <typename W>
void Stack<W>::push(W const& elem)
{
    data.push_back(elem);
}

	template <typename W>
void Stack<W>::pop()
{
	if (!data.empty())
	{
		data.pop_back();
	}
}

	template <typename W>
W Stack<W>::peek() const
{
	if (!data.empty())
	{
		return data.back();
	}
	return NULL;
}

template<typename W>
bool Stack<W>::empty()
{
	return data.empty();
}
