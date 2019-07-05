#include <iostream>

class Base
{
public:
   int pub;
protected:
   int pro;
private:
   int pri;
   virtual void priFunc() = 0;
};

class PriBase : private Base
{
public:
   void access()
      {
         pro = 1;
      }
};

class PubPriBase : public PriBase
{
public:
   void accessPro()
   {
      // pro = 2; // can't compile for no access right (PriBase is private inherit)
   }
   void priFunc()
   {
      // TODO: eweiwux test virtual member function can be access(override) by child
      std::cout << "override a private function";
   }
};


int main()
{
   PubPriBase a;
   // a.pub = 3;
}
