/**
 * @file Window.hpp
 * @author K4li
 * @brief Windowing and input handling
 * @version 0.1
 * @date 2023-02-28
 *
 * @copyright Copyright (c) 2023 K4li
 * @todo Documentation
 */
#pragma once
#include <glad/glad.h>

#include <GLFW/glfw3.h>
#include <string_view>

#include "Exceptions.hpp"
#include "Logger.hpp"
#include "glm.h"

namespace Tutorial {
   /**
    * @brief GLFW helper functions bamespace
    *
    */
   namespace glfw {
      /**
       * @brief Call glfwInit() and check result
       *
       */
      inline void init() {
         if ( !glfwInit() )
            throw GlfwError( "Failed to init glfw" );
         Logger::info( "GLFW initialized" );
      }

      /**
       * @brief Set the GLFW error callback
       *
       */
      inline void setErrorCallback() {
         glfwSetErrorCallback( []( int errorCode, const char *description )
                               { Logger::err( "GLFW error {}: {}", errorCode, description ); } );
      }

      /**
       * @brief To keep all the necessary functions in one style
       *
       */
      inline auto pollEvents = glfwPollEvents;

      /**
       * @brief Call glfwTerminate and log
       *
       */
      inline void terminate() {
         glfwTerminate();
         Logger::info( "GLFW terminated" );
      }
   }  // namespace glfw

   /**
    * @brief glad helper functions namespace
    *
    */
   namespace glad {
      /**
       * @brief Load OpenGL, handle errors and log OpenGL version
       *
       */
      inline void loadGL() {
         if ( !gladLoadGLLoader( reinterpret_cast<GLADloadproc>( glfwGetProcAddress ) ) ) {
            Logger::crit( "Failed to load OpenGL" );
            throw GlError( "Failed to load OpenGL" );
         }
         Logger::info( "Loaded OpenGL {}.{}", GLVersion.major, GLVersion.minor );
      }
   }  // namespace glad

   /**
    * @brief Window Mode
    */
   enum class WindowMode { eWindowed, eBorderless, eFullscreen };

   /**
    * @brief Handles input, windows, and gl context
    *
    */
   class Window {
      GLFWwindow  *window  = nullptr;
      GLFWmonitor *monitor = nullptr;

      /**
       * @brief Keyboard events callback
       * @todo Implement event callbacks
       * @param window
       * @param key
       * @param scancode
       * @param action
       * @param mods
       */
      inline static void
         KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mods ) noexcept {}

      /**
       * @brief Text input events callback
       * @todo Implement event callbacks
       * @param window
       * @param codepoint
       * @param mods
       */
      inline static void
         CharCallback( GLFWwindow *window, unsigned int codepoint, int mods ) noexcept {}

      /**
       * @brief Mouse buttons events callback
       * @todo Implement event callbacks
       * @param window
       * @param button
       * @param action
       * @param mods
       */
      inline static void
         MouseButtonCallback( GLFWwindow *window, int button, int action, int mods ) noexcept {}

      /**
       * @brief Mouse motion events callback
       * @todo Implement event callbacks
       * @param window
       * @param xpos
       * @param ypos
       */
      inline static void
         MouseMoveCallback( GLFWwindow *window, double xpos, double ypos ) noexcept {}

      /**
       * @brief Mouse/touchpad scroll
       * @todo Implement event callbacks
       * @param window
       * @param xoffset For touchpads with bidirectional scroll
       * @param yoffset
       */
      inline static void
         ScrollCallback( GLFWwindow *window, double xoffset, double yoffset ) noexcept {}

      /**
       * @brief Check if cursor hover / leave window rect
       * @todo Implement event callbacks
       * @param window
       * @param entered
       */
      inline static void CursorEnterCallback( GLFWwindow *window, int entered ) noexcept {}

      /**
       * @brief
       *
       * @param window
       * @param width
       * @param height
       */
      inline static void SizeCallback( GLFWwindow *window, int width, int height ) noexcept {
         glViewport( 0, 0, width, height );
      }

   public:
      /**
       * @brief Default constructor
       *
       */
      Window() noexcept = default;

      /**
       * @brief Call destroy()
       *
       */
      ~Window() noexcept {
         destroy();
      }

      /**
       * @brief Create window and gl context
       *
       * @param windowName
       * @param mode
       * @param windowSize
       * @param resizable The default value is true
       */
      inline void create( std::string_view windowName,
                          WindowMode       mode,
                          glm::uvec2       windowSize,
                          bool             resizable = true ) {
         monitor = glfwGetPrimaryMonitor();
         glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 4 );
         glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 5 );
         glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
         glfwWindowHint( GLFW_RESIZABLE, resizable );

         switch ( mode ) {
            case WindowMode::eBorderless: glfwWindowHint( GLFW_DECORATED, GLFW_FALSE );
            case WindowMode::eWindowed:
               window = glfwCreateWindow(
                  windowSize.x, windowSize.y, windowName.data(), nullptr, nullptr );
               break;
            case WindowMode::eFullscreen:
               window = glfwCreateWindow(
                  windowSize.x, windowSize.y, windowName.data(), monitor, nullptr );
         }
         glfwSetWindowUserPointer( window, this );
         glfwSetWindowSizeCallback( window, Window::SizeCallback );

         glfwMakeContextCurrent( window );
      }

      /**
       * @brief Check if window should close
       *
       * @return true
       * @return false
       */
      inline bool shouldClose() const noexcept {
         return glfwWindowShouldClose( window );
      }

      /**
       * @brief Set vertical synchronisation mode
       *
       * @param vsync false - swap interval 0; true - swap interval 1
       */
      inline void setVsync( bool vsync ) const noexcept {
         glfwSwapInterval( vsync );
      }

      /**
       * @brief Swap framebuffers
       *
       */
      inline void swap() const noexcept {
         glfwSwapBuffers( window );
      }

      /**
       * @brief Destroy window
       *
       */
      inline void destroy() noexcept {
         if ( window ) {
            glfwDestroyWindow( window );
            window = nullptr;
         }
      }
   };
}  // namespace Tutorial
