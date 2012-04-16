add_library( RandomNumberGenerator SHARED RandomNumberGenerator.cpp RandomNumberGenerator.hpp )

install( TARGETS RandomNumberGenerator DESTINATION lib )
install( FILES RandomNumberGenerator.hpp DESTINATION include )