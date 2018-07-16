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

//-----------------------------------------------------------------------------
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

   if (SMB0CN0_ARBLOST == 0)           // Check for errors
   {
      // Normal operation
      switch (SMB0CN0 & 0xF0)          // Status vector
      {
         // Master Transmitter/Receiver: START condition transmitted.
         case SMB_MTSTA:
            SMB0DAT = TARGET<<1;          // Load address of the target slave
            SMB0DAT &= 0xFE;           // Clear the LSB of the address for the
                                       // R/W bit
            SMB0DAT |= (uint8_t) SMB_RW;    // Load R/W bit
            SMB0CN0_STA = 0;           // Manually clear START bit
            rec_byte_counter = 1;      // Reset the counter
            sent_byte_counter = 1;     // Reset the counter
            break;

         // Master Transmitter: Data byte transmitted
         case SMB_MTDB:
            if (SMB0CN0_ACK)           // Slave SMB0CN0_ACK?
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
                     SMB0CN0_STO = 1;  // Set SMB0CN0_STO to terminate transfer
                     SMB_BUSY = 0;     // And free SMBus interface
                  }
               }
               else {}                 // If this transfer is a READ,
                                       // proceed with transfer without
                                       // writing to SMB0DAT (switch
                                       // to receive mode)

            }
            else                       // If slave NACK,
            {
               SMB0CN0_STO = 1;        // Send STOP condition, followed
               SMB0CN0_STA = 1;        // By a START
               NUM_ERRORS++;           // Indicate error
            }
            break;

         // Master Receiver: byte received
         case SMB_MRDB:
            if (rec_byte_counter < NUM_BYTES_RD)
            {
               SMB_DATA_IN[rec_byte_counter-1] = SMB0DAT; // Store received
                                                          // byte
               SMB0CN0_ACK = 1;        // Send SMB0CN0_ACK to indicate byte received
               rec_byte_counter++;     // Increment the byte counter
            }
            else
            {
               SMB_DATA_IN[rec_byte_counter-1] = SMB0DAT; // Store received
                                                          // byte
               SMB_BUSY = 0;           // Free SMBus interface
               SMB0CN0_ACK = 0;        // Send NACK to indicate last byte
                                       // of this transfer

               SMB0CN0_STO = 1;        // Send STOP to terminate transfer
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

   if (FAIL)                           // If the transfer failed,
   {
      SMB0CF &= ~0x80;                 // Reset communication
      SMB0CF |= 0x80;
      SMB0CN0_STA = 0;
      SMB0CN0_STO = 0;
      SMB0CN0_ACK = 0;

      SMB_BUSY = 0;                    // Free SMBus

      FAIL = 0;
      LED1 = 0;

      NUM_ERRORS++;                    // Indicate an error occurred
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
   SMB0CF  &= ~0x80;                   // Disable SMBus
   SMB0CF  |=  0x80;                   // Re-enable SMBus
   TMR3CN0 &= ~0x80;                   // Clear Timer3 interrupt-pending
                                       // flag
   SMB0CN0_STA = 0;
   SMB_BUSY = 0;                       // Free SMBus
}

