#include <iostream>
#include <type_traits>

enum class type : uint8_t
{
    r = 0,
    b,
    g
};

struct red {
    void f()
    {
        std::cout << "red" << std::endl;
    }
};

struct blue
{
    void f()
    {
        std::cout << "blue" << std::endl;
    }
};

struct green
{
    void f()
    {
        std::cout << "green" << std::endl;
    }
};

template <type t>
struct proxy
{
    // using color = typename std::conditional<t == type::r, red, blue>::type;
    using color = std::conditional_t<t == type::r, red,
                  std::conditional_t<t == type::b, blue, green>>; // C++ 14
};


template <type t>
struct enable_proxy
{
    // using color = typename std::enable_if<t == type::r, red>::type;
    // using color = typename std::enable_if<t == type::b, blue>::type;
    using color = std::enable_if_t<t == type::r, red>; // C++ 14
    // TODO: consider how to fix re-declaration of color
    // using color = std::enable_if_t<t == type::b, blue>; // C++ 14
};


int main()
{
    proxy<type::g>::color c;
    c.f();
    // enable_proxy<type::b>::color d;
    // d.f();
}
