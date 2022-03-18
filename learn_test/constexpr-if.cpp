#include <iostream>

enum class color : uint16_t
{
    green =0,
    blue,
    red
};

struct base
{
    static constexpr auto colorFeature = false;
};

struct smug : public base
{
    static constexpr auto colorFeature = true;

    static constexpr color c = color::green;
};
struct smub : public base
{
    static constexpr color c = color::blue;
};

template<typename smu>
struct printor
{

void print()
{
    if constexpr ((smu::c == color::green) && smu::colorFeature)
        std::cout << "green" << std::endl;
    else
    {
        std::cout << "unknown" << std::endl;
    }
}

};

int main()
{
    printor<smug> p;
    p.print();
    printor<smub> pb;
    pb.print();
}
