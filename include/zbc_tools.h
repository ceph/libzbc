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

int zbc_tools_info(const char *dev, struct zbc_device_info *info);

int zbc_tools_close(char *path,struct zbc_device *dev, struct zbc_device_info *info, long long z, int lba);

int zbc_tools_finish(char *path, struct zbc_device_info info, struct zbc_device *dev, int lba);

#endif /* __LIBZBC_TOOLS_H__ */ 
