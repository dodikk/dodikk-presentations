#ifndef __LESS_H__
#define __LESS_H__

template<class T>
class LessThan
{
public:
	LessThan(const T& value) : 
		value_(value)
	{}

	bool operator(const T& item)
	{
		return (item < value_);
	}
	
private:
	T value_;
};

#endif //__LESS_H__

