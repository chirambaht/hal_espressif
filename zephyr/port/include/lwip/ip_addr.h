/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Minimal LwIP ip_addr shim for Zephyr.
 *
 * esp_mesh.h includes lwip/ip_addr.h solely to get ip4_addr_t and the
 * esp_ip4_addr_t typedef. Zephyr does not ship LwIP, so we provide the
 * minimum subset needed to compile the ESP-WIFI-MESH API header.
 *
 * Only mip_t in esp_mesh.h uses esp_ip4_addr_t, and mip_t is only used
 * by esp_mesh_recv_toDS() on the root node. No LwIP runtime code is
 * exercised by this shim — it is compile-time only.
 */

#ifndef ZEPHYR_LWIP_IP_ADDR_SHIM_H
#define ZEPHYR_LWIP_IP_ADDR_SHIM_H

#include <stdint.h>

/** IPv4 address (matches LwIP's struct ip4_addr layout) */
struct ip4_addr {
	uint32_t addr;
};

typedef struct ip4_addr ip4_addr_t;

/** ESP-IDF aliases LwIP's ip4_addr_t as esp_ip4_addr_t */
typedef ip4_addr_t esp_ip4_addr_t;

#endif /* ZEPHYR_LWIP_IP_ADDR_SHIM_H */
