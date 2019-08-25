#include <string>
#include <array>

typedef std::array<char, 16> TraceId;
typedef std::array<char, 8> SpanId;
//typedef TraceOptions struct {
//  bool recorded
//}
//
//typedef TraceState struct {
//  std::string state
//}

class SpanContext {
  TraceId* trace_id;
  SpanId span_id;
  //TraceOptions options;
  //TraceState* state;
  //bool is_valid;
public:
  SpanContext(const SpanContext* const);
};
