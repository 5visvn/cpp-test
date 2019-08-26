#include <iostream>
#include <string>

using namespace std;

struct conf{
   int num;
   string attr;
   conf():num(1), attr("hi"){}

   conf(const conf & c):
      num(c.num),
      attr(c.attr)
   {}

};



class Singleton{
   Singleton():a(2){}
   virtual ~Singleton(){}
   static Singleton * instance;
   int a;
public:
   static Singleton * getInstance(){
      if (!instance){
         instance = new Singleton();
      }
      return instance;
   }

   void print(){
      conf c;
      auto l = [co=c, this](){
                  cout << co.attr << endl << a << endl;
               };
      auto l1 = std::move(l);
      l1();
   }
};

Singleton * Singleton::instance = nullptr;


int main(){
   Singleton::getInstance()->print();
}
