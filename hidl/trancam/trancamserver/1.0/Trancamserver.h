/*
 * Copyright (C) 2026 MillenniumOSS
 * SPDX-License-Identifer: Apache-2.0
 */
#pragma once

#include <hidl/MQDescriptor.h>
#include <hidl/Status.h>
#include <vendor/transsion/hardware/trancam/trancamserver/1.0/IEventCallback.h>
#include <vendor/transsion/hardware/trancam/trancamserver/1.0/ITrancamserver.h>

namespace vendor {
namespace transsion {
namespace hardware {
namespace trancam {
namespace trancamserver {
namespace V1_0 {
namespace implementation {

using ::android::sp;
using ::android::hardware::hidl_string;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::vendor::transsion::hardware::trancam::trancamserver::V1_0::
    IEventCallback;
using ::vendor::transsion::hardware::trancam::trancamserver::V1_0::
    ITrancamserver;

struct Trancamserver : public ITrancamserver {
public:
  Trancamserver();
  ~Trancamserver();

  static sp<ITrancamserver> getInstance();

  Return<void> setPackagename(const hidl_string &packagename) override;
  Return<void> getPackagename(getPackagename_cb _hidl_cb) override;
  Return<void> setEventCallback(const sp<IEventCallback> &callback) override;
  Return<void> getEventCallback(getEventCallback_cb _hidl_cb) override;

private:
  static Trancamserver *sInstance;

  hidl_string mPackagename;
  sp<IEventCallback> mEventCallback;
};

} // namespace implementation
} // namespace V1_0
} // namespace trancamserver
} // namespace trancam
} // namespace hardware
} // namespace transsion
} // namespace vendor
