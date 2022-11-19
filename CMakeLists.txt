cmake_minimum_required(VERSION 3.23)
project(TiendaVentaMass)

set(CMAKE_CXX_STANDARD 14)

add_executable(TiendaVentaMass
        main.cpp Controlador/ProductoControlador.h Modelo/Cliente.h Modelo/Vendedor.h Modelo/Categoria.h Modelo/DetalledeVenta.h Modelo/Venta.h)
