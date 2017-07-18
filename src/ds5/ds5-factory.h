// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2015 Intel Corporation. All Rights Reserved.
#pragma once

#include "ds5-private.h"

namespace librealsense
{
    class ds5_info : public device_info
    {
    public:
        std::shared_ptr<device_interface> create(const platform::backend& backend) const override;

        ds5_info(std::shared_ptr<platform::backend> backend,
                 std::vector<platform::uvc_device_info> depth,
                 std::vector<platform::usb_device_info> hwm,
                 std::vector<platform::hid_device_info> hid)
            : device_info(std::move(backend)), _depth(std::move(depth)),
              _hwm(std::move(hwm)), _hid(std::move(hid)) {}

        static std::vector<std::shared_ptr<device_info>> pick_ds5_devices(
                std::shared_ptr<platform::backend> backend,
                platform::backend_device_group& gproup);

        platform::backend_device_group get_device_data() const override
        {
            return platform::backend_device_group(_depth, _hwm, _hid);
        }
    private:
        std::vector<platform::uvc_device_info> _depth;
        std::vector<platform::usb_device_info> _hwm;
        std::vector<platform::hid_device_info> _hid;
    };
}