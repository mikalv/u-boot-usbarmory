/*
 * USB armory MkI board configuration settings
 * http://inversepath.com/usbarmory
 *
 * Copyright (C) 2015, Inverse Path
 * Andrej Rosano <andrej@inversepath.com>
 *
 * SPDX-License-Identifier:|____GPL-2.0+
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_MX53
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO
#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_LATE_INIT
#define CONFIG_OF_LIBFDT
#define CONFIG_SYS_GENERIC_BOARD
#define CONFIG_MXC_GPIO

#include <asm/arch/imx-regs.h>
#include <config_cmd_default.h>

/* U-Boot commands */
#define CONFIG_CMD_BOOTZ
#define CONFIG_CMD_FAT
#define CONFIG_CMD_MEMTEST
#define CONFIG_CMD_EXT2
#undef CONFIG_CMD_IMLS

/* U-Boot environment */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_SYS_NO_FLASH
#define CONFIG_ENV_OFFSET	(6 * 64 * 1024)
#define CONFIG_ENV_SIZE		(8 * 1024)
#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV	0

/* U-Boot general configurations */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE	512
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS	16
#define CONFIG_SYS_BARGSIZE	CONFIG_SYS_CBSIZE
#define CONFIG_CMDLINE_EDITING

/* UART */
#define CONFIG_MXC_UART
#define CONFIG_MXC_UART_BASE	UART1_BASE
#define CONFIG_CONS_INDEX	1
#define CONFIG_BAUDRATE		115200

/* SD/MMC */
#define CONFIG_CMD_MMC
#define CONFIG_FSL_ESDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	0
#define CONFIG_SYS_FSL_ESDHC_NUM	2
#define CONFIG_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_DOS_PARTITION

/* USB */
#define CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX5
#define CONFIG_USB_STORAGE
#define CONFIG_MXC_USB_PORT	1
#define CONFIG_MXC_USB_PORTSC	(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS	0

/* I2C */
#define CONFIG_CMD_I2C
#define CONFIG_SYS_I2C
#define CONFIG_SYS_I2C_MXC

/* Fuse */
#define CONFIG_CMD_FUSE
#define CONFIG_FSL_IIM

/* Linux boot */
#define CONFIG_BOOTDELAY	1
#define CONFIG_LOADADDR		0x72000000
#define CONFIG_SYS_TEXT_BASE	0x77800000
#define CONFIG_SYS_LOAD_ADDR	CONFIG_LOADADDR
#define CONFIG_HOSTNAME		usbarmory
#define CONFIG_BOOTARGS \
	"console=ttymxc0,115200 root=/dev/mmcblk0p1 rootwait rw"
#define CONFIG_BOOTCOMMAND \
	"ext2load mmc 0:1 0x70800000 /boot/uImage; ext2load mmc 0:1 " \
	"0x71000000 /boot/imx53-usbarmory.dtb; bootm 0x70800000 - 0x71000000"

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS		1
#define PHYS_SDRAM			CSD0_BASE_ADDR
#define PHYS_SDRAM_SIZE			(gd->ram_size)

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

#define CONFIG_SYS_MEMTEST_START	0x70000000
#define CONFIG_SYS_MEMTEST_END		0x90000000

#define CONFIG_SYS_MALLOC_LEN		(10 * 1024 * 1024)

#endif				/* __CONFIG_H */
