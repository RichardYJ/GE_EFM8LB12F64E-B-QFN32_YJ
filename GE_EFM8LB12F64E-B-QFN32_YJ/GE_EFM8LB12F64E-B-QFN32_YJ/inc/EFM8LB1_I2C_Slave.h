
#ifndef I2C_SLAVE_H_
#define I2C_SLAVE_H_

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Global Constants
//-----------------------------------------------------------------------------
#define  SYSCLK               24500000 

#define  WRITE                    0x00 
#define  READ                     0x01 

#define  SLAVE_ADDR               0x50 

#define  I2C_STATUS_VECTOR_MASK  0x0F  
// I2C States
#define  I2C_ADDR_RD    0x09			
#define  I2C_ADDR_WR    0x0A			
#define  I2C_RD_DATA    0x01			
#define  I2C_WR_DATA    0x02			
#define  I2C_STO        0x04
#define  I2C_STOSTA     0x0C
#define  I2C_STOSTARD   0x0D


//-----------------------------------------------------------------------------
// Global VARIABLES
//-----------------------------------------------------------------------------
extern uint8_t I2C_DATA[16];          

extern bool DATA_READY;               
extern uint8_t i2cReceivedData;		  
extern bool dataReady;				  
extern uint8_t sendDataValue;		  
extern uint8_t sendDataCnt;			  
extern bool txDataReady; 			  

#endif // SMBUS_SLAVE_H_
