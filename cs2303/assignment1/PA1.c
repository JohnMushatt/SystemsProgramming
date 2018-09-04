#include <stdio.h>
#include <math.h>

int isLeapYear();
int getFirstDayOfYear();
void printCalendar();
int main() {
  int year,month; //Month is encoded as 0-11, where 0 is January
  //and day is encoded as 0-6, where 0 is Monday

  printf("Please enter a year for this calendar: ");
  scanf("%d",&year);
  printCalendar(year,getFirstDayOfYear(year));

  //printf("\n\n1st day of year: %d\n",getFirstDayOfYear(year));
  return 0;
}
int getFirstDayOfYear(int year) {
  //day
  int day =1;
  int Y = year-1;
  //last 2 digits of year
  int y = Y %100;

  //First 2 digits of year
  int c =Y / 100;


  //Shifted month i.e. 11 = January, calculatged from (month-2)%12
  double shifted_month = 11;

  int h = (int)(day + (2.6 * shifted_month -.2) + y + y/4 + c/4 - 2*c) % 7 -1;
  if (h<0) {
    return h +6;
  }
  return h;
}

void printCalendar(int year, int day) {
  int new_day= day;
  printf("\n  ***\t     CALENDER For year %d\t***\n\n", year);
  for(int current_month=0; current_month<12;current_month++){
    new_day=printMonth(year,current_month,new_day);
    printf("\n\n");
  }

}
/*Print month name and return number of days in month*/
int printMonthName(int year, int month) {
  switch(month) {

    case 0:
      printf("January\t%d\n",year);
      return 31;
    case 1:
      printf("February\t%d\n",year);
      if(isLeapYear(year)) {
        return 29;
      }
      return 28;
    case 2:
      printf("March\t%d\n",year);
      return 31;
    case 3:
      printf("April\t%d\n",year);
      return 30;
    case 4:
      printf("May\t%d\n",year);
      return 31;
    case 5:
      printf("June\t%d\n",year);
      return 30;
    case 6:
      printf("July\t%d\n",year);
      return 31;
    case 7:
      printf("August\t%d\n",year);
      return 31;
    case 8:
      printf("September\t%d\n",year);
      return 30;
    case 9:
      printf("October\t%d\n",year);
      return 31;
    case 10:
      printf("November\t%d\n",year);
      return 30;
    case 11:
      printf("December\t%d\n",year);
      return 31;
  }
  return 0;
}


//Takes three arguments, returns number of day the next month starts on,
//Prints out month
/* Mon Tue Wed Thr Fri Sat Sun
    0   1   2   3   4   5   6
  num_days = the number of days in the Month*/
int printMonth(int year, int month, int day) {
  int num_days = printMonthName(year,month); //# of days in month
  int current_day=day;
  int current_date = 1; //0-31, though the displayed day will be (current_day+1)
  int days_remaining = num_days;

  printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");

  //If month ends on saturday, next month begins on monday, FIX
  //While we are still building the month
  while(current_date<num_days+1) {

    for(current_day;current_day<7;current_day++) {
      if((current_date==1) && (current_day!=0)) {

        //Add correct spacing NOT WORKING RIGHT NOW
        for(int spaces = day;spaces>0;--spaces) {
          printf("\t");
        }
      }
      if(current_day==0) {
        printf("%2d\t", current_date);

      }
      else if(current_day!=6 && current_date<= num_days) {
        printf("%2d\t", current_date);
      }
      else if(current_date< num_days){
        printf("%2d\n", current_date);
      }
      else if(current_date==num_days+1){
        return current_day;
      }
      current_date++;
      days_remaining--;
    }
      current_day=0;
  }
  //Print out day number, print 7 on each before starting a new line
  /* while(current_date<=num_days) {


    //Go week by week
    for(current_day;current_day<7;current_day++) {

      //heck if we need to pritn special 1st line
      //(e.g. the month does not start on monday)
      if((current_date==1) && (current_day!=0)) {

        //Add correct spacing NOT WORKING RIGHT NOW
        for(int spaces = day*2;spaces>1;--spaces) {
          printf("\t");
        }
      }
      else {
        if(current_day==0) {
          printf("%-d\t", current_date);
        }
        else if(current_day==6) {
          printf("%2d\n",current_date );
        }
        else if((current_date< num_days) && (current_day<6)){
          printf("%2d\t",current_date);
        }
        else if(current_date==num_days) {
          return current_day+1;
        }
      }

      current_date++;
      days_remaining--;
    }
    printf("\n");
    current_day=0;
  }
  */
  return 0;
}

int isLeapYear(int year) {

  if(((year % 4 == 0) && (year%100!=0)) || ((year%400)==0)) {
    return 1;
  }
  return 0;
}
