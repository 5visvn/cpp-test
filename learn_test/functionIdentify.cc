#include <iostream>

using namespace std;

int test()
{
   return 1;
}

// functions were not identified by return type
// char test()
// {
//    return 'a';
// }


int main()
{
   cout << test();
   return 0;
}
