/*
 * Copyright (C) 2026 MillenniumOSS
 * SPDX-License-Identifer: Apache-2.0
 */

#define LOG_TAG "TRANCAM_DEBUG"

#include "Trancamserver.h"
#include <log/log.h>

namespace vendor {
namespace transsion {
namespace hardware {
namespace trancam {
namespace trancamserver {
namespace V1_0 {
namespace implementation {

Trancamserver *Trancamserver::sInstance = nullptr;

Trancamserver::Trancamserver() { ALOGD("Trancamserver"); }

Trancamserver::~Trancamserver() { ALOGD("~Trancamserver"); }

sp<ITrancamserver> Trancamserver::getInstance() {
  if (sInstance == nullptr) {
    sInstance = new Trancamserver();
  }
  return sInstance;
}

Return<void> Trancamserver::setPackagename(const hidl_string &packagename) {
  mPackagename = packagename;
  return Void();
}

Return<void> Trancamserver::getPackagename(getPackagename_cb _hidl_cb) {
  _hidl_cb(mPackagename);
  return Void();
}

Return<void>
Trancamserver::setEventCallback(const sp<IEventCallback> &callback) {
  ALOGV("setEventCallback+");
  if (callback == nullptr) {
    ALOGV("App HIDL trancamserver::V1_0::IEventCallback function is empty, "
          "callback=%p",
          nullptr);
  }
  mEventCallback = callback;
  ALOGD("setEventCallback-");
  return Void();
}

Return<void> Trancamserver::getEventCallback(getEventCallback_cb _hidl_cb) {
  _hidl_cb(mEventCallback);
  return Void();
}

} // namespace implementation
} // namespace V1_0
} // namespace trancamserver
} // namespace trancam
} // namespace hardware
} // namespace transsion
} // namespace vendor
