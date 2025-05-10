################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/http/request_parser/connect_http_body_segments.c \
../Core/Src/http/request_parser/extract_http_header_segment.c \
../Core/Src/http/request_parser/request_type.c 

OBJS += \
./Core/Src/http/request_parser/connect_http_body_segments.o \
./Core/Src/http/request_parser/extract_http_header_segment.o \
./Core/Src/http/request_parser/request_type.o 

C_DEPS += \
./Core/Src/http/request_parser/connect_http_body_segments.d \
./Core/Src/http/request_parser/extract_http_header_segment.d \
./Core/Src/http/request_parser/request_type.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/http/request_parser/%.o Core/Src/http/request_parser/%.su Core/Src/http/request_parser/%.cyclo: ../Core/Src/http/request_parser/%.c Core/Src/http/request_parser/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_PWR_LDO_SUPPLY -DUSE_HAL_DRIVER -DSTM32H723xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -I../LWIP/App -I../LWIP/Target -I../Middlewares/Third_Party/LwIP/src/include -I../Middlewares/Third_Party/LwIP/system -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/BSP/Components/lan8742 -I../Middlewares/Third_Party/LwIP/src/include/netif/ppp -I../Middlewares/Third_Party/LwIP/src/include/lwip -I../Middlewares/Third_Party/LwIP/src/include/lwip/apps -I../Middlewares/Third_Party/LwIP/src/include/lwip/priv -I../Middlewares/Third_Party/LwIP/src/include/lwip/prot -I../Middlewares/Third_Party/LwIP/src/include/netif -I../Middlewares/Third_Party/LwIP/src/include/compat/posix -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/arpa -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/net -I../Middlewares/Third_Party/LwIP/src/include/compat/posix/sys -I../Middlewares/Third_Party/LwIP/src/include/compat/stdc -I../Middlewares/Third_Party/LwIP/system/arch -I../Middlewares/Third_Party/LwIP/src/apps/http -I../Core/ThreadSafe -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-http-2f-request_parser

clean-Core-2f-Src-2f-http-2f-request_parser:
	-$(RM) ./Core/Src/http/request_parser/connect_http_body_segments.cyclo ./Core/Src/http/request_parser/connect_http_body_segments.d ./Core/Src/http/request_parser/connect_http_body_segments.o ./Core/Src/http/request_parser/connect_http_body_segments.su ./Core/Src/http/request_parser/extract_http_header_segment.cyclo ./Core/Src/http/request_parser/extract_http_header_segment.d ./Core/Src/http/request_parser/extract_http_header_segment.o ./Core/Src/http/request_parser/extract_http_header_segment.su ./Core/Src/http/request_parser/request_type.cyclo ./Core/Src/http/request_parser/request_type.d ./Core/Src/http/request_parser/request_type.o ./Core/Src/http/request_parser/request_type.su

.PHONY: clean-Core-2f-Src-2f-http-2f-request_parser

