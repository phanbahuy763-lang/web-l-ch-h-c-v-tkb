#include "stm32f0xx.h"
//config PLL dau vao HSI -> PLL (32MHz) -> SYSLCK
void IntPLL_32MHzHSI(void);

int main(void)
{
IntPLL_32MHzHSI();
    while(1);
}
/* B1 */

void IntPLL_32MHzHSI(void){
	/* B1 */
	if((RCC->CFGR & ((uint32_t)0x0000000C)) == ((uint32_t)0x00000000)){
		/* B2 */
		RCC->CFGR &= ~ ((uint32_t)0x00000003);
		/* B3 */
		while((RCC->CFGR & ((uint32_t)0x0000000C)) != (uint32_t)0x00000000){}
	}
	/* B4 */
	RCC->CR &= ~((uint32_t)0x01000000);
	/* B5 */
	while((RCC->CR & ((uint32_t)0x02000000)) != 0){}
	/* B6 */
	RCC->CFGR &= ~ ((uint32_t)0x00018000);
	/* B7 (32MHz) 4 * 8 = 32 */
	RCC->CFGR &= ~((uint32_t)0x003C0000) | ((uint32_t)0x00180000);
	/* B8 PLLON = 1 cua CR */
	RCC->CR |= ((uint32_t)0x01000000);
	/* B9 */
	while((RCC->CR & ((uint32_t)0x02000000)) == 0){}
	/* B10 */
	RCC->CFGR |= ((uint32_t)0x00000002);
	/* B11 */
	while((RCC->CFGR & ((uint32_t)0x0000000C)) != ((uint32_t)0x00000008)){}
}
