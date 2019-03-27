// this function test how parent's and child's class constructors  called. 
// and shows how to access parent's member variable
#include <iostream>

using namespace std;

template<typename T>
class parent
{
protected:
   int p_mem;
public:
   parent(int m) : p_mem(m) // for calling by construct of child
      {}
   parent() : p_mem(1)
      {}
};

template<typename T>
class child :public parent<T>
{
public:
   child() : parent<T>(2)
   {
   }

   child(int i) : parent<T>() // can't access p_mem right now.
   {
      // access p_mem by parent::<T> or this->
      parent<T>::p_mem = i; // can access p_mem because we have constructed parent with :parent<T>()
   }

   void printMem()
   {
      cout<< this->p_mem << endl;
   }
};

int main()
{
   child<int> c;
   c.printMem();
   child<int> d(5);
   d.printMem();
}
