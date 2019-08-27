#include "trace/span.h"

std::chrono::milliseconds get_timestamp();
std::chrono::milliseconds get_timestamp() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::system_clock::now().time_since_epoch()
  );
}

Span::Span(
    std::string name,
    Tracer* const t,
    const SpanContext* const parent = nullptr
  ) :
  tracer(t),
  name(name),
  context(new SpanContext(parent)),
  parent_context(parent),
  start_time(get_timestamp()),
  end_time(0)
{}

void Span::set_name(std::string n) {
  name = n;
}

void Span::end() {
  end_time = get_timestamp();
}

void Span::end(std::chrono::milliseconds e) {
  end_time = e;
  tracer->on_span_end(this);
}

bool Span::is_ended() const {
  return end_time == std::chrono::milliseconds(0);
}

void Span::add_attribute(std::string k, const double v) {
  attributes[k] = std::make_unique<const double>(v);
}

void Span::add_attribute(std::string k, const std::string v) {
  attributes[k] = std::make_unique<const std::string>(v);
}

void Span::add_attribute(std::string k, const bool v) {
  attributes[k] = std::make_unique<const bool>(v);
}

void Span::add_attribute(std::string k, const int64_t v) {
  attributes[k] = std::make_unique<const int64_t>(v);
}

const SpanContext* Span::get_context() const {
  return context;
}

const SpanContext* Span::get_parent_context() const {
  return parent_context;
}
