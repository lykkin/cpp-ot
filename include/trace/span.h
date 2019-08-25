#include <map>
#include <cstdint>
#include <chrono>
#include <variant>
#include <string>

#include "trace/span-context.h"

class Span {
  std::string name;
  const SpanContext* context;
  const SpanContext* const parent_context;
  std::chrono::milliseconds start_time;
  std::chrono::milliseconds end_time;
  std::map<std::string, std::variant<std::string, int64_t, bool, double>> attributes;
public:
  Span(std::string, const SpanContext* const);
  void set_name(std::string);
  void end();
  void end(std::chrono::milliseconds);
  bool is_ended() const;
  void add_attribute(std::string, double);
  void add_attribute(std::string, bool);
  void add_attribute(std::string, int64_t);
  void add_attribute(std::string, std::string);
  const SpanContext* get_context() const;
  const SpanContext* get_parent_context() const;
};
