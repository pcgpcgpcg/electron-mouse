#include <napi.h>
#include <windows.h>

//loadCursorFromFile,
//setSystemCursor

Napi::Value SetNullCursor(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

  // if (info.Length() < 2) {
  //   Napi::TypeError::New(env, "Wrong number of arguments")
  //       .ThrowAsJavaScriptException();
  //   return env.Null();
  // }

  // if (!info[0].IsString()) {
  //   Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
  //   return env.Null();
  // }

  // string arg0 = info[0].As<Napi::String>().StringValue();
  HCURSOR hCurDef = CopyCursor(LoadCursor(0, IDC_ICON));
  SetSystemCursor(hCurDef, OCR_NORMAL);
  DestroyCursor(hCurDef);
  return 0;
}

// Napi::Value SetCursorFromFile(const Napi::CallbackInfo& info) {
//   Napi::Env env = info.Env();

//   if (info.Length() < 1) {
//     Napi::TypeError::New(env, "Wrong number of arguments")
//         .ThrowAsJavaScriptException();
//     return env.Null();
//   }

//   if (!info[0].IsString()) {
//     Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
//     return env.Null();
//   }

//   // string arg0 = info[0].As<Napi::String>().StringValue();
//   HCURSOR hCurDef = CopyCursor(LoadCursorFromFile(TEXT("cursor.cur")));
//   SetSystemCursor(hCurDef, OCR_NORMAL);
//   DestroyCursor(hCurDef);
//   return 0;
// }

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set(Napi::String::New(env, "SetNullCursor"), Napi::Function::New(env, SetNullCursor));
  //exports.Set(Napi::String::New(env, "SetCursorFromFile"), Napi::Function::New(env, SetCursorFromFile));
  return exports;
}

NODE_API_MODULE(mousecur, Init)
