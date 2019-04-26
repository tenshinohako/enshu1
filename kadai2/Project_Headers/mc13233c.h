/* Based on CPU DB MC13233C, version 3.00.000 (RegistersPrg V2.33) */
/*
** ###################################################################
**     Filename  : mc13233c.h
**     Processor : MC13233C
**     FileFormat: V2.33
**     DataSheet : MC1323xRM Draft 06/2011
**     Compiler  : CodeWarrior compiler
**     Date/Time : 10/16/2012, 4:47 PM
**     Abstract  :
**         This header implements the mapping of I/O devices.
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
**
**     CPU Registers Revisions:
**      - 15.4.2011, V3.00.0:
**              - Renamed interrupt Viic to Viicx, renamed register PHY_CNTRL2 bit TCRV_RST to TCRV_MSK.
**              - Removed bit SPMSC1[BGBE]. Added bit SCGC2[MDM].
**              - Corrected the address of PTBPE,PTBSE,PTBDS,PTCPE,PTCSE,PTCDS,PTDPE,PTDSE,PTDDS registers.
**              - Removed PHY_PA_PWR_CNTL register bits. Removed bits PHY_FSM[7:6].
**              - Renamed PHY_INDIRECT_ACCESS_REG register to PHY_INDIRECT_ACCESS_DATA.
**      - 25.7.2011, V3.00.1:
**              - Added PID bit in the SOPT2 register. Updated the RTC register map.
**      - 12.10.2012, V3.00.2:
**              - Removed FCDIV register
**
**     File-Format-Revisions:
**      - 18.05.2010, V2.32 :
**               - MISRA compliance: U/UL suffixes added to all numbers (_MASK,_BITNUM and addresses)
**      - 15.09.2010, V2.33 :
**               - Empty union is not generated for data overlapping registers, cause there is no bit access
**
**     Not all general-purpose I/O pins are available on all packages or on all mask sets of a specific
**     derivative device. To avoid extra current drain from floating input pins, the user’s reset
**     initialization routine in the application program must either enable on-chip pull-up devices
**     or change the direction of unconnected pins to outputs so the pins do not float.
** ###################################################################
*/

#ifndef _MC13233C_H
#define _MC13233C_H

/*lint -save  -e950 -esym(960,18.4) -e46 -esym(961,19.7) Disable MISRA rule (1.1,18.4,6.4,19.7) checking. */
/*lint -save  -e621 Disable MISRA rule (5.1) checking. */
/* Types definition */
typedef unsigned char byte;
typedef unsigned int word;
typedef unsigned long dword;
typedef unsigned long dlong[2];

/* Watchdog reset macro */
#ifndef __RESET_WATCHDOG
#ifdef _lint
  #define __RESET_WATCHDOG()  /* empty */
#else
  #define __RESET_WATCHDOG() {asm sta SRS;}
#endif
#endif /* __RESET_WATCHDOG */

#define REG_BASE 0x0000                /* Base address for the I/O register block */


#pragma MESSAGE DISABLE C1106 /* WARNING C1106: Non-standard bitfield type */

/**************** interrupt vector numbers ****************/
#define VectorNumber_Vrtc               25U
#define VectorNumber_Vkeyboard1         24U
#define VectorNumber_Vkeyboard2         23U
#define VectorNumber_Viicx              22U
#define VectorNumber_Vcmt               21U
#define VectorNumber_Vscitx             20U
#define VectorNumber_Vscirx             19U
#define VectorNumber_Vscierr            18U
#define VectorNumber_Vspi               17U
#define VectorNumber_Vtpm4ovf           16U
#define VectorNumber_Vtpm4ch0           15U
#define VectorNumber_Vtpm3ovf           14U
#define VectorNumber_Vtpm3ch0           13U
#define VectorNumber_Vtpm2ovf           12U
#define VectorNumber_Vtpm2ch0           11U
#define VectorNumber_Vtpm1ovf           10U
#define VectorNumber_Vtpm1ch0           9U
#define VectorNumber_Vaes128            8U
#define VectorNumber_Vrx_watermark_802_15_4 7U
#define VectorNumber_Vtimers_802_15_4   6U
#define VectorNumber_Vtx_802_15_4       5U
#define VectorNumber_Vrx_802_15_4       4U
#define VectorNumber_Vlvd               3U
#define VectorNumber_Virq               2U
#define VectorNumber_Vswi               1U
#define VectorNumber_Vreset             0U

/**************** interrupt vector table ****************/
#define Vrtc                            0xFFCCU
#define Vkeyboard1                      0xFFCEU
#define Vkeyboard2                      0xFFD0U
#define Viicx                           0xFFD2U
#define Vcmt                            0xFFD4U
#define Vscitx                          0xFFD6U
#define Vscirx                          0xFFD8U
#define Vscierr                         0xFFDAU
#define Vspi                            0xFFDCU
#define Vtpm4ovf                        0xFFDEU
#define Vtpm4ch0                        0xFFE0U
#define Vtpm3ovf                        0xFFE2U
#define Vtpm3ch0                        0xFFE4U
#define Vtpm2ovf                        0xFFE6U
#define Vtpm2ch0                        0xFFE8U
#define Vtpm1ovf                        0xFFEAU
#define Vtpm1ch0                        0xFFECU
#define Vaes128                         0xFFEEU
#define Vrx_watermark_802_15_4          0xFFF0U
#define Vtimers_802_15_4                0xFFF2U
#define Vtx_802_15_4                    0xFFF4U
#define Vrx_802_15_4                    0xFFF6U
#define Vlvd                            0xFFF8U
#define Virq                            0xFFFAU
#define Vswi                            0xFFFCU
#define Vreset                          0xFFFEU

/**************** registers I/O map ****************/

/*** PTAD - Port A Data Register; 0x00000000 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAD0       :1;                                       /* Port A Data Register Bit 0 */
    byte PTAD1       :1;                                       /* Port A Data Register Bit 1 */
    byte PTAD2       :1;                                       /* Port A Data Register Bit 2 */
    byte PTAD3       :1;                                       /* Port A Data Register Bit 3 */
    byte PTAD4       :1;                                       /* Port A Data Register Bit 4 */
    byte PTAD5       :1;                                       /* Port A Data Register Bit 5 */
    byte PTAD6       :1;                                       /* Port A Data Register Bit 6 */
    byte PTAD7       :1;                                       /* Port A Data Register Bit 7 */
  } Bits;
} PTADSTR;
extern volatile PTADSTR _PTAD @0x00000000;
#define PTAD                            _PTAD.Byte
#define PTAD_PTAD0                      _PTAD.Bits.PTAD0
#define PTAD_PTAD1                      _PTAD.Bits.PTAD1
#define PTAD_PTAD2                      _PTAD.Bits.PTAD2
#define PTAD_PTAD3                      _PTAD.Bits.PTAD3
#define PTAD_PTAD4                      _PTAD.Bits.PTAD4
#define PTAD_PTAD5                      _PTAD.Bits.PTAD5
#define PTAD_PTAD6                      _PTAD.Bits.PTAD6
#define PTAD_PTAD7                      _PTAD.Bits.PTAD7

#define PTAD_PTAD0_MASK                 1U
#define PTAD_PTAD1_MASK                 2U
#define PTAD_PTAD2_MASK                 4U
#define PTAD_PTAD3_MASK                 8U
#define PTAD_PTAD4_MASK                 16U
#define PTAD_PTAD5_MASK                 32U
#define PTAD_PTAD6_MASK                 64U
#define PTAD_PTAD7_MASK                 128U


/*** PTADD - Port A Data Direction Register; 0x00000001 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADD0      :1;                                       /* Data Direction for Port A Bit 0 */
    byte PTADD1      :1;                                       /* Data Direction for Port A Bit 1 */
    byte PTADD2      :1;                                       /* Data Direction for Port A Bit 2 */
    byte PTADD3      :1;                                       /* Data Direction for Port A Bit 3 */
    byte PTADD4      :1;                                       /* Data Direction for Port A Bit 4 */
    byte PTADD5      :1;                                       /* Data Direction for Port A Bit 5 */
    byte PTADD6      :1;                                       /* Data Direction for Port A Bit 6 */
    byte PTADD7      :1;                                       /* Data Direction for Port A Bit 7 */
  } Bits;
} PTADDSTR;
extern volatile PTADDSTR _PTADD @0x00000001;
#define PTADD                           _PTADD.Byte
#define PTADD_PTADD0                    _PTADD.Bits.PTADD0
#define PTADD_PTADD1                    _PTADD.Bits.PTADD1
#define PTADD_PTADD2                    _PTADD.Bits.PTADD2
#define PTADD_PTADD3                    _PTADD.Bits.PTADD3
#define PTADD_PTADD4                    _PTADD.Bits.PTADD4
#define PTADD_PTADD5                    _PTADD.Bits.PTADD5
#define PTADD_PTADD6                    _PTADD.Bits.PTADD6
#define PTADD_PTADD7                    _PTADD.Bits.PTADD7

#define PTADD_PTADD0_MASK               1U
#define PTADD_PTADD1_MASK               2U
#define PTADD_PTADD2_MASK               4U
#define PTADD_PTADD3_MASK               8U
#define PTADD_PTADD4_MASK               16U
#define PTADD_PTADD5_MASK               32U
#define PTADD_PTADD6_MASK               64U
#define PTADD_PTADD7_MASK               128U


/*** PTBD - Port B Data Register; 0x00000002 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBD0       :1;                                       /* Port B Data Register Bit 0 */
    byte PTBD1       :1;                                       /* Port B Data Register Bit 1 */
    byte PTBD2       :1;                                       /* Port B Data Register Bit 2 */
    byte PTBD3       :1;                                       /* Port B Data Register Bit 3 */
    byte PTBD4       :1;                                       /* Port B Data Register Bit 4 */
    byte PTBD5       :1;                                       /* Port B Data Register Bit 5 */
    byte PTBD6       :1;                                       /* Port B Data Register Bit 6 */
    byte PTBD7       :1;                                       /* Port B Data Register Bit 7 */
  } Bits;
} PTBDSTR;
extern volatile PTBDSTR _PTBD @0x00000002;
#define PTBD                            _PTBD.Byte
#define PTBD_PTBD0                      _PTBD.Bits.PTBD0
#define PTBD_PTBD1                      _PTBD.Bits.PTBD1
#define PTBD_PTBD2                      _PTBD.Bits.PTBD2
#define PTBD_PTBD3                      _PTBD.Bits.PTBD3
#define PTBD_PTBD4                      _PTBD.Bits.PTBD4
#define PTBD_PTBD5                      _PTBD.Bits.PTBD5
#define PTBD_PTBD6                      _PTBD.Bits.PTBD6
#define PTBD_PTBD7                      _PTBD.Bits.PTBD7

#define PTBD_PTBD0_MASK                 1U
#define PTBD_PTBD1_MASK                 2U
#define PTBD_PTBD2_MASK                 4U
#define PTBD_PTBD3_MASK                 8U
#define PTBD_PTBD4_MASK                 16U
#define PTBD_PTBD5_MASK                 32U
#define PTBD_PTBD6_MASK                 64U
#define PTBD_PTBD7_MASK                 128U


/*** PTBDD - Port B Data Direction Register; 0x00000003 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDD0      :1;                                       /* Data Direction for Port B Bit 0 */
    byte PTBDD1      :1;                                       /* Data Direction for Port B Bit 1 */
    byte PTBDD2      :1;                                       /* Data Direction for Port B Bit 2 */
    byte PTBDD3      :1;                                       /* Data Direction for Port B Bit 3 */
    byte PTBDD4      :1;                                       /* Data Direction for Port B Bit 4 */
    byte PTBDD5      :1;                                       /* Data Direction for Port B Bit 5 */
    byte PTBDD6      :1;                                       /* Data Direction for Port B Bit 6 */
    byte PTBDD7      :1;                                       /* Data Direction for Port B Bit 7 */
  } Bits;
} PTBDDSTR;
extern volatile PTBDDSTR _PTBDD @0x00000003;
#define PTBDD                           _PTBDD.Byte
#define PTBDD_PTBDD0                    _PTBDD.Bits.PTBDD0
#define PTBDD_PTBDD1                    _PTBDD.Bits.PTBDD1
#define PTBDD_PTBDD2                    _PTBDD.Bits.PTBDD2
#define PTBDD_PTBDD3                    _PTBDD.Bits.PTBDD3
#define PTBDD_PTBDD4                    _PTBDD.Bits.PTBDD4
#define PTBDD_PTBDD5                    _PTBDD.Bits.PTBDD5
#define PTBDD_PTBDD6                    _PTBDD.Bits.PTBDD6
#define PTBDD_PTBDD7                    _PTBDD.Bits.PTBDD7

#define PTBDD_PTBDD0_MASK               1U
#define PTBDD_PTBDD1_MASK               2U
#define PTBDD_PTBDD2_MASK               4U
#define PTBDD_PTBDD3_MASK               8U
#define PTBDD_PTBDD4_MASK               16U
#define PTBDD_PTBDD5_MASK               32U
#define PTBDD_PTBDD6_MASK               64U
#define PTBDD_PTBDD7_MASK               128U


/*** PTCD - Port C Data Register; 0x00000004 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCD0       :1;                                       /* Port C Data Register Bit 0 */
    byte PTCD1       :1;                                       /* Port C Data Register Bit 1 */
    byte PTCD2       :1;                                       /* Port C Data Register Bit 2 */
    byte PTCD3       :1;                                       /* Port C Data Register Bit 3 */
    byte PTCD4       :1;                                       /* Port C Data Register Bit 4 */
    byte PTCD5       :1;                                       /* Port C Data Register Bit 5 */
    byte PTCD6       :1;                                       /* Port C Data Register Bit 6 */
    byte PTCD7       :1;                                       /* Port C Data Register Bit 7 */
  } Bits;
} PTCDSTR;
extern volatile PTCDSTR _PTCD @0x00000004;
#define PTCD                            _PTCD.Byte
#define PTCD_PTCD0                      _PTCD.Bits.PTCD0
#define PTCD_PTCD1                      _PTCD.Bits.PTCD1
#define PTCD_PTCD2                      _PTCD.Bits.PTCD2
#define PTCD_PTCD3                      _PTCD.Bits.PTCD3
#define PTCD_PTCD4                      _PTCD.Bits.PTCD4
#define PTCD_PTCD5                      _PTCD.Bits.PTCD5
#define PTCD_PTCD6                      _PTCD.Bits.PTCD6
#define PTCD_PTCD7                      _PTCD.Bits.PTCD7

#define PTCD_PTCD0_MASK                 1U
#define PTCD_PTCD1_MASK                 2U
#define PTCD_PTCD2_MASK                 4U
#define PTCD_PTCD3_MASK                 8U
#define PTCD_PTCD4_MASK                 16U
#define PTCD_PTCD5_MASK                 32U
#define PTCD_PTCD6_MASK                 64U
#define PTCD_PTCD7_MASK                 128U


/*** PTCDD - Port C Data Direction Register; 0x00000005 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDD0      :1;                                       /* Data Direction for Port C Bit 0 */
    byte PTCDD1      :1;                                       /* Data Direction for Port C Bit 1 */
    byte PTCDD2      :1;                                       /* Data Direction for Port C Bit 2 */
    byte PTCDD3      :1;                                       /* Data Direction for Port C Bit 3 */
    byte PTCDD4      :1;                                       /* Data Direction for Port C Bit 4 */
    byte PTCDD5      :1;                                       /* Data Direction for Port C Bit 5 */
    byte PTCDD6      :1;                                       /* Data Direction for Port C Bit 6 */
    byte PTCDD7      :1;                                       /* Data Direction for Port C Bit 7 */
  } Bits;
} PTCDDSTR;
extern volatile PTCDDSTR _PTCDD @0x00000005;
#define PTCDD                           _PTCDD.Byte
#define PTCDD_PTCDD0                    _PTCDD.Bits.PTCDD0
#define PTCDD_PTCDD1                    _PTCDD.Bits.PTCDD1
#define PTCDD_PTCDD2                    _PTCDD.Bits.PTCDD2
#define PTCDD_PTCDD3                    _PTCDD.Bits.PTCDD3
#define PTCDD_PTCDD4                    _PTCDD.Bits.PTCDD4
#define PTCDD_PTCDD5                    _PTCDD.Bits.PTCDD5
#define PTCDD_PTCDD6                    _PTCDD.Bits.PTCDD6
#define PTCDD_PTCDD7                    _PTCDD.Bits.PTCDD7

#define PTCDD_PTCDD0_MASK               1U
#define PTCDD_PTCDD1_MASK               2U
#define PTCDD_PTCDD2_MASK               4U
#define PTCDD_PTCDD3_MASK               8U
#define PTCDD_PTCDD4_MASK               16U
#define PTCDD_PTCDD5_MASK               32U
#define PTCDD_PTCDD6_MASK               64U
#define PTCDD_PTCDD7_MASK               128U


/*** PTDD - Port D Data Register; 0x00000006 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDD0       :1;                                       /* Port D Data Register Bit 0 */
    byte PTDD1       :1;                                       /* Port D Data Register Bit 1 */
    byte PTDD2       :1;                                       /* Port D Data Register Bit 2 */
    byte PTDD3       :1;                                       /* Port D Data Register Bit 3 */
    byte PTDD4       :1;                                       /* Port D Data Register Bit 4 */
    byte PTDD5       :1;                                       /* Port D Data Register Bit 5 */
    byte PTDD6       :1;                                       /* Port D Data Register Bit 6 */
    byte PTDD7       :1;                                       /* Port D Data Register Bit 7 */
  } Bits;
} PTDDSTR;
extern volatile PTDDSTR _PTDD @0x00000006;
#define PTDD                            _PTDD.Byte
#define PTDD_PTDD0                      _PTDD.Bits.PTDD0
#define PTDD_PTDD1                      _PTDD.Bits.PTDD1
#define PTDD_PTDD2                      _PTDD.Bits.PTDD2
#define PTDD_PTDD3                      _PTDD.Bits.PTDD3
#define PTDD_PTDD4                      _PTDD.Bits.PTDD4
#define PTDD_PTDD5                      _PTDD.Bits.PTDD5
#define PTDD_PTDD6                      _PTDD.Bits.PTDD6
#define PTDD_PTDD7                      _PTDD.Bits.PTDD7

#define PTDD_PTDD0_MASK                 1U
#define PTDD_PTDD1_MASK                 2U
#define PTDD_PTDD2_MASK                 4U
#define PTDD_PTDD3_MASK                 8U
#define PTDD_PTDD4_MASK                 16U
#define PTDD_PTDD5_MASK                 32U
#define PTDD_PTDD6_MASK                 64U
#define PTDD_PTDD7_MASK                 128U


/*** PTDDD - Port D Data Direction Register; 0x00000007 ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDD0      :1;                                       /* Data Direction for Port D Bit 0 */
    byte PTDDD1      :1;                                       /* Data Direction for Port D Bit 1 */
    byte PTDDD2      :1;                                       /* Data Direction for Port D Bit 2 */
    byte PTDDD3      :1;                                       /* Data Direction for Port D Bit 3 */
    byte PTDDD4      :1;                                       /* Data Direction for Port D Bit 4 */
    byte PTDDD5      :1;                                       /* Data Direction for Port D Bit 5 */
    byte PTDDD6      :1;                                       /* Data Direction for Port D Bit 6 */
    byte PTDDD7      :1;                                       /* Data Direction for Port D Bit 7 */
  } Bits;
} PTDDDSTR;
extern volatile PTDDDSTR _PTDDD @0x00000007;
#define PTDDD                           _PTDDD.Byte
#define PTDDD_PTDDD0                    _PTDDD.Bits.PTDDD0
#define PTDDD_PTDDD1                    _PTDDD.Bits.PTDDD1
#define PTDDD_PTDDD2                    _PTDDD.Bits.PTDDD2
#define PTDDD_PTDDD3                    _PTDDD.Bits.PTDDD3
#define PTDDD_PTDDD4                    _PTDDD.Bits.PTDDD4
#define PTDDD_PTDDD5                    _PTDDD.Bits.PTDDD5
#define PTDDD_PTDDD6                    _PTDDD.Bits.PTDDD6
#define PTDDD_PTDDD7                    _PTDDD.Bits.PTDDD7

#define PTDDD_PTDDD0_MASK               1U
#define PTDDD_PTDDD1_MASK               2U
#define PTDDD_PTDDD2_MASK               4U
#define PTDDD_PTDDD3_MASK               8U
#define PTDDD_PTDDD4_MASK               16U
#define PTDDD_PTDDD5_MASK               32U
#define PTDDD_PTDDD6_MASK               64U
#define PTDDD_PTDDD7_MASK               128U


/*** TPM1SC - TPM1 Status and Control Register; 0x00000008 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1SCSTR;
extern volatile TPM1SCSTR _TPM1SC @0x00000008;
#define TPM1SC                          _TPM1SC.Byte
#define TPM1SC_PS0                      _TPM1SC.Bits.PS0
#define TPM1SC_PS1                      _TPM1SC.Bits.PS1
#define TPM1SC_PS2                      _TPM1SC.Bits.PS2
#define TPM1SC_CLKSA                    _TPM1SC.Bits.CLKSA
#define TPM1SC_CLKSB                    _TPM1SC.Bits.CLKSB
#define TPM1SC_CPWMS                    _TPM1SC.Bits.CPWMS
#define TPM1SC_TOIE                     _TPM1SC.Bits.TOIE
#define TPM1SC_TOF                      _TPM1SC.Bits.TOF
#define TPM1SC_PS                       _TPM1SC.MergedBits.grpPS
#define TPM1SC_CLKSx                    _TPM1SC.MergedBits.grpCLKSx

#define TPM1SC_PS0_MASK                 1U
#define TPM1SC_PS1_MASK                 2U
#define TPM1SC_PS2_MASK                 4U
#define TPM1SC_CLKSA_MASK               8U
#define TPM1SC_CLKSB_MASK               16U
#define TPM1SC_CPWMS_MASK               32U
#define TPM1SC_TOIE_MASK                64U
#define TPM1SC_TOF_MASK                 128U
#define TPM1SC_PS_MASK                  7U
#define TPM1SC_PS_BITNUM                0U
#define TPM1SC_CLKSx_MASK               24U
#define TPM1SC_CLKSx_BITNUM             3U


/*** TPM1CNT - TPM1 Timer Counter Register; 0x00000009 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1CNTH - TPM1 Timer Counter Register High; 0x00000009 ***/
    union {
      byte Byte;
    } TPM1CNTHSTR;
    #define TPM1CNTH                    _TPM1CNT.Overlap_STR.TPM1CNTHSTR.Byte
    

    /*** TPM1CNTL - TPM1 Timer Counter Register Low; 0x0000000A ***/
    union {
      byte Byte;
    } TPM1CNTLSTR;
    #define TPM1CNTL                    _TPM1CNT.Overlap_STR.TPM1CNTLSTR.Byte
    
  } Overlap_STR;

} TPM1CNTSTR;
extern volatile TPM1CNTSTR _TPM1CNT @0x00000009;
#define TPM1CNT                         _TPM1CNT.Word


/*** TPM1MOD - TPM1 Timer Counter Modulo Register; 0x0000000B ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1MODH - TPM1 Timer Counter Modulo Register High; 0x0000000B ***/
    union {
      byte Byte;
    } TPM1MODHSTR;
    #define TPM1MODH                    _TPM1MOD.Overlap_STR.TPM1MODHSTR.Byte
    

    /*** TPM1MODL - TPM1 Timer Counter Modulo Register Low; 0x0000000C ***/
    union {
      byte Byte;
    } TPM1MODLSTR;
    #define TPM1MODL                    _TPM1MOD.Overlap_STR.TPM1MODLSTR.Byte
    
  } Overlap_STR;

} TPM1MODSTR;
extern volatile TPM1MODSTR _TPM1MOD @0x0000000B;
#define TPM1MOD                         _TPM1MOD.Word


/*** TPM1C0SC - TPM1 Timer Channel 0 Status and Control Register; 0x0000000D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM1C0SCSTR;
extern volatile TPM1C0SCSTR _TPM1C0SC @0x0000000D;
#define TPM1C0SC                        _TPM1C0SC.Byte
#define TPM1C0SC_ELS0A                  _TPM1C0SC.Bits.ELS0A
#define TPM1C0SC_ELS0B                  _TPM1C0SC.Bits.ELS0B
#define TPM1C0SC_MS0A                   _TPM1C0SC.Bits.MS0A
#define TPM1C0SC_MS0B                   _TPM1C0SC.Bits.MS0B
#define TPM1C0SC_CH0IE                  _TPM1C0SC.Bits.CH0IE
#define TPM1C0SC_CH0F                   _TPM1C0SC.Bits.CH0F
#define TPM1C0SC_ELS0x                  _TPM1C0SC.MergedBits.grpELS0x
#define TPM1C0SC_MS0x                   _TPM1C0SC.MergedBits.grpMS0x

#define TPM1C0SC_ELS0A_MASK             4U
#define TPM1C0SC_ELS0B_MASK             8U
#define TPM1C0SC_MS0A_MASK              16U
#define TPM1C0SC_MS0B_MASK              32U
#define TPM1C0SC_CH0IE_MASK             64U
#define TPM1C0SC_CH0F_MASK              128U
#define TPM1C0SC_ELS0x_MASK             12U
#define TPM1C0SC_ELS0x_BITNUM           2U
#define TPM1C0SC_MS0x_MASK              48U
#define TPM1C0SC_MS0x_BITNUM            4U


/*** TPM1C0V - TPM1 Timer Channel 0 Value Register; 0x0000000E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM1C0VH - TPM1 Timer Channel 0 Value Register High; 0x0000000E ***/
    union {
      byte Byte;
    } TPM1C0VHSTR;
    #define TPM1C0VH                    _TPM1C0V.Overlap_STR.TPM1C0VHSTR.Byte
    

    /*** TPM1C0VL - TPM1 Timer Channel 0 Value Register Low; 0x0000000F ***/
    union {
      byte Byte;
    } TPM1C0VLSTR;
    #define TPM1C0VL                    _TPM1C0V.Overlap_STR.TPM1C0VLSTR.Byte
    
  } Overlap_STR;

} TPM1C0VSTR;
extern volatile TPM1C0VSTR _TPM1C0V @0x0000000E;
#define TPM1C0V                         _TPM1C0V.Word


/*** TPM2SC - TPM2 Status and Control Register; 0x00000010 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2SCSTR;
extern volatile TPM2SCSTR _TPM2SC @0x00000010;
#define TPM2SC                          _TPM2SC.Byte
#define TPM2SC_PS0                      _TPM2SC.Bits.PS0
#define TPM2SC_PS1                      _TPM2SC.Bits.PS1
#define TPM2SC_PS2                      _TPM2SC.Bits.PS2
#define TPM2SC_CLKSA                    _TPM2SC.Bits.CLKSA
#define TPM2SC_CLKSB                    _TPM2SC.Bits.CLKSB
#define TPM2SC_CPWMS                    _TPM2SC.Bits.CPWMS
#define TPM2SC_TOIE                     _TPM2SC.Bits.TOIE
#define TPM2SC_TOF                      _TPM2SC.Bits.TOF
#define TPM2SC_PS                       _TPM2SC.MergedBits.grpPS
#define TPM2SC_CLKSx                    _TPM2SC.MergedBits.grpCLKSx

#define TPM2SC_PS0_MASK                 1U
#define TPM2SC_PS1_MASK                 2U
#define TPM2SC_PS2_MASK                 4U
#define TPM2SC_CLKSA_MASK               8U
#define TPM2SC_CLKSB_MASK               16U
#define TPM2SC_CPWMS_MASK               32U
#define TPM2SC_TOIE_MASK                64U
#define TPM2SC_TOF_MASK                 128U
#define TPM2SC_PS_MASK                  7U
#define TPM2SC_PS_BITNUM                0U
#define TPM2SC_CLKSx_MASK               24U
#define TPM2SC_CLKSx_BITNUM             3U


/*** TPM2CNT - TPM2 Timer Counter Register; 0x00000011 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2CNTH - TPM2 Timer Counter Register High; 0x00000011 ***/
    union {
      byte Byte;
    } TPM2CNTHSTR;
    #define TPM2CNTH                    _TPM2CNT.Overlap_STR.TPM2CNTHSTR.Byte
    

    /*** TPM2CNTL - TPM2 Timer Counter Register Low; 0x00000012 ***/
    union {
      byte Byte;
    } TPM2CNTLSTR;
    #define TPM2CNTL                    _TPM2CNT.Overlap_STR.TPM2CNTLSTR.Byte
    
  } Overlap_STR;

} TPM2CNTSTR;
extern volatile TPM2CNTSTR _TPM2CNT @0x00000011;
#define TPM2CNT                         _TPM2CNT.Word


/*** TPM2MOD - TPM2 Timer Counter Modulo Register; 0x00000013 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2MODH - TPM2 Timer Counter Modulo Register High; 0x00000013 ***/
    union {
      byte Byte;
    } TPM2MODHSTR;
    #define TPM2MODH                    _TPM2MOD.Overlap_STR.TPM2MODHSTR.Byte
    

    /*** TPM2MODL - TPM2 Timer Counter Modulo Register Low; 0x00000014 ***/
    union {
      byte Byte;
    } TPM2MODLSTR;
    #define TPM2MODL                    _TPM2MOD.Overlap_STR.TPM2MODLSTR.Byte
    
  } Overlap_STR;

} TPM2MODSTR;
extern volatile TPM2MODSTR _TPM2MOD @0x00000013;
#define TPM2MOD                         _TPM2MOD.Word


/*** TPM2C0SC - TPM2 Timer Channel 0 Status and Control Register; 0x00000015 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM2C0SCSTR;
extern volatile TPM2C0SCSTR _TPM2C0SC @0x00000015;
#define TPM2C0SC                        _TPM2C0SC.Byte
#define TPM2C0SC_ELS0A                  _TPM2C0SC.Bits.ELS0A
#define TPM2C0SC_ELS0B                  _TPM2C0SC.Bits.ELS0B
#define TPM2C0SC_MS0A                   _TPM2C0SC.Bits.MS0A
#define TPM2C0SC_MS0B                   _TPM2C0SC.Bits.MS0B
#define TPM2C0SC_CH0IE                  _TPM2C0SC.Bits.CH0IE
#define TPM2C0SC_CH0F                   _TPM2C0SC.Bits.CH0F
#define TPM2C0SC_ELS0x                  _TPM2C0SC.MergedBits.grpELS0x
#define TPM2C0SC_MS0x                   _TPM2C0SC.MergedBits.grpMS0x

#define TPM2C0SC_ELS0A_MASK             4U
#define TPM2C0SC_ELS0B_MASK             8U
#define TPM2C0SC_MS0A_MASK              16U
#define TPM2C0SC_MS0B_MASK              32U
#define TPM2C0SC_CH0IE_MASK             64U
#define TPM2C0SC_CH0F_MASK              128U
#define TPM2C0SC_ELS0x_MASK             12U
#define TPM2C0SC_ELS0x_BITNUM           2U
#define TPM2C0SC_MS0x_MASK              48U
#define TPM2C0SC_MS0x_BITNUM            4U


/*** TPM2C0V - TPM2 Timer Channel 0 Value Register; 0x00000016 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM2C0VH - TPM2 Timer Channel 0 Value Register High; 0x00000016 ***/
    union {
      byte Byte;
    } TPM2C0VHSTR;
    #define TPM2C0VH                    _TPM2C0V.Overlap_STR.TPM2C0VHSTR.Byte
    

    /*** TPM2C0VL - TPM2 Timer Channel 0 Value Register Low; 0x00000017 ***/
    union {
      byte Byte;
    } TPM2C0VLSTR;
    #define TPM2C0VL                    _TPM2C0V.Overlap_STR.TPM2C0VLSTR.Byte
    
  } Overlap_STR;

} TPM2C0VSTR;
extern volatile TPM2C0VSTR _TPM2C0V @0x00000016;
#define TPM2C0V                         _TPM2C0V.Word


/*** TPM3SC - TPM3 Status and Control Register; 0x00000018 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM3SCSTR;
extern volatile TPM3SCSTR _TPM3SC @0x00000018;
#define TPM3SC                          _TPM3SC.Byte
#define TPM3SC_PS0                      _TPM3SC.Bits.PS0
#define TPM3SC_PS1                      _TPM3SC.Bits.PS1
#define TPM3SC_PS2                      _TPM3SC.Bits.PS2
#define TPM3SC_CLKSA                    _TPM3SC.Bits.CLKSA
#define TPM3SC_CLKSB                    _TPM3SC.Bits.CLKSB
#define TPM3SC_CPWMS                    _TPM3SC.Bits.CPWMS
#define TPM3SC_TOIE                     _TPM3SC.Bits.TOIE
#define TPM3SC_TOF                      _TPM3SC.Bits.TOF
#define TPM3SC_PS                       _TPM3SC.MergedBits.grpPS
#define TPM3SC_CLKSx                    _TPM3SC.MergedBits.grpCLKSx

#define TPM3SC_PS0_MASK                 1U
#define TPM3SC_PS1_MASK                 2U
#define TPM3SC_PS2_MASK                 4U
#define TPM3SC_CLKSA_MASK               8U
#define TPM3SC_CLKSB_MASK               16U
#define TPM3SC_CPWMS_MASK               32U
#define TPM3SC_TOIE_MASK                64U
#define TPM3SC_TOF_MASK                 128U
#define TPM3SC_PS_MASK                  7U
#define TPM3SC_PS_BITNUM                0U
#define TPM3SC_CLKSx_MASK               24U
#define TPM3SC_CLKSx_BITNUM             3U


/*** TPM3CNT - TPM3 Timer Counter Register; 0x00000019 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM3CNTH - TPM3 Timer Counter Register High; 0x00000019 ***/
    union {
      byte Byte;
    } TPM3CNTHSTR;
    #define TPM3CNTH                    _TPM3CNT.Overlap_STR.TPM3CNTHSTR.Byte
    

    /*** TPM3CNTL - TPM3 Timer Counter Register Low; 0x0000001A ***/
    union {
      byte Byte;
    } TPM3CNTLSTR;
    #define TPM3CNTL                    _TPM3CNT.Overlap_STR.TPM3CNTLSTR.Byte
    
  } Overlap_STR;

} TPM3CNTSTR;
extern volatile TPM3CNTSTR _TPM3CNT @0x00000019;
#define TPM3CNT                         _TPM3CNT.Word


/*** TPM3MOD - TPM3 Timer Counter Modulo Register; 0x0000001B ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM3MODH - TPM3 Timer Counter Modulo Register High; 0x0000001B ***/
    union {
      byte Byte;
    } TPM3MODHSTR;
    #define TPM3MODH                    _TPM3MOD.Overlap_STR.TPM3MODHSTR.Byte
    

    /*** TPM3MODL - TPM3 Timer Counter Modulo Register Low; 0x0000001C ***/
    union {
      byte Byte;
    } TPM3MODLSTR;
    #define TPM3MODL                    _TPM3MOD.Overlap_STR.TPM3MODLSTR.Byte
    
  } Overlap_STR;

} TPM3MODSTR;
extern volatile TPM3MODSTR _TPM3MOD @0x0000001B;
#define TPM3MOD                         _TPM3MOD.Word


/*** TPM3C0SC - TPM3 Timer Channel 0 Status and Control Register; 0x0000001D ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM3C0SCSTR;
extern volatile TPM3C0SCSTR _TPM3C0SC @0x0000001D;
#define TPM3C0SC                        _TPM3C0SC.Byte
#define TPM3C0SC_ELS0A                  _TPM3C0SC.Bits.ELS0A
#define TPM3C0SC_ELS0B                  _TPM3C0SC.Bits.ELS0B
#define TPM3C0SC_MS0A                   _TPM3C0SC.Bits.MS0A
#define TPM3C0SC_MS0B                   _TPM3C0SC.Bits.MS0B
#define TPM3C0SC_CH0IE                  _TPM3C0SC.Bits.CH0IE
#define TPM3C0SC_CH0F                   _TPM3C0SC.Bits.CH0F
#define TPM3C0SC_ELS0x                  _TPM3C0SC.MergedBits.grpELS0x
#define TPM3C0SC_MS0x                   _TPM3C0SC.MergedBits.grpMS0x

#define TPM3C0SC_ELS0A_MASK             4U
#define TPM3C0SC_ELS0B_MASK             8U
#define TPM3C0SC_MS0A_MASK              16U
#define TPM3C0SC_MS0B_MASK              32U
#define TPM3C0SC_CH0IE_MASK             64U
#define TPM3C0SC_CH0F_MASK              128U
#define TPM3C0SC_ELS0x_MASK             12U
#define TPM3C0SC_ELS0x_BITNUM           2U
#define TPM3C0SC_MS0x_MASK              48U
#define TPM3C0SC_MS0x_BITNUM            4U


/*** TPM3C0V - TPM3 Timer Channel 0 Value Register; 0x0000001E ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM3C0VH - TPM3 Timer Channel 0 Value Register High; 0x0000001E ***/
    union {
      byte Byte;
    } TPM3C0VHSTR;
    #define TPM3C0VH                    _TPM3C0V.Overlap_STR.TPM3C0VHSTR.Byte
    

    /*** TPM3C0VL - TPM3 Timer Channel 0 Value Register Low; 0x0000001F ***/
    union {
      byte Byte;
    } TPM3C0VLSTR;
    #define TPM3C0VL                    _TPM3C0V.Overlap_STR.TPM3C0VLSTR.Byte
    
  } Overlap_STR;

} TPM3C0VSTR;
extern volatile TPM3C0VSTR _TPM3C0V @0x0000001E;
#define TPM3C0V                         _TPM3C0V.Word


/*** AES_CONTROL1 - AES 128 Control 1 Register; 0x00000020 ***/
typedef union {
  byte Byte;
  struct {
    byte AES_MSK     :1;                                       /* AES128 Interrupt Mask */
    byte LOAD_MAC    :1;                                       /* MAC preload */
    byte AES         :1;                                       /* AES mode */
    byte CBC         :1;                                       /* CBC-MAC generation */
    byte CTR         :1;                                       /* Counter encryption mode */
    byte SELFTST     :1;                                       /* Self test mode */
    byte START       :1;                                       /* CBC or CTR or CCM or AES mode encryption start */
    byte CLEAR       :1;                                       /* ASM memory clear */
  } Bits;
} AES_CONTROL1STR;
extern volatile AES_CONTROL1STR _AES_CONTROL1 @0x00000020;
#define AES_CONTROL1                    _AES_CONTROL1.Byte
#define AES_CONTROL1_AES_MSK            _AES_CONTROL1.Bits.AES_MSK
#define AES_CONTROL1_LOAD_MAC           _AES_CONTROL1.Bits.LOAD_MAC
#define AES_CONTROL1_AES                _AES_CONTROL1.Bits.AES
#define AES_CONTROL1_CBC                _AES_CONTROL1.Bits.CBC
#define AES_CONTROL1_CTR                _AES_CONTROL1.Bits.CTR
#define AES_CONTROL1_SELFTST            _AES_CONTROL1.Bits.SELFTST
#define AES_CONTROL1_START              _AES_CONTROL1.Bits.START
#define AES_CONTROL1_CLEAR              _AES_CONTROL1.Bits.CLEAR

#define AES_CONTROL1_AES_MSK_MASK       1U
#define AES_CONTROL1_LOAD_MAC_MASK      2U
#define AES_CONTROL1_AES_MASK           4U
#define AES_CONTROL1_CBC_MASK           8U
#define AES_CONTROL1_CTR_MASK           16U
#define AES_CONTROL1_SELFTST_MASK       32U
#define AES_CONTROL1_START_MASK         64U
#define AES_CONTROL1_CLEAR_MASK         128U


/*** AES_CONTROL2 - AES 128 Control Register 2; 0x00000021 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte TSTPAS      :1;                                       /* Self test passed */
    byte IRQ_FLAG    :1;                                       /* AES Interrupt flag */
    byte             :1; 
    byte             :1; 
    byte DATA_REG_TYPE_SELECT0 :1;                             /* This register selects the type of data to be written to or read from the 16x8 Data, bit 0 */
    byte DATA_REG_TYPE_SELECT1 :1;                             /* This register selects the type of data to be written to or read from the 16x8 Data, bit 1 */
    byte DATA_REG_TYPE_SELECT2 :1;                             /* This register selects the type of data to be written to or read from the 16x8 Data, bit 2 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpDATA_REG_TYPE_SELECT :3;
  } MergedBits;
} AES_CONTROL2STR;
extern volatile AES_CONTROL2STR _AES_CONTROL2 @0x00000021;
#define AES_CONTROL2                    _AES_CONTROL2.Byte
#define AES_CONTROL2_TSTPAS             _AES_CONTROL2.Bits.TSTPAS
#define AES_CONTROL2_IRQ_FLAG           _AES_CONTROL2.Bits.IRQ_FLAG
#define AES_CONTROL2_DATA_REG_TYPE_SELECT0 _AES_CONTROL2.Bits.DATA_REG_TYPE_SELECT0
#define AES_CONTROL2_DATA_REG_TYPE_SELECT1 _AES_CONTROL2.Bits.DATA_REG_TYPE_SELECT1
#define AES_CONTROL2_DATA_REG_TYPE_SELECT2 _AES_CONTROL2.Bits.DATA_REG_TYPE_SELECT2
#define AES_CONTROL2_DATA_REG_TYPE_SELECT _AES_CONTROL2.MergedBits.grpDATA_REG_TYPE_SELECT

#define AES_CONTROL2_TSTPAS_MASK        2U
#define AES_CONTROL2_IRQ_FLAG_MASK      4U
#define AES_CONTROL2_DATA_REG_TYPE_SELECT0_MASK 32U
#define AES_CONTROL2_DATA_REG_TYPE_SELECT1_MASK 64U
#define AES_CONTROL2_DATA_REG_TYPE_SELECT2_MASK 128U
#define AES_CONTROL2_DATA_REG_TYPE_SELECT_MASK 224U
#define AES_CONTROL2_DATA_REG_TYPE_SELECT_BITNUM 5U


/*** ASM_Data_0 - AES 128 Data Register 0; 0x00000022 ***/
typedef union {
  byte Byte;
} ASM_Data_0STR;
extern volatile ASM_Data_0STR _ASM_Data_0 @0x00000022;
#define ASM_Data_0                      _ASM_Data_0.Byte
/* ASM_Data__ARR: Access 10 ASM_Data_x registers in an array */
#define ASM_Data__ARR                   ((volatile byte * __far) &ASM_Data_0)


/*** ASM_Data_1 - AES 128 Data Register 1; 0x00000023 ***/
typedef union {
  byte Byte;
} ASM_Data_1STR;
extern volatile ASM_Data_1STR _ASM_Data_1 @0x00000023;
#define ASM_Data_1                      _ASM_Data_1.Byte


/*** ASM_Data_2 - AES 128 Data Register 2; 0x00000024 ***/
typedef union {
  byte Byte;
} ASM_Data_2STR;
extern volatile ASM_Data_2STR _ASM_Data_2 @0x00000024;
#define ASM_Data_2                      _ASM_Data_2.Byte


/*** ASM_Data_3 - AES 128 Data Register 3; 0x00000025 ***/
typedef union {
  byte Byte;
} ASM_Data_3STR;
extern volatile ASM_Data_3STR _ASM_Data_3 @0x00000025;
#define ASM_Data_3                      _ASM_Data_3.Byte


/*** ASM_Data_4 - AES 128 Data Register 4; 0x00000026 ***/
typedef union {
  byte Byte;
} ASM_Data_4STR;
extern volatile ASM_Data_4STR _ASM_Data_4 @0x00000026;
#define ASM_Data_4                      _ASM_Data_4.Byte


/*** ASM_Data_5 - AES 128 Data Register 5; 0x00000027 ***/
typedef union {
  byte Byte;
} ASM_Data_5STR;
extern volatile ASM_Data_5STR _ASM_Data_5 @0x00000027;
#define ASM_Data_5                      _ASM_Data_5.Byte


/*** ASM_Data_6 - AES 128 Data Register 6; 0x00000028 ***/
typedef union {
  byte Byte;
} ASM_Data_6STR;
extern volatile ASM_Data_6STR _ASM_Data_6 @0x00000028;
#define ASM_Data_6                      _ASM_Data_6.Byte


/*** ASM_Data_7 - AES 128 Data Register 7; 0x00000029 ***/
typedef union {
  byte Byte;
} ASM_Data_7STR;
extern volatile ASM_Data_7STR _ASM_Data_7 @0x00000029;
#define ASM_Data_7                      _ASM_Data_7.Byte


/*** ASM_Data_8 - AES 128 Data Register 8; 0x0000002A ***/
typedef union {
  byte Byte;
} ASM_Data_8STR;
extern volatile ASM_Data_8STR _ASM_Data_8 @0x0000002A;
#define ASM_Data_8                      _ASM_Data_8.Byte


/*** ASM_Data_9 - AES 128 Data Register 9; 0x0000002B ***/
typedef union {
  byte Byte;
} ASM_Data_9STR;
extern volatile ASM_Data_9STR _ASM_Data_9 @0x0000002B;
#define ASM_Data_9                      _ASM_Data_9.Byte


/*** ASM_Data_A - AES 128 Data Register A; 0x0000002C ***/
typedef union {
  byte Byte;
} ASM_Data_ASTR;
extern volatile ASM_Data_ASTR _ASM_Data_A @0x0000002C;
#define ASM_Data_A                      _ASM_Data_A.Byte


/*** ASM_Data_B - AES 128 Data Register B; 0x0000002D ***/
typedef union {
  byte Byte;
} ASM_Data_BSTR;
extern volatile ASM_Data_BSTR _ASM_Data_B @0x0000002D;
#define ASM_Data_B                      _ASM_Data_B.Byte


/*** ASM_Data_C - AES 128 Data Register C; 0x0000002E ***/
typedef union {
  byte Byte;
} ASM_Data_CSTR;
extern volatile ASM_Data_CSTR _ASM_Data_C @0x0000002E;
#define ASM_Data_C                      _ASM_Data_C.Byte


/*** ASM_Data_D - AES 128 Data Register D; 0x0000002F ***/
typedef union {
  byte Byte;
} ASM_Data_DSTR;
extern volatile ASM_Data_DSTR _ASM_Data_D @0x0000002F;
#define ASM_Data_D                      _ASM_Data_D.Byte


/*** ASM_Data_E - AES 128 Data Register E; 0x00000030 ***/
typedef union {
  byte Byte;
} ASM_Data_ESTR;
extern volatile ASM_Data_ESTR _ASM_Data_E @0x00000030;
#define ASM_Data_E                      _ASM_Data_E.Byte


/*** ASM_Data_F - AES 128 Data Register F; 0x00000031 ***/
typedef union {
  byte Byte;
} ASM_Data_FSTR;
extern volatile ASM_Data_FSTR _ASM_Data_F @0x00000031;
#define ASM_Data_F                      _ASM_Data_F.Byte


/*** KBI1SC - KBI1 Status and Control Register; 0x00000032 ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI1SCSTR;
extern volatile KBI1SCSTR _KBI1SC @0x00000032;
#define KBI1SC                          _KBI1SC.Byte
#define KBI1SC_KBIMOD                   _KBI1SC.Bits.KBIMOD
#define KBI1SC_KBIE                     _KBI1SC.Bits.KBIE
#define KBI1SC_KBACK                    _KBI1SC.Bits.KBACK
#define KBI1SC_KBF                      _KBI1SC.Bits.KBF

#define KBI1SC_KBIMOD_MASK              1U
#define KBI1SC_KBIE_MASK                2U
#define KBI1SC_KBACK_MASK               4U
#define KBI1SC_KBF_MASK                 8U


/*** KBI1PE - KBI1 Pin Enable Register; 0x00000033 ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte KBIPE4      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 4 */
    byte KBIPE5      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 5 */
    byte KBIPE6      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 6 */
    byte KBIPE7      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 7 */
  } Bits;
} KBI1PESTR;
extern volatile KBI1PESTR _KBI1PE @0x00000033;
#define KBI1PE                          _KBI1PE.Byte
#define KBI1PE_KBIPE0                   _KBI1PE.Bits.KBIPE0
#define KBI1PE_KBIPE1                   _KBI1PE.Bits.KBIPE1
#define KBI1PE_KBIPE2                   _KBI1PE.Bits.KBIPE2
#define KBI1PE_KBIPE3                   _KBI1PE.Bits.KBIPE3
#define KBI1PE_KBIPE4                   _KBI1PE.Bits.KBIPE4
#define KBI1PE_KBIPE5                   _KBI1PE.Bits.KBIPE5
#define KBI1PE_KBIPE6                   _KBI1PE.Bits.KBIPE6
#define KBI1PE_KBIPE7                   _KBI1PE.Bits.KBIPE7

#define KBI1PE_KBIPE0_MASK              1U
#define KBI1PE_KBIPE1_MASK              2U
#define KBI1PE_KBIPE2_MASK              4U
#define KBI1PE_KBIPE3_MASK              8U
#define KBI1PE_KBIPE4_MASK              16U
#define KBI1PE_KBIPE5_MASK              32U
#define KBI1PE_KBIPE6_MASK              64U
#define KBI1PE_KBIPE7_MASK              128U


/*** KBI1ES - KBI1 Edge Select Register; 0x00000034 ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte KBEDG4      :1;                                       /* Keyboard Edge Select Bit 4 */
    byte KBEDG5      :1;                                       /* Keyboard Edge Select Bit 5 */
    byte KBEDG6      :1;                                       /* Keyboard Edge Select Bit 6 */
    byte KBEDG7      :1;                                       /* Keyboard Edge Select Bit 7 */
  } Bits;
} KBI1ESSTR;
extern volatile KBI1ESSTR _KBI1ES @0x00000034;
#define KBI1ES                          _KBI1ES.Byte
#define KBI1ES_KBEDG0                   _KBI1ES.Bits.KBEDG0
#define KBI1ES_KBEDG1                   _KBI1ES.Bits.KBEDG1
#define KBI1ES_KBEDG2                   _KBI1ES.Bits.KBEDG2
#define KBI1ES_KBEDG3                   _KBI1ES.Bits.KBEDG3
#define KBI1ES_KBEDG4                   _KBI1ES.Bits.KBEDG4
#define KBI1ES_KBEDG5                   _KBI1ES.Bits.KBEDG5
#define KBI1ES_KBEDG6                   _KBI1ES.Bits.KBEDG6
#define KBI1ES_KBEDG7                   _KBI1ES.Bits.KBEDG7

#define KBI1ES_KBEDG0_MASK              1U
#define KBI1ES_KBEDG1_MASK              2U
#define KBI1ES_KBEDG2_MASK              4U
#define KBI1ES_KBEDG3_MASK              8U
#define KBI1ES_KBEDG4_MASK              16U
#define KBI1ES_KBEDG5_MASK              32U
#define KBI1ES_KBEDG6_MASK              64U
#define KBI1ES_KBEDG7_MASK              128U


/*** KBI2SC - KBI2 Status and Control Register; 0x00000035 ***/
typedef union {
  byte Byte;
  struct {
    byte KBIMOD      :1;                                       /* Keyboard Detection Mode */
    byte KBIE        :1;                                       /* Keyboard Interrupt Enable */
    byte KBACK       :1;                                       /* Keyboard Interrupt Acknowledge */
    byte KBF         :1;                                       /* Keyboard Interrupt Flag */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} KBI2SCSTR;
extern volatile KBI2SCSTR _KBI2SC @0x00000035;
#define KBI2SC                          _KBI2SC.Byte
#define KBI2SC_KBIMOD                   _KBI2SC.Bits.KBIMOD
#define KBI2SC_KBIE                     _KBI2SC.Bits.KBIE
#define KBI2SC_KBACK                    _KBI2SC.Bits.KBACK
#define KBI2SC_KBF                      _KBI2SC.Bits.KBF

#define KBI2SC_KBIMOD_MASK              1U
#define KBI2SC_KBIE_MASK                2U
#define KBI2SC_KBACK_MASK               4U
#define KBI2SC_KBF_MASK                 8U


/*** KBI2PE - KBI2 Pin Enable Register; 0x00000036 ***/
typedef union {
  byte Byte;
  struct {
    byte KBIPE0      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 0 */
    byte KBIPE1      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 1 */
    byte KBIPE2      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 2 */
    byte KBIPE3      :1;                                       /* Keyboard Pin Enable for KBI Port Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpKBIPE :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} KBI2PESTR;
extern volatile KBI2PESTR _KBI2PE @0x00000036;
#define KBI2PE                          _KBI2PE.Byte
#define KBI2PE_KBIPE0                   _KBI2PE.Bits.KBIPE0
#define KBI2PE_KBIPE1                   _KBI2PE.Bits.KBIPE1
#define KBI2PE_KBIPE2                   _KBI2PE.Bits.KBIPE2
#define KBI2PE_KBIPE3                   _KBI2PE.Bits.KBIPE3
#define KBI2PE_KBIPE                    _KBI2PE.MergedBits.grpKBIPE

#define KBI2PE_KBIPE0_MASK              1U
#define KBI2PE_KBIPE1_MASK              2U
#define KBI2PE_KBIPE2_MASK              4U
#define KBI2PE_KBIPE3_MASK              8U
#define KBI2PE_KBIPE_MASK               15U
#define KBI2PE_KBIPE_BITNUM             0U


/*** KBI2ES - KBI2 Edge Select Register; 0x00000037 ***/
typedef union {
  byte Byte;
  struct {
    byte KBEDG0      :1;                                       /* Keyboard Edge Select Bit 0 */
    byte KBEDG1      :1;                                       /* Keyboard Edge Select Bit 1 */
    byte KBEDG2      :1;                                       /* Keyboard Edge Select Bit 2 */
    byte KBEDG3      :1;                                       /* Keyboard Edge Select Bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpKBEDG :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} KBI2ESSTR;
extern volatile KBI2ESSTR _KBI2ES @0x00000037;
#define KBI2ES                          _KBI2ES.Byte
#define KBI2ES_KBEDG0                   _KBI2ES.Bits.KBEDG0
#define KBI2ES_KBEDG1                   _KBI2ES.Bits.KBEDG1
#define KBI2ES_KBEDG2                   _KBI2ES.Bits.KBEDG2
#define KBI2ES_KBEDG3                   _KBI2ES.Bits.KBEDG3
#define KBI2ES_KBEDG                    _KBI2ES.MergedBits.grpKBEDG

#define KBI2ES_KBEDG0_MASK              1U
#define KBI2ES_KBEDG1_MASK              2U
#define KBI2ES_KBEDG2_MASK              4U
#define KBI2ES_KBEDG3_MASK              8U
#define KBI2ES_KBEDG_MASK               15U
#define KBI2ES_KBEDG_BITNUM             0U


/*** SCIBD - SCI Baud Rate Register; 0x00000038 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SCIBDH - SCI Baud Rate Register High; 0x00000038 ***/
    union {
      byte Byte;
      struct {
        byte SBR8        :1;                                       /* Baud Rate Modulo Divisor Bit 8 */
        byte SBR9        :1;                                       /* Baud Rate Modulo Divisor Bit 9 */
        byte SBR10       :1;                                       /* Baud Rate Modulo Divisor Bit 10 */
        byte SBR11       :1;                                       /* Baud Rate Modulo Divisor Bit 11 */
        byte SBR12       :1;                                       /* Baud Rate Modulo Divisor Bit 12 */
        byte             :1; 
        byte RXEDGIE     :1;                                       /* RxD Input Active Edge Interrupt Enable (for RXEDGIF) */
        byte LBKDIE      :1;                                       /* LIN Break Detect Interrupt Enable (for LBKDIF) */
      } Bits;
      struct {
        byte grpSBR_8 :5;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SCIBDHSTR;
    #define SCIBDH                      _SCIBD.Overlap_STR.SCIBDHSTR.Byte
    #define SCIBDH_SBR8                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR8
    #define SCIBDH_SBR9                 _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR9
    #define SCIBDH_SBR10                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR10
    #define SCIBDH_SBR11                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR11
    #define SCIBDH_SBR12                _SCIBD.Overlap_STR.SCIBDHSTR.Bits.SBR12
    #define SCIBDH_RXEDGIE              _SCIBD.Overlap_STR.SCIBDHSTR.Bits.RXEDGIE
    #define SCIBDH_LBKDIE               _SCIBD.Overlap_STR.SCIBDHSTR.Bits.LBKDIE
    #define SCIBDH_SBR_8                _SCIBD.Overlap_STR.SCIBDHSTR.MergedBits.grpSBR_8
    #define SCIBDH_SBR                  SCIBDH_SBR_8
    
    #define SCIBDH_SBR8_MASK            1U
    #define SCIBDH_SBR9_MASK            2U
    #define SCIBDH_SBR10_MASK           4U
    #define SCIBDH_SBR11_MASK           8U
    #define SCIBDH_SBR12_MASK           16U
    #define SCIBDH_RXEDGIE_MASK         64U
    #define SCIBDH_LBKDIE_MASK          128U
    #define SCIBDH_SBR_8_MASK           31U
    #define SCIBDH_SBR_8_BITNUM         0U
    

    /*** SCIBDL - SCI Baud Rate Register Low; 0x00000039 ***/
    union {
      byte Byte;
      struct {
        byte SBR0        :1;                                       /* Baud Rate Modulo Divisor Bit 0 */
        byte SBR1        :1;                                       /* Baud Rate Modulo Divisor Bit 1 */
        byte SBR2        :1;                                       /* Baud Rate Modulo Divisor Bit 2 */
        byte SBR3        :1;                                       /* Baud Rate Modulo Divisor Bit 3 */
        byte SBR4        :1;                                       /* Baud Rate Modulo Divisor Bit 4 */
        byte SBR5        :1;                                       /* Baud Rate Modulo Divisor Bit 5 */
        byte SBR6        :1;                                       /* Baud Rate Modulo Divisor Bit 6 */
        byte SBR7        :1;                                       /* Baud Rate Modulo Divisor Bit 7 */
      } Bits;
    } SCIBDLSTR;
    #define SCIBDL                      _SCIBD.Overlap_STR.SCIBDLSTR.Byte
    #define SCIBDL_SBR0                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR0
    #define SCIBDL_SBR1                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR1
    #define SCIBDL_SBR2                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR2
    #define SCIBDL_SBR3                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR3
    #define SCIBDL_SBR4                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR4
    #define SCIBDL_SBR5                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR5
    #define SCIBDL_SBR6                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR6
    #define SCIBDL_SBR7                 _SCIBD.Overlap_STR.SCIBDLSTR.Bits.SBR7
    
    #define SCIBDL_SBR0_MASK            1U
    #define SCIBDL_SBR1_MASK            2U
    #define SCIBDL_SBR2_MASK            4U
    #define SCIBDL_SBR3_MASK            8U
    #define SCIBDL_SBR4_MASK            16U
    #define SCIBDL_SBR5_MASK            32U
    #define SCIBDL_SBR6_MASK            64U
    #define SCIBDL_SBR7_MASK            128U
    
  } Overlap_STR;

} SCIBDSTR;
extern volatile SCIBDSTR _SCIBD @0x00000038;
#define SCIBD                           _SCIBD.Word


/*** SCIC1 - SCI Control Register 1; 0x0000003A ***/
typedef union {
  byte Byte;
  struct {
    byte PT          :1;                                       /* Parity Type */
    byte PE          :1;                                       /* Parity Enable */
    byte ILT         :1;                                       /* Idle Line Type Select */
    byte WAKE        :1;                                       /* Receiver Wakeup Method Select */
    byte M           :1;                                       /* 9-Bit or 8-Bit Mode Select */
    byte RSRC        :1;                                       /* Receiver Source Select */
    byte SCISWAI     :1;                                       /* SCI Stops in Wait Mode */
    byte LOOPS       :1;                                       /* Loop Mode Select */
  } Bits;
} SCIC1STR;
extern volatile SCIC1STR _SCIC1 @0x0000003A;
#define SCIC1                           _SCIC1.Byte
#define SCIC1_PT                        _SCIC1.Bits.PT
#define SCIC1_PE                        _SCIC1.Bits.PE
#define SCIC1_ILT                       _SCIC1.Bits.ILT
#define SCIC1_WAKE                      _SCIC1.Bits.WAKE
#define SCIC1_M                         _SCIC1.Bits.M
#define SCIC1_RSRC                      _SCIC1.Bits.RSRC
#define SCIC1_SCISWAI                   _SCIC1.Bits.SCISWAI
#define SCIC1_LOOPS                     _SCIC1.Bits.LOOPS

#define SCIC1_PT_MASK                   1U
#define SCIC1_PE_MASK                   2U
#define SCIC1_ILT_MASK                  4U
#define SCIC1_WAKE_MASK                 8U
#define SCIC1_M_MASK                    16U
#define SCIC1_RSRC_MASK                 32U
#define SCIC1_SCISWAI_MASK              64U
#define SCIC1_LOOPS_MASK                128U


/*** SCIC2 - SCI Control Register 2; 0x0000003B ***/
typedef union {
  byte Byte;
  struct {
    byte SBK         :1;                                       /* Send Break */
    byte RWU         :1;                                       /* Receiver Wakeup Control */
    byte RE          :1;                                       /* Receiver Enable */
    byte TE          :1;                                       /* Transmitter Enable */
    byte ILIE        :1;                                       /* Idle Line Interrupt Enable (for IDLE) */
    byte RIE         :1;                                       /* Receiver Interrupt Enable (for RDRF) */
    byte TCIE        :1;                                       /* Transmission Complete Interrupt Enable (for TC) */
    byte TIE         :1;                                       /* Transmit Interrupt Enable (for TDRE) */
  } Bits;
} SCIC2STR;
extern volatile SCIC2STR _SCIC2 @0x0000003B;
#define SCIC2                           _SCIC2.Byte
#define SCIC2_SBK                       _SCIC2.Bits.SBK
#define SCIC2_RWU                       _SCIC2.Bits.RWU
#define SCIC2_RE                        _SCIC2.Bits.RE
#define SCIC2_TE                        _SCIC2.Bits.TE
#define SCIC2_ILIE                      _SCIC2.Bits.ILIE
#define SCIC2_RIE                       _SCIC2.Bits.RIE
#define SCIC2_TCIE                      _SCIC2.Bits.TCIE
#define SCIC2_TIE                       _SCIC2.Bits.TIE

#define SCIC2_SBK_MASK                  1U
#define SCIC2_RWU_MASK                  2U
#define SCIC2_RE_MASK                   4U
#define SCIC2_TE_MASK                   8U
#define SCIC2_ILIE_MASK                 16U
#define SCIC2_RIE_MASK                  32U
#define SCIC2_TCIE_MASK                 64U
#define SCIC2_TIE_MASK                  128U


/*** SCIS1 - SCI Status Register 1; 0x0000003C ***/
typedef union {
  byte Byte;
  struct {
    byte PF          :1;                                       /* Parity Error Flag */
    byte FE          :1;                                       /* Framing Error Flag */
    byte NF          :1;                                       /* Noise Flag */
    byte OR          :1;                                       /* Receiver Overrun Flag */
    byte IDLE        :1;                                       /* Idle Line Flag */
    byte RDRF        :1;                                       /* Receive Data Register Full Flag */
    byte TC          :1;                                       /* Transmission Complete Flag */
    byte TDRE        :1;                                       /* Transmit Data Register Empty Flag */
  } Bits;
} SCIS1STR;
extern volatile SCIS1STR _SCIS1 @0x0000003C;
#define SCIS1                           _SCIS1.Byte
#define SCIS1_PF                        _SCIS1.Bits.PF
#define SCIS1_FE                        _SCIS1.Bits.FE
#define SCIS1_NF                        _SCIS1.Bits.NF
#define SCIS1_OR                        _SCIS1.Bits.OR
#define SCIS1_IDLE                      _SCIS1.Bits.IDLE
#define SCIS1_RDRF                      _SCIS1.Bits.RDRF
#define SCIS1_TC                        _SCIS1.Bits.TC
#define SCIS1_TDRE                      _SCIS1.Bits.TDRE

#define SCIS1_PF_MASK                   1U
#define SCIS1_FE_MASK                   2U
#define SCIS1_NF_MASK                   4U
#define SCIS1_OR_MASK                   8U
#define SCIS1_IDLE_MASK                 16U
#define SCIS1_RDRF_MASK                 32U
#define SCIS1_TC_MASK                   64U
#define SCIS1_TDRE_MASK                 128U


/*** SCIS2 - SCI Status Register 2; 0x0000003D ***/
typedef union {
  byte Byte;
  struct {
    byte RAF         :1;                                       /* Receiver Active Flag */
    byte LBKDE       :1;                                       /* LIN Break Detection Enable */
    byte BRK13       :1;                                       /* Break Character Generation Length */
    byte RWUID       :1;                                       /* Receive Wake Up Idle Detect */
    byte RXINV       :1;                                       /* Receive Data Inversion */
    byte             :1; 
    byte RXEDGIF     :1;                                       /* RxD Pin Active Edge Interrupt Flag */
    byte LBKDIF      :1;                                       /* LIN Break Detect Interrupt Flag */
  } Bits;
} SCIS2STR;
extern volatile SCIS2STR _SCIS2 @0x0000003D;
#define SCIS2                           _SCIS2.Byte
#define SCIS2_RAF                       _SCIS2.Bits.RAF
#define SCIS2_LBKDE                     _SCIS2.Bits.LBKDE
#define SCIS2_BRK13                     _SCIS2.Bits.BRK13
#define SCIS2_RWUID                     _SCIS2.Bits.RWUID
#define SCIS2_RXINV                     _SCIS2.Bits.RXINV
#define SCIS2_RXEDGIF                   _SCIS2.Bits.RXEDGIF
#define SCIS2_LBKDIF                    _SCIS2.Bits.LBKDIF

#define SCIS2_RAF_MASK                  1U
#define SCIS2_LBKDE_MASK                2U
#define SCIS2_BRK13_MASK                4U
#define SCIS2_RWUID_MASK                8U
#define SCIS2_RXINV_MASK                16U
#define SCIS2_RXEDGIF_MASK              64U
#define SCIS2_LBKDIF_MASK               128U


/*** SCIC3 - SCI Control Register 3; 0x0000003E ***/
typedef union {
  byte Byte;
  struct {
    byte PEIE        :1;                                       /* Parity Error Interrupt Enable */
    byte FEIE        :1;                                       /* Framing Error Interrupt Enable */
    byte NEIE        :1;                                       /* Noise Error Interrupt Enable */
    byte ORIE        :1;                                       /* Overrun Interrupt Enable */
    byte TXINV       :1;                                       /* Transmit Data Inversion */
    byte TXDIR       :1;                                       /* TxD Pin Direction in Single-Wire Mode */
    byte T8          :1;                                       /* Ninth Data Bit for Transmitter */
    byte R8          :1;                                       /* Ninth Data Bit for Receiver */
  } Bits;
} SCIC3STR;
extern volatile SCIC3STR _SCIC3 @0x0000003E;
#define SCIC3                           _SCIC3.Byte
#define SCIC3_PEIE                      _SCIC3.Bits.PEIE
#define SCIC3_FEIE                      _SCIC3.Bits.FEIE
#define SCIC3_NEIE                      _SCIC3.Bits.NEIE
#define SCIC3_ORIE                      _SCIC3.Bits.ORIE
#define SCIC3_TXINV                     _SCIC3.Bits.TXINV
#define SCIC3_TXDIR                     _SCIC3.Bits.TXDIR
#define SCIC3_T8                        _SCIC3.Bits.T8
#define SCIC3_R8                        _SCIC3.Bits.R8

#define SCIC3_PEIE_MASK                 1U
#define SCIC3_FEIE_MASK                 2U
#define SCIC3_NEIE_MASK                 4U
#define SCIC3_ORIE_MASK                 8U
#define SCIC3_TXINV_MASK                16U
#define SCIC3_TXDIR_MASK                32U
#define SCIC3_T8_MASK                   64U
#define SCIC3_R8_MASK                   128U


/*** SCID - SCI Data Register; 0x0000003F ***/
typedef union {
  byte Byte;
  struct {
    byte R0_T0       :1;                                       /* Receive/Transmit Data Bit 0 */
    byte R1_T1       :1;                                       /* Receive/Transmit Data Bit 1 */
    byte R2_T2       :1;                                       /* Receive/Transmit Data Bit 2 */
    byte R3_T3       :1;                                       /* Receive/Transmit Data Bit 3 */
    byte R4_T4       :1;                                       /* Receive/Transmit Data Bit 4 */
    byte R5_T5       :1;                                       /* Receive/Transmit Data Bit 5 */
    byte R6_T6       :1;                                       /* Receive/Transmit Data Bit 6 */
    byte R7_T7       :1;                                       /* Receive/Transmit Data Bit 7 */
  } Bits;
} SCIDSTR;
extern volatile SCIDSTR _SCID @0x0000003F;
#define SCID                            _SCID.Byte
#define SCID_R0_T0                      _SCID.Bits.R0_T0
#define SCID_R1_T1                      _SCID.Bits.R1_T1
#define SCID_R2_T2                      _SCID.Bits.R2_T2
#define SCID_R3_T3                      _SCID.Bits.R3_T3
#define SCID_R4_T4                      _SCID.Bits.R4_T4
#define SCID_R5_T5                      _SCID.Bits.R5_T5
#define SCID_R6_T6                      _SCID.Bits.R6_T6
#define SCID_R7_T7                      _SCID.Bits.R7_T7

#define SCID_R0_T0_MASK                 1U
#define SCID_R1_T1_MASK                 2U
#define SCID_R2_T2_MASK                 4U
#define SCID_R3_T3_MASK                 8U
#define SCID_R4_T4_MASK                 16U
#define SCID_R5_T5_MASK                 32U
#define SCID_R6_T6_MASK                 64U
#define SCID_R7_T7_MASK                 128U


/*** PHY_TXD_ADR_PNTR0 - Transmit Data Pointer Register 0; 0x00000040 ***/
typedef union {
  byte Byte;
  struct {
    byte TXD_ADR_PNTR :5;                                      /* Transmit Data Pointer, bit 8 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PHY_TXD_ADR_PNTR0STR;
extern volatile PHY_TXD_ADR_PNTR0STR _PHY_TXD_ADR_PNTR0 @0x00000040;
#define PHY_TXD_ADR_PNTR0               _PHY_TXD_ADR_PNTR0.Byte
#define PHY_TXD_ADR_PNTR0_TXD_ADR_PNTR  _PHY_TXD_ADR_PNTR0.Bits.TXD_ADR_PNTR
/* PHY_TXD_ADR_PNTR_ARR: Access 2 PHY_TXD_ADR_PNTRx registers in an array */
#define PHY_TXD_ADR_PNTR_ARR            ((volatile byte * __far) &PHY_TXD_ADR_PNTR0)

#define PHY_TXD_ADR_PNTR0_TXD_ADR_PNTR_MASK 31U
#define PHY_TXD_ADR_PNTR0_TXD_ADR_PNTR_BITNUM 0U


/*** PHY_TXD_ADR_PNTR1 - Transmit Data Pointer Register 1; 0x00000041 ***/
typedef union {
  byte Byte;
} PHY_TXD_ADR_PNTR1STR;
extern volatile PHY_TXD_ADR_PNTR1STR _PHY_TXD_ADR_PNTR1 @0x00000041;
#define PHY_TXD_ADR_PNTR1               _PHY_TXD_ADR_PNTR1.Byte


/*** PHY_RXD_ADR_PNTR0 - Receive Data Pointer Register 0; 0x00000042 ***/
typedef union {
  byte Byte;
  struct {
    byte RXD_ADR_PNTR0 :5;                                     /* Receive Data Pointer, bit 8 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PHY_RXD_ADR_PNTR0STR;
extern volatile PHY_RXD_ADR_PNTR0STR _PHY_RXD_ADR_PNTR0 @0x00000042;
#define PHY_RXD_ADR_PNTR0               _PHY_RXD_ADR_PNTR0.Byte
#define PHY_RXD_ADR_PNTR0_RXD_ADR_PNTR0 _PHY_RXD_ADR_PNTR0.Bits.RXD_ADR_PNTR0
/* PHY_RXD_ADR_PNTR_ARR: Access 2 PHY_RXD_ADR_PNTRx registers in an array */
#define PHY_RXD_ADR_PNTR_ARR            ((volatile byte * __far) &PHY_RXD_ADR_PNTR0)

#define PHY_RXD_ADR_PNTR0_RXD_ADR_PNTR0_MASK 31U
#define PHY_RXD_ADR_PNTR0_RXD_ADR_PNTR0_BITNUM 0U


/*** PHY_RXD_ADR_PNTR1 - Receive Data Pointer Register 1; 0x00000043 ***/
typedef union {
  byte Byte;
} PHY_RXD_ADR_PNTR1STR;
extern volatile PHY_RXD_ADR_PNTR1STR _PHY_RXD_ADR_PNTR1 @0x00000043;
#define PHY_RXD_ADR_PNTR1               _PHY_RXD_ADR_PNTR1.Byte


/*** PHY_CNTRL1 - Transceiver Control Register 1; 0x00000044 ***/
typedef union {
  byte Byte;
  struct {
    byte XCVSEQ0     :1;                                       /* Transceiver Sequence, bit 0, bit 0 */
    byte XCVSEQ1     :1;                                       /* Transceiver Sequence, bit 0, bit 1 */
    byte XCVSEQ2     :1;                                       /* Transceiver Sequence, bit 0, bit 2 */
    byte AUTOACK     :1;                                       /* Auto Acknowledge Enable */
    byte RXACKRQD    :1;                                       /* RX Acknowledge Required */
    byte CCABFRTX    :1;                                       /* Clear Channel Assessment Before Transmit */
    byte SLOTTED     :1;                                       /* Slotted Mode */
    byte TMRTRIGEN   :1;                                       /* Timer Trigger Enable */
  } Bits;
  struct {
    byte grpXCVSEQ :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PHY_CNTRL1STR;
extern volatile PHY_CNTRL1STR _PHY_CNTRL1 @0x00000044;
#define PHY_CNTRL1                      _PHY_CNTRL1.Byte
#define PHY_CNTRL1_XCVSEQ0              _PHY_CNTRL1.Bits.XCVSEQ0
#define PHY_CNTRL1_XCVSEQ1              _PHY_CNTRL1.Bits.XCVSEQ1
#define PHY_CNTRL1_XCVSEQ2              _PHY_CNTRL1.Bits.XCVSEQ2
#define PHY_CNTRL1_AUTOACK              _PHY_CNTRL1.Bits.AUTOACK
#define PHY_CNTRL1_RXACKRQD             _PHY_CNTRL1.Bits.RXACKRQD
#define PHY_CNTRL1_CCABFRTX             _PHY_CNTRL1.Bits.CCABFRTX
#define PHY_CNTRL1_SLOTTED              _PHY_CNTRL1.Bits.SLOTTED
#define PHY_CNTRL1_TMRTRIGEN            _PHY_CNTRL1.Bits.TMRTRIGEN
#define PHY_CNTRL1_XCVSEQ               _PHY_CNTRL1.MergedBits.grpXCVSEQ

#define PHY_CNTRL1_XCVSEQ0_MASK         1U
#define PHY_CNTRL1_XCVSEQ1_MASK         2U
#define PHY_CNTRL1_XCVSEQ2_MASK         4U
#define PHY_CNTRL1_AUTOACK_MASK         8U
#define PHY_CNTRL1_RXACKRQD_MASK        16U
#define PHY_CNTRL1_CCABFRTX_MASK        32U
#define PHY_CNTRL1_SLOTTED_MASK         64U
#define PHY_CNTRL1_TMRTRIGEN_MASK       128U
#define PHY_CNTRL1_XCVSEQ_MASK          7U
#define PHY_CNTRL1_XCVSEQ_BITNUM        0U


/*** PHY_CNTRL2 - Transceiver Control Register 2; 0x00000045 ***/
typedef union {
  byte Byte;
  struct {
    byte TC2EN       :1;                                       /* TC2 Prime Enable */
    byte PROMISCUOUS :1;                                       /* Promiscuous Mode Enable */
    byte TMRLOAD     :1;                                       /* Timer Load */
    byte CCATYPE0    :1;                                       /* CCA Type, bit 0, bit 0 */
    byte CCATYPE1    :1;                                       /* CCA Type, bit 0, bit 1 */
    byte PANCORDNTR  :1;                                       /* Pan Coordinator Enable */
    byte TC3TMOUT    :1;                                       /* Timer Comparator 3 Time-out */
    byte TRCV_MSK    :1;                                       /* Modem Interrupt Mask */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCCATYPE :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PHY_CNTRL2STR;
extern volatile PHY_CNTRL2STR _PHY_CNTRL2 @0x00000045;
#define PHY_CNTRL2                      _PHY_CNTRL2.Byte
#define PHY_CNTRL2_TC2EN                _PHY_CNTRL2.Bits.TC2EN
#define PHY_CNTRL2_PROMISCUOUS          _PHY_CNTRL2.Bits.PROMISCUOUS
#define PHY_CNTRL2_TMRLOAD              _PHY_CNTRL2.Bits.TMRLOAD
#define PHY_CNTRL2_CCATYPE0             _PHY_CNTRL2.Bits.CCATYPE0
#define PHY_CNTRL2_CCATYPE1             _PHY_CNTRL2.Bits.CCATYPE1
#define PHY_CNTRL2_PANCORDNTR           _PHY_CNTRL2.Bits.PANCORDNTR
#define PHY_CNTRL2_TC3TMOUT             _PHY_CNTRL2.Bits.TC3TMOUT
#define PHY_CNTRL2_TRCV_MSK             _PHY_CNTRL2.Bits.TRCV_MSK
#define PHY_CNTRL2_CCATYPE              _PHY_CNTRL2.MergedBits.grpCCATYPE

#define PHY_CNTRL2_TC2EN_MASK           1U
#define PHY_CNTRL2_PROMISCUOUS_MASK     2U
#define PHY_CNTRL2_TMRLOAD_MASK         4U
#define PHY_CNTRL2_CCATYPE0_MASK        8U
#define PHY_CNTRL2_CCATYPE1_MASK        16U
#define PHY_CNTRL2_PANCORDNTR_MASK      32U
#define PHY_CNTRL2_TC3TMOUT_MASK        64U
#define PHY_CNTRL2_TRCV_MSK_MASK        128U
#define PHY_CNTRL2_CCATYPE_MASK         24U
#define PHY_CNTRL2_CCATYPE_BITNUM       3U


/*** PHY_CNTRL3 - Transceiver Control Register 3; 0x00000046 ***/
typedef union {
  byte Byte;
  struct {
    byte SEQMSK      :1;                                       /* Sequence Interrupt Mask */
    byte TXMSK       :1;                                       /* Transmitter Interrupt Mask */
    byte RXMSK       :1;                                       /* Receiver Interrupt Mask */
    byte CCAMSK      :1;                                       /* Clear Assessment Interrupt Mask */
    byte RX_WMRK_MSK :1;                                       /* Received Count Water Mark interrupt */
    byte FILTERFAIL_MSK :1;                                    /* Rx Packet filtering */
    byte LO1_UNLOCK_MSK :1;                                    /* lo1_lock_irq */
    byte CRC_MSK     :1;                                       /* Cyclic Redundancy Check */
  } Bits;
} PHY_CNTRL3STR;
extern volatile PHY_CNTRL3STR _PHY_CNTRL3 @0x00000046;
#define PHY_CNTRL3                      _PHY_CNTRL3.Byte
#define PHY_CNTRL3_SEQMSK               _PHY_CNTRL3.Bits.SEQMSK
#define PHY_CNTRL3_TXMSK                _PHY_CNTRL3.Bits.TXMSK
#define PHY_CNTRL3_RXMSK                _PHY_CNTRL3.Bits.RXMSK
#define PHY_CNTRL3_CCAMSK               _PHY_CNTRL3.Bits.CCAMSK
#define PHY_CNTRL3_RX_WMRK_MSK          _PHY_CNTRL3.Bits.RX_WMRK_MSK
#define PHY_CNTRL3_FILTERFAIL_MSK       _PHY_CNTRL3.Bits.FILTERFAIL_MSK
#define PHY_CNTRL3_LO1_UNLOCK_MSK       _PHY_CNTRL3.Bits.LO1_UNLOCK_MSK
#define PHY_CNTRL3_CRC_MSK              _PHY_CNTRL3.Bits.CRC_MSK

#define PHY_CNTRL3_SEQMSK_MASK          1U
#define PHY_CNTRL3_TXMSK_MASK           2U
#define PHY_CNTRL3_RXMSK_MASK           4U
#define PHY_CNTRL3_CCAMSK_MASK          8U
#define PHY_CNTRL3_RX_WMRK_MSK_MASK     16U
#define PHY_CNTRL3_FILTERFAIL_MSK_MASK  32U
#define PHY_CNTRL3_LO1_UNLOCK_MSK_MASK  64U
#define PHY_CNTRL3_CRC_MSK_MASK         128U


/*** PHY_CNTRL4 - Transceiver Control Register 4; 0x00000047 ***/
typedef union {
  byte Byte;
  struct {
    byte TMR1CMP_EN  :1;                                       /* Timer Comparator 1 Enable */
    byte TMR2CMP_EN  :1;                                       /* Timer Comparator 2 Enable */
    byte TMR3CMP_EN  :1;                                       /* Timer Comparator 3 Enable */
    byte TMR4CMP_EN  :1;                                       /* Timer Comparator 4 Enable */
    byte TMR1MSK     :1;                                       /* Timer Comparator 1 Interrupt Mask */
    byte TMR2MSK     :1;                                       /* Timer Comparator 2 Interrupt Mask */
    byte TMR3MSK     :1;                                       /* Timer Comparator 3 Interrupt Mask */
    byte TMR4MSK     :1;                                       /* Timer Comparator 4 Interrupt Mask */
  } Bits;
} PHY_CNTRL4STR;
extern volatile PHY_CNTRL4STR _PHY_CNTRL4 @0x00000047;
#define PHY_CNTRL4                      _PHY_CNTRL4.Byte
#define PHY_CNTRL4_TMR1CMP_EN           _PHY_CNTRL4.Bits.TMR1CMP_EN
#define PHY_CNTRL4_TMR2CMP_EN           _PHY_CNTRL4.Bits.TMR2CMP_EN
#define PHY_CNTRL4_TMR3CMP_EN           _PHY_CNTRL4.Bits.TMR3CMP_EN
#define PHY_CNTRL4_TMR4CMP_EN           _PHY_CNTRL4.Bits.TMR4CMP_EN
#define PHY_CNTRL4_TMR1MSK              _PHY_CNTRL4.Bits.TMR1MSK
#define PHY_CNTRL4_TMR2MSK              _PHY_CNTRL4.Bits.TMR2MSK
#define PHY_CNTRL4_TMR3MSK              _PHY_CNTRL4.Bits.TMR3MSK
#define PHY_CNTRL4_TMR4MSK              _PHY_CNTRL4.Bits.TMR4MSK

#define PHY_CNTRL4_TMR1CMP_EN_MASK      1U
#define PHY_CNTRL4_TMR2CMP_EN_MASK      2U
#define PHY_CNTRL4_TMR3CMP_EN_MASK      4U
#define PHY_CNTRL4_TMR4CMP_EN_MASK      8U
#define PHY_CNTRL4_TMR1MSK_MASK         16U
#define PHY_CNTRL4_TMR2MSK_MASK         32U
#define PHY_CNTRL4_TMR3MSK_MASK         64U
#define PHY_CNTRL4_TMR4MSK_MASK         128U


/*** PHY_SRC_CNTRL - Transceiver Source Address Control Register; 0x00000048 ***/
typedef union {
  byte Byte;
  struct {
    byte INDEX_DISABLE :1;                                     /* Index Disable */
    byte INDEX_EN    :1;                                       /* Index Enable */
    byte SRCADDR_EN  :1;                                       /* Source Address Matching function Enable */
    byte ACK_FRM_PND :1;                                       /* If SRCADDR_EN enable field is a 0, then ACK_FRM_PND gets copied into the TXACK frame */
    byte INDEX0      :1;                                       /* Index Field, bit 0, bit 0 */
    byte INDEX1      :1;                                       /* Index Field, bit 0, bit 1 */
    byte INDEX2      :1;                                       /* Index Field, bit 0, bit 2 */
    byte INDEX3      :1;                                       /* Index Field, bit 0, bit 3 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpINDEX :4;
  } MergedBits;
} PHY_SRC_CNTRLSTR;
extern volatile PHY_SRC_CNTRLSTR _PHY_SRC_CNTRL @0x00000048;
#define PHY_SRC_CNTRL                   _PHY_SRC_CNTRL.Byte
#define PHY_SRC_CNTRL_INDEX_DISABLE     _PHY_SRC_CNTRL.Bits.INDEX_DISABLE
#define PHY_SRC_CNTRL_INDEX_EN          _PHY_SRC_CNTRL.Bits.INDEX_EN
#define PHY_SRC_CNTRL_SRCADDR_EN        _PHY_SRC_CNTRL.Bits.SRCADDR_EN
#define PHY_SRC_CNTRL_ACK_FRM_PND       _PHY_SRC_CNTRL.Bits.ACK_FRM_PND
#define PHY_SRC_CNTRL_INDEX0            _PHY_SRC_CNTRL.Bits.INDEX0
#define PHY_SRC_CNTRL_INDEX1            _PHY_SRC_CNTRL.Bits.INDEX1
#define PHY_SRC_CNTRL_INDEX2            _PHY_SRC_CNTRL.Bits.INDEX2
#define PHY_SRC_CNTRL_INDEX3            _PHY_SRC_CNTRL.Bits.INDEX3
#define PHY_SRC_CNTRL_INDEX             _PHY_SRC_CNTRL.MergedBits.grpINDEX

#define PHY_SRC_CNTRL_INDEX_DISABLE_MASK 1U
#define PHY_SRC_CNTRL_INDEX_EN_MASK     2U
#define PHY_SRC_CNTRL_SRCADDR_EN_MASK   4U
#define PHY_SRC_CNTRL_ACK_FRM_PND_MASK  8U
#define PHY_SRC_CNTRL_INDEX0_MASK       16U
#define PHY_SRC_CNTRL_INDEX1_MASK       32U
#define PHY_SRC_CNTRL_INDEX2_MASK       64U
#define PHY_SRC_CNTRL_INDEX3_MASK       128U
#define PHY_SRC_CNTRL_INDEX_MASK        240U
#define PHY_SRC_CNTRL_INDEX_BITNUM      4U


/*** PHY_SRC_ADDRS_SUM_DATA0 - Transceiver Source Address Sum Data Register 0; 0x00000049 ***/
typedef union {
  byte Byte;
} PHY_SRC_ADDRS_SUM_DATA0STR;
extern volatile PHY_SRC_ADDRS_SUM_DATA0STR _PHY_SRC_ADDRS_SUM_DATA0 @0x00000049;
#define PHY_SRC_ADDRS_SUM_DATA0         _PHY_SRC_ADDRS_SUM_DATA0.Byte
/* PHY_SRC_ADDRS_SUM_DATA_ARR: Access 2 PHY_SRC_ADDRS_SUM_DATAx registers in an array */
#define PHY_SRC_ADDRS_SUM_DATA_ARR      ((volatile byte * __far) &PHY_SRC_ADDRS_SUM_DATA0)


/*** PHY_SRC_ADDRS_SUM_DATA1 - Transceiver Source Address Sum Data Register 1; 0x0000004A ***/
typedef union {
  byte Byte;
} PHY_SRC_ADDRS_SUM_DATA1STR;
extern volatile PHY_SRC_ADDRS_SUM_DATA1STR _PHY_SRC_ADDRS_SUM_DATA1 @0x0000004A;
#define PHY_SRC_ADDRS_SUM_DATA1         _PHY_SRC_ADDRS_SUM_DATA1.Byte


/*** PHY_RX_WTR_MARK - Receiver Byte Count Watermark Threshold; 0x0000004B ***/
typedef union {
  byte Byte;
} PHY_RX_WTR_MARKSTR;
extern volatile PHY_RX_WTR_MARKSTR _PHY_RX_WTR_MARK @0x0000004B;
#define PHY_RX_WTR_MARK                 _PHY_RX_WTR_MARK.Byte


/*** PHY_RX_BYTE_COUNT - Receiver Byte Count; 0x0000004C ***/
typedef union {
  byte Byte;
} PHY_RX_BYTE_COUNTSTR;
extern volatile PHY_RX_BYTE_COUNTSTR _PHY_RX_BYTE_COUNT @0x0000004C;
#define PHY_RX_BYTE_COUNT               _PHY_RX_BYTE_COUNT.Byte


/*** PHY_STATUS1 - Status Register 1; 0x0000004D ***/
typedef union {
  byte Byte;
  struct {
    byte TMR1IRQ     :1;                                       /* Timer Comparator 1 Interrupt flag */
    byte TMR2IRQ     :1;                                       /* Timer Comparator 2 Interrupt flag */
    byte TMR3IRQ     :1;                                       /* Timer Comparator 3 Interrupt flag */
    byte TMR4IRQ     :1;                                       /* Timer Comparator 4 Interrupt flag */
    byte PI          :1;                                       /* Poll indication */
    byte SRCADDR     :1;                                       /* Part of the source address feature */
    byte CCA         :1;                                       /* Clear Channel Assessment result flag */
    byte CRCVALID    :1;                                       /* Code Redundancy Check Valid */
  } Bits;
} PHY_STATUS1STR;
extern volatile PHY_STATUS1STR _PHY_STATUS1 @0x0000004D;
#define PHY_STATUS1                     _PHY_STATUS1.Byte
#define PHY_STATUS1_TMR1IRQ             _PHY_STATUS1.Bits.TMR1IRQ
#define PHY_STATUS1_TMR2IRQ             _PHY_STATUS1.Bits.TMR2IRQ
#define PHY_STATUS1_TMR3IRQ             _PHY_STATUS1.Bits.TMR3IRQ
#define PHY_STATUS1_TMR4IRQ             _PHY_STATUS1.Bits.TMR4IRQ
#define PHY_STATUS1_PI                  _PHY_STATUS1.Bits.PI
#define PHY_STATUS1_SRCADDR             _PHY_STATUS1.Bits.SRCADDR
#define PHY_STATUS1_CCA                 _PHY_STATUS1.Bits.CCA
#define PHY_STATUS1_CRCVALID            _PHY_STATUS1.Bits.CRCVALID

#define PHY_STATUS1_TMR1IRQ_MASK        1U
#define PHY_STATUS1_TMR2IRQ_MASK        2U
#define PHY_STATUS1_TMR3IRQ_MASK        4U
#define PHY_STATUS1_TMR4IRQ_MASK        8U
#define PHY_STATUS1_PI_MASK             16U
#define PHY_STATUS1_SRCADDR_MASK        32U
#define PHY_STATUS1_CCA_MASK            64U
#define PHY_STATUS1_CRCVALID_MASK       128U


/*** PHY_STATUS2 - Status Register 2; 0x0000004E ***/
typedef union {
  byte Byte;
  struct {
    byte SEQIRQ      :1;                                       /* Sequence flag */
    byte TXIRQ       :1;                                       /* Transmitter flag */
    byte RXIRQ       :1;                                       /* Receiver flag */
    byte CCAIRQ      :1;                                       /* Clear Channel Assessment flag */
    byte RXWTRMRKIRQ :1;                                       /* Receiver Byte Count Water Mark flag */
    byte FILTERFAIL_IRQ :1;                                    /* Receiver Packet Filter Fail flag */
    byte LO1_UNLOCK_IRQ :1;                                    /* Local Oscillator Un-lock */
    byte RX_FRM_PEND :1;                                       /* Status of the frame pending bit of the frame control field */
  } Bits;
} PHY_STATUS2STR;
extern volatile PHY_STATUS2STR _PHY_STATUS2 @0x0000004E;
#define PHY_STATUS2                     _PHY_STATUS2.Byte
#define PHY_STATUS2_SEQIRQ              _PHY_STATUS2.Bits.SEQIRQ
#define PHY_STATUS2_TXIRQ               _PHY_STATUS2.Bits.TXIRQ
#define PHY_STATUS2_RXIRQ               _PHY_STATUS2.Bits.RXIRQ
#define PHY_STATUS2_CCAIRQ              _PHY_STATUS2.Bits.CCAIRQ
#define PHY_STATUS2_RXWTRMRKIRQ         _PHY_STATUS2.Bits.RXWTRMRKIRQ
#define PHY_STATUS2_FILTERFAIL_IRQ      _PHY_STATUS2.Bits.FILTERFAIL_IRQ
#define PHY_STATUS2_LO1_UNLOCK_IRQ      _PHY_STATUS2.Bits.LO1_UNLOCK_IRQ
#define PHY_STATUS2_RX_FRM_PEND         _PHY_STATUS2.Bits.RX_FRM_PEND

#define PHY_STATUS2_SEQIRQ_MASK         1U
#define PHY_STATUS2_TXIRQ_MASK          2U
#define PHY_STATUS2_RXIRQ_MASK          4U
#define PHY_STATUS2_CCAIRQ_MASK         8U
#define PHY_STATUS2_RXWTRMRKIRQ_MASK    16U
#define PHY_STATUS2_FILTERFAIL_IRQ_MASK 32U
#define PHY_STATUS2_LO1_UNLOCK_IRQ_MASK 64U
#define PHY_STATUS2_RX_FRM_PEND_MASK    128U


/*** PHY_CCAFNL - Clear Channel Assessment Final Value; 0x00000050 ***/
typedef union {
  byte Byte;
} PHY_CCAFNLSTR;
extern volatile PHY_CCAFNLSTR _PHY_CCAFNL @0x00000050;
#define PHY_CCAFNL                      _PHY_CCAFNL.Byte


/*** PHY_EVENT_TMR0 - Event Timer Register 0; 0x00000051 ***/
typedef union {
  byte Byte;
} PHY_EVENT_TMR0STR;
extern volatile PHY_EVENT_TMR0STR _PHY_EVENT_TMR0 @0x00000051;
#define PHY_EVENT_TMR0                  _PHY_EVENT_TMR0.Byte
/* PHY_EVENT_TMR_ARR: Access 3 PHY_EVENT_TMRx registers in an array */
#define PHY_EVENT_TMR_ARR               ((volatile byte * __far) &PHY_EVENT_TMR0)


/*** PHY_EVENT_TMR1 - Event Timer Register 1; 0x00000052 ***/
typedef union {
  byte Byte;
} PHY_EVENT_TMR1STR;
extern volatile PHY_EVENT_TMR1STR _PHY_EVENT_TMR1 @0x00000052;
#define PHY_EVENT_TMR1                  _PHY_EVENT_TMR1.Byte


/*** PHY_EVENT_TMR2 - Event Timer Register 2; 0x00000053 ***/
typedef union {
  byte Byte;
} PHY_EVENT_TMR2STR;
extern volatile PHY_EVENT_TMR2STR _PHY_EVENT_TMR2 @0x00000053;
#define PHY_EVENT_TMR2                  _PHY_EVENT_TMR2.Byte


/*** PHY_TIMESTAMP0 - Time Stamp Register 0; 0x00000054 ***/
typedef union {
  byte Byte;
} PHY_TIMESTAMP0STR;
extern volatile PHY_TIMESTAMP0STR _PHY_TIMESTAMP0 @0x00000054;
#define PHY_TIMESTAMP0                  _PHY_TIMESTAMP0.Byte
/* PHY_TIMESTAMP_ARR: Access 3 PHY_TIMESTAMPx registers in an array */
#define PHY_TIMESTAMP_ARR               ((volatile byte * __far) &PHY_TIMESTAMP0)


/*** PHY_TIMESTAMP1 - Time Stamp Register 1; 0x00000055 ***/
typedef union {
  byte Byte;
} PHY_TIMESTAMP1STR;
extern volatile PHY_TIMESTAMP1STR _PHY_TIMESTAMP1 @0x00000055;
#define PHY_TIMESTAMP1                  _PHY_TIMESTAMP1.Byte


/*** PHY_TIMESTAMP2 - Time Stamp Register 2; 0x00000056 ***/
typedef union {
  byte Byte;
} PHY_TIMESTAMP2STR;
extern volatile PHY_TIMESTAMP2STR _PHY_TIMESTAMP2 @0x00000056;
#define PHY_TIMESTAMP2                  _PHY_TIMESTAMP2.Byte


/*** PHY_T3CMP0 - Event Timer Comparator 3 Register 0; 0x00000057 ***/
typedef union {
  byte Byte;
} PHY_T3CMP0STR;
extern volatile PHY_T3CMP0STR _PHY_T3CMP0 @0x00000057;
#define PHY_T3CMP0                      _PHY_T3CMP0.Byte
/* PHY_T3CMP_ARR: Access 3 PHY_T3CMPx registers in an array */
#define PHY_T3CMP_ARR                   ((volatile byte * __far) &PHY_T3CMP0)


/*** PHY_T3CMP1 - Event Timer Comparator 3 Register 1; 0x00000058 ***/
typedef union {
  byte Byte;
} PHY_T3CMP1STR;
extern volatile PHY_T3CMP1STR _PHY_T3CMP1 @0x00000058;
#define PHY_T3CMP1                      _PHY_T3CMP1.Byte


/*** PHY_T3CMP2 - Event Timer Comparator 3 Register 2; 0x00000059 ***/
typedef union {
  byte Byte;
} PHY_T3CMP2STR;
extern volatile PHY_T3CMP2STR _PHY_T3CMP2 @0x00000059;
#define PHY_T3CMP2                      _PHY_T3CMP2.Byte


/*** PHY_TC2_PRIME0 - Time Comparator 2 Prime Register 0; 0x0000005A ***/
typedef union {
  byte Byte;
} PHY_TC2_PRIME0STR;
extern volatile PHY_TC2_PRIME0STR _PHY_TC2_PRIME0 @0x0000005A;
#define PHY_TC2_PRIME0                  _PHY_TC2_PRIME0.Byte
/* PHY_TC2_PRIME_ARR: Access 2 PHY_TC2_PRIMEx registers in an array */
#define PHY_TC2_PRIME_ARR               ((volatile byte * __far) &PHY_TC2_PRIME0)


/*** PHY_TC2_PRIME1 - Time Comparator 2 Prime Register 1; 0x0000005B ***/
typedef union {
  byte Byte;
} PHY_TC2_PRIME1STR;
extern volatile PHY_TC2_PRIME1STR _PHY_TC2_PRIME1 @0x0000005B;
#define PHY_TC2_PRIME1                  _PHY_TC2_PRIME1.Byte


/*** PHY_MACSHORTADDRS0 - MAC Short Address Register 0; 0x0000005C ***/
typedef union {
  byte Byte;
} PHY_MACSHORTADDRS0STR;
extern volatile PHY_MACSHORTADDRS0STR _PHY_MACSHORTADDRS0 @0x0000005C;
#define PHY_MACSHORTADDRS0              _PHY_MACSHORTADDRS0.Byte
/* PHY_MACSHORTADDRS_ARR: Access 2 PHY_MACSHORTADDRSx registers in an array */
#define PHY_MACSHORTADDRS_ARR           ((volatile byte * __far) &PHY_MACSHORTADDRS0)


/*** PHY_MACSHORTADDRS1 - MAC Short Address Register 1; 0x0000005D ***/
typedef union {
  byte Byte;
} PHY_MACSHORTADDRS1STR;
extern volatile PHY_MACSHORTADDRS1STR _PHY_MACSHORTADDRS1 @0x0000005D;
#define PHY_MACSHORTADDRS1              _PHY_MACSHORTADDRS1.Byte


/*** PHY_MACPANID0 - MAC Pan ID Register 0; 0x0000005E ***/
typedef union {
  byte Byte;
} PHY_MACPANID0STR;
extern volatile PHY_MACPANID0STR _PHY_MACPANID0 @0x0000005E;
#define PHY_MACPANID0                   _PHY_MACPANID0.Byte
/* PHY_MACPANID_ARR: Access 2 PHY_MACPANIDx registers in an array */
#define PHY_MACPANID_ARR                ((volatile byte * __far) &PHY_MACPANID0)


/*** PHY_MACPANID1 - MAC Pan ID Register 1; 0x0000005F ***/
typedef union {
  byte Byte;
} PHY_MACPANID1STR;
extern volatile PHY_MACPANID1STR _PHY_MACPANID1 @0x0000005F;
#define PHY_MACPANID1                   _PHY_MACPANID1.Byte


/*** CMTCG1 - Carrier Generator Data Register 1; 0x00000060 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCGH1 - CMT Carrier Generator Data Register 1 High Byte; 0x00000060 ***/
    union {
      byte Byte;
    } CMTCGH1STR;
    #define CMTCGH1                     _CMTCG1.Overlap_STR.CMTCGH1STR.Byte
    

    /*** CMTCGL1 - CMT Carrier Generator Data Register 1 Low Byte; 0x00000061 ***/
    union {
      byte Byte;
    } CMTCGL1STR;
    #define CMTCGL1                     _CMTCG1.Overlap_STR.CMTCGL1STR.Byte
    
  } Overlap_STR;

} CMTCG1STR;
extern volatile CMTCG1STR _CMTCG1 @0x00000060;
#define CMTCG1                          _CMTCG1.Word


/*** CMTCG2 - Carrier Generator Data Register 2; 0x00000062 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCGH2 - CMT Carrier Generator Data Register 2 High Byte; 0x00000062 ***/
    union {
      byte Byte;
    } CMTCGH2STR;
    #define CMTCGH2                     _CMTCG2.Overlap_STR.CMTCGH2STR.Byte
    

    /*** CMTCGL2 - CMT Carrier Generator Data Register 2 Low Byte; 0x00000063 ***/
    union {
      byte Byte;
    } CMTCGL2STR;
    #define CMTCGL2                     _CMTCG2.Overlap_STR.CMTCGL2STR.Byte
    
  } Overlap_STR;

} CMTCG2STR;
extern volatile CMTCG2STR _CMTCG2 @0x00000062;
#define CMTCG2                          _CMTCG2.Word


/*** CMTOC - CMT Output Control Register; 0x00000064 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CMTDIV2     :1;                                       /* CMT Clock Divide Prescaler Bit 2 */
    byte IROPEN      :1;                                       /* IRO pin enable */
    byte CMTPOL      :1;                                       /* CMT output polarity */
    byte IROL        :1;                                       /* IRO latch control */
  } Bits;
} CMTOCSTR;
extern volatile CMTOCSTR _CMTOC @0x00000064;
#define CMTOC                           _CMTOC.Byte
#define CMTOC_CMTDIV2                   _CMTOC.Bits.CMTDIV2
#define CMTOC_IROPEN                    _CMTOC.Bits.IROPEN
#define CMTOC_CMTPOL                    _CMTOC.Bits.CMTPOL
#define CMTOC_IROL                      _CMTOC.Bits.IROL

#define CMTOC_CMTDIV2_MASK              16U
#define CMTOC_IROPEN_MASK               32U
#define CMTOC_CMTPOL_MASK               64U
#define CMTOC_IROL_MASK                 128U


/*** CMTMSC - CMT Modulator Status and Control Register; 0x00000065 ***/
typedef union {
  byte Byte;
  struct {
    byte MCGEN       :1;                                       /* Modulator and Carrier Generator Enable */
    byte EOCIE       :1;                                       /* End of Cycle Interrupt Enable */
    byte FSK         :1;                                       /* FSK Mode Select */
    byte BASE        :1;                                       /* Baseband Mode Enable */
    byte EXSPC       :1;                                       /* Extended Space Enable */
    byte CMTDIV0     :1;                                       /* CMT Clock Divide Prescaler Bit 0 */
    byte CMTDIV1     :1;                                       /* CMT Clock Divide Prescaler Bit 1 */
    byte EOCF        :1;                                       /* End of Cycle Status Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpCMTDIV :2;
    byte         :1;
  } MergedBits;
} CMTMSCSTR;
extern volatile CMTMSCSTR _CMTMSC @0x00000065;
#define CMTMSC                          _CMTMSC.Byte
#define CMTMSC_MCGEN                    _CMTMSC.Bits.MCGEN
#define CMTMSC_EOCIE                    _CMTMSC.Bits.EOCIE
#define CMTMSC_FSK                      _CMTMSC.Bits.FSK
#define CMTMSC_BASE                     _CMTMSC.Bits.BASE
#define CMTMSC_EXSPC                    _CMTMSC.Bits.EXSPC
#define CMTMSC_CMTDIV0                  _CMTMSC.Bits.CMTDIV0
#define CMTMSC_CMTDIV1                  _CMTMSC.Bits.CMTDIV1
#define CMTMSC_EOCF                     _CMTMSC.Bits.EOCF
#define CMTMSC_CMTDIV                   _CMTMSC.MergedBits.grpCMTDIV

#define CMTMSC_MCGEN_MASK               1U
#define CMTMSC_EOCIE_MASK               2U
#define CMTMSC_FSK_MASK                 4U
#define CMTMSC_BASE_MASK                8U
#define CMTMSC_EXSPC_MASK               16U
#define CMTMSC_CMTDIV0_MASK             32U
#define CMTMSC_CMTDIV1_MASK             64U
#define CMTMSC_EOCF_MASK                128U
#define CMTMSC_CMTDIV_MASK              96U
#define CMTMSC_CMTDIV_BITNUM            5U


/*** CMTCMD12 - CMT Modulator Data Register 12; 0x00000066 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCMD1 - CMT Modulator Data Register 1; 0x00000066 ***/
    union {
      byte Byte;
    } CMTCMD1STR;
    #define CMTCMD1                     _CMTCMD12.Overlap_STR.CMTCMD1STR.Byte
    

    /*** CMTCMD2 - CMT Modulator Data Register 2; 0x00000067 ***/
    union {
      byte Byte;
      struct {
        byte MB0         :1;                                       /* Data Value Bit 0 */
        byte MB1         :1;                                       /* Data Value Bit 1 */
        byte MB2         :1;                                       /* Data Value Bit 2 */
        byte MB3         :1;                                       /* Data Value Bit 3 */
        byte MB4         :1;                                       /* Data Value Bit 4 */
        byte MB5         :1;                                       /* Data Value Bit 5 */
        byte MB6         :1;                                       /* Data Value Bit 6 */
        byte MB7         :1;                                       /* Data Value Bit 7 */
      } Bits;
    } CMTCMD2STR;
    #define CMTCMD2                     _CMTCMD12.Overlap_STR.CMTCMD2STR.Byte
    #define CMTCMD2_MB0                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB0
    #define CMTCMD2_MB1                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB1
    #define CMTCMD2_MB2                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB2
    #define CMTCMD2_MB3                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB3
    #define CMTCMD2_MB4                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB4
    #define CMTCMD2_MB5                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB5
    #define CMTCMD2_MB6                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB6
    #define CMTCMD2_MB7                 _CMTCMD12.Overlap_STR.CMTCMD2STR.Bits.MB7
    
    #define CMTCMD2_MB0_MASK            1U
    #define CMTCMD2_MB1_MASK            2U
    #define CMTCMD2_MB2_MASK            4U
    #define CMTCMD2_MB3_MASK            8U
    #define CMTCMD2_MB4_MASK            16U
    #define CMTCMD2_MB5_MASK            32U
    #define CMTCMD2_MB6_MASK            64U
    #define CMTCMD2_MB7_MASK            128U
    
  } Overlap_STR;

} CMTCMD12STR;
extern volatile CMTCMD12STR _CMTCMD12 @0x00000066;
#define CMTCMD12                        _CMTCMD12.Word


/*** CMTCMD34 - CMT Modulator Data Register 34; 0x00000068 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** CMTCMD3 - CMT Modulator Data Register 3; 0x00000068 ***/
    union {
      byte Byte;
    } CMTCMD3STR;
    #define CMTCMD3                     _CMTCMD34.Overlap_STR.CMTCMD3STR.Byte
    

    /*** CMTCMD4 - CMT Modulator Data Register 4; 0x00000069 ***/
    union {
      byte Byte;
      struct {
        byte SB0         :1;                                       /* Data Value Bit 0 */
        byte SB1         :1;                                       /* Data Value Bit 1 */
        byte SB2         :1;                                       /* Data Value Bit 2 */
        byte SB3         :1;                                       /* Data Value Bit 3 */
        byte SB4         :1;                                       /* Data Value Bit 4 */
        byte SB5         :1;                                       /* Data Value Bit 5 */
        byte SB6         :1;                                       /* Data Value Bit 6 */
        byte SB7         :1;                                       /* Data Value Bit 7 */
      } Bits;
    } CMTCMD4STR;
    #define CMTCMD4                     _CMTCMD34.Overlap_STR.CMTCMD4STR.Byte
    #define CMTCMD4_SB0                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB0
    #define CMTCMD4_SB1                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB1
    #define CMTCMD4_SB2                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB2
    #define CMTCMD4_SB3                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB3
    #define CMTCMD4_SB4                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB4
    #define CMTCMD4_SB5                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB5
    #define CMTCMD4_SB6                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB6
    #define CMTCMD4_SB7                 _CMTCMD34.Overlap_STR.CMTCMD4STR.Bits.SB7
    
    #define CMTCMD4_SB0_MASK            1U
    #define CMTCMD4_SB1_MASK            2U
    #define CMTCMD4_SB2_MASK            4U
    #define CMTCMD4_SB3_MASK            8U
    #define CMTCMD4_SB4_MASK            16U
    #define CMTCMD4_SB5_MASK            32U
    #define CMTCMD4_SB6_MASK            64U
    #define CMTCMD4_SB7_MASK            128U
    
  } Overlap_STR;

} CMTCMD34STR;
extern volatile CMTCMD34STR _CMTCMD34 @0x00000068;
#define CMTCMD34                        _CMTCMD34.Word


/*** IICA - IIC Address Register; 0x0000006A ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte AD1         :1;                                       /* Slave Address Bit 1 */
    byte AD2         :1;                                       /* Slave Address Bit 2 */
    byte AD3         :1;                                       /* Slave Address Bit 3 */
    byte AD4         :1;                                       /* Slave Address Bit 4 */
    byte AD5         :1;                                       /* Slave Address Bit 5 */
    byte AD6         :1;                                       /* Slave Address Bit 6 */
    byte AD7         :1;                                       /* Slave Address Bit 7 */
  } Bits;
  struct {
    byte         :1;
    byte grpAD_1 :7;
  } MergedBits;
} IICASTR;
extern volatile IICASTR _IICA @0x0000006A;
#define IICA                            _IICA.Byte
#define IICA_AD1                        _IICA.Bits.AD1
#define IICA_AD2                        _IICA.Bits.AD2
#define IICA_AD3                        _IICA.Bits.AD3
#define IICA_AD4                        _IICA.Bits.AD4
#define IICA_AD5                        _IICA.Bits.AD5
#define IICA_AD6                        _IICA.Bits.AD6
#define IICA_AD7                        _IICA.Bits.AD7
#define IICA_AD_1                       _IICA.MergedBits.grpAD_1
#define IICA_AD                         IICA_AD_1

#define IICA_AD1_MASK                   2U
#define IICA_AD2_MASK                   4U
#define IICA_AD3_MASK                   8U
#define IICA_AD4_MASK                   16U
#define IICA_AD5_MASK                   32U
#define IICA_AD6_MASK                   64U
#define IICA_AD7_MASK                   128U
#define IICA_AD_1_MASK                  254U
#define IICA_AD_1_BITNUM                1U


/*** IICF - IIC Frequency Divider Register; 0x0000006B ***/
typedef union {
  byte Byte;
  struct {
    byte ICR0        :1;                                       /* IIC Clock Rate Bit 0 */
    byte ICR1        :1;                                       /* IIC Clock Rate Bit 1 */
    byte ICR2        :1;                                       /* IIC Clock Rate Bit 2 */
    byte ICR3        :1;                                       /* IIC Clock Rate Bit 3 */
    byte ICR4        :1;                                       /* IIC Clock Rate Bit 4 */
    byte ICR5        :1;                                       /* IIC Clock Rate Bit 5 */
    byte MULT0       :1;                                       /* Multiplier Factor Bit 0 */
    byte MULT1       :1;                                       /* Multiplier Factor Bit 1 */
  } Bits;
  struct {
    byte grpICR  :6;
    byte grpMULT :2;
  } MergedBits;
} IICFSTR;
extern volatile IICFSTR _IICF @0x0000006B;
#define IICF                            _IICF.Byte
#define IICF_ICR0                       _IICF.Bits.ICR0
#define IICF_ICR1                       _IICF.Bits.ICR1
#define IICF_ICR2                       _IICF.Bits.ICR2
#define IICF_ICR3                       _IICF.Bits.ICR3
#define IICF_ICR4                       _IICF.Bits.ICR4
#define IICF_ICR5                       _IICF.Bits.ICR5
#define IICF_MULT0                      _IICF.Bits.MULT0
#define IICF_MULT1                      _IICF.Bits.MULT1
#define IICF_ICR                        _IICF.MergedBits.grpICR
#define IICF_MULT                       _IICF.MergedBits.grpMULT

#define IICF_ICR0_MASK                  1U
#define IICF_ICR1_MASK                  2U
#define IICF_ICR2_MASK                  4U
#define IICF_ICR3_MASK                  8U
#define IICF_ICR4_MASK                  16U
#define IICF_ICR5_MASK                  32U
#define IICF_MULT0_MASK                 64U
#define IICF_MULT1_MASK                 128U
#define IICF_ICR_MASK                   63U
#define IICF_ICR_BITNUM                 0U
#define IICF_MULT_MASK                  192U
#define IICF_MULT_BITNUM                6U


/*** IICC1 - IIC Control Register 1; 0x0000006C ***/
typedef union {
  byte Byte;
  union { /* Several registers at the same address */
    /*** IICC1 - IIC Control Register 1; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICC1STR;
    #define IICC1                       _IICC1.Byte
    #define IICC1_RSTA                  _IICC1.SameAddr_STR.IICC1STR.Bits.RSTA
    #define IICC1_TXAK                  _IICC1.SameAddr_STR.IICC1STR.Bits.TXAK
    #define IICC1_TX                    _IICC1.SameAddr_STR.IICC1STR.Bits.TX
    #define IICC1_MST                   _IICC1.SameAddr_STR.IICC1STR.Bits.MST
    #define IICC1_IICIE                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICIE
    #define IICC1_IICEN                 _IICC1.SameAddr_STR.IICC1STR.Bits.IICEN
    
    #define IICC1_RSTA_MASK             4U
    #define IICC1_TXAK_MASK             8U
    #define IICC1_TX_MASK               16U
    #define IICC1_MST_MASK              32U
    #define IICC1_IICIE_MASK            64U
    #define IICC1_IICEN_MASK            128U
    
    /*** IICC - IIC Control Register; Several registers at the same address ***/
    union {
      struct {
        byte             :1; 
        byte             :1; 
        byte RSTA        :1;                                       /* Repeat START */
        byte TXAK        :1;                                       /* Transmit Acknowledge Enable */
        byte TX          :1;                                       /* Transmit Mode Select */
        byte MST         :1;                                       /* Master Mode Select */
        byte IICIE       :1;                                       /* IIC Interrupt Enable */
        byte IICEN       :1;                                       /* IIC Enable */
      } Bits;
    } IICCSTR;
    #define IICC                        _IICC1.Byte
    #define IICC_RSTA                   _IICC1.SameAddr_STR.IICCSTR.Bits.RSTA
    #define IICC_TXAK                   _IICC1.SameAddr_STR.IICCSTR.Bits.TXAK
    #define IICC_TX                     _IICC1.SameAddr_STR.IICCSTR.Bits.TX
    #define IICC_MST                    _IICC1.SameAddr_STR.IICCSTR.Bits.MST
    #define IICC_IICIE                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICIE
    #define IICC_IICEN                  _IICC1.SameAddr_STR.IICCSTR.Bits.IICEN
    
    #define IICC_RSTA_MASK              4U
    #define IICC_TXAK_MASK              8U
    #define IICC_TX_MASK                16U
    #define IICC_MST_MASK               32U
    #define IICC_IICIE_MASK             64U
    #define IICC_IICEN_MASK             128U
    
  } SameAddr_STR; /*Several registers at the same address */

} IICC1STR;
extern volatile IICC1STR _IICC1 @0x0000006C;


/*** IICS - IIC Status Register; 0x0000006D ***/
typedef union {
  byte Byte;
  struct {
    byte RXAK        :1;                                       /* Receive Acknowledge */
    byte IICIF       :1;                                       /* IIC Interrupt Flag */
    byte SRW         :1;                                       /* Slave Read/Write */
    byte             :1; 
    byte ARBL        :1;                                       /* Arbitration Lost */
    byte BUSY        :1;                                       /* Bus Busy */
    byte IAAS        :1;                                       /* Addressed as a Slave */
    byte TCF         :1;                                       /* Transfer Complete Flag */
  } Bits;
} IICSSTR;
extern volatile IICSSTR _IICS @0x0000006D;
#define IICS                            _IICS.Byte
#define IICS_RXAK                       _IICS.Bits.RXAK
#define IICS_IICIF                      _IICS.Bits.IICIF
#define IICS_SRW                        _IICS.Bits.SRW
#define IICS_ARBL                       _IICS.Bits.ARBL
#define IICS_BUSY                       _IICS.Bits.BUSY
#define IICS_IAAS                       _IICS.Bits.IAAS
#define IICS_TCF                        _IICS.Bits.TCF

#define IICS_RXAK_MASK                  1U
#define IICS_IICIF_MASK                 2U
#define IICS_SRW_MASK                   4U
#define IICS_ARBL_MASK                  16U
#define IICS_BUSY_MASK                  32U
#define IICS_IAAS_MASK                  64U
#define IICS_TCF_MASK                   128U


/*** IICD - IIC Data I/O Register; 0x0000006E ***/
typedef union {
  byte Byte;
  struct {
    byte DATA0       :1;                                       /* IIC Data Bit 0 */
    byte DATA1       :1;                                       /* IIC Data Bit 1 */
    byte DATA2       :1;                                       /* IIC Data Bit 2 */
    byte DATA3       :1;                                       /* IIC Data Bit 3 */
    byte DATA4       :1;                                       /* IIC Data Bit 4 */
    byte DATA5       :1;                                       /* IIC Data Bit 5 */
    byte DATA6       :1;                                       /* IIC Data Bit 6 */
    byte DATA7       :1;                                       /* IIC Data Bit 7 */
  } Bits;
} IICDSTR;
extern volatile IICDSTR _IICD @0x0000006E;
#define IICD                            _IICD.Byte
#define IICD_DATA0                      _IICD.Bits.DATA0
#define IICD_DATA1                      _IICD.Bits.DATA1
#define IICD_DATA2                      _IICD.Bits.DATA2
#define IICD_DATA3                      _IICD.Bits.DATA3
#define IICD_DATA4                      _IICD.Bits.DATA4
#define IICD_DATA5                      _IICD.Bits.DATA5
#define IICD_DATA6                      _IICD.Bits.DATA6
#define IICD_DATA7                      _IICD.Bits.DATA7

#define IICD_DATA0_MASK                 1U
#define IICD_DATA1_MASK                 2U
#define IICD_DATA2_MASK                 4U
#define IICD_DATA3_MASK                 8U
#define IICD_DATA4_MASK                 16U
#define IICD_DATA5_MASK                 32U
#define IICD_DATA6_MASK                 64U
#define IICD_DATA7_MASK                 128U


/*** IICC2 - IIC Control Register 2; 0x0000006F ***/
typedef union {
  byte Byte;
  struct {
    byte AD8         :1;                                       /* Slave Address Bit 8 */
    byte AD9         :1;                                       /* Slave Address Bit 9 */
    byte AD10        :1;                                       /* Slave Address Bit 10 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte ADEXT       :1;                                       /* Address Extension */
    byte GCAEN       :1;                                       /* General Call Address Enable */
  } Bits;
  struct {
    byte grpAD_8 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} IICC2STR;
extern volatile IICC2STR _IICC2 @0x0000006F;
#define IICC2                           _IICC2.Byte
#define IICC2_AD8                       _IICC2.Bits.AD8
#define IICC2_AD9                       _IICC2.Bits.AD9
#define IICC2_AD10                      _IICC2.Bits.AD10
#define IICC2_ADEXT                     _IICC2.Bits.ADEXT
#define IICC2_GCAEN                     _IICC2.Bits.GCAEN
#define IICC2_AD_8                      _IICC2.MergedBits.grpAD_8
#define IICC2_AD                        IICC2_AD_8

#define IICC2_AD8_MASK                  1U
#define IICC2_AD9_MASK                  2U
#define IICC2_AD10_MASK                 4U
#define IICC2_ADEXT_MASK                64U
#define IICC2_GCAEN_MASK                128U
#define IICC2_AD_8_MASK                 7U
#define IICC2_AD_8_BITNUM               0U


/*** SPIC1 - SPI Control Register 1; 0x00000070 ***/
typedef union {
  byte Byte;
  struct {
    byte LSBFE       :1;                                       /* LSB First (Shifter Direction) */
    byte SSOE        :1;                                       /* Slave Select Output Enable */
    byte CPHA        :1;                                       /* Clock Phase */
    byte CPOL        :1;                                       /* Clock Polarity */
    byte MSTR        :1;                                       /* Master/Slave Mode Select */
    byte SPTIE       :1;                                       /* SPI Transmit Interrupt Enable */
    byte SPE         :1;                                       /* SPI System Enable */
    byte SPIE        :1;                                       /* SPI Interrupt Enable (for SPRF and MODF) */
  } Bits;
} SPIC1STR;
extern volatile SPIC1STR _SPIC1 @0x00000070;
#define SPIC1                           _SPIC1.Byte
#define SPIC1_LSBFE                     _SPIC1.Bits.LSBFE
#define SPIC1_SSOE                      _SPIC1.Bits.SSOE
#define SPIC1_CPHA                      _SPIC1.Bits.CPHA
#define SPIC1_CPOL                      _SPIC1.Bits.CPOL
#define SPIC1_MSTR                      _SPIC1.Bits.MSTR
#define SPIC1_SPTIE                     _SPIC1.Bits.SPTIE
#define SPIC1_SPE                       _SPIC1.Bits.SPE
#define SPIC1_SPIE                      _SPIC1.Bits.SPIE

#define SPIC1_LSBFE_MASK                1U
#define SPIC1_SSOE_MASK                 2U
#define SPIC1_CPHA_MASK                 4U
#define SPIC1_CPOL_MASK                 8U
#define SPIC1_MSTR_MASK                 16U
#define SPIC1_SPTIE_MASK                32U
#define SPIC1_SPE_MASK                  64U
#define SPIC1_SPIE_MASK                 128U


/*** SPIC2 - SPI Control Register 2; 0x00000071 ***/
typedef union {
  byte Byte;
  struct {
    byte SPC0        :1;                                       /* SPI Pin Control 0 */
    byte SPISWAI     :1;                                       /* SPI Stop in Wait Mode */
    byte             :1; 
    byte BIDIROE     :1;                                       /* Bidirectional Mode Output Enable */
    byte MODFEN      :1;                                       /* Master Mode-Fault Function Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SPIC2STR;
extern volatile SPIC2STR _SPIC2 @0x00000071;
#define SPIC2                           _SPIC2.Byte
#define SPIC2_SPC0                      _SPIC2.Bits.SPC0
#define SPIC2_SPISWAI                   _SPIC2.Bits.SPISWAI
#define SPIC2_BIDIROE                   _SPIC2.Bits.BIDIROE
#define SPIC2_MODFEN                    _SPIC2.Bits.MODFEN

#define SPIC2_SPC0_MASK                 1U
#define SPIC2_SPISWAI_MASK              2U
#define SPIC2_BIDIROE_MASK              8U
#define SPIC2_MODFEN_MASK               16U


/*** SPIBR - SPI Baud Rate Register; 0x00000072 ***/
typedef union {
  byte Byte;
  struct {
    byte SPR0        :1;                                       /* SPI Baud Rate Divisor Bit 0 */
    byte SPR1        :1;                                       /* SPI Baud Rate Divisor Bit 1 */
    byte SPR2        :1;                                       /* SPI Baud Rate Divisor Bit 2 */
    byte             :1; 
    byte SPPR0       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 0 */
    byte SPPR1       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 1 */
    byte SPPR2       :1;                                       /* SPI Baud Rate Prescale Divisor Bit 2 */
    byte             :1; 
  } Bits;
  struct {
    byte grpSPR  :3;
    byte         :1;
    byte grpSPPR :3;
    byte         :1;
  } MergedBits;
} SPIBRSTR;
extern volatile SPIBRSTR _SPIBR @0x00000072;
#define SPIBR                           _SPIBR.Byte
#define SPIBR_SPR0                      _SPIBR.Bits.SPR0
#define SPIBR_SPR1                      _SPIBR.Bits.SPR1
#define SPIBR_SPR2                      _SPIBR.Bits.SPR2
#define SPIBR_SPPR0                     _SPIBR.Bits.SPPR0
#define SPIBR_SPPR1                     _SPIBR.Bits.SPPR1
#define SPIBR_SPPR2                     _SPIBR.Bits.SPPR2
#define SPIBR_SPR                       _SPIBR.MergedBits.grpSPR
#define SPIBR_SPPR                      _SPIBR.MergedBits.grpSPPR

#define SPIBR_SPR0_MASK                 1U
#define SPIBR_SPR1_MASK                 2U
#define SPIBR_SPR2_MASK                 4U
#define SPIBR_SPPR0_MASK                16U
#define SPIBR_SPPR1_MASK                32U
#define SPIBR_SPPR2_MASK                64U
#define SPIBR_SPR_MASK                  7U
#define SPIBR_SPR_BITNUM                0U
#define SPIBR_SPPR_MASK                 112U
#define SPIBR_SPPR_BITNUM               4U


/*** SPIS - SPI Status Register; 0x00000073 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte MODF        :1;                                       /* Master Mode Fault Flag */
    byte SPTEF       :1;                                       /* SPI Transmit Buffer Empty Flag */
    byte             :1; 
    byte SPRF        :1;                                       /* SPI Read Buffer Full Flag */
  } Bits;
} SPISSTR;
extern volatile SPISSTR _SPIS @0x00000073;
#define SPIS                            _SPIS.Byte
#define SPIS_MODF                       _SPIS.Bits.MODF
#define SPIS_SPTEF                      _SPIS.Bits.SPTEF
#define SPIS_SPRF                       _SPIS.Bits.SPRF

#define SPIS_MODF_MASK                  16U
#define SPIS_SPTEF_MASK                 32U
#define SPIS_SPRF_MASK                  128U


/*** SPID - SPI Data Register; 0x00000075 ***/
typedef union {
  byte Byte;
} SPIDSTR;
extern volatile SPIDSTR _SPID @0x00000075;
#define SPID                            _SPID.Byte


/*** IRQSC - Interrupt request status and control register; 0x00000076 ***/
typedef union {
  byte Byte;
  struct {
    byte IRQMOD      :1;                                       /* IRQ Detection Mode */
    byte IRQIE       :1;                                       /* IRQ Interrupt Enable */
    byte IRQACK      :1;                                       /* IRQ Acknowledge */
    byte IRQF        :1;                                       /* IRQ Flag */
    byte IRQPE       :1;                                       /* IRQ Pin Enable */
    byte IRQEDG      :1;                                       /* IRQ Edge Select */
    byte IRQPDD      :1;                                       /* IRQ Pull Device Disable */
    byte             :1; 
  } Bits;
} IRQSCSTR;
extern volatile IRQSCSTR _IRQSC @0x00000076;
#define IRQSC                           _IRQSC.Byte
#define IRQSC_IRQMOD                    _IRQSC.Bits.IRQMOD
#define IRQSC_IRQIE                     _IRQSC.Bits.IRQIE
#define IRQSC_IRQACK                    _IRQSC.Bits.IRQACK
#define IRQSC_IRQF                      _IRQSC.Bits.IRQF
#define IRQSC_IRQPE                     _IRQSC.Bits.IRQPE
#define IRQSC_IRQEDG                    _IRQSC.Bits.IRQEDG
#define IRQSC_IRQPDD                    _IRQSC.Bits.IRQPDD

#define IRQSC_IRQMOD_MASK               1U
#define IRQSC_IRQIE_MASK                2U
#define IRQSC_IRQACK_MASK               4U
#define IRQSC_IRQF_MASK                 8U
#define IRQSC_IRQPE_MASK                16U
#define IRQSC_IRQEDG_MASK               32U
#define IRQSC_IRQPDD_MASK               64U


/*** PPAGE - Program Page Register; 0x00000078 ***/
typedef union {
  byte Byte;
  struct {
    byte XA14        :1;                                       /* Extended address, bit 14 */
    byte XA15        :1;                                       /* Extended address, bit 15 */
    byte XA16        :1;                                       /* Extended address, bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpXA_14 :3;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} PPAGESTR;
extern volatile PPAGESTR _PPAGE @0x00000078;
#define PPAGE                           _PPAGE.Byte
#define PPAGE_XA14                      _PPAGE.Bits.XA14
#define PPAGE_XA15                      _PPAGE.Bits.XA15
#define PPAGE_XA16                      _PPAGE.Bits.XA16
#define PPAGE_XA_14                     _PPAGE.MergedBits.grpXA_14
#define PPAGE_XA                        PPAGE_XA_14

#define PPAGE_XA14_MASK                 1U
#define PPAGE_XA15_MASK                 2U
#define PPAGE_XA16_MASK                 4U
#define PPAGE_XA_14_MASK                7U
#define PPAGE_XA_14_BITNUM              0U


/*** LAP2 - Linear Address Pointer Register 2; 0x00000079 ***/
typedef union {
  byte Byte;
  struct {
    byte LA16        :1;                                       /* Linear address pointer, bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} LAP2STR;
extern volatile LAP2STR _LAP2 @0x00000079;
#define LAP2                            _LAP2.Byte
#define LAP2_LA16                       _LAP2.Bits.LA16

#define LAP2_LA16_MASK                  1U


/*** LAP1 - Linear Address Pointer Register 1; 0x0000007A ***/
typedef union {
  byte Byte;
  struct {
    byte LA8         :1;                                       /* Linear address pointer, bit 8 */
    byte LA9         :1;                                       /* Linear address pointer, bit 9 */
    byte LA10        :1;                                       /* Linear address pointer, bit 10 */
    byte LA11        :1;                                       /* Linear address pointer, bit 11 */
    byte LA12        :1;                                       /* Linear address pointer, bit 12 */
    byte LA13        :1;                                       /* Linear address pointer, bit 13 */
    byte LA14        :1;                                       /* Linear address pointer, bit 14 */
    byte LA15        :1;                                       /* Linear address pointer, bit 15 */
  } Bits;
} LAP1STR;
extern volatile LAP1STR _LAP1 @0x0000007A;
#define LAP1                            _LAP1.Byte
#define LAP1_LA8                        _LAP1.Bits.LA8
#define LAP1_LA9                        _LAP1.Bits.LA9
#define LAP1_LA10                       _LAP1.Bits.LA10
#define LAP1_LA11                       _LAP1.Bits.LA11
#define LAP1_LA12                       _LAP1.Bits.LA12
#define LAP1_LA13                       _LAP1.Bits.LA13
#define LAP1_LA14                       _LAP1.Bits.LA14
#define LAP1_LA15                       _LAP1.Bits.LA15

#define LAP1_LA8_MASK                   1U
#define LAP1_LA9_MASK                   2U
#define LAP1_LA10_MASK                  4U
#define LAP1_LA11_MASK                  8U
#define LAP1_LA12_MASK                  16U
#define LAP1_LA13_MASK                  32U
#define LAP1_LA14_MASK                  64U
#define LAP1_LA15_MASK                  128U


/*** LAP0 - Linear Address Pointer Register 0; 0x0000007B ***/
typedef union {
  byte Byte;
  struct {
    byte LA0         :1;                                       /* Linear address pointer, bit 0 */
    byte LA1         :1;                                       /* Linear address pointer, bit 1 */
    byte LA2         :1;                                       /* Linear address pointer, bit 2 */
    byte LA3         :1;                                       /* Linear address pointer, bit 3 */
    byte LA4         :1;                                       /* Linear address pointer, bit 4 */
    byte LA5         :1;                                       /* Linear address pointer, bit 5 */
    byte LA6         :1;                                       /* Linear address pointer, bit 6 */
    byte LA7         :1;                                       /* Linear address pointer, bit 7 */
  } Bits;
} LAP0STR;
extern volatile LAP0STR _LAP0 @0x0000007B;
#define LAP0                            _LAP0.Byte
#define LAP0_LA0                        _LAP0.Bits.LA0
#define LAP0_LA1                        _LAP0.Bits.LA1
#define LAP0_LA2                        _LAP0.Bits.LA2
#define LAP0_LA3                        _LAP0.Bits.LA3
#define LAP0_LA4                        _LAP0.Bits.LA4
#define LAP0_LA5                        _LAP0.Bits.LA5
#define LAP0_LA6                        _LAP0.Bits.LA6
#define LAP0_LA7                        _LAP0.Bits.LA7

#define LAP0_LA0_MASK                   1U
#define LAP0_LA1_MASK                   2U
#define LAP0_LA2_MASK                   4U
#define LAP0_LA3_MASK                   8U
#define LAP0_LA4_MASK                   16U
#define LAP0_LA5_MASK                   32U
#define LAP0_LA6_MASK                   64U
#define LAP0_LA7_MASK                   128U


/*** LWP - Linear Word Post Increment Register; 0x0000007C ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LWPSTR;
extern volatile LWPSTR _LWP @0x0000007C;
#define LWP                             _LWP.Byte
#define LWP_D0                          _LWP.Bits.D0
#define LWP_D1                          _LWP.Bits.D1
#define LWP_D2                          _LWP.Bits.D2
#define LWP_D3                          _LWP.Bits.D3
#define LWP_D4                          _LWP.Bits.D4
#define LWP_D5                          _LWP.Bits.D5
#define LWP_D6                          _LWP.Bits.D6
#define LWP_D7                          _LWP.Bits.D7

#define LWP_D0_MASK                     1U
#define LWP_D1_MASK                     2U
#define LWP_D2_MASK                     4U
#define LWP_D3_MASK                     8U
#define LWP_D4_MASK                     16U
#define LWP_D5_MASK                     32U
#define LWP_D6_MASK                     64U
#define LWP_D7_MASK                     128U


/*** LBP - Linear Byte Post Increment Register; 0x0000007D ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LBPSTR;
extern volatile LBPSTR _LBP @0x0000007D;
#define LBP                             _LBP.Byte
#define LBP_D0                          _LBP.Bits.D0
#define LBP_D1                          _LBP.Bits.D1
#define LBP_D2                          _LBP.Bits.D2
#define LBP_D3                          _LBP.Bits.D3
#define LBP_D4                          _LBP.Bits.D4
#define LBP_D5                          _LBP.Bits.D5
#define LBP_D6                          _LBP.Bits.D6
#define LBP_D7                          _LBP.Bits.D7

#define LBP_D0_MASK                     1U
#define LBP_D1_MASK                     2U
#define LBP_D2_MASK                     4U
#define LBP_D3_MASK                     8U
#define LBP_D4_MASK                     16U
#define LBP_D5_MASK                     32U
#define LBP_D6_MASK                     64U
#define LBP_D7_MASK                     128U


/*** LB - Linear Byte Register; 0x0000007E ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LBSTR;
extern volatile LBSTR _LB @0x0000007E;
#define LB                              _LB.Byte
#define LB_D0                           _LB.Bits.D0
#define LB_D1                           _LB.Bits.D1
#define LB_D2                           _LB.Bits.D2
#define LB_D3                           _LB.Bits.D3
#define LB_D4                           _LB.Bits.D4
#define LB_D5                           _LB.Bits.D5
#define LB_D6                           _LB.Bits.D6
#define LB_D7                           _LB.Bits.D7

#define LB_D0_MASK                      1U
#define LB_D1_MASK                      2U
#define LB_D2_MASK                      4U
#define LB_D3_MASK                      8U
#define LB_D4_MASK                      16U
#define LB_D5_MASK                      32U
#define LB_D6_MASK                      64U
#define LB_D7_MASK                      128U


/*** LAPAB - Linear Address Pointer Add Byte Register; 0x0000007F ***/
typedef union {
  byte Byte;
  struct {
    byte D0          :1;                                       /* Data value bit 0 */
    byte D1          :1;                                       /* Data value bit 1 */
    byte D2          :1;                                       /* Data value bit 2 */
    byte D3          :1;                                       /* Data value bit 3 */
    byte D4          :1;                                       /* Data value bit 4 */
    byte D5          :1;                                       /* Data value bit 5 */
    byte D6          :1;                                       /* Data value bit 6 */
    byte D7          :1;                                       /* Data value bit 7 */
  } Bits;
} LAPABSTR;
extern volatile LAPABSTR _LAPAB @0x0000007F;
#define LAPAB                           _LAPAB.Byte
#define LAPAB_D0                        _LAPAB.Bits.D0
#define LAPAB_D1                        _LAPAB.Bits.D1
#define LAPAB_D2                        _LAPAB.Bits.D2
#define LAPAB_D3                        _LAPAB.Bits.D3
#define LAPAB_D4                        _LAPAB.Bits.D4
#define LAPAB_D5                        _LAPAB.Bits.D5
#define LAPAB_D6                        _LAPAB.Bits.D6
#define LAPAB_D7                        _LAPAB.Bits.D7

#define LAPAB_D0_MASK                   1U
#define LAPAB_D1_MASK                   2U
#define LAPAB_D2_MASK                   4U
#define LAPAB_D3_MASK                   8U
#define LAPAB_D4_MASK                   16U
#define LAPAB_D5_MASK                   32U
#define LAPAB_D6_MASK                   64U
#define LAPAB_D7_MASK                   128U


/*** SRS - System Reset Status Register; 0x00001800 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte LVD         :1;                                       /* Low Voltage Detect */
    byte             :1; 
    byte ILAD        :1;                                       /* Illegal Address */
    byte ILOP        :1;                                       /* Illegal Opcode */
    byte COP         :1;                                       /* Computer Operating Properly (COP) Watchdog */
    byte PIN         :1;                                       /* External Reset Pin */
    byte POR         :1;                                       /* Power-On Reset */
  } Bits;
} SRSSTR;
extern volatile SRSSTR _SRS @0x00001800;
#define SRS                             _SRS.Byte
#define SRS_LVD                         _SRS.Bits.LVD
#define SRS_ILAD                        _SRS.Bits.ILAD
#define SRS_ILOP                        _SRS.Bits.ILOP
#define SRS_COP                         _SRS.Bits.COP
#define SRS_PIN                         _SRS.Bits.PIN
#define SRS_POR                         _SRS.Bits.POR

#define SRS_LVD_MASK                    2U
#define SRS_ILAD_MASK                   8U
#define SRS_ILOP_MASK                   16U
#define SRS_COP_MASK                    32U
#define SRS_PIN_MASK                    64U
#define SRS_POR_MASK                    128U


/*** SBDFR - System Background Debug Force Reset Register; 0x00001801 ***/
typedef union {
  byte Byte;
  struct {
    byte BDFR        :1;                                       /* Background Debug Force Reset */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} SBDFRSTR;
extern volatile SBDFRSTR _SBDFR @0x00001801;
#define SBDFR                           _SBDFR.Byte
#define SBDFR_BDFR                      _SBDFR.Bits.BDFR

#define SBDFR_BDFR_MASK                 1U


/*** SOPT1 - System Options Register 1; 0x00001802 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte BKGDPE      :1;                                       /* Background Debug Mode Pin Enable */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte STOPE       :1;                                       /* Stop Mode Enable */
    byte COPT        :1;                                       /* COP Watchdog Timeout */
    byte COPE        :1;                                       /* COP Watchdog Enable */
  } Bits;
} SOPT1STR;
extern volatile SOPT1STR _SOPT1 @0x00001802;
#define SOPT1                           _SOPT1.Byte
#define SOPT1_BKGDPE                    _SOPT1.Bits.BKGDPE
#define SOPT1_STOPE                     _SOPT1.Bits.STOPE
#define SOPT1_COPT                      _SOPT1.Bits.COPT
#define SOPT1_COPE                      _SOPT1.Bits.COPE

#define SOPT1_BKGDPE_MASK               2U
#define SOPT1_STOPE_MASK                32U
#define SOPT1_COPT_MASK                 64U
#define SOPT1_COPE_MASK                 128U


/*** SOPT2 - System Options Register 2; 0x00001803 ***/
typedef union {
  byte Byte;
  struct {
    byte PID         :1;                                       /* Phantom ID */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte COPCLKS     :1;                                       /* COP Watchdog Clock Select */
  } Bits;
} SOPT2STR;
extern volatile SOPT2STR _SOPT2 @0x00001803;
#define SOPT2                           _SOPT2.Byte
#define SOPT2_PID                       _SOPT2.Bits.PID
#define SOPT2_COPCLKS                   _SOPT2.Bits.COPCLKS

#define SOPT2_PID_MASK                  1U
#define SOPT2_COPCLKS_MASK              128U


/*** SCIC4 - SCI Control Register 4; 0x00001804 ***/
typedef union {
  byte Byte;
  struct {
    byte BRFA0       :1;                                       /* Baud rate fine adjust, bit 0 */
    byte BRFA1       :1;                                       /* Baud rate fine adjust, bit 1 */
    byte BRFA2       :1;                                       /* Baud rate fine adjust, bit 2 */
    byte BRFA3       :1;                                       /* Baud rate fine adjust, bit 3 */
    byte BRFA4       :1;                                       /* Baud rate fine adjust, bit 4 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpBRFA :5;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} SCIC4STR;
extern volatile SCIC4STR _SCIC4 @0x00001804;
#define SCIC4                           _SCIC4.Byte
#define SCIC4_BRFA0                     _SCIC4.Bits.BRFA0
#define SCIC4_BRFA1                     _SCIC4.Bits.BRFA1
#define SCIC4_BRFA2                     _SCIC4.Bits.BRFA2
#define SCIC4_BRFA3                     _SCIC4.Bits.BRFA3
#define SCIC4_BRFA4                     _SCIC4.Bits.BRFA4
#define SCIC4_BRFA                      _SCIC4.MergedBits.grpBRFA

#define SCIC4_BRFA0_MASK                1U
#define SCIC4_BRFA1_MASK                2U
#define SCIC4_BRFA2_MASK                4U
#define SCIC4_BRFA3_MASK                8U
#define SCIC4_BRFA4_MASK                16U
#define SCIC4_BRFA_MASK                 31U
#define SCIC4_BRFA_BITNUM               0U


/*** SDID - System Device Identification Register; 0x00001806 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** SDIDH - System Device Identification Register High; 0x00001806 ***/
    union {
      byte Byte;
      struct {
        byte ID8         :1;                                       /* Part Identification Number, bit 8 */
        byte ID9         :1;                                       /* Part Identification Number, bit 9 */
        byte ID10        :1;                                       /* Part Identification Number, bit 10 */
        byte ID11        :1;                                       /* Part Identification Number, bit 11 */
        byte             :1; 
        byte             :1; 
        byte             :1; 
        byte             :1; 
      } Bits;
      struct {
        byte grpID_8 :4;
        byte     :1;
        byte     :1;
        byte     :1;
        byte     :1;
      } MergedBits;
    } SDIDHSTR;
    #define SDIDH                       _SDID.Overlap_STR.SDIDHSTR.Byte
    #define SDIDH_ID8                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID8
    #define SDIDH_ID9                   _SDID.Overlap_STR.SDIDHSTR.Bits.ID9
    #define SDIDH_ID10                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID10
    #define SDIDH_ID11                  _SDID.Overlap_STR.SDIDHSTR.Bits.ID11
    #define SDIDH_ID_8                  _SDID.Overlap_STR.SDIDHSTR.MergedBits.grpID_8
    #define SDIDH_ID                    SDIDH_ID_8
    
    #define SDIDH_ID8_MASK              1U
    #define SDIDH_ID9_MASK              2U
    #define SDIDH_ID10_MASK             4U
    #define SDIDH_ID11_MASK             8U
    #define SDIDH_ID_8_MASK             15U
    #define SDIDH_ID_8_BITNUM           0U
    

    /*** SDIDL - System Device Identification Register Low; 0x00001807 ***/
    union {
      byte Byte;
      struct {
        byte ID0         :1;                                       /* Part Identification Number, bit 0 */
        byte ID1         :1;                                       /* Part Identification Number, bit 1 */
        byte ID2         :1;                                       /* Part Identification Number, bit 2 */
        byte ID3         :1;                                       /* Part Identification Number, bit 3 */
        byte ID4         :1;                                       /* Part Identification Number, bit 4 */
        byte ID5         :1;                                       /* Part Identification Number, bit 5 */
        byte ID6         :1;                                       /* Part Identification Number, bit 6 */
        byte ID7         :1;                                       /* Part Identification Number, bit 7 */
      } Bits;
    } SDIDLSTR;
    #define SDIDL                       _SDID.Overlap_STR.SDIDLSTR.Byte
    #define SDIDL_ID0                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID0
    #define SDIDL_ID1                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID1
    #define SDIDL_ID2                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID2
    #define SDIDL_ID3                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID3
    #define SDIDL_ID4                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID4
    #define SDIDL_ID5                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID5
    #define SDIDL_ID6                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID6
    #define SDIDL_ID7                   _SDID.Overlap_STR.SDIDLSTR.Bits.ID7
    
    #define SDIDL_ID0_MASK              1U
    #define SDIDL_ID1_MASK              2U
    #define SDIDL_ID2_MASK              4U
    #define SDIDL_ID3_MASK              8U
    #define SDIDL_ID4_MASK              16U
    #define SDIDL_ID5_MASK              32U
    #define SDIDL_ID6_MASK              64U
    #define SDIDL_ID7_MASK              128U
    
  } Overlap_STR;

} SDIDSTR;
extern volatile SDIDSTR _SDID @0x00001806;
#define SDID                            _SDID.Word


/*** SPMSC1 - System Power Management Status and Control 1 Register; 0x00001808 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte LVDE        :1;                                       /* Low-Voltage Detect Enable */
    byte LVDSE       :1;                                       /* Low-Voltage Detect Stop Enable */
    byte LVDRE       :1;                                       /* Low-Voltage Detect Reset Enable */
    byte LVDIE       :1;                                       /* Low-Voltage Detect Interrupt Enable */
    byte LVDACK      :1;                                       /* Low-Voltage Detect Acknowledge */
    byte LVDF        :1;                                       /* Low-Voltage Detect Flag */
  } Bits;
} SPMSC1STR;
extern volatile SPMSC1STR _SPMSC1 @0x00001808;
#define SPMSC1                          _SPMSC1.Byte
#define SPMSC1_LVDE                     _SPMSC1.Bits.LVDE
#define SPMSC1_LVDSE                    _SPMSC1.Bits.LVDSE
#define SPMSC1_LVDRE                    _SPMSC1.Bits.LVDRE
#define SPMSC1_LVDIE                    _SPMSC1.Bits.LVDIE
#define SPMSC1_LVDACK                   _SPMSC1.Bits.LVDACK
#define SPMSC1_LVDF                     _SPMSC1.Bits.LVDF

#define SPMSC1_LVDE_MASK                4U
#define SPMSC1_LVDSE_MASK               8U
#define SPMSC1_LVDRE_MASK               16U
#define SPMSC1_LVDIE_MASK               32U
#define SPMSC1_LVDACK_MASK              64U
#define SPMSC1_LVDF_MASK                128U


/*** SPMSC2 - System Power Management Status and Control 2 Register; 0x00001809 ***/
typedef union {
  byte Byte;
  struct {
    byte PPDC        :1;                                       /* Partial Power Down Control */
    byte PPDE        :1;                                       /* Partial Power Down Enable */
    byte PPDACK      :1;                                       /* Partial Power Down Acknowledge */
    byte PPDF        :1;                                       /* Partial Power Down Flag */
    byte             :1; 
    byte LPWUI       :1;                                       /* Low Power Wake Up on Interrupt */
    byte LPRS        :1;                                       /* Low Power Regulator Status */
    byte LPR         :1;                                       /* Low Power Regulator Control */
  } Bits;
} SPMSC2STR;
extern volatile SPMSC2STR _SPMSC2 @0x00001809;
#define SPMSC2                          _SPMSC2.Byte
#define SPMSC2_PPDC                     _SPMSC2.Bits.PPDC
#define SPMSC2_PPDE                     _SPMSC2.Bits.PPDE
#define SPMSC2_PPDACK                   _SPMSC2.Bits.PPDACK
#define SPMSC2_PPDF                     _SPMSC2.Bits.PPDF
#define SPMSC2_LPWUI                    _SPMSC2.Bits.LPWUI
#define SPMSC2_LPRS                     _SPMSC2.Bits.LPRS
#define SPMSC2_LPR                      _SPMSC2.Bits.LPR

#define SPMSC2_PPDC_MASK                1U
#define SPMSC2_PPDE_MASK                2U
#define SPMSC2_PPDACK_MASK              4U
#define SPMSC2_PPDF_MASK                8U
#define SPMSC2_LPWUI_MASK               32U
#define SPMSC2_LPRS_MASK                64U
#define SPMSC2_LPR_MASK                 128U


/*** SPMSC3 - System Power Management Status and Control 3 Register; 0x0000180B ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte LVWIE       :1;                                       /* Low-Voltage Warning Interrupt Enable */
    byte LVWV        :1;                                       /* Low-Voltage Warning Voltage Select */
    byte LVDV        :1;                                       /* Low-Voltage Detect Voltage Select */
    byte LVWACK      :1;                                       /* Low-Voltage Warning Acknowledge */
    byte LVWF        :1;                                       /* Low-Voltage Warning Flag */
  } Bits;
} SPMSC3STR;
extern volatile SPMSC3STR _SPMSC3 @0x0000180B;
#define SPMSC3                          _SPMSC3.Byte
#define SPMSC3_LVWIE                    _SPMSC3.Bits.LVWIE
#define SPMSC3_LVWV                     _SPMSC3.Bits.LVWV
#define SPMSC3_LVDV                     _SPMSC3.Bits.LVDV
#define SPMSC3_LVWACK                   _SPMSC3.Bits.LVWACK
#define SPMSC3_LVWF                     _SPMSC3.Bits.LVWF

#define SPMSC3_LVWIE_MASK               8U
#define SPMSC3_LVWV_MASK                16U
#define SPMSC3_LVDV_MASK                32U
#define SPMSC3_LVWACK_MASK              64U
#define SPMSC3_LVWF_MASK                128U


/*** SOMC1 - ; 0x0000180C ***/
typedef union {
  byte Byte;
  struct {
    byte XTAL0_TST_OUT :1;                                     /* Crystal 0 Test Out (32kHz) Enable */
    byte XTAL1_TST_OUT :1;                                     /* Crystal 1 Test Out (32MHz) Enable */
    byte XTAL1STEN   :1;                                       /* Crystal 1 Oscillator (32MHz) STOP Mode Enable */
    byte XTAL0STEN   :1;                                       /* Crystal 0 Oscillator (32.768KHz) STOP Mode Enable */
    byte XTAL0EN     :1;                                       /* Crystal 0 Oscillator (32.768KHz) Enable */
    byte RDIV0       :1;                                       /* Reference Divider, bit 0 */
    byte RDIV1       :1;                                       /* Reference Divider, bit 1 */
    byte RDIV2       :1;                                       /* Reference Divider, bit 2 */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpRDIV :3;
  } MergedBits;
} SOMC1STR;
extern volatile SOMC1STR _SOMC1 @0x0000180C;
#define SOMC1                           _SOMC1.Byte
#define SOMC1_XTAL0_TST_OUT             _SOMC1.Bits.XTAL0_TST_OUT
#define SOMC1_XTAL1_TST_OUT             _SOMC1.Bits.XTAL1_TST_OUT
#define SOMC1_XTAL1STEN                 _SOMC1.Bits.XTAL1STEN
#define SOMC1_XTAL0STEN                 _SOMC1.Bits.XTAL0STEN
#define SOMC1_XTAL0EN                   _SOMC1.Bits.XTAL0EN
#define SOMC1_RDIV0                     _SOMC1.Bits.RDIV0
#define SOMC1_RDIV1                     _SOMC1.Bits.RDIV1
#define SOMC1_RDIV2                     _SOMC1.Bits.RDIV2
#define SOMC1_RDIV                      _SOMC1.MergedBits.grpRDIV

#define SOMC1_XTAL0_TST_OUT_MASK        1U
#define SOMC1_XTAL1_TST_OUT_MASK        2U
#define SOMC1_XTAL1STEN_MASK            4U
#define SOMC1_XTAL0STEN_MASK            8U
#define SOMC1_XTAL0EN_MASK              16U
#define SOMC1_RDIV0_MASK                32U
#define SOMC1_RDIV1_MASK                64U
#define SOMC1_RDIV2_MASK                128U
#define SOMC1_RDIV_MASK                 224U
#define SOMC1_RDIV_BITNUM               5U


/*** SOMC2 - ; 0x0000180D ***/
typedef union {
  byte Byte;
  struct {
    byte XTAL1_TRIM0 :1;                                       /* XTAL1_TRIM, bit 0 */
    byte XTAL1_TRIM1 :1;                                       /* XTAL1_TRIM, bit 1 */
    byte XTAL1_TRIM2 :1;                                       /* XTAL1_TRIM, bit 2 */
    byte XTAL1_TRIM3 :1;                                       /* XTAL1_TRIM, bit 3 */
    byte XTAL1_TRIM4 :1;                                       /* XTAL1_TRIM, bit 4 */
    byte XTAL1_TRIM5 :1;                                       /* XTAL1_TRIM, bit 5 */
    byte XTAL1_TRIM6 :1;                                       /* XTAL1_TRIM, bit 6 */
    byte XTAL1_TRIM7 :1;                                       /* XTAL1_TRIM, bit 7 */
  } Bits;
} SOMC2STR;
extern volatile SOMC2STR _SOMC2 @0x0000180D;
#define SOMC2                           _SOMC2.Byte
#define SOMC2_XTAL1_TRIM0               _SOMC2.Bits.XTAL1_TRIM0
#define SOMC2_XTAL1_TRIM1               _SOMC2.Bits.XTAL1_TRIM1
#define SOMC2_XTAL1_TRIM2               _SOMC2.Bits.XTAL1_TRIM2
#define SOMC2_XTAL1_TRIM3               _SOMC2.Bits.XTAL1_TRIM3
#define SOMC2_XTAL1_TRIM4               _SOMC2.Bits.XTAL1_TRIM4
#define SOMC2_XTAL1_TRIM5               _SOMC2.Bits.XTAL1_TRIM5
#define SOMC2_XTAL1_TRIM6               _SOMC2.Bits.XTAL1_TRIM6
#define SOMC2_XTAL1_TRIM7               _SOMC2.Bits.XTAL1_TRIM7

#define SOMC2_XTAL1_TRIM0_MASK          1U
#define SOMC2_XTAL1_TRIM1_MASK          2U
#define SOMC2_XTAL1_TRIM2_MASK          4U
#define SOMC2_XTAL1_TRIM3_MASK          8U
#define SOMC2_XTAL1_TRIM4_MASK          16U
#define SOMC2_XTAL1_TRIM5_MASK          32U
#define SOMC2_XTAL1_TRIM6_MASK          64U
#define SOMC2_XTAL1_TRIM7_MASK          128U


/*** SCGC1 - System Clock Gating Control 1 Register; 0x0000180E ***/
typedef union {
  byte Byte;
  struct {
    byte SCI         :1;                                       /* SCI Clock Gate Control */
    byte IIC         :1;                                       /* IIC Clock Gate Control */
    byte CMT         :1;                                       /* CMT Clock Gate Control */
    byte TPM1        :1;                                       /* TPM1 Clock Gate Control */
    byte TPM2        :1;                                       /* TPM2 Clock Gate Control */
    byte TPM3        :1;                                       /* TPM3 Clock Gate Control */
    byte TPM4        :1;                                       /* TPM4 Clock Gate Control */
    byte             :1; 
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTPM_1 :4;
    byte         :1;
  } MergedBits;
} SCGC1STR;
extern volatile SCGC1STR _SCGC1 @0x0000180E;
#define SCGC1                           _SCGC1.Byte
#define SCGC1_SCI                       _SCGC1.Bits.SCI
#define SCGC1_IIC                       _SCGC1.Bits.IIC
#define SCGC1_CMT                       _SCGC1.Bits.CMT
#define SCGC1_TPM1                      _SCGC1.Bits.TPM1
#define SCGC1_TPM2                      _SCGC1.Bits.TPM2
#define SCGC1_TPM3                      _SCGC1.Bits.TPM3
#define SCGC1_TPM4                      _SCGC1.Bits.TPM4
#define SCGC1_TPM_1                     _SCGC1.MergedBits.grpTPM_1
#define SCGC1_TPM                       SCGC1_TPM_1

#define SCGC1_SCI_MASK                  1U
#define SCGC1_IIC_MASK                  2U
#define SCGC1_CMT_MASK                  4U
#define SCGC1_TPM1_MASK                 8U
#define SCGC1_TPM2_MASK                 16U
#define SCGC1_TPM3_MASK                 32U
#define SCGC1_TPM4_MASK                 64U
#define SCGC1_TPM_1_MASK                120U
#define SCGC1_TPM_1_BITNUM              3U


/*** SCGC2 - System Clock Gating Control 2 Register; 0x0000180F ***/
typedef union {
  byte Byte;
  struct {
    byte SPI         :1;                                       /* SPI Clock Gate Control */
    byte RTC         :1;                                       /* RTC Clock Gate Control */
    byte KBI2        :1;                                       /* KBI2 Clock Gate Control */
    byte KBI1        :1;                                       /* KBI1 Clock Gate Control */
    byte IRQ         :1;                                       /* IRQ Clock Gate Control */
    byte FLS         :1;                                       /* FLS Clock Gate Control */
    byte DBG         :1;                                       /* DBG Clock Gate Control */
    byte MDM         :1;                                       /* Modem Clock Gate Control */
  } Bits;
} SCGC2STR;
extern volatile SCGC2STR _SCGC2 @0x0000180F;
#define SCGC2                           _SCGC2.Byte
#define SCGC2_SPI                       _SCGC2.Bits.SPI
#define SCGC2_RTC                       _SCGC2.Bits.RTC
#define SCGC2_KBI2                      _SCGC2.Bits.KBI2
#define SCGC2_KBI1                      _SCGC2.Bits.KBI1
#define SCGC2_IRQ                       _SCGC2.Bits.IRQ
#define SCGC2_FLS                       _SCGC2.Bits.FLS
#define SCGC2_DBG                       _SCGC2.Bits.DBG
#define SCGC2_MDM                       _SCGC2.Bits.MDM

#define SCGC2_SPI_MASK                  1U
#define SCGC2_RTC_MASK                  2U
#define SCGC2_KBI2_MASK                 4U
#define SCGC2_KBI1_MASK                 8U
#define SCGC2_IRQ_MASK                  16U
#define SCGC2_FLS_MASK                  32U
#define SCGC2_DBG_MASK                  64U
#define SCGC2_MDM_MASK                  128U


/*** DBGCA - Debug Comparator A Register; 0x00001810 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCAH - Debug Comparator A High Register; 0x00001810 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator A High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator A High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator A High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator A High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator A High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator A High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator A High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator A High Compare Bit 15 */
      } Bits;
    } DBGCAHSTR;
    #define DBGCAH                      _DBGCA.Overlap_STR.DBGCAHSTR.Byte
    #define DBGCAH_Bit8                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit8
    #define DBGCAH_Bit9                 _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit9
    #define DBGCAH_Bit10                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit10
    #define DBGCAH_Bit11                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit11
    #define DBGCAH_Bit12                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit12
    #define DBGCAH_Bit13                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit13
    #define DBGCAH_Bit14                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit14
    #define DBGCAH_Bit15                _DBGCA.Overlap_STR.DBGCAHSTR.Bits.Bit15
    
    #define DBGCAH_Bit8_MASK            1U
    #define DBGCAH_Bit9_MASK            2U
    #define DBGCAH_Bit10_MASK           4U
    #define DBGCAH_Bit11_MASK           8U
    #define DBGCAH_Bit12_MASK           16U
    #define DBGCAH_Bit13_MASK           32U
    #define DBGCAH_Bit14_MASK           64U
    #define DBGCAH_Bit15_MASK           128U
    

    /*** DBGCAL - Debug Comparator A Low Register; 0x00001811 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator A Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator A Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator A Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator A Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator A Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator A Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator A Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator A Low Compare Bit 7 */
      } Bits;
    } DBGCALSTR;
    #define DBGCAL                      _DBGCA.Overlap_STR.DBGCALSTR.Byte
    #define DBGCAL_Bit0                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit0
    #define DBGCAL_Bit1                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit1
    #define DBGCAL_Bit2                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit2
    #define DBGCAL_Bit3                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit3
    #define DBGCAL_Bit4                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit4
    #define DBGCAL_Bit5                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit5
    #define DBGCAL_Bit6                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit6
    #define DBGCAL_Bit7                 _DBGCA.Overlap_STR.DBGCALSTR.Bits.Bit7
    
    #define DBGCAL_Bit0_MASK            1U
    #define DBGCAL_Bit1_MASK            2U
    #define DBGCAL_Bit2_MASK            4U
    #define DBGCAL_Bit3_MASK            8U
    #define DBGCAL_Bit4_MASK            16U
    #define DBGCAL_Bit5_MASK            32U
    #define DBGCAL_Bit6_MASK            64U
    #define DBGCAL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCASTR;
extern volatile DBGCASTR _DBGCA @0x00001810;
#define DBGCA                           _DBGCA.Word


/*** DBGCB - Debug Comparator B Register; 0x00001812 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCBH - Debug Comparator B High Register; 0x00001812 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator B High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator B High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator B High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator B High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator B High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator B High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator B High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator B High Compare Bit 15 */
      } Bits;
    } DBGCBHSTR;
    #define DBGCBH                      _DBGCB.Overlap_STR.DBGCBHSTR.Byte
    #define DBGCBH_Bit8                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit8
    #define DBGCBH_Bit9                 _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit9
    #define DBGCBH_Bit10                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit10
    #define DBGCBH_Bit11                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit11
    #define DBGCBH_Bit12                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit12
    #define DBGCBH_Bit13                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit13
    #define DBGCBH_Bit14                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit14
    #define DBGCBH_Bit15                _DBGCB.Overlap_STR.DBGCBHSTR.Bits.Bit15
    
    #define DBGCBH_Bit8_MASK            1U
    #define DBGCBH_Bit9_MASK            2U
    #define DBGCBH_Bit10_MASK           4U
    #define DBGCBH_Bit11_MASK           8U
    #define DBGCBH_Bit12_MASK           16U
    #define DBGCBH_Bit13_MASK           32U
    #define DBGCBH_Bit14_MASK           64U
    #define DBGCBH_Bit15_MASK           128U
    

    /*** DBGCBL - Debug Comparator B Low Register; 0x00001813 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator B Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator B Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator B Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator B Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator B Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator B Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator B Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator B Low Compare Bit 7 */
      } Bits;
    } DBGCBLSTR;
    #define DBGCBL                      _DBGCB.Overlap_STR.DBGCBLSTR.Byte
    #define DBGCBL_Bit0                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit0
    #define DBGCBL_Bit1                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit1
    #define DBGCBL_Bit2                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit2
    #define DBGCBL_Bit3                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit3
    #define DBGCBL_Bit4                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit4
    #define DBGCBL_Bit5                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit5
    #define DBGCBL_Bit6                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit6
    #define DBGCBL_Bit7                 _DBGCB.Overlap_STR.DBGCBLSTR.Bits.Bit7
    
    #define DBGCBL_Bit0_MASK            1U
    #define DBGCBL_Bit1_MASK            2U
    #define DBGCBL_Bit2_MASK            4U
    #define DBGCBL_Bit3_MASK            8U
    #define DBGCBL_Bit4_MASK            16U
    #define DBGCBL_Bit5_MASK            32U
    #define DBGCBL_Bit6_MASK            64U
    #define DBGCBL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCBSTR;
extern volatile DBGCBSTR _DBGCB @0x00001812;
#define DBGCB                           _DBGCB.Word


/*** DBGCC - Debug Comparator C Register; 0x00001814 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGCCH - Debug Comparator C High Register; 0x00001814 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* Comparator C High Compare Bit 8 */
        byte Bit9        :1;                                       /* Comparator C High Compare Bit 9 */
        byte Bit10       :1;                                       /* Comparator C High Compare Bit 10 */
        byte Bit11       :1;                                       /* Comparator C High Compare Bit 11 */
        byte Bit12       :1;                                       /* Comparator C High Compare Bit 12 */
        byte Bit13       :1;                                       /* Comparator C High Compare Bit 13 */
        byte Bit14       :1;                                       /* Comparator C High Compare Bit 14 */
        byte Bit15       :1;                                       /* Comparator C High Compare Bit 15 */
      } Bits;
    } DBGCCHSTR;
    #define DBGCCH                      _DBGCC.Overlap_STR.DBGCCHSTR.Byte
    #define DBGCCH_Bit8                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit8
    #define DBGCCH_Bit9                 _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit9
    #define DBGCCH_Bit10                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit10
    #define DBGCCH_Bit11                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit11
    #define DBGCCH_Bit12                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit12
    #define DBGCCH_Bit13                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit13
    #define DBGCCH_Bit14                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit14
    #define DBGCCH_Bit15                _DBGCC.Overlap_STR.DBGCCHSTR.Bits.Bit15
    
    #define DBGCCH_Bit8_MASK            1U
    #define DBGCCH_Bit9_MASK            2U
    #define DBGCCH_Bit10_MASK           4U
    #define DBGCCH_Bit11_MASK           8U
    #define DBGCCH_Bit12_MASK           16U
    #define DBGCCH_Bit13_MASK           32U
    #define DBGCCH_Bit14_MASK           64U
    #define DBGCCH_Bit15_MASK           128U
    

    /*** DBGCCL - Debug Comparator C Low Register; 0x00001815 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* Comparator C Low Compare Bit 0 */
        byte Bit1        :1;                                       /* Comparator C Low Compare Bit 1 */
        byte Bit2        :1;                                       /* Comparator C Low Compare Bit 2 */
        byte Bit3        :1;                                       /* Comparator C Low Compare Bit 3 */
        byte Bit4        :1;                                       /* Comparator C Low Compare Bit 4 */
        byte Bit5        :1;                                       /* Comparator C Low Compare Bit 5 */
        byte Bit6        :1;                                       /* Comparator C Low Compare Bit 6 */
        byte Bit7        :1;                                       /* Comparator C Low Compare Bit 7 */
      } Bits;
    } DBGCCLSTR;
    #define DBGCCL                      _DBGCC.Overlap_STR.DBGCCLSTR.Byte
    #define DBGCCL_Bit0                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit0
    #define DBGCCL_Bit1                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit1
    #define DBGCCL_Bit2                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit2
    #define DBGCCL_Bit3                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit3
    #define DBGCCL_Bit4                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit4
    #define DBGCCL_Bit5                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit5
    #define DBGCCL_Bit6                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit6
    #define DBGCCL_Bit7                 _DBGCC.Overlap_STR.DBGCCLSTR.Bits.Bit7
    
    #define DBGCCL_Bit0_MASK            1U
    #define DBGCCL_Bit1_MASK            2U
    #define DBGCCL_Bit2_MASK            4U
    #define DBGCCL_Bit3_MASK            8U
    #define DBGCCL_Bit4_MASK            16U
    #define DBGCCL_Bit5_MASK            32U
    #define DBGCCL_Bit6_MASK            64U
    #define DBGCCL_Bit7_MASK            128U
    
  } Overlap_STR;

} DBGCCSTR;
extern volatile DBGCCSTR _DBGCC @0x00001814;
#define DBGCC                           _DBGCC.Word


/*** DBGF - Debug FIFO Register; 0x00001816 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** DBGFH - Debug FIFO High Register; 0x00001816 ***/
    union {
      byte Byte;
      struct {
        byte Bit8        :1;                                       /* FIFO High Data Bit 8 */
        byte Bit9        :1;                                       /* FIFO High Data Bit 9 */
        byte Bit10       :1;                                       /* FIFO High Data Bit 10 */
        byte Bit11       :1;                                       /* FIFO High Data Bit 11 */
        byte Bit12       :1;                                       /* FIFO High Data Bit 12 */
        byte Bit13       :1;                                       /* FIFO High Data Bit 13 */
        byte Bit14       :1;                                       /* FIFO High Data Bit 14 */
        byte Bit15       :1;                                       /* FIFO High Data Bit 15 */
      } Bits;
    } DBGFHSTR;
    #define DBGFH                       _DBGF.Overlap_STR.DBGFHSTR.Byte
    #define DBGFH_Bit8                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit8
    #define DBGFH_Bit9                  _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit9
    #define DBGFH_Bit10                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit10
    #define DBGFH_Bit11                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit11
    #define DBGFH_Bit12                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit12
    #define DBGFH_Bit13                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit13
    #define DBGFH_Bit14                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit14
    #define DBGFH_Bit15                 _DBGF.Overlap_STR.DBGFHSTR.Bits.Bit15
    
    #define DBGFH_Bit8_MASK             1U
    #define DBGFH_Bit9_MASK             2U
    #define DBGFH_Bit10_MASK            4U
    #define DBGFH_Bit11_MASK            8U
    #define DBGFH_Bit12_MASK            16U
    #define DBGFH_Bit13_MASK            32U
    #define DBGFH_Bit14_MASK            64U
    #define DBGFH_Bit15_MASK            128U
    

    /*** DBGFL - Debug FIFO Low Register; 0x00001817 ***/
    union {
      byte Byte;
      struct {
        byte Bit0        :1;                                       /* FIFO Low Data Bit 0 */
        byte Bit1        :1;                                       /* FIFO Low Data Bit 1 */
        byte Bit2        :1;                                       /* FIFO Low Data Bit 2 */
        byte Bit3        :1;                                       /* FIFO Low Data Bit 3 */
        byte Bit4        :1;                                       /* FIFO Low Data Bit 4 */
        byte Bit5        :1;                                       /* FIFO Low Data Bit 5 */
        byte Bit6        :1;                                       /* FIFO Low Data Bit 6 */
        byte Bit7        :1;                                       /* FIFO Low Data Bit 7 */
      } Bits;
    } DBGFLSTR;
    #define DBGFL                       _DBGF.Overlap_STR.DBGFLSTR.Byte
    #define DBGFL_Bit0                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit0
    #define DBGFL_Bit1                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit1
    #define DBGFL_Bit2                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit2
    #define DBGFL_Bit3                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit3
    #define DBGFL_Bit4                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit4
    #define DBGFL_Bit5                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit5
    #define DBGFL_Bit6                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit6
    #define DBGFL_Bit7                  _DBGF.Overlap_STR.DBGFLSTR.Bits.Bit7
    
    #define DBGFL_Bit0_MASK             1U
    #define DBGFL_Bit1_MASK             2U
    #define DBGFL_Bit2_MASK             4U
    #define DBGFL_Bit3_MASK             8U
    #define DBGFL_Bit4_MASK             16U
    #define DBGFL_Bit5_MASK             32U
    #define DBGFL_Bit6_MASK             64U
    #define DBGFL_Bit7_MASK             128U
    
  } Overlap_STR;

} DBGFSTR;
extern volatile DBGFSTR _DBGF @0x00001816;
#define DBGF                            _DBGF.Word


/*** DBGCAX - Debug Comparator A Extension Register; 0x00001818 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator A Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator A Page Select Bit */
    byte RWA         :1;                                       /* Read/Write Comparator A Value Bit */
    byte RWAEN       :1;                                       /* Read/Write Comparator A Enable Bit */
  } Bits;
} DBGCAXSTR;
extern volatile DBGCAXSTR _DBGCAX @0x00001818;
#define DBGCAX                          _DBGCAX.Byte
#define DBGCAX_Bit16                    _DBGCAX.Bits.Bit16
#define DBGCAX_PAGSEL                   _DBGCAX.Bits.PAGSEL
#define DBGCAX_RWA                      _DBGCAX.Bits.RWA
#define DBGCAX_RWAEN                    _DBGCAX.Bits.RWAEN

#define DBGCAX_Bit16_MASK               1U
#define DBGCAX_PAGSEL_MASK              32U
#define DBGCAX_RWA_MASK                 64U
#define DBGCAX_RWAEN_MASK               128U


/*** DBGCBX - Debug Comparator B Extension Register; 0x00001819 ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator B Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator B Page Select Bit */
    byte RWB         :1;                                       /* Read/Write Comparator B Value Bit */
    byte RWBEN       :1;                                       /* Read/Write Comparator B Enable Bit */
  } Bits;
} DBGCBXSTR;
extern volatile DBGCBXSTR _DBGCBX @0x00001819;
#define DBGCBX                          _DBGCBX.Byte
#define DBGCBX_Bit16                    _DBGCBX.Bits.Bit16
#define DBGCBX_PAGSEL                   _DBGCBX.Bits.PAGSEL
#define DBGCBX_RWB                      _DBGCBX.Bits.RWB
#define DBGCBX_RWBEN                    _DBGCBX.Bits.RWBEN

#define DBGCBX_Bit16_MASK               1U
#define DBGCBX_PAGSEL_MASK              32U
#define DBGCBX_RWB_MASK                 64U
#define DBGCBX_RWBEN_MASK               128U


/*** DBGCCX - Debug Comparator C Extension Register; 0x0000181A ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* omparator C Extended Address Bit 16 Compare Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PAGSEL      :1;                                       /* Comparator C Page Select Bit */
    byte RWC         :1;                                       /* Read/Write Comparator C Value Bit */
    byte RWCEN       :1;                                       /* Read/Write Comparator C Enable Bit */
  } Bits;
} DBGCCXSTR;
extern volatile DBGCCXSTR _DBGCCX @0x0000181A;
#define DBGCCX                          _DBGCCX.Byte
#define DBGCCX_Bit16                    _DBGCCX.Bits.Bit16
#define DBGCCX_PAGSEL                   _DBGCCX.Bits.PAGSEL
#define DBGCCX_RWC                      _DBGCCX.Bits.RWC
#define DBGCCX_RWCEN                    _DBGCCX.Bits.RWCEN

#define DBGCCX_Bit16_MASK               1U
#define DBGCCX_PAGSEL_MASK              32U
#define DBGCCX_RWC_MASK                 64U
#define DBGCCX_RWCEN_MASK               128U


/*** DBGFX - Debug FIFO Extended Information Register; 0x0000181B ***/
typedef union {
  byte Byte;
  struct {
    byte Bit16       :1;                                       /* Extended Address Bit 16 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte PPACC       :1;                                       /* PPAGE Access Indicator Bit */
  } Bits;
} DBGFXSTR;
extern volatile DBGFXSTR _DBGFX @0x0000181B;
#define DBGFX                           _DBGFX.Byte
#define DBGFX_Bit16                     _DBGFX.Bits.Bit16
#define DBGFX_PPACC                     _DBGFX.Bits.PPACC

#define DBGFX_Bit16_MASK                1U
#define DBGFX_PPACC_MASK                128U


/*** DBGC - Debug Control Register; 0x0000181C ***/
typedef union {
  byte Byte;
  struct {
    byte LOOP1       :1;                                       /* Select LOOP1 Capture Mode */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte BRKEN       :1;                                       /* Break Enable Bit */
    byte TAG         :1;                                       /* Tag or Force Bit */
    byte ARM         :1;                                       /* Arm Bit */
    byte DBGEN       :1;                                       /* DBG Module Enable Bit */
  } Bits;
} DBGCSTR;
extern volatile DBGCSTR _DBGC @0x0000181C;
#define DBGC                            _DBGC.Byte
#define DBGC_LOOP1                      _DBGC.Bits.LOOP1
#define DBGC_BRKEN                      _DBGC.Bits.BRKEN
#define DBGC_TAG                        _DBGC.Bits.TAG
#define DBGC_ARM                        _DBGC.Bits.ARM
#define DBGC_DBGEN                      _DBGC.Bits.DBGEN

#define DBGC_LOOP1_MASK                 1U
#define DBGC_BRKEN_MASK                 16U
#define DBGC_TAG_MASK                   32U
#define DBGC_ARM_MASK                   64U
#define DBGC_DBGEN_MASK                 128U


/*** DBGT - Debug Trigger Register; 0x0000181D ***/
typedef union {
  byte Byte;
  struct {
    byte TRG0        :1;                                       /* Trigger Mode Bit 0 */
    byte TRG1        :1;                                       /* Trigger Mode Bit 1 */
    byte TRG2        :1;                                       /* Trigger Mode Bit 2 */
    byte TRG3        :1;                                       /* Trigger Mode Bit 3 */
    byte             :1; 
    byte             :1; 
    byte BEGIN       :1;                                       /* Begin/End Trigger Bit */
    byte TRGSEL      :1;                                       /* Trigger Selection Bit */
  } Bits;
  struct {
    byte grpTRG  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGTSTR;
extern volatile DBGTSTR _DBGT @0x0000181D;
#define DBGT                            _DBGT.Byte
#define DBGT_TRG0                       _DBGT.Bits.TRG0
#define DBGT_TRG1                       _DBGT.Bits.TRG1
#define DBGT_TRG2                       _DBGT.Bits.TRG2
#define DBGT_TRG3                       _DBGT.Bits.TRG3
#define DBGT_BEGIN                      _DBGT.Bits.BEGIN
#define DBGT_TRGSEL                     _DBGT.Bits.TRGSEL
#define DBGT_TRG                        _DBGT.MergedBits.grpTRG

#define DBGT_TRG0_MASK                  1U
#define DBGT_TRG1_MASK                  2U
#define DBGT_TRG2_MASK                  4U
#define DBGT_TRG3_MASK                  8U
#define DBGT_BEGIN_MASK                 64U
#define DBGT_TRGSEL_MASK                128U
#define DBGT_TRG_MASK                   15U
#define DBGT_TRG_BITNUM                 0U


/*** DBGS - Debug Status Register; 0x0000181E ***/
typedef union {
  byte Byte;
  struct {
    byte ARMF        :1;                                       /* Arm Flag Bit */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte CF          :1;                                       /* Trigger C Match Bit */
    byte BF          :1;                                       /* Trigger B Match Bit */
    byte AF          :1;                                       /* Trigger A Match Bit */
  } Bits;
} DBGSSTR;
extern volatile DBGSSTR _DBGS @0x0000181E;
#define DBGS                            _DBGS.Byte
#define DBGS_ARMF                       _DBGS.Bits.ARMF
#define DBGS_CF                         _DBGS.Bits.CF
#define DBGS_BF                         _DBGS.Bits.BF
#define DBGS_AF                         _DBGS.Bits.AF

#define DBGS_ARMF_MASK                  1U
#define DBGS_CF_MASK                    32U
#define DBGS_BF_MASK                    64U
#define DBGS_AF_MASK                    128U


/*** DBGCNT - Debug Count Status Register; 0x0000181F ***/
typedef union {
  byte Byte;
  struct {
    byte CNT0        :1;                                       /* FIFO Valid Count Bits, bit 0 */
    byte CNT1        :1;                                       /* FIFO Valid Count Bits, bit 1 */
    byte CNT2        :1;                                       /* FIFO Valid Count Bits, bit 2 */
    byte CNT3        :1;                                       /* FIFO Valid Count Bits, bit 3 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
  struct {
    byte grpCNT  :4;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} DBGCNTSTR;
extern volatile DBGCNTSTR _DBGCNT @0x0000181F;
#define DBGCNT                          _DBGCNT.Byte
#define DBGCNT_CNT0                     _DBGCNT.Bits.CNT0
#define DBGCNT_CNT1                     _DBGCNT.Bits.CNT1
#define DBGCNT_CNT2                     _DBGCNT.Bits.CNT2
#define DBGCNT_CNT3                     _DBGCNT.Bits.CNT3
#define DBGCNT_CNT                      _DBGCNT.MergedBits.grpCNT

#define DBGCNT_CNT0_MASK                1U
#define DBGCNT_CNT1_MASK                2U
#define DBGCNT_CNT2_MASK                4U
#define DBGCNT_CNT3_MASK                8U
#define DBGCNT_CNT_MASK                 15U
#define DBGCNT_CNT_BITNUM               0U


/*** FOPT - Flash Options Register; 0x00001821 ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} FOPTSTR;
extern volatile FOPTSTR _FOPT @0x00001821;
#define FOPT                            _FOPT.Byte
#define FOPT_SEC0                       _FOPT.Bits.SEC0
#define FOPT_SEC1                       _FOPT.Bits.SEC1
#define FOPT_KEYEN0                     _FOPT.Bits.KEYEN0
#define FOPT_KEYEN1                     _FOPT.Bits.KEYEN1
#define FOPT_SEC                        _FOPT.MergedBits.grpSEC
#define FOPT_KEYEN                      _FOPT.MergedBits.grpKEYEN

#define FOPT_SEC0_MASK                  1U
#define FOPT_SEC1_MASK                  2U
#define FOPT_KEYEN0_MASK                64U
#define FOPT_KEYEN1_MASK                128U
#define FOPT_SEC_MASK                   3U
#define FOPT_SEC_BITNUM                 0U
#define FOPT_KEYEN_MASK                 192U
#define FOPT_KEYEN_BITNUM               6U


/*** FCNFG - Flash Configuration Register; 0x00001823 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYACC      :1;                                       /* Enable Security Key Writing */
    byte             :1; 
    byte             :1; 
  } Bits;
} FCNFGSTR;
extern volatile FCNFGSTR _FCNFG @0x00001823;
#define FCNFG                           _FCNFG.Byte
#define FCNFG_KEYACC                    _FCNFG.Bits.KEYACC

#define FCNFG_KEYACC_MASK               32U


/*** FPROT - Flash Protection Register; 0x00001824 ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} FPROTSTR;
extern volatile FPROTSTR _FPROT @0x00001824;
#define FPROT                           _FPROT.Byte
#define FPROT_FPOPEN                    _FPROT.Bits.FPOPEN
#define FPROT_FPS0                      _FPROT.Bits.FPS0
#define FPROT_FPS1                      _FPROT.Bits.FPS1
#define FPROT_FPS2                      _FPROT.Bits.FPS2
#define FPROT_FPS3                      _FPROT.Bits.FPS3
#define FPROT_FPS4                      _FPROT.Bits.FPS4
#define FPROT_FPS5                      _FPROT.Bits.FPS5
#define FPROT_FPS6                      _FPROT.Bits.FPS6
#define FPROT_FPS                       _FPROT.MergedBits.grpFPS

#define FPROT_FPOPEN_MASK               1U
#define FPROT_FPS0_MASK                 2U
#define FPROT_FPS1_MASK                 4U
#define FPROT_FPS2_MASK                 8U
#define FPROT_FPS3_MASK                 16U
#define FPROT_FPS4_MASK                 32U
#define FPROT_FPS5_MASK                 64U
#define FPROT_FPS6_MASK                 128U
#define FPROT_FPS_MASK                  254U
#define FPROT_FPS_BITNUM                1U


/*** FSTAT - Flash Status Register; 0x00001825 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte FBLANK      :1;                                       /* FLASH Flag Indicating the Erase Verify Operation Status */
    byte             :1; 
    byte FACCERR     :1;                                       /* FLASH Access Error Flag */
    byte FPVIOL      :1;                                       /* FLASH Protection Violation Flag */
    byte FCCF        :1;                                       /* FLASH Command Complete Interrupt Flag */
    byte FCBEF       :1;                                       /* FLASH Command Buffer Empty Flag */
  } Bits;
} FSTATSTR;
extern volatile FSTATSTR _FSTAT @0x00001825;
#define FSTAT                           _FSTAT.Byte
#define FSTAT_FBLANK                    _FSTAT.Bits.FBLANK
#define FSTAT_FACCERR                   _FSTAT.Bits.FACCERR
#define FSTAT_FPVIOL                    _FSTAT.Bits.FPVIOL
#define FSTAT_FCCF                      _FSTAT.Bits.FCCF
#define FSTAT_FCBEF                     _FSTAT.Bits.FCBEF

#define FSTAT_FBLANK_MASK               4U
#define FSTAT_FACCERR_MASK              16U
#define FSTAT_FPVIOL_MASK               32U
#define FSTAT_FCCF_MASK                 64U
#define FSTAT_FCBEF_MASK                128U


/*** FCMD - Flash Command Register; 0x00001826 ***/
typedef union {
  byte Byte;
  struct {
    byte FCMD0       :1;                                       /* Flash Command, bit 0 */
    byte FCMD1       :1;                                       /* Flash Command, bit 1 */
    byte FCMD2       :1;                                       /* Flash Command, bit 2 */
    byte FCMD3       :1;                                       /* Flash Command, bit 3 */
    byte FCMD4       :1;                                       /* Flash Command, bit 4 */
    byte FCMD5       :1;                                       /* Flash Command, bit 5 */
    byte FCMD6       :1;                                       /* Flash Command, bit 6 */
    byte             :1; 
  } Bits;
  struct {
    byte grpFCMD :7;
    byte         :1;
  } MergedBits;
} FCMDSTR;
extern volatile FCMDSTR _FCMD @0x00001826;
#define FCMD                            _FCMD.Byte
#define FCMD_FCMD0                      _FCMD.Bits.FCMD0
#define FCMD_FCMD1                      _FCMD.Bits.FCMD1
#define FCMD_FCMD2                      _FCMD.Bits.FCMD2
#define FCMD_FCMD3                      _FCMD.Bits.FCMD3
#define FCMD_FCMD4                      _FCMD.Bits.FCMD4
#define FCMD_FCMD5                      _FCMD.Bits.FCMD5
#define FCMD_FCMD6                      _FCMD.Bits.FCMD6
#define FCMD_FCMD                       _FCMD.MergedBits.grpFCMD

#define FCMD_FCMD0_MASK                 1U
#define FCMD_FCMD1_MASK                 2U
#define FCMD_FCMD2_MASK                 4U
#define FCMD_FCMD3_MASK                 8U
#define FCMD_FCMD4_MASK                 16U
#define FCMD_FCMD5_MASK                 32U
#define FCMD_FCMD6_MASK                 64U
#define FCMD_FCMD_MASK                  127U
#define FCMD_FCMD_BITNUM                0U


/*** RTCSC - RTC Status and Control Register; 0x00001828 ***/
typedef union {
  byte Byte;
  struct {
    byte RTCPS0      :1;                                       /* Real-Time Clock Prescaler Select, bit 0 */
    byte RTCPS1      :1;                                       /* Real-Time Clock Prescaler Select, bit 1 */
    byte RTCPS2      :1;                                       /* Real-Time Clock Prescaler Select, bit 2 */
    byte RTCPS3      :1;                                       /* Real-Time Clock Prescaler Select, bit 3 */
    byte RTIE        :1;                                       /* Real-Time Interrupt Enable */
    byte RTCLKS0     :1;                                       /* Real-Time Clock Source Select, bit 0 */
    byte RTCLKS1     :1;                                       /* Real-Time Clock Source Select, bit 1 */
    byte RTIF        :1;                                       /* Real-Time Interrupt Flag */
  } Bits;
  struct {
    byte grpRTCPS :4;
    byte         :1;
    byte grpRTCLKS :2;
    byte         :1;
  } MergedBits;
} RTCSCSTR;
extern volatile RTCSCSTR _RTCSC @0x00001828;
#define RTCSC                           _RTCSC.Byte
#define RTCSC_RTCPS0                    _RTCSC.Bits.RTCPS0
#define RTCSC_RTCPS1                    _RTCSC.Bits.RTCPS1
#define RTCSC_RTCPS2                    _RTCSC.Bits.RTCPS2
#define RTCSC_RTCPS3                    _RTCSC.Bits.RTCPS3
#define RTCSC_RTIE                      _RTCSC.Bits.RTIE
#define RTCSC_RTCLKS0                   _RTCSC.Bits.RTCLKS0
#define RTCSC_RTCLKS1                   _RTCSC.Bits.RTCLKS1
#define RTCSC_RTIF                      _RTCSC.Bits.RTIF
#define RTCSC_RTCPS                     _RTCSC.MergedBits.grpRTCPS
#define RTCSC_RTCLKS                    _RTCSC.MergedBits.grpRTCLKS

#define RTCSC_RTCPS0_MASK               1U
#define RTCSC_RTCPS1_MASK               2U
#define RTCSC_RTCPS2_MASK               4U
#define RTCSC_RTCPS3_MASK               8U
#define RTCSC_RTIE_MASK                 16U
#define RTCSC_RTCLKS0_MASK              32U
#define RTCSC_RTCLKS1_MASK              64U
#define RTCSC_RTIF_MASK                 128U
#define RTCSC_RTCPS_MASK                15U
#define RTCSC_RTCPS_BITNUM              0U
#define RTCSC_RTCLKS_MASK               96U
#define RTCSC_RTCLKS_BITNUM             5U


/*** RTCCNTL - RTC Counter Register Low; 0x00001829 ***/
typedef union {
  byte Byte;
} RTCCNTLSTR;
extern volatile RTCCNTLSTR _RTCCNTL @0x00001829;
#define RTCCNTL                         _RTCCNTL.Byte


/*** RTCMODL - RTC Modulo Register Low; 0x0000182A ***/
typedef union {
  byte Byte;
} RTCMODLSTR;
extern volatile RTCMODLSTR _RTCMODL @0x0000182A;
#define RTCMODL                         _RTCMODL.Byte


/*** RTCCNTH - RTC Counter Register High; 0x0000182B ***/
typedef union {
  byte Byte;
} RTCCNTHSTR;
extern volatile RTCCNTHSTR _RTCCNTH @0x0000182B;
#define RTCCNTH                         _RTCCNTH.Byte


/*** RTCMODH - RTC Modulo Register High; 0x0000182C ***/
typedef union {
  byte Byte;
} RTCMODHSTR;
extern volatile RTCMODHSTR _RTCMODH @0x0000182C;
#define RTCMODH                         _RTCMODH.Byte


/*** PTAPE - Port A Pull Enable Register; 0x00001830 ***/
typedef union {
  byte Byte;
  struct {
    byte PTAPE0      :1;                                       /* Internal Pull Enable for Port A Bit 0 */
    byte PTAPE1      :1;                                       /* Internal Pull Enable for Port A Bit 1 */
    byte PTAPE2      :1;                                       /* Internal Pull Enable for Port A Bit 2 */
    byte PTAPE3      :1;                                       /* Internal Pull Enable for Port A Bit 3 */
    byte PTAPE4      :1;                                       /* Internal Pull Enable for Port A Bit 4 */
    byte PTAPE5      :1;                                       /* Internal Pull Enable for Port A Bit 5 */
    byte PTAPE6      :1;                                       /* Internal Pull Enable for Port A Bit 6 */
    byte PTAPE7      :1;                                       /* Internal Pull Enable for Port A Bit 7 */
  } Bits;
} PTAPESTR;
extern volatile PTAPESTR _PTAPE @0x00001830;
#define PTAPE                           _PTAPE.Byte
#define PTAPE_PTAPE0                    _PTAPE.Bits.PTAPE0
#define PTAPE_PTAPE1                    _PTAPE.Bits.PTAPE1
#define PTAPE_PTAPE2                    _PTAPE.Bits.PTAPE2
#define PTAPE_PTAPE3                    _PTAPE.Bits.PTAPE3
#define PTAPE_PTAPE4                    _PTAPE.Bits.PTAPE4
#define PTAPE_PTAPE5                    _PTAPE.Bits.PTAPE5
#define PTAPE_PTAPE6                    _PTAPE.Bits.PTAPE6
#define PTAPE_PTAPE7                    _PTAPE.Bits.PTAPE7

#define PTAPE_PTAPE0_MASK               1U
#define PTAPE_PTAPE1_MASK               2U
#define PTAPE_PTAPE2_MASK               4U
#define PTAPE_PTAPE3_MASK               8U
#define PTAPE_PTAPE4_MASK               16U
#define PTAPE_PTAPE5_MASK               32U
#define PTAPE_PTAPE6_MASK               64U
#define PTAPE_PTAPE7_MASK               128U


/*** PTASE - Port A Slew Rate Enable Register; 0x00001831 ***/
typedef union {
  byte Byte;
  struct {
    byte PTASE0      :1;                                       /* Output Slew Rate Enable for Port A Bit 0 */
    byte PTASE1      :1;                                       /* Output Slew Rate Enable for Port A Bit 1 */
    byte PTASE2      :1;                                       /* Output Slew Rate Enable for Port A Bit 2 */
    byte PTASE3      :1;                                       /* Output Slew Rate Enable for Port A Bit 3 */
    byte PTASE4      :1;                                       /* Output Slew Rate Enable for Port A Bit 4 */
    byte PTASE5      :1;                                       /* Output Slew Rate Enable for Port A Bit 5 */
    byte PTASE6      :1;                                       /* Output Slew Rate Enable for Port A Bit 6 */
    byte PTASE7      :1;                                       /* Output Slew Rate Enable for Port A Bit 7 */
  } Bits;
} PTASESTR;
extern volatile PTASESTR _PTASE @0x00001831;
#define PTASE                           _PTASE.Byte
#define PTASE_PTASE0                    _PTASE.Bits.PTASE0
#define PTASE_PTASE1                    _PTASE.Bits.PTASE1
#define PTASE_PTASE2                    _PTASE.Bits.PTASE2
#define PTASE_PTASE3                    _PTASE.Bits.PTASE3
#define PTASE_PTASE4                    _PTASE.Bits.PTASE4
#define PTASE_PTASE5                    _PTASE.Bits.PTASE5
#define PTASE_PTASE6                    _PTASE.Bits.PTASE6
#define PTASE_PTASE7                    _PTASE.Bits.PTASE7

#define PTASE_PTASE0_MASK               1U
#define PTASE_PTASE1_MASK               2U
#define PTASE_PTASE2_MASK               4U
#define PTASE_PTASE3_MASK               8U
#define PTASE_PTASE4_MASK               16U
#define PTASE_PTASE5_MASK               32U
#define PTASE_PTASE6_MASK               64U
#define PTASE_PTASE7_MASK               128U


/*** PTADS - Port A Drive Strength Selection Register; 0x00001832 ***/
typedef union {
  byte Byte;
  struct {
    byte PTADS0      :1;                                       /* Output Drive Strength Selection for Port A Bit 0 */
    byte PTADS1      :1;                                       /* Output Drive Strength Selection for Port A Bit 1 */
    byte PTADS2      :1;                                       /* Output Drive Strength Selection for Port A Bit 2 */
    byte PTADS3      :1;                                       /* Output Drive Strength Selection for Port A Bit 3 */
    byte PTADS4      :1;                                       /* Output Drive Strength Selection for Port A Bit 4 */
    byte PTADS5      :1;                                       /* Output Drive Strength Selection for Port A Bit 5 */
    byte PTADS6      :1;                                       /* Output Drive Strength Selection for Port A Bit 6 */
    byte PTADS7      :1;                                       /* Output Drive Strength Selection for Port A Bit 7 */
  } Bits;
} PTADSSTR;
extern volatile PTADSSTR _PTADS @0x00001832;
#define PTADS                           _PTADS.Byte
#define PTADS_PTADS0                    _PTADS.Bits.PTADS0
#define PTADS_PTADS1                    _PTADS.Bits.PTADS1
#define PTADS_PTADS2                    _PTADS.Bits.PTADS2
#define PTADS_PTADS3                    _PTADS.Bits.PTADS3
#define PTADS_PTADS4                    _PTADS.Bits.PTADS4
#define PTADS_PTADS5                    _PTADS.Bits.PTADS5
#define PTADS_PTADS6                    _PTADS.Bits.PTADS6
#define PTADS_PTADS7                    _PTADS.Bits.PTADS7

#define PTADS_PTADS0_MASK               1U
#define PTADS_PTADS1_MASK               2U
#define PTADS_PTADS2_MASK               4U
#define PTADS_PTADS3_MASK               8U
#define PTADS_PTADS4_MASK               16U
#define PTADS_PTADS5_MASK               32U
#define PTADS_PTADS6_MASK               64U
#define PTADS_PTADS7_MASK               128U


/*** PTBPE - Port B Pull Enable Register; 0x00001834 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBPE0      :1;                                       /* Internal Pull Enable for Port B Bit 0 */
    byte PTBPE1      :1;                                       /* Internal Pull Enable for Port B Bit 1 */
    byte PTBPE2      :1;                                       /* Internal Pull Enable for Port B Bit 2 */
    byte PTBPE3      :1;                                       /* Internal Pull Enable for Port B Bit 3 */
    byte PTBPE4      :1;                                       /* Internal Pull Enable for Port B Bit 4 */
    byte PTBPE5      :1;                                       /* Internal Pull Enable for Port B Bit 5 */
    byte PTBPE6      :1;                                       /* Internal Pull Enable for Port B Bit 6 */
    byte PTBPE7      :1;                                       /* Internal Pull Enable for Port B Bit 7 */
  } Bits;
} PTBPESTR;
extern volatile PTBPESTR _PTBPE @0x00001834;
#define PTBPE                           _PTBPE.Byte
#define PTBPE_PTBPE0                    _PTBPE.Bits.PTBPE0
#define PTBPE_PTBPE1                    _PTBPE.Bits.PTBPE1
#define PTBPE_PTBPE2                    _PTBPE.Bits.PTBPE2
#define PTBPE_PTBPE3                    _PTBPE.Bits.PTBPE3
#define PTBPE_PTBPE4                    _PTBPE.Bits.PTBPE4
#define PTBPE_PTBPE5                    _PTBPE.Bits.PTBPE5
#define PTBPE_PTBPE6                    _PTBPE.Bits.PTBPE6
#define PTBPE_PTBPE7                    _PTBPE.Bits.PTBPE7

#define PTBPE_PTBPE0_MASK               1U
#define PTBPE_PTBPE1_MASK               2U
#define PTBPE_PTBPE2_MASK               4U
#define PTBPE_PTBPE3_MASK               8U
#define PTBPE_PTBPE4_MASK               16U
#define PTBPE_PTBPE5_MASK               32U
#define PTBPE_PTBPE6_MASK               64U
#define PTBPE_PTBPE7_MASK               128U


/*** PTBSE - Port B Slew Rate Enable Register; 0x00001835 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBSE0      :1;                                       /* Output Slew Rate Enable for Port B Bit 0 */
    byte PTBSE1      :1;                                       /* Output Slew Rate Enable for Port B Bit 1 */
    byte PTBSE2      :1;                                       /* Output Slew Rate Enable for Port B Bit 2 */
    byte PTBSE3      :1;                                       /* Output Slew Rate Enable for Port B Bit 3 */
    byte PTBSE4      :1;                                       /* Output Slew Rate Enable for Port B Bit 4 */
    byte PTBSE5      :1;                                       /* Output Slew Rate Enable for Port B Bit 5 */
    byte PTBSE6      :1;                                       /* Output Slew Rate Enable for Port B Bit 6 */
    byte PTBSE7      :1;                                       /* Output Slew Rate Enable for Port B Bit 7 */
  } Bits;
} PTBSESTR;
extern volatile PTBSESTR _PTBSE @0x00001835;
#define PTBSE                           _PTBSE.Byte
#define PTBSE_PTBSE0                    _PTBSE.Bits.PTBSE0
#define PTBSE_PTBSE1                    _PTBSE.Bits.PTBSE1
#define PTBSE_PTBSE2                    _PTBSE.Bits.PTBSE2
#define PTBSE_PTBSE3                    _PTBSE.Bits.PTBSE3
#define PTBSE_PTBSE4                    _PTBSE.Bits.PTBSE4
#define PTBSE_PTBSE5                    _PTBSE.Bits.PTBSE5
#define PTBSE_PTBSE6                    _PTBSE.Bits.PTBSE6
#define PTBSE_PTBSE7                    _PTBSE.Bits.PTBSE7

#define PTBSE_PTBSE0_MASK               1U
#define PTBSE_PTBSE1_MASK               2U
#define PTBSE_PTBSE2_MASK               4U
#define PTBSE_PTBSE3_MASK               8U
#define PTBSE_PTBSE4_MASK               16U
#define PTBSE_PTBSE5_MASK               32U
#define PTBSE_PTBSE6_MASK               64U
#define PTBSE_PTBSE7_MASK               128U


/*** PTBDS - Port B Drive Strength Selection Register; 0x00001836 ***/
typedef union {
  byte Byte;
  struct {
    byte PTBDS0      :1;                                       /* Output Drive Strength Selection for Port B Bit 0 */
    byte PTBDS1      :1;                                       /* Output Drive Strength Selection for Port B Bit 1 */
    byte PTBDS2      :1;                                       /* Output Drive Strength Selection for Port B Bit 2 */
    byte PTBDS3      :1;                                       /* Output Drive Strength Selection for Port B Bit 3 */
    byte PTBDS4      :1;                                       /* Output Drive Strength Selection for Port B Bit 4 */
    byte PTBDS5      :1;                                       /* Output Drive Strength Selection for Port B Bit 5 */
    byte PTBDS6      :1;                                       /* Output Drive Strength Selection for Port B Bit 6 */
    byte PTBDS7      :1;                                       /* Output Drive Strength Selection for Port B Bit 7 */
  } Bits;
} PTBDSSTR;
extern volatile PTBDSSTR _PTBDS @0x00001836;
#define PTBDS                           _PTBDS.Byte
#define PTBDS_PTBDS0                    _PTBDS.Bits.PTBDS0
#define PTBDS_PTBDS1                    _PTBDS.Bits.PTBDS1
#define PTBDS_PTBDS2                    _PTBDS.Bits.PTBDS2
#define PTBDS_PTBDS3                    _PTBDS.Bits.PTBDS3
#define PTBDS_PTBDS4                    _PTBDS.Bits.PTBDS4
#define PTBDS_PTBDS5                    _PTBDS.Bits.PTBDS5
#define PTBDS_PTBDS6                    _PTBDS.Bits.PTBDS6
#define PTBDS_PTBDS7                    _PTBDS.Bits.PTBDS7

#define PTBDS_PTBDS0_MASK               1U
#define PTBDS_PTBDS1_MASK               2U
#define PTBDS_PTBDS2_MASK               4U
#define PTBDS_PTBDS3_MASK               8U
#define PTBDS_PTBDS4_MASK               16U
#define PTBDS_PTBDS5_MASK               32U
#define PTBDS_PTBDS6_MASK               64U
#define PTBDS_PTBDS7_MASK               128U


/*** PTCPE - Port C Pull Enable Register; 0x00001838 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCPE0      :1;                                       /* Internal Pull Enable for Port C Bit 0 */
    byte PTCPE1      :1;                                       /* Internal Pull Enable for Port C Bit 1 */
    byte PTCPE2      :1;                                       /* Internal Pull Enable for Port C Bit 2 */
    byte PTCPE3      :1;                                       /* Internal Pull Enable for Port C Bit 3 */
    byte PTCPE4      :1;                                       /* Internal Pull Enable for Port C Bit 4 */
    byte PTCPE5      :1;                                       /* Internal Pull Enable for Port C Bit 5 */
    byte PTCPE6      :1;                                       /* Internal Pull Enable for Port C Bit 6 */
    byte PTCPE7      :1;                                       /* Internal Pull Enable for Port C Bit 7 */
  } Bits;
} PTCPESTR;
extern volatile PTCPESTR _PTCPE @0x00001838;
#define PTCPE                           _PTCPE.Byte
#define PTCPE_PTCPE0                    _PTCPE.Bits.PTCPE0
#define PTCPE_PTCPE1                    _PTCPE.Bits.PTCPE1
#define PTCPE_PTCPE2                    _PTCPE.Bits.PTCPE2
#define PTCPE_PTCPE3                    _PTCPE.Bits.PTCPE3
#define PTCPE_PTCPE4                    _PTCPE.Bits.PTCPE4
#define PTCPE_PTCPE5                    _PTCPE.Bits.PTCPE5
#define PTCPE_PTCPE6                    _PTCPE.Bits.PTCPE6
#define PTCPE_PTCPE7                    _PTCPE.Bits.PTCPE7

#define PTCPE_PTCPE0_MASK               1U
#define PTCPE_PTCPE1_MASK               2U
#define PTCPE_PTCPE2_MASK               4U
#define PTCPE_PTCPE3_MASK               8U
#define PTCPE_PTCPE4_MASK               16U
#define PTCPE_PTCPE5_MASK               32U
#define PTCPE_PTCPE6_MASK               64U
#define PTCPE_PTCPE7_MASK               128U


/*** PTCSE - Port C Slew Rate Enable Register; 0x00001839 ***/
typedef union {
  byte Byte;
  struct {
    byte PTCSE0      :1;                                       /* Output Slew Rate Enable for Port C Bit 0 */
    byte PTCSE1      :1;                                       /* Output Slew Rate Enable for Port C Bit 1 */
    byte PTCSE2      :1;                                       /* Output Slew Rate Enable for Port C Bit 2 */
    byte PTCSE3      :1;                                       /* Output Slew Rate Enable for Port C Bit 3 */
    byte PTCSE4      :1;                                       /* Output Slew Rate Enable for Port C Bit 4 */
    byte PTCSE5      :1;                                       /* Output Slew Rate Enable for Port C Bit 5 */
    byte PTCSE6      :1;                                       /* Output Slew Rate Enable for Port C Bit 6 */
    byte PTCSE7      :1;                                       /* Output Slew Rate Enable for Port C Bit 7 */
  } Bits;
} PTCSESTR;
extern volatile PTCSESTR _PTCSE @0x00001839;
#define PTCSE                           _PTCSE.Byte
#define PTCSE_PTCSE0                    _PTCSE.Bits.PTCSE0
#define PTCSE_PTCSE1                    _PTCSE.Bits.PTCSE1
#define PTCSE_PTCSE2                    _PTCSE.Bits.PTCSE2
#define PTCSE_PTCSE3                    _PTCSE.Bits.PTCSE3
#define PTCSE_PTCSE4                    _PTCSE.Bits.PTCSE4
#define PTCSE_PTCSE5                    _PTCSE.Bits.PTCSE5
#define PTCSE_PTCSE6                    _PTCSE.Bits.PTCSE6
#define PTCSE_PTCSE7                    _PTCSE.Bits.PTCSE7

#define PTCSE_PTCSE0_MASK               1U
#define PTCSE_PTCSE1_MASK               2U
#define PTCSE_PTCSE2_MASK               4U
#define PTCSE_PTCSE3_MASK               8U
#define PTCSE_PTCSE4_MASK               16U
#define PTCSE_PTCSE5_MASK               32U
#define PTCSE_PTCSE6_MASK               64U
#define PTCSE_PTCSE7_MASK               128U


/*** PTCDS - Port C Drive Strength Selection Register; 0x0000183A ***/
typedef union {
  byte Byte;
  struct {
    byte PTCDS0      :1;                                       /* Output Drive Strength Selection for Port C Bit 0 */
    byte PTCDS1      :1;                                       /* Output Drive Strength Selection for Port C Bit 1 */
    byte PTCDS2      :1;                                       /* Output Drive Strength Selection for Port C Bit 2 */
    byte PTCDS3      :1;                                       /* Output Drive Strength Selection for Port C Bit 3 */
    byte PTCDS4      :1;                                       /* Output Drive Strength Selection for Port C Bit 4 */
    byte PTCDS5      :1;                                       /* Output Drive Strength Selection for Port C Bit 5 */
    byte PTCDS6      :1;                                       /* Output Drive Strength Selection for Port C Bit 6 */
    byte PTCDS7      :1;                                       /* Output Drive Strength Selection for Port C Bit 7 */
  } Bits;
} PTCDSSTR;
extern volatile PTCDSSTR _PTCDS @0x0000183A;
#define PTCDS                           _PTCDS.Byte
#define PTCDS_PTCDS0                    _PTCDS.Bits.PTCDS0
#define PTCDS_PTCDS1                    _PTCDS.Bits.PTCDS1
#define PTCDS_PTCDS2                    _PTCDS.Bits.PTCDS2
#define PTCDS_PTCDS3                    _PTCDS.Bits.PTCDS3
#define PTCDS_PTCDS4                    _PTCDS.Bits.PTCDS4
#define PTCDS_PTCDS5                    _PTCDS.Bits.PTCDS5
#define PTCDS_PTCDS6                    _PTCDS.Bits.PTCDS6
#define PTCDS_PTCDS7                    _PTCDS.Bits.PTCDS7

#define PTCDS_PTCDS0_MASK               1U
#define PTCDS_PTCDS1_MASK               2U
#define PTCDS_PTCDS2_MASK               4U
#define PTCDS_PTCDS3_MASK               8U
#define PTCDS_PTCDS4_MASK               16U
#define PTCDS_PTCDS5_MASK               32U
#define PTCDS_PTCDS6_MASK               64U
#define PTCDS_PTCDS7_MASK               128U


/*** PTDPE - Port D Pull Enable Register; 0x0000183C ***/
typedef union {
  byte Byte;
  struct {
    byte PTDPE0      :1;                                       /* Internal Pull Enable for Port D Bit 0 */
    byte PTDPE1      :1;                                       /* Internal Pull Enable for Port D Bit 1 */
    byte PTDPE2      :1;                                       /* Internal Pull Enable for Port D Bit 2 */
    byte PTDPE3      :1;                                       /* Internal Pull Enable for Port D Bit 3 */
    byte PTDPE4      :1;                                       /* Internal Pull Enable for Port D Bit 4 */
    byte PTDPE5      :1;                                       /* Internal Pull Enable for Port D Bit 5 */
    byte PTDPE6      :1;                                       /* Internal Pull Enable for Port D Bit 6 */
    byte PTDPE7      :1;                                       /* Internal Pull Enable for Port D Bit 7 */
  } Bits;
} PTDPESTR;
extern volatile PTDPESTR _PTDPE @0x0000183C;
#define PTDPE                           _PTDPE.Byte
#define PTDPE_PTDPE0                    _PTDPE.Bits.PTDPE0
#define PTDPE_PTDPE1                    _PTDPE.Bits.PTDPE1
#define PTDPE_PTDPE2                    _PTDPE.Bits.PTDPE2
#define PTDPE_PTDPE3                    _PTDPE.Bits.PTDPE3
#define PTDPE_PTDPE4                    _PTDPE.Bits.PTDPE4
#define PTDPE_PTDPE5                    _PTDPE.Bits.PTDPE5
#define PTDPE_PTDPE6                    _PTDPE.Bits.PTDPE6
#define PTDPE_PTDPE7                    _PTDPE.Bits.PTDPE7

#define PTDPE_PTDPE0_MASK               1U
#define PTDPE_PTDPE1_MASK               2U
#define PTDPE_PTDPE2_MASK               4U
#define PTDPE_PTDPE3_MASK               8U
#define PTDPE_PTDPE4_MASK               16U
#define PTDPE_PTDPE5_MASK               32U
#define PTDPE_PTDPE6_MASK               64U
#define PTDPE_PTDPE7_MASK               128U


/*** PTDSE - Port D Slew Rate Enable Register; 0x0000183D ***/
typedef union {
  byte Byte;
  struct {
    byte PTDSE0      :1;                                       /* Output Slew Rate Enable for Port D Bit 0 */
    byte PTDSE1      :1;                                       /* Output Slew Rate Enable for Port D Bit 1 */
    byte PTDSE2      :1;                                       /* Output Slew Rate Enable for Port D Bit 2 */
    byte PTDSE3      :1;                                       /* Output Slew Rate Enable for Port D Bit 3 */
    byte PTDSE4      :1;                                       /* Output Slew Rate Enable for Port D Bit 4 */
    byte PTDSE5      :1;                                       /* Output Slew Rate Enable for Port D Bit 5 */
    byte PTDSE6      :1;                                       /* Output Slew Rate Enable for Port D Bit 6 */
    byte PTDSE7      :1;                                       /* Output Slew Rate Enable for Port D Bit 7 */
  } Bits;
} PTDSESTR;
extern volatile PTDSESTR _PTDSE @0x0000183D;
#define PTDSE                           _PTDSE.Byte
#define PTDSE_PTDSE0                    _PTDSE.Bits.PTDSE0
#define PTDSE_PTDSE1                    _PTDSE.Bits.PTDSE1
#define PTDSE_PTDSE2                    _PTDSE.Bits.PTDSE2
#define PTDSE_PTDSE3                    _PTDSE.Bits.PTDSE3
#define PTDSE_PTDSE4                    _PTDSE.Bits.PTDSE4
#define PTDSE_PTDSE5                    _PTDSE.Bits.PTDSE5
#define PTDSE_PTDSE6                    _PTDSE.Bits.PTDSE6
#define PTDSE_PTDSE7                    _PTDSE.Bits.PTDSE7

#define PTDSE_PTDSE0_MASK               1U
#define PTDSE_PTDSE1_MASK               2U
#define PTDSE_PTDSE2_MASK               4U
#define PTDSE_PTDSE3_MASK               8U
#define PTDSE_PTDSE4_MASK               16U
#define PTDSE_PTDSE5_MASK               32U
#define PTDSE_PTDSE6_MASK               64U
#define PTDSE_PTDSE7_MASK               128U


/*** PTDDS - Port D Drive Strength Selection Register; 0x0000183E ***/
typedef union {
  byte Byte;
  struct {
    byte PTDDS0      :1;                                       /* Output Drive Strength Selection for Port D Bit 0 */
    byte PTDDS1      :1;                                       /* Output Drive Strength Selection for Port D Bit 1 */
    byte PTDDS2      :1;                                       /* Output Drive Strength Selection for Port D Bit 2 */
    byte PTDDS3      :1;                                       /* Output Drive Strength Selection for Port D Bit 3 */
    byte PTDDS4      :1;                                       /* Output Drive Strength Selection for Port D Bit 4 */
    byte PTDDS5      :1;                                       /* Output Drive Strength Selection for Port D Bit 5 */
    byte PTDDS6      :1;                                       /* Output Drive Strength Selection for Port D Bit 6 */
    byte PTDDS7      :1;                                       /* Output Drive Strength Selection for Port D Bit 7 */
  } Bits;
} PTDDSSTR;
extern volatile PTDDSSTR _PTDDS @0x0000183E;
#define PTDDS                           _PTDDS.Byte
#define PTDDS_PTDDS0                    _PTDDS.Bits.PTDDS0
#define PTDDS_PTDDS1                    _PTDDS.Bits.PTDDS1
#define PTDDS_PTDDS2                    _PTDDS.Bits.PTDDS2
#define PTDDS_PTDDS3                    _PTDDS.Bits.PTDDS3
#define PTDDS_PTDDS4                    _PTDDS.Bits.PTDDS4
#define PTDDS_PTDDS5                    _PTDDS.Bits.PTDDS5
#define PTDDS_PTDDS6                    _PTDDS.Bits.PTDDS6
#define PTDDS_PTDDS7                    _PTDDS.Bits.PTDDS7

#define PTDDS_PTDDS0_MASK               1U
#define PTDDS_PTDDS1_MASK               2U
#define PTDDS_PTDDS2_MASK               4U
#define PTDDS_PTDDS3_MASK               8U
#define PTDDS_PTDDS4_MASK               16U
#define PTDDS_PTDDS5_MASK               32U
#define PTDDS_PTDDS6_MASK               64U
#define PTDDS_PTDDS7_MASK               128U


/*** PHY_T1CMP0 - Event Timer Comparator 1 Register 0; 0x00001840 ***/
typedef union {
  byte Byte;
} PHY_T1CMP0STR;
extern volatile PHY_T1CMP0STR _PHY_T1CMP0 @0x00001840;
#define PHY_T1CMP0                      _PHY_T1CMP0.Byte
/* PHY_T1CMP_ARR: Access 3 PHY_T1CMPx registers in an array */
#define PHY_T1CMP_ARR                   ((volatile byte * __far) &PHY_T1CMP0)


/*** PHY_T1CMP1 - Event Timer Comparator 1 Register 1; 0x00001841 ***/
typedef union {
  byte Byte;
} PHY_T1CMP1STR;
extern volatile PHY_T1CMP1STR _PHY_T1CMP1 @0x00001841;
#define PHY_T1CMP1                      _PHY_T1CMP1.Byte


/*** PHY_T1CMP2 - Event Timer Comparator 1 Register 2; 0x00001842 ***/
typedef union {
  byte Byte;
} PHY_T1CMP2STR;
extern volatile PHY_T1CMP2STR _PHY_T1CMP2 @0x00001842;
#define PHY_T1CMP2                      _PHY_T1CMP2.Byte


/*** PHY_T2CMP0 - Event Timer Comparator 2 Register 0; 0x00001843 ***/
typedef union {
  byte Byte;
} PHY_T2CMP0STR;
extern volatile PHY_T2CMP0STR _PHY_T2CMP0 @0x00001843;
#define PHY_T2CMP0                      _PHY_T2CMP0.Byte
/* PHY_T2CMP_ARR: Access 3 PHY_T2CMPx registers in an array */
#define PHY_T2CMP_ARR                   ((volatile byte * __far) &PHY_T2CMP0)


/*** PHY_T2CMP1 - Event Timer Comparator 2 Register 1; 0x00001844 ***/
typedef union {
  byte Byte;
} PHY_T2CMP1STR;
extern volatile PHY_T2CMP1STR _PHY_T2CMP1 @0x00001844;
#define PHY_T2CMP1                      _PHY_T2CMP1.Byte


/*** PHY_T2CMP2 - Event Timer Comparator 2 Register 2; 0x00001845 ***/
typedef union {
  byte Byte;
} PHY_T2CMP2STR;
extern volatile PHY_T2CMP2STR _PHY_T2CMP2 @0x00001845;
#define PHY_T2CMP2                      _PHY_T2CMP2.Byte


/*** PHY_T4CMP0 - Event Timer Comparator 4 Register 0; 0x00001846 ***/
typedef union {
  byte Byte;
} PHY_T4CMP0STR;
extern volatile PHY_T4CMP0STR _PHY_T4CMP0 @0x00001846;
#define PHY_T4CMP0                      _PHY_T4CMP0.Byte
/* PHY_T4CMP_ARR: Access 3 PHY_T4CMPx registers in an array */
#define PHY_T4CMP_ARR                   ((volatile byte * __far) &PHY_T4CMP0)


/*** PHY_T4CMP1 - Event Timer Comparator 4 Register 1; 0x00001847 ***/
typedef union {
  byte Byte;
} PHY_T4CMP1STR;
extern volatile PHY_T4CMP1STR _PHY_T4CMP1 @0x00001847;
#define PHY_T4CMP1                      _PHY_T4CMP1.Byte


/*** PHY_T4CMP2 - Event Timer Comparator 4 Register 2; 0x00001848 ***/
typedef union {
  byte Byte;
} PHY_T4CMP2STR;
extern volatile PHY_T4CMP2STR _PHY_T4CMP2 @0x00001848;
#define PHY_T4CMP2                      _PHY_T4CMP2.Byte


/*** PHY_LO1_FRAC0 - LO1 FracN Numerator Value Register 0; 0x00001849 ***/
typedef union {
  byte Byte;
} PHY_LO1_FRAC0STR;
extern volatile PHY_LO1_FRAC0STR _PHY_LO1_FRAC0 @0x00001849;
#define PHY_LO1_FRAC0                   _PHY_LO1_FRAC0.Byte
/* PHY_LO1_FRAC_ARR: Access 2 PHY_LO1_FRACx registers in an array */
#define PHY_LO1_FRAC_ARR                ((volatile byte * __far) &PHY_LO1_FRAC0)


/*** PHY_LO1_FRAC1 - LO1 FracN Numerator Value Register 1; 0x0000184A ***/
typedef union {
  byte Byte;
} PHY_LO1_FRAC1STR;
extern volatile PHY_LO1_FRAC1STR _PHY_LO1_FRAC1 @0x0000184A;
#define PHY_LO1_FRAC1                   _PHY_LO1_FRAC1.Byte


/*** PHY_LO1_INT - LO1 Integer Register; 0x0000184B ***/
typedef union {
  byte Byte;
} PHY_LO1_INTSTR;
extern volatile PHY_LO1_INTSTR _PHY_LO1_INT @0x0000184B;
#define PHY_LO1_INT                     _PHY_LO1_INT.Byte


/*** PHY_PA_PWR_CNTL - Power Amplifier (PA) Power Control Register; 0x0000184C ***/
typedef union {
  byte Byte;
} PHY_PA_PWR_CNTLSTR;
extern volatile PHY_PA_PWR_CNTLSTR _PHY_PA_PWR_CNTL @0x0000184C;
#define PHY_PA_PWR_CNTL                 _PHY_PA_PWR_CNTL.Byte


/*** PHY_MACLONGADDRS0 - MAC Long Address Register 0; 0x0000184D ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS0STR;
extern volatile PHY_MACLONGADDRS0STR _PHY_MACLONGADDRS0 @0x0000184D;
#define PHY_MACLONGADDRS0               _PHY_MACLONGADDRS0.Byte
/* PHY_MACLONGADDRS_ARR: Access 8 PHY_MACLONGADDRSx registers in an array */
#define PHY_MACLONGADDRS_ARR            ((volatile byte * __far) &PHY_MACLONGADDRS0)


/*** PHY_MACLONGADDRS1 - MAC Long Address Register 1; 0x0000184E ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS1STR;
extern volatile PHY_MACLONGADDRS1STR _PHY_MACLONGADDRS1 @0x0000184E;
#define PHY_MACLONGADDRS1               _PHY_MACLONGADDRS1.Byte


/*** PHY_MACLONGADDRS2 - MAC Long Address Register 2; 0x0000184F ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS2STR;
extern volatile PHY_MACLONGADDRS2STR _PHY_MACLONGADDRS2 @0x0000184F;
#define PHY_MACLONGADDRS2               _PHY_MACLONGADDRS2.Byte


/*** PHY_MACLONGADDRS3 - MAC Long Address Register 3; 0x00001850 ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS3STR;
extern volatile PHY_MACLONGADDRS3STR _PHY_MACLONGADDRS3 @0x00001850;
#define PHY_MACLONGADDRS3               _PHY_MACLONGADDRS3.Byte


/*** PHY_MACLONGADDRS4 - MAC Long Address Register 4; 0x00001851 ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS4STR;
extern volatile PHY_MACLONGADDRS4STR _PHY_MACLONGADDRS4 @0x00001851;
#define PHY_MACLONGADDRS4               _PHY_MACLONGADDRS4.Byte


/*** PHY_MACLONGADDRS5 - MAC Long Address Register 5; 0x00001852 ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS5STR;
extern volatile PHY_MACLONGADDRS5STR _PHY_MACLONGADDRS5 @0x00001852;
#define PHY_MACLONGADDRS5               _PHY_MACLONGADDRS5.Byte


/*** PHY_MACLONGADDRS6 - MAC Long Address Register 6; 0x00001853 ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS6STR;
extern volatile PHY_MACLONGADDRS6STR _PHY_MACLONGADDRS6 @0x00001853;
#define PHY_MACLONGADDRS6               _PHY_MACLONGADDRS6.Byte


/*** PHY_MACLONGADDRS7 - MAC Long Address Register 7; 0x00001854 ***/
typedef union {
  byte Byte;
} PHY_MACLONGADDRS7STR;
extern volatile PHY_MACLONGADDRS7STR _PHY_MACLONGADDRS7 @0x00001854;
#define PHY_MACLONGADDRS7               _PHY_MACLONGADDRS7.Byte


/*** PHY_MAXFRAMELENGTH - Max Frame Length Register; 0x00001855 ***/
typedef union {
  byte Byte;
} PHY_MAXFRAMELENGTHSTR;
extern volatile PHY_MAXFRAMELENGTHSTR _PHY_MAXFRAMELENGTH @0x00001855;
#define PHY_MAXFRAMELENGTH              _PHY_MAXFRAMELENGTH.Byte


/*** PHY_RX_FRAME_FILTER - Receive Frame Filter; 0x00001856 ***/
typedef union {
  byte Byte;
  struct {
    byte BEACON_FT   :1;                                       /* BEACON_FT */
    byte DATA_FT     :1;                                       /* DATA_FT */
    byte ACK_FT      :1;                                       /* ACK_FT */
    byte CMD_FT      :1;                                       /* CMD_FT */
    byte NS_FT       :1;                                       /* NOT_SPECIFIED_FT */
    byte             :1; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PHY_RX_FRAME_FILTERSTR;
extern volatile PHY_RX_FRAME_FILTERSTR _PHY_RX_FRAME_FILTER @0x00001856;
#define PHY_RX_FRAME_FILTER             _PHY_RX_FRAME_FILTER.Byte
#define PHY_RX_FRAME_FILTER_BEACON_FT   _PHY_RX_FRAME_FILTER.Bits.BEACON_FT
#define PHY_RX_FRAME_FILTER_DATA_FT     _PHY_RX_FRAME_FILTER.Bits.DATA_FT
#define PHY_RX_FRAME_FILTER_ACK_FT      _PHY_RX_FRAME_FILTER.Bits.ACK_FT
#define PHY_RX_FRAME_FILTER_CMD_FT      _PHY_RX_FRAME_FILTER.Bits.CMD_FT
#define PHY_RX_FRAME_FILTER_NS_FT       _PHY_RX_FRAME_FILTER.Bits.NS_FT

#define PHY_RX_FRAME_FILTER_BEACON_FT_MASK 1U
#define PHY_RX_FRAME_FILTER_DATA_FT_MASK 2U
#define PHY_RX_FRAME_FILTER_ACK_FT_MASK 4U
#define PHY_RX_FRAME_FILTER_CMD_FT_MASK 8U
#define PHY_RX_FRAME_FILTER_NS_FT_MASK  16U


/*** PHY_MACFRAMEVER - ; 0x00001857 ***/
typedef union {
  byte Byte;
  struct {
    byte FRM_VER0    :1;                                       /* Frame Version Selection, bit 0, bit 0 */
    byte FRM_VER1    :1;                                       /* Frame Version Selection, bit 0, bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte TMR_PRESCALE0 :1;                                     /* Timer Prescaler Select, bit 0, bit 0 */
    byte TMR_PRESCALE1 :1;                                     /* Timer Prescaler Select, bit 0, bit 1 */
    byte TMR_PRESCALE2 :1;                                     /* Timer Prescaler Select, bit 0, bit 2 */
  } Bits;
  struct {
    byte grpFRM_VER :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpTMR_PRESCALE :3;
  } MergedBits;
} PHY_MACFRAMEVERSTR;
extern volatile PHY_MACFRAMEVERSTR _PHY_MACFRAMEVER @0x00001857;
#define PHY_MACFRAMEVER                 _PHY_MACFRAMEVER.Byte
#define PHY_MACFRAMEVER_FRM_VER0        _PHY_MACFRAMEVER.Bits.FRM_VER0
#define PHY_MACFRAMEVER_FRM_VER1        _PHY_MACFRAMEVER.Bits.FRM_VER1
#define PHY_MACFRAMEVER_TMR_PRESCALE0   _PHY_MACFRAMEVER.Bits.TMR_PRESCALE0
#define PHY_MACFRAMEVER_TMR_PRESCALE1   _PHY_MACFRAMEVER.Bits.TMR_PRESCALE1
#define PHY_MACFRAMEVER_TMR_PRESCALE2   _PHY_MACFRAMEVER.Bits.TMR_PRESCALE2
#define PHY_MACFRAMEVER_FRM_VER         _PHY_MACFRAMEVER.MergedBits.grpFRM_VER
#define PHY_MACFRAMEVER_TMR_PRESCALE    _PHY_MACFRAMEVER.MergedBits.grpTMR_PRESCALE

#define PHY_MACFRAMEVER_FRM_VER0_MASK   1U
#define PHY_MACFRAMEVER_FRM_VER1_MASK   2U
#define PHY_MACFRAMEVER_TMR_PRESCALE0_MASK 32U
#define PHY_MACFRAMEVER_TMR_PRESCALE1_MASK 64U
#define PHY_MACFRAMEVER_TMR_PRESCALE2_MASK 128U
#define PHY_MACFRAMEVER_FRM_VER_MASK    3U
#define PHY_MACFRAMEVER_FRM_VER_BITNUM  0U
#define PHY_MACFRAMEVER_TMR_PRESCALE_MASK 224U
#define PHY_MACFRAMEVER_TMR_PRESCALE_BITNUM 5U


/*** PHY_CCA_THRESHOLD - CCA Energy Threshold; 0x00001858 ***/
typedef union {
  byte Byte;
} PHY_CCA_THRESHOLDSTR;
extern volatile PHY_CCA_THRESHOLDSTR _PHY_CCA_THRESHOLD @0x00001858;
#define PHY_CCA_THRESHOLD               _PHY_CCA_THRESHOLD.Byte


/*** PHY_CCA_OFFSET_CMP - CCA Power Compensation; 0x00001859 ***/
typedef union {
  byte Byte;
} PHY_CCA_OFFSET_CMPSTR;
extern volatile PHY_CCA_OFFSET_CMPSTR _PHY_CCA_OFFSET_CMP @0x00001859;
#define PHY_CCA_OFFSET_CMP              _PHY_CCA_OFFSET_CMP.Byte


/*** PHY_FSM - Finite State Machine Register; 0x0000185A ***/
typedef union {
  byte Byte;
  struct {
    byte FSM         :6; 
    byte             :1; 
    byte             :1; 
  } Bits;
} PHY_FSMSTR;
extern volatile PHY_FSMSTR _PHY_FSM @0x0000185A;
#define PHY_FSM                         _PHY_FSM.Byte
#define PHY_FSM_FSM                     _PHY_FSM.Bits.FSM

#define PHY_FSM_FSM_MASK                63U
#define PHY_FSM_FSM_BITNUM              0U


/*** PHY_INDIRECT_ACCESS_INDEX - Transceiver Indirect Access Index Register; 0x0000185B ***/
typedef union {
  byte Byte;
} PHY_INDIRECT_ACCESS_INDEXSTR;
extern volatile PHY_INDIRECT_ACCESS_INDEXSTR _PHY_INDIRECT_ACCESS_INDEX @0x0000185B;
#define PHY_INDIRECT_ACCESS_INDEX       _PHY_INDIRECT_ACCESS_INDEX.Byte


/*** PHY_INDIRECT_ACCESS_DATA - Transceiver Indirect Access Data Register; 0x0000185C ***/
typedef union {
  byte Byte;
} PHY_INDIRECT_ACCESS_DATASTR;
extern volatile PHY_INDIRECT_ACCESS_DATASTR _PHY_INDIRECT_ACCESS_DATA @0x0000185C;
#define PHY_INDIRECT_ACCESS_DATA        _PHY_INDIRECT_ACCESS_DATA.Byte


/*** TPM4SC - TPM4 Status and Control Register; 0x00001860 ***/
typedef union {
  byte Byte;
  struct {
    byte PS0         :1;                                       /* Prescale Divisor Select Bit 0 */
    byte PS1         :1;                                       /* Prescale Divisor Select Bit 1 */
    byte PS2         :1;                                       /* Prescale Divisor Select Bit 2 */
    byte CLKSA       :1;                                       /* Clock Source Select A */
    byte CLKSB       :1;                                       /* Clock Source Select B */
    byte CPWMS       :1;                                       /* Center-Aligned PWM Select */
    byte TOIE        :1;                                       /* Timer Overflow Interrupt Enable */
    byte TOF         :1;                                       /* Timer Overflow Flag */
  } Bits;
  struct {
    byte grpPS   :3;
    byte grpCLKSx :2;
    byte         :1;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM4SCSTR;
extern volatile TPM4SCSTR _TPM4SC @0x00001860;
#define TPM4SC                          _TPM4SC.Byte
#define TPM4SC_PS0                      _TPM4SC.Bits.PS0
#define TPM4SC_PS1                      _TPM4SC.Bits.PS1
#define TPM4SC_PS2                      _TPM4SC.Bits.PS2
#define TPM4SC_CLKSA                    _TPM4SC.Bits.CLKSA
#define TPM4SC_CLKSB                    _TPM4SC.Bits.CLKSB
#define TPM4SC_CPWMS                    _TPM4SC.Bits.CPWMS
#define TPM4SC_TOIE                     _TPM4SC.Bits.TOIE
#define TPM4SC_TOF                      _TPM4SC.Bits.TOF
#define TPM4SC_PS                       _TPM4SC.MergedBits.grpPS
#define TPM4SC_CLKSx                    _TPM4SC.MergedBits.grpCLKSx

#define TPM4SC_PS0_MASK                 1U
#define TPM4SC_PS1_MASK                 2U
#define TPM4SC_PS2_MASK                 4U
#define TPM4SC_CLKSA_MASK               8U
#define TPM4SC_CLKSB_MASK               16U
#define TPM4SC_CPWMS_MASK               32U
#define TPM4SC_TOIE_MASK                64U
#define TPM4SC_TOF_MASK                 128U
#define TPM4SC_PS_MASK                  7U
#define TPM4SC_PS_BITNUM                0U
#define TPM4SC_CLKSx_MASK               24U
#define TPM4SC_CLKSx_BITNUM             3U


/*** TPM4CNT - TPM4 Timer Counter Register; 0x00001861 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM4CNTH - TPM4 Timer Counter Register High; 0x00001861 ***/
    union {
      byte Byte;
    } TPM4CNTHSTR;
    #define TPM4CNTH                    _TPM4CNT.Overlap_STR.TPM4CNTHSTR.Byte
    

    /*** TPM4CNTL - TPM4 Timer Counter Register Low; 0x00001862 ***/
    union {
      byte Byte;
    } TPM4CNTLSTR;
    #define TPM4CNTL                    _TPM4CNT.Overlap_STR.TPM4CNTLSTR.Byte
    
  } Overlap_STR;

} TPM4CNTSTR;
extern volatile TPM4CNTSTR _TPM4CNT @0x00001861;
#define TPM4CNT                         _TPM4CNT.Word


/*** TPM4MOD - TPM4 Timer Counter Modulo Register; 0x00001863 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM4MODH - TPM4 Timer Counter Modulo Register High; 0x00001863 ***/
    union {
      byte Byte;
    } TPM4MODHSTR;
    #define TPM4MODH                    _TPM4MOD.Overlap_STR.TPM4MODHSTR.Byte
    

    /*** TPM4MODL - TPM4 Timer Counter Modulo Register Low; 0x00001864 ***/
    union {
      byte Byte;
    } TPM4MODLSTR;
    #define TPM4MODL                    _TPM4MOD.Overlap_STR.TPM4MODLSTR.Byte
    
  } Overlap_STR;

} TPM4MODSTR;
extern volatile TPM4MODSTR _TPM4MOD @0x00001863;
#define TPM4MOD                         _TPM4MOD.Word


/*** TPM4C0SC - TPM4 Timer Channel 0 Status and Control Register; 0x00001865 ***/
typedef union {
  byte Byte;
  struct {
    byte             :1; 
    byte             :1; 
    byte ELS0A       :1;                                       /* Edge/Level Select Bit A */
    byte ELS0B       :1;                                       /* Edge/Level Select Bit B */
    byte MS0A        :1;                                       /* Mode Select A for TPM Channel 0 */
    byte MS0B        :1;                                       /* Mode Select B for TPM Channel 0 */
    byte CH0IE       :1;                                       /* Channel 0 Interrupt Enable */
    byte CH0F        :1;                                       /* Channel 0 Flag */
  } Bits;
  struct {
    byte         :1;
    byte         :1;
    byte grpELS0x :2;
    byte grpMS0x :2;
    byte         :1;
    byte         :1;
  } MergedBits;
} TPM4C0SCSTR;
extern volatile TPM4C0SCSTR _TPM4C0SC @0x00001865;
#define TPM4C0SC                        _TPM4C0SC.Byte
#define TPM4C0SC_ELS0A                  _TPM4C0SC.Bits.ELS0A
#define TPM4C0SC_ELS0B                  _TPM4C0SC.Bits.ELS0B
#define TPM4C0SC_MS0A                   _TPM4C0SC.Bits.MS0A
#define TPM4C0SC_MS0B                   _TPM4C0SC.Bits.MS0B
#define TPM4C0SC_CH0IE                  _TPM4C0SC.Bits.CH0IE
#define TPM4C0SC_CH0F                   _TPM4C0SC.Bits.CH0F
#define TPM4C0SC_ELS0x                  _TPM4C0SC.MergedBits.grpELS0x
#define TPM4C0SC_MS0x                   _TPM4C0SC.MergedBits.grpMS0x

#define TPM4C0SC_ELS0A_MASK             4U
#define TPM4C0SC_ELS0B_MASK             8U
#define TPM4C0SC_MS0A_MASK              16U
#define TPM4C0SC_MS0B_MASK              32U
#define TPM4C0SC_CH0IE_MASK             64U
#define TPM4C0SC_CH0F_MASK              128U
#define TPM4C0SC_ELS0x_MASK             12U
#define TPM4C0SC_ELS0x_BITNUM           2U
#define TPM4C0SC_MS0x_MASK              48U
#define TPM4C0SC_MS0x_BITNUM            4U


/*** TPM4C0V - TPM4 Timer Channel 0 Value Register; 0x00001866 ***/
typedef union {
  word Word;
   /* Overlapped registers: */
  struct {
    /*** TPM4C0VH - TPM4 Timer Channel 0 Value Register High; 0x00001866 ***/
    union {
      byte Byte;
    } TPM4C0VHSTR;
    #define TPM4C0VH                    _TPM4C0V.Overlap_STR.TPM4C0VHSTR.Byte
    

    /*** TPM4C0VL - TPM4 Timer Channel 0 Value Register Low; 0x00001867 ***/
    union {
      byte Byte;
    } TPM4C0VLSTR;
    #define TPM4C0VL                    _TPM4C0V.Overlap_STR.TPM4C0VLSTR.Byte
    
  } Overlap_STR;

} TPM4C0VSTR;
extern volatile TPM4C0VSTR _TPM4C0V @0x00001866;
#define TPM4C0V                         _TPM4C0V.Word


/*** NVBACKKEY0 - Backdoor Comparison Key 0; 0x0000FFB0 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 0 Bits, bit 7 */
  } Bits;
} NVBACKKEY0STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
#define _NVBACKKEY0 (*(const NVBACKKEY0STR * __far)0x0000FFB0)
#define NVBACKKEY0                      _NVBACKKEY0.Byte
#define NVBACKKEY0_KEY0                 _NVBACKKEY0.Bits.KEY0
#define NVBACKKEY0_KEY1                 _NVBACKKEY0.Bits.KEY1
#define NVBACKKEY0_KEY2                 _NVBACKKEY0.Bits.KEY2
#define NVBACKKEY0_KEY3                 _NVBACKKEY0.Bits.KEY3
#define NVBACKKEY0_KEY4                 _NVBACKKEY0.Bits.KEY4
#define NVBACKKEY0_KEY5                 _NVBACKKEY0.Bits.KEY5
#define NVBACKKEY0_KEY6                 _NVBACKKEY0.Bits.KEY6
#define NVBACKKEY0_KEY7                 _NVBACKKEY0.Bits.KEY7
/* NVBACKKEY_ARR: Access 8 NVBACKKEYx registers in an array */
#define NVBACKKEY_ARR                   ((volatile byte * __far) &NVBACKKEY0)

#define NVBACKKEY0_KEY0_MASK            1U
#define NVBACKKEY0_KEY1_MASK            2U
#define NVBACKKEY0_KEY2_MASK            4U
#define NVBACKKEY0_KEY3_MASK            8U
#define NVBACKKEY0_KEY4_MASK            16U
#define NVBACKKEY0_KEY5_MASK            32U
#define NVBACKKEY0_KEY6_MASK            64U
#define NVBACKKEY0_KEY7_MASK            128U


/*** NVBACKKEY1 - Backdoor Comparison Key 1; 0x0000FFB1 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 1 Bits, bit 7 */
  } Bits;
} NVBACKKEY1STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
#define _NVBACKKEY1 (*(const NVBACKKEY1STR * __far)0x0000FFB1)
#define NVBACKKEY1                      _NVBACKKEY1.Byte
#define NVBACKKEY1_KEY0                 _NVBACKKEY1.Bits.KEY0
#define NVBACKKEY1_KEY1                 _NVBACKKEY1.Bits.KEY1
#define NVBACKKEY1_KEY2                 _NVBACKKEY1.Bits.KEY2
#define NVBACKKEY1_KEY3                 _NVBACKKEY1.Bits.KEY3
#define NVBACKKEY1_KEY4                 _NVBACKKEY1.Bits.KEY4
#define NVBACKKEY1_KEY5                 _NVBACKKEY1.Bits.KEY5
#define NVBACKKEY1_KEY6                 _NVBACKKEY1.Bits.KEY6
#define NVBACKKEY1_KEY7                 _NVBACKKEY1.Bits.KEY7

#define NVBACKKEY1_KEY0_MASK            1U
#define NVBACKKEY1_KEY1_MASK            2U
#define NVBACKKEY1_KEY2_MASK            4U
#define NVBACKKEY1_KEY3_MASK            8U
#define NVBACKKEY1_KEY4_MASK            16U
#define NVBACKKEY1_KEY5_MASK            32U
#define NVBACKKEY1_KEY6_MASK            64U
#define NVBACKKEY1_KEY7_MASK            128U


/*** NVBACKKEY2 - Backdoor Comparison Key 2; 0x0000FFB2 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 2 Bits, bit 7 */
  } Bits;
} NVBACKKEY2STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
#define _NVBACKKEY2 (*(const NVBACKKEY2STR * __far)0x0000FFB2)
#define NVBACKKEY2                      _NVBACKKEY2.Byte
#define NVBACKKEY2_KEY0                 _NVBACKKEY2.Bits.KEY0
#define NVBACKKEY2_KEY1                 _NVBACKKEY2.Bits.KEY1
#define NVBACKKEY2_KEY2                 _NVBACKKEY2.Bits.KEY2
#define NVBACKKEY2_KEY3                 _NVBACKKEY2.Bits.KEY3
#define NVBACKKEY2_KEY4                 _NVBACKKEY2.Bits.KEY4
#define NVBACKKEY2_KEY5                 _NVBACKKEY2.Bits.KEY5
#define NVBACKKEY2_KEY6                 _NVBACKKEY2.Bits.KEY6
#define NVBACKKEY2_KEY7                 _NVBACKKEY2.Bits.KEY7

#define NVBACKKEY2_KEY0_MASK            1U
#define NVBACKKEY2_KEY1_MASK            2U
#define NVBACKKEY2_KEY2_MASK            4U
#define NVBACKKEY2_KEY3_MASK            8U
#define NVBACKKEY2_KEY4_MASK            16U
#define NVBACKKEY2_KEY5_MASK            32U
#define NVBACKKEY2_KEY6_MASK            64U
#define NVBACKKEY2_KEY7_MASK            128U


/*** NVBACKKEY3 - Backdoor Comparison Key 3; 0x0000FFB3 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 3 Bits, bit 7 */
  } Bits;
} NVBACKKEY3STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
#define _NVBACKKEY3 (*(const NVBACKKEY3STR * __far)0x0000FFB3)
#define NVBACKKEY3                      _NVBACKKEY3.Byte
#define NVBACKKEY3_KEY0                 _NVBACKKEY3.Bits.KEY0
#define NVBACKKEY3_KEY1                 _NVBACKKEY3.Bits.KEY1
#define NVBACKKEY3_KEY2                 _NVBACKKEY3.Bits.KEY2
#define NVBACKKEY3_KEY3                 _NVBACKKEY3.Bits.KEY3
#define NVBACKKEY3_KEY4                 _NVBACKKEY3.Bits.KEY4
#define NVBACKKEY3_KEY5                 _NVBACKKEY3.Bits.KEY5
#define NVBACKKEY3_KEY6                 _NVBACKKEY3.Bits.KEY6
#define NVBACKKEY3_KEY7                 _NVBACKKEY3.Bits.KEY7

#define NVBACKKEY3_KEY0_MASK            1U
#define NVBACKKEY3_KEY1_MASK            2U
#define NVBACKKEY3_KEY2_MASK            4U
#define NVBACKKEY3_KEY3_MASK            8U
#define NVBACKKEY3_KEY4_MASK            16U
#define NVBACKKEY3_KEY5_MASK            32U
#define NVBACKKEY3_KEY6_MASK            64U
#define NVBACKKEY3_KEY7_MASK            128U


/*** NVBACKKEY4 - Backdoor Comparison Key 4; 0x0000FFB4 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 4 Bits, bit 7 */
  } Bits;
} NVBACKKEY4STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
#define _NVBACKKEY4 (*(const NVBACKKEY4STR * __far)0x0000FFB4)
#define NVBACKKEY4                      _NVBACKKEY4.Byte
#define NVBACKKEY4_KEY0                 _NVBACKKEY4.Bits.KEY0
#define NVBACKKEY4_KEY1                 _NVBACKKEY4.Bits.KEY1
#define NVBACKKEY4_KEY2                 _NVBACKKEY4.Bits.KEY2
#define NVBACKKEY4_KEY3                 _NVBACKKEY4.Bits.KEY3
#define NVBACKKEY4_KEY4                 _NVBACKKEY4.Bits.KEY4
#define NVBACKKEY4_KEY5                 _NVBACKKEY4.Bits.KEY5
#define NVBACKKEY4_KEY6                 _NVBACKKEY4.Bits.KEY6
#define NVBACKKEY4_KEY7                 _NVBACKKEY4.Bits.KEY7

#define NVBACKKEY4_KEY0_MASK            1U
#define NVBACKKEY4_KEY1_MASK            2U
#define NVBACKKEY4_KEY2_MASK            4U
#define NVBACKKEY4_KEY3_MASK            8U
#define NVBACKKEY4_KEY4_MASK            16U
#define NVBACKKEY4_KEY5_MASK            32U
#define NVBACKKEY4_KEY6_MASK            64U
#define NVBACKKEY4_KEY7_MASK            128U


/*** NVBACKKEY5 - Backdoor Comparison Key 5; 0x0000FFB5 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 5 Bits, bit 7 */
  } Bits;
} NVBACKKEY5STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
#define _NVBACKKEY5 (*(const NVBACKKEY5STR * __far)0x0000FFB5)
#define NVBACKKEY5                      _NVBACKKEY5.Byte
#define NVBACKKEY5_KEY0                 _NVBACKKEY5.Bits.KEY0
#define NVBACKKEY5_KEY1                 _NVBACKKEY5.Bits.KEY1
#define NVBACKKEY5_KEY2                 _NVBACKKEY5.Bits.KEY2
#define NVBACKKEY5_KEY3                 _NVBACKKEY5.Bits.KEY3
#define NVBACKKEY5_KEY4                 _NVBACKKEY5.Bits.KEY4
#define NVBACKKEY5_KEY5                 _NVBACKKEY5.Bits.KEY5
#define NVBACKKEY5_KEY6                 _NVBACKKEY5.Bits.KEY6
#define NVBACKKEY5_KEY7                 _NVBACKKEY5.Bits.KEY7

#define NVBACKKEY5_KEY0_MASK            1U
#define NVBACKKEY5_KEY1_MASK            2U
#define NVBACKKEY5_KEY2_MASK            4U
#define NVBACKKEY5_KEY3_MASK            8U
#define NVBACKKEY5_KEY4_MASK            16U
#define NVBACKKEY5_KEY5_MASK            32U
#define NVBACKKEY5_KEY6_MASK            64U
#define NVBACKKEY5_KEY7_MASK            128U


/*** NVBACKKEY6 - Backdoor Comparison Key 6; 0x0000FFB6 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 6 Bits, bit 7 */
  } Bits;
} NVBACKKEY6STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
#define _NVBACKKEY6 (*(const NVBACKKEY6STR * __far)0x0000FFB6)
#define NVBACKKEY6                      _NVBACKKEY6.Byte
#define NVBACKKEY6_KEY0                 _NVBACKKEY6.Bits.KEY0
#define NVBACKKEY6_KEY1                 _NVBACKKEY6.Bits.KEY1
#define NVBACKKEY6_KEY2                 _NVBACKKEY6.Bits.KEY2
#define NVBACKKEY6_KEY3                 _NVBACKKEY6.Bits.KEY3
#define NVBACKKEY6_KEY4                 _NVBACKKEY6.Bits.KEY4
#define NVBACKKEY6_KEY5                 _NVBACKKEY6.Bits.KEY5
#define NVBACKKEY6_KEY6                 _NVBACKKEY6.Bits.KEY6
#define NVBACKKEY6_KEY7                 _NVBACKKEY6.Bits.KEY7

#define NVBACKKEY6_KEY0_MASK            1U
#define NVBACKKEY6_KEY1_MASK            2U
#define NVBACKKEY6_KEY2_MASK            4U
#define NVBACKKEY6_KEY3_MASK            8U
#define NVBACKKEY6_KEY4_MASK            16U
#define NVBACKKEY6_KEY5_MASK            32U
#define NVBACKKEY6_KEY6_MASK            64U
#define NVBACKKEY6_KEY7_MASK            128U


/*** NVBACKKEY7 - Backdoor Comparison Key 7; 0x0000FFB7 ***/
typedef union {
  byte Byte;
  struct {
    byte KEY0        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 0 */
    byte KEY1        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 1 */
    byte KEY2        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 2 */
    byte KEY3        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 3 */
    byte KEY4        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 4 */
    byte KEY5        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 5 */
    byte KEY6        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 6 */
    byte KEY7        :1;                                       /* Backdoor Comparison Key 7 Bits, bit 7 */
  } Bits;
} NVBACKKEY7STR;
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
#define _NVBACKKEY7 (*(const NVBACKKEY7STR * __far)0x0000FFB7)
#define NVBACKKEY7                      _NVBACKKEY7.Byte
#define NVBACKKEY7_KEY0                 _NVBACKKEY7.Bits.KEY0
#define NVBACKKEY7_KEY1                 _NVBACKKEY7.Bits.KEY1
#define NVBACKKEY7_KEY2                 _NVBACKKEY7.Bits.KEY2
#define NVBACKKEY7_KEY3                 _NVBACKKEY7.Bits.KEY3
#define NVBACKKEY7_KEY4                 _NVBACKKEY7.Bits.KEY4
#define NVBACKKEY7_KEY5                 _NVBACKKEY7.Bits.KEY5
#define NVBACKKEY7_KEY6                 _NVBACKKEY7.Bits.KEY6
#define NVBACKKEY7_KEY7                 _NVBACKKEY7.Bits.KEY7

#define NVBACKKEY7_KEY0_MASK            1U
#define NVBACKKEY7_KEY1_MASK            2U
#define NVBACKKEY7_KEY2_MASK            4U
#define NVBACKKEY7_KEY3_MASK            8U
#define NVBACKKEY7_KEY4_MASK            16U
#define NVBACKKEY7_KEY5_MASK            32U
#define NVBACKKEY7_KEY6_MASK            64U
#define NVBACKKEY7_KEY7_MASK            128U


/*** NVPROT - Nonvolatile Flash Protection Register; 0x0000FFBD ***/
typedef union {
  byte Byte;
  struct {
    byte FPOPEN      :1;                                       /* Flash Protection Open */
    byte FPS0        :1;                                       /* Flash Protection Size, bit 0 */
    byte FPS1        :1;                                       /* Flash Protection Size, bit 1 */
    byte FPS2        :1;                                       /* Flash Protection Size, bit 2 */
    byte FPS3        :1;                                       /* Flash Protection Size, bit 3 */
    byte FPS4        :1;                                       /* Flash Protection Size, bit 4 */
    byte FPS5        :1;                                       /* Flash Protection Size, bit 5 */
    byte FPS6        :1;                                       /* Flash Protection Size, bit 6 */
  } Bits;
  struct {
    byte         :1;
    byte grpFPS  :7;
  } MergedBits;
} NVPROTSTR;
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
#define _NVPROT (*(const NVPROTSTR * __far)0x0000FFBD)
#define NVPROT                          _NVPROT.Byte
#define NVPROT_FPOPEN                   _NVPROT.Bits.FPOPEN
#define NVPROT_FPS0                     _NVPROT.Bits.FPS0
#define NVPROT_FPS1                     _NVPROT.Bits.FPS1
#define NVPROT_FPS2                     _NVPROT.Bits.FPS2
#define NVPROT_FPS3                     _NVPROT.Bits.FPS3
#define NVPROT_FPS4                     _NVPROT.Bits.FPS4
#define NVPROT_FPS5                     _NVPROT.Bits.FPS5
#define NVPROT_FPS6                     _NVPROT.Bits.FPS6
#define NVPROT_FPS                      _NVPROT.MergedBits.grpFPS

#define NVPROT_FPOPEN_MASK              1U
#define NVPROT_FPS0_MASK                2U
#define NVPROT_FPS1_MASK                4U
#define NVPROT_FPS2_MASK                8U
#define NVPROT_FPS3_MASK                16U
#define NVPROT_FPS4_MASK                32U
#define NVPROT_FPS5_MASK                64U
#define NVPROT_FPS6_MASK                128U
#define NVPROT_FPS_MASK                 254U
#define NVPROT_FPS_BITNUM               1U


/*** NVOPT - Nonvolatile Flash Options Register; 0x0000FFBF ***/
typedef union {
  byte Byte;
  struct {
    byte SEC0        :1;                                       /* Flash Security Bit 0 */
    byte SEC1        :1;                                       /* Flash Security Bit 1 */
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte             :1; 
    byte KEYEN0      :1;                                       /* Backdoor Key Security Enable Bit 0 */
    byte KEYEN1      :1;                                       /* Backdoor Key Security Enable Bit 1 */
  } Bits;
  struct {
    byte grpSEC  :2;
    byte         :1;
    byte         :1;
    byte         :1;
    byte         :1;
    byte grpKEYEN :2;
  } MergedBits;
} NVOPTSTR;
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */
#define _NVOPT (*(const NVOPTSTR * __far)0x0000FFBF)
#define NVOPT                           _NVOPT.Byte
#define NVOPT_SEC0                      _NVOPT.Bits.SEC0
#define NVOPT_SEC1                      _NVOPT.Bits.SEC1
#define NVOPT_KEYEN0                    _NVOPT.Bits.KEYEN0
#define NVOPT_KEYEN1                    _NVOPT.Bits.KEYEN1
#define NVOPT_SEC                       _NVOPT.MergedBits.grpSEC
#define NVOPT_KEYEN                     _NVOPT.MergedBits.grpKEYEN

#define NVOPT_SEC0_MASK                 1U
#define NVOPT_SEC1_MASK                 2U
#define NVOPT_KEYEN0_MASK               64U
#define NVOPT_KEYEN1_MASK               128U
#define NVOPT_SEC_MASK                  3U
#define NVOPT_SEC_BITNUM                0U
#define NVOPT_KEYEN_MASK                192U
#define NVOPT_KEYEN_BITNUM              6U



/* Flash commands */
#define mBlank                          0x05
#define mBurstProg                      0x25
#define mByteProg                       0x20
#define mMassErase                      0x41
#define mPageErase                      0x40


/***********************************************/
/**   D E P R E C I A T E D   S Y M B O L S   **/
/***********************************************/
/* --------------------------------------------------------------------------- */
/* The following symbols were removed, because they were invalid or irrelevant */
/* --------------------------------------------------------------------------- */



/* **** 18.4.2011 14:39:59 */

#define VectorNumber_Viic                VectorNumber_Viicx
#define Viic                             Viicx
#define PHY_CNTRL2_TRCV_RST              PHY_CNTRL2_TRCV_MSK
#define PHY_CNTRL2_TRCV_RST_MASK         PHY_CNTRL2_TRCV_MSK_MASK
#define SPMSC1_BGBE                      This_symb_has_been_depreciated
#define SPMSC1_BGBE_MASK                 This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADFINE0         This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADFINE1         This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADCRS0          This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADCRS1          This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALFINE0         This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALFINE1         This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALCRS0          This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALCRS1          This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADFINE          This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADCRS           This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALFINE          This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALCRS           This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADFINE0_MASK    This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADFINE1_MASK    This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADCRS0_MASK     This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADCRS1_MASK     This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALFINE0_MASK    This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALFINE1_MASK    This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALCRS0_MASK     This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALCRS1_MASK     This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADFINE_MASK     This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADFINE_BITNUM   This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADCRS_MASK      This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PADCRS_BITNUM    This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALFINE_MASK     This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALFINE_BITNUM   This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALCRS_MASK      This_symb_has_been_depreciated
#define PHY_PA_PWR_CNTL_PALCRS_BITNUM    This_symb_has_been_depreciated
#define PHY_INDIRECT_ACCESS_REG          PHY_INDIRECT_ACCESS_DATA

/* **** 12.10.2012  */
#define FCDIV                           This_symb_has_been_depreciated
#define FCDIV_FDIV0                     This_symb_has_been_depreciated
#define FCDIV_FDIV1                     This_symb_has_been_depreciated
#define FCDIV_FDIV2                     This_symb_has_been_depreciated
#define FCDIV_FDIV3                     This_symb_has_been_depreciated
#define FCDIV_FDIV4                     This_symb_has_been_depreciated
#define FCDIV_FDIV5                     This_symb_has_been_depreciated
#define FCDIV_PRDIV8                    This_symb_has_been_depreciated
#define FCDIV_FDIVLD                    This_symb_has_been_depreciated
#define FCDIV_FDIV                      This_symb_has_been_depreciated

#define FCDIV_FDIV0_MASK                This_symb_has_been_depreciated
#define FCDIV_FDIV1_MASK                This_symb_has_been_depreciated
#define FCDIV_FDIV2_MASK                This_symb_has_been_depreciated
#define FCDIV_FDIV3_MASK                This_symb_has_been_depreciated
#define FCDIV_FDIV4_MASK                This_symb_has_been_depreciated
#define FCDIV_FDIV5_MASK                This_symb_has_been_depreciated
#define FCDIV_PRDIV8_MASK               This_symb_has_been_depreciated
#define FCDIV_FDIVLD_MASK               This_symb_has_been_depreciated
#define FCDIV_FDIV_MASK                 This_symb_has_been_depreciated
#define FCDIV_FDIV_BITNUM               This_symb_has_been_depreciated
#endif
/*lint -restore Enable MISRA rule (5.1) checking. */
/*lint -restore  +esym(960,18.4) +esym(961,19.7) Enable MISRA rule (1.1,18.4,6.4,19.7) checking. */
