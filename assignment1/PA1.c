#include <stdio.h>
#include <math.h>

//John Mushatt

//----Prototypes----
int isLeapYear();
int getFirstDayOfYear();
void printCalendar();

/**
* Main function
*/
int main() {
  int year; //Month is encoded as 0-11, where 0 is January
  //and day is encoded as 0-6, where 0 is Monday

  printf("Please enter a year for this calendar: ");
  scanf("%d",&year);


  int wrongInput =0;
  //Validation of user input, make sure type conversion and date limit succeed
  while(!wrongInput) {
    if(year!=0 && year >1532) {
      printCalendar(year,getFirstDayOfYear(year));
      wrongInput= 1;
    }
    else {
      printf("You entered a bad year, please enter an integer year starting after at"
      "least 1582\n");
      scanf("%d",&year);
    }
  }
  //printf("\n\n1st day of year: %d\n",getFirstDayOfYear(year));
  return 0;
}
/**Gauss's Algorithm - Disparate Version | Retrieved and modified from
*https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Gauss.27s_algorithm
*Takes the year and calculates the 1st day of a given month (In this case it
*gives the 1st of January)
*@param year Year to calculate 1st day of
*@return int Encoded day to return to start next month
*/

int getFirstDayOfYear(int year) {
  //Date of day to calculate (1st of January)
  int day =1;

  /*Year to calculate, in this case if the month is either Jan or Feb
  subtract 1 from the year, else leave as is
  */
  int Y = year-1;

  //last 2 digits of year
  int y = Y %100;

  //First 2 digits of year
  int c =Y / 100;


  //Shifted month i.e. 11 = January, calculated from (month-2)%12
  double shifted_month = 11;

  /* Formulate to calculate 1st day of January, special offset because
  this program uses Monday as 0 rather than Sunday
  */
  int next_day = (int)(day + (2.6 * shifted_month -.2) + y + y/4 + c/4 - 2*c) % 7 -1;

  //If the day is negative add 6
  if (next_day<0) {
    return next_day +6;
  }
  return next_day;
}


/**Create calendar by passing in a year and a starting day, print header then
*reassign new_day to the printMonth() function thus updating the next day
*correctly
*@param year Year to print calendar of
*@param day day to begin each month, gets updated as each month progresses
*/
void printCalendar(int year, int day) {

  int new_day= day;

  printf("\n  ***\t     CALENDER For year %d\t***\n\n", year);

  //Loop invariant--new_day will always be the day the next month starts on
  for(int current_month=0; current_month<12;current_month++){

    new_day=printMonth(year,current_month,new_day);
    printf("\n\n");
  }

}
/**Print month name and return number of days in month
*@param year Year to print
*@param month  Encoded month to select
*@return int Returns number of days in given month
*/
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
/**
*Prints the month in a specified format:
*Mon Tue Wed Thr Fri Sat Sun
* 0   1   2   3   4   5   6
*Adds special spacing to first line incase it does not begin with monday
*and is not the first day of the month
*@param year Year to get the month names
*@param month Month to get month name and # of days
*@param day current day that the month starts on
*@return The day the next month starts on
*/
int printMonth(int year, int month, int day) {

  int num_days = printMonthName(year,month); //# of days in month
  int current_day=day; //Assign the current day
  int current_date = 1; //0-31, though the displayed day will be (current_day+1)
  int days_remaining = num_days; //Keep track of how many days that need to be processed

  //Header for week
  printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");


  //While we are still building the month
  //Loop invariant--Current date will never go past the # of days in the month
  while(current_date<num_days+1) {

    for(current_day;current_day<7;current_day++) {

      //Add correct spacing if needed
      if((current_date==1) && (current_day!=0)) {

        for(int spaces = day;spaces>0;--spaces) {
          printf("\t");
        }
      }

      //If we are not Sunday and we still have days to processed
      if(current_day!=6 && current_date<= num_days) {
        printf("%2d\t", current_date);
      }

      //If we still have days to process
      else if(current_date< num_days){
        printf("%2d\n", current_date);
      }

      //Exit if we are on the next day of the next month and return it
      else if(current_date==num_days+1){
        return current_day;
      }
      current_date++;
      days_remaining--;
    }
      //Reset week back to Monday
      current_day=0;
  }
  return 0;
}

/**
*Checks if given year is a leap Year
*@param year Year to test if leap Year
*@return int 0 or 1 depending on validity of the year being a leap year
*/
int isLeapYear(int year) {

  if(((year % 4 == 0) && (year%100!=0)) || ((year%400)==0)) {
    return 1;
  }
  return 0;
}
