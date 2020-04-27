#ifndef __ARRAY__
#define __ARRAY__

#include <cstdlib>
#include<iostream>
using namespace std;


template <typename T>
class Array{
	protected:
		T *data;
		int len;
	public:
			Array(int size)
			{
				if (size < 0)
				{
					cout << "Error: data size can't be negative integer." << endl;
				}
				else
				{
					data = new T [size];
					len = size;
				}
			};
			~Array()
			{
				delete[] data;
			}

			int length() const
			{
				return len;
			}

			T& operator[](int i);
			T operator[](int i)const;

			void print();
};

template <typename T>
T& Array<T>::operator[](int i)
{
	static T tmp;

	if (i >= 0 && i < len)
	{
		return *(data + i);
	}
	else
	{
		cout << "Array bound error!" << endl;
		return tmp;
	}
}

template <typename T>
T Array<T>::operator[](int i)const
{
	if (i >= 0 && i < len)
	{
		return *(data + i);
	}
	else
	{
		cout << "Array arror!" << endl;
		return 0;
	}
}
template <typename T>
void Array<T>::print()
{
	int i;
	cout << "[";
	for (i = 0; i < len; i++)
		cout << data[i] << " ";

	cout << "]" << endl;
}


#endif
