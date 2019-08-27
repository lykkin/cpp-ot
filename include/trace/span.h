#ifndef INCLUDE_TRACE_SPAN_H_
#define INCLUDE_TRACE_SPAN_H_
#include <variant>
#include <cstdint>
#include <map>
#include <memory>
#include <chrono>
#include <string>

#include "./span-context.h"
#include "./tracer.h"

class Tracer;
class Span {
 public:
  Span(std::string, Tracer* const, const SpanContext* const);
  void set_name(std::string);
  void end();
  void end(std::chrono::milliseconds);
  bool is_ended() const;
  void add_attribute(std::string, const double);
  void add_attribute(std::string, const bool);
  void add_attribute(std::string, const int64_t);
  void add_attribute(std::string, const std::string);
  const SpanContext* get_context() const;
  const SpanContext* get_parent_context() const;

 private:
  Tracer* const tracer;
  std::string name;
  const SpanContext* context;
  const SpanContext* const parent_context;
  std::chrono::milliseconds start_time;
  std::chrono::milliseconds end_time;
  std::map<
    std::string,
    std::variant<
      std::unique_ptr<const std::string>,
      std::unique_ptr<const int64_t>,
      std::unique_ptr<const bool>,
      std::unique_ptr<const double>
    >
  > attributes;
};
#endif  // INCLUDE_TRACE_SPAN_H_
