/* SPDX-License-Identifier: MIT
 * Copyright (C) 2025 Avnet
 * Authors: Nikola Markovic <nikola.markovic@avnet.com>, Shu Liu <shu.liu@avnet.com> et al.
 */

#ifndef APP_CONFIG_H
#define APP_CONFIG_H

#include "iotconnect.h"

// see IotConnectConnectionType: IOTC_CT_AWS or IOTC_CT_AZURE
#define IOTCONNECT_CONNECTION_TYPE IOTC_CT_UNDEFINED
#define IOTCONNECT_CPID "your-cpid"
#define IOTCONNECT_ENV  "your-env"

// If Device Unique ID (DUID) is not provided, a generated DUID will be used using the below prefix
#define IOTCONNECT_DUID "" 
// prefix for the auto-generated name based on chip HWUID that will be used if IOTCONNECT_DUID is not supplied
#define IOTCONNECT_DUID_PREFIX "psoc-edge-va-"

/*
 PEM format certificate and private key
Example:
#define IOTCONNECT_DEVICE_CERT \
"-----BEGIN CERTIFICATE-----\n" \
".... base64 encoded certificate ..."\
"-----END CERTIFICATE-----"
#define IOTCONNECT_DEVICE_KEY \
"-----BEGIN PRIVATE KEY-----\n" \
".... base64 encoded private key ..."\
"-----END PRIVATE KEY-----"
Leave certificate and private key blank if  you wish to use EMEEPROM data to automatically generate the certificate
and use the runtime configuration for all of the configurable values in this file.
IMPORTANT NOTE: If you use the EMEEPROM runtime configuration,
the certificate and private key will be regenerated when you re-flash the board!
In that case, you would need to delete and re-create your device in IoTConnect.
*/
#define IOTCONNECT_DEVICE_CERT ""
#define IOTCONNECT_DEVICE_KEY ""

#endif /* APP_CONFIG_H */