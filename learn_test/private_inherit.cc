class Base
{
public:
   int pub;
protected:
   int pro;
private:
   int pri;
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
         // pro = 2; // can't compile for no access right
      }
};


int main()
{
   PubPriBase a;
   // a.pub = 3;
}
