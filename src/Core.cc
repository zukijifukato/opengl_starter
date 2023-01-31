#include "Core.h"

Core::Core() {}
Core::~Core() {}

void Core::init(const char *title, int width, int height) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_RENDERER_ACCELERATED);

  context = SDL_GL_CreateContext(window);
  SDL_GL_MakeCurrent(window, context);

  // make buffer swap synchronized with the monitor's vertical refresh
  SDL_GL_SetSwapInterval(1);
  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Core::handleEvents() {
  // handle events from event queue
  while(SDL_PollEvent(&event)) {
    switch(event.type) {
      case SDL_QUIT:
        running = false;
        break;
      case SDL_WINDOWEVENT:
        if(event.window.event == SDL_WINDOWEVENT_RESIZED) {
          glViewport(0, 0, event.window.data1, event.window.data2);
        }
        break;
      default:
        break;
    }
  }
}

void Core::update() {}

void Core::render() {
  // clear context
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // swap buffers in double buffered opengl context
  SDL_GL_SwapWindow(window);
}
void Core::exit() {
  SDL_GL_DeleteContext(context);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
