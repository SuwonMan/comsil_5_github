#include "Array.h"

template<typename T>
class GrowableArray : public Array<T>
{
	public:
		GrowableArray(int i) : Array<T>(i){};
		T& operator[](int i)
		{
			T* tmp;
			int j;

			if(i>=0 && i < this->len)
			{
				return *((this->data) + i);
			}
			else if(i >= 0)
			{
				tmp = new T[(this->len) * 2];
				for(j = 0; j < this->len; j++)
					*(tmp + j) = *((this->data) + j);
				delete[] this->data;
				this->data = tmp;
				this->len *= 2;
				return *((this->data) + i);
			}
			else
			{
				cout<<"Array Bound Error!"<<endl;
			}
		}
};
				
						
