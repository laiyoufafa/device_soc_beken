/*
// Copyright (C) 2022 Beken Corporation
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef _MMGMT_H_
#define _MMGMT_H_

#include "rwnx_config.h"

//#define		MMGMT_DEBUG

#define MM_MAGIC		0x1234abcd

/**
 ****************************************************************************************
 * @defgroup KE_MEM KE_MEM
 * @ingroup KERNEL
 * @brief Heap management module.
 *
 * The KEMEM module implements heap management functions that allow initializing heap,
 * allocating and freeing memory.
 *
 * @{
 ****************************************************************************************
 */
#define KE_HEAP_SIZE             CFG_HEAP_SIZE

/// Free memory block delimiter structure (size must be word multiple)
struct mblock_free {
	struct mblock_free *next;   ///< Pointer to the next block
	uint32_t size;              ///< Size of the current free block (including delimiter)
};

/// Used memory block delimiter structure (size must be word multiple)
struct mblock_used {
	uint32_t magic;
	uint32_t size;              ///< Size of the current used block (including delimiter)
};

// forward declarations
struct mblock_free;

extern void sys_mem_init(void);

/**
 ****************************************************************************************
 * @brief Heap initialization.
 *
 * This function performs the following operations:
 * - sanity checks
 * - check memory allocated is at least large enough to hold two block descriptors to hold
 * start and end
 * - initialize the first and last descriptors
 * - save the pointer to the first free descriptor
 *
 * @return The pointer to the first free block.
 *
 ****************************************************************************************
 */
struct mblock_free *mmgmt_init(void);

/**
 ****************************************************************************************
 * @brief Allocation of a block of memory.
 *
 * Allocates a memory block whose size is size; if no memory is available return
 * NULL
 *
 * @param[in] size Size of the memory area that need to be allocated.
 *
 * @return A pointer to the allocated memory area.
 *
 ****************************************************************************************
 */
#if CONFIG_MALLOC_STATIS
void *mmgmt_malloc(const char *call_func_name, int line, uint32_t size);
#else
void *mmgmt_malloc(uint32_t size);
#endif
void *mmgmt_realloc(void *ptr, size_t size);
uint32_t mmgmt_alloc_space(void);

/**
 ****************************************************************************************
 * @brief Freeing of a block of memory.
 *
 * Free the memory area pointed by mem_ptr : mark the block as free and insert it in
 * the pool of free block.
 *
 * @param[in] mem_ptr Pointer to the memory area that need to be freed.
 *
 ****************************************************************************************
 */
#if CONFIG_MALLOC_STATIS
void mmgmt_free(const char *call_func_name, int line, void *mem_ptr);
#else
void mmgmt_free(void *mem_ptr);
#endif

int mm_magic_match(void *mem_ptr);

///@} MEM

#endif // _MMGMT_H_

