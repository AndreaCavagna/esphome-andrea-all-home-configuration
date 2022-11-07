// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
logger::Logger *logger_logger;
web_server_base::WebServerBase *web_server_base_webserverbase;
captive_portal::CaptivePortal *captive_portal_captiveportal;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
mqtt::MQTTClientComponent *mqtt_mqttclientcomponent;
using namespace mqtt;
using namespace sensor;
using namespace json;
preferences::IntervalSyncer *preferences_intervalsyncer;
using namespace uart;
uart::ESP8266UartComponent *uart_esp8266uartcomponent;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin;
pm1006::PM1006Component *pm1006_pm1006component;
sensor::Sensor *sensor_sensor;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent;
wifi_signal::WiFiSignalSensor *wifi_signal_wifisignalsensor;
sensor::QuantileFilter *sensor_quantilefilter;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent_2;
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_MODE[16] = {255, 255, INPUT, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_LEVEL[16] = {255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
#define yield() esphome::yield()
#define millis() esphome::millis()
#define micros() esphome::micros()
#define delay(x) esphome::delay(x)
#define delayMicroseconds(x) esphome::delayMicroseconds(x)
// ========== AUTO GENERATED INCLUDE BLOCK END ==========="

void setup() {
  // ========== AUTO GENERATED CODE BEGIN ===========
  // esp8266:
  //   board: d1_mini_lite
  //   framework:
  //     version: 3.0.2
  //     source: ~3.30002.0
  //     platform_version: platformio/espressif8266 @ 3.2.0
  //   restore_from_flash: false
  //   early_pin_init: true
  //   board_flash_mode: dout
  esphome::esp8266::setup_preferences();
  // async_tcp:
  //   {}
  // esphome:
  //   name: qualita-aria-dk-camera
  //   comment: Sensore qualita aria IKEA camera Andrea Danimarca
  //   build_path: .esphome/build/qualita-aria-dk-camera
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("qualita-aria-dk-camera", __DATE__ ", " __TIME__, false);
  // logger:
  //   id: logger_logger
  //   baud_rate: 115200
  //   tx_buffer_size: 512
  //   deassert_rts_dtr: false
  //   hardware_uart: UART0
  //   level: DEBUG
  //   logs: {}
  //   esp8266_store_log_strings_in_flash: true
  logger_logger = new logger::Logger(115200, 512, logger::UART_SELECTION_UART0);
  logger_logger->pre_setup();
  logger_logger->set_component_source("logger");
  App.register_component(logger_logger);
  // web_server_base:
  //   id: web_server_base_webserverbase
  web_server_base_webserverbase = new web_server_base::WebServerBase();
  web_server_base_webserverbase->set_component_source("web_server_base");
  App.register_component(web_server_base_webserverbase);
  // captive_portal:
  //   id: captive_portal_captiveportal
  //   web_server_base_id: web_server_base_webserverbase
  captive_portal_captiveportal = new captive_portal::CaptivePortal(web_server_base_webserverbase);
  captive_portal_captiveportal->set_component_source("captive_portal");
  App.register_component(captive_portal_captiveportal);
  // wifi:
  //   ap:
  //     ssid: Qualita Aria Dk Camera
  //     password: Pippero64
  //     id: wifi_wifiap
  //     ap_timeout: 1min
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   power_save_mode: NONE
  //   fast_connect: false
  //   output_power: 20.0
  //   networks:
  //   - ssid: !secret 'wifi_ssid_dk'
  //     password: !secret 'wifi_password_dk'
  //     id: wifi_wifiap_2
  //     priority: 0.0
  //   use_address: qualita-aria-dk-camera.local
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("qualita-aria-dk-camera.local");
  wifi::WiFiAP wifi_wifiap_2 = wifi::WiFiAP();
  wifi_wifiap_2.set_ssid("Silence of the LANs");
  wifi_wifiap_2.set_password("123Sushi");
  wifi_wifiap_2.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap_2);
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Qualita Aria Dk Camera");
  wifi_wifiap.set_password("Pippero64");
  wifi_wificomponent->set_ap(wifi_wifiap);
  wifi_wificomponent->set_ap_timeout(60000);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(false);
  wifi_wificomponent->set_output_power(20.0f);
  wifi_wificomponent->set_component_source("wifi");
  App.register_component(wifi_wificomponent);
  // mdns:
  //   id: mdns_mdnscomponent
  //   disabled: false
  mdns_mdnscomponent = new mdns::MDNSComponent();
  mdns_mdnscomponent->set_component_source("mdns");
  App.register_component(mdns_mdnscomponent);
  // ota:
  //   password: 5bda3bca66e736daa257da373f1f8d57
  //   id: ota_otacomponent
  //   safe_mode: true
  //   port: 8266
  //   reboot_timeout: 5min
  //   num_attempts: 10
  ota_otacomponent = new ota::OTAComponent();
  ota_otacomponent->set_port(8266);
  ota_otacomponent->set_auth_password("5bda3bca66e736daa257da373f1f8d57");
  ota_otacomponent->set_component_source("ota");
  App.register_component(ota_otacomponent);
  if (ota_otacomponent->should_enter_safe_mode(10, 300000)) return;
  // mqtt:
  //   broker: !secret 'mqtt_broker'
  //   id: mqtt_mqttclientcomponent
  //   port: 1883
  //   username: ''
  //   password: ''
  //   discovery: true
  //   discovery_retain: true
  //   discovery_prefix: homeassistant
  //   discovery_unique_id_generator: legacy
  //   discovery_object_id_generator: none
  //   use_abbreviations: true
  //   topic_prefix: qualita-aria-dk-camera
  //   keepalive: 15s
  //   reboot_timeout: 15min
  //   birth_message:
  //     topic: qualita-aria-dk-camera/status
  //     payload: online
  //     qos: 0
  //     retain: true
  //   will_message:
  //     topic: qualita-aria-dk-camera/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   shutdown_message:
  //     topic: qualita-aria-dk-camera/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   log_topic:
  //     topic: qualita-aria-dk-camera/debug
  //     qos: 0
  //     retain: true
  mqtt_mqttclientcomponent = new mqtt::MQTTClientComponent();
  mqtt_mqttclientcomponent->set_component_source("mqtt");
  App.register_component(mqtt_mqttclientcomponent);
  mqtt_mqttclientcomponent->set_broker_address("myhomeipdk.hopto.org");
  mqtt_mqttclientcomponent->set_broker_port(1883);
  mqtt_mqttclientcomponent->set_username("");
  mqtt_mqttclientcomponent->set_password("");
  mqtt_mqttclientcomponent->set_discovery_info("homeassistant", mqtt::MQTT_LEGACY_UNIQUE_ID_GENERATOR, mqtt::MQTT_NONE_OBJECT_ID_GENERATOR, true);
  mqtt_mqttclientcomponent->set_topic_prefix("qualita-aria-dk-camera");
  mqtt_mqttclientcomponent->set_birth_message(mqtt::MQTTMessage{
      .topic = "qualita-aria-dk-camera/status",
      .payload = "online",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_last_will(mqtt::MQTTMessage{
      .topic = "qualita-aria-dk-camera/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_shutdown_message(mqtt::MQTTMessage{
      .topic = "qualita-aria-dk-camera/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_log_message_template(mqtt::MQTTMessage{
      .topic = "qualita-aria-dk-camera/debug",
      .payload = "",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_keep_alive(15);
  mqtt_mqttclientcomponent->set_reboot_timeout(900000);
  // sensor:
  // json:
  //   {}
  // preferences:
  //   id: preferences_intervalsyncer
  //   flash_write_interval: 60s
  preferences_intervalsyncer = new preferences::IntervalSyncer();
  preferences_intervalsyncer->set_write_interval(60000);
  preferences_intervalsyncer->set_component_source("preferences");
  App.register_component(preferences_intervalsyncer);
  // uart:
  //   rx_pin:
  //     number: 2
  //     mode:
  //       input: true
  //       analog: false
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esphome_esp8266_esp8266gpiopin
  //     inverted: false
  //   baud_rate: 9600
  //   id: uart_esp8266uartcomponent
  //   rx_buffer_size: 256
  //   stop_bits: 1
  //   data_bits: 8
  //   parity: NONE
  uart_esp8266uartcomponent = new uart::ESP8266UartComponent();
  uart_esp8266uartcomponent->set_component_source("uart");
  App.register_component(uart_esp8266uartcomponent);
  uart_esp8266uartcomponent->set_baud_rate(9600);
  esphome_esp8266_esp8266gpiopin = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin->set_pin(2);
  esphome_esp8266_esp8266gpiopin->set_inverted(false);
  esphome_esp8266_esp8266gpiopin->set_flags(gpio::Flags::FLAG_INPUT);
  uart_esp8266uartcomponent->set_rx_pin(esphome_esp8266_esp8266gpiopin);
  uart_esp8266uartcomponent->set_rx_buffer_size(256);
  uart_esp8266uartcomponent->set_stop_bits(1);
  uart_esp8266uartcomponent->set_data_bits(8);
  uart_esp8266uartcomponent->set_parity(uart::UART_CONFIG_PARITY_NONE);
  // sensor.pm1006:
  //   platform: pm1006
  //   pm_2_5:
  //     name: Qualita Aria Dk Camera Andrea
  //     disabled_by_default: false
  //     mqtt_id: mqtt_mqttsensorcomponent
  //     id: sensor_sensor
  //     force_update: false
  //     unit_of_measurement: µg/m³
  //     icon: mdi:blur
  //     accuracy_decimals: 0
  //     device_class: pm25
  //     state_class: measurement
  //   id: pm1006_pm1006component
  //   uart_id: uart_esp8266uartcomponent
  //   update_interval: 4294967295
  pm1006_pm1006component = new pm1006::PM1006Component();
  pm1006_pm1006component->set_update_interval(4294967295UL);
  pm1006_pm1006component->set_component_source("pm1006.sensor");
  App.register_component(pm1006_pm1006component);
  pm1006_pm1006component->set_uart_parent(uart_esp8266uartcomponent);
  sensor_sensor = new sensor::Sensor();
  App.register_sensor(sensor_sensor);
  sensor_sensor->set_name("Qualita Aria Dk Camera Andrea");
  sensor_sensor->set_disabled_by_default(false);
  sensor_sensor->set_icon("mdi:blur");
  sensor_sensor->set_device_class("pm25");
  sensor_sensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  sensor_sensor->set_unit_of_measurement("\302\265g/m\302\263");
  sensor_sensor->set_accuracy_decimals(0);
  sensor_sensor->set_force_update(false);
  mqtt_mqttsensorcomponent = new mqtt::MQTTSensorComponent(sensor_sensor);
  mqtt_mqttsensorcomponent->set_component_source("mqtt");
  App.register_component(mqtt_mqttsensorcomponent);
  pm1006_pm1006component->set_pm_2_5_sensor(sensor_sensor);
  // sensor.wifi_signal:
  //   platform: wifi_signal
  //   name: WiFi Signal qualita Aria Dk Camera-Andrea
  //   update_interval: 60s
  //   filters:
  //   - quantile:
  //       window_size: 7
  //       send_every: 4
  //       send_first_at: 3
  //       quantile: 0.9
  //     type_id: sensor_quantilefilter
  //   disabled_by_default: false
  //   mqtt_id: mqtt_mqttsensorcomponent_2
  //   force_update: false
  //   id: wifi_signal_wifisignalsensor
  //   unit_of_measurement: dBm
  //   accuracy_decimals: 0
  //   device_class: signal_strength
  //   state_class: measurement
  //   entity_category: diagnostic
  wifi_signal_wifisignalsensor = new wifi_signal::WiFiSignalSensor();
  App.register_sensor(wifi_signal_wifisignalsensor);
  wifi_signal_wifisignalsensor->set_name("WiFi Signal qualita Aria Dk Camera-Andrea");
  wifi_signal_wifisignalsensor->set_disabled_by_default(false);
  wifi_signal_wifisignalsensor->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_signal_wifisignalsensor->set_device_class("signal_strength");
  wifi_signal_wifisignalsensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  wifi_signal_wifisignalsensor->set_unit_of_measurement("dBm");
  wifi_signal_wifisignalsensor->set_accuracy_decimals(0);
  wifi_signal_wifisignalsensor->set_force_update(false);
  sensor_quantilefilter = new sensor::QuantileFilter(7, 4, 3, 0.9f);
  wifi_signal_wifisignalsensor->set_filters({sensor_quantilefilter});
  mqtt_mqttsensorcomponent_2 = new mqtt::MQTTSensorComponent(wifi_signal_wifisignalsensor);
  mqtt_mqttsensorcomponent_2->set_component_source("mqtt");
  App.register_component(mqtt_mqttsensorcomponent_2);
  wifi_signal_wifisignalsensor->set_update_interval(60000);
  wifi_signal_wifisignalsensor->set_component_source("wifi_signal.sensor");
  App.register_component(wifi_signal_wifisignalsensor);
  // socket:
  //   implementation: lwip_tcp
  // network:
  //   {}
  // =========== AUTO GENERATED CODE END ============
  App.setup();
}

void loop() {
  App.loop();
}
