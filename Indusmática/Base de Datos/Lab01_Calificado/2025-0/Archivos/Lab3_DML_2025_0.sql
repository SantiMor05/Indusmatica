-- Áreas Temáticas
INSERT INTO l3_areas_tematicas VALUES (1, 'Ciencias', 'Área de ciencias básicas y aplicadas');
INSERT INTO l3_areas_tematicas VALUES (2, 'Humanidades', 'Área de estudios humanísticos');
INSERT INTO l3_areas_tematicas VALUES (3, 'Ingeniería', 'Área de estudios en ingeniería');
INSERT INTO l3_areas_tematicas VALUES (4, 'Derecho', 'Área de ciencias jurídicas');
INSERT INTO l3_areas_tematicas VALUES (5, 'Economía', 'Área de ciencias económicas y empresariales');
INSERT INTO l3_areas_tematicas VALUES (6, 'Arquitectura', 'Área de estudios en arquitectura y urbanismo');
INSERT INTO l3_areas_tematicas VALUES (7, 'Psicología', 'Área de estudios del comportamiento humano');
INSERT INTO l3_areas_tematicas VALUES (8, 'Arte', 'Área de estudios artísticos y culturales');
INSERT INTO l3_areas_tematicas VALUES (9, 'Comunicaciones', 'Área de estudios en comunicación');
INSERT INTO l3_areas_tematicas VALUES (10, 'Educación', 'Área de estudios pedagógicos');
INSERT INTO l3_areas_tematicas VALUES (11, 'Gestión', 'Área de administración y negocios');
INSERT INTO l3_areas_tematicas VALUES (12, 'Sociología', 'Área de estudios sociales');
INSERT INTO l3_areas_tematicas VALUES (13, 'Filosofía', 'Área de estudios filosóficos');
INSERT INTO l3_areas_tematicas VALUES (14, 'Historia', 'Área de estudios históricos');
INSERT INTO l3_areas_tematicas VALUES (15, 'Lingüística', 'Área de estudios del lenguaje');

-- Categorías de Productos
INSERT INTO l3_categorias VALUES (1, 'Libros Académicos', 'Libros para cursos universitarios');
INSERT INTO l3_categorias VALUES (2, 'Revistas Académicas', 'Publicaciones periódicas académicas');
INSERT INTO l3_categorias VALUES (3, 'Útiles de Escritorio', 'Materiales de oficina y estudio');
INSERT INTO l3_categorias VALUES (4, 'Merchandising PUCP', 'Productos institucionales PUCP');
INSERT INTO l3_categorias VALUES (5, 'Literatura General', 'Libros de interés general');
INSERT INTO l3_categorias VALUES (6, 'Material Digital', 'Recursos educativos digitales');
INSERT INTO l3_categorias VALUES (7, 'Arte y Diseño', 'Materiales para arte y diseño');
INSERT INTO l3_categorias VALUES (8, 'Material Laboratorio', 'Instrumentos y materiales de laboratorio');
INSERT INTO l3_categorias VALUES (9, 'Papelería', 'Artículos de papel y cartulina');
INSERT INTO l3_categorias VALUES (10, 'Electrónica', 'Componentes y accesorios electrónicos');

-- Tipos de Cliente
INSERT INTO l3_tipos_cliente VALUES (1, 'Estudiante PUCP', 'Estudiantes matriculados en la PUCP');
INSERT INTO l3_tipos_cliente VALUES (2, 'Docente PUCP', 'Profesores que enseñan en la PUCP');
INSERT INTO l3_tipos_cliente VALUES (3, 'Administrativo PUCP', 'Personal administrativo de la PUCP');
INSERT INTO l3_tipos_cliente VALUES (4, 'Público General', 'Clientes externos a la PUCP');
INSERT INTO l3_tipos_cliente VALUES (5, 'Egresado PUCP', 'Ex-alumnos de la PUCP');
INSERT INTO l3_tipos_cliente VALUES (6, 'Investigador PUCP', 'Personal de investigación PUCP');
INSERT INTO l3_tipos_cliente VALUES (7, 'Biblioteca PUCP', 'Sistema de Bibliotecas PUCP');
INSERT INTO l3_tipos_cliente VALUES (8, 'Institucional', 'Otras instituciones educativas');

-- Editoriales
INSERT INTO l3_editoriales VALUES (1, 'Fondo Editorial PUCP', 'Perú', 'Multidisciplinario', 'Juan Pérez', 'jperez@pucp.edu.pe', '999888777');
INSERT INTO l3_editoriales VALUES (2, 'McGraw-Hill', 'Estados Unidos', 'Ingeniería y Ciencias', 'María García', 'mgarcia@mcgraw.com', '998877665');
INSERT INTO l3_editoriales VALUES (3, 'Pearson', 'Reino Unido', 'Educación Superior', 'Carlos López', 'clopez@pearson.com', '997766554');
INSERT INTO l3_editoriales VALUES (4, 'Oxford University Press', 'Reino Unido', 'Humanidades', 'Ana Smith', 'asmith@oxford.com', '996655443');
INSERT INTO l3_editoriales VALUES (5, 'Cambridge University Press', 'Reino Unido', 'Académico General', 'John Doe', 'jdoe@cambridge.com', '995544332');
INSERT INTO l3_editoriales VALUES (6, 'Springer', 'Alemania', 'Ciencias e Ingeniería', 'Hans Mueller', 'hmueller@springer.com', '994433221');
INSERT INTO l3_editoriales VALUES (7, 'Planeta', 'España', 'Literatura General', 'Carmen Rivas', 'crivas@planeta.com', '993322110');
INSERT INTO l3_editoriales VALUES (8, 'Cengage Learning', 'Estados Unidos', 'Educación Superior', 'Peter Smith', 'psmith@cengage.com', '992211009');
INSERT INTO l3_editoriales VALUES (9, 'Wiley', 'Estados Unidos', 'Ciencias y Tecnología', 'Robert Johnson', 'rjohnson@wiley.com', '991100998');
INSERT INTO l3_editoriales VALUES (10, 'Santillana', 'España', 'Educación General', 'Miguel Sánchez', 'msanchez@santillana.com', '990099887');
INSERT INTO l3_editoriales VALUES (11, 'Elsevier', 'Países Bajos', 'Ciencias y Medicina', 'Lisa Brown', 'lbrown@elsevier.com', '989988776');
INSERT INTO l3_editoriales VALUES (12, 'Thomson Reuters', 'Canadá', 'Derecho y Negocios', 'David Wilson', 'dwilson@thomson.com', '988877665');

-- Cursos
INSERT INTO l3_cursos VALUES (1, 'MAT101', 'Cálculo 1', 'Ciencias');
INSERT INTO l3_cursos VALUES (2, 'DER101', 'Introducción al Derecho', 'Derecho');
INSERT INTO l3_cursos VALUES (3, 'ING101', 'Programación 1', 'Ingeniería');
INSERT INTO l3_cursos VALUES (4, 'ECO101', 'Economía General', 'Economía');
INSERT INTO l3_cursos VALUES (5, 'HUM101', 'Filosofía', 'Humanidades');
INSERT INTO l3_cursos VALUES (6, 'FIS101', 'Física 1', 'Ciencias');
INSERT INTO l3_cursos VALUES (7, 'QUI101', 'Química General', 'Ciencias');
INSERT INTO l3_cursos VALUES (8, 'COM101', 'Teoría de la Comunicación', 'Comunicaciones');
INSERT INTO l3_cursos VALUES (9, 'PSI101', 'Psicología General', 'Psicología');
INSERT INTO l3_cursos VALUES (10, 'ARQ101', 'Diseño Arquitectónico', 'Arquitectura');
INSERT INTO l3_cursos VALUES (11, 'ART101', 'Historia del Arte', 'Arte');
INSERT INTO l3_cursos VALUES (12, 'GES101', 'Gestión Empresarial', 'Gestión');
INSERT INTO l3_cursos VALUES (13, 'SOC101', 'Sociología', 'Sociología');
INSERT INTO l3_cursos VALUES (14, 'EDU101', 'Teorías del Aprendizaje', 'Educación');
INSERT INTO l3_cursos VALUES (15, 'LIN101', 'Lingüística General', 'Lingüística');

COMMIT;

-- Productos
INSERT INTO l3_productos VALUES (1, 'LIB001', 'Cálculo Diferencial', 'Libro fundamental de cálculo para ciencias e ingeniería', 1, 150.00, 50, 10, 20, 'ACTIVO', 2, 'EST-A1-01');
INSERT INTO l3_productos VALUES (2, 'LIB002', 'Derecho Civil', 'Manual completo de derecho civil', 1, 180.00, 0, 8, 15, 'DESCONTINUADO', 1, 'EST-A1-02');
INSERT INTO l3_productos VALUES (3, 'LIB003', 'Introducción a la Psicología', 'Fundamentos de psicología general', 1, 130.00, 45, 10, 18, 'ACTIVO', 3, 'EST-A1-03');
INSERT INTO l3_productos VALUES (4, 'REV001', 'Journal of Engineering Vol.1', 'Revista académica de ingeniería', 2, 45.00, 30, 5, 10, 'ACTIVO', 6, 'EST-B1-01');
INSERT INTO l3_productos VALUES (5, 'REV002', 'Economics Review', 'Revista especializada en economía', 2, 55.00, 25, 5, 12, 'ACTIVO', 4, 'EST-B1-02');
INSERT INTO l3_productos VALUES (6, 'LIB004', 'Química Orgánica', 'Texto completo de química orgánica', 1, 160.00, 35, 8, 15, 'ACTIVO', 2, 'EST-A1-04');
INSERT INTO l3_productos VALUES (7, 'MER001', 'Polo PUCP', 'Polo institucional con logo PUCP', 4, 35.00, 100, 20, 40, 'ACTIVO', NULL, 'EST-C1-01');
INSERT INTO l3_productos VALUES (8, 'MER002', 'Mochila PUCP', 'Mochila con logo institucional', 4, 65.00, 80, 15, 30, 'ACTIVO', NULL, 'EST-C1-02');
INSERT INTO l3_productos VALUES (9, 'LIB005', 'Marketing Digital', 'Estrategias modernas de marketing', 1, 140.00, 40, 8, 16, 'ACTIVO', 8, 'EST-A1-05');
INSERT INTO l3_productos VALUES (10, 'LIB006', 'Arquitectura Moderna', 'Historia y conceptos de arquitectura', 1, 170.00, 30, 6, 12, 'ACTIVO', 1, 'EST-A1-06');
INSERT INTO l3_productos VALUES (11, 'REV003', 'Humanidades Hoy', 'Revista de estudios humanísticos', 2, 40.00, 35, 7, 14, 'ACTIVO', 1, 'EST-B1-03');
INSERT INTO l3_productos VALUES (12, 'UTI001', 'Set de Geometría', 'Kit completo de instrumentos geométricos', 3, 25.00, 150, 30, 50, 'ACTIVO', NULL, 'EST-D1-01');
INSERT INTO l3_productos VALUES (13, 'LIB007', 'Gestión de Proyectos', 'Manual de gestión de proyectos', 1, 145.00, 40, 8, 16, 'ACTIVO', 3, 'EST-A1-07');
INSERT INTO l3_productos VALUES (14, 'REV004', 'Arte Contemporáneo', 'Revista especializada en arte', 2, 50.00, 30, 6, 12, 'ACTIVO', 7, 'EST-B1-04');
INSERT INTO l3_productos VALUES (15, 'MER003', 'Taza PUCP', 'Taza cerámica con logo institucional', 4, 20.00, 0, 25, 45, 'DESCONTINUADO', NULL, 'EST-C1-03');

-- Libros (para productos tipo libro)
INSERT INTO l3_libros VALUES (1, 1, '9780123456789', 2024, 'Primera Edición', 'Español', 500, '21x27cm', 0.8, 'Tapa dura');
INSERT INTO l3_libros VALUES (2, 2, '9780987654321', 2023, 'Segunda Edición', 'Español', 400, '17x24cm', 0.6, 'Tapa blanda');
INSERT INTO l3_libros VALUES (3, 3, '9781234567890', 2024, 'Tercera Edición', 'Español', 350, '21x27cm', 0.7, 'Tapa dura');
INSERT INTO l3_libros VALUES (4, 6, '9789876543210', 2023, 'Primera Edición', 'Español', 450, '21x27cm', 0.9, 'Tapa dura');
INSERT INTO l3_libros VALUES (5, 9, '9782345678901', 2024, 'Segunda Edición', 'Español', 380, '17x24cm', 0.5, 'Tapa blanda');
INSERT INTO l3_libros VALUES (6, 10, '9788765432109', 2023, 'Primera Edición', 'Español', 420, '21x27cm', 0.8, 'Tapa dura');
INSERT INTO l3_libros VALUES (7, 13, '9783456789012', 2024, 'Primera Edición', 'Español', 300, '17x24cm', 0.4, 'Tapa blanda');

-- Revistas
INSERT INTO l3_revistas VALUES (1, 4, '12345678', 'Vol. 1', 'Núm. 1', '2024-1');
INSERT INTO l3_revistas VALUES (2, 5, '23456789', 'Vol. 15', 'Núm. 2', '2024-1');
INSERT INTO l3_revistas VALUES (3, 11, '34567890', 'Vol. 8', 'Núm. 1', '2024-1');
INSERT INTO l3_revistas VALUES (4, 14, '45678901', 'Vol. 5', 'Núm. 3', '2024-1');

-- Campañas
INSERT INTO l3_campanias VALUES (1, 'Inicio de Ciclo 2024-1', 'Descuentos para inicio del ciclo académico', TO_DATE('2024-03-01', 'YYYY-MM-DD'), TO_DATE('2024-03-15', 'YYYY-MM-DD'), 15.00);
INSERT INTO l3_campanias VALUES (2, 'Feria del Libro PUCP 2024', 'Feria anual del libro universitario', TO_DATE('2024-05-01', 'YYYY-MM-DD'), TO_DATE('2024-05-07', 'YYYY-MM-DD'), 20.00);
INSERT INTO l3_campanias VALUES (3, 'Semana de Ingeniería', 'Descuentos especiales facultad de ingeniería', TO_DATE('2024-06-15', 'YYYY-MM-DD'), TO_DATE('2024-06-21', 'YYYY-MM-DD'), 18.00);
INSERT INTO l3_campanias VALUES (4, 'Aniversario PUCP', 'Celebración institucional', TO_DATE('2024-04-01', 'YYYY-MM-DD'), TO_DATE('2024-04-07', 'YYYY-MM-DD'), 25.00);
INSERT INTO l3_campanias VALUES (5, 'Black Friday PUCP', 'Ofertas especiales fin de año', TO_DATE('2024-11-29', 'YYYY-MM-DD'), TO_DATE('2024-12-01', 'YYYY-MM-DD'), 30.00);

-- Precios por Tipo de Cliente
INSERT INTO l3_precios_tipo_cliente VALUES (1, 1, 20.00); -- Estudiantes obtienen 20% en libros de cálculo
INSERT INTO l3_precios_tipo_cliente VALUES (1, 2, 15.00); -- Docentes obtienen 15% en libros de cálculo
INSERT INTO l3_precios_tipo_cliente VALUES (2, 1, 20.00); -- Estudiantes obtienen 20% en libros de derecho
INSERT INTO l3_precios_tipo_cliente VALUES (2, 2, 15.00); -- Docentes obtienen 15% en libros de derecho
INSERT INTO l3_precios_tipo_cliente VALUES (3, 1, 20.00); -- Estudiantes obtienen 20% en libros de psicología
INSERT INTO l3_precios_tipo_cliente VALUES (3, 2, 15.00); -- Docentes obtienen 15% en libros de psicología
INSERT INTO l3_precios_tipo_cliente VALUES (4, 1, 10.00); -- Estudiantes obtienen 10% en revistas
INSERT INTO l3_precios_tipo_cliente VALUES (4, 2, 10.00); -- Docentes obtienen 10% en revistas
INSERT INTO l3_precios_tipo_cliente VALUES (7, 1, 15.00); -- Estudiantes obtienen 15% en merchandising
INSERT INTO l3_precios_tipo_cliente VALUES (7, 2, 10.00); -- Docentes obtienen 10% en merchandising
INSERT INTO l3_precios_tipo_cliente VALUES (8, 1, 15.00); -- Estudiantes obtienen 15% en merchandising
INSERT INTO l3_precios_tipo_cliente VALUES (9, 1, 20.00); -- Estudiantes obtienen 20% en libros de marketing
INSERT INTO l3_precios_tipo_cliente VALUES (9, 2, 15.00); -- Docentes obtienen 15% en libros de marketing
INSERT INTO l3_precios_tipo_cliente VALUES (10, 1, 20.00); -- Estudiantes obtienen 20% en libros de arquitectura
INSERT INTO l3_precios_tipo_cliente VALUES (10, 2, 15.00); -- Docentes obtienen 15% en libros de arquitectura

COMMIT;

-- Productos-Áreas (relación entre productos y áreas temáticas)
INSERT INTO l3_productos_areas VALUES (1, 1);  -- Cálculo Diferencial - Ciencias
INSERT INTO l3_productos_areas VALUES (1, 3);  -- Cálculo Diferencial - Ingeniería
INSERT INTO l3_productos_areas VALUES (2, 4);  -- Derecho Civil - Derecho
INSERT INTO l3_productos_areas VALUES (3, 7);  -- Introducción a la Psicología - Psicología
INSERT INTO l3_productos_areas VALUES (4, 3);  -- Journal of Engineering - Ingeniería
INSERT INTO l3_productos_areas VALUES (5, 5);  -- Economics Review - Economía
INSERT INTO l3_productos_areas VALUES (6, 1);  -- Química Orgánica - Ciencias
INSERT INTO l3_productos_areas VALUES (9, 11); -- Marketing Digital - Gestión
INSERT INTO l3_productos_areas VALUES (10, 6); -- Arquitectura Moderna - Arquitectura
INSERT INTO l3_productos_areas VALUES (11, 2); -- Humanidades Hoy - Humanidades
INSERT INTO l3_productos_areas VALUES (13, 11); -- Gestión de Proyectos - Gestión
INSERT INTO l3_productos_areas VALUES (14, 8); -- Arte Contemporáneo - Arte
INSERT INTO l3_productos_areas VALUES (6, 3);  -- Química Orgánica también para Ingeniería
INSERT INTO l3_productos_areas VALUES (9, 5);  -- Marketing Digital también para Economía
INSERT INTO l3_productos_areas VALUES (13, 5); -- Gestión de Proyectos también para Economía

-- Bibliografía de Cursos
INSERT INTO l3_bibliografia_cursos VALUES (1, 1, 'OBLIGATORIA');  -- MAT101 - Cálculo Diferencial
INSERT INTO l3_bibliografia_cursos VALUES (2, 2, 'OBLIGATORIA');  -- DER101 - Derecho Civil
INSERT INTO l3_bibliografia_cursos VALUES (3, 3, 'OBLIGATORIA');  -- ING101 - Introducción a la Psicología
INSERT INTO l3_bibliografia_cursos VALUES (4, 4, 'COMPLEMENTARIA'); -- ECO101 - Química Orgánica
INSERT INTO l3_bibliografia_cursos VALUES (5, 5, 'OBLIGATORIA');  -- HUM101 - Marketing Digital
INSERT INTO l3_bibliografia_cursos VALUES (6, 6, 'OBLIGATORIA');  -- FIS101 - Arquitectura Moderna
INSERT INTO l3_bibliografia_cursos VALUES (7, 7, 'COMPLEMENTARIA'); -- QUI101 - Programación en Python
INSERT INTO l3_bibliografia_cursos VALUES (8, 1, 'COMPLEMENTARIA'); -- COM101 - También usa Cálculo
INSERT INTO l3_bibliografia_cursos VALUES (9, 2, 'COMPLEMENTARIA'); -- PSI101 - También usa Derecho
INSERT INTO l3_bibliografia_cursos VALUES (10, 3, 'OBLIGATORIA');  -- ARQ101 - También usa Psicología
INSERT INTO l3_bibliografia_cursos VALUES (11, 4, 'OBLIGATORIA');  -- ART101 - También usa Química
INSERT INTO l3_bibliografia_cursos VALUES (12, 5, 'COMPLEMENTARIA'); -- GES101 - También usa Marketing
INSERT INTO l3_bibliografia_cursos VALUES (13, 6, 'COMPLEMENTARIA'); -- SOC101 - También usa Arquitectura
INSERT INTO l3_bibliografia_cursos VALUES (14, 7, 'OBLIGATORIA');  -- EDU101 - También usa Programación
INSERT INTO l3_bibliografia_cursos VALUES (15, 1, 'OBLIGATORIA');  -- LIN101 - También usa Cálculo

-- Clientes
INSERT INTO l3_clientes VALUES (1, 1, 'Ana', 'Torres', 'atorres@pucp.edu.pe', '999111222', '20240101');
INSERT INTO l3_clientes VALUES (2, 2, 'Jorge', 'Ramírez', 'jramirez@pucp.edu.pe', '999222333', 'D0012345');
INSERT INTO l3_clientes VALUES (3, 3, 'María', 'López', 'mlopez@pucp.edu.pe', '999333444', 'A0023456');
INSERT INTO l3_clientes VALUES (4, 4, 'Carlos', 'García', 'cgarcia@gmail.com', '999444555', NULL);
INSERT INTO l3_clientes VALUES (5, 1, 'Laura', 'Mendoza', 'lmendoza@pucp.edu.pe', '999555666', '20240102');
INSERT INTO l3_clientes VALUES (6, 2, 'Pedro', 'Díaz', 'pdiaz@pucp.edu.pe', '999666777', 'D0034567');
INSERT INTO l3_clientes VALUES (7, 5, 'Rosa', 'Vargas', 'rvargas@gmail.com', '999777888', 'E0045678');
INSERT INTO l3_clientes VALUES (8, 1, 'Juan', 'Castro', 'jcastro@pucp.edu.pe', '999888999', '20240103');
INSERT INTO l3_clientes VALUES (9, 6, 'Luis', 'Flores', 'lflores@pucp.edu.pe', '999999000', 'I0056789');
INSERT INTO l3_clientes VALUES (10, 7, 'Carmen', 'Ruiz', 'cruiz@pucp.edu.pe', '999000111', 'B0067890');

-- Órdenes de Compra
INSERT INTO l3_ordenes_compra VALUES (1, 2, TO_DATE('2024-01-15', 'YYYY-MM-DD'), TO_DATE('2024-02-15', 'YYYY-MM-DD'), 'PROGRAMADA', 'APROBADA', 5000.00, 200.00, 'Reposición de stock para ciclo 2024-1');
INSERT INTO l3_ordenes_compra VALUES (2, 3, TO_DATE('2024-01-20', 'YYYY-MM-DD'), TO_DATE('2024-02-20', 'YYYY-MM-DD'), 'PROGRAMADA', 'EN_PROCESO', 6000.00, 250.00, 'Stock para feria del libro');
INSERT INTO l3_ordenes_compra VALUES (3, 1, TO_DATE('2024-01-25', 'YYYY-MM-DD'), TO_DATE('2024-01-30', 'YYYY-MM-DD'), 'EXTRAORDINARIA', 'APROBADA', 2000.00, 100.00, 'Pedido urgente facultad de letras');
INSERT INTO l3_ordenes_compra VALUES (4, 4, TO_DATE('2024-02-01', 'YYYY-MM-DD'), TO_DATE('2024-03-01', 'YYYY-MM-DD'), 'PROGRAMADA', 'PENDIENTE', 8000.00, 300.00, 'Stock regular primer semestre');
INSERT INTO l3_ordenes_compra VALUES (5, 6, TO_DATE('2024-02-05', 'YYYY-MM-DD'), TO_DATE('2024-02-15', 'YYYY-MM-DD'), 'EXTRAORDINARIA', 'APROBADA', 3000.00, 150.00, 'Pedido especial facultad de ingeniería');

-- Detalle de Órdenes de Compra
INSERT INTO l3_ordenes_compra_detalle VALUES (1, 1, 30, 100.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (1, 2, 25, 90.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (1, 3, 20, 85.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (2, 4, 15, 35.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (2, 5, 20, 40.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (2, 6, 25, 95.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (3, 9, 15, 90.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (3, 10, 10, 100.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (4, 11, 30, 30.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (4, 13, 25, 95.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (5, 1, 20, 100.00);
INSERT INTO l3_ordenes_compra_detalle VALUES (5, 6, 15, 95.00);

COMMIT;

-- Ventas
INSERT INTO l3_ventas VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 300.00, 60.00, 240.00, 'TARJETA', 'AUT001', NULL);
INSERT INTO l3_ventas VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 450.00, 67.50, 382.50, 'EFECTIVO', NULL, NULL);
INSERT INTO l3_ventas VALUES (3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 800.00, 0.00, 800.00, 'TRANSFERENCIA', 'AUT002', 'CC-LETRAS-2024');
INSERT INTO l3_ventas VALUES (4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 150.00, 0.00, 150.00, 'EFECTIVO', NULL, NULL);
INSERT INTO l3_ventas VALUES (5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 250.00, 50.00, 200.00, 'TARJETA', 'AUT003', NULL);
INSERT INTO l3_ventas VALUES (6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 600.00, 90.00, 510.00, 'TRANSFERENCIA', 'AUT004', 'CC-ING-2024');
INSERT INTO l3_ventas VALUES (7, 7, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 180.00, 27.00, 153.00, 'TARJETA', 'AUT005', NULL);
INSERT INTO l3_ventas VALUES (8, 8, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 420.00, 84.00, 336.00, 'EFECTIVO', NULL, NULL);
INSERT INTO l3_ventas VALUES (9, 9, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 550.00, 82.50, 467.50, 'TARJETA', 'AUT006', NULL);
INSERT INTO l3_ventas VALUES (10, 10, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 900.00, 180.00, 720.00, 'TRANSFERENCIA', 'AUT007', 'CC-BIB-2024');

-- Ventas Detalle
INSERT INTO l3_ventas_detalle VALUES (1, 1, 2, 150.00, 30.00, 15.00, 105.00, 1);
INSERT INTO l3_ventas_detalle VALUES (1, 7, 1, 35.00, 5.25, 0.00, 29.75, NULL);
INSERT INTO l3_ventas_detalle VALUES (2, 2, 3, 180.00, 27.00, 18.00, 135.00, 1);
INSERT INTO l3_ventas_detalle VALUES (3, 3, 5, 130.00, 0.00, 0.00, 130.00, NULL);
INSERT INTO l3_ventas_detalle VALUES (3, 6, 2, 160.00, 0.00, 0.00, 160.00, NULL);
INSERT INTO l3_ventas_detalle VALUES (4, 4, 3, 45.00, 0.00, 0.00, 45.00, NULL);
INSERT INTO l3_ventas_detalle VALUES (5, 5, 2, 55.00, 11.00, 13.75, 30.25, 2);
INSERT INTO l3_ventas_detalle VALUES (5, 8, 2, 65.00, 13.00, 16.25, 35.75, 2);
INSERT INTO l3_ventas_detalle VALUES (6, 9, 3, 140.00, 21.00, 14.00, 105.00, 1);
INSERT INTO l3_ventas_detalle VALUES (6, 10, 2, 170.00, 25.50, 17.00, 127.50, 1);
INSERT INTO l3_ventas_detalle VALUES (7, 11, 3, 40.00, 6.00, 10.00, 24.00, 3);
INSERT INTO l3_ventas_detalle VALUES (8, 13, 2, 145.00, 29.00, 14.50, 101.50, 1);
INSERT INTO l3_ventas_detalle VALUES (8, 14, 2, 50.00, 10.00, 12.50, 27.50, 2);
INSERT INTO l3_ventas_detalle VALUES (9, 15, 5, 20.00, 3.00, 5.00, 12.00, 3);
INSERT INTO l3_ventas_detalle VALUES (10, 1, 6, 150.00, 30.00, 37.50, 82.50, 4);

-- Pedidos Especiales
INSERT INTO l3_pedidos_especiales VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), TO_DATE('2024-02-15', 'YYYY-MM-DD'), 'EN_PROCESO', 200.00, 'Libro importado no disponible en catálogo');
INSERT INTO l3_pedidos_especiales VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), TO_DATE('2024-02-01', 'YYYY-MM-DD'), 'LISTO', 300.00, 'Pedido de libros para curso completo');
INSERT INTO l3_pedidos_especiales VALUES (3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), TO_DATE('2024-03-01', 'YYYY-MM-DD'), 'SOLICITADO', 150.00, 'Edición especial de libro de derecho');
INSERT INTO l3_pedidos_especiales VALUES (4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), TO_DATE('2024-02-20', 'YYYY-MM-DD'), 'EN_PROCESO', 250.00, 'Compra al por mayor para biblioteca personal');
INSERT INTO l3_pedidos_especiales VALUES (5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), TO_DATE('2024-02-10', 'YYYY-MM-DD'), 'LISTO', 180.00, 'Libro especializado de arquitectura');
INSERT INTO l3_pedidos_especiales VALUES (6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), TO_DATE('2024-03-15', 'YYYY-MM-DD'), 'SOLICITADO', 400.00, 'Colección completa de revista científica');
INSERT INTO l3_pedidos_especiales VALUES (7, 7, TO_DATE('2025-01-21', 'YYYY-MM-DD'), TO_DATE('2025-02-28', 'YYYY-MM-DD'), 'EN_PROCESO', 220.00, 'Libros de edición limitada');
INSERT INTO l3_pedidos_especiales VALUES (8, 8, TO_DATE('2025-01-22', 'YYYY-MM-DD'), TO_DATE('2025-02-25', 'YYYY-MM-DD'), 'LISTO', 280.00, 'Material complementario de curso');

-- Pérdidas de Inventario
INSERT INTO l3_perdidas_inventario VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Daño por humedad en almacén');
INSERT INTO l3_perdidas_inventario VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 2, 'PERDIDA', 'No encontrado en inventario físico');
INSERT INTO l3_perdidas_inventario VALUES (3, 4, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 3, 'AJUSTE', 'Diferencia en conteo de inventario');
INSERT INTO l3_perdidas_inventario VALUES (4, 6, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Daño en manipulación');
INSERT INTO l3_perdidas_inventario VALUES (5, 7, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 2, 'PERDIDA', 'Faltante en entrega');
INSERT INTO l3_perdidas_inventario VALUES (6, 8, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Producto dañado en exhibición');
INSERT INTO l3_perdidas_inventario VALUES (7, 9, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 1, 'AJUSTE', 'Corrección de inventario');
INSERT INTO l3_perdidas_inventario VALUES (8, 11, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 2, 'PERDIDA', 'Extravío en traslado');
INSERT INTO l3_perdidas_inventario VALUES (9, 13, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Daño en empaque');
INSERT INTO l3_perdidas_inventario VALUES (10, 15, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 3, 'AJUSTE', 'Actualización de inventario');
INSERT INTO l3_perdidas_inventario VALUES (11, 3, TO_DATE('2024-01-25', 'YYYY-MM-DD'), 2, 'DETERIORO', 'Daño por caída en manipulación');
INSERT INTO l3_perdidas_inventario VALUES (12, 5, TO_DATE('2024-01-26', 'YYYY-MM-DD'), 1, 'PERDIDA', 'No ubicado en inventario');
INSERT INTO l3_perdidas_inventario VALUES (13, 7, TO_DATE('2024-01-27', 'YYYY-MM-DD'), 3, 'AJUSTE', 'Corrección por conteo físico');
INSERT INTO l3_perdidas_inventario VALUES (14, 9, TO_DATE('2024-01-28', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Daño en almacenamiento');
INSERT INTO l3_perdidas_inventario VALUES (15, 11, TO_DATE('2024-01-29', 'YYYY-MM-DD'), 2, 'PERDIDA', 'Pérdida en tránsito');


-- Productos Condición
INSERT INTO l3_productos_condicion VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-01', 'Stock en perfectas condiciones');
INSERT INTO l3_productos_condicion VALUES (2, 2, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'REGULAR', 'EST-A1-02', 'Algunas portadas con desgaste menor');
INSERT INTO l3_productos_condicion VALUES (3, 3, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-03', 'Material nuevo sin daños');
INSERT INTO l3_productos_condicion VALUES (4, 4, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-B1-01', 'Revistas en buen estado');
INSERT INTO l3_productos_condicion VALUES (5, 5, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'REGULAR', 'EST-B1-02', 'Algunas revistas con marcas de uso');
INSERT INTO l3_productos_condicion VALUES (6, 6, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-04', 'Libros nuevos en perfecto estado');
INSERT INTO l3_productos_condicion VALUES (7, 7, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-C1-01', 'Merchandising sin defectos');
INSERT INTO l3_productos_condicion VALUES (8, 8, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-C1-02', 'Productos en buen estado');
INSERT INTO l3_productos_condicion VALUES (9, 9, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'REGULAR', 'EST-A1-05', 'Algunos ejemplares con desgaste');
INSERT INTO l3_productos_condicion VALUES (10, 10, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-06', 'Libros en excelente estado');
INSERT INTO l3_productos_condicion VALUES (11, 11, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-B1-03', 'Revistas en excelente estado');
INSERT INTO l3_productos_condicion VALUES (12, 12, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'REGULAR', 'EST-D1-01', 'Algunos sets con empaques deteriorados');
INSERT INTO l3_productos_condicion VALUES (13, 13, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-07', 'Stock recién recibido');
INSERT INTO l3_productos_condicion VALUES (14, 14, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-B1-04', 'Material en perfectas condiciones');
INSERT INTO l3_productos_condicion VALUES (15, 15, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-C1-03', 'Productos nuevos sin uso');


COMMIT;

-- Pedidos Especiales Detalle
INSERT INTO l3_pedidos_especiales_detalle VALUES (1, 1, 2, 160.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (1, 2, 1, 130.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (2, 3, 5, 140.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (2, 4, 3, 50.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (3, 5, 2, 60.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (3, 6, 1, 170.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (4, 7, 4, 40.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (4, 8, 2, 70.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (5, 9, 3, 150.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (6, 10, 2, 180.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (7, 11, 3, 45.00);
INSERT INTO l3_pedidos_especiales_detalle VALUES (8, 13, 2, 155.00);

-- Campañas Productos
INSERT INTO l3_campanias_productos VALUES (1, 1, 15.00);  -- Inicio de Ciclo - Cálculo
INSERT INTO l3_campanias_productos VALUES (1, 2, 15.00);  -- Inicio de Ciclo - Derecho
INSERT INTO l3_campanias_productos VALUES (1, 3, 15.00);  -- Inicio de Ciclo - Psicología
INSERT INTO l3_campanias_productos VALUES (2, 4, 20.00);  -- Feria del Libro - Revista Ingeniería
INSERT INTO l3_campanias_productos VALUES (2, 5, 20.00);  -- Feria del Libro - Revista Economía
INSERT INTO l3_campanias_productos VALUES (2, 6, 20.00);  -- Feria del Libro - Química
INSERT INTO l3_campanias_productos VALUES (3, 7, 25.00);  -- Black Friday - Merchandising
INSERT INTO l3_campanias_productos VALUES (3, 8, 25.00);  -- Black Friday - Merchandising
INSERT INTO l3_campanias_productos VALUES (3, 9, 25.00);  -- Black Friday - Marketing
INSERT INTO l3_campanias_productos VALUES (4, 10, 18.00); -- Navidad - Arquitectura
INSERT INTO l3_campanias_productos VALUES (4, 11, 18.00); -- Navidad - Revista Humanidades
INSERT INTO l3_campanias_productos VALUES (5, 13, 22.00); -- Aniversario - Gestión
INSERT INTO l3_campanias_productos VALUES (5, 14, 22.00); -- Aniversario - Revista Arte
INSERT INTO l3_campanias_productos VALUES (5, 15, 22.00); -- Aniversario - Merchandising

-- Editoriales Histórico
INSERT INTO l3_editoriales_historico VALUES (1, 1, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 15, 95.5, 4.5, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (2, 2, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 20, 92.0, 4.2, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (3, 3, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 18, 93.5, 4.3, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (4, 4, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 22, 91.0, 4.0, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (5, 5, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 16, 94.5, 4.4, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (6, 6, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 21, 90.5, 4.1, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (7, 7, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 17, 93.0, 4.3, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (8, 8, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 19, 92.5, 4.2, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (9, 9, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 23, 89.5, 3.9, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (10, 10, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 14, 96.0, 4.6, '2023-2');
INSERT INTO l3_editoriales_historico VALUES (11, 1, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 16, 94.5, 4.4, '2024-0');
INSERT INTO l3_editoriales_historico VALUES (12, 2, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 21, 91.0, 4.1, '2024-0');
INSERT INTO l3_editoriales_historico VALUES (13, 3, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 19, 92.5, 4.2, '2024-0');
INSERT INTO l3_editoriales_historico VALUES (14, 4, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 23, 89.5, 3.9, '2024-0');
INSERT INTO l3_editoriales_historico VALUES (15, 5, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 17, 93.0, 4.3, '2024-0');

-- Encuestas
INSERT INTO l3_encuestas VALUES (1, 1, 1, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 4.5, 4.0, 'Excelente servicio, entrega rápida');
INSERT INTO l3_encuestas VALUES (2, 2, 2, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 4.0, 4.5, 'Buenos precios, amplio catálogo');
INSERT INTO l3_encuestas VALUES (3, 3, 3, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 3.5, 4.0, 'Servicio regular, mejorar tiempos de atención');
INSERT INTO l3_encuestas VALUES (4, 4, 4, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 5.0, 4.5, 'Muy satisfecho con la atención');
INSERT INTO l3_encuestas VALUES (5, 5, 5, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 4.0, 3.5, 'Productos buenos, mejorar stock');
INSERT INTO l3_encuestas VALUES (6, 6, 6, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 4.5, 4.0, 'Excelente variedad de libros');
INSERT INTO l3_encuestas VALUES (7, 7, 7, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 3.0, 3.5, 'Precios algo elevados');
INSERT INTO l3_encuestas VALUES (8, 8, 8, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 4.5, 5.0, 'Muy satisfecho con todo el servicio');
INSERT INTO l3_encuestas VALUES (9, 9, 9, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 4.0, 4.0, 'Buena experiencia de compra');
INSERT INTO l3_encuestas VALUES (10, 10, 10, TO_DATE('2024-01-25', 'YYYY-MM-DD'), 5.0, 4.5, 'Excelente atención del personal');

-- Sugerencias
INSERT INTO sugerencia VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'PRODUCTO', 'Incluir más libros de matemáticas avanzadas', 'REGISTRADA');
INSERT INTO sugerencia VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'SERVICIO', 'Ampliar horario de atención', 'EN_REVISION');
INSERT INTO sugerencia VALUES (3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 'INFRAESTRUCTURA', 'Mejorar iluminación en estantes', 'IMPLEMENTADA');
INSERT INTO sugerencia VALUES (4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 'PRODUCTO', 'Traer más títulos en inglés', 'REGISTRADA');
INSERT INTO sugerencia VALUES (5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 'SERVICIO', 'Implementar sistema de reservas online', 'EN_REVISION');
INSERT INTO sugerencia VALUES (6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 'PRODUCTO', 'Aumentar variedad de útiles', 'IMPLEMENTADA');
INSERT INTO sugerencia VALUES (7, 7, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 'INFRAESTRUCTURA', 'Más espacios de lectura', 'EN_REVISION');
INSERT INTO sugerencia VALUES (8, 8, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 'SERVICIO', 'Ofrecer servicio de empaque de regalo', 'REGISTRADA');
INSERT INTO sugerencia VALUES (9, 9, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 'PRODUCTO', 'Incluir más merchandising PUCP', 'IMPLEMENTADA');
INSERT INTO sugerencia VALUES (10, 10, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 'SERVICIO', 'Implementar sistema de notificaciones', 'EN_REVISION');

-- Incidencias
INSERT INTO l3_incidencias VALUES (1, 1, 1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Libro con páginas dañadas', 'EN_PROCESO', 'Se está gestionando el reemplazo con editorial');
INSERT INTO l3_incidencias VALUES (2, 2, 2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'ERROR_ENTREGA', 'Entrega de edición incorrecta', 'RESUELTA', 'Se realizó el cambio por la edición correcta');
INSERT INTO l3_incidencias VALUES (3, 3, 3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 'RETRASO_ENTREGA', 'Demora en entrega de pedido', 'CERRADA', 'Se compensó al cliente con descuento adicional');
INSERT INTO l3_incidencias VALUES (4, 4, 4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 'PRODUCTO_INCOMPLETO', 'Falta CD complementario', 'EN_PROCESO', 'Solicitando material faltante a editorial');
INSERT INTO l3_incidencias VALUES (5, 5, 5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 'COBRO_INCORRECTO', 'Error en aplicación de descuento', 'RESUELTA', 'Se realizó el reembolso de la diferencia');
INSERT INTO l3_incidencias VALUES (6, 6, 6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Problemas con el empaste', 'REGISTRADA', 'Pendiente de revisión por el proveedor');
INSERT INTO l3_incidencias VALUES (7, 7, 7, 7, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 'ERROR_SISTEMA', 'Problema con facturación', 'RESUELTA', 'Se corrigió el documento de venta');
INSERT INTO l3_incidencias VALUES (8, 8, 8, 8, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Merchandising con falla', 'EN_PROCESO', 'En espera de reposición');
INSERT INTO l3_incidencias VALUES (9, 9, 9, 9, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 'RETRASO_ENTREGA', 'Demora en pedido especial', 'REGISTRADA', 'En seguimiento con proveedor');
INSERT INTO l3_incidencias VALUES (10, 10, 10, 10, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 'ERROR_ENTREGA', 'Entrega en ubicación incorrecta', 'RESUELTA', 'Se coordinó nueva entrega en ubicación correcta');
INSERT INTO l3_incidencias VALUES (11, 1, 1, 11, TO_DATE('2024-01-25', 'YYYY-MM-DD'), 'PRODUCTO_INCOMPLETO', 'Falta material complementario', 'EN_PROCESO', 'Contactando con editorial');
INSERT INTO l3_incidencias VALUES (12, 2, 2, 12, TO_DATE('2024-01-26', 'YYYY-MM-DD'), 'COBRO_INCORRECTO', 'No se aplicó descuento institucional', 'RESUELTA', 'Se aplicó nota de crédito');
INSERT INTO l3_incidencias VALUES (13, 3, 3, 13, TO_DATE('2024-01-27', 'YYYY-MM-DD'), 'ERROR_SISTEMA', 'Problema con orden de compra', 'CERRADA', 'Se corrigió registro en sistema');
INSERT INTO l3_incidencias VALUES (14, 4, 4, 14, TO_DATE('2024-01-28', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Revista con impresión defectuosa', 'REGISTRADA', 'Pendiente evaluación');
INSERT INTO l3_incidencias VALUES (15, 5, 5, 15, TO_DATE('2024-01-29', 'YYYY-MM-DD'), 'RETRASO_ENTREGA', 'Demora en entrega institucional', 'EN_PROCESO', 'Coordinando con logística');

COMMIT;


