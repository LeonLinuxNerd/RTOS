#include"tinyOS.h"
#include "ARMCM3.h"

#define NVIC_INT_CRL     0xE000Ed04  //??????????
#define NVIC_PENDSVSET   0x10000000  //???????
#define NVIC_SYSPRI2     0xE000ED22  //???????
#define NVIC_PENDSV_PRI  0x000000FF  //?????

#define MEM32(addr)  *(volatile unsigned long *)(addr)
#define MEME8(addr)  *(volatile unsigned char *)(addr)

uint32_t tTaskEnterCritical (void)
{
	uint32_t primask = __get_PRIMASK();
	__disable_irq();
	return primask;
}
//退出临界区
void tTaskExitCritical (uint32_t status)
{
	__set_PRIMASK(status);
}

//内嵌汇编
__asm void PendSV_Handler(void)   //异常处理函数
{
	IMPORT currentTask
	IMPORT nextTask
	
	MRS R0,PSP
	CBZ R0,PendSVHander_nosave
	//任务的保存操作
	STMDB R0,{R4-R11}
	
	LDR R1,=currentTask
	LDR R1,[R1]
	STR R0,[R1]
////////////////	
PendSVHander_nosave
	LDR R0,=currentTask
	LDR R1,=nextTask
	LDR r2,[R1]
	STR R2,[R0]
	
	LDR R0,[R2]
	LDMIA R0!,{R4-R11}
	
	MSR PSP,R0
	ORR LR,LR,#0X04
	BX LR
}

void tTaskRunFirst()
{
	__set_PSP(0);
	
	MEME8(NVIC_SYSPRI2)=NVIC_PENDSV_PRI;   //设置优先级
	MEM32(NVIC_INT_CRL)=NVIC_PENDSVSET;    //设置触发
}

void tTaskSwitch()
{
	MEM32(NVIC_INT_CRL)=NVIC_PENDSVSET;
}
