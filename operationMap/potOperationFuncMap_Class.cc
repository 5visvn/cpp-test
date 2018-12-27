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

template<typename P>
class Dbs
{
protected:
   enum KeyType{INT, STRING, UNSIGNED};
   struct Operations
   {
      // has
      typedef bool (P::*Has)();
      Has has;

      // get
      typedef int (P::*GetInt)();
      typedef string (P::*GetStr)();
      typedef unsigned int (P::*GetUInt)();
      GetInt getInt;
      GetStr getStr;
      GetUInt getUInt;

      // put
      typedef void (P::*PutInt)(int);
      typedef void (P::*PutStr)(string&);
      typedef void (P::*PutUInt)(unsigned int);
      PutInt putInt;
      PutStr putStr;
      PutUInt putUInt;

      KeyType type;

      explicit Operations(Has h, GetInt g, PutInt p)
         :has(h), getInt(g), putInt(p){type = KeyType::INT;}
      explicit Operations(Has h, GetStr g, PutStr p)
         :has(h), getStr(g), putStr(p){type = KeyType::STRING;}
      explicit Operations(Has h, GetUInt g, PutUInt p)
         :has(h), getUInt(g), putUInt(p){type = KeyType::UNSIGNED;}
   };
   map<string, Operations> keyOperationsMap;
public:
   virtual void printKey(P* pot, string& key)
   {
      auto it = keyOperationsMap.find(key);
      if(it != keyOperationsMap.end())
      {
         // has
         Operations &operations = it->second;
         bool hasKey = (pot->*(operations.has))();
         if(!hasKey)
         {
            cout << "ERROR : this key has no value : " << key << endl << endl;
            return;
         }

         cout << "searching key : " << key << endl;
         switch(operations.type)
         {
         case KeyType::INT :
         {
            int a = (pot->*(operations.getInt))();
            cout << "key's type is : int" << endl
                 << " and value is : "<< a << endl << endl;
            break;
         }
         case KeyType::STRING :
         {
            auto s = (pot->*(operations.getStr))();
            cout << "key's type is : string" << endl
                 << " and value is : "<< s << endl << endl;
            break;
         }
         case KeyType::UNSIGNED :
         {
            auto s = (pot->*(operations.getUInt))();
            cout << "key's type is : unsigned int" << endl
                 << " and value is : "<< s << endl << endl;
            break;
         }
         }
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
      }
   }

   virtual void putKey(P* pot, string& key, string value)
   {
      auto it = keyOperationsMap.find(key);
      if(it != keyOperationsMap.end())
      {
         cout << "Put string : (" << value << ") into : (" << key << ")\n";
         auto &operations = it->second;
         if(operations.type == KeyType::STRING)
         {
            (pot->*(operations.putStr))(value);
         }
         else
         {
            cout<< "ERROR : this key's type is not string!" << endl;
         }
         cout << endl;
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
      }
   }

   virtual void putKey(P* pot, string& key, int value)
   {
      auto it = keyOperationsMap.find(key);
      if(it != keyOperationsMap.end())
      {
         cout << "Put int : (" << value << ") into : (" << key << ")\n";
         auto &operations = it->second;
         if(operations.type == KeyType::INT)
         {
            (pot->*(operations.putInt))(value);
         }
         else
         {
            cout << "ERROR : this key's type is not int!" << endl;
         }
         cout << endl;
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
      }
   }

   virtual void putKey(P* pot, string& key, unsigned int value)
   {
      auto it = keyOperationsMap.find(key);
      if(it != keyOperationsMap.end())
      {
         cout << "Put int : (" << value << ") into : (" << key << ")\n";
         auto &operations = it->second;
         if(operations.type == KeyType::UNSIGNED)
         {
            (pot->*(operations.putUInt))(value);
         }
         else
         {
            cout << "ERROR : this key's type is not int!" << endl;
         }
         cout << endl;
      }
      else
      {
         cout << "ERROR : this pot can't find key : " << key << endl << endl;
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
   keyOperationsMap.insert(pair<string, Operations>("key1",
                Operations(&PotA::key1_has, &PotA::key1_get, &PotA::key1_put)));

   keyOperationsMap.insert(pair<string, Operations>("key2",
                Operations(&PotA::key2_has, &PotA::key2_get, &PotA::key2_put)));
}

class DbsB : public Dbs<PotB>
{
public:
   DbsB();
};

DbsB::DbsB()
{
   keyOperationsMap.insert(pair<string, Operations>("key1",
                Operations(&PotB::key1_has, &PotB::key1_get, &PotB::key1_put)));

   keyOperationsMap.insert(pair<string, Operations>("key2",
                Operations(&PotB::key2_has, &PotB::key2_get, &PotB::key2_put)));

   keyOperationsMap.insert(pair<string, Operations>("key3",
                Operations(&PotB::key3_has, &PotB::key3_get, &PotB::key3_put)));
}

int main()
{
   string key1 = "key1";
   string key2 = "key2";
   string key3 = "key3";

   PotA pA;
   DbsA dbsA;
   cout<< "*** pot A:" << endl << endl;
   dbsA.printKey(&pA, key1);
   dbsA.printKey(&pA, key2);
   dbsA.printKey(&pA, key3);

   PotB pB;
   DbsB dbsB;
   cout<< "*** pot B:" << endl << endl;
   dbsB.printKey(&pB, key1);
   dbsB.printKey(&pB, key2);
   dbsB.printKey(&pB, key3);

   cout << "*** PUT string value with pot A:" << endl << endl;
   dbsA.putKey(&pA, key1, "new value of potA, key1");
   dbsA.printKey(&pA, key1);
   dbsA.putKey(&pA, key2, "new value of potA, key2");
   dbsA.printKey(&pA, key2);
   dbsA.putKey(&pA, key3, "new value of potA, key3");
   dbsA.printKey(&pA, key3);
}
