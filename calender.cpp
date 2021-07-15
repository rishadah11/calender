#include<iostream>
using namespace std;
int dayNumber(int day, int month, int year){
   static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
   year -= month < 3;
   return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}
string getMonthName(int monthNumber){
   string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   return (months[monthNumber]);
}
int numberOfDays (int monthNumber, int year){
   switch(monthNumber){
      case 0 :
      case 2 :
      case 4 :
      case 6 :
      case 7 :
      case 9 :
      case 11: return(31);
      break;
      case 1 :
         if (year % 400 == 0 || (year % 4 == 0 && year %100 != 0))
            return (29);
         else
            return (28);
      break;
      case 3 :
      case 5 :
      case 8 :
      case 10 : return(30);
      break;
   }
}
void printCalendar(int year, int month_no){
   cout<<"\t\t\t#########################"<<endl;
   cout<<"\t\t\t#  Calendar - Year "<<year<<" #"<<endl;;
   cout<<"\t\t\t#########################"<<endl;
   int days;
   int current = dayNumber (1, 1, year);

      days = numberOfDays (month_no, year);
      cout<<endl<<"\t\t*******++******* "<<getMonthName (month_no).c_str()<<" *******++*******\t\t\n"<<endl;
      cout<<" \tSun\tMon\tTue\tWed\tThu\tFri\tSat\n\n";
      int k;
      for (k = 0; k < current; k++)
         cout<<"\t";
      for (int j = 1; j <= days; j++){
         printf("\t%3d ", j);
         if (++k > 6){
            k = 0;
            cout<<endl;
         }
      }
      if (k)
         cout<<endl;
         current = k;

   return;
}
int main(){
   int year;
   int month_no;
   cout<<"Enter Year: ";
   cin>>year;
   cout<<"Enter Month Number: ";
   cin>>month_no;
   cout<<"\n\n";
   printCalendar(year,month_no-1);
   return (0);
}
