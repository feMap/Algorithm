#include <cstdio>
//#include <cstring>
#include <iostream>
//#include <string>
#include <cctype>
using namespace std;

int main()
{
  int n;
  scanf("%d", &n);getchar();
  for(int i = 0; i < n; i++)
  {
    string pw;
    //scanf("%s", pw);
    getline(cin, pw);

    int lens = pw.length();
    if(lens < 6)
    {
      printf("Your password is tai duan le.\n");
      continue;
    }
    int flag1 = 0, flag2 = 0;
    int flag = 0;
    for(int i = 0; i < lens; i++)
    {
      
      if((pw[i] <= '9' && pw[i] >= '0') || pw[i] == '.' || (pw[i] <= 'z' && pw[i] >= 'a') || (pw[i] <= 'Z' && pw[i] >= 'A'))
      {
        if(pw[i] <= '9' && pw[i] >= '0')
          flag1 = 1;
        else if((pw[i] <= 'z' && pw[i] >= 'a') || (pw[i] <= 'Z' && pw[i] >= 'A'))
          flag2 = 1;
      }
      else
      {
        printf("Your password is tai luan le.\n");
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      if(flag1 == 1 && flag2 == 0){
        printf("Your password needs zi mu.\n");
      }
      else if(flag1 == 0 && flag2 == 1){
        printf("Your password needs shu zi.\n");
      }
      else if(flag1 == 1 && flag2 == 1){
        printf("Your password is wan mei.\n");
      }
    }
  }
  return 0;
}