#include <stdio.h>
#include <math.h>
int isLeapYear();
int main() {
  int year,month; //Month is encoded as 0-11, where 0 is January
  //and day is encoded as 0-6, where 0 is Monday

  printf("\t\t\t\tMONTHLY CALENDAR\n\nPlease enter a year for this calendar: ");
  scanf("%d",&year);

  return 0;
}
int getFirstDayOfMonth(int year, int month) {
  return 0;
}
void printCalendar(int year, int day) {


}

int printMonthName(int year, int month) {
  switch(month) {

    case 0:
      printf("January\n");
      return 31;
    case 1:
      printf("February\n");
      if(isLeapYear(year)) {
        return 29;
      }
      return 28;
    case 2:
      printf("March\n");
      return 31;
    case 3:
      printf("April\n");
      return 30;
    case 4:
      printf("May\n");
      return 31;
    case 5:
      printf("June\n");
      return 30;
    case 6:
      printf("July\n");
      return 31;
    case 7:
      printf("August\n");
      return 31;
    case 8:
      printf("September\n");
      return 30;
    case 9:
      printf("October\n");
      return 31;
    case 10:
      printf("November\n");
      return 30;
    case 11:
      printf("December\n");
      return 31;
  }
  return 0;
}


//Takes three arguments, returns number of day the next month starts on,
//Prints out month
/* Mon Tue Wed Thr Fri Sat Sun
    0   1   2   3   4   5   6
  num_days = the number of days in the Month



    */
int printMonth(int year, int month, int day) {
  int num_days = printMonthName(year,month); //# of days in month
  int current_day = day; //0-6
  int days_remaining = num_days;
  int extra_days = num_days -(num_days / 7);

  //Print out each day w/o a newline untile sunday is reached, then add a new line
  while(days_remaining>=0) {
    if(current_day==7) {
      current_day=0;
    }
    //Days 0-5 (Mon-Thr)
    else if(current_day<6) {
      if(current_day==0) {
        printf("Monday\t");
      }
      else if(current_day==1) {
        printf("Tuesday\t");
      }
      else if(current_day==2) {
        printf("Wednesday\t");
      }
      else if(current_day==3) {
        printf("Thursday\t");
      }
      else if(current_day==4) {
        printf("Friday\t");
      }
      else if(current_day==5) {
        printf("Saturday\t");
      }
    }
    else{
      printf("Sunday\n");
    }
  }
  return 0;
}

int isLeapYear(int year) {

  if(((year % 4 == 0) && (year%100!=0)) || ((year%400)==0)) {
    return 1;
  }
  return 0;
}
