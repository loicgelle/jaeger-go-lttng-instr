package lttng

/*
#cgo LDFLAGS: -ldl -llttng-ust

#define TRACEPOINT_DEFINE
#include "jaeger-tp.h"

void traceStartSpan(uint64_t t_id_h, uint64_t t_id_l, uint64_t s_id, uint64_t s_p_id, char* o_name, int64_t s_time) {
	tracepoint(jaeger_ust, start_span, t_id_h, t_id_l, s_id, s_p_id, o_name, s_time);
}

void traceEndSpan(uint64_t t_id_h, uint64_t t_id_l, uint64_t s_id, int64_t dur) {
	tracepoint(jaeger_ust, end_span, t_id_h, t_id_l, s_id, dur);
}
*/
import "C"

import (
	"time"
)

func ReportStartSpan(traceIDHigh uint64, traceIDLow uint64, spanID uint64, parentID uint64, operationName string, startTime time.Time) {
	C.traceStartSpan(
		C.uint64_t(traceIDHigh),
		C.uint64_t(traceIDLow),
		C.uint64_t(spanID),
		C.uint64_t(parentID),
		C.CString(operationName),
		C.int64_t(startTime.UnixNano()),
	)
}

func ReportEndSpan(traceIDHigh uint64, traceIDLow uint64, spanID uint64, duration time.Duration) {
	C.traceEndSpan(
		C.uint64_t(traceIDHigh),
		C.uint64_t(traceIDLow),
		C.uint64_t(spanID),
		C.int64_t(duration.Nanoseconds()),
	)
}