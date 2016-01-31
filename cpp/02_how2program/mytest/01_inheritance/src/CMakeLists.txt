# add to the include paths                                                      
include_directories(${CMAKE_SOURCE_DIR}/include) 

add_library(BasePlusCommissionEmployee SHARED 
			BasePlusCommissionEmployee.cpp)

add_library(CommissionEmployee SHARED
			CommissionEmployee.cpp)

add_executable(ce 
			  ce.cpp)  

target_link_libraries(ce
					  BasePlusCommissionEmployee 
					  CommissionEmployee)   

#set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) 


