#include <iostream>
#include <memory>

using namespace std;

void testPtr(int*& p)
{
   unique_ptr<int> up(new int(1));
   p = &*up;
   cout << "p in function is: " << *p << endl;
}

void testUPtr(unique_ptr<int>& np)
{
   int* p = &*np;
   cout << "np in function is: " << *np << endl;
}

int main()
{
   int i = 2;
   int* p = &i;
   testPtr(p);
   cout << "p out function is: " << *p << endl;

   unique_ptr<int> np(new int(3));
   testUPtr(np);
   cout << "np out function is: " << *np << endl;

}
