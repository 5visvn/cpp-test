#include <iostream>
#include <string>
#include <vector>
#include <numeric>

#define show(x) std::cout << #x" is : " << x << std::endl;
#define show1(x, state) std::cout << state << " "#x" is : " << str << std::endl;
#define ranges(algrithmn, container, statements...) algrithmn(container.begin(), container.end(), statements)

int main()
{
    int i = 42;
    int&& j = std::move(i);
    j = 23;
    show(i);
    show(j);

    std::vector<std::string> vv;
    std::string str("111");
    vv.push_back(str);
    show1(str, "push");
    vv.push_back(std::move(str));
    show1(str, "move");
    std::string str2("222");
    vv.emplace_back(str2);
    show1(str2, "emplace");

    std::cout << ranges(std::accumulate, vv, std::string("vv: "), [](const std::string& re, const std::string& item){
        return re + " " + item;
    }) << std::endl;
}
