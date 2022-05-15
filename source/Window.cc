// This file is a part of FireEngine.
// Copyright (c) 2021-2022, Ink. All rights reserved.
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

#include <iostream>
#include <algorithm>

#include "../dependence/stb_image.h"

#include "../include/Window.hpp"

namespace fire {

FWindow::~FWindow() {
  glfwDestroyWindow(window);
}

FWindow::FWindow(FireStr title, FireInt width,
               FireInt length, FireBool fullscreen) {
  this->full = fullscreen;

  GLFWmonitor* temp = this->full ? glfwGetPrimaryMonitor() : nullptr;

  this->window = glfwCreateWindow(width, length, title, temp, nullptr);

  if (this->window == nullptr) {
    std::cerr << "Failed to create a window." << std::endl;
    exit(-1);
  }
}

FireBool FWindow::shouldClose() {
  return glfwWindowShouldClose(this->window);
}

void FWindow::setColor(const FireColor& new_) {
  this->color = new_;
}

void FWindow::setColor(SafeStr new_, int alpha) {
  if (new_.size() != 7 || new_[0] != '#') {
    std::cerr << "There is a invalid color literal: " << new_ << std::endl;
    exit(-3);
  }

  new_.erase(new_.begin());

  auto check = [](const SafeStr& str) -> bool {
    return std::all_of(str.begin(), str.end(), [](char i) -> bool {
        if (!std::isdigit(i)) {
          if ((i >= 'A' && i <= 'F') || (i >= 'a' && i <= 'f'));
          else return false;
        }
      return true;
    });
  };

  if (!check(new_)) {
    std::cerr << "There is an invalid color literal: " + new_ << std::endl;
    exit(-3);
  }

  float A = getAlpha(alpha);

  float R = (float)std::stoi(new_.substr(0, 2), nullptr, 16) / 255;
  float G = (float)std::stoi(new_.substr(2, 2), nullptr, 16) / 255;
  float B = (float)std::stoi(new_.substr(4, 2), nullptr, 16) / 255;

  this->setColor({R, G, B, A});
}

FireFloat FWindow::getAlpha(int new_) {
  if (new_ < 0 || new_ > 255) {
    std::cerr << "There is an invalid alpha literal: " + std::to_string(new_) << std::endl;
    exit(-3);
  }

  return static_cast<FireFloat>(new_) / 255;
}

void FWindow::setCloseKey(FireInt new_) {
  this->close_key = new_;
}

void FWindow::setIcon(FireStr icon_path) {
  int h, w, nr_channel;
  unsigned char* data = stbi_load(icon_path, &w, &h, &nr_channel, 0);

  if (data == nullptr) {
    std::cerr << "Cannot load icon: " + std::string(icon_path) << std::endl;
    exit(-4);
  }

  GLFWimage a[1]; a[0] = {w, h, data};

  glfwSetWindowIcon(this->window, 1, a);
}

void FWindow::Load() {
  glfwMakeContextCurrent(this->window);
  glfwSetFramebufferSizeCallback(window, [](GLFWwindow* window_, FireInt w, FireInt l)
      -> void {
    glViewport(0, 0, w, l);
  });

  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    std::cerr << "Cannot load OpenGL 3.3." << std::endl;
    exit(-2);
  }
}

void FWindow::Draw() {
  if (glfwGetKey(this->window, this->close_key) == GLFW_PRESS)
    glfwSetWindowShouldClose(this->window, true);

  glClearColor(this->color.R, this->color.G, this->color.B, this->color.A);
  glClear(GL_COLOR_BUFFER_BIT);

  glfwSwapBuffers(window);
  glfwPollEvents();
}

} // namespace fire