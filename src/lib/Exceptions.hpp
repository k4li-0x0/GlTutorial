/**
 * @file Exceptions.hpp
 * @author K4li
 * @brief Project exceptions
 * @version 0.1
 * @date 2023-02-28
 *
 * @copyright Copyright (c) 2023 K4li
 *
 */
#include <stdexcept>
#include <string_view>

#define DEFINE_EXCEPTION( name, base )                                           \
   class name : public base {                                                    \
      typedef base _Mybase;                                                      \
                                                                                 \
   public:                                                                       \
      explicit name( std::string_view _Message ) : _Mybase( _Message.data() ) {} \
   }

namespace Tutorial {
   DEFINE_EXCEPTION( RenderError, std::runtime_error );
   DEFINE_EXCEPTION( GlfwError, RenderError );
   DEFINE_EXCEPTION( GlError, RenderError );
}  // namespace Tutorial