//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!!
//=========================================================

// USER INCLUDES
#include <SI_EFM8LB1_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//================================================================================
// PORTS_2_enter_BusFreeMode_from_RESET
//================================================================================
extern void PORTS_2_enter_BusFreeMode_from_RESET(void) {
	// $[P2 - Port 2 Pin Latch]
	// [P2 - Port 2 Pin Latch]$

	// $[P2MDOUT - Port 2 Output Mode]
	/***********************************************************************
	 - P2.0 output is open-drain
	 - P2.1 output is open-drain
	 - P2.2 output is open-drain
	 - P2.3 output is push-pull
	 - P2.4 output is open-drain
	 - P2.5 output is open-drain
	 - P2.6 output is open-drain
	 ***********************************************************************/
	SFRPAGE = 0x00;
	P2MDOUT = P2MDOUT_B0__OPEN_DRAIN | P2MDOUT_B1__OPEN_DRAIN
			| P2MDOUT_B2__OPEN_DRAIN | P2MDOUT_B3__PUSH_PULL
			| P2MDOUT_B4__OPEN_DRAIN | P2MDOUT_B5__OPEN_DRAIN
			| P2MDOUT_B6__OPEN_DRAIN;
	// [P2MDOUT - Port 2 Output Mode]$

	// $[P2MDIN - Port 2 Input Mode]
	// [P2MDIN - Port 2 Input Mode]$

	// $[P2SKIP - Port 2 Skip]
	/***********************************************************************
	 - P2.0 pin is not skipped by the crossbar
	 - P2.1 pin is not skipped by the crossbar
	 - P2.2 pin is not skipped by the crossbar
	 - P2.3 pin is skipped by the crossbar
	 ***********************************************************************/
	SFRPAGE = 0x20;
	P2SKIP = P2SKIP_B0__NOT_SKIPPED | P2SKIP_B1__NOT_SKIPPED
			| P2SKIP_B2__NOT_SKIPPED | P2SKIP_B3__SKIPPED;
	// [P2SKIP - Port 2 Skip]$

	// $[P2MASK - Port 2 Mask]
	// [P2MASK - Port 2 Mask]$

	// $[P2MAT - Port 2 Match]
	// [P2MAT - Port 2 Match]$

}

//================================================================================
// PBCFG_0_enter_BusFreeMode_from_RESET
//================================================================================
extern void PBCFG_0_enter_BusFreeMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	// [XBR2 - Port I/O Crossbar 2]$

	// $[PRTDRV - Port Drive Strength]
	// [PRTDRV - Port Drive Strength]$

	// $[XBR0 - Port I/O Crossbar 0]
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	// [XBR1 - Port I/O Crossbar 1]$

}

//================================================================================
// CLOCK_0_enter_BusFreeMode_from_RESET
//================================================================================
extern void CLOCK_0_enter_BusFreeMode_from_RESET(void) {
	// $[HFOSC1 Setup]
	// [HFOSC1 Setup]$

	// $[CLKSEL - Clock Select]
	/***********************************************************************
	 - Clock derived from the Internal High Frequency Oscillator 0
	 - SYSCLK is equal to selected clock source divided by 1
	 ***********************************************************************/
	SFRPAGE = 0x00;
	CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
	while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
		;
	// [CLKSEL - Clock Select]$

}

//==============================================================================
// enter_BusFreeMode_from_RESET
//==============================================================================
extern void enter_BusFreeMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	PORTS_2_enter_BusFreeMode_from_RESET();
	PBCFG_0_enter_BusFreeMode_from_RESET();
	CLOCK_0_enter_BusFreeMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	WDT_0_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	TIMER01_0_enter_DefaultMode_from_RESET();
	TIMER16_3_enter_DefaultMode_from_RESET();
	TIMER16_4_enter_DefaultMode_from_RESET();
	TIMER_SETUP_0_enter_DefaultMode_from_RESET();
	SMBUS_0_enter_DefaultMode_from_RESET();
	UARTE_1_enter_DefaultMode_from_RESET();
	I2CSLAVE_0_enter_DefaultMode_from_RESET();
	INTERRUPT_0_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

extern void WDT_0_enter_DefaultMode_from_RESET(void) {
	// $[WDTCN - Watchdog Timer Control]
	SFRPAGE = 0x00;
	//Disable Watchdog with key sequence
	WDTCN = 0xDE; //First key
	WDTCN = 0xAD; //Second key
	// [WDTCN - Watchdog Timer Control]$

}

extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	/***********************************************************************
	 - Weak Pullups enabled 
	 - Crossbar enabled
	 - UART1 TX1 RX1 routed to Port pins
	 - UART1 RTS1 unavailable at Port pin
	 - UART1 CTS1 unavailable at Port pin
	 ***********************************************************************/
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED
			| XBR2_URT1E__ENABLED | XBR2_URT1RTSE__DISABLED
			| XBR2_URT1CTSE__DISABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[PRTDRV - Port Drive Strength]
	// [PRTDRV - Port Drive Strength]$

	// $[XBR0 - Port I/O Crossbar 0]
	/***********************************************************************
	 - UART0 I/O unavailable at Port pin
	 - SPI I/O unavailable at Port pins
	 - SMBus 0 I/O routed to Port pins
	 - CP0 unavailable at Port pin
	 - Asynchronous CP0 unavailable at Port pin
	 - CP1 unavailable at Port pin
	 - Asynchronous CP1 unavailable at Port pin
	 - SYSCLK unavailable at Port pin
	 ***********************************************************************/
	XBR0 = XBR0_URT0E__DISABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__ENABLED
			| XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED | XBR0_CP1E__DISABLED
			| XBR0_CP1AE__DISABLED | XBR0_SYSCKE__DISABLED;
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	// [XBR1 - Port I/O Crossbar 1]$

}

extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {
	// $[HFOSC1 Setup]
	// [HFOSC1 Setup]$

	// $[CLKSEL - Clock Select]
	/***********************************************************************
	 - Clock derived from the Internal High Frequency Oscillator 0
	 - SYSCLK is equal to selected clock source divided by 1
	 ***********************************************************************/
	CLKSEL = CLKSEL_CLKSL__HFOSC0 | CLKSEL_CLKDIV__SYSCLK_DIV_1;
	while ((CLKSEL & CLKSEL_DIVRDY__BMASK) == CLKSEL_DIVRDY__NOT_READY)
		;
	// [CLKSEL - Clock Select]$

}

extern void TIMER01_0_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	//Save Timer Configuration
	uint8_t TCON_save;
	TCON_save = TCON;
	//Stop Timers
	TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

	// [Timer Initialization]$

	// $[TH0 - Timer 0 High Byte]
	/***********************************************************************
	 - Timer 0 High Byte = 0x38
	 ***********************************************************************/
	TH0 = (0x38 << TH0_TH0__SHIFT);
	// [TH0 - Timer 0 High Byte]$

	// $[TL0 - Timer 0 Low Byte]
	/***********************************************************************
	 - Timer 0 Low Byte = 0x13
	 ***********************************************************************/
	TL0 = (0x13 << TL0_TL0__SHIFT);
	// [TL0 - Timer 0 Low Byte]$

	// $[TH1 - Timer 1 High Byte]
	/***********************************************************************
	 - Timer 1 High Byte = 0xE9
	 ***********************************************************************/
	TH1 = (0xE9 << TH1_TH1__SHIFT);
	// [TH1 - Timer 1 High Byte]$

	// $[TL1 - Timer 1 Low Byte]
	// [TL1 - Timer 1 Low Byte]$

	// $[Timer Restoration]
	//Restore Timer Configuration
	TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

	// [Timer Restoration]$

}

extern void TIMER_SETUP_0_enter_DefaultMode_from_RESET(void) {
	// $[CKCON0 - Clock Control 0]
	/***********************************************************************
	 - System clock divided by 4
	 - Counter/Timer 0 uses the clock defined by the prescale field, SCA
	 - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 1 uses the system clock
	 ***********************************************************************/
	SFRPAGE = 0x00;
	CKCON0 = CKCON0_SCA__SYSCLK_DIV_4 | CKCON0_T0M__PRESCALE
			| CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
			| CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
			| CKCON0_T1M__SYSCLK;
	// [CKCON0 - Clock Control 0]$

	// $[CKCON1 - Clock Control 1]
	// [CKCON1 - Clock Control 1]$

	// $[TMOD - Timer 0/1 Mode]
	/***********************************************************************
	 - Mode 0, 13-bit Counter/Timer
	 - Mode 2, 8-bit Counter/Timer with Auto-Reload
	 - Timer Mode
	 - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
	 - Timer Mode
	 - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
	 ***********************************************************************/
	TMOD = TMOD_T0M__MODE0 | TMOD_T1M__MODE2 | TMOD_CT0__TIMER
			| TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
	// [TMOD - Timer 0/1 Mode]$

	// $[TCON - Timer 0/1 Control]
	/***********************************************************************
	 - Start Timer 1 running
	 ***********************************************************************/
	TCON |= TCON_TR1__RUN;
	// [TCON - Timer 0/1 Control]$

}

extern void UART_0_enter_DefaultMode_from_RESET(void) {
	// $[SCON0 - UART0 Serial Port Control]
	/***********************************************************************
	 - UART0 reception enabled
	 ***********************************************************************/
	SCON0 |= SCON0_REN__RECEIVE_ENABLED;
	// [SCON0 - UART0 Serial Port Control]$

}

extern void I2CSLAVE_0_enter_DefaultMode_from_RESET(void) {
	// $[I2C0FCN0 - I2C0 FIFO Control 0]
	/***********************************************************************
	 - RFRQ will be set anytime new data arrives in the RX FIFO 
	 - TFRQ will be set when the TX FIFO is empty
	 - I2C0 interrupts will be generated if RFRQ is set
	 - I2C0 interrupts will be generated if TFRQ is set
	 ***********************************************************************/
	I2C0FCN0 = I2C0FCN0_RXTH__ZERO | I2C0FCN0_TXTH__ZERO
			| I2C0FCN0_RFRQE__ENABLED | I2C0FCN0_TFRQE__ENABLED;
	// [I2C0FCN0 - I2C0 FIFO Control 0]$

	// $[I2C0SLAD - I2C0 Slave Address]
	/***********************************************************************
	 - I2C Hardware Slave Address = 0x50
	 ***********************************************************************/
	I2C0SLAD = (0x50 << I2C0SLAD_I2C0SLAD__SHIFT);
	// [I2C0SLAD - I2C0 Slave Address]$

	// $[I2C0ADM - I2C0 Slave Address Mask]
	// [I2C0ADM - I2C0 Slave Address Mask]$

	// $[I2C0CN0 - I2C0 Control]
	/***********************************************************************
	 - Set the I2C0 Slave pins in I2C mode
	 - Data bytes must be written into the TX FIFO via the I2C0DOUT register
	 before the 8th SCL clock of the matching slave address byte transfer
	 arrives for an I2C read operation
	 - Enable I2C SCL low timeout detection using Timer 4 if Timer 4 RLFSEL
	 is set appropriately
	 - Enable the I2C0 Slave module
	 ***********************************************************************/
	I2C0CN0 &= ~I2C0CN0_PRELOAD__BMASK;
	I2C0CN0 |= I2C0CN0_PINMD__I2C_MODE | I2C0CN0_TIMEOUT__ENABLED;
	I2C0CN0 |= I2C0CN0_I2C0EN__ENABLED;
	// [I2C0CN0 - I2C0 Control]$

}

extern void INTERRUPT_0_enter_DefaultMode_from_RESET(void) {
	// $[EIE1 - Extended Interrupt Enable 1]
	/***********************************************************************
	 - Disable ADC0 Conversion Complete interrupt
	 - Disable ADC0 Window Comparison interrupt
	 - Disable CP0 interrupts
	 - Disable CP1 interrupts
	 - Disable all Port Match interrupts
	 - Disable all PCA0 interrupts
	 - Enable interrupt requests generated by SMB0
	 - Enable interrupt requests generated by the TF3L or TF3H flags
	 ***********************************************************************/
	SFRPAGE = 0x00;
	EIE1 = EIE1_EADC0__DISABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
			| EIE1_ECP1__DISABLED | EIE1_EMAT__DISABLED | EIE1_EPCA0__DISABLED
			| EIE1_ESMB0__ENABLED | EIE1_ET3__ENABLED;
	// [EIE1 - Extended Interrupt Enable 1]$

	// $[EIE2 - Extended Interrupt Enable 2]
	/***********************************************************************
	 - Disable CL0 interrupts
	 - Enable interrupt requests generated by the I2C0 slave
	 - Enable interrupt requests generated by the TF4L or TF4H flags
	 - Disable Timer 5 interrupts
	 - Disable UART1 interrupts
	 ***********************************************************************/
	EIE2 = EIE2_CL0__DISABLED | EIE2_EI2C0__ENABLED | EIE2_ET4__ENABLED
			| EIE2_ET5__DISABLED | EIE2_ES1__DISABLED;
	// [EIE2 - Extended Interrupt Enable 2]$

	// $[EIP1H - Extended Interrupt Priority 1 High]
	// [EIP1H - Extended Interrupt Priority 1 High]$

	// $[EIP1 - Extended Interrupt Priority 1 Low]
	// [EIP1 - Extended Interrupt Priority 1 Low]$

	// $[EIP2 - Extended Interrupt Priority 2]
	// [EIP2 - Extended Interrupt Priority 2]$

	// $[EIP2H - Extended Interrupt Priority 2 High]
	// [EIP2H - Extended Interrupt Priority 2 High]$

	// $[IE - Interrupt Enable]
	/***********************************************************************
	 - Enable each interrupt according to its individual mask setting
	 - Disable external interrupt 0
	 - Disable external interrupt 1
	 - Disable all SPI0 interrupts
	 - Disable all Timer 0 interrupt
	 - Disable all Timer 1 interrupt
	 - Disable Timer 2 interrupt
	 - Enable UART0 interrupt
	 ***********************************************************************/
	IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
			| IE_ESPI0__DISABLED | IE_ET0__DISABLED | IE_ET1__DISABLED
			| IE_ET2__DISABLED | IE_ES0__ENABLED;
	// [IE - Interrupt Enable]$

	// $[IP - Interrupt Priority]
	// [IP - Interrupt Priority]$

	// $[IPH - Interrupt Priority High]
	// [IPH - Interrupt Priority High]$

}

extern void TIMER16_4_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	// Save Timer Configuration
	uint8_t TMR4CN0_TR4_save;
	SFRPAGE = 0x10;
	TMR4CN0_TR4_save = TMR4CN0 & TMR4CN0_TR4__BMASK;
	// Stop Timer
	TMR4CN0 &= ~(TMR4CN0_TR4__BMASK);
	// [Timer Initialization]$

	// $[TMR4CN1 - Timer 4 Control 1]
	// [TMR4CN1 - Timer 4 Control 1]$

	// $[TMR4CN0 - Timer 4 Control]
	// [TMR4CN0 - Timer 4 Control]$

	// $[TMR4H - Timer 4 High Byte]
	// [TMR4H - Timer 4 High Byte]$

	// $[TMR4L - Timer 4 Low Byte]
	// [TMR4L - Timer 4 Low Byte]$

	// $[TMR4RLH - Timer 4 Reload High Byte]
	/***********************************************************************
	 - Timer 4 Reload High Byte = 0x38
	 ***********************************************************************/
	TMR4RLH = (0x38 << TMR4RLH_TMR4RLH__SHIFT);
	// [TMR4RLH - Timer 4 Reload High Byte]$

	// $[TMR4RLL - Timer 4 Reload Low Byte]
	/***********************************************************************
	 - Timer 4 Reload Low Byte = 0x9E
	 ***********************************************************************/
	TMR4RLL = (0x9E << TMR4RLL_TMR4RLL__SHIFT);
	// [TMR4RLL - Timer 4 Reload Low Byte]$

	// $[TMR4CN0]
	/***********************************************************************
	 - Start Timer 4 running
	 ***********************************************************************/
	TMR4CN0 |= TMR4CN0_TR4__RUN;
	// [TMR4CN0]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR4CN0 |= TMR4CN0_TR4_save;
	// [Timer Restoration]$

}

extern void PORTS_0_enter_DefaultMode_from_RESET(void) {
	// $[P0 - Port 0 Pin Latch]
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	/***********************************************************************
	 - P0.0 output is open-drain
	 - P0.1 output is open-drain
	 - P0.2 output is open-drain
	 - P0.3 output is open-drain
	 - P0.4 output is push-pull
	 - P0.5 output is open-drain
	 - P0.6 output is open-drain
	 - P0.7 output is open-drain
	 ***********************************************************************/
	P0MDOUT = P0MDOUT_B0__OPEN_DRAIN | P0MDOUT_B1__OPEN_DRAIN
			| P0MDOUT_B2__OPEN_DRAIN | P0MDOUT_B3__OPEN_DRAIN
			| P0MDOUT_B4__PUSH_PULL | P0MDOUT_B5__OPEN_DRAIN
			| P0MDOUT_B6__OPEN_DRAIN | P0MDOUT_B7__OPEN_DRAIN;
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	/***********************************************************************
	 - P0.0 pin is skipped by the crossbar
	 - P0.1 pin is skipped by the crossbar
	 - P0.2 pin is skipped by the crossbar
	 - P0.3 pin is skipped by the crossbar
	 - P0.4 pin is skipped by the crossbar
	 - P0.5 pin is skipped by the crossbar
	 - P0.6 pin is skipped by the crossbar
	 - P0.7 pin is skipped by the crossbar
	 ***********************************************************************/
	P0SKIP = P0SKIP_B0__SKIPPED | P0SKIP_B1__SKIPPED | P0SKIP_B2__SKIPPED
			| P0SKIP_B3__SKIPPED | P0SKIP_B4__SKIPPED | P0SKIP_B5__SKIPPED
			| P0SKIP_B6__SKIPPED | P0SKIP_B7__SKIPPED;
	// [P0SKIP - Port 0 Skip]$

	// $[P0MASK - Port 0 Mask]
	// [P0MASK - Port 0 Mask]$

	// $[P0MAT - Port 0 Match]
	// [P0MAT - Port 0 Match]$

}

extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[P1 - Port 1 Pin Latch]
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	/***********************************************************************
	 - P1.0 output is open-drain
	 - P1.1 output is open-drain
	 - P1.2 output is open-drain
	 - P1.3 output is open-drain
	 - P1.4 output is push-pull
	 - P1.5 output is open-drain
	 - P1.6 output is open-drain
	 - P1.7 output is open-drain
	 ***********************************************************************/
	P1MDOUT = P1MDOUT_B0__OPEN_DRAIN | P1MDOUT_B1__OPEN_DRAIN
			| P1MDOUT_B2__OPEN_DRAIN | P1MDOUT_B3__OPEN_DRAIN
			| P1MDOUT_B4__PUSH_PULL | P1MDOUT_B5__OPEN_DRAIN
			| P1MDOUT_B6__OPEN_DRAIN | P1MDOUT_B7__OPEN_DRAIN;
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	/***********************************************************************
	 - P1.0 pin is skipped by the crossbar
	 - P1.1 pin is skipped by the crossbar
	 - P1.2 pin is not skipped by the crossbar
	 - P1.3 pin is not skipped by the crossbar
	 - P1.4 pin is not skipped by the crossbar
	 - P1.5 pin is not skipped by the crossbar
	 - P1.6 pin is not skipped by the crossbar
	 - P1.7 pin is not skipped by the crossbar
	 ***********************************************************************/
	P1SKIP = P1SKIP_B0__SKIPPED | P1SKIP_B1__SKIPPED | P1SKIP_B2__NOT_SKIPPED
			| P1SKIP_B3__NOT_SKIPPED | P1SKIP_B4__NOT_SKIPPED
			| P1SKIP_B5__NOT_SKIPPED | P1SKIP_B6__NOT_SKIPPED
			| P1SKIP_B7__NOT_SKIPPED;
	// [P1SKIP - Port 1 Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	// [P1MAT - Port 1 Match]$

}

extern void TIMER16_3_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	// Save Timer Configuration
	uint8_t TMR3CN0_TR3_save;
	TMR3CN0_TR3_save = TMR3CN0 & TMR3CN0_TR3__BMASK;
	// Stop Timer
	TMR3CN0 &= ~(TMR3CN0_TR3__BMASK);
	// [Timer Initialization]$

	// $[TMR3CN1 - Timer 3 Control 1]
	// [TMR3CN1 - Timer 3 Control 1]$

	// $[TMR3CN0 - Timer 3 Control]
	// [TMR3CN0 - Timer 3 Control]$

	// $[TMR3H - Timer 3 High Byte]
	// [TMR3H - Timer 3 High Byte]$

	// $[TMR3L - Timer 3 Low Byte]
	// [TMR3L - Timer 3 Low Byte]$

	// $[TMR3RLH - Timer 3 Reload High Byte]
	/***********************************************************************
	 - Timer 3 Reload High Byte = 0x38
	 ***********************************************************************/
	TMR3RLH = (0x38 << TMR3RLH_TMR3RLH__SHIFT);
	// [TMR3RLH - Timer 3 Reload High Byte]$

	// $[TMR3RLL - Timer 3 Reload Low Byte]
	/***********************************************************************
	 - Timer 3 Reload Low Byte = 0x9E
	 ***********************************************************************/
	TMR3RLL = (0x9E << TMR3RLL_TMR3RLL__SHIFT);
	// [TMR3RLL - Timer 3 Reload Low Byte]$

	// $[TMR3CN0]
	/***********************************************************************
	 - Start Timer 3 running
	 ***********************************************************************/
	TMR3CN0 |= TMR3CN0_TR3__RUN;
	// [TMR3CN0]$

	// $[Timer Restoration]
	// Restore Timer Configuration
	TMR3CN0 |= TMR3CN0_TR3_save;
	// [Timer Restoration]$

}

extern void SMBUS_0_enter_DefaultMode_from_RESET(void) {
	// $[SMB0FCN0 - SMBus0 FIFO Control 0]
	// [SMB0FCN0 - SMBus0 FIFO Control 0]$

	// $[SMB0RXLN - SMBus0 Receive Length Counter]
	// [SMB0RXLN - SMBus0 Receive Length Counter]$

	// $[SMB0ADR - SMBus 0 Slave Address]
	// [SMB0ADR - SMBus 0 Slave Address]$

	// $[SMB0ADM - SMBus 0 Slave Address Mask]
	// [SMB0ADM - SMBus 0 Slave Address Mask]$

	// $[SMB0TC - SMBus 0 Timing and Pin Control]
	// [SMB0TC - SMBus 0 Timing and Pin Control]$

	// $[SMB0CF - SMBus 0 Configuration]
	/***********************************************************************
	 - Timer 1 Overflow
	 - Slave states are inhibited
	 - Enable the SMBus module
	 - Enable bus free timeouts
	 - Enable SCL low timeouts if Timer 3 RLFSEL is set appropriately
	 - Enable SDA extended setup and hold times
	 ***********************************************************************/
	SMB0CF &= ~SMB0CF_SMBCS__FMASK;
	SMB0CF |= SMB0CF_SMBCS__TIMER1 | SMB0CF_INH__SLAVE_DISABLED
			| SMB0CF_ENSMB__ENABLED | SMB0CF_SMBFTE__FREE_TO_ENABLED
			| SMB0CF_SMBTOE__SCL_TO_ENABLED | SMB0CF_EXTHOLD__ENABLED;
	// [SMB0CF - SMBus 0 Configuration]$

}

extern void UARTE_1_enter_DefaultMode_from_RESET(void) {
	// $[SBCON1 - UART1 Baud Rate Generator Control]
	/***********************************************************************
	 - Enable the baud rate generator
	 - Prescaler = 1
	 ***********************************************************************/
	SFRPAGE = 0x20;
	SBCON1 = SBCON1_BREN__ENABLED | SBCON1_BPS__DIV_BY_1;
	// [SBCON1 - UART1 Baud Rate Generator Control]$

	// $[SMOD1 - UART1 Mode]
	// [SMOD1 - UART1 Mode]$

	// $[UART1FCN0 - UART1 FIFO Control 0]
	// [UART1FCN0 - UART1 FIFO Control 0]$

	// $[SBRLH1 - UART1 Baud Rate Generator High Byte]
	/***********************************************************************
	 - UART1 Baud Rate Reload High = 0xFF
	 ***********************************************************************/
	SBRLH1 = (0xFF << SBRLH1_BRH__SHIFT);
	// [SBRLH1 - UART1 Baud Rate Generator High Byte]$

	// $[SBRLL1 - UART1 Baud Rate Generator Low Byte]
	/***********************************************************************
	 - UART1 Baud Rate Reload Low = 0x96
	 ***********************************************************************/
	SBRLL1 = (0x96 << SBRLL1_BRL__SHIFT);
	// [SBRLL1 - UART1 Baud Rate Generator Low Byte]$

	// $[UART1LIN - UART1 LIN Configuration]
	// [UART1LIN - UART1 LIN Configuration]$

	// $[SCON1 - UART1 Serial Port Control]
	/***********************************************************************
	 - UART1 reception enabled
	 ***********************************************************************/
	SCON1 |= SCON1_REN__RECEIVE_ENABLED;
	// [SCON1 - UART1 Serial Port Control]$

	// $[UART1FCN1 - UART1 FIFO Control 1]
	// [UART1FCN1 - UART1 FIFO Control 1]$

}

