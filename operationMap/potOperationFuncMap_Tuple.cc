#include <iostream>
#include <string>
#include <map>
#include <tuple>

using namespace std;

class PotA
{
   int key1;
   string key2;
public:
   PotA():key1(101), key2("string of pot 1, key 2\n"){}

   bool key1_has(){return key1 != 0;}
   int key1_get(){return key1;}
   void key1_put(int v){key1 = v;}

   bool key2_has(){return !key2.empty();}
   string key2_get(){return key2;}
   void key2_put(string& v){key2 = v;}
};

class PotB
{
   string key1;
   int key2;
public:
   PotB():key1("string of pot 2, key 1\n"), key2(202){}

   bool key1_has(){return key1.empty();}
   string key1_get(){return key1;}
   void key1_put(string &v){key1 = v;}

   bool key2_has(){return key2 != 0;}
   int key2_get(){return key2;}
   void key2_put(int v){key2 = v;}
};

template<typename P>
class Dbs
{
protected:
   // has
   typedef bool (P::*Has)();
   // get
   typedef int (P::*GetInt)();
   typedef string (P::*GetStr)();
   typedef tuple<GetInt, GetStr> TupGet_i_s; // all get methods

   // put
   typedef void (P::*PutInt)(int);
   typedef void (P::*PutStr)(string&);
   typedef tuple<PutInt, PutStr> TupPut_i_s; // all put methods

   typedef tuple<Has, // has
                 TupGet_i_s,  // get, maybe more types
                 TupPut_i_s  // put
                 > TupOperations;
   typedef map<string, TupOperations> OperationMap;
   OperationMap operationMap;
public:
   void printKey(P* pot, string& key)
   {
      auto it = operationMap.find(key);
      if(it != operationMap.end())
      {
         // has
         auto oprations = it->second;
         Has &has = std::get<0>(oprations);
         // get
         auto gets = get<1>(oprations);
         if(get<0>(gets) != nullptr) // get int
         {
            int a = (pot->*(get<0>(gets)))();
            cout << "searching key with string : " << key << endl
                 << "this key type is : int" << endl
                 << "and output is : "<< a << endl << endl;
         }
         else if(get<1>(gets) != nullptr) // get str
         {
            string s = (pot->*(get<1>(gets)))();
            cout << "searching key with string : " << key << endl
                 << "this key type is : string" << endl
                 << "and output is : "<< s << endl << endl;
         }
      }
   }
};

class DbsA : public Dbs<PotA>
{
public:
   DbsA();
};

DbsA::DbsA()
{
   operationMap.insert( pair<string, TupOperations>(
                           "key1", make_tuple(
                              &PotA::key1_has,
                              TupGet_i_s(make_tuple(&PotA::key1_get, nullptr)),
                              TupPut_i_s(make_tuple(&PotA::key1_put, nullptr))
                              )));

   operationMap.insert( pair<string, TupOperations>(
                           "key2", make_tuple(
                              &PotA::key2_has,
                              TupGet_i_s(make_tuple(nullptr, &PotA::key2_get)),
                              TupPut_i_s(make_tuple(nullptr, &PotA::key2_put))
                              )));
}

class DbsB : public Dbs<PotB>
{
public:
   DbsB();
};

DbsB::DbsB()
{
   operationMap.insert( pair<string, TupOperations>(
                           "key1", make_tuple(
                              &PotB::key1_has,
                              TupGet_i_s(make_tuple(nullptr, &PotB::key1_get)),
                              TupPut_i_s(make_tuple(nullptr, &PotB::key1_put))
                              )));

   operationMap.insert( pair<string, TupOperations>(
                           "key2", make_tuple(
                              &PotB::key2_has,
                              TupGet_i_s(make_tuple(&PotB::key2_get, nullptr)),
                              TupPut_i_s(make_tuple(&PotB::key2_put, nullptr))
                              )));
}

int main()
{
   PotA pA;
   DbsA pIfA;
   cout<< "pot 1:" << endl;
   string key = "key1";
   pIfA.printKey(&pA, key);
   key = "key2";
   pIfA.printKey(&pA, key);


   PotB pB;
   DbsB pIfB;
   cout << "pot 2:" << endl;
   key = "key1";
   pIfB.printKey(&pB, key);
   key = "key2";
   pIfB.printKey(&pB, key);
}
