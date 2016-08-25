#include "zbc_tools.h"
#include <stdio.h>

uint64_t zbc_get_zones(char const *path){
	return zbc_get_zone_type(path,ZBC_RO_ALL);
}

uint64_t zbc_get_random_zones(char const *path){
	return zbc_get_zone_type(path,ZBC_RO_NOT_WP);
}

uint64_t zbc_get_zone_type(char const *path, enum zbc_reporting_options ro)
{
    struct zbc_device_info info;
    unsigned long long lba = 0;
    struct zbc_device *dev;
 //   enum zbc_reporting_options ro = ZBC_RO_ALL;
    int ret = 1;
    zbc_zone_t *zones = NULL;
    unsigned int nr_zones = 0;//, nz = 0, partial = 0;
    //int num = 0;
//    char *path;

	ret = zbc_open(path, O_RDONLY, &dev);
    if ( ret != 0 ) {
        return( 1 );
    }

    ret = zbc_get_device_info(dev, &info);
    if ( ret < 0 ) {
        fprintf(stderr,
                "zbc_get_device_info failed\n");
		goto out;
    }

	ret = zbc_report_nr_zones(dev, lba, ro, &nr_zones);
    if ( ret != 0 ) {
        fprintf(stderr, "zbc_report_nr_zones at lba %llu, ro 0x%02x failed %d\n",
                (unsigned long long) lba,
                (unsigned int) ro,
                ret);
        ret = 1;
        goto out;
    }

	return nr_zones;

	out:

    if ( zones ) {
        free(zones);
    }

    zbc_close(dev);

    return( ret );
	
}

int zbc_tools_info(const char *dev, struct zbc_device_info *info)
{
	return 0;
}

int zbc_tools_close(char *path,struct zbc_device *dev, struct zbc_device_info *info, long long z, int lba)
{
	return 0;
}

int zbc_tools_finish(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z ,int lba)
{
	return 0;
}

int zbc_tools_open(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z, int lba)
{
	return 0;
}

int zbc_tools_read_zone(char *path, struct zbc_device_info *info, struct zbc_device *dev, 
                struct zbc_zone *zones, unsigned int nr_zones, int zidx, size_t iosize, char *file,
                unsigned long long ionum, long long lba_ofst )
{
	return 0;
}

int zbc_tools_report_zones(char *path, struct zbc_device_info *info, struct zbc_device *dev, int lba, 
                enum zbc_reporting_options ro, unsigned int nz,unsigned int  partial, int num)
{
	return 0;
}

int zbc_tools_reset_write_pointer(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z ,int lba)
{
	return 0;
}

int zbc_tools_set_write_pointer(char *path, struct zbc_device_info *info, struct zbc_device *dev, long long z ,int lba)
{
	return 0;
}
