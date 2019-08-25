#ifndef INCLUDE_TRACE_SPAN_CONTEXT_H_
#define INCLUDE_TRACE_SPAN_CONTEXT_H_
#include <string>
#include <array>

typedef std::array<char, 16> TraceId;
typedef std::array<char, 8> SpanId;
// typedef TraceOptions struct {
//   bool recorded
// }
//
// typedef TraceState struct {
//   std::string state
// }

class SpanContext final {
 public:
  explicit SpanContext(const SpanContext* const);
 private:
  TraceId* trace_id;
  SpanId span_id;
  // TraceOptions options;
  // TraceState* state;
  // bool is_valid;
};
#endif  // INCLUDE_TRACE_SPAN_CONTEXT_H_
