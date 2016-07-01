/*
 * This file is part of libzbc.
 *
 * Copyright (C) 2009-2014, HGST, Inc.  This software is distributed
 * under the terms of the GNU Lesser General Public License version 3,
 * or any later version, "as is," without technical support, and WITHOUT
 * ANY WARRANTY, without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  You should have received a copy
 * of the GNU Lesser General Public License along with libzbc.  If not,
 * see <http://www.gnu.org/licenses/>.
 *
 * Authors: Damien Le Moal (damien.lemoal@hgst.com)
 *          Christophe Louargant (christophe.louargant@hgst.com)
 *          Shehbaz Jaffer (shehbaz.jaffer@mail.utoronto.ca)
 */

/***** Including files *****/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <libzbc/zbc.h>
#include <zbc_tools.h>

/***** Main *****/

int main(int argc,
         char **argv)
{
    struct zbc_device_info info;
    int ret, i;

    /* Check command line */
    if ( argc < 2 ) {
usage:
        printf("Usage: %s [options] <dev>\n"
               "Options:\n"
               "    -v         : Verbose mode\n",
               argv[0]);
        return( 1 );
    }

    /* Silent by default */
    zbc_set_log_level("none");

    /* Parse options */
    for(i = 1; i < (argc - 1); i++) {

        if ( strcmp(argv[i], "-v") == 0 ) {

            zbc_set_log_level("debug");

        } else if ( argv[i][0] == '-' ) {

            printf("Unknown option \"%s\"\n",
                   argv[i]);
            goto usage;

        } else {

            break;

        }

    }

    if ( i != (argc - 1) ) {
        goto usage;
    }

	const char *dev = argv[i];
	return zbc_tools_info(dev, &info);
}

int	zbc_tools_info(const char *dev, struct zbc_device_info *info)
{
    /* Open device */
	int ret;
    ret = zbc_device_is_smr(dev, info);
    if ( ret < 0 ) {
        fprintf(stderr,
                "zbc_device_is_smr failed %d (%s)\n",
		ret,
		strerror(-ret));
        return( 1 );
    }

    if ( ret ) {
	printf("Device %s: %s\n",
	       dev,
	       info->zbd_vendor_id);
	printf("    %s interface, %s disk model\n",
	       zbc_disk_type_str(info->zbd_type),
	       zbc_disk_model_str(info->zbd_model));
	printf("    %llu logical blocks of %u B\n",
	       (unsigned long long) info->zbd_logical_blocks,
	       (unsigned int) info->zbd_logical_block_size);
	printf("    %llu physical blocks of %u B\n",
	       (unsigned long long) info->zbd_physical_blocks,
	       (unsigned int) info->zbd_physical_block_size);
	printf("    %.03F GB capacity\n",
	       (double) (info->zbd_physical_blocks * info->zbd_physical_block_size) / 1000000000);
    } else {
	printf("%s is not an SMR device\n", dev);
    }

    return( 0 );
}
