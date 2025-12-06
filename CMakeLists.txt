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

### UTILS

set(UTILS ${SRC}/utils/utils.c)

### TAD

# TAD Instance
set(TAD_INSTANCE ${TYPES}/instance/instance.c)

# TAD OrdonnancementMachine
set(TAD_ORDONNANCEMENT_MACHINE ${TYPES}/ordonnancementMachine/ordonnancementMachine.c)

# TAD TableauDynamique
set(TAD_TABLEAU_DYNAMIQUE ${TYPES}/tableauDynamique/tableauDynamique.c)

### ALGO

### EXECUTABLES ###

# Executable Main
add_executable(Algorithmie ${SRC}/main.c
        ${UTILS}

        ${TAD_INSTANCE}
        ${TAD_ORDONNANCEMENT_MACHINE}
)


add_executable(testTableauDynamique ${TESTS}/testTableauDynamique.c
        ${TAD_TABLEAU_DYNAMIQUE}
)

add_executable(testTriFusion ${TESTS}/testTriFusion.c
        ${UTILS}
)
