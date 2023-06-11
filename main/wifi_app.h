#ifndef MAIN_WIFI_APP_H_
#define MAIN_WIFI_APP_H
#include "esp_netif.h"
#include "freertos/FreeRTOS.h"

// Wifi application settings
#define WIFI_AP_SSID "ESP32_AP"          // AP name
#define WIFI_AP_PASSWORD "password"      // AP password
#define WIFI_AP_CHANNEL 1                // AP channel
#define WIFI_AP_SSID_HIDEN 0             // AP visibility
#define WIFI_AP_MAX_CONNECTIONS 5        // AP max clients
#define WIFI_AP_BEACON_INTERVAL 100      // Ap beacon interval
#define WIFI_AP_IP "192.168.0.1"         // AP default IP
#define WIFI_AP_GATEWAY "192.168.0.1"    // AP default gateway (should be the same as the IP address)
#define WIFI_AP_NETMASK "255.255.255.0"  // AP netmask
#define WIFI_AP_BANDWIDTH WIFI_BW_HT20   // AP bandwidth 20 Mhz
#define WIFI_STA_POWER_SAVE WIFI_PS_NONE // Power save not used
#define MAX_SSID_LENGTH 32               // IEEE standard maximum
#define MAX_PASSWORD_LENGTH 64           // IEEE standard maximum
#define MAX_CONNECTION_RETRIES 5         // Retry number on disconect

// netif object for the Station and Access Point
extern esp_netif_t *esp_netif_sta;
extern esp_netif_t *esp_netif_ap;

/*
Message IDs for the WiFi application task
*/
typedef enum wifi_app_message
{
    WIFI_APP_MSG_START_HTTP_SERVER = 0,
    WIFI_APP_MSG_CONNECTING_FROM_HTTP_SERVER,
    WIFI_APP_MSG_STA_CONNECTED_GOT_IP,
} wifi_app_message_e;

/*
Structer for the message queue
*/
typedef struct wifi_app_queue_message
{
    wifi_app_message_e msgID;
} wifi_app_queue_message_t;

/*
Sends a message to the queue
@param msgID from the wifi_app_message_e enum
@return pdTRUE if an item was successfully sent to the queue, otherwise pdFALSE
*/
BaseType_t wifi_app_send_message(wifi_app_message_e msgId);

/*
Starts the WIFI RTOS task
*/
void wifi_app_start(void);
#endif