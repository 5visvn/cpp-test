#include <iostream>
#include <string>

using namespace std;

int main()
{
   string input = "imeisv-19290012313";
   auto index = input.find_first_of('-');
   cout << input.substr(index + 1, input.size());
}
