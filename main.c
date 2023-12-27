#include "main.h"

u8 yal=0;
void main (void)
{

	PORT_voidInit();
	GIF_voidEnable();
	EXTI_u8Int0SetCallBack(&ExternalInterrupt);
	EXTI_voidInt0Init();
	TIMER2_u8SetCallback(&Timer2_interrupt);
	TIMER0_u8SetCallback(&Timer0_interrupt);
	TIMER2_voidInit();
	TIMER0_voidInit();
	app();

	while(1)
	{

	}
}

//this function just count 5 second and will call app function
void Timer2_interrupt()
{
	static u32 count=0;
	if (count==15530)
	{
		switch(programe_mode)
		{
		case normal:app();break;
		case pedestrian_Red:red();break;
		case pedestrian_GorY:greenoryallow();break;
		}

		count=0;
	}
	else
	{
		count++;

	}
}

//when change to pedestrian mode
void ExternalInterrupt(void)
{
	u8 local_state;
	if (sw==switch_pressed)
	{
		//nothing
	}
	else
	{
		//TIMER0_voidMS_Delay(20);
		DIO_u8GetPinValue(DIO_u8PORTD,DIO_u8PIN2,&local_state);
		if (local_state==0)
		{
			//nothing
		}
		else
		{
			sw=switch_pressed;
			switch(CURRENT_LED_ON)
			{
			case LED_RED_CAR:programe_mode =pedestrian_Red;break;
			case LED_YAL_CAR:programe_mode=pedestrian_GorY;greenoryallow();break;
			case LED_GREEN_CAR:programe_mode=pedestrian_GorY;break;
			default : programe_mode=normal;
			}
		}
	}

}

void Timer0_interrupt(void)
{
	static u32 count2=0;
	if (count2==800)
	{
		if(yal==1)
		{
			LED_voidToggle(DIO_u8PORTA,LED_YALP);
			LED_voidToggle(DIO_u8PORTA,LED_YAL_CAR);
		}
		else
		{
			LED_voidTurnOff(DIO_u8PORTA,LED_YALP);
			LED_voidTurnOff(DIO_u8PORTA,LED_YAL_CAR);
		}


		count2=0;
	}
	else
	{
		count2++;

	}
}

//func in normal mode
void app(void)
{

	//will increment each five second
	static u8 LED_Counter=0;

	switch(LED_Counter)
	{
	case 0:
		//make Green Car Led On
		CURRENT_LED_ON=LED_GREEN_CAR;
		LED_voidTurnOn(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOn(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOff(DIO_u8PORTA,LED_YALP);
		yal=0;
		LED_Counter++;break;

	case 1:
		//make yellow Car Led On
		CURRENT_LED_ON=LED_YAL_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOn(DIO_u8PORTA,LED_YALP);
		yal=1;
		LED_Counter++;

		break;


	case 2:
		//make red car Led on
		CURRENT_LED_ON=LED_RED_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOff(DIO_u8PORTA,LED_YALP);
		yal=0;
		LED_Counter++;break;
	case 3:
		//make yellow Car Led On
		CURRENT_LED_ON=LED_YAL_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOn(DIO_u8PORTA,LED_YALP);
		yal=1;
		LED_Counter=0;

		break;
	default:LED_Counter=0;break;

	}

}



void greenoryallow(void)
{
	static u8 count_GY=0;
	switch(count_GY)
	{
	case 0:
		CURRENT_LED_ON=LED_YAL_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOn(DIO_u8PORTA,LED_YALP);
		yal=1;
		count_GY++;
		break;
	case 1:

		CURRENT_LED_ON=LED_RED_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOff(DIO_u8PORTA,LED_YALP);
		yal=0;
		count_GY++;
		break;
	case 2:
		CURRENT_LED_ON=LED_YAL_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOn(DIO_u8PORTA,LED_YALP);
		yal=1;
		count_GY++;
		break;
	case 3:

		CURRENT_LED_ON=LED_GREEN_CAR;
		LED_voidTurnOn(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOn(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOff(DIO_u8PORTA,LED_YALP);
		yal=0;
		count_GY++;
		break;
	case 4:
		app();
		sw=switch_notpressed;
		programe_mode=normal;
		count_GY=0;
		break;

	}
}

void red(void)
{

	static u8 count_red=0;
	switch(count_red)
	{
	case 0:
		//make red car Led on
		CURRENT_LED_ON=LED_RED_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOff(DIO_u8PORTA,LED_YALP);
		count_red++;
		break;
	case 1:
		//make yellow Car Led On
		CURRENT_LED_ON=LED_YAL_CAR;
		LED_voidTurnOff(DIO_u8PORTA,LED_GREEN_CAR);
		LED_voidTurnOff(DIO_u8PORTA,LED_RED_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_YAL_CAR);
		LED_voidTurnOn(DIO_u8PORTA,LED_GREENP);
		LED_voidTurnOff(DIO_u8PORTA,LED_REDP);
		LED_voidTurnOn(DIO_u8PORTA,LED_YALP);
		count_red++;
		break;
	case 2:
		count_red=0;
		app();
		sw=switch_notpressed;
		programe_mode=normal;
		break;
	}
}
