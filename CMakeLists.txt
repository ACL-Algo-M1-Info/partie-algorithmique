cmake_minimum_required(VERSION 4.0)
project(Algorithmie C)

### VARIABLES ###

set(CMAKE_C_STANDARD 17)

## FILESYSTEM

# Racine
set(SRC src)

# Tests
set(TESTS tests)

# Types
set(TYPES ${SRC}/types)

## UTILS

set(UTILS ${SRC}/utils/utils.c)

## TAD

# TAD Instance
set(TAD_INSTANCE ${TYPES}/instance/instance.c)

# TAD OrdonnancementMachine
set(TAD_ORDONNANCEMENT_MACHINE ${TYPES}/ordonnancementMachine/ordonnancementMachine.c)

# TAD TableauDynamique
set(TAD_TABLEAU_DYNAMIQUE ${TYPES}/tableauDynamique/tableauDynamique.c)

## ALGO

### EXECUTABLES ###

## Executable Main
add_executable(Algorithmie ${SRC}/main.c
        ${UTILS}

        ${TAD_INSTANCE}
        ${TAD_ORDONNANCEMENT_MACHINE}
)

## Tests

# Tableaux dynamiques
add_executable(testTableauDynamique ${TESTS}/testTableauDynamique.c
        ${UTILS}

        ${TAD_TABLEAU_DYNAMIQUE}
)

# Instance
add_executable(testInstance ${TESTS}/testInstance.c
        ${UTILS}

        ${TAD_INSTANCE}
)

# OrdonnancementMachine
add_executable(testOrdonnancementMachine ${TESTS}/testOrdonnancementMachine.c
        ${UTILS}

        ${TAD_TABLEAU_DYNAMIQUE}
        ${TAD_INSTANCE}
        ${TAD_ORDONNANCEMENT_MACHINE}
)
