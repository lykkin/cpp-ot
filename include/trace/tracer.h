#ifndef INCLUDE_TRACE_TRACER_H_
#define INCLUDE_TRACE_TRACER_H_
#include <string>
#include "./span.h"

class Tracer {
 public:
  Tracer();
  Span* get_current_span() const;
  void set_current_span(Span*);
  Span* start_span(std::string);

 private:
  Span* current_span;
  // Sampler sampler;
};
#endif  // INCLUDE_TRACE_TRACER_H_
