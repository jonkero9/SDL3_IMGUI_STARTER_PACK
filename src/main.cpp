#include "SDL3/SDL.h"
#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

auto init(SDL_Window **window, SDL_Renderer **renderer) -> auto {
  if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
    return false;
  }

  bool success = SDL_CreateWindowAndRenderer(
      "Jbattles", 600, 500, SDL_WINDOW_RESIZABLE, window, renderer);

  if (success == false) {
    SDL_Log("errrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr");
    return false;
  }
  return true;
}

auto init_imgui(SDL_Window *window, SDL_Renderer *renderer) -> auto {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiIO &io = ImGui::GetIO();
  (void)io;
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls

  // Setup scaling
  float main_scale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
  ImGuiStyle &style = ImGui::GetStyle();
  style.ScaleAllSizes(
      main_scale); // Bake a fixed style scale. (until we have a
                   // solution for dynamic style scaling, changing this
                   // requires resetting Style + calling this again)
                   // makes this unnecessary. We leave both here for
                   // documentation purpose)
  style.FontScaleDpi = main_scale;

  style.FontSizeBase = 20.f;
  io.Fonts->AddFontDefault();

  ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
  ImGui_ImplSDLRenderer3_Init(renderer);
}

int main(int argc, char *argv[]) {

  // **************************************************************
  //  ____       _
  // / ___|  ___| |_ _   _ _ __
  // \___ \ / _ \ __| | | | '_ \
  //  ___) |  __/ |_| |_| | |_) |
  // |____/ \___|\__|\__,_| .__/
  //                      |_|
  // **************************************************************

  SDL_Window *window;
  SDL_Renderer *renderer;

  if (init(&window, &renderer) == false) {
    return -1;
  }

  init_imgui(window, renderer);

  // **************************************************************
  //  _
  // | | ___   ___  _ __
  // | |/ _ \ / _ \| '_ \
  // | | (_) | (_) | |_) |
  // |_|\___/ \___/| .__/
  //               |_|
  // **************************************************************

  bool should_run{true};

  while (should_run) {
    SDL_Event e;

    if (SDL_PollEvent(&e)) {

      ImGui_ImplSDL3_ProcessEvent(&e);
      if (e.type == SDL_EVENT_QUIT) {
        should_run = false;
      }
      if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE) {
        should_run = false;
      }
    }

    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    ImGui::ShowDemoWindow();

    ImGui::Render();
    SDL_SetRenderDrawColor(renderer, 17, 17, 27, 255);
    SDL_RenderClear(renderer);
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);
    SDL_RenderPresent(renderer);
  }

  // **************************************************************

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
