#include <stdio.h>
#include <stdlib.h>
int* foo();
void iterate_ptr(char *arr);
void iterate_pointer();
char* print_stuff();
char* print_stuff2();
int main() {

  int a = 0,d=0;
  int c,b;
  b = a++;
  c = ++d;



  char* testString = "I am a string";
  iterate_ptr(testString);
  iterate_pointer(testString);

  printf("%s",print_stuff(testString));
  printf("%s",print_stuff2(testString));

}

void iterate_ptr(char *arr) {

  char *ptr;

  for(ptr=arr;*ptr!='\0';ptr++) {
    printf("%c",*ptr);
  }
  printf("\n\n");

}
void iterate_pointer(char *arr) {

  char *ptr;

  for(ptr=arr;*ptr!='\0';ptr++) {
    printf("%p",ptr);
  }
  printf("\n\n");

}
char* print_stuff(char *arr) {

  char *ptr;

  for(ptr=arr;*ptr!='\0';ptr++) {
    printf("%p",ptr);
  }
  printf("\n\n");

  return ptr;

}
char* print_stuff2(char *arr) {

  char *ptr;

  for(ptr=arr;*ptr!='\0';ptr++) {
  }

  return ptr;

}
