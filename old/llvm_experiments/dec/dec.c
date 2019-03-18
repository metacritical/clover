#include <stdio.h>

long sub_one(long n){
  return (n-1);
}

long dec(){
  return sub_one(42);
}

int main(){
  printf("%d", sub_one(42));
  return 0;
}
