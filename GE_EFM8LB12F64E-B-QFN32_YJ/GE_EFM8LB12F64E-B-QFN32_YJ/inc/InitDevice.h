#ifndef __INIT_DEVICE_H__
#define __INIT_DEVICE_H__

extern void enter_BusFreeMode_from_RESET(void);
extern void enter_DefaultMode_from_BusFreeMode(void);
extern void CLOCK_0_enter_BusFreeMode_from_RESET(void);
extern void WDT_0_enter_DefaultMode_from_BusFreeMode(void);
extern void PORTS_0_enter_DefaultMode_from_BusFreeMode(void);
extern void PORTS_1_enter_DefaultMode_from_BusFreeMode(void);
extern void PBCFG_0_enter_DefaultMode_from_BusFreeMode(void);
extern void ADC_0_enter_DefaultMode_from_BusFreeMode(void);
extern void TIMER01_0_enter_DefaultMode_from_BusFreeMode(void);
extern void TIMER16_3_enter_DefaultMode_from_BusFreeMode(void);
extern void TIMER16_4_enter_DefaultMode_from_BusFreeMode(void);
extern void TIMER16_5_enter_DefaultMode_from_BusFreeMode(void);
extern void TIMER_SETUP_0_enter_DefaultMode_from_BusFreeMode(void);
extern void SMBUS_0_enter_DefaultMode_from_BusFreeMode(void);
extern void UARTE_1_enter_DefaultMode_from_BusFreeMode(void);
extern void I2CSLAVE_0_enter_DefaultMode_from_BusFreeMode(void);
extern void INTERRUPT_0_enter_DefaultMode_from_BusFreeMode(void);


#endif

