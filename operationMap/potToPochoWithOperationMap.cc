// @wisan
// This program implement a key-operation map that using map to store function's pointer.
// it has:
//    three key's data types: int, string, unsigned into
//    two pots: potA has two keys, potB has three keys
//    two pochos with the same keys of pots.
//    three operations of pots and pochos: has, get, put
//    two DBS which is a bridge betweens pot and pocho
// main(): test functions of DBS operations by key string

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
   unsigned int key3;
public:
   PotB():key1("pot B, key 1\n"), key2(0), key3(203u){}

   bool key1_has(){return !key1.empty();}
   string key1_get(){return key1;}
   void key1_put(string &v){key1 = v;}

   bool key2_has(){return key2 != 0;}
   int key2_get(){return key2;}
   void key2_put(int v){key2 = v;}

   bool key3_has(){return key3 != 0;}
   unsigned int key3_get(){return key3;}
   void key3_put(unsigned int v){key3 = v;}
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
   unsigned int key3;
public:
   PochoB():key1(""), key2(0), key3(0u){}

   bool key1_isSet(){return !key1.empty();}
   string key1_get(){return key1;}
   void key1_put(string &value){key1 = value;}

   bool key2_isSet(){return key2 != 0;}
   int key2_get(){return key2;}
   void key2_put(int value){key2 = value;}

   bool key3_isSet(){return key3 != 0;}
   unsigned int key3_get(){return key3;}
   void key3_put(unsigned int value){key3 = value;}
};

template<typename P, typename Pocho>
class Reflection
{
protected:
   enum KeyType{INT, STRING, UNSIGNED};
   struct Operations
   {
      // has
      typedef bool (P::*HasPot)();
      HasPot hasPot;
      typedef bool (Pocho::*HasPocho)();
      HasPocho hasPocho;

      // get && put
      // int
      typedef int (P::*GetPotInt)();
      typedef void (P::*PutPotInt)(int);
      typedef int (Pocho::*GetPochoInt)();
      typedef void (Pocho::*PutPochoInt)(int);
      GetPotInt getPotInt;
      PutPotInt putPotInt;
      GetPochoInt getPochoInt;
      PutPochoInt putPochoInt;
      // string
      typedef string (P::*GetPotStr)();
      typedef void (P::*PutPotStr)(string&);
      typedef string (Pocho::*GetPochoStr)();
      typedef void (Pocho::*PutPochoStr)(string&);
      GetPotStr getPotStr;
      PutPotStr putPotStr;
      GetPochoStr getPochoStr;
      PutPochoStr putPochoStr;
      // unsigned int
      typedef unsigned int (P::*GetPotUns)();
      typedef void (P::*PutPotUns)(unsigned int);
      typedef unsigned int (Pocho::*GetPochoUns)();
      typedef void (Pocho::*PutPochoUns)(unsigned int);
      GetPotUns getPotUns;
      PutPotUns putPotUns;
      GetPochoUns getPochoUns;
      PutPochoUns putPochoUns;

      KeyType type;

      explicit Operations(HasPot ht, GetPotInt gt, PutPotInt pt, HasPocho ho, GetPochoInt go, PutPochoInt po)
                     :hasPot(ht), getPotInt(gt), putPotInt(pt), hasPocho(ho), getPochoInt(go), putPochoInt(po)
                     {type = KeyType::INT;}
      explicit Operations(HasPot ht, GetPotStr gt, PutPotStr pt, HasPocho ho, GetPochoStr go, PutPochoStr po)
                     :hasPot(ht), getPotStr(gt), putPotStr(pt), hasPocho(ho), getPochoStr(go), putPochoStr(po)
                     {type = KeyType::STRING;}
      explicit Operations(HasPot ht, GetPotUns gt, PutPotUns pt, HasPocho ho, GetPochoUns go, PutPochoUns po)
                     :hasPot(ht), getPotUns(gt), putPotUns(pt), hasPocho(ho), getPochoUns(go), putPochoUns(po)
                     {type = KeyType::UNSIGNED;}
   };
   map<string, Operations> keyOperationsMap;

   virtual void getDataFromPot(const P* pot, Pocho* pocho, string& key)
   {
      auto it = keyOperationsMap.find(key);
      if(it != keyOperationsMap.end())
      {
         // has
         Operations &operations = it->second;
         bool hasKey = (pot->*(operations.hasPot))();
         if(!hasKey)
         {
            cout << "ERROR : this pot's key has no value: " << key << endl << endl;
            return;
         }

         cout << "searching key in pot : " << key << endl;
         switch(operations.type)
         {
         case KeyType::INT :
         {
            int value = (pot->*(operations.getPotInt))();
            (pocho->*(operations.putPochoInt))(value);
            cout << "key's type is : int" << endl
                 << " and copied to pocho."<< endl << endl;
            break;
         }
         case KeyType::STRING:
         {
            auto value = (pot->*(operations.getPotStr))();
            (pocho->*(operations.putPochoStr))(value);
            cout << "key's type is : string" << endl
                 << " and copied to pocho."<< endl << endl;
            break;
         }
         case KeyType::UNSIGNED:
         {
            auto value = (pot->*(operations.getPotUns))();
            (pocho->*(operations.putPochoUns))(value);
            cout << "key's type is : unsigned int" << endl
                 << " and copied to pocho."<< endl << endl;
            break;
         }
         }
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
      }
   }

   virtual void putDataToPot(P* pot, const Pocho* pocho, string& key)
   {
      auto it = keyOperationsMap.find(key);
      if(it != keyOperationsMap.end())
      {
         auto &operations = it->second;
         bool hasKey = (pocho->*(operations.hasPocho))();
         if(!hasKey)
         {
            cout << "ERROR : this pocho's key has no value: " << key << endl << endl;
            return;
         }

         cout << "searching key in pocho: " << key << endl;
         switch(operations.type)
         {
         case KeyType::INT :
         {
            auto value = (pocho->*(operations.getPochoInt))();
            (pot->*(operations.putPotInt))(value);
            cout << "key's type is : int" << endl
                 << " and copied to pot."<< endl;
            break;
         }
         case KeyType::STRING:
         {
            auto value = (pocho->*(operations.getPochoStr))();
            (pot->*(operations.putPotStr))(value);
            cout << "key's type is : string" << endl
                 << " and copied to pot."<< endl;
            break;
         }
         case KeyType::UNSIGNED:
         {
            (pot->*(operations.putPotUns))((pocho->*(operations.getPochoInt))());
            cout << "key's type is : unsigned int" << endl
                 << " and copied to pot."<< endl;
            break;
         }
         }
         cout << endl;
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
      }

   }

   virtual bool validateKey(const string& inKey)
   {
      return keyOperationsMap.find(key) != keyOperationsMap.end();
   }

   virtual bool checkConditions(const P* pot, const map<string, string> &conditions)
   {
      for(auto &c : conditions)
      {
         auto it = keyOperationMap.find()
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
   keyOperationsMap.insert(pair<string, Operations>("key1",
      Operations(&PotA::key1_has, &PotA::key1_get, &PotA::key1_put,
                 &PochoA::key1_isSet, &PochoA::key1_get, &PochoA::key1_put)));

   keyOperationsMap.insert(pair<string, Operations>("key2",
      Operations(&PotA::key2_has, &PotA::key2_get, &PotA::key2_put,
                 &PochoA::key2_isSet, &PochoA::key2_get, &PochoA::key2_put)));
}

class ReflectionB : public Reflection<PotB, PochoB>
{
public:
   ReflectionB();
};

ReflectionB::ReflectionB()
{
   keyOperationsMap.insert(pair<string, Operations>("key1",
      Operations(&PotB::key1_has, &PotB::key1_get, &PotB::key1_put,
               &PochoB::key1_isSet, &PochoB::key1_get, &PochoB::key1_put)));

   keyOperationsMap.insert(pair<string, Operations>("key2",
      Operations(&PotB::key2_has, &PotB::key2_get, &PotB::key2_put,
               &PochoB::key2_isSet, &PochoB::key2_get, &PochoB::key2_put)));

   keyOperationsMap.insert(pair<string, Operations>("key3",
      Operations(&PotB::key3_has, &PotB::key3_get, &PotB::key3_put,
               &PochoB::key3_isSet, &PochoB::key3_get, &PochoB::key3_put)));
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
