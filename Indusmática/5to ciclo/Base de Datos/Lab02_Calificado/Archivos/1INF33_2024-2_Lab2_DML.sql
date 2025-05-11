INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(1,'CREACIONES BASICAS', NULL, '3456789', 'creacion@gmail.com', 'Av. Puruchuco 345');
INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(2,'Rosa Varga', NULL, '2347890', 'rvargas@gmail.com', 'Pasaje Chorrillos 789');
INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(3,'Irvin Gonzales', '10453874350', '976613423', 'irving@gmail.com', '');
INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(4,'Universidad del Centro', '209045678', '2135678', 'coordinacion@univcentro.edu.pe', 'Av. Canto Grande 289');
INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(5,'Muebleria La Unica', '21904536', '999345671', 'launica@muebleria.com.pe', 'Calle Las Rosas 4567');
INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(6,'Panaderia Rosita', NULL, '4557890', 'informes@panaderiarosita.com.pe', 'Av Bolivar 876');
INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(7,'Interprovincial Lima', NULL, '34589560', 'gestion@pinterprovincial.com.pe', 'Av Tomas Valle 145');
INSERT INTO CLIENTE (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(8,'Inversiones Group Lima', NULL, '356789023', 'consultas_group@inversiones.com', 'Calle Rosendo 457');

INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion) values(1,'Almacen central', 'Villa El Salvador', 'Lima', 200, 'Av. Grande 231 Mz. C. Lote 1');
INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion,telefono) values(2,'Almacen Sur', 'Lurin', 'Lima', 1000, 'Av. Piura 1050 Mz. D.','2345678' );
INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion,telefono) values(3,'Almacen Sur II', 'Villa El Salvador', 'Lima', 500, 'Av. Piura 5690 Mz. A.','980457879' );
INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion,telefono) values(4,'Almacen Cono Norte', 'Comas', 'Lima', 1500, 'Av. Pasamayo 456','2345667' );
INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion,telefono) values(5,'Almacen Norte', 'San Martin de Porres', 'Lima', 400, 'Calle Tarazona 101','967456382' );
INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion,telefono) values(6,'Almacen Chico', 'Villa El Salvador', 'Lima', 450, 'Calle C 346 Mz. B. Lote 3','2179463' );
INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion,telefono) values(7,'Deposito Emergencia', 'Villa El Salvador', 'Lima', 350, 'Av. Pasco 480','909346712' );
INSERT INTO SEDE (id_sede, nombre_sede,distrito,provincia, area_sede, direccion,telefono) values(8,'Almacen Centro II', 'La Molina', 'Lima', 350, 'Av. La Molina 270','4563890' );

INSERT INTO FORMA_PAGO (id_forma_pago, nombre_forma_pago,moneda) values (1, 'tarjeta debito', 'S');
INSERT INTO FORMA_PAGO (id_forma_pago, nombre_forma_pago,moneda) values (2, 'tarjeta credito', 'S');
INSERT INTO FORMA_PAGO (id_forma_pago, nombre_forma_pago,moneda) values (3, 'efectivo', 'S');
INSERT INTO FORMA_PAGO (id_forma_pago, nombre_forma_pago,moneda) values (4, 'efectivo', 'D');
INSERT INTO FORMA_PAGO (id_forma_pago, nombre_forma_pago,moneda) values (5, 'transferencia', 'S');

INSERT INTO TIPO_BUS (id_tipo_bus, nombre) values(1, 'Bus de transporte publico');
INSERT INTO TIPO_BUS (id_tipo_bus, nombre) values(2, 'Bus para transporte de personal');
INSERT INTO TIPO_BUS (id_tipo_bus, nombre) values(3, 'Bus de transporte interprovincial');
INSERT INTO TIPO_BUS (id_tipo_bus, nombre) values(4, 'Bus para el sector turismo');

INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(1,to_date('10/01/2024','dd/mm/yyyy'),to_date('30/01/2024', 'dd/mm/yyyy'),4,3,3 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(2,to_date('18/03/2024','dd/mm/yyyy'),to_date('01/04/2024', 'dd/mm/yyyy'),4,5,3 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(3,to_date('08/02/2024','dd/mm/yyyy'),to_date('24/02/2024', 'dd/mm/yyyy'),5,2,2 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(4,to_date('23/04/2024','dd/mm/yyyy'),to_date('05/05/2024', 'dd/mm/yyyy'),5,5,2 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(5,to_date('25/04/2024','dd/mm/yyyy'),to_date('09/06/2024', 'dd/mm/yyyy'),2,1,5 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(6,to_date('18/03/2024','dd/mm/yyyy'),to_date('01/04/2024', 'dd/mm/yyyy'),3,8,5 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(7,to_date('09/02/2024','dd/mm/yyyy'),to_date('09/03/2024', 'dd/mm/yyyy'),1,1,4 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(8,to_date('10/02/2024','dd/mm/yyyy'),to_date('01/03/2024', 'dd/mm/yyyy'),6,1,5 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(9,to_date('01/03/2024','dd/mm/yyyy'),to_date('25/03/2024', 'dd/mm/yyyy'),6,8,1 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(10,to_date('04/04/2024','dd/mm/yyyy'),to_date('05/05/2024', 'dd/mm/yyyy'),6,2,2 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(11,to_date('03/08/2024','dd/mm/yyyy'),to_date('20/08/2024', 'dd/mm/yyyy'),6,1,3 );
INSERT INTO ORDEN_PEDIDO (id_orden_pedido, fecha_registro, fecha_entrega, id_cliente, id_sede, id_forma_pago) values(12,to_date('13/09/2024','dd/mm/yyyy'),to_date('10/10/2024', 'dd/mm/yyyy'),4,1,1 );



INSERT INTO ROL(id_rol, descripcion, es_jefe, activo) VALUES(1, 'Administrador', 'S', 'S');
INSERT INTO ROL(id_rol, descripcion, es_jefe, activo) VALUES(2, 'Almacenero', 'N', 'S');
INSERT INTO ROL(id_rol, descripcion, es_jefe, activo) VALUES(3, 'Vendedor', 'N', 'S');
INSERT INTO ROL(id_rol, descripcion, es_jefe, activo) VALUES(4, 'Jefe de Almacen', 'S', 'S');
INSERT INTO ROL(id_rol, descripcion, es_jefe, activo) VALUES(5, 'Jefe de produccion', 'S', 'S');
INSERT INTO ROL(id_rol, descripcion, es_jefe, activo) VALUES(6, 'Supervisor de produccion', 'S', 'S');


INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (1,'CobS','Ballard','Salazar','N','01-02-25',4);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (2,'Kennan','Harrell','Huff','N','16-04-27',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (3,'Akeem','Munoz','Farmer','S','26-05-28',2);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (4,'Victor','Munoz','Carter','S','16-10-27',2);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (5,'Sophia','RSan','Nieves','N','24-02-27',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (6,'Fitzgerald','Mcintosh','Tran','S','21-03-26',2);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (7,'RosalSn','BentleS','Shannon','N','10-07-26',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (8,'Jaden','Graves','Schneider','N','23-10-30',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (9,'KSlSnn','Bruce','Castillo','N','17-05-28',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (10,'Cameron','Lucas','Hurst','N','14-11-24',2);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (11,'John','Pugh','Villarreal','N','07-11-29',5);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (12,'Robin','MccraS','Beach','N','15-01-25',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (13,'DaceS','Bowers','Dickson','N','26-03-28',2);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (14,'Hadassah','Glenn','Prince','S','17-04-30',4);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (15,'Ori','Ferrell','Fields','S','28-05-25',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (16,'Fletcher','Joseph','Robinson','N','11-12-28',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (17,'Malachi','Roberson','Baldwin','S','06-11-24',5);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (18,'MacaulaS','Sork','Valdez','N','11-04-30',5);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (19,'Brenna','Munoz','ASers','S','07-11-27',6);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (20,'UnitS','Morton','Chan','N','16-08-28',4);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (21,'Ezra','Marsh','SweeneS','S','24-05-26',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (22,'Reese','Gould','BSrd','N','20-07-29',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (23,'Charles','RoS','Sanford','S','13-01-28',4);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (24,'Judith','Barnett','Salinas','N','07-06-27',4);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (25,'Bell','LSnn','BerrS','N','22-05-28',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (26,'Randall','Durham','Stuart','N','28-03-25',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (27,'Levi','Macdonald','Mcdowell','S','17-01-30',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (28,'KirbS','TalleS','Moore','S','20-07-27',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (29,'Elton','MaSnard','Schwartz','S','07-09-26',2);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (30,'Finn','Hart','Callahan','S','23-01-28',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (31,'Gloria','Rowland','Spencer','S','27-11-28',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (32,'Abraham','Ramos','FloSd','N','13-03-29',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (33,'Grant','Keller','Lambert','S','25-11-25',5);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (34,'Briar','Bruce','Colon','N','11-04-25',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (35,'Regan','Burton','Bonner','S','09-02-25',3);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (36,'Quamar','Holland','Pate','N','19-02-27',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (37,'Mira','Brown','Nielsen','S','21-05-29',5);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (38,'Mira','Freeman','Sosa','N','02-01-26',1);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (39,'Christen','Cooper','Gomez','S','16-09-25',6);
INSERT INTO Empleado (id_empleado,nombre,ape_paterno,ape_materno,activo,fecha_fin_contrato,id_rol)
VALUES (40,'Lacota','Rodriquez','Steele','S','15-04-27',3);




INSERT INTO ORDEN_PRODUCCION (id_orden_produccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(1,to_date('18/03/2024','dd/mm/yyyy'),to_date('20/03/2024','dd/mm/yyyy'),to_date('30/03/2024','dd/mm/yyyy'),10,'Fabricar bus de transporte publico');
INSERT INTO ORDEN_PRODUCCION (id_orden_produccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(2,to_date('25/04/2024','dd/mm/yyyy'),to_date('26/04/2024','dd/mm/yyyy'),to_date('07/06/2024','dd/mm/yyyy'),8,'Fabricar bus de transporte de personal');
INSERT INTO ORDEN_PRODUCCION (id_orden_produccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(3,to_date('13/09/2024','dd/mm/yyyy'),to_date('15/09/2024','dd/mm/yyyy'),to_date('08/10/2024','dd/mm/yyyy'),10,'Fabricar bus para sector turismo');
INSERT INTO ORDEN_PRODUCCION (id_orden_produccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(4,to_date('09/02/2024','dd/mm/yyyy'),to_date('09/02/2024','dd/mm/yyyy'),to_date('06/03/2024','dd/mm/yyyy'),8,'Fabricar bus para el sector turismo');



INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(1, 'Chasis', 1, 'ud', 1);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(2, 'Asiento', 10, 'ud', 1);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(3, 'Carroceria', 4, 'ud', 1);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(4, 'Pintura Blanca', 2, 'ud', 1);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(5, 'Tanque de combustible', 1, 'ud', 1);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(6, 'Faros delanteros', 2, 'ud', 1);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(7, 'Faros traseros', 2, 'ud', 1);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(1, 'Chasis', 4, 'ud', 2);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(2, 'Asiento', 40, 'ud', 2);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(3, 'Carroceria', 12, 'ud', 2);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(4, 'Pintura Blanca', 6, 'ud', 2);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(5, 'Tanque de combustible', 4, 'ud', 2);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(6, 'Faros delanteros', 10, 'ud', 2);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(7, 'Faros traseros', 10, 'ud', 2);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(1, 'Chasis', 4, 'ud', 3);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(2, 'Asiento',30, 'ud', 3);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(3, 'Carroceria', 10, 'ud', 3);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(4, 'Pintura Blanca',8, 'ud', 3);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(5, 'Tanque de combustible', 8, 'ud', 3);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(6, 'Faros delanteros', 12, 'ud', 3);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(7, 'Faros traseros', 12, 'ud', 3);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(1, 'Chasis', 10, 'ud', 4);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(2, 'Asiento', 60, 'ud', 4);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(3, 'Carroceria', 6, 'ud', 4);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(4, 'Pintura Blanca', 10, 'ud', 4);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(5, 'Tanque de combustible', 15, 'ud', 4);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(6, 'Faros delanteros', 70, 'ud', 4);
INSERT INTO DETALLE_ORD_PRODUCCION (id_detalle_ord_prod, articulo, cantidad, unidad, id_orden_produccion) values(7, 'Faros traseros', 40, 'ud', 4);



INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (1,11,27,'S',4,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (2,10,17,'N',1,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (3,3,26,'N',2,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (4,9,11,'S',3,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (5,6,14,'S',4,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (6,5,24,'N',2,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (7,4,27,'N',2,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (8,6,28,'N',1,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (9,5,29,'S',1,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (10,11,15,'S',1,4);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (11,5,28,'N',4,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (12,9,13,'N',3,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (13,2,27,'N',3,4);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (14,2,12,'S',3,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (15,5,15,'S',3,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (16,9,25,'S',2,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (17,9,21,'N',2,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (18,7,28,'S',3,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (19,10,29,'N',2,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (20,2,11,'N',3,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (21,8,22,'N',3,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (22,10,14,'N',3,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (23,5,22,'N',2,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (24,2,16,'N',3,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (25,6,29,'N',4,4);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (26,1,20,'N',4,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (27,6,25,'S',3,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (28,3,22,'N',2,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (29,9,25,'S',2,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (30,3,26,'N',3,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (31,7,26,'N',2,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (32,11,22,'S',2,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (33,8,19,'S',2,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (34,10,14,'N',3,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (35,6,26,'S',4,1);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (36,6,20,'N',1,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (37,7,14,'N',3,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (38,2,26,'N',4,2);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (39,10,15,'N',2,3);
INSERT INTO DETALLE_ORD_PEDIDO (id_detalle_pedido,id_orden_pedido,cantidad,en_stock,id_orden_produccion,id_tipo_bus)
VALUES (40,5,23,'N',2,1);
