#include "trace/span.h"

std::chrono::milliseconds get_timestamp();
std::chrono::milliseconds get_timestamp() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
    std::chrono::system_clock::now().time_since_epoch()
  );
}

Span::Span(std::string name, const SpanContext* const parent=nullptr)
  : name(name),
  context(new SpanContext(parent)),
  parent_context(parent),
  start_time(get_timestamp()),
  end_time(0)
{}

void Span::set_name(std::string n)
{
  name = n;
}

void Span::end()
{
  end_time = get_timestamp();
}

void Span::end(std::chrono::milliseconds e)
{
  end_time = e;
}

bool Span::is_ended() const
{
  return end_time == std::chrono::milliseconds(0);
}

void Span::add_attribute(std::string k, double v)
{
  attributes[k] = v;
}

void Span::add_attribute(std::string k, std::string v)
{
  attributes[k] = v;
}

void Span::add_attribute(std::string k, bool v)
{
  attributes[k] = v;
}

void Span::add_attribute(std::string k, int64_t v)
{
  attributes[k] = v;
}

const SpanContext* Span::get_context() const
{
  return context;
}

const SpanContext* Span::get_parent_context() const
{
  return parent_context;
}
