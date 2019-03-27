// this function test how to initial a template static member variable and inherit it
#include <set>
#include <iostream>


template<typename T>
class BaseContainer
{
public:

   virtual ~BaseContainer() {}


   virtual void print() = 0;

   static void printBase()
   {
      for (const auto& v : dataSetM)
      {
         std::cout << v << std::endl;
      }
   }

protected:
   static std::set<T> dataSetM;
};

class IntContainer : public BaseContainer<int>
{
  public:
   void print()
   {
      for (const auto& v : BaseContainer<int>::dataSetM)
      {
         std::cout << v << std::endl;
      }
   }
   static void setData(int value)
   {
      BaseContainer<int>::dataSetM.insert(value);
   }

};

class IntContainer1 : public BaseContainer<int>
{
  public:
   void print()
   {
      for (const auto& v : BaseContainer<int>::dataSetM)
      {
         std::cout << v << std::endl;
      }
   }
   static void setData(int value)
   {
      BaseContainer<int>::dataSetM.insert(value);
   }

};

class CharContainer : public BaseContainer<char>
{
  public:
   void print()
   {
   }
   static void setData(char value)
   {
      BaseContainer<char>::dataSetM.insert(value);
   }

};

template<class T>
std::set<T> BaseContainer<T>::dataSetM;

void setDataContainer()
{
   IntContainer::setData(1);
   IntContainer1::setData(2);
   CharContainer::setData('a');
}


int main()
{
   IntContainer a;
   setDataContainer();
   std::cout << "print IntContainer:\n";
   a.print();
   IntContainer1 b;
   std::cout << "print IntContainer1:\n";
   b.print();
   std::cout << "print BaseContainer:\n";
   BaseContainer<int>::printBase();
   std::cout << "print CharContainer:\n";
   BaseContainer<char>::printBase();

   // can't access as dataSetM is protected, but this method is avariable
   // std::cout << *(BaseContainer<int>::dataSetM.begin()) << std::endl;

}
