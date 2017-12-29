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
	uint8_t i;
	switch (I2C0STAT & I2C_STATUS_VECTOR_MASK) {

		case I2C_ADDR_RD:  // START+ADDR+R
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_RD__BMASK);
		I2C0DOUT = I2C_DATA;// Write data to buffer for transmitting
		break;

		case I2C_ADDR_WR:// START+ADDR+W
		I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_WR__BMASK);
		break;

		case I2C_RD_DATA://RD
		// Check for NACK
		if ((I2C0STAT & I2C0STAT_NACK__BMASK) == I2C0STAT_NACK__SET) {
			// Master did not NACK
			// Stopping transfer of data
			// Flush FIFO if there is data in it
			I2C0STAT &= ~I2C0STAT_NACK__BMASK;
		} else { // Prepare data for master
			I2C0DOUT = I2C_DATA;
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
		I2C_DATA[i] = I2C0DIN;// This example only supports host write 1 byte to slave
		// If want slave to accept more than 1 byte, use a buffer to save the data from FIFO
		DATA_READY = 1;
		if(i<16) i++;
	}

	// Clear I2C interrupt flag
	I2C0STAT &= ~I2C0STAT_I2C0INT__BMASK;
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
