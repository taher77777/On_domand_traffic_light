/********************		Author: TAHER MOHAMED	**************/
/********************		Layer: MCAL				**************/
/********************		SWC: TIMER2				**************/
/********************		Version: 1.00			**************/
/********************		Date: 28-8-2020			**************/
/*****************************************************************/
/*****************************************************************/
#ifndef TIMER2_CONFIG_H_
#define TIMER2_CONFIG_H_
//Waveform Generation Mode

#define NORMAL   			1
#define PWM_Phase_Correct	2
#define CTC					3
#define PWM_FAST_MODE		4
#define TIMER2_MODE         NORMAL

//clock select

	/*
		no_source :  0
		normal	  :  1
		clock/8   :  2
		clock/64  :  3
		clock/256 :  4
		clock/1024:  5
		E_S_T0_F_E:  6		External clock source on T0 pin. Clock on falling edge
		E_S_T0_R_E:  7		External clock source on T0 pin. Clock on raising edge
						*/
#define TIMER2_CLK_PRE      2

/*ctc outbut oc2*/

	/* 
		oc2 disconected  1
		oc2 toggle       2
		oc2 clear        3
		oc2 set          4
							*/

#define TIMER2_CTC_oc2   1

/*pwm FAST Mode*/

   /*
		oc2 disconected  								1
		Clear oc2 on compare match, set oc2 at TOP      2
		set oc2 on compare match, clear oc2 at TOP		3
															*/
#define TIMER2_PWM_F_MODE_oc2   1

/*Phase Correct PWM Mode*/

   /*
		oc2 disconected  																			1
		Clear oc2 on compare match when up-counting. Set oc2 on compare match when downcounting     2
		Set oc2 on compare match when up-counting. Clear oc2 on comparematch when downcounting		3
															*/
#define TIMER2_PWM_PH_MODE_oc2   1
											
 

#endif
