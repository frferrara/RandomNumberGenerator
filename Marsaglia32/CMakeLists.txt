add_library( Marsaglia32 SHARED Marsaglia32.cpp Marsaglia32.hpp )
target_link_libraries( Marsaglia32 Ran32 )

install( TARGETS Marsaglia32 DESTINATION lib )
install( FILES Marsaglia32.hpp DESTINATION include )