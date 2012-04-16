add_library( Ran32 SHARED Ran32.cpp Ran32.hpp )

install( TARGETS Ran32 DESTINATION lib )
install( FILES Ran32.hpp DESTINATION include )