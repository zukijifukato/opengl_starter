#include "Core.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 48

int main(int argc, char **argv) {
  Core *core = new Core();

  core->init("OpenGL Starter", 640, 480);
  while(core->isRunning()) {
    core->handleEvents();
    core->update();
    core->render();
  }
  core->exit();

  delete core;

  return 0;
}
