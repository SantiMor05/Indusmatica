-- Eliminar primero las tablas con FKs (tablas hijo)

-- Tablas de Ventas y Pedidos
DROP TABLE l3_ventas_detalle;
DROP TABLE l3_campanias_productos;
DROP TABLE l3_pedidos_especiales_detalle;
DROP TABLE l3_ordenes_compra_detalle;

-- Tablas de Feedback y Seguimiento
DROP TABLE l3_encuestas;
DROP TABLE l3_sugerencias;
DROP TABLE l3_incidencias;

-- Tablas de Productos y Bibliografía
DROP TABLE l3_bibliografia_cursos;
DROP TABLE l3_productos_areas;
DROP TABLE l3_precios_tipo_cliente;
DROP TABLE l3_productos_condicion;
DROP TABLE l3_perdidas_inventario;
DROP TABLE l3_libros;
DROP TABLE l3_revistas;

-- Tablas Principales
DROP TABLE l3_ventas;
DROP TABLE l3_pedidos_especiales;
DROP TABLE l3_ordenes_compra;
DROP TABLE l3_campanias;
DROP TABLE l3_productos;
DROP TABLE l3_clientes;
DROP TABLE l3_editoriales_historico;

-- Tablas Maestras
DROP TABLE l3_cursos;
DROP TABLE l3_tipos_cliente;
DROP TABLE l3_areas_tematicas;
DROP TABLE l3_categorias;
DROP TABLE l3_editoriales;