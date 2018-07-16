
#ifndef SMBUS_MASTER_MULTIBYTE_H_
#define SMBUS_MASTER_MULTIBYTE_H_

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------
SI_SBIT (SDA, SFR_P1, 2);              
SI_SBIT (SCL, SFR_P1, 3);              

SI_SBIT (LED1, SFR_P1, 6);             
#define LED_ON   0
#define LED_OFF  1

SI_SBIT (DISP_EN, SFR_P3, 4);          
#define DISP_BC_DRIVEN   0             
#define DISP_EFM8_DRIVEN 1             

//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------

#define  SYSCLK               24500000 

#define  SMB_FREQUENCY           10000 

#define  WRITE                    0x00 
#define  READ                     0x01 


#define  TARGET_ADDR               0x10 


#define  SMB_MTSTA                0xE0
#define  SMB_MTDB                 0xC0
#define  SMB_MRDB                 0x80


#define  NUM_BYTES_WR                4  
#define  NUM_BYTES_RD                2 
//-----------------------------------------------------------------------------
// Global VARIABLES
//-----------------------------------------------------------------------------



extern uint8_t SMB_DATA_IN[NUM_BYTES_RD];

extern uint8_t SMB_DATA_OUT[NUM_BYTES_WR];

extern uint8_t TARGET;                

extern volatile bool SMB_BUSY;        
extern volatile bool SMB_RW;          
extern uint16_t NUM_ERRORS;           


#endif // SMBUS_MASTER_MULTIBYTE_H_
//-----------------------------------------------------------------------------
// End Of File
//-----------------------------------------------------------------------------
