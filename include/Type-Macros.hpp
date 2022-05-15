
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

#ifndef FIREENGINE_TYPE_MACROS_HPP
#define FIREENGINE_TYPE_MACROS_HPP

using FireBool    = bool;

using FireInt     = int;
using FireValue   = unsigned long long int;
using FireLongInt = long long int;
using FireFloat   = float;

#include <string>

using FireStr     = const char*;
using SafeStr     = std::string;

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define INIT_ALL() glfwInit(); \
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); \
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); \
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE)

#define TERMINATE() glfwTerminate()

#endif // FIREENGINE_TYPE_MACROS_HPP
