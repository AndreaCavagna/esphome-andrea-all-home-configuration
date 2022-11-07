// Auto generated code by esphome
// ========== AUTO GENERATED INCLUDE BLOCK BEGIN ===========
#include "esphome.h"
using namespace esphome;
using std::isnan;
using std::min;
using std::max;
using namespace binary_sensor;
logger::Logger *logger_logger;
wifi::WiFiComponent *wifi_wificomponent;
mdns::MDNSComponent *mdns_mdnscomponent;
ota::OTAComponent *ota_otacomponent;
mqtt::MQTTClientComponent *mqtt_mqttclientcomponent;
using namespace mqtt;
using namespace sensor;
using namespace json;
preferences::IntervalSyncer *preferences_intervalsyncer;
gpio::GPIOBinarySensor *gpio_gpiobinarysensor;
mqtt::MQTTBinarySensorComponent *mqtt_mqttbinarysensorcomponent;
esphome::esp8266::ESP8266GPIOPin *esphome_esp8266_esp8266gpiopin;
wifi_signal::WiFiSignalSensor *wifi_signal_wifisignalsensor;
sensor::QuantileFilter *sensor_quantilefilter;
mqtt::MQTTSensorComponent *mqtt_mqttsensorcomponent;
const uint8_t ESPHOME_ESP8266_GPIO_INITIAL_MODE[16] = {INPUT, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255};
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
  // esphome:
  //   name: esp8266-dk-ingresso
  //   comment: Sensore movimento ingresso andrea danimarca
  //   build_path: .esphome/build/esp8266-dk-ingresso
  //   platformio_options: {}
  //   includes: []
  //   libraries: []
  //   name_add_mac_suffix: false
  App.pre_setup("esp8266-dk-ingresso", __DATE__ ", " __TIME__, false);
  // binary_sensor:
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
  // wifi:
  //   manual_ip:
  //     static_ip: 192.168.123.229
  //     gateway: 192.168.123.1
  //     subnet: 255.255.255.0
  //     dns1: 0.0.0.0
  //     dns2: 0.0.0.0
  //   fast_connect: true
  //   output_power: 12.0
  //   power_save_mode: NONE
  //   id: wifi_wificomponent
  //   domain: .local
  //   reboot_timeout: 15min
  //   networks:
  //   - ssid: !secret 'wifi_ssid_dk'
  //     password: !secret 'wifi_password_dk'
  //     id: wifi_wifiap
  //     priority: 0.0
  //   use_address: 192.168.123.229
  wifi_wificomponent = new wifi::WiFiComponent();
  wifi_wificomponent->set_use_address("192.168.123.229");
  wifi::WiFiAP wifi_wifiap = wifi::WiFiAP();
  wifi_wifiap.set_ssid("Silence of the LANs");
  wifi_wifiap.set_password("123Sushi");
  wifi_wifiap.set_manual_ip(wifi::ManualIP{
      .static_ip = network::IPAddress(192, 168, 123, 229),
      .gateway = network::IPAddress(192, 168, 123, 1),
      .subnet = network::IPAddress(255, 255, 255, 0),
      .dns1 = network::IPAddress(0, 0, 0, 0),
      .dns2 = network::IPAddress(0, 0, 0, 0),
  });
  wifi_wifiap.set_priority(0.0f);
  wifi_wificomponent->add_sta(wifi_wifiap);
  wifi_wificomponent->set_reboot_timeout(900000);
  wifi_wificomponent->set_power_save_mode(wifi::WIFI_POWER_SAVE_NONE);
  wifi_wificomponent->set_fast_connect(true);
  wifi_wificomponent->set_output_power(12.0f);
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
  //   broker: !secret 'mqtt_broker_local'
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
  //   topic_prefix: esp8266-dk-ingresso
  //   keepalive: 15s
  //   reboot_timeout: 15min
  //   birth_message:
  //     topic: esp8266-dk-ingresso/status
  //     payload: online
  //     qos: 0
  //     retain: true
  //   will_message:
  //     topic: esp8266-dk-ingresso/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   shutdown_message:
  //     topic: esp8266-dk-ingresso/status
  //     payload: offline
  //     qos: 0
  //     retain: true
  //   log_topic:
  //     topic: esp8266-dk-ingresso/debug
  //     qos: 0
  //     retain: true
  mqtt_mqttclientcomponent = new mqtt::MQTTClientComponent();
  mqtt_mqttclientcomponent->set_component_source("mqtt");
  App.register_component(mqtt_mqttclientcomponent);
  mqtt_mqttclientcomponent->set_broker_address("192.168.123.16");
  mqtt_mqttclientcomponent->set_broker_port(1883);
  mqtt_mqttclientcomponent->set_username("");
  mqtt_mqttclientcomponent->set_password("");
  mqtt_mqttclientcomponent->set_discovery_info("homeassistant", mqtt::MQTT_LEGACY_UNIQUE_ID_GENERATOR, mqtt::MQTT_NONE_OBJECT_ID_GENERATOR, true);
  mqtt_mqttclientcomponent->set_topic_prefix("esp8266-dk-ingresso");
  mqtt_mqttclientcomponent->set_birth_message(mqtt::MQTTMessage{
      .topic = "esp8266-dk-ingresso/status",
      .payload = "online",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_last_will(mqtt::MQTTMessage{
      .topic = "esp8266-dk-ingresso/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_shutdown_message(mqtt::MQTTMessage{
      .topic = "esp8266-dk-ingresso/status",
      .payload = "offline",
      .qos = 0,
      .retain = true,
  });
  mqtt_mqttclientcomponent->set_log_message_template(mqtt::MQTTMessage{
      .topic = "esp8266-dk-ingresso/debug",
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
  // binary_sensor.gpio:
  //   platform: gpio
  //   pin:
  //     number: 0
  //     mode:
  //       input: true
  //       analog: false
  //       output: false
  //       open_drain: false
  //       pullup: false
  //       pulldown: false
  //     id: esphome_esp8266_esp8266gpiopin
  //     inverted: false
  //   name: Sensore Movimento Ingresso Danimarca
  //   device_class: motion
  //   disabled_by_default: false
  //   mqtt_id: mqtt_mqttbinarysensorcomponent
  //   id: gpio_gpiobinarysensor
  gpio_gpiobinarysensor = new gpio::GPIOBinarySensor();
  App.register_binary_sensor(gpio_gpiobinarysensor);
  gpio_gpiobinarysensor->set_name("Sensore Movimento Ingresso Danimarca");
  gpio_gpiobinarysensor->set_disabled_by_default(false);
  gpio_gpiobinarysensor->set_device_class("motion");
  mqtt_mqttbinarysensorcomponent = new mqtt::MQTTBinarySensorComponent(gpio_gpiobinarysensor);
  mqtt_mqttbinarysensorcomponent->set_component_source("mqtt");
  App.register_component(mqtt_mqttbinarysensorcomponent);
  gpio_gpiobinarysensor->set_component_source("gpio.binary_sensor");
  App.register_component(gpio_gpiobinarysensor);
  esphome_esp8266_esp8266gpiopin = new esphome::esp8266::ESP8266GPIOPin();
  esphome_esp8266_esp8266gpiopin->set_pin(0);
  esphome_esp8266_esp8266gpiopin->set_inverted(false);
  esphome_esp8266_esp8266gpiopin->set_flags(gpio::Flags::FLAG_INPUT);
  gpio_gpiobinarysensor->set_pin(esphome_esp8266_esp8266gpiopin);
  // sensor.wifi_signal:
  //   platform: wifi_signal
  //   name: WiFi Signal esp8266-dk-ingresso
  //   update_interval: 60s
  //   filters:
  //   - quantile:
  //       window_size: 7
  //       send_every: 4
  //       send_first_at: 3
  //       quantile: 0.9
  //     type_id: sensor_quantilefilter
  //   disabled_by_default: false
  //   mqtt_id: mqtt_mqttsensorcomponent
  //   force_update: false
  //   id: wifi_signal_wifisignalsensor
  //   unit_of_measurement: dBm
  //   accuracy_decimals: 0
  //   device_class: signal_strength
  //   state_class: measurement
  //   entity_category: diagnostic
  wifi_signal_wifisignalsensor = new wifi_signal::WiFiSignalSensor();
  App.register_sensor(wifi_signal_wifisignalsensor);
  wifi_signal_wifisignalsensor->set_name("WiFi Signal esp8266-dk-ingresso");
  wifi_signal_wifisignalsensor->set_disabled_by_default(false);
  wifi_signal_wifisignalsensor->set_entity_category(::ENTITY_CATEGORY_DIAGNOSTIC);
  wifi_signal_wifisignalsensor->set_device_class("signal_strength");
  wifi_signal_wifisignalsensor->set_state_class(sensor::STATE_CLASS_MEASUREMENT);
  wifi_signal_wifisignalsensor->set_unit_of_measurement("dBm");
  wifi_signal_wifisignalsensor->set_accuracy_decimals(0);
  wifi_signal_wifisignalsensor->set_force_update(false);
  sensor_quantilefilter = new sensor::QuantileFilter(7, 4, 3, 0.9f);
  wifi_signal_wifisignalsensor->set_filters({sensor_quantilefilter});
  mqtt_mqttsensorcomponent = new mqtt::MQTTSensorComponent(wifi_signal_wifisignalsensor);
  mqtt_mqttsensorcomponent->set_component_source("mqtt");
  App.register_component(mqtt_mqttsensorcomponent);
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
