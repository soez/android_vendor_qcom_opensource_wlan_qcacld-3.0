/*
 * Copyright (c) 2012-2016 The Linux Foundation. All rights reserved.
 *
 * Previously licensed under the ISC license by Qualcomm Atheros, Inc.
 *
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * This file was originally distributed by Qualcomm Atheros, Inc.
 * under proprietary terms before Copyright ownership was assigned
 * to the Linux Foundation.
 */

#if !defined(WLAN_HDD_LPASS_H)
#define WLAN_HDD_LPASS_H

struct hdd_context_s;

#ifdef WLAN_FEATURE_LPSS
void wlan_hdd_send_status_pkg(hdd_adapter_t *adapter,
			      hdd_station_ctx_t *sta_ctx,
			      uint8_t is_on, uint8_t is_connected);
void wlan_hdd_send_all_scan_intf_info(hdd_context_t *hdd_ctx);

/**
 * hdd_lpass_notify_start() - Notify LPASS of driver start
 * @hdd_ctx: The global HDD context
 *
 * This function is used to notify the LPASS feature that the wlan
 * driver has (re-)started.
 *
 * Return: none
 */
void hdd_lpass_notify_start(struct hdd_context_s *hdd_ctx);
#else
static inline void wlan_hdd_send_status_pkg(hdd_adapter_t *adapter,
					    hdd_station_ctx_t *sta_ctx,
					    uint8_t is_on, uint8_t is_connected)
{
	return;
}

static inline void wlan_hdd_send_all_scan_intf_info(hdd_context_t *hdd_ctx)
{
	return;
}
static inline void hdd_lpass_notify_start(struct hdd_context_s *hdd_ctx) { }
#endif

#endif /* WLAN_HDD_LPASS_H */
