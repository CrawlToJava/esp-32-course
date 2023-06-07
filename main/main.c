/*
 * SPDX-FileCopyrightText: 2010-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */

#include <stdio.h>
#include <inttypes.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_chip_info.h"
#include "esp_flash.h"
#include "rgb_led.h"

void app_main(void)
{
    while (true)
    {
        rgb_led_wifi_app_started();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        rgb_led_http_server_started();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        rgb_led_wifi_connected();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
