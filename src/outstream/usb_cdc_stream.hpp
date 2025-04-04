#pragma once

#include "outstream.hpp"
#include <tusb.h>

namespace piccante::usb_cdc {
class USB_CDC_Sink : public outstream::CustomSink {
        public:
    explicit USB_CDC_Sink(uint8_t itf) : itf(itf) {}
    USB_CDC_Sink() = default;
    void write(const char* v, std::size_t s) override;
    void flush() override;

        private:
    uint8_t itf = 0;
};


inline USB_CDC_Sink usb_cdc_sink0(0);
inline outstream::Stream<char> out0(usb_cdc_sink0);

inline USB_CDC_Sink usb_cdc_sink1(1);
inline outstream::Stream<char> out1(usb_cdc_sink1);

} // namespace usb_cdc
