#include "gtest/gtest.h"
#include "trace/span.h"
#include "trace/tracer.h"
namespace {
TEST(Span, ConstructorNoParent){
  auto t = new Tracer();
  auto s = new Span("test name", t);
  EXPECT_EQ(s->get_name(), "test name");
}

TEST(Span, DoubleAttributes){
  auto t = new Tracer();
  auto s = new Span("test name", t);
  s->add_attribute<double>("test", 123.12);
  EXPECT_EQ(s->get_attribute<double>("test"), 123.12);
}

TEST(Span, StringAttributes){
  auto t = new Tracer();
  auto s = new Span("test name", t);
  s->add_attribute<std::string>("test", "test value");
  EXPECT_EQ(s->get_attribute<std::string>("test"), "test value");
}
}