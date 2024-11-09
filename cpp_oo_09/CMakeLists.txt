cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(sqlite_project)

# Definir a versão mínima do C++ necessária
set(CMAKE_CXX_STANDARD 17)

# Encontrar o pacote SQLite3
find_package(SQLite3 REQUIRED)

# Adicionar arquivos fontes do projeto
set(SOURCE
    src/main.cpp
)

add_executable(sqlite_project ${SOURCE})

# Vincular a biblioteca SQLite3 ao projeto
target_link_libraries(sqlite_project SQLite::SQLite3)
