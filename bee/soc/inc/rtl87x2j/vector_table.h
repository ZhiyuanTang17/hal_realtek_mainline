#ifndef VECTOR_TABLE_H
#define VECTOR_TABLE_H

// *INDENT-OFF*
#include "vector_table_auto_gen.h"

#define SUB_IRQ_DEF(first_irq, second_index) (((first_irq) << 8) | (second_index))
#define GET_FIRST_IRQn(sub_irq)              ((sub_irq) >> 8)

typedef void (* P_SECOND_VECTOR_UPDATE)(uint32_t irqn, IRQ_Fun isr_handler);
bool ram_vector_table_register(uint8_t irqn, P_SECOND_VECTOR_UPDATE reg_func);

bool ram_vector_table_init(uint32_t ram_vector_addr);
bool ram_vector_table_update(int irqn, IRQ_Fun isr_handler);

// *INDENT-ON* 
#endif //#define VECTOR_TABLE_H
