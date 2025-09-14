#include "xrtc/xrtc.h"

#include <rtc_base/logging.h>
#include <rtc_base/task_utils/to_queued_task.h>

#include "xrtc/base/xrtc_global.h"

namespace xrtc {

int test() {
	rtc::LogMessage::ConfigureLogging("thread");
	return 0;
}

void XRTCEngine::Init()
{
	XRTCGlobal::Instance()->api_thread()->PostTask(webrtc::ToQueuedTask([=]() {
		int a = 1;
	}));

	int b = 1;
}

} // namespace xrtc