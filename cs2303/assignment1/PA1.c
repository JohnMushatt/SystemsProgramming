#include <stdio.h>

int main() {
  int year, day;
  printf("\t\t\t\tMONTHLY CALENDAR\n\nPlease enter a year for this calendar: ");
  scanf("%d",&year);

  return 0;
}

void printCalendar(int year, int day) {

}

int printMonth(int year, int month, int day) {
  return 0;
}

int isLeapYear(int year) {

  if(((year % 4 = 0) && (year%100!=0)) || ((year%400)==0)) {
    return 1;
  }
  return 0;
}
