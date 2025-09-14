#ifndef XRTCSDK_XRTC_BASE_XRTC_GLOBAL_H_
#define XRTCSDK_XRTC_BASE_XRTC_GLOBAL_H_

#include <rtc_base/thread.h>

namespace xrtc {

// µ¥ÀýÄ£Ê½
class XRTCGlobal {
public:
	static XRTCGlobal* Instance();

	rtc::Thread* api_thread() { return api_thread_.get(); }
	rtc::Thread* worker_thread() { return api_thread_.get(); }
	rtc::Thread* network_thread() { return api_thread_.get(); }

private:
	XRTCGlobal();
	~XRTCGlobal();
private:
	std::unique_ptr<rtc::Thread> api_thread_;
	std::unique_ptr<rtc::Thread> worker_thread_;
	std::unique_ptr<rtc::Thread> network_thread_;
};

} // namespace xrtc

#endif // XRTCSDK_XRTC_BASE_XRTC_GLOBAL_H_