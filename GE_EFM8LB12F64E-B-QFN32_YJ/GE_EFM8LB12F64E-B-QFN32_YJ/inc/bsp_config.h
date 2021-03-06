/////////////////////////////////////////////////////////////////////////////
// bsp_config.h
/////////////////////////////////////////////////////////////////////////////

#ifndef BSP_CONFIG_H_
#define BSP_CONFIG_H_

/////////////////////////////////////////////////////////////////////////////
// Includes
/////////////////////////////////////////////////////////////////////////////

#include <SI_EFM8LB1_Register_Enums.h>

/////////////////////////////////////////////////////////////////////////////
// Defines
/////////////////////////////////////////////////////////////////////////////

#define BSP_PB_PRESSED          0
#define BSP_PB_UNPRESSED        1

#define BSP_LED_ON              0
#define BSP_LED_OFF             1


#define BSP_DISP_BC_DRIVEN      0      
#define BSP_DISP_EFM8_DRIVEN    1      


#define BSP_BC_DISCONNECTED     0      
#define BSP_BC_CONNECTED        1      


SI_SBIT(BSP_DISP_EN, SFR_P3, 4);
SI_SBIT(BSP_DISP_CS, SFR_P2, 6);

SI_SBIT(BSP_PB0, SFR_P0, 2);
SI_SBIT(BSP_PB1, SFR_P0, 3);

SI_SBIT(BSP_JOYSTICK, SFR_P1, 7);

SI_SBIT(BSP_LED_G, SFR_P1, 4);
SI_SBIT(BSP_LED_B, SFR_P1, 5);
SI_SBIT(BSP_LED_R, SFR_P1, 6);

SI_SBIT(BSP_BC_EN, SFR_P2, 2);

#endif /* BSP_CONFIG_H_ */
