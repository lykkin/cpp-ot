#include <algorithm>
#include <random>

#include "trace/span-context.h"

SpanContext::SpanContext(const SpanContext* const parent){
  std::random_device rd;
  if (parent == nullptr) {
    std::generate(trace_id->begin(), trace_id->end(), [&](){return rd();});
  } else {
    delete trace_id;
    trace_id = parent->trace_id;
  }
  std::generate(span_id.begin(), span_id.end(), [&](){return rd();});
}
