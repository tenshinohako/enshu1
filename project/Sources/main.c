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
	
	PTADD_PTADD0 = 1;
	PTADD_PTADD4 = 1;
	
	PTAD_PTAD0 = 0;
	PTAD_PTAD4 = 0;
}

void main_control(void){
	
}
