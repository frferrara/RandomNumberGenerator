add_library( Marsaglia64 SHARED Marsaglia64.cpp Marsaglia64.hpp )
target_link_libraries( Marsaglia64 Ran64 )

install( TARGETS Marsaglia64 DESTINATION lib )
install( FILES Marsaglia64.hpp DESTINATION include )