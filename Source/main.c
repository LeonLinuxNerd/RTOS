#define NVIC_INT_CRL     0xE000Ed04 
#define NVIC_PENDSVSET   0x10000000  //��Ĵ���д��ֵ
#define NVIC_SYSPRI2     0xE000ED22
#define NVIC_PENDSV_PRI  0x000000FF  //��Ĵ���д��ֵ

#define MEM32(addr)  *(volatile unsigned long *)(addr)
#define MEME8(addr)  *(volatile unsigned char *)(addr)

//�쳣��������
void triggerPendSVC(void)
{
	MEME8(NVIC_SYSPRI2)=NVIC_PENDSV_PRI;
	MEM32(NVIC_INT_CRL)=NVIC_PENDSVSET;
}
typedef struct _BlockType_t
{
		unsigned long *stackPtr;
}BlockType_t;

BlockType_t *blockPtr;
void delay(int count)
{
	while(--count>0);
}

int flag;

//����һ��������
unsigned long stackBuffer[1024];
BlockType_t block;
int main()
{
	block.stackPtr = &stackBuffer[1024];//ָ�����һ����Ԫ
	blockPtr = &block;
	for(;;){
		flag = 0;
		delay(100);
		flag = 1;
		delay(100);
		
		triggerPendSVC();
	}
}
