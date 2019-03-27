#include <iostream>
#include <vector>

using namespace std;
int count = 20;

void quickInsertSort(vector<int>& inArr,
                     size_t left, size_t right);

int main()
{
   vector<int> arr;

   // generate data
   for(int i = 0; i < count; ++i)
   {
      int r = rand() % (count * 2);
      cout << r << " ";
      arr.emplace_back(r);
   }
   cout << endl << endl;

   // sort it
   quickInsertSort(arr, 0, count - 1);

   for(int i : arr)
   {
      cout << i << " ";
   }
   cout << endl;
}

void quickInsertSort(vector<int>& inArr,
                     size_t left, size_t right)
{
   if(left < 0 || left >= right || right >= inArr.size())
      return;

   //quick sort
   size_t l = left, r = right;
   while(l < r)
   {
      while(l < r && inArr[l] <= tmp)
         ++l;
      swap(inArr[r], inArr[l]);
      while(l < r && inArr[r] > tmp)
         --r;
      swap(inArr[r], inArr[l]);
   }

   quickInsertSort(inArr, left, l - 1 );
   quickInsertSort(inArr, r + 1 , right);
}
