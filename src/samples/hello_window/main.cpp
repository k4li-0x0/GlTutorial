#include <glad/glad.h>

#include <Logger.hpp>
#include <Version.hpp>
#include <Window.hpp>
#include <exception>
#include <glm/fwd.hpp>
#include <iostream>


class Application {
   int              exit_code = -1;
   Tutorial::Window window{};
   struct {
      bool                 vsync = false;
      glm::vec2            windowSize{ 1280, 720 };
      Tutorial::WindowMode windowMode = Tutorial::WindowMode::eWindowed;
   } settings;

public:
   Application &init( int argc, const char **argv ) {
      Tutorial::glfw::setErrorCallback();
      Tutorial::glfw::init();
      window.create( Tutorial::PROJECT_NAME, settings.windowMode, settings.windowSize );
      Tutorial::glad::loadGL();
      return *this;
   }

   Application &run() {
      while ( !window.shouldClose() ) {
         Tutorial::glfw::pollEvents();
         glClearColor( 0.f, 0.f, 1.f, 1.f );  // Blue window
         glClear( GL_COLOR_BUFFER_BIT );
         window.swap();
      }
      exit_code = 0;
      return *this;
   }

   int destroy() {
      window.destroy();
      Tutorial::glfw::terminate();
      return exit_code;
   }
};

int main( int argc, const char **argv ) {
   try {
      Application app{};
      return app.init( argc, argv ).run().destroy();
   }
   catch ( const Tutorial::RenderError &e ) {
      Tutorial::Logger::crit( "Render error: {}", e.what() );
      return -1;
   }
   catch ( const std::exception &e ) {
      Tutorial::Logger::crit( "Uncaught exception: {}", e.what() );
      return -1;
   }
}
