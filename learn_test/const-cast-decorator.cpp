#include <iostream>

namespace lib
{

template<typename T>
inline T& constCast(const T& v)
{
    return const_cast<T&>(v);
}

};

void plus1(int& i)
{
    ++i;
    std::cout << i << std::endl;
}

int main()
{
    const int i = 9;
    plus1(lib::constCast(i));
}
