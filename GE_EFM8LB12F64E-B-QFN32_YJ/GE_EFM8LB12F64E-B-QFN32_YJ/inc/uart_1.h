
#ifndef __UART_1_H__
#define __UART_1_H__


#include "efm8_config.h"
#include "SI_EFM8LB1_Register_Enums.h"


#ifndef IS_DOXYGEN
  #define IS_DOXYGEN 0
#endif

#ifndef EFM8PDL_UART1_AUTO_PAGE
#define EFM8PDL_UART1_AUTO_PAGE 1
#endif
#ifndef EFM8PDL_UART1_USE_STDIO
#define EFM8PDL_UART1_USE_STDIO 0
#endif
#ifndef EFM8PDL_UART1_USE_BUFFER
  #if (!EFM8PDL_UART1_USE_STDIO)
    #define EFM8PDL_UART1_USE_BUFFER 1 
  #else
    #define EFM8PDL_UART1_USE_BUFFER 0
  #endif
#endif
#ifndef EFM8PDL_UART1_TX_BUFTYPE
#define EFM8PDL_UART1_TX_BUFTYPE SI_SEG_XDATA
#endif
#ifndef EFM8PDL_UART1_RX_BUFTYPE
#define EFM8PDL_UART1_RX_BUFTYPE SI_SEG_XDATA
#endif
#ifndef EFM8PDL_UART1_USE_ERR_CALLBACK
#define EFM8PDL_UART1_USE_ERR_CALLBACK 0
#endif

#define UART1_TX_IF SCON1_TI__BMASK 
#define UART1_RX_IF SCON1_RI__BMASK 

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
uint8_t UART1_getIntFlags(void);
#else
#define UART1_getIntFlags(x) (SCON1 & (UART1_TX_IF | UART1_RX_IF))
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_clearIntFlags(uint8_t flags);
#else
#define UART1_clearIntFlags(flags) do{SCON1 &= ~(flags);} while(0)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_enableTxInt(bool enable);
#else
#define UART1_enableTxInt(enable) do{UART1FCN1_TIE = enable;} while(0)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_enableRxInt(bool enable);
#else
#define UART1_enableRxInt(enable) do{UART1FCN1_RIE = enable;} while(0)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_initTxPolling(void);
#else
#define UART1_initTxPolling(x) do{SCON1_TI = 1;} while(0)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_write(uint8_t value);
#else
#define UART1_write(value) do{SBUF1 = value;} while(0)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
uint8_t UART1_read(void);
#else
#define UART1_read(x) (SBUF1)
#endif

void UART1_writeWithExtraBit(uint16_t value);

uint16_t UART1_readWithExtraBit(void);

#define UART1_RXOVR_EF  SCON1_OVR__BMASK  
#define UART1_PARITY_EF SCON1_PERR__BMASK 


#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
uint8_t UART1_getErrFlags(void);
#else
#define UART1_getErrFlags(x) (SCON1 & (UART1_RXOVR_EF | UART1_PARITY_EF))
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_clearErrFlags(uint8_t flags);
#else
#define UART1_clearErrFlags(flags) do{SCON1 &= ~(flags);} while(0)
#endif

#define UART1_TFRQ_IF UART1FCN1_TFRQ__BMASK 
#define UART1_RFRQ_IF UART1FCN1_RFRQ__BMASK 

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
uint8_t UART1_getFifoIntFlags(void);
#else
#define UART1_getFifoIntFlags(x) (UART1FCN1 & (UART1_TFRQ_IF | UART1_RFRQ_IF))
#endif

void UART1_enableTxFifoInt(bool enable);

void UART1_enableRxFifoInt(bool enable);

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
uint8_t UART1_getTxFifoCount(void);
#else
#define UART1_getTxFifoCount(x) ((UART1FCT & UART1FCT_TXCNT__FMASK) >> UART1FCT_TXCNT__SHIFT)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
uint8_t UART1_getRxFifoCount(void);
#else
#define UART1_getRxFifoCount(x) ((UART1FCT & UART1FCT_RXCNT__FMASK) >> UART1FCT_RXCNT__SHIFT)
#endif

bool UART1_isTxFifoFull(void);

void UART1_stallTxFifo(bool enable);

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_flushTxFifo(void);
#else
#define UART1_flushTxFifo(x) do{UART1FCN0 |= UART1FCN0_TFLSH__FLUSH;} while(0)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_flushRxFifo(void);
#else
#define UART1_flushRxFifo(x) do{UART1FCN0 |= UART1FCN0_RFLSH__FLUSH;} while(0)
#endif

#define UART1_AUTOBAUD_IF UART1LIN_SYNCD__SYNC_DONE /**< UART1 Auto-baud Interrupt */
#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
uint8_t UART1_getAutobaudIntFlag(void);
#else
#define UART1_getAutobaudIntFlag(x) (UART1LIN & UART1_AUTOBAUD_IF)
#endif

#if (EFM8PDL_UART1_AUTO_PAGE == 1) || IS_DOXYGEN
void UART1_clearAutobaudIntFlag(void);
#else
#define UART1_clearAutobaudIntFlag(x) do{UART1LIN &= ~UART1_AUTOBAUD_IF;} while(0)
#endif

void UART1_enableAutobaud(bool enable);
typedef enum
{
  UART1_DATALEN_5 = SMOD1_SDL__5_BITS, 
  UART1_DATALEN_6 = SMOD1_SDL__6_BITS, 
  UART1_DATALEN_7 = SMOD1_SDL__7_BITS, 
  UART1_DATALEN_8 = SMOD1_SDL__8_BITS, 
} UART1_DataLen_t;


typedef enum
{
  UART1_STOPLEN_SHORT = SMOD1_SBL__SHORT, 
  UART1_STOPLEN_LONG  = SMOD1_SBL__LONG,  
} UART1_StopLen_t;


typedef enum
{
  UART1_FEATURE_DISABLE  = SMOD1_PE__PARITY_DISABLED | SMOD1_XBE__DISABLED, 
  UART1_FEATURE_PARITY   = SMOD1_PE__PARITY_ENABLED,                        
  UART1_FEATURE_EXTRABIT = SMOD1_XBE__ENABLED,                              
} UART1_FeatureBit_t;


typedef enum
{
  UART1_PARITY_ODD   = SMOD1_SPT__ODD_PARITY,   
  UART1_PARITY_EVEN  = SMOD1_SPT__EVEN_PARITY,  
  UART1_PARITY_MARK  = SMOD1_SPT__MARK_PARITY,  
  UART1_PARITY_SPACE = SMOD1_SPT__SPACE_PARITY, 
} UART1_ParityType_t;


typedef enum
{
  UART1_RX_ENABLE  = SCON0_REN__RECEIVE_ENABLED,   
  UART1_RX_DISABLE = SCON0_REN__RECEIVE_DISABLED,  
} UART1_RxEnable_t;


typedef enum
{
  UART1_RX_CROSSBAR = UART1PCF_RXSEL__CROSSBAR, 
  UART1_RX_CLU0     = UART1PCF_RXSEL__CLU0,     
  UART1_RX_CLU1     = UART1PCF_RXSEL__CLU1,     
  UART1_RX_CLU2     = UART1PCF_RXSEL__CLU2,     
} UART1_RxSelect_t;


typedef enum
{
  UART1_MULTIPROC_DISABLE = SMOD1_MCE__MULTI_DISABLED, 
  UART1_MULTIPROC_ENABLE  = SMOD1_MCE__MULTI_ENABLED,  
} UART1_Multiproc_t;


typedef enum
{
  UART1_BRPRESCALER_01 = SBCON1_BPS__DIV_BY_1,  
  UART1_BRPRESCALER_04 = SBCON1_BPS__DIV_BY_4,  
  UART1_BRPRESCALER_08 = SBCON1_BPS__DIV_BY_8,  
  UART1_BRPRESCALER_12 = SBCON1_BPS__DIV_BY_12, 
  UART1_BRPRESCALER_16 = SBCON1_BPS__DIV_BY_16, 
  UART1_BRPRESCALER_24 = SBCON1_BPS__DIV_BY_24, 
  UART1_BRPRESCALER_32 = SBCON1_BPS__DIV_BY_32, 
  UART1_BRPRESCALER_48 = SBCON1_BPS__DIV_BY_48, 
} UART1_BrPrescaler_t;


void UART1_init(uint32_t sysclk, uint32_t baudrate, 
                UART1_DataLen_t datalen, UART1_StopLen_t stoplen, 
                UART1_FeatureBit_t featbit, UART1_ParityType_t partype,
                UART1_RxEnable_t rxen, UART1_RxSelect_t rxsel, 
                UART1_Multiproc_t mcen);

void UART1_initWithAutobaud(UART1_BrPrescaler_t presc, UART1_StopLen_t stoplen,
                            UART1_FeatureBit_t featbit, UART1_ParityType_t partype,
                            UART1_RxEnable_t rxen, UART1_RxSelect_t rxsel,
                            UART1_Multiproc_t mcen);

void UART1_reset(void);


typedef enum
{
  UART1_TXTHRSH_ZERO  = UART1FCN0_TXTH__ZERO,  
} UART1_TxFifoThreshold_t;


typedef enum
{
  UART1_TXFIFOINT_ENABLE  = UART1FCN0_TFRQE__ENABLED,   
  UART1_TXFIFOINT_DISABLE = UART1FCN0_TFRQE__DISABLED,  
} UART1_TxFifoInt_t;


typedef enum
{
  UART1_RXTHRSH_ZERO  = UART1FCN0_RXTH__ZERO, 
} UART1_RxFiFoThreshold_t;


typedef enum
{
  UART1_RXTIMEOUT_DISABLE = UART1FCN1_RXTO__DISABLED,   
  UART1_RXTIMEOUT_2       = UART1FCN1_RXTO__TIMEOUT_2,  
  UART1_RXTIMEOUT_4       = UART1FCN1_RXTO__TIMEOUT_4,  
  UART1_RXTIMEOUT_16      = UART1FCN1_RXTO__TIMEOUT_16, 
} UART1_RxFifoTimeout_t;


typedef enum
{
  UART1_RXFIFOINT_ENABLE  = UART1FCN0_RFRQE__ENABLED,   
  UART1_RXFIFOINT_DISABLE = UART1FCN0_RFRQE__DISABLED,  
} UART1_RxFifoInt_t;

void UART1_initTxFifo(UART1_TxFifoThreshold_t txth, UART1_TxFifoInt_t txint);

void UART1_initRxFifo(UART1_RxFiFoThreshold_t rxth, UART1_RxFifoTimeout_t rxto,
                      UART1_RxFifoInt_t rxint);
#if (EFM8PDL_UART1_USE_BUFFER == 1) || IS_DOXYGEN

void UART1_writeBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer,
                                                uint8_t,
                                                EFM8PDL_UART1_TX_BUFTYPE),
                                                uint8_t length);

void UART1_readBuffer(SI_VARIABLE_SEGMENT_POINTER(buffer,
                                               uint8_t,
                                               EFM8PDL_UART1_RX_BUFTYPE),
                                               uint8_t length);

void UART1_abortTx(void);

void UART1_abortRx(void);

uint8_t UART1_txBytesRemaining(void);

uint8_t UART1_rxBytesRemaining(void);
#endif //EFM8PDL_UART1_USE_BUFFER

#if (EFM8PDL_UART1_USE_BUFFER == 1) || IS_DOXYGEN

#if EFM8PDL_UART1_USE_ERR_CALLBACK == 1 || IS_DOXYGEN
void UART1_transferErrorCb(uint8_t errFlags);
#endif // EFM8PDL_UART1_USE_ERR_CALLBACK

void UART1_receiveCompleteCb(void);

void UART1_transmitCompleteCb(void);

#endif //EFM8PDL_UART1_USE_BUFFER
#if (EFM8PDL_UART1_USE_STDIO == 1) || IS_DOXYGEN

void UART1_initStdio(uint32_t sysclk, uint32_t baudrate);

#endif //EFM8PDL_UART1_USE_STDIO
#endif //__UART_0_H__
