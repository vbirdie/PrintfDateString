#include "date_to_string.h"
#include <stdlib.h>
#include <string.h> 

void reverse(char s[])
{
  int i, j;
  char c;
  for (i = 0, j = strlen(s)-1; i<j; i++, j--) 
  {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(int n, char s[])
{
  int i, sign;
  if ((sign = n) < 0) //записываем знак
    n = -n; // делаем n положительным числом
  
  i = 0;
  do { //генерируем цифры в обратном порядке
    s[i++] = n % 10 + '0'; //берем следующую цифру
  } while ((n /= 10) > 0); // удаляем
  
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

char* years_to_string(uint32_t years, char* years_str, uint8_t* str_lenght)
{
  char str1[] = " год";
  char str2[] = " года";
  char str3[] = " лет";
 
  itoa(years, years_str);
    
  if (years > 0)
  {
    uint32_t yearsTmp0 = years;    
    if (years >= 100) yearsTmp0 = years % 100;
  
      if ( (yearsTmp0 > 10) && (yearsTmp0 < 20) )
      {
        strncat (years_str, str3, strlen(str3));//лет
      }
      else
      {
        uint32_t yearsTmp1 = years % 10;
        switch (yearsTmp1) 
        {
          case 1:
            strncat (years_str, str1, strlen(str1));//год
            break;
          case 2:
          case 3:
          case 4:
            strncat (years_str, str2, strlen(str2));//года
            break;
          default:
            strncat (years_str, str3, strlen(str3));//лет
        }       
      }

  }
  *str_lenght =  strlen(years_str);
  return years_str;
}

char* days_to_string(uint32_t days, char* days_str, uint8_t* str_lenght)
{
  char str1[] = " день";
  char str2[] = " дня";
  char str3[] = " дней";
    
  itoa(days, days_str);
  
  if ( (days > 0) && (days < 365) )
  {
    if ( (days % 100 / 10) == 1 )
    {
      strncat (days_str, str3, strlen(str3));//дней
    }
    else if ( (days % 10) == 1 )
    {
      strncat (days_str, str1, strlen(str1));//день
    }
    else if ( ((days % 10) == 2) || ((days % 10) == 3) || ((days % 10) == 4) )
    {
      strncat (days_str, str2, strlen(str2));//дня
    }
    else
    {
      strncat (days_str, str3, strlen(str3));//дней
    }
  }

  *str_lenght =  strlen(days_str);
  return days_str;
}

char* hours_to_string(uint32_t hours, char* hours_str, uint8_t* str_lenght)
{
  char str1[] = " час";
  char str2[] = " часа";
  char str3[] = " часов";
    
  itoa(hours, hours_str);
  
  if ( (hours > 0) && (hours < 24) )
  {
    if ( (hours >= 5) && (hours<=20) )
    {     
      strncat (hours_str, str3, strlen(str3));//часов
    }
    else if ( (hours == 1) || (hours == 21) )
    {      
      strncat (hours_str, str1, strlen(str1));//час
    }
    else
    {      
      strncat (hours_str, str2, strlen(str2));//часа
    }
  }
  *str_lenght =  strlen(hours_str);
  return hours_str;
}

char* minutes_to_string(uint32_t minutes, char* minutes_str, uint8_t* str_lenght)
{
  char str1[] = " минута";
  char str2[] = " минуты";
  char str3[] = " минут";
    
  itoa(minutes, minutes_str);

  if ( (minutes > 0) && (minutes < 60) )
  {
    if ( (minutes == 1) || (minutes == 21) || (minutes == 31) 
        || (minutes == 41) || (minutes == 51) )
    {
      strncat (minutes_str, str1, strlen(str1));//минута
    }
    else if ( ((minutes >= 5) && (minutes <= 20)) || ((minutes >= 25) && (minutes <= 30)) 
             || ((minutes >= 35) && (minutes <= 40))  || ((minutes >= 45) && (minutes <= 50))  
             || ((minutes >= 55) && (minutes <= 59)) )
    {
      strncat (minutes_str, str3, strlen(str3));//минут
    }
    else if ( ((minutes >= 2) && (minutes <= 4)) || ((minutes >= 22) && (minutes <= 24)) 
             || ((minutes >= 32) && (minutes <= 34))  || ((minutes >= 42) && (minutes <= 44))  
             || ((minutes >= 52) && (minutes <= 54)) )
    {
      strncat (minutes_str, str2, strlen(str2));//минуты
    }  
  }  

  *str_lenght =  strlen(minutes_str);
  return minutes_str;
}

char* seconds_to_string(uint32_t seconds, char* seconds_str, uint8_t* str_lenght)
{
  char str1[] = " секунда";
  char str2[] = " секунды";
  char str3[] = " секунд";
    
  itoa(seconds, seconds_str);

  if ( (seconds > 0) && (seconds < 60) )
  {
    if ( (seconds == 1) || (seconds == 21) || (seconds == 31) 
        || (seconds == 41) || (seconds == 51) )
    {
      strncat (seconds_str, str1, strlen(str1));//секунда
    }
    else if ( ((seconds >= 5) && (seconds <= 20)) || ((seconds >= 25) && (seconds <= 30)) 
             || ((seconds >= 35) && (seconds <= 40))  || ((seconds >= 45) && (seconds <= 50))  
             || ((seconds >= 55) && (seconds <= 59)) )
    {
      strncat (seconds_str, str3, strlen(str3));//секунд
    }
    else if ( ((seconds >= 2) && (seconds <= 4)) || ((seconds >= 22) && (seconds <= 24)) 
             || ((seconds >= 32) && (seconds <= 34))  || ((seconds >= 42) && (seconds <= 44))  
             || ((seconds >= 52) && (seconds <= 54)) )
    {
      strncat (seconds_str, str2, strlen(str2));//секунды
    }  
  }  

  *str_lenght =  strlen(seconds_str);
  return seconds_str;
}

char* unixTimeToString(time_t unixTime, char* unixTimeStr)
{
  char str1[] = "сейчас";  
  char str2[] = ", ";
  char str3[] = " и ";
  
  uint8_t yearsStrlenght;
  uint8_t daysStrlenght;
  uint8_t hoursStrlenght;
  uint8_t minutesStrlenght;
  uint8_t secondsStrlenght;
  uint8_t strlenght =0;
  
  if (unixTime == 0)
  {
    *unixTimeStr = '\0';
    strncat (unixTimeStr, str1, strlen(str1));    
  }
  else
  {
    struct tm* aTm = localtime(&unixTime);  
    uint32_t myYears = aTm->tm_year - 70;
    uint32_t myDays = aTm->tm_yday;//-1
    uint32_t myHours = aTm->tm_hour;
    uint32_t myMinutes = aTm->tm_min;
    uint32_t mySeconds = aTm->tm_sec; 
    
    if (myYears != 0)
    {
      years_to_string(myYears, unixTimeStr+strlenght, &yearsStrlenght);
      strlenght += yearsStrlenght;
    }

    if (myDays != 0)
    {
      if(myYears == 0)
      {
        ;
      }
      else
      {
        if ((mySeconds ==0) && (myMinutes ==0) && (myHours ==0))
        {
          strncat (unixTimeStr, str3, strlen(str3));//" и " 
          strlenght += 3;           
        }
        else
        {
          strncat (unixTimeStr, str2, strlen(str2));//", " 
          strlenght += 2;          
        }
      }
      days_to_string(myDays, unixTimeStr+strlenght, &daysStrlenght);
      strlenght += daysStrlenght;                 
    }     
    
    if (myHours != 0)
    {
      if((myYears == 0) && (myDays == 0))
      {
        ;
      }
      else
      {
        if ((mySeconds ==0) && (myMinutes ==0))
        {
          strncat (unixTimeStr, str3, strlen(str3));//" и " 
          strlenght += 3;           
        }
        else
        {
          strncat (unixTimeStr, str2, strlen(str2));//", " 
          strlenght += 2;          
        }
      }
      hours_to_string(myHours, unixTimeStr+strlenght, &hoursStrlenght);
      strlenght += hoursStrlenght;                 
    } 
    
    if (myMinutes != 0)
    {
      if((myYears == 0) && (myDays == 0) && (myHours == 0))
      {
        ;
      }
      else
      {
        if (mySeconds ==0)
        {
          strncat (unixTimeStr, str3, strlen(str3));//" и " 
          strlenght += 3;           
        }
        else
        {
          strncat (unixTimeStr, str2, strlen(str2));//", " 
          strlenght += 2;          
        }
      }
      minutes_to_string(myMinutes, unixTimeStr+strlenght, &minutesStrlenght);
      strlenght += minutesStrlenght; 
      
    }      
     
    if (mySeconds != 0)
    {
      if((myYears == 0) && (myDays == 0) && (myHours == 0) && (myMinutes == 0))
      {
        ;
      }
      else
      {
        strncat (unixTimeStr, str3, strlen(str3));//" и " 
        strlenght += 3;   
      }
      seconds_to_string(mySeconds, unixTimeStr+strlenght, &secondsStrlenght);
      strlenght += secondsStrlenght;                 
    }
    
  } 
  return unixTimeStr;
}

