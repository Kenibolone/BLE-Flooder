#include <esp_bt.h>
#include <esp_gap_ble_api.h>
#include <esp_bt_main.h>
#include <esp_bt_device.h>

uint8_t adv_data[31]; 

esp_ble_adv_params_t adv_params = {
  .adv_int_min        = 0x20,
  .adv_int_max        = 0x40,
  .adv_type           = ADV_TYPE_NONCONN_IND,
  .own_addr_type      = BLE_ADDR_TYPE_PUBLIC,
  .channel_map        = ADV_CHNL_ALL,
  .adv_filter_policy  = ADV_FILTER_ALLOW_SCAN_ANY_CON_ANY,
};

void gapCallback(esp_gap_ble_cb_event_t event, esp_ble_gap_cb_param_t *param) {
  if (event == ESP_GAP_BLE_ADV_DATA_RAW_SET_COMPLETE_EVT) {
    esp_ble_gap_start_advertising(&adv_params);  
  }
}

void advertiseRandomName() {
  char name[11];
  for (int i = 0; i < 10; i++) name[i] = random(33, 127);
  name[10] = '\0';

  uint8_t len = strlen(name);
  adv_data[0] = len + 1;
  adv_data[1] = 0x09; 
  memcpy(&adv_data[2], name, len);
  int total_len = len + 2;

  adv_data[total_len++] = 0x02;  
  adv_data[total_len++] = 0x01;  
  adv_data[total_len++] = 0x06;  

  esp_ble_gap_config_adv_data_raw(adv_data, total_len);
}

void setup() {
  Serial.begin(115200);
  Serial.println("BLE Flooder Starting...");

  esp_bt_controller_config_t bt_cfg = BT_CONTROLLER_INIT_CONFIG_DEFAULT();
  esp_bt_controller_init(&bt_cfg);
  esp_bt_controller_enable(ESP_BT_MODE_BLE);
  esp_bluedroid_init();
  esp_bluedroid_enable();

  esp_ble_gap_register_callback(gapCallback);
  advertiseRandomName();  
}

void loop() {
  advertiseRandomName(); 
  delay(1000);
}
