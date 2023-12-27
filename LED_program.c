/***********************************************************************/
/***********************************************************************/
/*****************    AUTHOR: TAHER MOHAMED   **************************/
/*****************    LAYER:  HAL            **************************/
/*****************    SWC:    LED             **************************/
/*****************    VERSION:1.00            **************************/
/***********************************************************************/
/***********************************************************************/
#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "PORT_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

/*use micro as a controlled circuit not as asource */

/*configration*/

#if LED_TYPE == FORWORD

/* SET LED ON  */
u8 LED_voidTurnOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	if (Copy_u8Port<4&&Copy_u8Pin<8)
	{
		DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_HIGH );
		return OK;
	}
	else
	{
		return NOK;
	}



}

/* SET LED OFF  */
u8 LED_voidTurnOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	if (Copy_u8Port<4&&Copy_u8Pin<8)
	{
		DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_LOW);
		return OK;
	}
	else
	{
		return NOK;
	}


}

/* TOGGLE LED */
u8 LED_voidToggle(u8 Copy_u8Port,u8 Copy_u8Pin)
{

	u8 Local_u8LedState=0;
	if (Copy_u8Port<4&&Copy_u8Pin<8)
	{
		DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Local_u8LedState);
		if(Local_u8LedState==1)
		{
			DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_LOW);
		}
		else
		{
			DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_HIGH );
		}
		return OK;
	}
	else
	{
		return NOK;
	}

}

#elif LED_TYPE == REVERSE
/* SET LED ON  */
u8 LED_voidTurnOn(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	if (Copy_u8Port<4&&Copy_u8Pin<8)
	{
		DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_LOW );
		return OK;
	}
	else
	{
		return NOK;
	}



}

/* SET LED OFF  */
u8 LED_voidTurnOff(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	if (Copy_u8Port<4&&Copy_u8Pin<8)
		{
		DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_HIGH);
			return OK;
		}
		else
		{
			return NOK;
		}

}

/* TOGGLE LED */
u8 LED_voidToggle(u8 Copy_u8Port,u8 Copy_u8Pin)
{
	u8 Local_u8LedState=0;
	if (Copy_u8Port<4&&Copy_u8Pin<8)
		{
		DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Local_u8LedState);
		if(Local_u8LedState==1)
		{
			DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinValue ( Copy_u8Port, Copy_u8Pin, DIO_u8PIN_LOW );
		}
			return OK;
		}
		else
		{
			return NOK;
		}

}
#endif 
