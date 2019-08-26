#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

using namespace std;

class B
{
public:
   string name;
   explicit B(const string& n):name(n){}
   ~B(){
      cout << name << "destruct\n";
   }
};

class A
{
public:
   shared_ptr<B> b1;
   shared_ptr<B> b2;
   shared_ptr<B> b3;

   A() {
      b1 = make_shared<B>("B1");
      b2 = make_shared<B>("B2");
      b3 = make_shared<B>("B3");
   }
   ~A(){
      cout << " start A destruct\n";
      std::this_thread::sleep_for(std::chrono::seconds(1));
      cout << this->b1->name << endl;

      cout<< " end A destruct\n";
   }
};

int main(){
   A a;
   return 0;
}
