cmake_minimum_required(VERSION 3.10)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
set(CMAKE_CROSSCOMPILING TRUE)

set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(OBJCOPY arm-none-eabi-objcopy)

project(qlock)
enable_language(C CXX)

set(LDSCRIPT "${CMAKE_SOURCE_DIR}/stm32f401re.ld")
set(LIBNAME "opencm3_stm32f4")
add_definitions(-DSTM32F4)

set(FP_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
set(ARCH_FLAGS "-mthumb -mcpu=cortex-m4 ${FP_FLAGS}")

set(OPENCM3_DIR "${CMAKE_SOURCE_DIR}/lib/libopencm3")

include_directories(${OPENCM3_DIR}/include)

link_directories(${OPENCM3_DIR}/lib)

set(CMAKE_ASM_FLAGS "-D__ASSEMBLY__ -mcpu=cortex-m4 -mthumb")
set(CMAKE_C_FLAGS " \
-lc \
-lgcc \
-Os -g -Wall -Werror -Wredundant-decls -Wstrict-prototypes \
-fno-common -ffunction-sections -fdata-sections \
-MD -Wundef \
${ARCH_FLAGS}")

set(CMAKE_CXX_FLAGS " \
-lc \
-lgcc \
-Os \
-Wall -std=c++14 ${ARCH_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS " \
-T${LDSCRIPT} \
--static \
-nostartfiles \
--specs=nosys.specs \
-Wl,--start-group -lc -lgcc -Wl,--end-group")

add_custom_target(libopencm3 make WORKING_DIRECTORY ${OPENCM3_DIR})


# SRC
file(GLOB USER_SOURCES ./src/*.c ./src/*.cpp)
add_executable(${PROJECT_NAME}.elf ${USER_SOURCES})
target_link_libraries(${PROJECT_NAME}.elf opencm3_stm32f4)