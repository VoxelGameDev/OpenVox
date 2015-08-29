# Please change to: 
# ADD_LIBRARY(Engine
#     <sources>
# )
# when engine is no longer header-only.
# When you add a new file to the engine, please add it to the list below.
ADD_CUSTOM_TARGET(Engine ALL SOURCES
    include/math/VectorMath.hpp
    include/math/VGDMath.hpp
    include/Decorators.h
    include/Types.h
    include/Vector.hpp
    include/Vector.inl
    include/VGD.h
    include/VGDAssert.hpp
    include/Events.hpp
)
