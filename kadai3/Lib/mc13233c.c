/* Based on CPU DB MC13233C, version 3.00.000 (RegistersPrg V2.33) */
/* DataSheet : MC1323xRM Draft 06/2011 */

#include <mc13233c.h>

/*lint -save -esym(765, *) */


/* * * * *  8-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile PTADSTR _PTAD;                                    /* Port A Data Register; 0x00000000 */
volatile PTADDSTR _PTADD;                                  /* Port A Data Direction Register; 0x00000001 */
volatile PTBDSTR _PTBD;                                    /* Port B Data Register; 0x00000002 */
volatile PTBDDSTR _PTBDD;                                  /* Port B Data Direction Register; 0x00000003 */
volatile PTCDSTR _PTCD;                                    /* Port C Data Register; 0x00000004 */
volatile PTCDDSTR _PTCDD;                                  /* Port C Data Direction Register; 0x00000005 */
volatile PTDDSTR _PTDD;                                    /* Port D Data Register; 0x00000006 */
volatile PTDDDSTR _PTDDD;                                  /* Port D Data Direction Register; 0x00000007 */
volatile TPM1SCSTR _TPM1SC;                                /* TPM1 Status and Control Register; 0x00000008 */
volatile TPM1C0SCSTR _TPM1C0SC;                            /* TPM1 Timer Channel 0 Status and Control Register; 0x0000000D */
volatile TPM2SCSTR _TPM2SC;                                /* TPM2 Status and Control Register; 0x00000010 */
volatile TPM2C0SCSTR _TPM2C0SC;                            /* TPM2 Timer Channel 0 Status and Control Register; 0x00000015 */
volatile TPM3SCSTR _TPM3SC;                                /* TPM3 Status and Control Register; 0x00000018 */
volatile TPM3C0SCSTR _TPM3C0SC;                            /* TPM3 Timer Channel 0 Status and Control Register; 0x0000001D */
volatile AES_CONTROL1STR _AES_CONTROL1;                    /* AES 128 Control 1 Register; 0x00000020 */
volatile AES_CONTROL2STR _AES_CONTROL2;                    /* AES 128 Control Register 2; 0x00000021 */
volatile ASM_Data_0STR _ASM_Data_0;                        /* AES 128 Data Register 0; 0x00000022 */
volatile ASM_Data_1STR _ASM_Data_1;                        /* AES 128 Data Register 1; 0x00000023 */
volatile ASM_Data_2STR _ASM_Data_2;                        /* AES 128 Data Register 2; 0x00000024 */
volatile ASM_Data_3STR _ASM_Data_3;                        /* AES 128 Data Register 3; 0x00000025 */
volatile ASM_Data_4STR _ASM_Data_4;                        /* AES 128 Data Register 4; 0x00000026 */
volatile ASM_Data_5STR _ASM_Data_5;                        /* AES 128 Data Register 5; 0x00000027 */
volatile ASM_Data_6STR _ASM_Data_6;                        /* AES 128 Data Register 6; 0x00000028 */
volatile ASM_Data_7STR _ASM_Data_7;                        /* AES 128 Data Register 7; 0x00000029 */
volatile ASM_Data_8STR _ASM_Data_8;                        /* AES 128 Data Register 8; 0x0000002A */
volatile ASM_Data_9STR _ASM_Data_9;                        /* AES 128 Data Register 9; 0x0000002B */
volatile ASM_Data_ASTR _ASM_Data_A;                        /* AES 128 Data Register A; 0x0000002C */
volatile ASM_Data_BSTR _ASM_Data_B;                        /* AES 128 Data Register B; 0x0000002D */
volatile ASM_Data_CSTR _ASM_Data_C;                        /* AES 128 Data Register C; 0x0000002E */
volatile ASM_Data_DSTR _ASM_Data_D;                        /* AES 128 Data Register D; 0x0000002F */
volatile ASM_Data_ESTR _ASM_Data_E;                        /* AES 128 Data Register E; 0x00000030 */
volatile ASM_Data_FSTR _ASM_Data_F;                        /* AES 128 Data Register F; 0x00000031 */
volatile KBI1SCSTR _KBI1SC;                                /* KBI1 Status and Control Register; 0x00000032 */
volatile KBI1PESTR _KBI1PE;                                /* KBI1 Pin Enable Register; 0x00000033 */
volatile KBI1ESSTR _KBI1ES;                                /* KBI1 Edge Select Register; 0x00000034 */
volatile KBI2SCSTR _KBI2SC;                                /* KBI2 Status and Control Register; 0x00000035 */
volatile KBI2PESTR _KBI2PE;                                /* KBI2 Pin Enable Register; 0x00000036 */
volatile KBI2ESSTR _KBI2ES;                                /* KBI2 Edge Select Register; 0x00000037 */
volatile SCIC1STR _SCIC1;                                  /* SCI Control Register 1; 0x0000003A */
volatile SCIC2STR _SCIC2;                                  /* SCI Control Register 2; 0x0000003B */
volatile SCIS1STR _SCIS1;                                  /* SCI Status Register 1; 0x0000003C */
volatile SCIS2STR _SCIS2;                                  /* SCI Status Register 2; 0x0000003D */
volatile SCIC3STR _SCIC3;                                  /* SCI Control Register 3; 0x0000003E */
volatile SCIDSTR _SCID;                                    /* SCI Data Register; 0x0000003F */
volatile PHY_TXD_ADR_PNTR0STR _PHY_TXD_ADR_PNTR0;          /* Transmit Data Pointer Register 0; 0x00000040 */
volatile PHY_TXD_ADR_PNTR1STR _PHY_TXD_ADR_PNTR1;          /* Transmit Data Pointer Register 1; 0x00000041 */
volatile PHY_RXD_ADR_PNTR0STR _PHY_RXD_ADR_PNTR0;          /* Receive Data Pointer Register 0; 0x00000042 */
volatile PHY_RXD_ADR_PNTR1STR _PHY_RXD_ADR_PNTR1;          /* Receive Data Pointer Register 1; 0x00000043 */
volatile PHY_CNTRL1STR _PHY_CNTRL1;                        /* Transceiver Control Register 1; 0x00000044 */
volatile PHY_CNTRL2STR _PHY_CNTRL2;                        /* Transceiver Control Register 2; 0x00000045 */
volatile PHY_CNTRL3STR _PHY_CNTRL3;                        /* Transceiver Control Register 3; 0x00000046 */
volatile PHY_CNTRL4STR _PHY_CNTRL4;                        /* Transceiver Control Register 4; 0x00000047 */
volatile PHY_SRC_CNTRLSTR _PHY_SRC_CNTRL;                  /* Transceiver Source Address Control Register; 0x00000048 */
volatile PHY_SRC_ADDRS_SUM_DATA0STR _PHY_SRC_ADDRS_SUM_DATA0; /* Transceiver Source Address Sum Data Register 0; 0x00000049 */
volatile PHY_SRC_ADDRS_SUM_DATA1STR _PHY_SRC_ADDRS_SUM_DATA1; /* Transceiver Source Address Sum Data Register 1; 0x0000004A */
volatile PHY_RX_WTR_MARKSTR _PHY_RX_WTR_MARK;              /* Receiver Byte Count Watermark Threshold; 0x0000004B */
volatile PHY_RX_BYTE_COUNTSTR _PHY_RX_BYTE_COUNT;          /* Receiver Byte Count; 0x0000004C */
volatile PHY_STATUS1STR _PHY_STATUS1;                      /* Status Register 1; 0x0000004D */
volatile PHY_STATUS2STR _PHY_STATUS2;                      /* Status Register 2; 0x0000004E */
volatile PHY_CCAFNLSTR _PHY_CCAFNL;                        /* Clear Channel Assessment Final Value; 0x00000050 */
volatile PHY_EVENT_TMR0STR _PHY_EVENT_TMR0;                /* Event Timer Register 0; 0x00000051 */
volatile PHY_EVENT_TMR1STR _PHY_EVENT_TMR1;                /* Event Timer Register 1; 0x00000052 */
volatile PHY_EVENT_TMR2STR _PHY_EVENT_TMR2;                /* Event Timer Register 2; 0x00000053 */
volatile PHY_TIMESTAMP0STR _PHY_TIMESTAMP0;                /* Time Stamp Register 0; 0x00000054 */
volatile PHY_TIMESTAMP1STR _PHY_TIMESTAMP1;                /* Time Stamp Register 1; 0x00000055 */
volatile PHY_TIMESTAMP2STR _PHY_TIMESTAMP2;                /* Time Stamp Register 2; 0x00000056 */
volatile PHY_T3CMP0STR _PHY_T3CMP0;                        /* Event Timer Comparator 3 Register 0; 0x00000057 */
volatile PHY_T3CMP1STR _PHY_T3CMP1;                        /* Event Timer Comparator 3 Register 1; 0x00000058 */
volatile PHY_T3CMP2STR _PHY_T3CMP2;                        /* Event Timer Comparator 3 Register 2; 0x00000059 */
volatile PHY_TC2_PRIME0STR _PHY_TC2_PRIME0;                /* Time Comparator 2 Prime Register 0; 0x0000005A */
volatile PHY_TC2_PRIME1STR _PHY_TC2_PRIME1;                /* Time Comparator 2 Prime Register 1; 0x0000005B */
volatile PHY_MACSHORTADDRS0STR _PHY_MACSHORTADDRS0;        /* MAC Short Address Register 0; 0x0000005C */
volatile PHY_MACSHORTADDRS1STR _PHY_MACSHORTADDRS1;        /* MAC Short Address Register 1; 0x0000005D */
volatile PHY_MACPANID0STR _PHY_MACPANID0;                  /* MAC Pan ID Register 0; 0x0000005E */
volatile PHY_MACPANID1STR _PHY_MACPANID1;                  /* MAC Pan ID Register 1; 0x0000005F */
volatile CMTOCSTR _CMTOC;                                  /* CMT Output Control Register; 0x00000064 */
volatile CMTMSCSTR _CMTMSC;                                /* CMT Modulator Status and Control Register; 0x00000065 */
volatile IICASTR _IICA;                                    /* IIC Address Register; 0x0000006A */
volatile IICFSTR _IICF;                                    /* IIC Frequency Divider Register; 0x0000006B */
volatile IICC1STR _IICC1;                                  /* IIC Control Register 1; 0x0000006C */
volatile IICSSTR _IICS;                                    /* IIC Status Register; 0x0000006D */
volatile IICDSTR _IICD;                                    /* IIC Data I/O Register; 0x0000006E */
volatile IICC2STR _IICC2;                                  /* IIC Control Register 2; 0x0000006F */
volatile SPIC1STR _SPIC1;                                  /* SPI Control Register 1; 0x00000070 */
volatile SPIC2STR _SPIC2;                                  /* SPI Control Register 2; 0x00000071 */
volatile SPIBRSTR _SPIBR;                                  /* SPI Baud Rate Register; 0x00000072 */
volatile SPISSTR _SPIS;                                    /* SPI Status Register; 0x00000073 */
volatile SPIDSTR _SPID;                                    /* SPI Data Register; 0x00000075 */
volatile IRQSCSTR _IRQSC;                                  /* Interrupt request status and control register; 0x00000076 */
volatile PPAGESTR _PPAGE;                                  /* Program Page Register; 0x00000078 */
volatile LAP2STR _LAP2;                                    /* Linear Address Pointer Register 2; 0x00000079 */
volatile LAP1STR _LAP1;                                    /* Linear Address Pointer Register 1; 0x0000007A */
volatile LAP0STR _LAP0;                                    /* Linear Address Pointer Register 0; 0x0000007B */
volatile LWPSTR _LWP;                                      /* Linear Word Post Increment Register; 0x0000007C */
volatile LBPSTR _LBP;                                      /* Linear Byte Post Increment Register; 0x0000007D */
volatile LBSTR _LB;                                        /* Linear Byte Register; 0x0000007E */
volatile LAPABSTR _LAPAB;                                  /* Linear Address Pointer Add Byte Register; 0x0000007F */
volatile SRSSTR _SRS;                                      /* System Reset Status Register; 0x00001800 */
volatile SBDFRSTR _SBDFR;                                  /* System Background Debug Force Reset Register; 0x00001801 */
volatile SOPT1STR _SOPT1;                                  /* System Options Register 1; 0x00001802 */
volatile SOPT2STR _SOPT2;                                  /* System Options Register 2; 0x00001803 */
volatile SCIC4STR _SCIC4;                                  /* SCI Control Register 4; 0x00001804 */
volatile SPMSC1STR _SPMSC1;                                /* System Power Management Status and Control 1 Register; 0x00001808 */
volatile SPMSC2STR _SPMSC2;                                /* System Power Management Status and Control 2 Register; 0x00001809 */
volatile SPMSC3STR _SPMSC3;                                /* System Power Management Status and Control 3 Register; 0x0000180B */
volatile SOMC1STR _SOMC1;                                  /* ; 0x0000180C */
volatile SOMC2STR _SOMC2;                                  /* ; 0x0000180D */
volatile SCGC1STR _SCGC1;                                  /* System Clock Gating Control 1 Register; 0x0000180E */
volatile SCGC2STR _SCGC2;                                  /* System Clock Gating Control 2 Register; 0x0000180F */
volatile DBGCAXSTR _DBGCAX;                                /* Debug Comparator A Extension Register; 0x00001818 */
volatile DBGCBXSTR _DBGCBX;                                /* Debug Comparator B Extension Register; 0x00001819 */
volatile DBGCCXSTR _DBGCCX;                                /* Debug Comparator C Extension Register; 0x0000181A */
volatile DBGFXSTR _DBGFX;                                  /* Debug FIFO Extended Information Register; 0x0000181B */
volatile DBGCSTR _DBGC;                                    /* Debug Control Register; 0x0000181C */
volatile DBGTSTR _DBGT;                                    /* Debug Trigger Register; 0x0000181D */
volatile DBGSSTR _DBGS;                                    /* Debug Status Register; 0x0000181E */
volatile DBGCNTSTR _DBGCNT;                                /* Debug Count Status Register; 0x0000181F */
volatile FOPTSTR _FOPT;                                    /* Flash Options Register; 0x00001821 */
volatile FCNFGSTR _FCNFG;                                  /* Flash Configuration Register; 0x00001823 */
volatile FPROTSTR _FPROT;                                  /* Flash Protection Register; 0x00001824 */
volatile FSTATSTR _FSTAT;                                  /* Flash Status Register; 0x00001825 */
volatile FCMDSTR _FCMD;                                    /* Flash Command Register; 0x00001826 */
volatile RTCSCSTR _RTCSC;                                  /* RTC Status and Control Register; 0x00001828 */
volatile RTCCNTLSTR _RTCCNTL;                              /* RTC Counter Register Low; 0x00001829 */
volatile RTCMODLSTR _RTCMODL;                              /* RTC Modulo Register Low; 0x0000182A */
volatile RTCCNTHSTR _RTCCNTH;                              /* RTC Counter Register High; 0x0000182B */
volatile RTCMODHSTR _RTCMODH;                              /* RTC Modulo Register High; 0x0000182C */
volatile PTAPESTR _PTAPE;                                  /* Port A Pull Enable Register; 0x00001830 */
volatile PTASESTR _PTASE;                                  /* Port A Slew Rate Enable Register; 0x00001831 */
volatile PTADSSTR _PTADS;                                  /* Port A Drive Strength Selection Register; 0x00001832 */
volatile PTBPESTR _PTBPE;                                  /* Port B Pull Enable Register; 0x00001834 */
volatile PTBSESTR _PTBSE;                                  /* Port B Slew Rate Enable Register; 0x00001835 */
volatile PTBDSSTR _PTBDS;                                  /* Port B Drive Strength Selection Register; 0x00001836 */
volatile PTCPESTR _PTCPE;                                  /* Port C Pull Enable Register; 0x00001838 */
volatile PTCSESTR _PTCSE;                                  /* Port C Slew Rate Enable Register; 0x00001839 */
volatile PTCDSSTR _PTCDS;                                  /* Port C Drive Strength Selection Register; 0x0000183A */
volatile PTDPESTR _PTDPE;                                  /* Port D Pull Enable Register; 0x0000183C */
volatile PTDSESTR _PTDSE;                                  /* Port D Slew Rate Enable Register; 0x0000183D */
volatile PTDDSSTR _PTDDS;                                  /* Port D Drive Strength Selection Register; 0x0000183E */
volatile PHY_T1CMP0STR _PHY_T1CMP0;                        /* Event Timer Comparator 1 Register 0; 0x00001840 */
volatile PHY_T1CMP1STR _PHY_T1CMP1;                        /* Event Timer Comparator 1 Register 1; 0x00001841 */
volatile PHY_T1CMP2STR _PHY_T1CMP2;                        /* Event Timer Comparator 1 Register 2; 0x00001842 */
volatile PHY_T2CMP0STR _PHY_T2CMP0;                        /* Event Timer Comparator 2 Register 0; 0x00001843 */
volatile PHY_T2CMP1STR _PHY_T2CMP1;                        /* Event Timer Comparator 2 Register 1; 0x00001844 */
volatile PHY_T2CMP2STR _PHY_T2CMP2;                        /* Event Timer Comparator 2 Register 2; 0x00001845 */
volatile PHY_T4CMP0STR _PHY_T4CMP0;                        /* Event Timer Comparator 4 Register 0; 0x00001846 */
volatile PHY_T4CMP1STR _PHY_T4CMP1;                        /* Event Timer Comparator 4 Register 1; 0x00001847 */
volatile PHY_T4CMP2STR _PHY_T4CMP2;                        /* Event Timer Comparator 4 Register 2; 0x00001848 */
volatile PHY_LO1_FRAC0STR _PHY_LO1_FRAC0;                  /* LO1 FracN Numerator Value Register 0; 0x00001849 */
volatile PHY_LO1_FRAC1STR _PHY_LO1_FRAC1;                  /* LO1 FracN Numerator Value Register 1; 0x0000184A */
volatile PHY_LO1_INTSTR _PHY_LO1_INT;                      /* LO1 Integer Register; 0x0000184B */
volatile PHY_PA_PWR_CNTLSTR _PHY_PA_PWR_CNTL;              /* Power Amplifier (PA) Power Control Register; 0x0000184C */
volatile PHY_MACLONGADDRS0STR _PHY_MACLONGADDRS0;          /* MAC Long Address Register 0; 0x0000184D */
volatile PHY_MACLONGADDRS1STR _PHY_MACLONGADDRS1;          /* MAC Long Address Register 1; 0x0000184E */
volatile PHY_MACLONGADDRS2STR _PHY_MACLONGADDRS2;          /* MAC Long Address Register 2; 0x0000184F */
volatile PHY_MACLONGADDRS3STR _PHY_MACLONGADDRS3;          /* MAC Long Address Register 3; 0x00001850 */
volatile PHY_MACLONGADDRS4STR _PHY_MACLONGADDRS4;          /* MAC Long Address Register 4; 0x00001851 */
volatile PHY_MACLONGADDRS5STR _PHY_MACLONGADDRS5;          /* MAC Long Address Register 5; 0x00001852 */
volatile PHY_MACLONGADDRS6STR _PHY_MACLONGADDRS6;          /* MAC Long Address Register 6; 0x00001853 */
volatile PHY_MACLONGADDRS7STR _PHY_MACLONGADDRS7;          /* MAC Long Address Register 7; 0x00001854 */
volatile PHY_MAXFRAMELENGTHSTR _PHY_MAXFRAMELENGTH;        /* Max Frame Length Register; 0x00001855 */
volatile PHY_RX_FRAME_FILTERSTR _PHY_RX_FRAME_FILTER;      /* Receive Frame Filter; 0x00001856 */
volatile PHY_MACFRAMEVERSTR _PHY_MACFRAMEVER;              /* ; 0x00001857 */
volatile PHY_CCA_THRESHOLDSTR _PHY_CCA_THRESHOLD;          /* CCA Energy Threshold; 0x00001858 */
volatile PHY_CCA_OFFSET_CMPSTR _PHY_CCA_OFFSET_CMP;        /* CCA Power Compensation; 0x00001859 */
volatile PHY_FSMSTR _PHY_FSM;                              /* Finite State Machine Register; 0x0000185A */
volatile PHY_INDIRECT_ACCESS_INDEXSTR _PHY_INDIRECT_ACCESS_INDEX; /* Transceiver Indirect Access Index Register; 0x0000185B */
volatile PHY_INDIRECT_ACCESS_DATASTR _PHY_INDIRECT_ACCESS_DATA; /* Transceiver Indirect Access Data Register; 0x0000185C */
volatile TPM4SCSTR _TPM4SC;                                /* TPM4 Status and Control Register; 0x00001860 */
volatile TPM4C0SCSTR _TPM4C0SC;                            /* TPM4 Timer Channel 0 Status and Control Register; 0x00001865 */
/* NVBACKKEY0 - macro for reading non volatile register    Backdoor Comparison Key 0; 0x0000FFB0 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY0_INIT @0x0000FFB0 = <NVBACKKEY0_INITVAL>; */
/* NVBACKKEY1 - macro for reading non volatile register    Backdoor Comparison Key 1; 0x0000FFB1 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY1_INIT @0x0000FFB1 = <NVBACKKEY1_INITVAL>; */
/* NVBACKKEY2 - macro for reading non volatile register    Backdoor Comparison Key 2; 0x0000FFB2 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY2_INIT @0x0000FFB2 = <NVBACKKEY2_INITVAL>; */
/* NVBACKKEY3 - macro for reading non volatile register    Backdoor Comparison Key 3; 0x0000FFB3 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY3_INIT @0x0000FFB3 = <NVBACKKEY3_INITVAL>; */
/* NVBACKKEY4 - macro for reading non volatile register    Backdoor Comparison Key 4; 0x0000FFB4 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY4_INIT @0x0000FFB4 = <NVBACKKEY4_INITVAL>; */
/* NVBACKKEY5 - macro for reading non volatile register    Backdoor Comparison Key 5; 0x0000FFB5 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY5_INIT @0x0000FFB5 = <NVBACKKEY5_INITVAL>; */
/* NVBACKKEY6 - macro for reading non volatile register    Backdoor Comparison Key 6; 0x0000FFB6 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY6_INIT @0x0000FFB6 = <NVBACKKEY6_INITVAL>; */
/* NVBACKKEY7 - macro for reading non volatile register    Backdoor Comparison Key 7; 0x0000FFB7 */
/* Tip for register initialization in the user code:  const byte NVBACKKEY7_INIT @0x0000FFB7 = <NVBACKKEY7_INITVAL>; */
/* NVPROT - macro for reading non volatile register        Nonvolatile Flash Protection Register; 0x0000FFBD */
/* Tip for register initialization in the user code:  const byte NVPROT_INIT @0x0000FFBD = <NVPROT_INITVAL>; */
/* NVOPT - macro for reading non volatile register         Nonvolatile Flash Options Register; 0x0000FFBF */
/* Tip for register initialization in the user code:  const byte NVOPT_INIT @0x0000FFBF = <NVOPT_INITVAL>; */


/* * * * *  16-BIT REGISTERS  * * * * * * * * * * * * * * * */
volatile TPM1CNTSTR _TPM1CNT;                              /* TPM1 Timer Counter Register; 0x00000009 */
volatile TPM1MODSTR _TPM1MOD;                              /* TPM1 Timer Counter Modulo Register; 0x0000000B */
volatile TPM1C0VSTR _TPM1C0V;                              /* TPM1 Timer Channel 0 Value Register; 0x0000000E */
volatile TPM2CNTSTR _TPM2CNT;                              /* TPM2 Timer Counter Register; 0x00000011 */
volatile TPM2MODSTR _TPM2MOD;                              /* TPM2 Timer Counter Modulo Register; 0x00000013 */
volatile TPM2C0VSTR _TPM2C0V;                              /* TPM2 Timer Channel 0 Value Register; 0x00000016 */
volatile TPM3CNTSTR _TPM3CNT;                              /* TPM3 Timer Counter Register; 0x00000019 */
volatile TPM3MODSTR _TPM3MOD;                              /* TPM3 Timer Counter Modulo Register; 0x0000001B */
volatile TPM3C0VSTR _TPM3C0V;                              /* TPM3 Timer Channel 0 Value Register; 0x0000001E */
volatile SCIBDSTR _SCIBD;                                  /* SCI Baud Rate Register; 0x00000038 */
volatile CMTCG1STR _CMTCG1;                                /* Carrier Generator Data Register 1; 0x00000060 */
volatile CMTCG2STR _CMTCG2;                                /* Carrier Generator Data Register 2; 0x00000062 */
volatile CMTCMD12STR _CMTCMD12;                            /* CMT Modulator Data Register 12; 0x00000066 */
volatile CMTCMD34STR _CMTCMD34;                            /* CMT Modulator Data Register 34; 0x00000068 */
volatile SDIDSTR _SDID;                                    /* System Device Identification Register; 0x00001806 */
volatile DBGCASTR _DBGCA;                                  /* Debug Comparator A Register; 0x00001810 */
volatile DBGCBSTR _DBGCB;                                  /* Debug Comparator B Register; 0x00001812 */
volatile DBGCCSTR _DBGCC;                                  /* Debug Comparator C Register; 0x00001814 */
volatile DBGFSTR _DBGF;                                    /* Debug FIFO Register; 0x00001816 */
volatile TPM4CNTSTR _TPM4CNT;                              /* TPM4 Timer Counter Register; 0x00001861 */
volatile TPM4MODSTR _TPM4MOD;                              /* TPM4 Timer Counter Modulo Register; 0x00001863 */
volatile TPM4C0VSTR _TPM4C0V;                              /* TPM4 Timer Channel 0 Value Register; 0x00001866 */

/*lint -restore */

/* EOF */
