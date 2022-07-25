#include <napi.h>
  #ifdef _WIN32
#define OEMRESOURCE
#include <windows.h>
#include <winuser.h>
#endif

//loadCursorFromFile,
//setSystemCursor


Napi::Value ShowMouseCursor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  if (info.Length() < 1) {
    Napi::TypeError::New(env, "Wrong number of arguments")
        .ThrowAsJavaScriptException();
    return env.Null();
  }

  if (!info[0].IsBoolean()) {
    Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
    return env.Null();
  }


  bool arg0 = info[0].As<Napi::Boolean>().Value();
  #ifdef _WIN32
  ::ShowCursor(arg0);
  #endif
  Napi::Number num = Napi::Number::New(env, 0);
  return num;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "ShowMouseCursor"), Napi::Function::New(env, ShowMouseCursor));
  //exports.Set(Napi::String::New(env, "SetCursorFromFile"), Napi::Function::New(env, SetCursorFromFile));
  return exports;
}

NODE_API_MODULE(mousecur, Init)


  // string arg0 = info[0].As<Napi::String>().StringValue();
  //HCURSOR hCurDef = CopyCursor(LoadCursor(NULL, IDC_ARROW));
  //SetSystemCursor(hCurDef, OCR_NORMAL);
  //DestroyCursor(hCurDef);