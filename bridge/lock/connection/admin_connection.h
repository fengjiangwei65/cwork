
#include <string.h>
#include <stdint.h>
#include "connection_common.h"

static const char *kTag = "JNI_admin_connection";

// 
int igloohome_ble_lock_crypto_AdminConnection_beginConnection(uint8_t *jKey, int keyLen);
int igloohome_ble_lock_crypto_AdminConnection_genConnStep2Native(int connectionId, 
  uint8_t *jConnectionStep1, int step1Len, uint8_t **retBytes);
bool igloohome_ble_lock_crypto_AdminConnection_recConnStep3Native(
  int connectionId, uint8_t *jConnectionStep3, int messageLen);
