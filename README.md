# RTOS
    A real-time operation system about MCU(imitative writing)，I will use it in 32-bit MCU .(I'm learning rules about markdown，I will translate it from Chinese to English)
    v0.1,初始工程创建,flag1的切换。
    v0.2,内核编程，用pendSVC触发异常，在异常处理函数中保存R4~R11到缓冲区，在恢复，模拟任务切换时的寄存器保护与恢复。
    v0.3,任务的定义与切换，任务的含义，切换的原理，堆，栈，数据，代码区（各部分作用与分配），任务切换本质，保持前一任务当前运行状态，恢复后一任务之前的运行状态（要保存的值）。
    v0.4,任务切换的实现与分析。
    v0.5,上一版本通过任务中的任务切换函数实现任务切换，这一版采用时间片的方式自动切换任务。
    v0.6,解决任务空延时的问题，提供一个函数延时接口，使得延时过程中可放弃CPU转而运行其他任务，计时器与硬件定时器。
    v0.7,临界区，解决多任务同时访问导致冲突的问题。
    v0.8,调度锁，在不关中断的情况下对任务进行保护。后续，多任务与优先级。
    v0.9,位图数据结构学习。
    v0.10,多优先级任务的编写，不足：一个任务只能占用一个优先级，能否多个任务使用一个优先级？
    v0.11,双向链表建立与增删查改。
    v0.12,任务延时队列
    v0.13,多个任务占用一个优先级。
    v0.14,任务的挂起与唤醒。
    v0.15,任务的删除。
    v0.16,任务状态查询。
    v0.17,事件控制块。
    v0.18,事件等待与通知。
    v0.19,事件控制块的清空与状态查询。
    v0.20,计数信号量的原理与初始化。
    v0.21,计数信号量获取与释放。
    v0.22,计数信号量的删除与状态查询。
    v0.23,TinyOS邮箱的原理与创建。
    v0.24,邮箱的获取与释放。
    v0.25,邮箱的清空与删除。
    v0.26,邮箱状态查询。
    v0.27,存储块的原理与创建。
