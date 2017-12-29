//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8LB1_Register_Enums.h>
#include "EFM8LB1_I2C_Slave.h"


typedef enum
{
    SLAVE_NORMAL_DATA,
    SLAVE_DATA_ADDRESS,
} SLAVE_WRITE_DATA_TYPE;

volatile uint8_t	I2C1_slaveWriteData 	 = 0x55;

    //static uint8_t EEPROM_Buffer[] =
uint8_t EEPROM_Buffer[] =
{
    17,		//B0
5,
6,
};
/*0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
56,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,		//B127
17,
0,
35,
128,	//136
0,
112,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
1,
8,
70,
73,
84,
32,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
31,
0,
9,
58,
49,
48,
48,
50,
57,
55,
49,
49,
48,
49,
32,
32,
32,
32,
32,
32,
49,
32,
66,
104,
7,
208,
0,
99,
2,				//CR4=11 SR4=2 AOC=1��24
0,
0,
0,
53,
50,
56,
54,
50,
48,
55,
53,
48,
32,
32,
32,
32,
32,
32,
32,
49,
53,
49,
48,
49,
51,
32,
32,
0,
0,
0,
41,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,
0,

};
*/
//-----------------------------------------------------------------------------
// I2C0_ISR
//-----------------------------------------------------------------------------
//
// I2C0 ISR Content goes here. Remember to clear flag bits:
// I2C0STAT::I2C0INT (I2C Interrupt)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (I2C0_ISR, I2C0_IRQn)
{//д�Ƿ��豸��ַ д+reg��ַ+���ݡ����Ƿ��豸��ַ д+reg��ַ+���豸��ַ �� + ��������
#if 1
	static uint16_t eepromAddress	 = 0;  //for addressing larger than 256Byte
	static uint8_t slaveWriteType	= SLAVE_NORMAL_DATA;
	static uint8_t WriteStat;
	uint8_t i = 0;
	switch (I2C0STAT & I2C_STATUS_VECTOR_MASK) {

		case I2C_ADDR_RD:  // START+ADDR+R
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_RD__BMASK);
		//I2C0DOUT = 0x11;//I2C_DATA[0];// Write data to buffer for transmitting
		I2C0DOUT = EEPROM_Buffer[eepromAddress++];
		if(sizeof(EEPROM_Buffer) <= eepromAddress)	//this compare will cost too many mcu time, will cause SCL conflict,unless set MCU to 32MHz
		{
		   eepromAddress = 0;	 // wrap to start of eeprom page
		}
		break;

		case I2C_ADDR_WR:// START+ADDR+W
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_WR__BMASK);
		// the master will be sending the eeprom address next
		slaveWriteType	= SLAVE_DATA_ADDRESS;
		WriteStat = 0;
		break;

		case I2C_RD_DATA://RD
		// Check for NACK
		if ((I2C0STAT & I2C0STAT_NACK__BMASK) == I2C0STAT_NACK__SET) {
			// Master did not NACK
			// Stopping transfer of data
			// Flush FIFO if there is data in it
			I2C0STAT &= ~I2C0STAT_NACK__BMASK;
		} else { // Prepare data for master
			I2C0DOUT = 0x22;//I2C_DATA[0];
		}
		I2C0STAT &= ~I2C0STAT_RD__BMASK;
		break;

		case I2C_WR_DATA: 	//WR // FIFO is full, whatever slave ACK/NACK master
		I2C0STAT &= ~I2C0STAT_WR__BMASK;
#if 0
				I2C1_slaveWriteData = I2C0DIN;
					
				switch(slaveWriteType)
				{
					case SLAVE_DATA_ADDRESS:
						if(I2C1_slaveWriteData>=128)
						{
						 eepromAddress	  = I2C1_slaveWriteData+128*EEPROM_Buffer[127] ;   
						}
						else
						{
						 eepromAddress	  = I2C1_slaveWriteData;   
						}
					break;
			
			
					case SLAVE_NORMAL_DATA:
					default:
						EEPROM_Buffer[eepromAddress++]	  = I2C1_slaveWriteData;   
					 
						
						if(sizeof(EEPROM_Buffer) <= eepromAddress) //this compare will cost too many mcu time, will cause SCL conflict,unless set MCU to 32MHz
						{
						eepromAddress = 0;	  // wrap to start of eeprom page
						}
					break;
				} // end switch(slaveWriteType)
			
				slaveWriteType	= SLAVE_NORMAL_DATA;
#endif				
		break;

		case I2C_STOSTA:		//stop ��start���յ������ڶ�����
		case I2C_STOSTARD:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
		//
		//	STOP Condition received.
		//
		return;// START Flag set, so re-enter ISR
		break;
/*
		case :

		break;
*/
		case I2C_STO:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
#if 0		
		if(0 == WriteStat)
			WriteStat = 1;
#endif		
		//
		//	STOP Condition received.
		//
		break;
		default:
		break;
	}

#if 1
	// Poll this bit is also OK
	// while(I2C0FCT&I2C0FCT_RXCNT__FMASK) {
	while((I2C0FCN1 & I2C0FCN1_RXE__BMASK) == I2C0FCN1_RXE__NOT_EMPTY) { // Read data out
#if 0
		I2C_DATA[0] = I2C0DIN;// This example only supports host write 1 byte to slave
		// If want slave to accept more than 1 byte, use a buffer to save the data from FIFO
		DATA_READY = 1;
		if(i<16) i++;
#else
		//if(1==WriteStat)
			I2C1_slaveWriteData = I2C0DIN;
		switch(slaveWriteType)
		{
			case SLAVE_DATA_ADDRESS:
				if(I2C1_slaveWriteData>=128)
				{
				 eepromAddress	  = I2C1_slaveWriteData+128*EEPROM_Buffer[127] ;   
				}
				else
				{
				 eepromAddress	  = I2C1_slaveWriteData;   
				}
			break;
	
	
			case SLAVE_NORMAL_DATA:
			default:
				EEPROM_Buffer[eepromAddress++]	  = I2C1_slaveWriteData;   
			 
				
				if(sizeof(EEPROM_Buffer) <= eepromAddress) //this compare will cost too many mcu time, will cause SCL conflict,unless set MCU to 32MHz
				{
				eepromAddress = 0;	  // wrap to start of eeprom page
				}
			break;
		} // end switch(slaveWriteType)
	
		slaveWriteType	= SLAVE_NORMAL_DATA;
#endif				
	}
#endif
	// Clear I2C interrupt flag
	I2C0STAT &= ~I2C0STAT_I2C0INT__BMASK;
#if 0
	static uint16_t eepromAddress	 = 0;  //for addressing larger than 256Byte
	static uint8_t slaveWriteType	= SLAVE_NORMAL_DATA;
	
	
	switch (i2c_bus_state)
	{
		case I2C1_SLAVE_WRITE_REQUEST:
			// the master will be sending the eeprom address next
			slaveWriteType	= SLAVE_DATA_ADDRESS;
		break;
	
	
		case I2C1_SLAVE_WRITE_COMPLETED:
			switch(slaveWriteType)
			{
				case SLAVE_DATA_ADDRESS:
					if(I2C1_slaveWriteData>=128)
					{
					 eepromAddress	  = I2C1_slaveWriteData+128*EEPROM_Buffer[127] ;   
					}
					else
					{
					 eepromAddress	  = I2C1_slaveWriteData;   
					}
				break;
	
	
				case SLAVE_NORMAL_DATA:
				default:
					EEPROM_Buffer[eepromAddress++]	  = I2C1_slaveWriteData;   
				 
					
					if(sizeof(EEPROM_Buffer) <= eepromAddress) //this compare will cost too many mcu time, will cause SCL conflict,unless set MCU to 32MHz
					{
					eepromAddress = 0;	  // wrap to start of eeprom page
					}
				break;
			} // end switch(slaveWriteType)
	
		slaveWriteType	= SLAVE_NORMAL_DATA;
		break;
	
		case I2C1_SLAVE_READ_REQUEST:
			SSP1BUF = EEPROM_Buffer[eepromAddress++];
			if(sizeof(EEPROM_Buffer) <= eepromAddress)	//this compare will cost too many mcu time, will cause SCL conflict,unless set MCU to 32MHz
			{
			   eepromAddress = 0;	 // wrap to start of eeprom page
			}
			break;
	
		case I2C1_SLAVE_READ_COMPLETED:
		default:;
		 
	} // end switch(i2c_bus_state)
	
#endif

#else

	uint8_t i = 0;
	switch (I2C0STAT & I2C_STATUS_VECTOR_MASK) {

		case I2C_ADDR_RD:  // START+ADDR+R
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_RD__BMASK);
		I2C0DOUT = 0x11;//I2C_DATA[0];// Write data to buffer for transmitting
		break;

		case I2C_ADDR_WR:// START+ADDR+W
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_WR__BMASK);
//		I2C_DATA[0] = I2C0DIN;
		break;

		case I2C_RD_DATA://RD
		// Check for NACK
		if ((I2C0STAT & I2C0STAT_NACK__BMASK) == I2C0STAT_NACK__SET) {
			// Master did not NACK
			// Stopping transfer of data
			// Flush FIFO if there is data in it
			I2C0STAT &= ~I2C0STAT_NACK__BMASK;
		} else { // Prepare data for master
			I2C0DOUT = 0x22;//I2C_DATA[0];
		}
		I2C0STAT &= ~I2C0STAT_RD__BMASK;
		break;

		case I2C_WR_DATA: 	//WR // FIFO is full, whatever slave ACK/NACK master
		I2C0STAT &= ~I2C0STAT_WR__BMASK;
		break;

		case I2C_STOSTA:
		case I2C_STOSTARD:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
		//
		//	STOP Condition received.
		//
		return;// START Flag set, so re-enter ISR
		break;

		case I2C_STO:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
		//
		//	STOP Condition received.
		//
		break;
		default:
		break;
	}

	// Poll this bit is also OK
	// while(I2C0FCT&I2C0FCT_RXCNT__FMASK) {
	while((I2C0FCN1 & I2C0FCN1_RXE__BMASK) == I2C0FCN1_RXE__NOT_EMPTY) { // Read data out
		I2C_DATA[0] = I2C0DIN;// This example only supports host write 1 byte to slave
		// If want slave to accept more than 1 byte, use a buffer to save the data from FIFO
		DATA_READY = 1;
		if(i<16) i++;
	}

	// Clear I2C interrupt flag
	I2C0STAT &= ~I2C0STAT_I2C0INT__BMASK;

#endif


	

	
}

//-----------------------------------------------------------------------------
// TIMER4_ISR
//-----------------------------------------------------------------------------
//
// TIMER4 ISR Content goes here. Remember to clear flag bits:
// TMR4CN0::TF4H (Timer # High Byte Overflow Flag)
// TMR4CN0::TF4L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER4_ISR, TIMER4_IRQn)
{
	SFRPAGE = PG3_PAGE;

	I2C0CN0 &= ~I2C0CN0_I2C0EN__BMASK;			// Disable I2C module
	I2C0CN0 |= I2C0CN0_I2C0EN__ENABLED;// Re-enable I2C module

	SFRPAGE = PG2_PAGE;
	TMR4CN0 &= ~TMR4CN0_TF4H__BMASK;// Clear Timer3 interrupt-pending flag
}

//-----------------------------------------------------------------------------
// UART0_ISR
//-----------------------------------------------------------------------------
//
// UART0 ISR Content goes here. Remember to clear flag bits:
// SCON0::RI (Receive Interrupt Flag)
// SCON0::TI (Transmit Interrupt Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (UART0_ISR, UART0_IRQn)
{

}
