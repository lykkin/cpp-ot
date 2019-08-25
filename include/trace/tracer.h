#include "trace/span.h"
#include <string>

class Tracer {
  Span* current_span;
  // Sampler sampler;
public:
  Tracer();
  Span* get_current_span() const;
  void set_current_span(Span*);
  Span* start_span(std::string);
};
