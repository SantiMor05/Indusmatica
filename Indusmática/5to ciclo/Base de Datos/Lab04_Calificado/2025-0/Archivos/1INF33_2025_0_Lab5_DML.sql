-- �reas Tem�ticas
INSERT INTO L6_areas_tematicas VALUES (1, 'Ciencias', '�rea de ciencias b�sicas y aplicadas');
INSERT INTO L6_areas_tematicas VALUES (2, 'Humanidades', '�rea de estudios human�sticos');
INSERT INTO L6_areas_tematicas VALUES (3, 'Ingenier�a', '�rea de estudios en ingenier�a');
INSERT INTO L6_areas_tematicas VALUES (4, 'Derecho', '�rea de ciencias jur�dicas');
INSERT INTO L6_areas_tematicas VALUES (5, 'Econom�a', '�rea de ciencias econ�micas y empresariales');
INSERT INTO L6_areas_tematicas VALUES (6, 'Arquitectura', '�rea de estudios en arquitectura y urbanismo');
INSERT INTO L6_areas_tematicas VALUES (7, 'Psicolog�a', '�rea de estudios del comportamiento humano');
INSERT INTO L6_areas_tematicas VALUES (8, 'Arte', '�rea de estudios art�sticos y culturales');
INSERT INTO L6_areas_tematicas VALUES (9, 'Comunicaciones', '�rea de estudios en comunicaci�n');
INSERT INTO L6_areas_tematicas VALUES (10, 'Educaci�n', '�rea de estudios pedag�gicos');
INSERT INTO L6_areas_tematicas VALUES (11, 'Gesti�n', '�rea de administraci�n y negocios');
INSERT INTO L6_areas_tematicas VALUES (12, 'Sociolog�a', '�rea de estudios sociales');
INSERT INTO L6_areas_tematicas VALUES (13, 'Filosof�a', '�rea de estudios filos�ficos');
INSERT INTO L6_areas_tematicas VALUES (14, 'Historia', '�rea de estudios hist�ricos');
INSERT INTO L6_areas_tematicas VALUES (15, 'Ling��stica', '�rea de estudios del lenguaje');

-- Categor�as de Productos
INSERT INTO L6_categorias VALUES (1, 'Libros Acad�micos', 'Libros para cursos universitarios');
INSERT INTO L6_categorias VALUES (2, 'Revistas Acad�micas', 'Publicaciones peri�dicas acad�micas');
INSERT INTO L6_categorias VALUES (3, '�tiles de Escritorio', 'Materiales de oficina y estudio');
INSERT INTO L6_categorias VALUES (4, 'Merchandising PUCP', 'Productos institucionales PUCP');
INSERT INTO L6_categorias VALUES (5, 'Literatura General', 'Libros de inter�s general');
INSERT INTO L6_categorias VALUES (6, 'Material Digital', 'Recursos educativos digitales');
INSERT INTO L6_categorias VALUES (7, 'Arte y Dise�o', 'Materiales para arte y dise�o');
INSERT INTO L6_categorias VALUES (8, 'Material Laboratorio', 'Instrumentos y materiales de laboratorio');
INSERT INTO L6_categorias VALUES (9, 'Papeler�a', 'Art�culos de papel y cartulina');
INSERT INTO L6_categorias VALUES (10, 'Electr�nica', 'Componentes y accesorios electr�nicos');

-- Tipos de Cliente
INSERT INTO L6_tipos_cliente VALUES (1, 'Estudiante PUCP', 'Estudiantes matriculados en la PUCP');
INSERT INTO L6_tipos_cliente VALUES (2, 'Docente PUCP', 'Profesores que ense�an en la PUCP');
INSERT INTO L6_tipos_cliente VALUES (3, 'Administrativo PUCP', 'Personal administrativo de la PUCP');
INSERT INTO L6_tipos_cliente VALUES (4, 'P�blico General', 'Clientes externos a la PUCP');
INSERT INTO L6_tipos_cliente VALUES (5, 'Egresado PUCP', 'Ex-alumnos de la PUCP');
INSERT INTO L6_tipos_cliente VALUES (6, 'Investigador PUCP', 'Personal de investigaci�n PUCP');
INSERT INTO L6_tipos_cliente VALUES (7, 'Biblioteca PUCP', 'Sistema de Bibliotecas PUCP');
INSERT INTO L6_tipos_cliente VALUES (8, 'Institucional', 'Otras instituciones educativas');

-- Editoriales
INSERT INTO L6_editoriales VALUES (1, 'Fondo Editorial PUCP', 'Per�', 'Multidisciplinario', 'Juan P�rez', 'jperez@pucp.edu.pe', '999888777');
INSERT INTO L6_editoriales VALUES (2, 'McGraw-Hill', 'Estados Unidos', 'Ingenier�a y Ciencias', 'Mar�a Garc�a', 'mgarcia@mcgraw.com', '998877665');
INSERT INTO L6_editoriales VALUES (3, 'Pearson', 'Reino Unido', 'Educaci�n Superior', 'Carlos L�pez', 'clopez@pearson.com', '997766554');
INSERT INTO L6_editoriales VALUES (4, 'Oxford University Press', 'Reino Unido', 'Humanidades', 'Ana Smith', 'asmith@oxford.com', '996655443');
INSERT INTO L6_editoriales VALUES (5, 'Cambridge University Press', 'Reino Unido', 'Acad�mico General', 'John Doe', 'jdoe@cambridge.com', '995544332');
INSERT INTO L6_editoriales VALUES (6, 'Springer', 'Alemania', 'Ciencias e Ingenier�a', 'Hans Mueller', 'hmueller@springer.com', '994433221');
INSERT INTO L6_editoriales VALUES (7, 'Planeta', 'Espa�a', 'Literatura General', 'Carmen Rivas', 'crivas@planeta.com', '993322110');
INSERT INTO L6_editoriales VALUES (8, 'Cengage Learning', 'Estados Unidos', 'Educaci�n Superior', 'Peter Smith', 'psmith@cengage.com', '992211009');
INSERT INTO L6_editoriales VALUES (9, 'Wiley', 'Estados Unidos', 'Ciencias y Tecnolog�a', 'Robert Johnson', 'rjohnson@wiley.com', '991100998');
INSERT INTO L6_editoriales VALUES (10, 'Santillana', 'Espa�a', 'Educaci�n General', 'Miguel S�nchez', 'msanchez@santillana.com', '990099887');
INSERT INTO L6_editoriales VALUES (11, 'Elsevier', 'Pa�ses Bajos', 'Ciencias y Medicina', 'Lisa Brown', 'lbrown@elsevier.com', '989988776');
INSERT INTO L6_editoriales VALUES (12, 'Thomson Reuters', 'Canad�', 'Derecho y Negocios', 'David Wilson', 'dwilson@thomson.com', '988877665');

-- Cursos
INSERT INTO L6_cursos VALUES (1, 'MAT101', 'C�lculo 1', 'Ciencias');
INSERT INTO L6_cursos VALUES (2, 'DER101', 'Introducci�n al Derecho', 'Derecho');
INSERT INTO L6_cursos VALUES (3, 'ING101', 'Programaci�n 1', 'Ingenier�a');
INSERT INTO L6_cursos VALUES (4, 'ECO101', 'Econom�a General', 'Econom�a');
INSERT INTO L6_cursos VALUES (5, 'HUM101', 'Filosof�a', 'Humanidades');
INSERT INTO L6_cursos VALUES (6, 'FIS101', 'F�sica 1', 'Ciencias');
INSERT INTO L6_cursos VALUES (7, 'QUI101', 'Qu�mica General', 'Ciencias');
INSERT INTO L6_cursos VALUES (8, 'COM101', 'Teor�a de la Comunicaci�n', 'Comunicaciones');
INSERT INTO L6_cursos VALUES (9, 'PSI101', 'Psicolog�a General', 'Psicolog�a');
INSERT INTO L6_cursos VALUES (10, 'ARQ101', 'Dise�o Arquitect�nico', 'Arquitectura');
INSERT INTO L6_cursos VALUES (11, 'ART101', 'Historia del Arte', 'Arte');
INSERT INTO L6_cursos VALUES (12, 'GES101', 'Gesti�n Empresarial', 'Gesti�n');
INSERT INTO L6_cursos VALUES (13, 'SOC101', 'Sociolog�a', 'Sociolog�a');
INSERT INTO L6_cursos VALUES (14, 'EDU101', 'Teor�as del Aprendizaje', 'Educaci�n');
INSERT INTO L6_cursos VALUES (15, 'LIN101', 'Ling��stica General', 'Ling��stica');

COMMIT;

-- Productos
INSERT INTO L6_productos VALUES (1, 'LIB001', 'C�lculo Diferencial', 'Libro fundamental de c�lculo para ciencias e ingenier�a', 1, 150.00, 50, 10, 20, 'ACTIVO', 2, 'EST-A1-01');
INSERT INTO L6_productos VALUES (2, 'LIB002', 'Derecho Civil', 'Manual completo de derecho civil', 1, 180.00, 0, 8, 15, 'DESCONTINUADO', 1, 'EST-A1-02');
INSERT INTO L6_productos VALUES (3, 'LIB003', 'Introducci�n a la Psicolog�a', 'Fundamentos de psicolog�a general', 1, 130.00, 45, 10, 18, 'ACTIVO', 3, 'EST-A1-03');
INSERT INTO L6_productos VALUES (4, 'REV001', 'Journal of Engineering Vol.1', 'Revista acad�mica de ingenier�a', 2, 45.00, 30, 5, 10, 'ACTIVO', 6, 'EST-B1-01');
INSERT INTO L6_productos VALUES (5, 'REV002', 'Economics Review', 'Revista especializada en econom�a', 2, 55.00, 25, 5, 12, 'ACTIVO', 4, 'EST-B1-02');
INSERT INTO L6_productos VALUES (6, 'LIB004', 'Qu�mica Org�nica', 'Texto completo de qu�mica org�nica', 1, 160.00, 35, 8, 15, 'ACTIVO', 2, 'EST-A1-04');
INSERT INTO L6_productos VALUES (7, 'MER001', 'Polo PUCP', 'Polo institucional con logo PUCP', 4, 35.00, 100, 20, 40, 'ACTIVO', NULL, 'EST-C1-01');
INSERT INTO L6_productos VALUES (8, 'MER002', 'Mochila PUCP', 'Mochila con logo institucional', 4, 65.00, 80, 15, 30, 'ACTIVO', NULL, 'EST-C1-02');
INSERT INTO L6_productos VALUES (9, 'LIB005', 'Marketing Digital', 'Estrategias modernas de marketing', 1, 140.00, 40, 8, 16, 'ACTIVO', 8, 'EST-A1-05');
INSERT INTO L6_productos VALUES (10, 'LIB006', 'Arquitectura Moderna', 'Historia y conceptos de arquitectura', 1, 170.00, 30, 6, 12, 'ACTIVO', 1, 'EST-A1-06');
INSERT INTO L6_productos VALUES (11, 'REV003', 'Humanidades Hoy', 'Revista de estudios human�sticos', 2, 40.00, 35, 7, 14, 'ACTIVO', 1, 'EST-B1-03');
INSERT INTO L6_productos VALUES (12, 'UTI001', 'Set de Geometr�a', 'Kit completo de instrumentos geom�tricos', 3, 25.00, 150, 30, 50, 'ACTIVO', NULL, 'EST-D1-01');
INSERT INTO L6_productos VALUES (13, 'LIB007', 'Gesti�n de Proyectos', 'Manual de gesti�n de proyectos', 1, 145.00, 40, 8, 16, 'ACTIVO', 3, 'EST-A1-07');
INSERT INTO L6_productos VALUES (14, 'REV004', 'Arte Contempor�neo', 'Revista especializada en arte', 2, 50.00, 30, 6, 12, 'ACTIVO', 7, 'EST-B1-04');
INSERT INTO L6_productos VALUES (15, 'MER003', 'Taza PUCP', 'Taza cer�mica con logo institucional', 4, 20.00, 0, 25, 45, 'DESCONTINUADO', NULL, 'EST-C1-03');

-- Libros (para productos tipo libro)
INSERT INTO L6_libros VALUES (1, 1, '9780123456789', 2024, 'Primera Edici�n', 'Espa�ol', 500, '21x27cm', 0.8, 'Tapa dura');
INSERT INTO L6_libros VALUES (2, 2, '9780987654321', 2023, 'Segunda Edici�n', 'Espa�ol', 400, '17x24cm', 0.6, 'Tapa blanda');
INSERT INTO L6_libros VALUES (3, 3, '9781234567890', 2024, 'Tercera Edici�n', 'Espa�ol', 350, '21x27cm', 0.7, 'Tapa dura');
INSERT INTO L6_libros VALUES (4, 6, '9789876543210', 2023, 'Primera Edici�n', 'Espa�ol', 450, '21x27cm', 0.9, 'Tapa dura');
INSERT INTO L6_libros VALUES (5, 9, '9782345678901', 2024, 'Segunda Edici�n', 'Espa�ol', 380, '17x24cm', 0.5, 'Tapa blanda');
INSERT INTO L6_libros VALUES (6, 10, '9788765432109', 2023, 'Primera Edici�n', 'Espa�ol', 420, '21x27cm', 0.8, 'Tapa dura');
INSERT INTO L6_libros VALUES (7, 13, '9783456789012', 2024, 'Primera Edici�n', 'Espa�ol', 300, '17x24cm', 0.4, 'Tapa blanda');

-- Revistas
INSERT INTO L6_revistas VALUES (1, 4, '12345678', 'Vol. 1', 'N�m. 1', '2024-1');
INSERT INTO L6_revistas VALUES (2, 5, '23456789', 'Vol. 15', 'N�m. 2', '2024-1');
INSERT INTO L6_revistas VALUES (3, 11, '34567890', 'Vol. 8', 'N�m. 1', '2024-1');
INSERT INTO L6_revistas VALUES (4, 14, '45678901', 'Vol. 5', 'N�m. 3', '2024-1');

-- Campa�as
INSERT INTO L6_campanias VALUES (1, 'Inicio de Ciclo 2024-1', 'Descuentos para inicio del ciclo acad�mico', TO_DATE('2024-03-01', 'YYYY-MM-DD'), TO_DATE('2024-03-15', 'YYYY-MM-DD'), 15.00);
INSERT INTO L6_campanias VALUES (2, 'Feria del Libro PUCP 2024', 'Feria anual del libro universitario', TO_DATE('2024-05-01', 'YYYY-MM-DD'), TO_DATE('2024-05-07', 'YYYY-MM-DD'), 20.00);
INSERT INTO L6_campanias VALUES (3, 'Semana de Ingenier�a', 'Descuentos especiales facultad de ingenier�a', TO_DATE('2024-06-15', 'YYYY-MM-DD'), TO_DATE('2024-06-21', 'YYYY-MM-DD'), 18.00);
INSERT INTO L6_campanias VALUES (4, 'Aniversario PUCP', 'Celebraci�n institucional', TO_DATE('2024-04-01', 'YYYY-MM-DD'), TO_DATE('2024-04-07', 'YYYY-MM-DD'), 25.00);
INSERT INTO L6_campanias VALUES (5, 'Black Friday PUCP', 'Ofertas especiales fin de a�o', TO_DATE('2024-11-29', 'YYYY-MM-DD'), TO_DATE('2024-12-01', 'YYYY-MM-DD'), 30.00);

-- Precios por Tipo de Cliente
INSERT INTO L6_precios_tipo_cliente VALUES (1, 1, 20.00); -- Estudiantes obtienen 20% en libros de c�lculo
INSERT INTO L6_precios_tipo_cliente VALUES (1, 2, 15.00); -- Docentes obtienen 15% en libros de c�lculo
INSERT INTO L6_precios_tipo_cliente VALUES (2, 1, 20.00); -- Estudiantes obtienen 20% en libros de derecho
INSERT INTO L6_precios_tipo_cliente VALUES (2, 2, 15.00); -- Docentes obtienen 15% en libros de derecho
INSERT INTO L6_precios_tipo_cliente VALUES (3, 1, 20.00); -- Estudiantes obtienen 20% en libros de psicolog�a
INSERT INTO L6_precios_tipo_cliente VALUES (3, 2, 15.00); -- Docentes obtienen 15% en libros de psicolog�a
INSERT INTO L6_precios_tipo_cliente VALUES (4, 1, 10.00); -- Estudiantes obtienen 10% en revistas
INSERT INTO L6_precios_tipo_cliente VALUES (4, 2, 10.00); -- Docentes obtienen 10% en revistas
INSERT INTO L6_precios_tipo_cliente VALUES (7, 1, 15.00); -- Estudiantes obtienen 15% en merchandising
INSERT INTO L6_precios_tipo_cliente VALUES (7, 2, 10.00); -- Docentes obtienen 10% en merchandising
INSERT INTO L6_precios_tipo_cliente VALUES (8, 1, 15.00); -- Estudiantes obtienen 15% en merchandising
INSERT INTO L6_precios_tipo_cliente VALUES (9, 1, 20.00); -- Estudiantes obtienen 20% en libros de marketing
INSERT INTO L6_precios_tipo_cliente VALUES (9, 2, 15.00); -- Docentes obtienen 15% en libros de marketing
INSERT INTO L6_precios_tipo_cliente VALUES (10, 1, 20.00); -- Estudiantes obtienen 20% en libros de arquitectura
INSERT INTO L6_precios_tipo_cliente VALUES (10, 2, 15.00); -- Docentes obtienen 15% en libros de arquitectura

COMMIT;

-- Productos-�reas (relaci�n entre productos y �reas tem�ticas)
INSERT INTO L6_productos_areas VALUES (1, 1);  -- C�lculo Diferencial - Ciencias
INSERT INTO L6_productos_areas VALUES (1, 3);  -- C�lculo Diferencial - Ingenier�a
INSERT INTO L6_productos_areas VALUES (2, 4);  -- Derecho Civil - Derecho
INSERT INTO L6_productos_areas VALUES (3, 7);  -- Introducci�n a la Psicolog�a - Psicolog�a
INSERT INTO L6_productos_areas VALUES (4, 3);  -- Journal of Engineering - Ingenier�a
INSERT INTO L6_productos_areas VALUES (5, 5);  -- Economics Review - Econom�a
INSERT INTO L6_productos_areas VALUES (6, 1);  -- Qu�mica Org�nica - Ciencias
INSERT INTO L6_productos_areas VALUES (9, 11); -- Marketing Digital - Gesti�n
INSERT INTO L6_productos_areas VALUES (10, 6); -- Arquitectura Moderna - Arquitectura
INSERT INTO L6_productos_areas VALUES (11, 2); -- Humanidades Hoy - Humanidades
INSERT INTO L6_productos_areas VALUES (13, 11); -- Gesti�n de Proyectos - Gesti�n
INSERT INTO L6_productos_areas VALUES (14, 8); -- Arte Contempor�neo - Arte
INSERT INTO L6_productos_areas VALUES (6, 3);  -- Qu�mica Org�nica tambi�n para Ingenier�a
INSERT INTO L6_productos_areas VALUES (9, 5);  -- Marketing Digital tambi�n para Econom�a
INSERT INTO L6_productos_areas VALUES (13, 5); -- Gesti�n de Proyectos tambi�n para Econom�a

-- Bibliograf�a de Cursos
INSERT INTO L6_bibliografia_cursos VALUES (1, 1, 'OBLIGATORIA');  -- MAT101 - C�lculo Diferencial
INSERT INTO L6_bibliografia_cursos VALUES (2, 2, 'OBLIGATORIA');  -- DER101 - Derecho Civil
INSERT INTO L6_bibliografia_cursos VALUES (3, 3, 'OBLIGATORIA');  -- ING101 - Introducci�n a la Psicolog�a
INSERT INTO L6_bibliografia_cursos VALUES (4, 4, 'COMPLEMENTARIA'); -- ECO101 - Qu�mica Org�nica
INSERT INTO L6_bibliografia_cursos VALUES (5, 5, 'OBLIGATORIA');  -- HUM101 - Marketing Digital
INSERT INTO L6_bibliografia_cursos VALUES (6, 6, 'OBLIGATORIA');  -- FIS101 - Arquitectura Moderna
INSERT INTO L6_bibliografia_cursos VALUES (7, 7, 'COMPLEMENTARIA'); -- QUI101 - Programaci�n en Python
INSERT INTO L6_bibliografia_cursos VALUES (8, 1, 'COMPLEMENTARIA'); -- COM101 - Tambi�n usa C�lculo
INSERT INTO L6_bibliografia_cursos VALUES (9, 2, 'COMPLEMENTARIA'); -- PSI101 - Tambi�n usa Derecho
INSERT INTO L6_bibliografia_cursos VALUES (10, 3, 'OBLIGATORIA');  -- ARQ101 - Tambi�n usa Psicolog�a
INSERT INTO L6_bibliografia_cursos VALUES (11, 4, 'OBLIGATORIA');  -- ART101 - Tambi�n usa Qu�mica
INSERT INTO L6_bibliografia_cursos VALUES (12, 5, 'COMPLEMENTARIA'); -- GES101 - Tambi�n usa Marketing
INSERT INTO L6_bibliografia_cursos VALUES (13, 6, 'COMPLEMENTARIA'); -- SOC101 - Tambi�n usa Arquitectura
INSERT INTO L6_bibliografia_cursos VALUES (14, 7, 'OBLIGATORIA');  -- EDU101 - Tambi�n usa Programaci�n
INSERT INTO L6_bibliografia_cursos VALUES (15, 1, 'OBLIGATORIA');  -- LIN101 - Tambi�n usa C�lculo

-- Clientes
INSERT INTO L6_clientes VALUES (1, 1, 'Ana', 'Torres', 'atorres@pucp.edu.pe', '999111222', '20240101');
INSERT INTO L6_clientes VALUES (2, 2, 'Jorge', 'Ram�rez', 'jramirez@pucp.edu.pe', '999222333', 'D0012345');
INSERT INTO L6_clientes VALUES (3, 3, 'Mar�a', 'L�pez', 'mlopez@pucp.edu.pe', '999333444', 'A0023456');
INSERT INTO L6_clientes VALUES (4, 4, 'Carlos', 'Garc�a', 'cgarcia@gmail.com', '999444555', NULL);
INSERT INTO L6_clientes VALUES (5, 1, 'Laura', 'Mendoza', 'lmendoza@pucp.edu.pe', '999555666', '20240102');
INSERT INTO L6_clientes VALUES (6, 2, 'Pedro', 'D�az', 'pdiaz@pucp.edu.pe', '999666777', 'D0034567');
INSERT INTO L6_clientes VALUES (7, 5, 'Rosa', 'Vargas', 'rvargas@gmail.com', '999777888', 'E0045678');
INSERT INTO L6_clientes VALUES (8, 1, 'Juan', 'Castro', 'jcastro@pucp.edu.pe', '999888999', '20240103');
INSERT INTO L6_clientes VALUES (9, 6, 'Luis', 'Flores', 'lflores@pucp.edu.pe', '999999000', 'I0056789');
INSERT INTO L6_clientes VALUES (10, 7, 'Carmen', 'Ruiz', 'cruiz@pucp.edu.pe', '999000111', 'B0067890');

-- �rdenes de Compra
INSERT INTO L6_ordenes_compra VALUES (1, 2, TO_DATE('2024-01-15', 'YYYY-MM-DD'), TO_DATE('2024-02-15', 'YYYY-MM-DD'), 'PROGRAMADA', 'APROBADA', 5000.00, 200.00, 'Reposici�n de stock para ciclo 2024-1');
INSERT INTO L6_ordenes_compra VALUES (2, 3, TO_DATE('2024-01-20', 'YYYY-MM-DD'), TO_DATE('2024-02-20', 'YYYY-MM-DD'), 'PROGRAMADA', 'EN_PROCESO', 6000.00, 250.00, 'Stock para feria del libro');
INSERT INTO L6_ordenes_compra VALUES (3, 1, TO_DATE('2024-01-25', 'YYYY-MM-DD'), TO_DATE('2024-01-30', 'YYYY-MM-DD'), 'EXTRAORDINARIA', 'APROBADA', 2000.00, 100.00, 'Pedido urgente facultad de letras');
INSERT INTO L6_ordenes_compra VALUES (4, 4, TO_DATE('2024-02-01', 'YYYY-MM-DD'), TO_DATE('2024-03-01', 'YYYY-MM-DD'), 'PROGRAMADA', 'PENDIENTE', 8000.00, 300.00, 'Stock regular primer semestre');
INSERT INTO L6_ordenes_compra VALUES (5, 6, TO_DATE('2024-02-05', 'YYYY-MM-DD'), TO_DATE('2024-02-15', 'YYYY-MM-DD'), 'EXTRAORDINARIA', 'APROBADA', 3000.00, 150.00, 'Pedido especial facultad de ingenier�a');

-- Detalle de �rdenes de Compra
INSERT INTO L6_ordenes_compra_detalle VALUES (1, 1, 30, 100.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (1, 2, 25, 90.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (1, 3, 20, 85.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (2, 4, 15, 35.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (2, 5, 20, 40.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (2, 6, 25, 95.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (3, 9, 15, 90.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (3, 10, 10, 100.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (4, 11, 30, 30.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (4, 13, 25, 95.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (5, 1, 20, 100.00);
INSERT INTO L6_ordenes_compra_detalle VALUES (5, 6, 15, 95.00);

COMMIT;

-- Ventas
INSERT INTO L6_ventas VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 300.00, 60.00, 240.00, 'TARJETA', 'AUT001', NULL);
INSERT INTO L6_ventas VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 450.00, 67.50, 382.50, 'EFECTIVO', NULL, NULL);
INSERT INTO L6_ventas VALUES (3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 800.00, 0.00, 800.00, 'TRANSFERENCIA', 'AUT002', 'CC-LETRAS-2024');
INSERT INTO L6_ventas VALUES (4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 150.00, 0.00, 150.00, 'EFECTIVO', NULL, NULL);
INSERT INTO L6_ventas VALUES (5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 250.00, 50.00, 200.00, 'TARJETA', 'AUT003', NULL);
INSERT INTO L6_ventas VALUES (6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 600.00, 90.00, 510.00, 'TRANSFERENCIA', 'AUT004', 'CC-ING-2024');
INSERT INTO L6_ventas VALUES (7, 7, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 180.00, 27.00, 153.00, 'TARJETA', 'AUT005', NULL);
INSERT INTO L6_ventas VALUES (8, 8, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 420.00, 84.00, 336.00, 'EFECTIVO', NULL, NULL);
INSERT INTO L6_ventas VALUES (9, 9, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 550.00, 82.50, 467.50, 'TARJETA', 'AUT006', NULL);
INSERT INTO L6_ventas VALUES (10, 10, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 900.00, 180.00, 720.00, 'TRANSFERENCIA', 'AUT007', 'CC-BIB-2024');

-- Ventas Detalle
INSERT INTO L6_ventas_detalle VALUES (1, 1, 2, 150.00, 30.00, 15.00, 105.00, 1);
INSERT INTO L6_ventas_detalle VALUES (1, 7, 1, 35.00, 5.25, 0.00, 29.75, NULL);
INSERT INTO L6_ventas_detalle VALUES (2, 2, 3, 180.00, 27.00, 18.00, 135.00, 1);
INSERT INTO L6_ventas_detalle VALUES (3, 3, 5, 130.00, 0.00, 0.00, 130.00, NULL);
INSERT INTO L6_ventas_detalle VALUES (3, 6, 2, 160.00, 0.00, 0.00, 160.00, NULL);
INSERT INTO L6_ventas_detalle VALUES (4, 4, 3, 45.00, 0.00, 0.00, 45.00, NULL);
INSERT INTO L6_ventas_detalle VALUES (5, 5, 2, 55.00, 11.00, 13.75, 30.25, 2);
INSERT INTO L6_ventas_detalle VALUES (5, 8, 2, 65.00, 13.00, 16.25, 35.75, 2);
INSERT INTO L6_ventas_detalle VALUES (6, 9, 3, 140.00, 21.00, 14.00, 105.00, 1);
INSERT INTO L6_ventas_detalle VALUES (6, 10, 2, 170.00, 25.50, 17.00, 127.50, 1);
INSERT INTO L6_ventas_detalle VALUES (7, 11, 3, 40.00, 6.00, 10.00, 24.00, 3);
INSERT INTO L6_ventas_detalle VALUES (8, 13, 2, 145.00, 29.00, 14.50, 101.50, 1);
INSERT INTO L6_ventas_detalle VALUES (8, 14, 2, 50.00, 10.00, 12.50, 27.50, 2);
INSERT INTO L6_ventas_detalle VALUES (9, 15, 5, 20.00, 3.00, 5.00, 12.00, 3);
INSERT INTO L6_ventas_detalle VALUES (10, 1, 6, 150.00, 30.00, 37.50, 82.50, 4);

-- Pedidos Especiales
INSERT INTO L6_pedidos_especiales VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), TO_DATE('2024-02-15', 'YYYY-MM-DD'), 'EN_PROCESO', 200.00, 'Libro importado no disponible en cat�logo');
INSERT INTO L6_pedidos_especiales VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), TO_DATE('2024-02-01', 'YYYY-MM-DD'), 'LISTO', 300.00, 'Pedido de libros para curso completo');
INSERT INTO L6_pedidos_especiales VALUES (3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), TO_DATE('2024-03-01', 'YYYY-MM-DD'), 'SOLICITADO', 150.00, 'Edici�n especial de libro de derecho');
INSERT INTO L6_pedidos_especiales VALUES (4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), TO_DATE('2024-02-20', 'YYYY-MM-DD'), 'EN_PROCESO', 250.00, 'Compra al por mayor para biblioteca personal');
INSERT INTO L6_pedidos_especiales VALUES (5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), TO_DATE('2024-02-10', 'YYYY-MM-DD'), 'LISTO', 180.00, 'Libro especializado de arquitectura');
INSERT INTO L6_pedidos_especiales VALUES (6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), TO_DATE('2024-03-15', 'YYYY-MM-DD'), 'SOLICITADO', 400.00, 'Colecci�n completa de revista cient�fica');
INSERT INTO L6_pedidos_especiales VALUES (7, 7, TO_DATE('2025-01-21', 'YYYY-MM-DD'), TO_DATE('2025-02-28', 'YYYY-MM-DD'), 'EN_PROCESO', 220.00, 'Libros de edici�n limitada');
INSERT INTO L6_pedidos_especiales VALUES (8, 8, TO_DATE('2025-01-22', 'YYYY-MM-DD'), TO_DATE('2025-02-25', 'YYYY-MM-DD'), 'LISTO', 280.00, 'Material complementario de curso');

-- P�rdidas de Inventario
INSERT INTO L6_perdidas_inventario VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Da�o por humedad en almac�n');
INSERT INTO L6_perdidas_inventario VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 2, 'PERDIDA', 'No encontrado en inventario f�sico');
INSERT INTO L6_perdidas_inventario VALUES (3, 4, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 3, 'AJUSTE', 'Diferencia en conteo de inventario');
INSERT INTO L6_perdidas_inventario VALUES (4, 6, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Da�o en manipulaci�n');
INSERT INTO L6_perdidas_inventario VALUES (5, 7, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 2, 'PERDIDA', 'Faltante en entrega');
INSERT INTO L6_perdidas_inventario VALUES (6, 8, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Producto da�ado en exhibici�n');
INSERT INTO L6_perdidas_inventario VALUES (7, 9, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 1, 'AJUSTE', 'Correcci�n de inventario');
INSERT INTO L6_perdidas_inventario VALUES (8, 11, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 2, 'PERDIDA', 'Extrav�o en traslado');
INSERT INTO L6_perdidas_inventario VALUES (9, 13, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Da�o en empaque');
INSERT INTO L6_perdidas_inventario VALUES (10, 15, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 3, 'AJUSTE', 'Actualizaci�n de inventario');
INSERT INTO L6_perdidas_inventario VALUES (11, 3, TO_DATE('2024-01-25', 'YYYY-MM-DD'), 2, 'DETERIORO', 'Da�o por ca�da en manipulaci�n');
INSERT INTO L6_perdidas_inventario VALUES (12, 5, TO_DATE('2024-01-26', 'YYYY-MM-DD'), 1, 'PERDIDA', 'No ubicado en inventario');
INSERT INTO L6_perdidas_inventario VALUES (13, 7, TO_DATE('2024-01-27', 'YYYY-MM-DD'), 3, 'AJUSTE', 'Correcci�n por conteo f�sico');
INSERT INTO L6_perdidas_inventario VALUES (14, 9, TO_DATE('2024-01-28', 'YYYY-MM-DD'), 1, 'DETERIORO', 'Da�o en almacenamiento');
INSERT INTO L6_perdidas_inventario VALUES (15, 11, TO_DATE('2024-01-29', 'YYYY-MM-DD'), 2, 'PERDIDA', 'P�rdida en tr�nsito');


-- Productos Condici�n
INSERT INTO L6_productos_condicion VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-01', 'Stock en perfectas condiciones');
INSERT INTO L6_productos_condicion VALUES (2, 2, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'REGULAR', 'EST-A1-02', 'Algunas portadas con desgaste menor');
INSERT INTO L6_productos_condicion VALUES (3, 3, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-03', 'Material nuevo sin da�os');
INSERT INTO L6_productos_condicion VALUES (4, 4, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-B1-01', 'Revistas en buen estado');
INSERT INTO L6_productos_condicion VALUES (5, 5, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'REGULAR', 'EST-B1-02', 'Algunas revistas con marcas de uso');
INSERT INTO L6_productos_condicion VALUES (6, 6, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-04', 'Libros nuevos en perfecto estado');
INSERT INTO L6_productos_condicion VALUES (7, 7, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-C1-01', 'Merchandising sin defectos');
INSERT INTO L6_productos_condicion VALUES (8, 8, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-C1-02', 'Productos en buen estado');
INSERT INTO L6_productos_condicion VALUES (9, 9, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'REGULAR', 'EST-A1-05', 'Algunos ejemplares con desgaste');
INSERT INTO L6_productos_condicion VALUES (10, 10, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-06', 'Libros en excelente estado');
INSERT INTO L6_productos_condicion VALUES (11, 11, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-B1-03', 'Revistas en excelente estado');
INSERT INTO L6_productos_condicion VALUES (12, 12, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'REGULAR', 'EST-D1-01', 'Algunos sets con empaques deteriorados');
INSERT INTO L6_productos_condicion VALUES (13, 13, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-A1-07', 'Stock reci�n recibido');
INSERT INTO L6_productos_condicion VALUES (14, 14, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-B1-04', 'Material en perfectas condiciones');
INSERT INTO L6_productos_condicion VALUES (15, 15, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'BUENO', 'EST-C1-03', 'Productos nuevos sin uso');


COMMIT;

-- Pedidos Especiales Detalle
INSERT INTO L6_pedidos_especiales_detalle VALUES (1, 1, 2, 160.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (1, 2, 1, 130.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (2, 3, 5, 140.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (2, 4, 3, 50.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (3, 5, 2, 60.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (3, 6, 1, 170.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (4, 7, 4, 40.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (4, 8, 2, 70.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (5, 9, 3, 150.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (6, 10, 2, 180.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (7, 11, 3, 45.00);
INSERT INTO L6_pedidos_especiales_detalle VALUES (8, 13, 2, 155.00);

-- Campa�as Productos
INSERT INTO L6_campanias_productos VALUES (1, 1, 15.00);  -- Inicio de Ciclo - C�lculo
INSERT INTO L6_campanias_productos VALUES (1, 2, 15.00);  -- Inicio de Ciclo - Derecho
INSERT INTO L6_campanias_productos VALUES (1, 3, 15.00);  -- Inicio de Ciclo - Psicolog�a
INSERT INTO L6_campanias_productos VALUES (2, 4, 20.00);  -- Feria del Libro - Revista Ingenier�a
INSERT INTO L6_campanias_productos VALUES (2, 5, 20.00);  -- Feria del Libro - Revista Econom�a
INSERT INTO L6_campanias_productos VALUES (2, 6, 20.00);  -- Feria del Libro - Qu�mica
INSERT INTO L6_campanias_productos VALUES (3, 7, 25.00);  -- Black Friday - Merchandising
INSERT INTO L6_campanias_productos VALUES (3, 8, 25.00);  -- Black Friday - Merchandising
INSERT INTO L6_campanias_productos VALUES (3, 9, 25.00);  -- Black Friday - Marketing
INSERT INTO L6_campanias_productos VALUES (4, 10, 18.00); -- Navidad - Arquitectura
INSERT INTO L6_campanias_productos VALUES (4, 11, 18.00); -- Navidad - Revista Humanidades
INSERT INTO L6_campanias_productos VALUES (5, 13, 22.00); -- Aniversario - Gesti�n
INSERT INTO L6_campanias_productos VALUES (5, 14, 22.00); -- Aniversario - Revista Arte
INSERT INTO L6_campanias_productos VALUES (5, 15, 22.00); -- Aniversario - Merchandising

-- Editoriales Hist�rico
INSERT INTO L6_editoriales_historico VALUES (1, 1, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 15, 95.5, 4.5, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (2, 2, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 20, 92.0, 4.2, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (3, 3, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 18, 93.5, 4.3, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (4, 4, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 22, 91.0, 4.0, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (5, 5, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 16, 94.5, 4.4, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (6, 6, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 21, 90.5, 4.1, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (7, 7, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 17, 93.0, 4.3, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (8, 8, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 19, 92.5, 4.2, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (9, 9, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 23, 89.5, 3.9, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (10, 10, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 14, 96.0, 4.6, '2023-2');
INSERT INTO L6_editoriales_historico VALUES (11, 1, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 16, 94.5, 4.4, '2024-0');
INSERT INTO L6_editoriales_historico VALUES (12, 2, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 21, 91.0, 4.1, '2024-0');
INSERT INTO L6_editoriales_historico VALUES (13, 3, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 19, 92.5, 4.2, '2024-0');
INSERT INTO L6_editoriales_historico VALUES (14, 4, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 23, 89.5, 3.9, '2024-0');
INSERT INTO L6_editoriales_historico VALUES (15, 5, TO_DATE('2024-01-01', 'YYYY-MM-DD'), 17, 93.0, 4.3, '2024-0');

-- Encuestas
INSERT INTO L6_encuestas VALUES (1, 1, 1, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 4.5, 4.0, 'Excelente servicio, entrega r�pida');
INSERT INTO L6_encuestas VALUES (2, 2, 2, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 4.0, 4.5, 'Buenos precios, amplio cat�logo');
INSERT INTO L6_encuestas VALUES (3, 3, 3, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 3.5, 4.0, 'Servicio regular, mejorar tiempos de atenci�n');
INSERT INTO L6_encuestas VALUES (4, 4, 4, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 5.0, 4.5, 'Muy satisfecho con la atenci�n');
INSERT INTO L6_encuestas VALUES (5, 5, 5, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 4.0, 3.5, 'Productos buenos, mejorar stock');
INSERT INTO L6_encuestas VALUES (6, 6, 6, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 4.5, 4.0, 'Excelente variedad de libros');
INSERT INTO L6_encuestas VALUES (7, 7, 7, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 3.0, 3.5, 'Precios algo elevados');
INSERT INTO L6_encuestas VALUES (8, 8, 8, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 4.5, 5.0, 'Muy satisfecho con todo el servicio');
INSERT INTO L6_encuestas VALUES (9, 9, 9, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 4.0, 4.0, 'Buena experiencia de compra');
INSERT INTO L6_encuestas VALUES (10, 10, 10, TO_DATE('2024-01-25', 'YYYY-MM-DD'), 5.0, 4.5, 'Excelente atenci�n del personal');

-- Sugerencias
INSERT INTO L6_sugerencias VALUES (1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'PRODUCTO', 'Incluir m�s libros de matem�ticas avanzadas', 'REGISTRADA');
INSERT INTO L6_sugerencias VALUES (2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'SERVICIO', 'Ampliar horario de atenci�n', 'EN_REVISION');
INSERT INTO L6_sugerencias VALUES (3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 'INFRAESTRUCTURA', 'Mejorar iluminaci�n en estantes', 'IMPLEMENTADA');
INSERT INTO L6_sugerencias VALUES (4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 'PRODUCTO', 'Traer m�s t�tulos en ingl�s', 'REGISTRADA');
INSERT INTO L6_sugerencias VALUES (5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 'SERVICIO', 'Implementar sistema de reservas online', 'EN_REVISION');
INSERT INTO L6_sugerencias VALUES (6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 'PRODUCTO', 'Aumentar variedad de �tiles', 'IMPLEMENTADA');
INSERT INTO L6_sugerencias VALUES (7, 7, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 'INFRAESTRUCTURA', 'M�s espacios de lectura', 'EN_REVISION');
INSERT INTO L6_sugerencias VALUES (8, 8, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 'SERVICIO', 'Ofrecer servicio de empaque de regalo', 'REGISTRADA');
INSERT INTO L6_sugerencias VALUES (9, 9, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 'PRODUCTO', 'Incluir m�s merchandising PUCP', 'IMPLEMENTADA');
INSERT INTO L6_sugerencias VALUES (10, 10, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 'SERVICIO', 'Implementar sistema de notificaciones', 'EN_REVISION');

-- Incidencias
INSERT INTO L6_incidencias VALUES (1, 1, 1, 1, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Libro con p�ginas da�adas', 'EN_PROCESO', 'Se est� gestionando el reemplazo con editorial');
INSERT INTO L6_incidencias VALUES (2, 2, 2, 2, TO_DATE('2024-01-16', 'YYYY-MM-DD'), 'ERROR_ENTREGA', 'Entrega de edici�n incorrecta', 'RESUELTA', 'Se realiz� el cambio por la edici�n correcta');
INSERT INTO L6_incidencias VALUES (3, 3, 3, 3, TO_DATE('2024-01-17', 'YYYY-MM-DD'), 'RETRASO_ENTREGA', 'Demora en entrega de pedido', 'CERRADA', 'Se compens� al cliente con descuento adicional');
INSERT INTO L6_incidencias VALUES (4, 4, 4, 4, TO_DATE('2024-01-18', 'YYYY-MM-DD'), 'PRODUCTO_INCOMPLETO', 'Falta CD complementario', 'EN_PROCESO', 'Solicitando material faltante a editorial');
INSERT INTO L6_incidencias VALUES (5, 5, 5, 5, TO_DATE('2024-01-19', 'YYYY-MM-DD'), 'COBRO_INCORRECTO', 'Error en aplicaci�n de descuento', 'RESUELTA', 'Se realiz� el reembolso de la diferencia');
INSERT INTO L6_incidencias VALUES (6, 6, 6, 6, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Problemas con el empaste', 'REGISTRADA', 'Pendiente de revisi�n por el proveedor');
INSERT INTO L6_incidencias VALUES (7, 7, 7, 7, TO_DATE('2024-01-21', 'YYYY-MM-DD'), 'ERROR_SISTEMA', 'Problema con facturaci�n', 'RESUELTA', 'Se corrigi� el documento de venta');
INSERT INTO L6_incidencias VALUES (8, 8, 8, 8, TO_DATE('2024-01-22', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Merchandising con falla', 'EN_PROCESO', 'En espera de reposici�n');
INSERT INTO L6_incidencias VALUES (9, 9, 9, 9, TO_DATE('2024-01-23', 'YYYY-MM-DD'), 'RETRASO_ENTREGA', 'Demora en pedido especial', 'REGISTRADA', 'En seguimiento con proveedor');
INSERT INTO L6_incidencias VALUES (10, 10, 10, 10, TO_DATE('2024-01-24', 'YYYY-MM-DD'), 'ERROR_ENTREGA', 'Entrega en ubicaci�n incorrecta', 'RESUELTA', 'Se coordin� nueva entrega en ubicaci�n correcta');
INSERT INTO L6_incidencias VALUES (11, 1, 1, 11, TO_DATE('2024-01-25', 'YYYY-MM-DD'), 'PRODUCTO_INCOMPLETO', 'Falta material complementario', 'EN_PROCESO', 'Contactando con editorial');
INSERT INTO L6_incidencias VALUES (12, 2, 2, 12, TO_DATE('2024-01-26', 'YYYY-MM-DD'), 'COBRO_INCORRECTO', 'No se aplic� descuento institucional', 'RESUELTA', 'Se aplic� nota de cr�dito');
INSERT INTO L6_incidencias VALUES (13, 3, 3, 13, TO_DATE('2024-01-27', 'YYYY-MM-DD'), 'ERROR_SISTEMA', 'Problema con orden de compra', 'CERRADA', 'Se corrigi� registro en sistema');
INSERT INTO L6_incidencias VALUES (14, 4, 4, 14, TO_DATE('2024-01-28', 'YYYY-MM-DD'), 'PRODUCTO_DEFECTUOSO', 'Revista con impresi�n defectuosa', 'REGISTRADA', 'Pendiente evaluaci�n');
INSERT INTO L6_incidencias VALUES (15, 5, 5, 15, TO_DATE('2024-01-29', 'YYYY-MM-DD'), 'RETRASO_ENTREGA', 'Demora en entrega institucional', 'EN_PROCESO', 'Coordinando con log�stica');

COMMIT;


INSERT INTO L6_CAMPANIAS VALUES (6, 'San Valent�n - Enam�rate entre p�ginas', 'Campa�a especial por el d�a del amor y la amistad', TO_DATE('2024-02-01', 'YYYY-MM-DD'), TO_DATE('2024-02-14', 'YYYY-MM-DD'), 20.00);
INSERT INTO L6_PRODUCTOS VALUES (16, 'LIB008', 'Amor entre p�ginas', 'Novela rom�ntica bestseller', 5, 120.00, 30, 5, 10, 'ACTIVO', 7, 'EST-A2-01');
INSERT INTO L6_PRODUCTOS VALUES (17, 'LIB009', 'Est�reo', 'Novela juvenil rom�ntica', 5, 89.90, 25, 5, 10, 'ACTIVO', 7, 'EST-A2-02');

INSERT INTO L6_CAMPANIAS_PRODUCTOS VALUES (6, 16, 20.00);
INSERT INTO L6_CAMPANIAS_PRODUCTOS VALUES (6, 17, 20.00);

INSERT INTO L6_VENTAS VALUES (11, 5, TO_DATE('2024-02-13', 'YYYY-MM-DD'), 209.90, 41.98, 167.92, 'TARJETA', 'AUT008', NULL);

INSERT INTO L6_VENTAS_DETALLE VALUES (11, 16, 1, 120.00, 0, 24.00, 96.00, 6);
INSERT INTO L6_VENTAS_DETALLE VALUES (11, 17, 1, 89.90, 0, 17.98, 71.92, 6);

INSERT INTO L6_PRODUCTOS VALUES (18, 'LIB010', '7 H�bitos de la Gente Altamente Efectiva', 'Bestseller de desarrollo personal', 5, 89.90, 40, 10, 15, 'ACTIVO', 7, 'EST-A2-03');
INSERT INTO L6_PRODUCTOS VALUES (19, 'LIB011', 'Por Qu� Fracasan los Pa�ses', 'An�lisis econ�mico y pol�tico', 5, 99.90, 35, 8, 12, 'ACTIVO', 7, 'EST-A2-04');
INSERT INTO L6_PRODUCTOS VALUES (20, 'LIB012', 'Cuentos de Carbox', 'Libro infantil ilustrado', 5, 45.00, 30, 5, 10, 'ACTIVO', 1, 'EST-A2-05');
INSERT INTO L6_PRODUCTOS VALUES (21, 'LIB013', 'Cl�sicos Rom�nticos', 'Antolog�a de literatura rom�ntica', 5, 75.00, 25, 5, 10, 'ACTIVO', 4, 'EST-A2-06');
INSERT INTO L6_PRODUCTOS VALUES (22, 'MER004', 'Peluche Quilla PUCP', 'Peluche oficial mascota PUCP', 4, 59.90, 100, 20, 30, 'ACTIVO', NULL, 'EST-C1-04');
INSERT INTO L6_PRODUCTOS VALUES (23, 'MER005', 'Rompecabezas PUCP', 'Puzzle dise�o campus', 4, 29.90, 50, 10, 20, 'ACTIVO', NULL, 'EST-C1-05');
INSERT INTO L6_PRODUCTOS VALUES (24, 'MER006', 'Polo San Valent�n PUCP', 'Edici�n especial San Valent�n', 4, 45.00, 80, 15, 25, 'ACTIVO', NULL, 'EST-C1-06');
INSERT INTO L6_CAMPANIAS VALUES (7, 'Fondo Planeta 20% Descuento', 'Descuentos especiales en libros Planeta', TO_DATE('2024-02-07', 'YYYY-MM-DD'), TO_DATE('2024-02-16', 'YYYY-MM-DD'), 20.00);
INSERT INTO L6_CAMPANIAS VALUES (8, 'Merch San Valent�n', 'Descuentos especiales en merchandising', TO_DATE('2024-02-01', 'YYYY-MM-DD'), TO_DATE('2024-02-14', 'YYYY-MM-DD'), 35.00);

INSERT INTO L6_CAMPANIAS_PRODUCTOS VALUES (7, 18, 20.00);
INSERT INTO L6_CAMPANIAS_PRODUCTOS VALUES (7, 19, 20.00);
INSERT INTO L6_CAMPANIAS_PRODUCTOS VALUES (8, 22, 35.00);
INSERT INTO L6_CAMPANIAS_PRODUCTOS VALUES (8, 23, 35.00);
INSERT INTO L6_CAMPANIAS_PRODUCTOS VALUES (8, 24, 35.00);

INSERT INTO L6_VENTAS VALUES (12, 1, TO_DATE('2024-02-08', 'YYYY-MM-DD'), 189.80, 37.96, 151.84, 'TARJETA', 'AUT009', NULL);
INSERT INTO L6_VENTAS VALUES (13, 3, TO_DATE('2024-02-09', 'YYYY-MM-DD'), 99.90, 19.98, 79.92, 'EFECTIVO', NULL, NULL);
INSERT INTO L6_VENTAS VALUES (14, 5, TO_DATE('2024-02-13', 'YYYY-MM-DD'), 134.90, 47.22, 87.68, 'TARJETA', 'AUT010', NULL);
INSERT INTO L6_VENTAS VALUES (15, 8, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 104.90, 36.72, 68.18, 'EFECTIVO', NULL, NULL);

INSERT INTO L6_VENTAS_DETALLE VALUES (12, 18, 1, 89.90, 0, 17.98, 71.92, 7);
INSERT INTO L6_VENTAS_DETALLE VALUES (12, 19, 1, 99.90, 0, 19.98, 79.92, 7);
INSERT INTO L6_VENTAS_DETALLE VALUES (13, 19, 1, 99.90, 0, 19.98, 79.92, 7);
INSERT INTO L6_VENTAS_DETALLE VALUES (14, 22, 1, 59.90, 0, 20.97, 38.93, 8);
INSERT INTO L6_VENTAS_DETALLE VALUES (14, 23, 1, 29.90, 0, 10.47, 19.43, 8);
INSERT INTO L6_VENTAS_DETALLE VALUES (15, 23, 1, 29.90, 0, 10.47, 19.43, 8);
INSERT INTO L6_VENTAS_DETALLE VALUES (15, 24, 1, 45.00, 0, 15.75, 29.25, 8);

INSERT INTO L6_PEDIDOS_ESPECIALES VALUES (9, 2, TO_DATE('2024-02-10', 'YYYY-MM-DD'), TO_DATE('2024-02-14', 'YYYY-MM-DD'), 'ENTREGADO', 50.00, 'Pedido especial San Valent�n - Pack rom�ntico');
INSERT INTO L6_PEDIDOS_ESPECIALES VALUES (10, 4, TO_DATE('2024-02-11', 'YYYY-MM-DD'), TO_DATE('2024-02-14', 'YYYY-MM-DD'), 'ENTREGADO', 40.00, 'Pedido especial San Valent�n - Merchandising personalizado');

INSERT INTO L6_PEDIDOS_ESPECIALES_DETALLE VALUES (9, 21, 1, 75.00);
INSERT INTO L6_PEDIDOS_ESPECIALES_DETALLE VALUES (9, 22, 1, 59.90);
INSERT INTO L6_PEDIDOS_ESPECIALES_DETALLE VALUES (10, 24, 2, 45.00);

INSERT INTO L6_ENCUESTAS VALUES (11, 5, 14, TO_DATE('2024-02-13', 'YYYY-MM-DD'), 5.0, 4.8, 'Excelente servicio y productos de San Valent�n');
INSERT INTO L6_ENCUESTAS VALUES (12, 8, 15, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 4.7, 4.5, 'Muy buenos descuentos en merchandising');

COMMIT;


-- Primero agregamos m�s clientes de diferentes tipos
INSERT INTO L6_clientes VALUES (11, 4, 'Roberto', 'Miranda', 'rmiranda@gmail.com', '999123456', NULL);
INSERT INTO L6_clientes VALUES (12, 4, 'Diana', 'Castro', 'dcastro@gmail.com', '999234567', NULL);
INSERT INTO L6_clientes VALUES (13, 1, 'Jimena', 'S�nchez', 'jsanchez@pucp.edu.pe', '999345678', '20240104');
INSERT INTO L6_clientes VALUES (14, 1, 'Miguel', 'R�os', 'mrios@pucp.edu.pe', '999456789', '20240105');

-- Agregamos m�s ventas para la campa�a de San Valent�n
INSERT INTO L6_ventas VALUES (16, 11, TO_DATE('2024-02-13', 'YYYY-MM-DD'), 209.90, 41.98, 167.92, 'TARJETA', 'AUT011', NULL);
INSERT INTO L6_ventas VALUES (17, 12, TO_DATE('2024-02-13', 'YYYY-MM-DD'), 209.90, 41.98, 167.92, 'EFECTIVO', NULL, NULL);
INSERT INTO L6_ventas VALUES (18, 13, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 209.90, 41.98, 167.92, 'TARJETA', 'AUT012', NULL);
INSERT INTO L6_ventas VALUES (19, 14, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 209.90, 41.98, 167.92, 'EFECTIVO', NULL, NULL);

-- Agregamos el detalle de las ventas asoci�ndolas a la campa�a de San Valent�n
INSERT INTO L6_ventas_detalle VALUES (16, 16, 1, 120.00, 0, 24.00, 96.00, 6);
INSERT INTO L6_ventas_detalle VALUES (16, 17, 1, 89.90, 0, 17.98, 71.92, 6);
INSERT INTO L6_ventas_detalle VALUES (17, 16, 1, 120.00, 0, 24.00, 96.00, 6);
INSERT INTO L6_ventas_detalle VALUES (17, 17, 1, 89.90, 0, 17.98, 71.92, 6);
INSERT INTO L6_ventas_detalle VALUES (18, 16, 1, 120.00, 0, 24.00, 96.00, 6);
INSERT INTO L6_ventas_detalle VALUES (18, 17, 1, 89.90, 0, 17.98, 71.92, 6);
INSERT INTO L6_ventas_detalle VALUES (19, 16, 1, 120.00, 0, 24.00, 96.00, 6);
INSERT INTO L6_ventas_detalle VALUES (19, 17, 1, 89.90, 0, 17.98, 71.92, 6);

COMMIT;

-- Agregamos m�s clientes egresados PUCP
INSERT INTO L6_clientes VALUES (15, 5, 'Patricia', 'Wong', 'pwong@gmail.com', '999567890', 'E0045679');
INSERT INTO L6_clientes VALUES (16, 5, 'Fernando', 'Diaz', 'fdiaz@gmail.com', '999678901', 'E0045680');

-- Agregamos las ventas para los egresados
INSERT INTO L6_ventas VALUES (20, 15, TO_DATE('2024-02-13', 'YYYY-MM-DD'), 209.90, 41.98, 167.92, 'TARJETA', 'AUT013', NULL);
INSERT INTO L6_ventas VALUES (21, 16, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 209.90, 41.98, 167.92, 'TARJETA', 'AUT014', NULL);

-- Agregamos el detalle de las ventas asoci�ndolas a la campa�a de San Valent�n
INSERT INTO L6_ventas_detalle VALUES (20, 16, 1, 120.00, 0, 24.00, 96.00, 6);
INSERT INTO L6_ventas_detalle VALUES (20, 17, 1, 89.90, 0, 17.98, 71.92, 6);
INSERT INTO L6_ventas_detalle VALUES (21, 16, 1, 120.00, 0, 24.00, 96.00, 6);
INSERT INTO L6_ventas_detalle VALUES (21, 17, 1, 89.90, 0, 17.98, 71.92, 6);

COMMIT;

-- Agregamos m�s ventas para los clientes de P�blico General con montos diferentes
INSERT INTO L6_ventas VALUES (22, 11, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 309.90, 61.98, 247.92, 'TARJETA', 'AUT015', NULL);
INSERT INTO L6_ventas VALUES (23, 12, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 309.90, 61.98, 247.92, 'EFECTIVO', NULL, NULL);

-- Detalle de ventas para P�blico General con m�s productos
INSERT INTO L6_ventas_detalle VALUES (22, 16, 2, 120.00, 0, 48.00, 192.00, 6);
INSERT INTO L6_ventas_detalle VALUES (22, 17, 1, 89.90, 0, 17.98, 71.92, 6);
INSERT INTO L6_ventas_detalle VALUES (23, 16, 2, 120.00, 0, 48.00, 192.00, 6);
INSERT INTO L6_ventas_detalle VALUES (23, 17, 1, 89.90, 0, 17.98, 71.92, 6);

-- Agregamos m�s productos de mayor valor a la campa�a
INSERT INTO L6_productos VALUES (25, 'LIB014', 'Box Set Rom�ntico', 'Colecci�n especial San Valent�n', 5, 299.90, 20, 5, 10, 'ACTIVO', 7, 'EST-A2-07');
INSERT INTO L6_campanias_productos VALUES (6, 25, 20.00);

-- Agregamos ventas de productos de mayor valor para Egresado PUCP
INSERT INTO L6_ventas VALUES (24, 15, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 399.90, 79.98, 319.92, 'TARJETA', 'AUT016', NULL);
INSERT INTO L6_ventas VALUES (25, 16, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 399.90, 79.98, 319.92, 'TARJETA', 'AUT017', NULL);

-- Detalle de ventas para Egresado PUCP incluyendo productos de mayor valor
INSERT INTO L6_ventas_detalle VALUES (24, 25, 1, 299.90, 0, 59.98, 239.92, 6);
INSERT INTO L6_ventas_detalle VALUES (24, 17, 1, 89.90, 0, 17.98, 71.92, 6);
INSERT INTO L6_ventas_detalle VALUES (25, 25, 1, 299.90, 0, 59.98, 239.92, 6);
INSERT INTO L6_ventas_detalle VALUES (25, 17, 1, 89.90, 0, 17.98, 71.92, 6);

COMMIT;

-- Agregamos un docente PUCP
INSERT INTO L6_clientes VALUES (17, 2, 'Marco', 'Gonzales', 'mgonzales@pucp.edu.pe', '999789012', 'D0034568');

-- Agregamos venta para el docente
INSERT INTO L6_ventas VALUES (26, 17, TO_DATE('2024-02-14', 'YYYY-MM-DD'), 399.90, 79.98, 319.92, 'TARJETA', 'AUT018', NULL);

-- Detalle de venta para el docente incluyendo productos de la campa�a San Valent�n
INSERT INTO L6_ventas_detalle VALUES (26, 25, 1, 299.90, 0, 59.98, 239.92, 6);
INSERT INTO L6_ventas_detalle VALUES (26, 17, 1, 89.90, 0, 17.98, 71.92, 6);

COMMIT;

-- Primero, vamos a agregar algunas ventas nuevas
INSERT INTO L6_VENTAS VALUES (27, 1, TO_DATE('2024-01-05', 'YYYY-MM-DD'), 135.00, 0, 135.00, 'EFECTIVO', NULL, NULL);
INSERT INTO L6_VENTAS VALUES (28, 3, TO_DATE('2024-01-10', 'YYYY-MM-DD'), 195.00, 0, 195.00, 'TARJETA', 'AUT019', NULL);
INSERT INTO L6_VENTAS VALUES (29, 5, TO_DATE('2024-01-15', 'YYYY-MM-DD'), 85.00, 0, 85.00, 'EFECTIVO', NULL, NULL);
INSERT INTO L6_VENTAS VALUES (30, 7, TO_DATE('2024-01-20', 'YYYY-MM-DD'), 245.00, 0, 245.00, 'TARJETA', 'AUT020', NULL);

-- Ahora agregamos el detalle de las ventas usando productos de merchandising existentes
-- Usando productos: 7 (Polo PUCP), 8 (Mochila PUCP), 22 (Peluche Quilla PUCP), 23 (Rompecabezas PUCP)
INSERT INTO L6_VENTAS_DETALLE VALUES (27, 7, 2, 35.00, 0, 0, 35.00, NULL);  -- 2 Polos PUCP
INSERT INTO L6_VENTAS_DETALLE VALUES (27, 23, 2, 29.90, 0, 0, 29.90, NULL); -- 2 Rompecabezas

INSERT INTO L6_VENTAS_DETALLE VALUES (28, 8, 3, 65.00, 0, 0, 65.00, NULL);  -- 3 Mochilas PUCP

INSERT INTO L6_VENTAS_DETALLE VALUES (29, 22, 1, 59.90, 0, 0, 59.90, NULL); -- 1 Peluche Quilla
INSERT INTO L6_VENTAS_DETALLE VALUES (29, 23, 1, 29.90, 0, 0, 29.90, NULL); -- 1 Rompecabezas

INSERT INTO L6_VENTAS_DETALLE VALUES (30, 7, 3, 35.00, 0, 0, 35.00, NULL);  -- 3 Polos PUCP
INSERT INTO L6_VENTAS_DETALLE VALUES (30, 8, 2, 65.00, 0, 0, 65.00, NULL);  -- 2 Mochilas PUCP

COMMIT;