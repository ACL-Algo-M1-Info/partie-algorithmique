cmake_minimum_required(VERSION 4.0)
project(Algorithmie C)

### VARIABLES ###

set(CMAKE_C_STANDARD 17)

### FILESYSTEM

# Racine
set(SRC src)

# Tests
set(TESTS tests)

# Types
set(TYPES ${SRC}/types)

### TAD

# TAD Instance
set(TAD_INSTANCE ${TYPES}/instance/instance.c)

# TAD OrdonnancementMachine
set(TAD_ORDONNANCEMENT_MACHINE ${TYPES}/ordonnancementMachine/ordonnancementMachine.c)

### ALGO

### EXECUTABLES ###

# Executable Main
add_executable(Algorithmie ${SRC}/main.c
    ${TAD_INSTANCE}
    ${TAD_ORDONNANCEMENT_MACHINE}
)
