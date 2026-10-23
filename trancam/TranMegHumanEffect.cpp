/*
 * Copyright (C) 2026 MillenniumOSS
 * SPDX-License-Identifier: Apache-2.0
 */

struct YuvBufInfo;
struct tran_cam_algo_param_t;

namespace android {

struct TranMegHumanEffect {
    TranMegHumanEffect(int);
    virtual int init(tran_cam_algo_param_t*) { return 0; }
    virtual int unInit() { return 0; }
    virtual int processRaw(YuvBufInfo*, tran_cam_algo_param_t*) { return 0; }
    virtual int processPreview(YuvBufInfo*, tran_cam_algo_param_t*) { return 0; }
    virtual ~TranMegHumanEffect() = default;
};

TranMegHumanEffect::TranMegHumanEffect(int) {}

};
