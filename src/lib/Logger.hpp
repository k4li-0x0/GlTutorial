/**
 * @file Logger.hpp
 * @author K4li
 * @brief
 * @version 0.1
 * @date 2023-02-26
 *
 * @copyright Copyright (c) 2023 K4li
 */
#pragma once
#include "Version.hpp"

#include <array>
#include <memory>
#include <spdlog/common.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace Tutorial {
   /**
    * @brief Logger verbosity level
    */
   enum class LogLevel {
      eInfo     = spdlog::level::level_enum::info,
      eWarn     = spdlog::level::level_enum::warn,
      eErr      = spdlog::level::level_enum::err,
      eCritical = spdlog::level::level_enum::critical
   };

   /**
    * @brief Project's logger
    *
    */
   class Logger {
      inline static bool g_initialized = false;

      inline static void initLogger() noexcept {
         auto consoleSink = std::make_shared<spdlog::sinks::stderr_color_sink_mt>();
         auto fileSink =
            std::make_shared<spdlog::sinks::basic_file_sink_mt>( "GlTutorial.log", false );
         spdlog::sinks_init_list sinks_list = { consoleSink, fileSink };
         spdlog::set_default_logger( std::make_shared<spdlog::logger>(
            PROJECT_NAME, sinks_list.begin(), sinks_list.end() ) );
         spdlog::set_pattern( "[%Y-%m-%d %T.%f] [%^%l%$] %v" );
         g_initialized = true;
      }

   public:
      /**
       * @brief Set log level
       *
       * @param level Log level
       */
      inline static void setLogLevel( const LogLevel &level ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::set_level( static_cast<spdlog::level::level_enum>( level ) );
      }

      /**
       * @brief Write info message
       *
       * @tparam T
       * @param msg Message
       */
      template <typename T>
      inline static void info( const T &msg ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::info( msg );
      }

      /**
       * @brief Write info message
       *
       * @tparam Args variadic template
       * @param fmt Format string
       * @param args Formatting arguments
       */
      template <typename... Args>
      inline static void info( spdlog::format_string_t<Args...> fmt, Args... args ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::info( fmt, std::forward<Args>( args )... );
      }

      /**
       * @brief Write warning message
       *
       * @tparam T
       * @param msg Message
       */
      template <typename T>
      inline static void warn( const T &msg ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::warn( msg );
      }

      /**
       * @brief Write warning message
       *
       * @tparam Args
       * @param fmt Format string
       * @param args Formatting arguments
       */
      template <typename... Args>
      inline static void warn( spdlog::format_string_t<Args...> fmt, Args... args ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::warn( fmt, std::forward<Args>( args )... );
      }

      /**
       * @brief Write error message
       *
       * @tparam T
       * @param msg Message
       */
      template <typename T>
      inline static void err( const T &msg ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::error( msg );
      }

      /**
       * @brief Write error message
       *
       * @tparam Args
       * @param fmt Format string
       * @param args Formatting arguments
       */
      template <typename... Args>
      inline static void err( spdlog::format_string_t<Args...> fmt, Args... args ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::error( fmt, std::forward<Args>( args )... );
      }

      /**
       * @brief Write critical error message
       *
       * @tparam T
       * @param msg Message
       */
      template <typename T>
      inline static void crit( const T &msg ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::critical( msg );
      }

      /**
       * @brief Write critical error message
       *
       * @tparam Args
       * @param fmt Format string
       * @param args Formatting arguments
       */
      template <typename... Args>
      inline static void crit( spdlog::format_string_t<Args...> fmt, Args... args ) noexcept {
         if ( !g_initialized )
            initLogger();
         spdlog::critical( fmt, std::forward<Args>( args )... );
      }
   };
}  // namespace Tutorial