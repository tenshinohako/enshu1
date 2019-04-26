#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */

void init_device(void);
void main_control(void);

void main(void) {
	
  EnableInterrupts;
  /* include your code here */

  init_device();

  for(;;) {
	  main_control();
    //__RESET_WATCHDOG();	/* feeds the dog */
  } /* loop forever */
  /* please make sure that you never leave main */
}

void init_device(void){
	SOPT1_COPE = 0;
	
	//LED output
	PTADD_PTADD0 = 1;
	PTADD_PTADD4 = 1;
	PTDDD_PTDDD0 = 1;
	
	//KMD0 = 0
	PTCDD_PTCDD0 = 1;
	PTCD_PTCD0 = 0;
	
	//enable Key
	KBI1PE_KBIPE0 = 1;
	KBI1PE_KBIPE1 = 1;
	
	//Key input
	PTBDD_PTBDD0 = 0;
	PTBDD_PTBDD1 = 0;
	
	//Key pullup
	PTBPE_PTBPE0 = 1;
	PTBPE_PTBPE1 = 1;
	
	
	PTAD_PTAD0 = 0;
	PTAD_PTAD4 = 0;
	PTDD_PTDD0 = 0;
}

void main_control(void){

	PTAD_PTAD0 = PTBD_PTBD0;
	PTAD_PTAD4 = PTBD_PTBD1;
	PTDD_PTDD0 = ~PTBD_PTBD1;
}

