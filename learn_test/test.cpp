#include <iostream>
#include <string>
#include <tuple>
#include <ranges>
#include <algorithm>
#include <numeric>
#include <variant>

#define show(x)     std::cout << #x << " : [" << x << "]" << std::endl;
#define shows(x)     std::cout << #x << " : [" << std::to_string(x) << "]" << std::endl;


int main()
{
    std::variant<int, float> v{12};

    if(auto pval = std::get_if<int>(&v))
      std::cout << "variant value: " << *pval << '\n';
    else
      std::cout << "failed to get value!" << '\n';

}
