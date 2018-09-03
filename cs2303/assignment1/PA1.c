#include <stdio.h>

int main() {
  int year,month; //Month is encoded as 0-11, where 0 is January
  int day;  //and day is encoded as 0-6, where 0 is Sunday

  printf("\t\t\t\tMONTHLY CALENDAR\n\nPlease enter a year for this calendar: ");
  scanf("%d",&year);
  printCalendar(year,calculateDay(year,baseDay))
  return 0;
}

int calculateDay(int year, int baseDay) {


}
void printCalendar(int year, int day) {

  int const baseYear = 2000;
  int const baseDate = 1
  int const baseDay = 6;   
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
