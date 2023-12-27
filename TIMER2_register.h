/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER2				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER2_REGISTER_H_
#define TIMER2_REGISTER_H_

#define TCCR2             *((volatile u8*)0x45)             //Timer/Counter1 Control Register 


#define TCCR2_COM21       5                                  //Compare Output Mode for bit1 pin OC2
#define TCCR2_COM20       4                                  //Compare Output Mode for bit2 pin OC2 


#define TCCR2_WGM20       6                                  //Waveform Generation Mode Bit1 
#define TCCR2_WGM21       3                                  //Waveform Generation Mode Bit2 

#define TCCR2_CS20        0                                  //Clock Select Bit1
#define TCCR2_CS21        1                                  //Clock Select Bit1
#define TCCR2_CS22        2                                  //Clock Select Bit1

#define TCNT2             *((volatile u8*)0x44)

#define OCR2              *((volatile u8*)0x43)             //The Output Compare Registers 


#define TIMSK			  *((volatile u8*)0x59)
#define TIMSK_OCIE2       7									//Output Compare A Match Interrupt Enable
#define TIMSK_TOIE2       6									//Overflow Interrupt Enable
			



#endif
