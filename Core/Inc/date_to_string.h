/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DATE_TO_SRING_
#define _DATE_TO_SRING_

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h> 
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
/* Exported types ------------------------------------------------------------*/

/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
  
char* years_to_string(uint32_t years, char* years_str, uint8_t* str_lenght);
//char* days_to_string(uint32_t days, char* days_str, uint8_t* str_lenght);
//char* hours_to_string(uint32_t hours, char* hours_str, uint8_t* str_lenght);
//char* minutes_to_string(uint32_t minutes, char* minutes_str, uint8_t* str_lenght);
//char* seconds_to_string(uint32_t seconds, char* seconds_str, uint8_t* str_lenght);
char* unixTimeToString(time_t unixTime, char* unixTimeStr);

/* Private defines -----------------------------------------------------------*/
  
/* ---------------------------------------------------------------------------*/  

#ifdef __cplusplus
}
#endif

#endif /* _DATE_TO_SRING_ */
