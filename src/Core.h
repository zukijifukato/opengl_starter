#ifndef __CORE_H__
#define __CORE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

class Core {
  public:
    Core();
    ~Core();

    void init(const char *title, int width, int height);
    inline bool isRunning() { return running; }
    void handleEvents();
    void update();
    void render();
    void exit();
  private:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    bool running = true; // truthy value

    SDL_Window *window = nullptr;
    SDL_GLContext context;

    SDL_Event event;
};

#endif // !__CORE_H__
