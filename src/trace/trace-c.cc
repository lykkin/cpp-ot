#include "../../include/open-telemetry/trace/trace-c.h"

// TRACER METHODS
Tracer* tracer_create() {
  return reinterpret_cast<Tracer*>(new ot::trace::Tracer());
}
void tracer_destroy(Tracer* v) {
  delete reinterpret_cast<ot::trace::Tracer*>(v);
}
Span* tracer_get_current_span(const Tracer* const t) {
  return reinterpret_cast<Span*>(
    reinterpret_cast<const ot::trace::Tracer* const>(t)->get_current_span()
  );
}
void tracer_set_current_span(Tracer* const t, Span* s) {
  return reinterpret_cast<ot::trace::Tracer* const>(t)->set_current_span(
    reinterpret_cast<ot::trace::Span*>(s)
  );
}
Span* tracer_start_span(Tracer* const t, const char* name) {
  return reinterpret_cast<Span*>(
    reinterpret_cast<ot::trace::Tracer* const>(t)->start_span(name)
  );
}
void tracer_on_span_end(Tracer* const t, const Span* const s) {
  return reinterpret_cast<ot::trace::Tracer* const>(t)->on_span_end(
    reinterpret_cast<const ot::trace::Span* const>(s)
  );
}

// SPAN METHODS
Span* span_create(
  const char* name,
  Tracer* const t,
  const SpanContext* const ctx
) {
  return reinterpret_cast<Span*>(
    new ot::trace::Span(
      name,
      reinterpret_cast<ot::trace::Tracer* const>(t),
      reinterpret_cast<const ot::trace::SpanContext* const>(ctx)
    )
  );
}
void span_destroy(Span* v) {
  delete reinterpret_cast<ot::trace::Span*>(v);
}
void span_end(Span* s) {
  reinterpret_cast<ot::trace::Span*>(s)->end();
}

void span_set_aux(Span* const s, void* ptr) {
  reinterpret_cast<ot::trace::Span* const>(s)->set_aux(ptr);
}

void* span_get_aux(const Span* const s) {
  return reinterpret_cast<const ot::trace::Span* const>(s)->get_aux();
}