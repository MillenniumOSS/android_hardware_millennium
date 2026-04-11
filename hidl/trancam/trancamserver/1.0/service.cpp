/*
 * Copyright (C) 2026 MillenniumOSS
 * SPDX-License-Identifer: Apache-2.0
 */

#define LOG_TAG "TRANCAM_DEBUG"

#include "Trancamserver.h"
#include <android/log.h>
#include <hidl/HidlSupport.h>
#include <hidl/HidlTransportSupport.h>
#include <vendor/transsion/hardware/trancam/trancamserver/1.0/ITrancamserver.h>

using android::OK;
using android::sp;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using vendor::transsion::hardware::trancam::trancamserver::V1_0::ITrancamserver;
using vendor::transsion::hardware::trancam::trancamserver::V1_0::
    implementation::Trancamserver;

int main() {
  sp<ITrancamserver> trancamserver = Trancamserver::getInstance();

  configureRpcThreadpool(1, true);

  if (trancamserver != nullptr) {
    if (trancamserver->registerAsService() != OK) {
      ALOGE("Can't register trancamserver as service");
      return 1;
    }
  } else {
    ALOGE("Can't create instance of trancamserver, nullptr");
  }

  joinRpcThreadpool();

  return 0;
}
