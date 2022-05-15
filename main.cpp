#include "../include/Type-Macros.hpp"
#include "../include/Window.hpp"

#include <algorithm>

int main() {
  INIT_ALL();

  fire::FWindow test("MyWindow");

  test.Load();

  test.setIcon(R"(..\resource\favicon.png)");
  test.setColor("#114514", 0);
  test.setCloseKey(GLFW_KEY_P);

  while (!test.shouldClose()) {
    test.Draw();
  }

  TERMINATE();

  return 0;
}
