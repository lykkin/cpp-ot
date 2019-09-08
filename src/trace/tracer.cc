#include <iostream>

#include "open-telemetry/trace/tracer.h"

namespace ot {
namespace trace {
Tracer::Tracer(): current_span(nullptr) {}
Span* Tracer::start_span(const std::string& name) {
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
  std::cout << "{" << std::endl;
  std::cout << "  \"name\": \"" << span->get_name()
    << "\"," << std::endl;
  std::cout << "  \"timestamp\": " << span->get_start_time().count()
    << "," << std::endl;
  std::cout << "  \"duration\": " << span->get_duration().count()
    << "," << std::endl;
  span->print_attributes();
  std::cout << "}" << std::endl;
}
}  // namespace trace
}  // namespace ot
