
#ifndef APP_MAIN_H_
#define APP_MAIN_H_

#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "PORT_interface.h"
#include "TIMER0_interface.h"
#include "TIMER2_interface.h"
#include "GIE_interface.h"
#include "EXTI_interface.h"
#include "LED_interface.h"

#define LED_RED_CAR         DIO_u8PIN0
#define LED_YAL_CAR		    DIO_u8PIN1
#define LED_GREEN_CAR 	    DIO_u8PIN2
#define NO_LED_ON           3u
u8 CURRENT_LED_ON=NO_LED_ON;

#define LED_REDP			DIO_u8PIN5
#define LED_YALP			DIO_u8PIN6
#define LED_GREENP		    DIO_u8PIN7



//modes
#define normal              1
#define pedestrian_Red      2
#define pedestrian_GorY     3
//global timer count
u8 programe_mode=normal;
//switch status
typedef enum switch_status
{
	switch_pressed,
	switch_notpressed
}switch_status;

switch_status sw=switch_notpressed;

/*function part prototype*/
void ExternalInterrupt(void);
void Timer2_interrupt(void);
void Timer0_interrupt(void);
void app(void);
void greenoryallow(void);
void red();


#endif /* APP_MAIN_H_ */
