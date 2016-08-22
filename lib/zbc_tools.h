/*
 * This file contains headers to call libzbc tools.
 *
 * Add this header to call functions related to zbc_device. The backend for
 * this header file is libzbc library
 *
 * Author: Shehbaz Jaffer (shehbaz.jaffer@mail.utoronto.ca)
 */

#ifndef __LIBZBC_TOOLS_H__
#define __LIBZBC_TOOLS_H__

#include <stddef.h>
#include "zbc.h"

#ifdef __cplusplus
extern "C"{
#endif

uint64_t zbc_get_zone_type(char const *dev, enum zbc_reporting_options);

uint64_t zbc_get_zones(char const *dev);

uint64_t zbc_get_random_zones(char const *dev);

int zbc_tools_info(const char *dev, struct zbc_device_info *info);

int zbc_tools_close(char *path,struct zbc_device *dev, struct zbc_device_info *info, long long z, int lba);

int zbc_tools_finish(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z ,int lba);

int zbc_tools_open(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z, int lba);

int zbc_tools_read_zone(char *path, struct zbc_device_info *info, struct zbc_device *dev, 
		struct zbc_zone *zones, unsigned int nr_zones, int zidx, size_t iosize, char *file,
		unsigned long long ionum, long long lba_ofst );

int zbc_tools_report_zones(char *path, struct zbc_device_info *info, struct zbc_device *dev, int lba, 
		enum zbc_reporting_options ro, unsigned int nz,unsigned int  partial, int num);

int zbc_tools_reset_write_pointer(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z ,int lba);

int zbc_tools_set_write_pointer(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z ,int lba);

//int zbc_tools_set_zones(char *path, struct zbc_device_info *info, struct zbc_device *dev, char *cmd);

#ifdef __cplusplus
}
#endif

#endif /* __LIBZBC_TOOLS_H__ */ 
