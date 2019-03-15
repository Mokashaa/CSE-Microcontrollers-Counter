#if defined(ewarm) || defined(DOXYGEN)
void
SysCtlDelay(unsigned long ulCount)
{
    __asm("    subs    r0, #1\n"
          "    bne.n   SysCtlDelay\n"
          "    bx      lr");
}
#endif
#if defined(codered) || defined(gcc) || defined(sourcerygxx)
void __attribute__((naked))
SysCtlDelay(unsigned long ulCount)
{
    __asm("    subs    r0, #1\n"
          "    bne     SysCtlDelay\n"
          "    bx      lr");
}
#endif
#if defined(rvmdk) || defined(__ARMCC_VERSION)
__asm void
SysCtlDelay(unsigned long ulCount)
{
    subs    r0, #1;
    bne     SysCtlDelay;
    bx      lr;
}
#endif
#if defined(ccs)
volatile unsigned long g_ulInlineCCSWorkaround;
void
SysCtlDelay(unsigned long ulCount)
{
    __asm("delay?: subs    r0, #1\n"
          "    bne.n   delay?\n"
          "    bx lr\n");

    //
    // This is needed to keep TI compiler from optimizing away this code.
    //
    g_ulInlineCCSWorkaround += ulCount;
}
#endif