/*
 * QEMU model of the OCM General purpose memory for all system masters
 *
 * Copyright (c) 2013 Xilinx Inc.
 *
 * Written by Edgar E. Iglesias <edgari@xilinx.com>
 * Partly autogenerated by xregqemu.py 2013-10-15.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "qemu/osdep.h"
#include "hw/hw.h"
#include "hw/sysbus.h"
#include "migration/vmstate.h"
#include "hw/qdev-properties.h"
#include "hw/register.h"
#include "qemu/bitops.h"
#include "qemu/log.h"
#include "hw/irq.h"

#ifndef XILINX_OCM_ERR_DEBUG
#define XILINX_OCM_ERR_DEBUG 0
#endif

#define TYPE_XILINX_OCM "xlnx.zynqmp-ocmc"

#define XILINX_OCM(obj) \
     OBJECT_CHECK(OCMC, (obj), TYPE_XILINX_OCM)

REG32(OCM_ERR_CTRL, 0x0)
    FIELD(OCM_ERR_CTRL, UE_RES, 3, 1)
    FIELD(OCM_ERR_CTRL, PWR_ERR_RES, 2, 1)
    FIELD(OCM_ERR_CTRL, PZ_ERR_RES, 1, 1)
    FIELD(OCM_ERR_CTRL, APB_ERR_RES, 0, 1)
REG32(OCM_ISR, 0x4)
    FIELD(OCM_ISR, UE_RMW, 10, 1)
    FIELD(OCM_ISR, FIX_BURST_WR, 9, 1)
    FIELD(OCM_ISR, FIX_BURST_RD, 8, 1)
    FIELD(OCM_ISR, ECC_UE, 7, 1)
    FIELD(OCM_ISR, ECC_CE, 6, 1)
    FIELD(OCM_ISR, LOCK_ERR_WR, 5, 1)
    FIELD(OCM_ISR, LOCK_ERR_RD, 4, 1)
    FIELD(OCM_ISR, INV_OCM_WR, 3, 1)
    FIELD(OCM_ISR, INV_OCM_RD, 2, 1)
    FIELD(OCM_ISR, PWR_DWN, 1, 1)
    FIELD(OCM_ISR, INV_APB, 0, 1)
REG32(OCM_IMR, 0x8)
    FIELD(OCM_IMR, UE_RMW, 10, 1)
    FIELD(OCM_IMR, FIX_BURST_WR, 9, 1)
    FIELD(OCM_IMR, FIX_BURST_RD, 8, 1)
    FIELD(OCM_IMR, ECC_UE, 7, 1)
    FIELD(OCM_IMR, ECC_CE, 6, 1)
    FIELD(OCM_IMR, LOCK_ERR_WR, 5, 1)
    FIELD(OCM_IMR, LOCK_ERR_RD, 4, 1)
    FIELD(OCM_IMR, INV_OCM_WR, 3, 1)
    FIELD(OCM_IMR, INV_OCM_RD, 2, 1)
    FIELD(OCM_IMR, PWR_DWN, 1, 1)
    FIELD(OCM_IMR, INV_APB, 0, 1)
REG32(OCM_IEN, 0xc)
    FIELD(OCM_IEN, UE_RMW, 10, 1)
    FIELD(OCM_IEN, FIX_BURST_WR, 9, 1)
    FIELD(OCM_IEN, FIX_BURST_RD, 8, 1)
    FIELD(OCM_IEN, ECC_UE, 7, 1)
    FIELD(OCM_IEN, ECC_CE, 6, 1)
    FIELD(OCM_IEN, LOCK_ERR_WR, 5, 1)
    FIELD(OCM_IEN, LOCK_ERR_RD, 4, 1)
    FIELD(OCM_IEN, INV_OCM_WR, 3, 1)
    FIELD(OCM_IEN, INV_OCM_RD, 2, 1)
    FIELD(OCM_IEN, PWR_DWN, 1, 1)
    FIELD(OCM_IEN, INV_APB, 0, 1)
REG32(OCM_IDS, 0x10)
    FIELD(OCM_IDS, UE_RMW, 10, 1)
    FIELD(OCM_IDS, FIX_BURST_WR, 9, 1)
    FIELD(OCM_IDS, FIX_BURST_RD, 8, 1)
    FIELD(OCM_IDS, ECC_UE, 7, 1)
    FIELD(OCM_IDS, ECC_CE, 6, 1)
    FIELD(OCM_IDS, LOCK_ERR_WR, 5, 1)
    FIELD(OCM_IDS, LOCK_ERR_RD, 4, 1)
    FIELD(OCM_IDS, INV_OCM_WR, 3, 1)
    FIELD(OCM_IDS, INV_OCM_RD, 2, 1)
    FIELD(OCM_IDS, PWR_DWN, 1, 1)
    FIELD(OCM_IDS, INV_APB, 0, 1)
REG32(OCM_ECC_CNTL, 0x14)
    FIELD(OCM_ECC_CNTL, FI_MODE, 2, 1)
    FIELD(OCM_ECC_CNTL, DET_ONLY, 1, 1)
    FIELD(OCM_ECC_CNTL, ECC_ON_OFF, 0, 1)
REG32(OCM_CLR_EXE, 0x18)
    FIELD(OCM_CLR_EXE, MON_7, 7, 1)
    FIELD(OCM_CLR_EXE, MON_6, 6, 1)
    FIELD(OCM_CLR_EXE, MON_5, 5, 1)
    FIELD(OCM_CLR_EXE, MON_4, 4, 1)
    FIELD(OCM_CLR_EXE, MON_3, 3, 1)
    FIELD(OCM_CLR_EXE, MON_2, 2, 1)
    FIELD(OCM_CLR_EXE, MON_1, 1, 1)
    FIELD(OCM_CLR_EXE, MON_0, 0, 1)
REG32(OCM_CE_FFA, 0x1c)
    FIELD(OCM_CE_FFA, ADDR, 0, 18)
REG32(OCM_CE_FFD0, 0x20)
REG32(OCM_CE_FFD1, 0x24)
REG32(OCM_CE_FFD2, 0x28)
REG32(OCM_CE_FFD3, 0x2c)
REG32(OCM_CE_FFE, 0x30)
    FIELD(OCM_CE_FFE, SYNDROME, 0, 16)
REG32(OCM_UE_FFA, 0x34)
    FIELD(OCM_UE_FFA, ADDR, 0, 18)
REG32(OCM_UE_FFD0, 0x38)
REG32(OCM_UE_FFD1, 0x3c)
REG32(OCM_UE_FFD2, 0x40)
REG32(OCM_UE_FFD3, 0x44)
REG32(OCM_UE_FFE, 0x48)
    FIELD(OCM_UE_FFE, SYNDROME, 0, 16)
REG32(OCM_FI_D0, 0x4c)
REG32(OCM_FI_D1, 0x50)
REG32(OCM_FI_D2, 0x54)
REG32(OCM_FI_D3, 0x58)
REG32(OCM_FI_SY, 0x5c)
    FIELD(OCM_FI_SY, DATA, 0, 16)
REG32(OCM_EMA, 0x60)
    FIELD(OCM_EMA, BANK3, 9, 3)
    FIELD(OCM_EMA, BANK2, 6, 3)
    FIELD(OCM_EMA, BANK1, 3, 3)
    FIELD(OCM_EMA, BANK0, 0, 3)
REG32(OCM_EMAW, 0x64)
    FIELD(OCM_EMAW, BANK3, 6, 2)
    FIELD(OCM_EMAW, BANK2, 4, 2)
    FIELD(OCM_EMAW, BANK1, 2, 2)
    FIELD(OCM_EMAW, BANK0, 0, 2)
REG32(OCM_EMAS, 0x68)
    FIELD(OCM_EMAS, BANK3, 3, 1)
    FIELD(OCM_EMAS, BANK2, 2, 1)
    FIELD(OCM_EMAS, BANK1, 1, 1)
    FIELD(OCM_EMAS, BANK0, 0, 1)
REG32(OCM_CE_CNT, 0x6c)
    FIELD(OCM_CE_CNT, COUNT, 0, 16)
REG32(OCM_RMW_UE_FFA, 0x70)
    FIELD(OCM_RMW_UE_FFA, ADDR, 0, 18)
REG32(OCM_FI_CNTR, 0x74)
    FIELD(OCM_FI_CNTR, COUNT, 0, 24)
REG32(OCM_DBG_SYN_TOMEM, 0x78)
REG32(OCM_DBG_SYN_FROMEM, 0x7c)
REG32(OCM_IMP, 0x80)
    FIELD(OCM_IMP, SIZE, 0, 4)
REG32(OCM_ECO, 0xffc)

#define R_MAX (R_OCM_ECO + 1)

typedef struct OCMC {
    SysBusDevice parent_obj;
    MemoryRegion iomem;
    qemu_irq irq;

    struct {
        uint64_t memsize;
    } cfg;

    uint32_t regs[R_MAX];
    RegisterInfo regs_info[R_MAX];
} OCMC;

static const MemoryRegionOps ocm_ops = {
    .read = register_read_memory,
    .write = register_write_memory,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .valid = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void ocm_update_irq(OCMC *s)
{
    bool pending = s->regs[R_OCM_ISR] & s->regs[R_OCM_IMR];
    qemu_set_irq(s->irq, pending);
}

static void ocm_isr_postw(RegisterInfo *reg, uint64_t val64)
{
    OCMC *s = XILINX_OCM(reg->opaque);
    ocm_update_irq(s);
}

static uint64_t ocm_ien_prew(RegisterInfo *reg, uint64_t val64)
{
    OCMC *s = XILINX_OCM(reg->opaque);
    uint32_t val = val64;

    s->regs[R_OCM_IMR] |= val;
    ocm_update_irq(s);
    return 0;
}

static uint64_t ocm_ids_prew(RegisterInfo *reg, uint64_t val64)
{
    OCMC *s = XILINX_OCM(reg->opaque);
    uint32_t val = val64;

    s->regs[R_OCM_IMR] &= ~val;
    ocm_update_irq(s);
    return 0;
}

static const RegisterAccessInfo ocm_regs_info[] = {
    {   .name = "OCM_ERR_CTRL",  .addr = A_OCM_ERR_CTRL,
        .rsvd = 0xfffffff0,
    },{ .name = "OCM_ISR",  .addr = A_OCM_ISR,
        .rsvd = 0xfffff800,
        .w1c = 0x7ff,
        .ro = ~0x7ffull,
        .post_write = ocm_isr_postw,
    },{ .name = "OCM_IMR",  .addr = A_OCM_IMR,
        .reset = 0x7ff,
        .rsvd = 0xfffff800,
        .ro = 0x7ff,
    },{ .name = "OCM_IEN",  .addr = A_OCM_IEN,
        .rsvd = 0xfffff800,
        .pre_write = ocm_ien_prew,
    },{ .name = "OCM_IDS",  .addr = A_OCM_IDS,
        .rsvd = 0xfffff800,
        .pre_write = ocm_ids_prew,
    },{ .name = "OCM_ECC_CNTL",  .addr = A_OCM_ECC_CNTL,
        .rsvd = 0xfffffff8,
    },{ .name = "OCM_CLR_EXE",  .addr = A_OCM_CLR_EXE,
        .rsvd = 0xffffff00,
    },{ .name = "OCM_CE_FFA",  .addr = A_OCM_CE_FFA,
        .rsvd = 0xfffc0000,
        .ro = 0x3ffff,
    },{ .name = "OCM_CE_FFD0",  .addr = A_OCM_CE_FFD0,
        .ro = 0xffffffff,
    },{ .name = "OCM_CE_FFD1",  .addr = A_OCM_CE_FFD1,
        .ro = 0xffffffff,
    },{ .name = "OCM_CE_FFD2",  .addr = A_OCM_CE_FFD2,
        .ro = 0xffffffff,
    },{ .name = "OCM_CE_FFD3",  .addr = A_OCM_CE_FFD3,
        .ro = 0xffffffff,
    },{ .name = "OCM_CE_FFE",  .addr = A_OCM_CE_FFE,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "OCM_UE_FFA",  .addr = A_OCM_UE_FFA,
        .rsvd = 0xfffc0000,
        .ro = 0x3ffff,
    },{ .name = "OCM_UE_FFD0",  .addr = A_OCM_UE_FFD0,
        .ro = 0xffffffff,
    },{ .name = "OCM_UE_FFD1",  .addr = A_OCM_UE_FFD1,
        .ro = 0xffffffff,
    },{ .name = "OCM_UE_FFD2",  .addr = A_OCM_UE_FFD2,
        .ro = 0xffffffff,
    },{ .name = "OCM_UE_FFD3",  .addr = A_OCM_UE_FFD3,
        .ro = 0xffffffff,
    },{ .name = "OCM_UE_FFE",  .addr = A_OCM_UE_FFE,
        .rsvd = 0xffff0000,
        .ro = 0xffff,
    },{ .name = "OCM_FI_D0",  .addr = A_OCM_FI_D0,
    },{ .name = "OCM_FI_D1",  .addr = A_OCM_FI_D1,
    },{ .name = "OCM_FI_D2",  .addr = A_OCM_FI_D2,
    },{ .name = "OCM_FI_D3",  .addr = A_OCM_FI_D3,
    },{ .name = "OCM_FI_SY",  .addr = A_OCM_FI_SY,
        .rsvd = 0xffff0000,
    },{ .name = "OCM_EMA",  .addr = A_OCM_EMA,
        .reset = 0x249,
        .rsvd = 0xfffff000,
    },{ .name = "OCM_EMAW",  .addr = A_OCM_EMAW,
        .rsvd = 0xffffff00,
    },{ .name = "OCM_EMAS",  .addr = A_OCM_EMAS,
        .rsvd = 0xfffffff0,
    },{ .name = "OCM_CE_CNT",  .addr = A_OCM_CE_CNT,
        .w1c = 0xffff,
    },{ .name = "OCM_RMW_UE_FFA",  .addr = A_OCM_RMW_UE_FFA,
        .rsvd = 0xfffc0000,
        .ro = 0x3ffff,
    },{ .name = "OCM_FI_CNTR",  .addr = A_OCM_FI_CNTR,
        .rsvd = 0xff000000,
    },{ .name = "OCM_DBG_SYN_TOMEM",  .addr = A_OCM_DBG_SYN_TOMEM,
        .ro = 0xffffffff,
    },{ .name = "OCM_DBG_SYN_FROMEM",  .addr = A_OCM_DBG_SYN_FROMEM,
        .ro = 0xffffffff,
    },{ .name = "OCM_IMP",  .addr = A_OCM_IMP,
        .reset = 0x2,
        .ro = 0xf,
    },{ .name = "OCM_ECO",  .addr = A_OCM_ECO,
    }
};

static uint32_t ocmc_imp_encode_memsize(OCMC *s, uint64_t memsize)
{
    const char *prefix = object_get_canonical_path(OBJECT(s));
    uint32_t r;

    switch (memsize) {
    case 64 * 1024:
        r = 0;
        break;
    case 128 * 1024:
        r = 1;
        break;
    case 256 * 1024:
        r = 2;
        break;
    /* 512KB is still to be defined.  */
    case 512 * 1024:
        qemu_log("%s: WARN: Using an undefined OCM memory size.\n", prefix);
        r = 3;
        break;
    default:
        hw_error("%s: Invalid OCM memory size %" PRIu64 " bytes\n",
                 prefix, memsize);
        break;
    }
    return r;
}

static void ocm_reset(DeviceState *dev)
{
    OCMC *s = XILINX_OCM(dev);
    unsigned int i;

    for (i = 0; i < ARRAY_SIZE(s->regs_info); ++i) {
        register_reset(&s->regs_info[i]);
    }

    s->regs[R_OCM_IMP] = ocmc_imp_encode_memsize(s, s->cfg.memsize);
    ocm_update_irq(s);
}

static void ocm_init(Object *obj)
{
    OCMC *s = XILINX_OCM(obj);
    SysBusDevice *sbd = SYS_BUS_DEVICE(obj);
    RegisterInfoArray *reg_array;

    memory_region_init(&s->iomem, obj, TYPE_XILINX_OCM, R_MAX * 4);
    reg_array =
        register_init_block32(DEVICE(obj), ocm_regs_info,
                              ARRAY_SIZE(ocm_regs_info),
                              s->regs_info, s->regs,
                              &ocm_ops,
                              XILINX_OCM_ERR_DEBUG,
                              R_MAX * 4);
    memory_region_add_subregion(&s->iomem,
                                0x0,
                                &reg_array->mem);

    sysbus_init_mmio(sbd, &s->iomem);
    sysbus_init_irq(sbd, &s->irq);
}

static Property ocmc_properties[] = {
    DEFINE_PROP_UINT64("memsize", OCMC, cfg.memsize, 0),
    DEFINE_PROP_END_OF_LIST(),
};

static const VMStateDescription vmstate_ocm = {
    .name = TYPE_XILINX_OCM,
    .version_id = 1,
    .minimum_version_id = 1,
    .minimum_version_id_old = 1,
    .fields = (VMStateField[]) {
        VMSTATE_UINT32_ARRAY(regs, OCMC, R_MAX),
        VMSTATE_END_OF_LIST(),
    }
};

static void ocm_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);

    dc->reset = ocm_reset;
    dc->vmsd = &vmstate_ocm;
    dc->props = ocmc_properties;
}

static const TypeInfo ocm_info = {
    .name          = TYPE_XILINX_OCM,
    .parent        = TYPE_SYS_BUS_DEVICE,
    .instance_size = sizeof(OCMC),
    .class_init    = ocm_class_init,
    .instance_init = ocm_init,
};

static void ocm_register_types(void)
{
    type_register_static(&ocm_info);
}

type_init(ocm_register_types)
