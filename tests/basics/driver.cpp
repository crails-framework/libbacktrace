#include <crails/utils/backtrace.hpp>
#include <sstream>
#include <iostream>

#undef NDEBUG
#include <cassert>

int main()
{
  using namespace std;

  try {
    throw std::runtime_error("runtime error");
  }
  catch (const exception& error) {
    stringstream stream;
    string trace;

    stream << boost_ext::trace(error);
    trace = stream.str();
    assert(trace.length() == 0);
  }

  try {
    throw boost_ext::runtime_error("runtime error");
  }
  catch (const exception& error) {
    stringstream stream;
    string trace;

    assert(error.what() == string("runtime error"));
    stream << boost_ext::trace(error);
    trace = stream.str();
    assert(trace.length() > 0);
  }
  return 0;
}
