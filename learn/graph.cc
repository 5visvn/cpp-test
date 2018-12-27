#include <iostream>

typedef enum {UNDISCOVERED, DISCOVERED, VISITED} VStatus;
typedef enum {UNDETERMINED, TREE, CROSS, FORWARD, BACKWARD} Etype;

template <typename Tv, typename Te>
class Graph
{
   void reset()
   {
      for (int i = 0; i < n; ++i)
         {
         status(i) = UNDISCOVERED; dTime(i) = fTime(i) = -1;
         parent(i) = -1; priority(i) = INT_MAX;
         for (int j = 0; j < n; ++j)
            if (exist (i,j)) type(i,j) = UNDETERMINED;
         }
   }

   void BFS (int, int&);
};
