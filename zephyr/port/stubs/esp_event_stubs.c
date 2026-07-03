/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Minimal esp_event stubs for Zephyr.
 *
 * libmesh.a references esp_event_handler_register/unregister. The actual
 * event dispatch is handled by esp_mesh_event_dispatch() in esp_mesh_drv.c
 * which is called from esp_event_post() in wifi_compat_stubs.c. These stubs
 * satisfy the linker without duplicating any symbol already provided.
 */

#include "esp_event.h"
#include "esp_err.h"

esp_err_t esp_event_handler_register(esp_event_base_t event_base,
				      int32_t event_id,
				      esp_event_handler_t event_handler,
				      void *event_handler_arg)
{
	/* Event dispatch is done via esp_mesh_event_dispatch() hook. */
	return ESP_OK;
}

esp_err_t esp_event_handler_unregister(esp_event_base_t event_base,
				       int32_t event_id,
				       esp_event_handler_t event_handler)
{
	return ESP_OK;
}
