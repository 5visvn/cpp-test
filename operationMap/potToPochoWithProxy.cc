// @wisan
// This program implement a key-operation map that using map to store function's pointer.
// it has:
//    three key's data types: int, string, unsignedo
//    two pots: potA has two keys, potB has three keys
//    two pochos with the same keys of pots.
//    three operations of pots and pochos: has, get, put
//    two DBS which is a bridge betweens pot and pocho
// main(): test functions of DBS operations by key string

#include <functional>

#include <iostream>
#include <string>
#include <map>

using namespace std;

class PotA
{
   int key1;
   string key2;
public:
   PotA():key1(101), key2("pot A, key 2\n"){}

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
   unsigned key3;
public:
   PotB():key1("pot B, key 1\n"), key2(0), key3(203u){}

   bool key1_has(){return !key1.empty();}
   string key1_get(){return key1;}
   void key1_put(string &v){key1 = v;}

   bool key2_has(){return key2 != 0;}
   int key2_get(){return key2;}
   void key2_put(int v){key2 = v;}

   bool key3_has(){return key3 != 0;}
   unsigned key3_get(){return key3;}
   void key3_put(unsigned v){key3 = v;}
};

class PochoA
{
   int key1;
   string key2;
public:
   PochoA():key1(0), key2(""){}

   bool key1_isSet(){return key1 != 0;}
   int key1_get(){return key1;}
   void key1_put(int value){key1 = value;}

   bool key2_isSet(){return !key2.empty();}
   string key2_get(){return key2;}
   void key2_put(string &value){key2 = value;}
};

class PochoB
{
   string key1;
   int key2;
   unsigned key3;
public:
   PochoB():key1(""), key2(0), key3(0u){}

   bool key1_isSet(){return !key1.empty();}
   string key1_get(){return key1;}
   void key1_put(string &value){key1 = value;}

   bool key2_isSet(){return key2 != 0;}
   int key2_get(){return key2;}
   void key2_put(int value){key2 = value;}

   bool key3_isSet(){return key3 != 0;}
   unsigned key3_get(){return key3;}
   void key3_put(unsigned value){key3 = value;}
};

template<typename P, typename Pocho>
class Operation
{
   std::function<bool (P*)> potHas;
   std::function<bool (Pocho*)> pochoHas;
public:
   virtual bool has(const P* pot)
   {
      return potHas(pot);
   }
   virtual bool has(const Pocho* pocho)
   {
      return pochoHas(pocho);
   }
   // get one key's data from pot to pocho
   virtual void getDataFromPot(const P* pot, Pocho* pocho);
   // put one key's data from pocho to pot
   virtual void putDataIntoPot(P* pot, const Pocho* pocho);
   // match this key with condition
   virtual bool match(const P* pot, const string& condition);
   // virtual void clear();
};

template<typename P, typename Pocho>
class OperationInt
{
   std::function<int (P*)> potGetter;
   std::function<int (Pocho*)> pochoGetter;

   std::function<void (P*, int)> potSetter;
   std::function<void (Pocho*, int)> pochoSetter;

public:
   OperationInt(std::function<bool (P*)> th, std::function<int (P*)> tg, std::function<void (P*, int)> ts,
                std::function<bool (Pocho*)> oh, std::function<int (P*)> og, std::function<void (P*, int)> os)
      : potHas(th), potGetter(tg), potSetter(ts), pochoHas(oh), pochoGetter(og), pochoSetter(os){}

   virtual void getDataFromPot(const P* pot, Pocho* pocho) override
   {
      if(has(pot))
         pochoSetter(pocho, potGetter(pot));
   }
   virtual void putDataIntoPot(P* pot, const Pocho* pocho) override
   {
      if(has(pocho))
         potSetter(pot, pochoGetter(pocho));
   }
   virtual bool match(const P* pot, const string& condition) override
   {
      return condition == std::to_string(potGetter(pot));

   }
};

template<typename P, typename Pocho>
class OperationString
{
   std::function<string (P*)> potGetter;
   std::function<string (Pocho*)> pochoGetter;

   std::function<void (P*, string)> potSetter;
   std::function<void (Pocho*, string)> pochoSetter;

public:
   OperationString(std::function<bool (P*)> th, std::function<string (P*)> tg, std::function<void (P*, string)> ts,
                   std::function<bool (Pocho*)> oh, std::function<string (P*)> og, std::function<void (P*, string)> os)
      : potHas(th), potGetter(tg), potSetter(ts), pochoHas(oh), pochoGetter(og), pochoSetter(os){}

   virtual void getDataFromPot(const P* pot, Pocho* pocho) override
      {
         if(has(pot))
            pochoSetter(pocho, potGetter(pot));
      }
   virtual void putDataIntoPot(P* pot, const Pocho* pocho) override
      {
         if(has(pocho))
            potSetter(pot, pochoGetter(pocho));
      }
   virtual bool match(const P* pot, const string& condition) override
      {
         return condition == (potGetter(pot));
      }
};

template<typename P, typename Pocho>
class OperationUnsigned
{
   std::function<unsigned (P*)> potGetter;
   std::function<unsigned (Pocho*)> pochoGetter;

   std::function<void (P*, unsigned)> potSetter;
   std::function<void (Pocho*, unsigned)> pochoSetter;

public:
   OperationUnsigned(std::function<bool (P*)> th, std::function<unsigned (P*)> tg, std::function<void (P*, unsigned)> ts,
                     std::function<bool (Pocho*)> oh, std::function<unsigned (P*)> og, std::function<void (P*, unsigned)> os)
      : potHas(th), potGetter(tg), potSetter(ts), pochoHas(oh), pochoGetter(og), pochoSetter(os){}

   virtual void getDataFromPot(const P* pot, Pocho* pocho) override
      {
         if(has(pot))
            pochoSetter(pocho, potGetter(pot));
      }
   virtual void putDataIntoPot(P* pot, const Pocho* pocho) override
      {
         if(has(pocho))
            potSetter(pot, pochoGetter(pocho));
      }
   virtual bool match(const P* pot, const string& condition) override
      {
         return condition == std::to_string(potGetter(pot));

      }
};

template<typename P, typename Pocho>
struct OperationProxy
{
   Operation* operation;
   // int
   Proxy(std::function<bool (P*)> th, std::function<int (P*)> tg, std::function<void (P*, int)> ts,
         std::function<bool (Pocho*)> oh, std::function<int (P*)> og, std::function<void (P*, int)> os)
      {
         operation = new OperationInt<P, Pocho>(th, tg, ts, oh, og, os);
      }
   // string
   Proxy(std::function<bool (P*)> th, std::function<string (P*)> tg, std::function<void (P*, string)> ts,
         std::function<bool (Pocho*)> oh, std::function<string (P*)> og, std::function<void (P*, string)> os)
      {
         operation = new OperationString<P, Pocho>(th, tg, ts, oh, og, os);
      }
   // unsigned
Proxy(std::function<bool (P*)> th, std::function<unsigned (P*)> tg, std::function<void (P*, unsigned)> ts,
      std::function<bool (Pocho*)> oh, std::function<unsigned (P*)> og, std::function<void (P*, unsigned)> os)
      {
         operation = new OperationUnsigned(th, tg, ts, oh, og, os);
      }
};

template<typename P, typename Pocho>
class Reflection
{
protected:
   vector<PotA> potsA;
   map<string, OperationProxy<P, Pocho>*> keyOperationMap;
   virtual bool checkConditions(const P* pot, const map<string, string> &conditions)
   {
      for(auto &c : conditions)
      {
         auto it = keyOperationMap.find(c.first);
         // if validate key already, don't need to check find.
         if(it->second.operation->match(pot, c.second))
            continue;
         return false;
      }
      return true;
   }
   virtual bool validateKey(const string& inKey)
   {
      return keyOperationMap.find(key) != keyOperationMap.end();
   }
   virtual void getDataFromPot(const P* pot, Pocho* pocho, string& key)
   {
      auto it = keyOperationMap.find(key);
      if(it != keyOperationMap.end())
      {
         if(it->second.operation->has(pot))
            it->second.operation->getDataFromPot(pot, pocho);
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
      }
   }
   virtual void putDataToPot(P* pot, const Pocho* pocho, string& key)
   {
      auto it = keyOperationMap.find(key);
      if(it != keyOperationMap.end())
      {
         if(it->second.operation->has(pocho))
            it->second.operation->putDataIntoPot(pot, pocho);
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
      }
   }

public:
   virtual void getDataFromPot(const P* pot, Pocho* pocho, vector<string> keys)
   {
      for(auto &key : keys)
      {
         getDataFromPot(pot, pocho, key);
      }
   }
   virtual void getDataFromPot(const P* pot, Pocho* pocho)
   {
      for(auto &it : keyOperationMap)
      {
         if(it->second.operation->has(pot))
            it->second.operation->getDataFromPot(pot, pocho);
      }
   }

   virtual void putDataToPot(P* pot, const Pocho* pocho, const vector<string> &keys)
   {
      for(auto &key : keys)
      {
         putDataToPot(pot, pocho, key);
      }
   }
   virtual void putDataToPot(P* pot, const Pocho* pocho)
   {
      for(auto &it : keyOperationMap)
      {
         if(it->second.operation->has(pocho))
            it->second.operation->putDataIntoPot(pot, pocho);
      }
   }

   virtual void getDataFromPotByCondition(P* potItr, vector<Pocho>& pochos, const map<string, string> &conditions, const vector<string> &selectKeys)
   {
      // step1: check keys validate
      bool valid = true;
      for(auto & c : conditions)
      {
         if(!validateKey(c.first))
            valid = false;
      }
      for(auto &key : selectKeys)
      {
         if(!validateKey(key))
            valid = false;
      }
      if(!valid)
      {
         cout << "key invalid" << endl << endl;
         // trace debug
         return;
      }

      // step2: iterate pots and check conditions
      //potItr.nextReopenxxxxx();
      //if(poItr != nullptr && state == good)
      {
         if(checkConditions(potItr, conditions))
         {
            Pocho *pocho = new pocho;
            // step3: getdata
            getDataFromPot(potItr, pocho, selectKeys);
            pochos.emplace_back(*pocho);
         }
      }
   }

};

class ReflectionA : public Reflection<PotA, PochoA>
{
public:
   ReflectionA();
};

ReflectionA::ReflectionA()
{
   keyOperationMap = {
      {"key1", new OperationProxy<PotA, PochoA>(
            std::mem_fn(&PoPotA::key1_has),
            std::mem_fn(&PoPotA::key1_get),
            std::mem_fn(&PoPotA::key1_put),
            std::mem_fn(&PoPochoA::key1_isSet),
            std::mem_fn(&PoPochoA::key1_get),
            std::mem_fn(&PoPochoA::key1_put)
            )},

      {"key2", new OperationProxy<PotA, PochoA>(
            std::mem_fn(&PoPotA::key2_has),
            std::mem_fn(&PoPotA::key2_get),
            std::mem_fn(&PoPotA::key2_put),
            std::mem_fn(&PoPochoA::key2_isSet),
            std::mem_fn(&PoPochoA::key2_get),
            std::mem_fn(&PoPochoA::key2_put)
            )}

   };
}

class ReflectionB : public Reflection<PotB, PochoB>
{
public:
   ReflectionB();
};

ReflectionB::ReflectionB()
{
   keyOperationMap = {
      {"key1", OperationProxy<PotB, PochoB>(
            std::mem_fn(&PoPotB::key1_has),
            std::mem_fn(&PoPotB::key1_get),
            std::mem_fn(&PoPotB::key1_put),
            std::mem_fn(&PoPochoB::key1_isSet),
            std::mem_fn(&PoPochoB::key1_get),
            std::mem_fn(&PoPochoB::key1_put)
            )},

      {"key2", OperationProxy<PotB, PochoB>(
            std::mem_fn(&PoPotB::key2_has),
            std::mem_fn(&PoPotB::key2_get),
            std::mem_fn(&PoPotB::key2_put),
            std::mem_fn(&PoPochoB::key2_isSet),
            std::mem_fn(&PoPochoB::key2_get),
            std::mem_fn(&PoPochoB::key2_put)
            )},

      {"key3", OperationProxy<PotB, PochoB>(
            std::mem_fn(&PoPotB::key3_has),
            std::mem_fn(&PoPotB::key3_get),
            std::mem_fn(&PoPotB::key3_put),
            std::mem_fn(&PoPochoB::key3_isSet),
            std::mem_fn(&PoPochoB::key3_get),
            std::mem_fn(&PoPochoB::key3_put)
            )}
   };
}

int main()
{
   // Don't operate pot directly!
   // Operate only pocho, and then copy to pot by dbs.
   string key1 = "key1";
   string key2 = "key2";
   string key3 = "key3";

   PotA potA;
   ReflectionA dbsA;
   PochoA pochoA;
   cout<< "*** pot A:" << endl << endl;
   cout << "*step1: check pochoA is empty at the begining." << endl << endl;
   if(pochoA.key1_isSet() || pochoA.key2_isSet())
   {
      cout << "pochoA has value" << endl << endl;
   }
   else
   {
      cout << "pochoA has no value" << endl << endl;
   }

   cout << "*step2: get values from potA to pochoA" << endl << endl;
   dbsA.getDataFromPot(&potA, &pochoA, key1);
   dbsA.getDataFromPot(&potA, &pochoA, key2);
   dbsA.getDataFromPot(&potA, &pochoA, key3);

   cout << "*step3: output values of pochoA" << endl << endl
        << "key1: " << pochoA.key1_get() << endl
        << "key2: " << pochoA.key2_get() << endl << endl;

   string newStr = "***new value1***";
   cout << "*step4: set key2 of pochoA with string: " << newStr << ", and copy to potA." << endl << endl;
   pochoA.key2_put(newStr);
   cout << "now pochoA key2 value is: " << pochoA.key2_get() << endl <<endl;
   dbsA.putDataToPot(&potA, &pochoA, key1);
   dbsA.putDataToPot(&potA, &pochoA, key2);
   dbsA.putDataToPot(&potA, &pochoA, key3);

   newStr = "***new value2***";
   cout << "*step5: set key2 of pochoA with string: " << newStr << endl << endl;
   pochoA.key2_put(newStr);
   cout << "now pochoA key2 value is: " << pochoA.key2_get() << endl <<endl;

   cout << "*step6: get values from potA to pochoA" << endl << endl;
   dbsA.getDataFromPot(&potA, &pochoA, key1);
   dbsA.getDataFromPot(&potA, &pochoA, key2);
   dbsA.getDataFromPot(&potA, &pochoA, key3);

   cout << "*step7: output values of pochoA" << endl << endl
        << "key1: " << pochoA.key1_get() << endl
        << "key2: " << pochoA.key2_get() << endl << endl;


   PotB pB;
   ReflectionB dbsB;
   cout<< "*** pot B:" << endl << endl;

}
