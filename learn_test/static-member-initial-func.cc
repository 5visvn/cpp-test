#include <iostream>
#include <ranges>
#include <numeric>
#include <string>
#include <algorithm>
#include <array>
#include <span>
#include <variant>

using namespace std;

#define show(x)     std::cout << #x << " : [" << x << "]" << std::endl;

template<size_t Index>
static constexpr std::array<char, Index> strFunc()
{
   std::array<char, Index> re;
   char c = '0';
   std::generate(re.begin(), re.end(), [&c](){return c++;});
   return re;
}

template<int Size>
struct myStr
{
   static constexpr auto k_Mystr = strFunc<Size>();
};

int main()
{
   myStr<5> str;
   for (int i = 0; i < 5; ++i)
   {
      show(str.k_Mystr[i]);
   }
}
