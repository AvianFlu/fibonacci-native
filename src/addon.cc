#include <v8.h>
#include <node.h>

using namespace v8;
using namespace node;

static Handle<Value> Fibonacci(const Arguments& args) {
  HandleScope scope;
  int i, num1 = 0, num2 = 1, result;

  if (args[0]->IsInt32()) {
    for (i = 1; i < args[0]->Int32Value(); i++) {
      result = num1 + num2;
      num1 = num2;
      num2 = result;
    }
    return scope.Close(Number::New(result));
  }
  else {
    return ThrowException(Exception::Error(String::New("Not an integer.")));
  }
}


extern "C" void init(Handle<Object> target) {
  HandleScope scope;

  NODE_SET_METHOD(target, "fibonacci", Fibonacci);
}
