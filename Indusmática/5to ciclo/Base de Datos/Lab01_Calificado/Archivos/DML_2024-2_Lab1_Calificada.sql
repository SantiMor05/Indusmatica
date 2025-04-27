INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(1,'CREACIONES BASICAS', NULL, '3456789', 'creacion@gmail.com', 'Av. Puruchuco 345');
INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(2,'Rosa Varga', NULL, '2347890', 'rvargas@gmail.com', 'Pasaje Chorrillos 789');
INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(3,'Irvin Gonzales', '10453874350', '976613423', 'irving@gmail.com', '');
INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(4,'Universidad del Centro', '209045678', '2135678', 'coordinacion@univcentro.edu.pe', 'Av. Canto Grande 289');
INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(5,'Muebleria La Unica', '21904536', '999345671', 'launica@muebleria.com.pe', 'Calle Las Rosas 4567');
INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(6,'Panaderia Rosita', NULL, '4557890', 'informes@panaderiarosita.com.pe', 'Av Bolivar 876');
INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(7,'Interprovincial Lima', NULL, '34589560', 'gestion@pinterprovincial.com.pe', 'Av Tomas Valle 145');
INSERT INTO cliente (id_cliente,razon_social, ruc,telefono, correo, direccion_fiscal) values(8,'Inversiones Group Lima', NULL, '356789023', 'consultas_group@inversiones.com', 'Calle Rosendo 457');

INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion) values(1,'Almacen central', 'Villa El Salvador', 'Lima', 200, 'Av. Grande 231 Mz. C. Lote 1');
INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion,telefono) values(2,'Almacen Sur', 'Lurin', 'Lima', 1000, 'Av. Piura 1050 Mz. D.','2345678' );
INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion,telefono) values(3,'Almacen Sur II', 'Villa El Salvador', 'Lima', 500, 'Av. Piura 5690 Mz. A.','980457879' );
INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion,telefono) values(4,'Almacen Cono Norte', 'Comas', 'Lima', 1500, 'Av. Pasamayo 456','2345667' );
INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion,telefono) values(5,'Almacen Norte', 'San Martin de Porres', 'Lima', 400, 'Calle Tarazona 101','967456382' );
INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion,telefono) values(6,'Almacen Chico', 'Villa El Salvador', 'Lima', 450, 'Calle C 346 Mz. B. Lote 3','2179463' );
INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion,telefono) values(7,'Deposito Emergencia', 'Villa El Salvador', 'Lima', 350, 'Av. Pasco 480','909346712' );
INSERT INTO sede (id_sede, nombresede,distrito,provincia, area, direccion,telefono) values(8,'Almacen Centro II', 'La Molina', 'Lima', 350, 'Av. La Molina 270','4563890' );

INSERT INTO formaPago (id_formapago, nombre,moneda) values (1, 'tarjeta debito', 'S');
INSERT INTO formaPago (id_formapago, nombre,moneda) values (2, 'tarjeta credito', 'S');
INSERT INTO formaPago (id_formapago, nombre,moneda) values (3, 'efectivo', 'S');
INSERT INTO formaPago (id_formapago, nombre,moneda) values (4, 'efectivo', 'D');
INSERT INTO formaPago (id_formapago, nombre,moneda) values (5, 'transferencia', 'S');

insert into TipoBus (id_tipobus, nombre) values(1, 'Bus de transporte publico');
insert into TipoBus (id_tipobus, nombre) values(2, 'Bus para transporte de personal');
insert into TipoBus (id_tipobus, nombre) values(3, 'Bus de transporte interprovincial');
insert into TipoBus (id_tipobus, nombre) values(4, 'Bus para el sector turismo');

insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(1,to_date('10/01/2024','dd/mm/yyyy'),to_date('30/01/2024', 'dd/mm/yyyy'),4,3,3 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(2,to_date('18/03/2024','dd/mm/yyyy'),to_date('01/04/2024', 'dd/mm/yyyy'),4,5,3 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(3,to_date('08/02/2024','dd/mm/yyyy'),to_date('24/02/2024', 'dd/mm/yyyy'),5,2,2 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(4,to_date('23/04/2024','dd/mm/yyyy'),to_date('05/05/2024', 'dd/mm/yyyy'),5,5,2 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(5,to_date('25/04/2024','dd/mm/yyyy'),to_date('09/06/2024', 'dd/mm/yyyy'),2,1,5 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(6,to_date('18/03/2024','dd/mm/yyyy'),to_date('01/04/2024', 'dd/mm/yyyy'),3,8,5 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(7,to_date('09/02/2024','dd/mm/yyyy'),to_date('09/03/2024', 'dd/mm/yyyy'),1,1,4 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(8,to_date('10/02/2024','dd/mm/yyyy'),to_date('01/03/2024', 'dd/mm/yyyy'),6,1,5 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(9,to_date('01/03/2024','dd/mm/yyyy'),to_date('25/03/2024', 'dd/mm/yyyy'),6,8,1 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(10,to_date('04/04/2024','dd/mm/yyyy'),to_date('05/05/2024', 'dd/mm/yyyy'),6,2,2 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(11,to_date('03/08/2024','dd/mm/yyyy'),to_date('20/08/2024', 'dd/mm/yyyy'),6,1,3 );
insert into ordenpedido (id_ordenpedido, fecha_registro, fecha_entrega, Cliente_ID_cliente, sede_id_sede, formapago_id_formapago) values(12,to_date('13/09/2024','dd/mm/yyyy'),to_date('10/10/2024', 'dd/mm/yyyy'),4,1,1 );

insert into ordenproduccion (id_ordenproduccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(1,to_date('18/03/2024','dd/mm/yyyy'),to_date('20/03/2024','dd/mm/yyyy'),to_date('30/03/2024','dd/mm/yyyy'),10,'Fabricar bus de transporte publico');
insert into ordenproduccion (id_ordenproduccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(2,to_date('25/04/2024','dd/mm/yyyy'),to_date('26/04/2024','dd/mm/yyyy'),to_date('07/06/2024','dd/mm/yyyy'),8,'Fabricar bus de transporte de personal');
insert into ordenproduccion (id_ordenproduccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(3,to_date('13/09/2024','dd/mm/yyyy'),to_date('15/09/2024','dd/mm/yyyy'),to_date('08/10/2024','dd/mm/yyyy'),10,'Fabricar bus para sector turismo');
insert into ordenproduccion (id_ordenproduccion, fecha_registro,fecha_inicio, fecha_culminacion, id_personal_acargo,especificacion) values(4,to_date('09/02/2024','dd/mm/yyyy'),to_date('09/02/2024','dd/mm/yyyy'),to_date('06/03/2024','dd/mm/yyyy'),8,'Fabricar bus para el sector turismo');

insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Chasis', 1, 'ud', 1);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Asiento', 10, 'ud', 1);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Carroceria', 4, 'ud', 1);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Pintura Blanca', 2, 'ud', 1);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Tanque de combustible', 1, 'ud', 1);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros delanteros', 2, 'ud', 1);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros traseros', 2, 'ud', 1);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Chasis', 4, 'ud', 2);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Asiento', 40, 'ud', 2);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Carroceria', 12, 'ud', 2);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Pintura Blanca', 6, 'ud', 2);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Tanque de combustible', 4, 'ud', 2);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros delanteros', 10, 'ud', 2);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros traseros', 10, 'ud', 2);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Chasis', 4, 'ud', 3);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Asiento',30, 'ud', 3);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Carroceria', 10, 'ud', 3);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Pintura Blanca',8, 'ud', 3);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Tanque de combustible', 8, 'ud', 3);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros delanteros', 12, 'ud', 3);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros traseros', 12, 'ud', 3);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Chasis', 10, 'ud', 4);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Asiento', 60, 'ud', 4);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Carroceria', 6, 'ud', 4);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Pintura Blanca', 10, 'ud', 4);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Tanque de combustible', 15, 'ud', 4);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros delanteros', 70, 'ud', 4);
insert into detalleOrdProduccion (articulo, cantidad, unidad, id_ordenproduccion) values('Faros traseros', 40, 'ud', 4);

