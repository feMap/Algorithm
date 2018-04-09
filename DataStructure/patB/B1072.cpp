#include <cstdio>
#include <set>
#include <vector>
using namespace std;

int main()
{
  int nStu, nItem;
  scanf("%d %d", &nStu, &nItem);
  set<int> banList;  

  for(int i = 0; i < nItem; i++)
  {
    int temp;
    scanf("%d", &temp);
    banList.insert(temp);
  }

  int totalStu = 0, totalItem = 0;
  for(int i = 0; i < nStu; i++)
  {
    int flag = 0;
    char name[10];
    int count;
    int item;
    vector<int> items;
    scanf("%s %d", name, &count);
    for(int j = 0; j < count; j++)
    {
      scanf("%d", &item);
      if(banList.find(item) != banList.end())
      {
        totalItem++;
        flag = 1;
        items.push_back(item);
      }
    }
    
    if(flag == 1)
    {
      totalStu++;
      printf("%s:", name);
      for(vector<int>::iterator it = items.begin(); it != items.end(); it++)
      {
        //Please attention to this output format.
        printf(" %04d", *it);
      }
      printf("\n");
    }
    
    items.clear();
  }
  
  printf("%d %d", totalStu, totalItem);
  
  return 0;
}