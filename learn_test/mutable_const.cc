#include <iostream>

class Base
{
   mutable int a;
   const int b; // const don't need and can't to be mutable

public:
   Base(int v) : a(v), b(v){}

   int& changeValue(int v) const
   {
      a = v;
      return a;
   }

   const int& changeConstValue(int v) const
   {
      int& c = const_cast<int&>(b);
      c = v;
      return b;
   }
};

int main()
{
   Base b(1);
   std:: cout << b.changeValue(2) << std::endl << b.changeConstValue(3) << std::endl;

   int c(b.changeValue(4));
   std::cout << c << std::endl;
   // mutable lambda can change copy of c's value
   auto f = [=]() mutable
               {
                  c = 5;
                  std::cout << c << std::endl;
               };
   f();
   std::cout << c << std::endl; // but c is still not changed.
}
