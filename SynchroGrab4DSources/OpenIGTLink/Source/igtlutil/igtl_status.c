/*=========================================================================

  Program:   Open ITK Link Library
  Module:    $HeadURL: http://svn.na-mic.org/NAMICSandBox/trunk/OpenIGTLink/Source/igtlutil/igtl_status.c $
  Language:  C
  Date:      $Date: 2008-12-22 19:05:42 -0500 (Mon, 22 Dec 2008) $
  Version:   $Revision: 3460 $

  Copyright (c) Insight Software Consortium. All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.  See the above copyright notices for more information.

=========================================================================*/

#include <string.h>
#include "igtl_status.h"
#include "igtl_util.h"

#include <stdio.h>

void igtl_export igtl_status_convert_byte_order(igtl_status_header* status)
{

  if (igtl_is_little_endian()) {
    status->code    = BYTE_SWAP_INT16(status->code);
    status->subcode = BYTE_SWAP_INT64(status->subcode);
  }
}


igtl_uint64 igtl_export igtl_status_get_crc(igtl_status_header* status, igtl_uint32 msglen, const char* msg)
{

  igtl_uint64 crc = crc64(0, 0, 0);

  crc = crc64((unsigned char*)status, IGTL_STATUS_HEADER_SIZE, crc);
  crc = crc64((unsigned char*)msg, msglen, crc);

  return crc;
}
