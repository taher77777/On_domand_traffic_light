#include "STD_TYPE.h"
#include "BIT_MATH.h"

#include "TIMER2_register.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"
#include "TIMER2_config.h"

static void (*TIMER2_pvCallBackFunc)(void)=NULL;

u8 TIMER2_voidInit(void)
{
	/*choose TIMER2 MODE*/ 
	switch (TIMER2_MODE)
	{
		/*choose normal mode*/
		case 1: CLR_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21);

		/*output normal interrupt enable*/
		SET_BIT(TIMSK,TIMSK_TOIE2); break;

		/*choose pwm phase correct mode*/
		case 2: SET_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21);
				/*set OC2 output*/
		switch (TIMER2_PWM_F_MODE_oc2)
		{
					/*OC2 disconected*/
					case 1 :CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
					/*Clear OC2 on compare match when up-counting. Set OC2 on compare match when downcounting.*/
					case 2 :CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
					/*Set OC2 on compare match when up-counting. Clear OC2 on compare match when downcounting*/
					case 3 :SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
					/*OC2 disconected*/
					default:CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
		}
		
		break;
		
		
		/*choose ctc mode*/
		case 3: CLR_BIT(TCCR2,TCCR2_WGM20); SET_BIT(TCCR2,TCCR2_WGM21);
		/*output compare match interrupt enable*/
				SET_BIT(TIMSK,TIMSK_OCIE2);

		/*set OC2 value */
		        switch(TIMER2_CTC_oc2)
				{
					/*OC2 disconected*/
					case 1 :CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
					/*OC2 toggle*/
					case 2 :SET_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
					/*OC2 clear*/
					case 3 :CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
					/*OC2 set*/
					case 4 :SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
					/*OC2 disconected*/
					default:CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
				} 
				break;
				
				
		/*choose pwm fast mode*/
		case 4: SET_BIT(TCCR2,TCCR2_WGM20); SET_BIT(TCCR2,TCCR2_WGM21);
		
		/*set OC2 output*/
		switch (TIMER2_PWM_F_MODE_oc2)
		{
					/*OC2 disconected*/
					case 1 :CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
					/*Clear OC2 on compare match, set OC2 at TOP*/
					case 2 :CLR_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
					/*Set OC2 on compare match, clear OC2 at TOP*/
					case 3 :SET_BIT(TCCR2,TCCR2_COM20);SET_BIT(TCCR2,TCCR2_COM21);break;
					/*OC2 disconected*/
					default:CLR_BIT(TCCR2,TCCR2_COM20);CLR_BIT(TCCR2,TCCR2_COM21);break;
		}
		
		break;
		/*choose normal mode*/
		default:CLR_BIT(TCCR2,TCCR2_WGM20); CLR_BIT(TCCR2,TCCR2_WGM21);break;
	}
	
	/*prescaler*/
	switch (TIMER2_CLK_PRE)
	{
		/*no source*/
		case 0:	CLR_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);break;
		/*df1*/
		case 1: SET_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);break;
		/*df8*/
		case 2: CLR_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);break;
		/*df64*/
		case 3: SET_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);break;
		/*df256*/
		case 4: CLR_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);break;
		/*df1024*/
		case 5: SET_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);break;
		/*External clock source on T0 pin. Clock on falling edge*/
		case 6: CLR_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);break;
		/*External clock source on T0 pin. Clock on raising edge*/
		case 7: SET_BIT(TCCR2,TCCR2_CS20); SET_BIT(TCCR2,TCCR2_CS21); SET_BIT(TCCR2,TCCR2_CS22);break;
		/*no source*/
		default:CLR_BIT(TCCR2,TCCR2_CS20); CLR_BIT(TCCR2,TCCR2_CS21); CLR_BIT(TCCR2,TCCR2_CS22);break;
	}
	return OK;

}

u8 TIMER2_u8SetCallback(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvCallBackFunc!=NULL)
	{
		TIMER2_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else 
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	
	return Local_u8ErrorStatus;
}

		/*set preload value*/
u8 TIMER2_voidSetPreLoadValue (u32 TIMER2_u32PreValue)
{
	if(TIMER2_u32PreValue>=0)
	{
		TCNT2=TIMER2_u32PreValue;
		return OK;
	}
	else
	{
		return NOK;
	}

}

		/*SET OCR2 Value*/
u8 TIMER2_voidSetOCR2Value(u32 TIMER2_u32OCR2Value)
{
	if(TIMER2_u32OCR2Value>=0)
	{
		/*compare match value ocr0*/
	OCR2=TIMER2_u32OCR2Value;
		return OK;
	}
	else
	{
		return NOK;
	}

}
		
/*ISR OVERflow MODE*/
void __vector_5(void) __attribute__((signal));
void __vector_5(void) 
{
	if (TIMER2_pvCallBackFunc!=NULL)
	{
		TIMER2_pvCallBackFunc();
	}

}
/*ISR CTC MODE*/
void __vector_4(void) __attribute__((signal));
void __vector_4(void) 
{
	if (TIMER2_pvCallBackFunc!=NULL)
	{
		TIMER2_pvCallBackFunc();
	}

}
