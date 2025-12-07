cmake_minimum_required(VERSION 4.0)
project(Algorithmie C)

### VARIABLES ###

set(CMAKE_C_STANDARD 17)

## FILESYSTEM

# Racine
set(SRC src)

# Tests
set(TESTS tests)

### IMPORTS AUTOMATIQUES ###

# Fait une liste avec tous les .c et .h du projet.
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${SRC}/*.c ${SRC}/*.h)

# Exclut src/main.c.
list(REMOVE_ITEM SOURCES ${SRC}/main.c)

# Créé la librairie avec les fichiers obtenus.
add_library(CORE ${SOURCES})

# Ajoute le target sur la racine src
target_include_directories(CORE PUBLIC ${SRC})

### EXECUTABLES ###

## Executable Main
add_executable(Algorithmie ${SRC}/main.c)
target_link_libraries(Algorithmie PRIVATE CORE)

## Tests

# Tableaux dynamiques
add_executable(testTableauDynamique ${TESTS}/testTableauDynamique.c)
target_link_libraries(testTableauDynamique PRIVATE CORE)

# Instance
add_executable(testInstance ${TESTS}/testInstance.c)
target_link_libraries(testInstance PRIVATE CORE)

# OrdonnancementMachine
add_executable(testOrdonnancementMachine ${TESTS}/testOrdonnancementMachine.c)
target_link_libraries(testOrdonnancementMachine PRIVATE CORE)

# Etat
add_executable(testEtat ${TESTS}/testEtat.c)
target_link_libraries(testEtat PRIVATE CORE)

# Jackson
add_executable(testJackson ${TESTS}/testJackson.c)
target_link_libraries(testJackson PRIVATE CORE)

# Génération aléatoire
add_executable(testGenerationAleatoire ${TESTS}/testGenerationAleatoire.c)
target_link_libraries(testGenerationAleatoire PRIVATE CORE)

# Algo ProgDynamique
add_executable(testAlgoProgDynamique ${TESTS}/testAlgoProgDynamique.c)
target_link_libraries(testAlgoProgDynamique PRIVATE CORE)

# Algo ModificationInstance
add_executable(testAlgoModificationInstance ${TESTS}/testAlgoModificationInstance.c)
target_link_libraries(testAlgoModificationInstance PRIVATE CORE)

# InitInstanceRobot
add_executable(testInitInstanceRobot ${TESTS}/testInitInstanceRobot.c)
target_link_libraries(testInitInstanceRobot PRIVATE CORE)

# OrdonnancementRobot
add_executable(testOrdonnancementRobot ${TESTS}/testOrdonnancementRobot.c)
target_link_libraries(testOrdonnancementRobot PRIVATE CORE)
