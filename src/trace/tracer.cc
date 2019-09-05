#include "trace/tracer.h"
Tracer::Tracer(): current_span(nullptr) {}
Span* Tracer::start_span(std::string name) {
  auto span = new Span(
    name,
    this,
    current_span ? current_span->get_context() : nullptr
  );
  current_span = span;
  return span;
}

Span* Tracer::get_current_span() const {
  return current_span;
}

void Tracer::set_current_span(Span* s) {
  current_span = s;
}

void Tracer::on_span_end(const Span* const span) {
  span->get_context()->get_trace_id();
}
