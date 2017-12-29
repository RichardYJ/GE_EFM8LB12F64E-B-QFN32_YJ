//=========================================================
// src/GE_EFM8LB12F64E-B-QFN32_YJ_main.c: generated by Hardware Configurator
//
// This file will be updated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

//-----------------------------------------------------------------------------
// Includes
//-----------------------------------------------------------------------------
#include <SI_EFM8LB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include "EFM8LB1_I2C_Slave.h"
// $[Generated Includes]
// [Generated Includes]$
//-----------------------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------------------
uint8_t I2C_DATA[16];                      // Global holder for SMBus data.
// All receive data is written
// here;
// all transmit data is read
// from here

bool DATA_READY = 0;                    // Set to '1' by the SMBus ISR
// when a new data byte has been
// received.

//-----------------------------------------------------------------------------
// SiLabs_Startup() Routine
// ----------------------------------------------------------------------------
// This function is called immediately after reset, before the initialization
// code is run in SILABS_STARTUP.A51 (which runs before main() ). This is a
// useful place to disable the watchdog timer, which is enable by default
// and may trigger before main() in some instances.
//-----------------------------------------------------------------------------
void SiLabs_Startup(void) {
	// $[SiLabs Startup]
	// [SiLabs Startup]$
}

//-----------------------------------------------------------------------------
// main() Routine
// ----------------------------------------------------------------------------
int main(void) {
	// Call hardware initialization routine
	enter_DefaultMode_from_RESET();

	DISP_EN = DISP_BC_DRIVEN;           // EFM8 does not drive display

	I2C_DATA[0] = 0xFD;                    // Initialize SMBus data holder

	LED1 = 1;
	while (1) {
// $[Generated Run-time code]
// [Generated Run-time code]$
		IE_EA = 0;
		SFRPAGE = PG3_PAGE;
		I2C0CN0 &= ~I2C0CN0_BUSY__BMASK;		// Clear BUSY bit
		I2C0CN0 |= I2C0FCN0_RFLSH__FLUSH | I2C0FCN0_TFLSH__FLUSH;
		IE_EA = 1;

		while (!DATA_READY)
			;             // New I2C data received?
		DATA_READY = 0;
		LED1 = !LED1;
//		I2C_DATA = 0xff;
	}
}
