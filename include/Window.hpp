// This file is a part of FireEngine.
// Copyright (c) 2022, Ink. All rights reserved.
// License(MIT)
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the
// "Software"), to deal in the Software without restriction, including
// without limitation the rights to use, copy, modify, merge, publish,
// distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to
// the following conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
// LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
// WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef FIREENGINE_WINDOW_HPP
#define FIREENGINE_WINDOW_HPP

#include "Type-Macros.hpp"
#include "Color.hpp"

#include <cctype>

namespace fire {

class FWindow {
 private:
  FireBool full = false;

  FireColor color = {.0, .0, .0, 1.0};

  GLFWwindow* window = nullptr;

  FireInt close_key = GLFW_KEY_ESCAPE;

  void setColor(const FireColor& new_);

  static FireFloat getAlpha(int new_);

 public:
  FWindow() = default;
  ~FWindow();

  explicit FWindow(
                  FireStr title,
                  FireInt width = 400,
                  FireInt length = 400,
                  FireBool fullscreen = false
                 );

  FireBool shouldClose();

  void setColor(SafeStr new_, int alpha);

  void setCloseKey(FireInt new_);

  void setIcon(FireStr icon_path);

  void Load();

  void Draw();
};

} // namespace fire

#endif // FIREENGINE_WINDOW_HPP
