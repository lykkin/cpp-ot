#ifndef INCLUDE_TRACE_TRACER_H_
#define INCLUDE_TRACE_TRACER_H_
#include <string>
#include "./span.h"

class Span;
class Tracer {
 public:
  Tracer();
  Span* get_current_span() const;
  void set_current_span(Span*);
  Span* start_span(std::string);
  void on_span_end(const Span* const);

 private:
  Span* current_span;
  // Sampler sampler;
};
#endif  // INCLUDE_TRACE_TRACER_H_
