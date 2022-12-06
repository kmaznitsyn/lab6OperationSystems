#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <cstdio>

int main (int argc, char ** argv)
{
  int i, num1 = 0, num2 = 0;
  pid_t pid; 
  time_t now = time(NULL);
  printf("Поки один процес\n");
  printf("Виклик функції fork...\n");
  pid = fork();
  while(1)
  {
    if (pid == 0) {
      printf("Процес нащадок\n");
      num1++;
    } else if (pid > 0) {
      printf("Батьківський процес, pid нащадка %d\n", pid);
      num2++;
    } else {
      printf("Помилка, нащадок не створений\n"); 
    } 
    time_t end = time(NULL);
    if((end - now) == 1)break;
  }
  sleep(1);
  printf("------------------------------------------------------------------------\n");
  if(num2 != 0) printf("Кількість виконання циклу для батьківського процесу: %d\n", num2);
  if(num1 != 0) printf("Кількість виконання циклу для дочірнього процесу: %d\n", num1);
  return 0;
}
