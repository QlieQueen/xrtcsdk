#include "xrtc/base/xrtc_global.h"

namespace xrtc {

XRTCGlobal* XRTCGlobal::Instance() {
	static XRTCGlobal* const instance = new XRTCGlobal();
	return instance;
}

XRTCGlobal::XRTCGlobal() :
	api_thread_(rtc::Thread::Create()),
	worker_thread_(rtc::Thread::Create()),
	network_thread_(rtc::Thread::CreateWithSocketServer())
{
	api_thread_->SetName("api_threrad", nullptr);
	api_thread_->Start();

	worker_thread_->SetName("worker_threrad", nullptr);
	worker_thread_->Start();

	network_thread_->SetName("network_threrad", nullptr);
	network_thread_->Start();
}

XRTCGlobal::~XRTCGlobal() {

}

}