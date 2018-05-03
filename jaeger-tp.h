#undef TRACEPOINT_PROVIDER
#define TRACEPOINT_PROVIDER jaeger_ust

#undef TRACEPOINT_INCLUDE
#define TRACEPOINT_INCLUDE "./jaeger-tp.h"

#if !defined(_TP_H) || defined(TRACEPOINT_HEADER_MULTI_READ)
#define _TP_H

#include <lttng/tracepoint.h>

TRACEPOINT_EVENT(
    jaeger_ust,
    start_span,

    /* Input arguments */
    TP_ARGS(
        uint64_t, t_id_h,
        uint64_t, t_id_l,
        uint64_t, s_id,
        uint64_t, s_p_id,
        char*, o_name,
        int64_t, s_time
    ),

    /* Output event fields */
    TP_FIELDS(
        ctf_integer(uint64_t, trace_id_high, t_id_h)
        ctf_integer(uint64_t, trace_id_low, t_id_l)
        ctf_integer(uint64_t, span_id, s_id)
        ctf_integer(uint64_t, parent_span_id, s_p_id)
        ctf_string(op_name, o_name)
        ctf_integer(int64_t, start_time, s_time)
    )
)

TRACEPOINT_EVENT(
    jaeger_ust,
    end_span,

    /* Input arguments */
    TP_ARGS(
        uint64_t, t_id_h,
        uint64_t, t_id_l,
        uint64_t, s_id,
        int64_t, dur
    ),

    /* Output event fields */
    TP_FIELDS(
        ctf_integer(uint64_t, trace_id_high, t_id_h)
        ctf_integer(uint64_t, trace_id_low, t_id_l)
        ctf_integer(uint64_t, span_id, s_id)
        ctf_integer(int64_t, duration, dur)
    )
)

#endif /* _TP_H */

#include <lttng/tracepoint-event.h>