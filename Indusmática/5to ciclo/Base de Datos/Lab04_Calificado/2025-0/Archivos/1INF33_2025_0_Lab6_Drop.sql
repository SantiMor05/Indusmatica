-- Eliminar primero las tablas con FKs (tablas hijo)

-- Tablas de Ventas y Pedidos
DROP TABLE L6_ventas_detalle;
DROP TABLE L6_campanias_productos;
DROP TABLE L6_pedidos_especiales_detalle;
DROP TABLE L6_ordenes_compra_detalle;

-- Tablas de Feedback y Seguimiento
DROP TABLE L6_encuestas;
DROP TABLE L6_sugerencias;
DROP TABLE sugerencia;
DROP TABLE L6_incidencias;

-- Tablas de Productos y Bibliografía
DROP TABLE L6_bibliografia_cursos;
DROP TABLE L6_productos_areas;
DROP TABLE L6_precios_tipo_cliente;
DROP TABLE L6_productos_condicion;
DROP TABLE L6_perdidas_inventario;
DROP TABLE L6_libros;
DROP TABLE L6_revistas;

-- Tablas Principales
DROP TABLE L6_ventas;
DROP TABLE L6_pedidos_especiales;
DROP TABLE L6_ordenes_compra;
DROP TABLE L6_campanias;
DROP TABLE L6_productos;
DROP TABLE L6_clientes;
DROP TABLE L6_editoriales_historico;

-- Tablas Maestras
DROP TABLE L6_cursos;
DROP TABLE L6_tipos_cliente;
DROP TABLE L6_areas_tematicas;
DROP TABLE L6_categorias;
DROP TABLE L6_editoriales;