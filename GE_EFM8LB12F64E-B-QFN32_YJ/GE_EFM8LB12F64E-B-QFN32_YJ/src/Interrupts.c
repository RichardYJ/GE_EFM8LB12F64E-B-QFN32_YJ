//=========================================================
// src/Interrupts.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8LB1_Register_Enums.h>
#include "EFM8LB1_SMBus_MasterMultibyte.h"
#include "EFM8LB1_I2C_Slave.h"
typedef enum {
	SLAVE_NORMAL_DATA, SLAVE_DATA_ADDRESS,
} SLAVE_WRITE_DATA_TYPE;

extern volatile uint8_t nWR;
extern uint32_t ADC_AVG;               // Accumulates the ADC samples
extern bool CONV_COMPLETE;              // ADC accumulated result ready flag
uint8_t iArry = 0;
bool bTx_4th_byte_nack = false;

//#if 1//开放就会影响SMBUS0?         第一次测试时SMBUS0停止了（不能确定），后面每次测试都是成功的，SMBUS0频率为10.008KHZ,LED1好像是不能点亮了。
volatile uint8_t I2C1_slaveWriteData = 0x16;
//const uint8_t cConst[10];
#if 0
uint8_t EEPROM_Buffer[3] = {0, 1, 2}; //[64] = { 0 };
#else
//pdata volatile static 
uint8_t EEPROM_Buffer[] =
//uint8_t EEPROM_Buffer[] =
		{
				17,		//B0
				5, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0,

				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 56, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0,		//B127

				17, 0, 35,
				128,		//136
				0, 112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 8, 70, 73, 84,
				32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31, 0, 9, 58, 49, 48,
				48, 50, 57, 55, 49, 49, 48, 49, 32, 32, 32, 32, 32, 32, 49, 32,
				66, 104, 7, 208, 0, 99,
				2,		//CR4=11 SR4=2 AOC=1?ò24
				0, 0, 0, 53, 50, 56, 54, 50, 48, 55, 53, 48, 32, 32, 32, 32, 32,
				32, 32, 49, 53, 49, 48, 49, 51, 32, 32, 0, 0, 0, 41,

				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
				0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,

		};
#endif
uint8_t dbg_Buffer[512]={0};
static uint16_t k=0;
//-----------------------------------------------------------------------------
// I2C0_ISR
//-----------------------------------------------------------------------------
//
// I2C0 ISR Content goes here. Remember to clear flag bits:
// I2C0STAT::I2C0INT (I2C Interrupt)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (I2C0_ISR, I2C0_IRQn)
{
	static uint16_t eepromAddress = 0;  //for addressing larger than 256Byte
	static uint8_t slaveWriteType = SLAVE_NORMAL_DATA;
	static uint8_t WriteStat = 0;
	uint8_t t,j;

	uint8_t SAVE_SFRPAGE;
	bool EA_SAVE = IE_EA;				 // Preserve IE_EA
	IE_EA = 0;							// Disable interrupts
	SAVE_SFRPAGE = SFRPAGE;
	SFRPAGE = 0x20;

	switch (I2C0STAT & I2C_STATUS_VECTOR_MASK) {

		case I2C_ADDR_RD:
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_RD__BMASK);
		t = EEPROM_Buffer[eepromAddress++];
		if(0x0==t)
		{
			j=t;
		}
		I2C0DOUT = t;//EEPROM_Buffer[eepromAddress++];
		dbg_Buffer[k++]=t;
		if(sizeof(EEPROM_Buffer) <= eepromAddress)
		{
			eepromAddress = 0;
		}
		WriteStat = 0;
		break;

		case I2C_ADDR_WR:
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_WR__BMASK);
		slaveWriteType = SLAVE_DATA_ADDRESS;
		WriteStat = 1;
		break;

		case I2C_RD_DATA:
		if ((I2C0STAT & I2C0STAT_NACK__BMASK) == I2C0STAT_NACK__SET) {
			I2C0STAT &= ~I2C0STAT_NACK__BMASK;
		} else {
			t = EEPROM_Buffer[eepromAddress++];
			if(0x11==t)
			{
				j=t;
			}
			I2C0DOUT = t;
			dbg_Buffer[k++]=t;

			if(sizeof(EEPROM_Buffer) <= eepromAddress)
			{
				eepromAddress = 0;
			}
		}
		I2C0STAT &= ~I2C0STAT_RD__BMASK;
		break;

		case I2C_WR_DATA:
		I2C0STAT &= ~I2C0STAT_WR__BMASK;

		break;

		case I2C_STOSTA:
		case I2C_STOSTARD:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
#if 0
		I2C0CN0 &= ~I2C0CN0_BUSY__BMASK;		// Clear BUSY bit
		I2C0CN0 |= I2C0FCN0_RFLSH__FLUSH | I2C0FCN0_TFLSH__FLUSH;
#endif
		
//		WriteStat = 0;//added 20180122
		return;
		break;

		case I2C_STO:
		I2C0STAT &= ~I2C0STAT_STOP__BMASK;
#if 0
		I2C0CN0 &= ~I2C0CN0_BUSY__BMASK;		// Clear BUSY bit
		I2C0CN0 |= I2C0FCN0_RFLSH__FLUSH | I2C0FCN0_TFLSH__FLUSH;
#endif
		
//		WriteStat = 0;//added 20180122
		break;
		default:
		break;
	}

	while((I2C0FCN1 & I2C0FCN1_RXE__BMASK) == I2C0FCN1_RXE__NOT_EMPTY) {
		I2C1_slaveWriteData = I2C0DIN;
		if(1==WriteStat&&80!=I2C1_slaveWriteData)
		{
			switch(slaveWriteType)
			{
				case SLAVE_DATA_ADDRESS:
				if(I2C1_slaveWriteData>=128)
				{
					eepromAddress = I2C1_slaveWriteData+128*EEPROM_Buffer[127];
				}
				else
				{
					eepromAddress = I2C1_slaveWriteData;
				}
				break;

				case SLAVE_NORMAL_DATA:
				default:
				EEPROM_Buffer[eepromAddress++] = I2C1_slaveWriteData;

				if(sizeof(EEPROM_Buffer) <= eepromAddress)
				{
					eepromAddress = 0;
				}
				break;
			}

			slaveWriteType = SLAVE_NORMAL_DATA;
//			WriteStat = 0;//added 20180122
		}
	}

	I2C0STAT &= ~I2C0STAT_I2C0INT__BMASK;
	SFRPAGE = SAVE_SFRPAGE;
	IE_EA = EA_SAVE;					// Restore interrupts

}

// SMBUS0_ISR
//-----------------------------------------------------------------------------
//
// SMBUS0 ISR Content goes here. Remember to clear flag bits:
// SMB0CN0::SI (SMBus Interrupt Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (SMBUS0_ISR, SMBUS0_IRQn)
{
	bool FAIL = 0;                       // Used by the ISR to flag failed
										 // transfers

	static uint8_t sent_byte_counter;
	static uint8_t rec_byte_counter;

	if (SMB0CN0_ARBLOST == 0)		 // Check for errors
	{
		// Normal operation
		switch (SMB0CN0 & 0xF0)// Status vector
		{
			// Master Transmitter/Receiver: START condition transmitted.
			case SMB_MTSTA:
			SMB0DAT = TARGET<<1;// Load address of the target slave
			SMB0DAT &= 0xFE;	// Clear the LSB of the address for the
								// R/W bit
			SMB0DAT |= (uint8_t) SMB_RW;// Load R/W bit
			SMB0CN0_STA = 0;// Manually clear START bit
			rec_byte_counter = 1;// Reset the counter
			sent_byte_counter = 1;// Reset the counter
			break;

			// Master Transmitter: Data byte transmitted
			case SMB_MTDB:
			if (SMB0CN0_ACK)// Slave SMB0CN0_ACK?
			{
				if (SMB_RW == WRITE)    // If this transfer is a WRITE,
				{
					if (sent_byte_counter <= nWR /*NUM_BYTES_WR*/)
					{
						// send data byte
						SMB0DAT = SMB_DATA_OUT[sent_byte_counter-1];
						sent_byte_counter++;
					}
					else
					{
						SMB0CN0_STO = 1; // Set SMB0CN0_STO to terminate transfer
						SMB_BUSY = 0;// And free SMBus interface
					}
				}
				else {}                 // If this transfer is a READ,
										// proceed with transfer without
										// writing to SMB0DAT (switch
										// to receive mode)

			}
			else                       // If slave NACK,
			{
				if(bTx_4th_byte_nack)
				{
					SMB0CN0_STO = 1; // Set SMB0CN0_STO to terminate transfer
					SMB_BUSY = 0;// And free SMBus interface
					break;
				}
				SMB0CN0_STO = 1;        // Send STOP condition, followed
				SMB0CN0_STA = 1;// By a START
				NUM_ERRORS++;// Indicate error
			}
			break;

			// Master Receiver: byte received
			case SMB_MRDB:
			if (rec_byte_counter < NUM_BYTES_RD)
			{
				SMB_DATA_IN[rec_byte_counter-1] = SMB0DAT; // Store received
														   // byte
				SMB0CN0_ACK = 1;						   // Send SMB0CN0_ACK to indicate byte received
				rec_byte_counter++;						   // Increment the byte counter
			}
			else
			{
				SMB_DATA_IN[rec_byte_counter-1] = SMB0DAT; // Store received
														   // byte
				SMB_BUSY = 0;							   // Free SMBus interface
				SMB0CN0_ACK = 0;						   // Send NACK to indicate last byte
														   // of this transfer

				SMB0CN0_STO = 1;						   // Send STOP to terminate transfer
			}
			break;

			default:
			FAIL = 1;                  // Indicate failed transfer
									   // and handle at end of ISR
			break;

		} // end switch
	}
	else
	{
		// SMB0CN0_ARBLOST = 1, error occurred... abort transmission
		FAIL = 1;
	} // end SMB0CN0_ARBLOST if

	if (FAIL)// If the transfer failed,
	{
		SMB0CF &= ~0x80;                 // Reset communication
		SMB0CF |= 0x80;
		SMB0CN0_STA = 0;
		SMB0CN0_STO = 0;
		SMB0CN0_ACK = 0;

		SMB_BUSY = 0;// Free SMBus

		FAIL = 0;
//		LED1 = 0;

		NUM_ERRORS++;// Indicate an error occurred
	}

	SMB0CN0_SI = 0;                     // Clear interrupt flag
}

//-----------------------------------------------------------------------------
// TIMER3_ISR
//-----------------------------------------------------------------------------
//
// TIMER3 ISR Content goes here. Remember to clear flag bits:
// TMR3CN0::TF3H (Timer # High Byte Overflow Flag)
// TMR3CN0::TF3L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (TIMER3_ISR, TIMER3_IRQn)
{
	SMB0CF &= ~0x80;                   // Disable SMBus
	SMB0CF |= 0x80;// Re-enable SMBus
	TMR3CN0 &= ~0x80;// Clear Timer3 interrupt-pending
				   // flag
	SMB0CN0_STA = 0;
	SMB_BUSY = 0;  // Free SMBus
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
// ADC0EOC_ISR
//-----------------------------------------------------------------------------
//
// ADC0EOC ISR Content goes here. Remember to clear flag bits:
// ADC0CN0::ADINT (Conversion Complete Interrupt Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT (ADC0EOC_ISR, ADC0EOC_IRQn)
{
	   ADC0CN0_ADINT = 0;               // Clear ADC0 conv. complete flag
	   ADC_AVG = ADC0/4;
	   CONV_COMPLETE = 1;               // Set result ready flag

}

