#include <cstdio>
#include <cmath>
using namespace std;

int gcd(int a, int b)
{
  return (b == 0)? a:gcd(b, a%b);
}

void print0(int a, int b)
{
  if(gcd(a,b) != 1)
  {
    a = a / gcd(a, b);
    b = b / gcd(a, b);
  }
  if(abs(a) > abs(b) && a%b != 0)
    printf("%d %d/%d", a/b, (a - a/b * b), b);
  else if(a%b == 0)
    printf("%d", a/b);
  else
    printf("%d/%d", a, b);
}

int main()
{
  int a1, b1, a2, b2;
  scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);
  //printf("%d %d %d %d\n", a1, b1, a2, b2);
  int down, up1, up2;
  down = b1 * b2 / gcd(b1, b2);
  up1 = a1 * down / b1;
  up2 = a2 * down / b2;
  
  print0(a1, b1);
  printf(" + ");
  print0(a2, b2);
  printf(" = ");
  print0(up1+up2, down);
  printf("\n");
  
  print0(a1, b1);
  printf(" - ");
  print0(a2, b2);
  printf(" = ");
  print0(up1-up2, down);
  printf("\n");
  
  print0(a1, b1);
  printf(" * ");
  print0(a2, b2);
  printf(" = ");
  print0(a1 * a2, b1 * b2);
  printf("\n");
  
  print0(a1, b1);
  printf(" / ");
  print0(a2, b2);
  printf(" = ");
  if(a2 != 0)
    print0(a1 * b2, b1 * a2);
  else
    printf("Inf");
  printf("\n");
  
  return 0;
}