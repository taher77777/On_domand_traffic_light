/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER2				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/

#ifndef TIMER2_INTERFACE_H_
#define TIMER2_INTERFACE_H_

u8 TIMER2_voidInit(void);
u8 TIMER2_u8SetCallBack(void (*copy_pvCallBackFunc)(void));
u8 TIMER2_voidSetPreLoadValue (u32 TIMER2_u32PreValue);
u8 TIMER2_voidSetOCR2Value(u32 TIMER2_u32OCR2Value);
#endif
