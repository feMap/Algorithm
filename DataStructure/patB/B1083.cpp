#include <cstdio>
#include <cmath>
#include <cstdlib>

int main()
{
  int storage[10010] = {0};
  int n;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++)
  {
    int temp;
    scanf("%d", &temp);
    int value = abs(temp - i);
    storage[value]++;
  }
  
  for(int i = n; i > 0; i--)
  {
    if(storage[i] != 0)
      printf("%d %d\n", i, storage[i]);
  }
  
  return 0;
}