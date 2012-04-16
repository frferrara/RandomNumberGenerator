add_library( Ran64 SHARED Ran64.cpp Ran64.hpp )

install( TARGETS Ran64 DESTINATION lib )
install( FILES Ran64.hpp DESTINATION include )