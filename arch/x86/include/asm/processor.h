/*
 * (C) Copyright 2002
 * Daniel Engström, Omicron Ceti AB, daniel@omicron.se
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __ASM_PROCESSOR_H_
#define __ASM_PROCESSOR_H_ 1

#define X86_GDT_ENTRY_SIZE		8

#define X86_GDT_ENTRY_NULL		0
#define X86_GDT_ENTRY_UNUSED		1
#define X86_GDT_ENTRY_32BIT_CS		2
#define X86_GDT_ENTRY_32BIT_DS		3
#define X86_GDT_ENTRY_32BIT_FS		4
#define X86_GDT_ENTRY_16BIT_CS		5
#define X86_GDT_ENTRY_16BIT_DS		6
#define X86_GDT_ENTRY_16BIT_FLAT_CS	7
#define X86_GDT_ENTRY_16BIT_FLAT_DS	8
#define X86_GDT_NUM_ENTRIES		9

#define X86_GDT_SIZE		(X86_GDT_NUM_ENTRIES * X86_GDT_ENTRY_SIZE)

/* Length of the public header on Intel microcode blobs */
#define UCODE_HEADER_LEN	0x30

#ifndef __ASSEMBLY__

/*
 * This register is documented in (for example) the Intel Atom Processor E3800
 * Product Family Datasheet in "PCU - Power Management Controller (PMC)".
 *
 * RST_CNT: Reset Control Register (RST_CNT) Offset cf9.
 *
 * The naming follows Intel's naming.
 */
#define IO_PORT_RESET		0xcf9

enum {
	SYS_RST		= 1 << 1,	/* 0 for soft reset, 1 for hard reset */
	RST_CPU		= 1 << 2,	/* initiate reset */
	FULL_RST	= 1 << 3,	/* full power cycle */
};

/**
 * x86_full_reset() - reset everything: perform a full power cycle
 */
void x86_full_reset(void);

static inline __attribute__((always_inline)) void cpu_hlt(void)
{
	asm("hlt");
}

static inline ulong cpu_get_sp(void)
{
	ulong result;

	asm volatile(
		"mov %%esp, %%eax"
		: "=a" (result));
	return result;
}

#endif /* __ASSEMBLY__ */

#endif
